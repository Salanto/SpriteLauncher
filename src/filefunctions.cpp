#include "filefunctions.h"

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>

QString spritelauncher::FileFunctions::m_app_dir = "";

void spritelauncher::FileFunctions::init()
{
#ifdef Q_OS_WINDOWS
    FileFunctions::m_app_dir = QCoreApplication::applicationDirPath();
#endif

#ifdef Q_OS_LINUX
    QString app_image_dir = qgetenv("APPIMAGE");
    if (!app_image_dir.isEmpty()) {
        m_app_dir = QFileInfo(app_image_dir).absoluteDir().path();
        return;
    }
    m_app_dir = QCoreApplication::applicationDirPath();
#endif
}

QString spritelauncher::FileFunctions::appDir()
{
    return m_app_dir;
}
