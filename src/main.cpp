#include <QApplication>

#include "filefunctions.h"
#include "launcher.h"
#include "version.h"

#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    qDebug() << "Starting application.";
    QApplication app(argc, argv);
    QApplication::setApplicationName(spritelauncher::name());
    QApplication::setApplicationVersion(spritelauncher::version());
    spritelauncher::FileFunctions::init();

    qDebug() << QFile().exists(":/ui/settings.ui");

    Launcher launcher(&app);

    return app.exec();
}
