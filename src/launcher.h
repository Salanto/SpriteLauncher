#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "configloader.h"
#include "download.h"
#include "temporarydirectory.h"

#include <QObject>
#include <QPointer>

namespace ui {
class LauncherUserInterface;
class SettingsUserDialog;
} // namespace ui

class DownloadManager;

class QFile;

//< Central application class. Handles setup and interactions from the UI and delegates them to the worker classes

class Launcher : public QObject
{
    Q_OBJECT
public:
    explicit Launcher(QObject *parent = nullptr);

    QFile *createTemporaryFile(const QString &filename, const QByteArrayView &data);
    void queryServers();

private:
    void createAndShowLauncherUI();
    void createAndShowSettingsUI();

    void serverManifestStateChanged(Download *download);

    TemporaryDirectory temp_dir;
    DownloadManager *downloads;
    ConfigLoader *config;
    QPointer<ui::LauncherUserInterface> userinterface;
    QPointer<ui::SettingsUserDialog> settingsdialog;
};

#endif // LAUNCHER_H
