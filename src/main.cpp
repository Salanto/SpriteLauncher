#include <QCoreApplication>
#include "configloader.h"
#include "downloadmanager.h"
#include "version.h"

int main(int argc, char *argv[])
{
    QCoreApplication launcher(argc, argv);
    QCoreApplication::setApplicationName(simplelauncher::name());
    QCoreApplication::setApplicationVersion(simplelauncher::version());
    ConfigLoader loader(&launcher);
    DownloadManager manager(simplelauncher::userAgent(), &launcher);

    qDebug() << QCoreApplication::applicationName();
    return launcher.exec();
}
