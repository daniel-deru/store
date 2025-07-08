#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPixmap splash(":/splash/greenbag");
    QSplashScreen splashScreen(splash);

    splashScreen.show();

    QTimer::singleShot(1000, &splashScreen, &QSplashScreen::close);
    app.processEvents(); // Loads the splash faster and keeps it on the screen for the amount of time specified before mainwindow shows

    MainWindow mainWindow;

    QTimer::singleShot(1000, &mainWindow, [&mainWindow]() {
        mainWindow.show();
    });

    return app.exec();
}
