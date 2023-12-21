//
// Created by Carla on 5/17/2023.
//

#include "GUI.h"
#include "usergui.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QErrorMessage>
#include <QMessageBox>

GUI::GUI(Service &service, UserService &userService, EventValidator &validator, Repository &repository): service {service}, userService {userService}, validator {validator}, repository {repository} {
    this->titleWidget = new QLabel(this);
    this->adminButton = new QPushButton(this);
    this->userButton = new QPushButton(this);
    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#BA90C6>Welcome to the Events' App! <br> Select your mode!</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(10);
    titleFont.setStyleHint(QFont::System);
    titleFont.setWeight(QFont::Bold);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);

    this->adminButton->setText("Admin mode");
    layout->addWidget(this->adminButton);

    this->userButton->setText("User mode");
    layout->addWidget(this->userButton);

    this->setLayout(layout);
    this->setStyleSheet("color: #E8A0BF; background-color:#FDF4F5");
    this->adminButton->setStyleSheet("background-color:#E3F4F4");
    this->userButton->setStyleSheet("background-color:#E3F4F4");
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->adminButton, &QPushButton::clicked, this, &GUI::showAdmin);
    QObject::connect(this->userButton, &QPushButton::clicked, this, &GUI::showUser);
}

void GUI::showAdmin() {
    auto* admin = new AdminGUI(this, this->service, this->validator, this->repository);
    admin->show();
}

void GUI::showUser() {
    auto* user = new userGUI(this, this->service, this->userService, this->validator);
    user->show();
}

GUI::~GUI() = default;

AdminGUI::AdminGUI(QWidget *parent, Service &service, EventValidator &eventValidator, Repository &repository): service {service}, validator {eventValidator}, repository {repository} {
    this->titleWidget = new QLabel(this);
    this->eventsListWidget = new QListWidget{};
    this->titleLineEdit = new QLineEdit{};
    this->descriptionLineEdit = new QLineEdit{};
    this->dateTimeLineEdit = new QLineEdit{};
    this->numberOfPeopleLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};

    this->addButton = new QPushButton("Add");
    this->deleteButton = new QPushButton("Delete");
    this->updateButton = new QPushButton("Update");

    this->addButton->setStyleSheet("background-color: #D2E9E9");
    this->deleteButton->setStyleSheet("background-color: #D2E9E9");
    this->updateButton->setStyleSheet("background-color: #D2E9E9");

    setParent(parent);
    setWindowFlag(Qt::Window);
    this->initAdminGUI();
    this->populateList();
    this->connectSignalsAndSlots();
}

void AdminGUI::initAdminGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#BA90C6>ADMIN MODE</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(10);
    titleFont.setStyleHint(QFont::System);
    titleFont.setWeight(QFont::Bold);

    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);
    layout->addWidget(this->eventsListWidget);

    auto* eventsDetailsLayout = new QFormLayout{};
    eventsDetailsLayout->addRow("Title", this->titleLineEdit);
    eventsDetailsLayout->addRow("Description", this->descriptionLineEdit);
    eventsDetailsLayout->addRow("Date and Time", this->dateTimeLineEdit);
    eventsDetailsLayout->addRow("Number of people", this->numberOfPeopleLineEdit);
    eventsDetailsLayout->addRow("Link", this->linkLineEdit);
    layout->addLayout(eventsDetailsLayout);

    auto* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->updateButton, 1, 0);
    layout->addLayout(buttonsLayout);
}

void AdminGUI::populateList() {
    this->eventsListWidget->clear();
    std::vector<Event> allEvents = this->service.get_all_service();
    for(Event& event: allEvents)
        this->eventsListWidget->addItem(QString::fromStdString(event.toString()));
}

void AdminGUI::connectSignalsAndSlots() {
    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::addEvent);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteEvent);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdminGUI::updateEvent);
}

void AdminGUI::addEvent() {
    std::string title = this->titleLineEdit->text().toStdString();
    std::string description = this->descriptionLineEdit->text().toStdString();
    std::string dateAndTime = this->dateTimeLineEdit->text().toStdString();
    std::string numberOfPeople = this->numberOfPeopleLineEdit->text().toStdString();
    std::string link = this->linkLineEdit->text().toStdString();

    int numberOfPeopleInt = stoi(numberOfPeople);

    vector<string> dateTimeString = divide_line_in_elements(dateAndTime, '.');
    int day = stoi(dateTimeString[0]);
    int month = stoi(dateTimeString[1]);
    int year = stoi(dateTimeString[2]);
    int hour = stoi(dateTimeString[3]);
    int minutes = stoi(dateTimeString[4]);
    Datetime datetime {day, month, year, hour, minutes};

    try {
        this->validator.validate_title(title);
        this->validator.validate_description(description);
        this->validator.validate_date_and_time(datetime);
        this->validator.validate_number_of_people(numberOfPeopleInt);
        this->validator.validate_link(link);

        this->service.add_service(title, description, datetime, numberOfPeopleInt, link);
        this->populateList();

    } catch(ValidationException& exc) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input!");
        error->exec();
    } catch (RepositoryException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Error at adding an event!");
        error->exec();
    }
}

void AdminGUI::deleteEvent() {
    try {
        std::string title = this->titleLineEdit->text().toStdString();
        this->validator.validate_title(title);
        this->service.delete_service(title);
        this->populateList();
    } catch (ValidationException& exc) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input!");
        error->exec();
    } catch (RepositoryException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Error at deleting event!");
        error->exec();
    }
}

void AdminGUI::updateEvent() {
    int index = this->getSelectedIndex();
    try {
        if(index < 0) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText("No event selected!");
            error->setWindowTitle("Selection error!");
            error->exec();
        } else {
            string old_title = this->service.get_all_service()[index].get_title();
            string new_title = this->titleLineEdit->text().toStdString();
            string new_description = this->descriptionLineEdit->text().toStdString();
            string new_dateTime = this->dateTimeLineEdit->text().toStdString();
            string new_number_of_people = this->numberOfPeopleLineEdit->text().toStdString();
            string new_link = this->linkLineEdit->text().toStdString();

            int numberOfPeople = stoi(new_number_of_people);

            vector<string> dateTimeString = divide_line_in_elements(new_dateTime, '.');
            int day = stoi(dateTimeString[0]);
            int month = stoi(dateTimeString[1]);
            int year = stoi(dateTimeString[2]);
            int hour = stoi(dateTimeString[3]);
            int minutes = stoi(dateTimeString[4]);
            Datetime datetime {day, month, year, hour, minutes};

            this->validator.validate_title(old_title);
            this->validator.validate_title(new_title);
            this->validator.validate_description(new_description);
            this->validator.validate_date_and_time(datetime);
            this->validator.validate_number_of_people(numberOfPeople);
            this->validator.validate_link(new_link);

            this->service.update_service(old_title, new_title, new_description, datetime, numberOfPeople, new_link);
            this->populateList();
        }
    } catch (ValidationException& exc) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input!");
        error->exec();
    } catch (RepositoryException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Error at deleting event!");
        error->exec();
    }
}

int AdminGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->eventsListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty()) {
        this->titleLineEdit->clear();
        this->descriptionLineEdit->clear();
        this->dateTimeLineEdit->clear();
        this->numberOfPeopleLineEdit->clear();
        this->linkLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

AdminGUI::~AdminGUI() = default;


