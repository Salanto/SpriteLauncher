#ifndef LAUNCHER_H
#define LAUNCHER_H

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

private Q_SLOTS:

private:
    void createAndShowLauncherUI();
    void createAndShowSettingsUI();

    TemporaryDirectory temp_dir;
    DownloadManager *downloads;
    QPointer<ui::LauncherUserInterface> userinterface;
    QPointer<ui::SettingsUserDialog> settingsdialog;
};

#endif // LAUNCHER_H
