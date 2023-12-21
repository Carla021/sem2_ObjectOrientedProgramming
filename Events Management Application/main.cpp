#include <QApplication>
#include <QPushButton>
#include <crtdbg.h>
#include "repository/repository.h"
#include "services/services.h"
#include "validators/validators.h"
#include "GUI/GUI.h"
#include "repository/fake_repository.h"

using namespace std;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    /*
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();*/

    vector<Event> adminRepoList;
    adminRepoList.reserve(10);
    string filename = "events.txt";
    Repository repository{filename};
    Service service{repository};
    UserService userService{repository};
    EventValidator validator{};


    GUI gui{service, userService, validator, repository};

    gui.show();


    return QApplication::exec();
}
