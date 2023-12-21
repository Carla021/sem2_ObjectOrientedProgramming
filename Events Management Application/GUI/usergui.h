//
// Created by Carla on 5/28/2023.
//

#ifndef A89_CARLA021_USERGUI_H
#define A89_CARLA021_USERGUI_H

#include <QWidget>
#include "../services/services.h"
#include "../validators/validators.h"
#include "../repository/user_repository.h"
#include "../services/user_services.h"


QT_BEGIN_NAMESPACE
namespace Ui { class userGUI; }
QT_END_NAMESPACE

class userGUI : public QWidget {
Q_OBJECT

public:
    explicit userGUI(QWidget *parent, Service& service, UserService& userService, EventValidator& eventValidator);

    ~userGUI() override;

private:
    Service& service;
    UserService& userService;
    EventValidator& validator;
    Ui::userGUI *ui;

    void get_filtered();
    bool repositoryTypeSelected;
    void populateUserList();
    void populateSelectedList();
    void connectSignalsAndSlots();
    int getSelectedIndex() const;
    void deleteUserEvent();
    void chooseRepositoryType();
    void addUserList();
    void showInBrowser();
    void openFile();
};


#endif //A89_CARLA021_USERGUI_H
