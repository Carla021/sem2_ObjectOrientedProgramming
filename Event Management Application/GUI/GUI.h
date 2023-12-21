//
// Created by Carla on 5/17/2023.
//

#ifndef A89_CARLA021_GUI_H
#define A89_CARLA021_GUI_H

#include <QWidget>
#include "../services/services.h"
#include <QLabel>
#include <QPushButton>
#include "../services/user_services.h"
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include "../validators/validators.h"

class GUI: public QWidget {
private:
    Service& service;
    UserService& userService;
    EventValidator& validator;
    Repository& repository;
    void initGUI();
    QLabel* titleWidget;
    QPushButton* adminButton;
    QPushButton* userButton;
    void showAdmin();
    void showUser();

    void connectSignalsAndSlots();

public:
    explicit GUI(Service& service, UserService& userService, EventValidator& validator, Repository& repository);
    ~GUI() override;
};

class AdminGUI: public QWidget {
private:
    Service& service;
    EventValidator& validator;
    Repository& repository;
    void initAdminGUI();
    QLabel* titleWidget;
    QListWidget* eventsListWidget;
    QLineEdit* titleLineEdit, *descriptionLineEdit, *dateTimeLineEdit, *numberOfPeopleLineEdit, *linkLineEdit;
    QPushButton* addButton, *deleteButton, *updateButton, *chartButton;

    void populateList();
    void connectSignalsAndSlots();
    int getSelectedIndex() const;
    void addEvent();
    void deleteEvent();
    void updateEvent();

public:
    explicit AdminGUI(QWidget* parent, Service& service, EventValidator& eventValidator, Repository& repository);
    ~AdminGUI() override;
};

#endif //A89_CARLA021_GUI_H
