#include "launcher.h"
#include "downloadmanager.h"
#include "filefunctions.h"
#include "launcheruserinterface.h"
#include "settingsuserdialog.h"
#include "temporarydirectory.h"
#include "version.h"

#include <QDebug>
#include <QTemporaryFile>
#include <QUrl>

Launcher::Launcher(QObject *parent)
    : QObject{parent}
    , temp_dir(spritelauncher::FileFunctions::appDir(), "cache")
    , downloads(new DownloadManager(spritelauncher::userAgent(), this))
    , userinterface(nullptr)
    , settingsdialog(nullptr)
{
    qDebug() << "[Launcher]::CTOR: Creating Launcher at" << this;
    createAndShowLauncherUI();
}

void Launcher::createAndShowLauncherUI()
{
    if (!userinterface) {
        userinterface = new ui::LauncherUserInterface(nullptr);
        userinterface->setAttribute(Qt::WA_DeleteOnClose);
        connect(userinterface,
                &ui::LauncherUserInterface::settingsRequested,
                this,
                &Launcher::createAndShowSettingsUI);
        userinterface->show();
    }
}

void Launcher::createAndShowSettingsUI()
{
    if (!settingsdialog) {
        settingsdialog = new ui::SettingsUserDialog(nullptr);
        settingsdialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(userinterface,
                &ui::LauncherUserInterface::closed,
                settingsdialog,
                &ui::SettingsUserDialog::close);
        settingsdialog->show();
    }
}
