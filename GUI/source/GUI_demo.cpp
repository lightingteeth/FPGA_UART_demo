#include <QApplication>
#include "./include/main_gui.h"
#include "./include/lua_include.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyMainWindow MainWindow;
    MainWindow.show();
    return app.exec();
}
