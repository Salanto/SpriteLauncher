#include "launcher.h"
#include "downloadmanager.h"
#include "launcheruserinterface.h"
#include "version.h"

#include <QDebug>
#include <QTemporaryDir>
#include <QTemporaryFile>

Launcher::Launcher(QObject *parent)
    : QObject{parent}
    , downloads(new DownloadManager(spritelauncher::userAgent(), this))
    , userinterface(new LauncherUserInterface(nullptr))
{
    qDebug() << "[Launcher]::CTOR: Creating Launcher at" << this;
    userinterface->show();
}

Launcher::~Launcher()
{
    userinterface->deleteLater();
}

QFile *Launcher::createTemporaryFile(const QString &filename, const QByteArrayView &data)
{
    return nullptr;
}
