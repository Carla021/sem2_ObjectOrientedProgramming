//
// Created by Carla on 5/28/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_userGUI.h" resolved

#include <QMessageBox>
#include "usergui.h"
#include "ui_userGUI.h"
//#include <windows.h>

userGUI::userGUI(QWidget *parent, Service& service, UserService& userService, EventValidator& eventValidator) : service{service}, userService{userService}, validator{eventValidator},
        QWidget(parent), ui(new Ui::userGUI) {
    ui->setupUi(this);

    setParent(parent);
    setWindowFlag(Qt::Window);
    this->repositoryTypeSelected = false;
    this->populateUserList();
    this->connectSignalsAndSlots();
}

userGUI::~userGUI() {
    delete ui;
}

void userGUI::populateUserList() {
    vector<Event> allEvents = this->service.get_all_service();

    this->ui->givenMonthListWidget->clear();

    for(Event& event: allEvents)
        this->ui->givenMonthListWidget->addItem(QString::fromStdString(event.toString()));

}

void userGUI::connectSignalsAndSlots() {
    QObject::connect(this->ui->monthPushButton, &QPushButton::clicked, this, &userGUI::get_filtered);

    /*
    QObject::connect(this->ui->givenMonthListWidget, &QListWidget::itemClicked, this, &userGUI::addUserList);
    QObject::connect(this->ui->DeletePushButton, &QPushButton::clicked, this, &userGUI::deleteUserEvent);
     */

    QObject::connect(this->ui->fileTypeLineEdit, &QLineEdit::textChanged, this, &userGUI::chooseRepositoryType);
    QObject::connect(this->ui->givenMonthListWidget, &QListWidget::itemClicked, this, &userGUI::showInBrowser);
    QObject::connect(this->ui->AddPushButton, &QPushButton::clicked, this, &userGUI::addUserList);
    QObject::connect(this->ui->DeletePushButton, &QPushButton::clicked, this, &userGUI::deleteUserEvent);
    QObject::connect(this->ui->fileTypePushButton, &QPushButton::clicked, this, &userGUI::openFile);

    /*
    QObject::connect(this->ui->fileTypePushButton, &QPushButton::clicked, [this]() {
        this->chooseRepositoryType();

        if(!this->repositoryTypeSelected) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Warning);
            error->setText("Please select the type of file you want!");
            error->setWindowTitle("File type warning!");
            error->exec();
        } else {

            std::string link = std::string("start").append(this->userService.get_file_service());
            system(link.c_str());

        }
    });*/
}

int userGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->ui->givenMonthListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.empty()) {
        this->ui->titleLineEdit->clear();
        this->ui->givenMonthLineEdit->clear();
        this->ui->fileTypeLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void userGUI::deleteUserEvent() {

    string title = this->ui->titleLineEdit->text().toStdString();

    int event_deleted = this->userService.delete_user_service(title);

    if(event_deleted == 1) {
        auto *error = new QMessageBox();
        error->setIcon(QMessageBox::Warning);
        error->setText("Please enter an existing title!");
        error->setWindowTitle("Event title warning!");
        error->exec();
    } else
        this->populateSelectedList();
}

void userGUI::get_filtered() {

    int month = stoi(this->ui->givenMonthLineEdit->text().toStdString());
    vector<Event> list_of_filtered_events = this->userService.filter_events(month);

    this->ui->givenMonthListWidget->clear();

    for(Event& event: list_of_filtered_events)
        this->ui->givenMonthListWidget->addItem(QString::fromStdString(event.toString()));
}

void userGUI::populateSelectedList() {

    this->ui->listListWidget->clear();
    vector<Event> selectedEvents = this->userService.get_all_user_service();
    for(Event& event: selectedEvents)
        this->ui->listListWidget->addItem(QString::fromStdString(event.toString()));
}

void userGUI::chooseRepositoryType() {

    string repositoryType = this->ui->fileTypeLineEdit->text().toStdString();
    if(repositoryType == "html" || repositoryType == "csv")
    {
        this->repositoryTypeSelected = true;
        this->userService.repository_type(repositoryType);
    } else {
        this->repositoryTypeSelected = false;
    }
}

void userGUI::addUserList() {

    //this->chooseRepositoryType();

    if(!this->repositoryTypeSelected) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Warning);
        error->setText("Please select the type of file you want!");
        error->setWindowTitle("File type warning!");
        error->exec();
    } else {

        /*string event_name = this->ui->givenMonthListWidget->selectedItems().at(0)->text().toStdString();
        int index = this->service.find_events_by_title_service(event_name);
        Event event = this->service.get_all_service()[index];
        this->userService.add_user_service(event);

        this->populateSelectedList();*/

        string title = this->ui->TitleLineEdit->text().toStdString();
        string description = this->ui->DescriptionLineEdit_2->text().toStdString();
        string date_and_time = this->ui->DTLineEdit_3->text().toStdString();
        string number_of_people = this->ui->NbPLineEdit_4->text().toStdString();
        string link = this->ui->linkLineEdit_5->text().toStdString();

        try {
            int number_of_people_integer = stoi(number_of_people);

            vector<string> date_and_time_integers = divide_line_in_elements(date_and_time, '.');
            Datetime datetime {stoi(date_and_time_integers[0]), stoi(date_and_time_integers[1]), stoi(date_and_time_integers[2]), stoi(date_and_time_integers[3]), stoi(date_and_time_integers[4])};

            this->validator.validate_title(title);
            this->validator.validate_description(description);
            this->validator.validate_date_and_time(datetime);
            this->validator.validate_number_of_people(number_of_people_integer);
            this->validator.validate_link(link);

            Event event {title, description, datetime, number_of_people_integer, link};

            this->userService.add_user_service(event);
            this->populateSelectedList();
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
            error->setWindowTitle("Error at adding event!");
            error->exec();
        } catch (const std::invalid_argument& e) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText(e.what());
            error->setWindowTitle("Invalid argument exception caught!");
            error->exec();
        }

        //this->ui->listListWidget->addItem(this->ui->givenMonthListWidget->takeItem(this->getSelectedIndex()));
    }

}

void userGUI::showInBrowser() {

    string event_name = divide_line_in_elements(
            this->ui->givenMonthListWidget->selectedItems().at(0)->text().toStdString(), ',')[0];
    int index = this->service.find_events_by_title_service(event_name);
    Event event = this->service.get_all_service()[index];

    this->ui->TitleLineEdit->setText(QString::fromStdString(event_name));
    this->ui->DescriptionLineEdit_2->setText(QString::fromStdString(event.get_description()));
    this->ui->DTLineEdit_3->setText(QString::fromStdString(event.get_date_and_time().toStringDT()));
    this->ui->NbPLineEdit_4->setText(QString::fromStdString(to_string(event.get_number_of_people())));
    this->ui->linkLineEdit_5->setText(QString::fromStdString(event.get_link()));

    std::string link = std::string("start ").append(event.get_link());
    system(link.c_str());
}

void userGUI::openFile() {

    if(!this->repositoryTypeSelected) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Warning);
        error->setText("Please select the type of file you want!");
        error->setWindowTitle("File type warning!");
        error->exec();
    } else {
        string link = string("start ").append(this->userService.get_file_service());
        system(link.c_str());
    }
}


