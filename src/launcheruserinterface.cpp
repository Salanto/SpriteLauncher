#include "launcheruserinterface.h"

#include <QDebug>
#include <QtUiTools/QUiLoader>

const QString LauncherUserInterface::UI_FILE_PATH = "userinterface.ui";

LauncherUserInterface::LauncherUserInterface(QWidget *parent)
    : QMainWindow{parent}
{
    qDebug() << "[LauncherUserInterface]::CTOR: Creating LauncherUserInterface at" << this;
}

void LauncherUserInterface::setupUI() {}
