#include "launcheruserinterface.h"

#include <QDebug>
#include <QFile>
#include <QVBoxLayout>
#include <QtUiTools/QUiLoader>

#include <QMenuBar>

const QString ui::LauncherUserInterface::UI_FILE_PATH = ":/ui/launcher.ui";

ui::LauncherUserInterface::LauncherUserInterface(QWidget *parent)
    : QMainWindow{parent}
{
    qDebug() << "[LauncherUserInterface]::CTOR: Creating LauncherUserInterface at" << this;
    QFile file(UI_FILE_PATH);

    if (!file.open(QFile::ReadOnly)) {
        qFatal("Unable to open file %s", qPrintable(file.fileName()));
        return;
    }

    QUiLoader loader(this);
    loader.load(&file, this);

    QMenu *file_menu = menuBar()->addMenu("File");
    file_menu->addAction("Open Settings", [this] { Q_EMIT settingsRequested(); });
}

void ui::LauncherUserInterface::closeEvent(QCloseEvent *event)
{
    Q_EMIT closed();
    QMainWindow::closeEvent(event);
}
