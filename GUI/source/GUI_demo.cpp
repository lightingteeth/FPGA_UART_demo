#include <QApplication>
#include "./include/main_gui.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyMainWindow MainWindow;
    MainWindow.show();
    return app.exec();
}
