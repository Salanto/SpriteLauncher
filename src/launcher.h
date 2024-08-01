#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QObject>

class DownloadManager;
class TemporaryFileHandler;
class LauncherUserInterface;
class QFile;

//< Central application class. Handles setup and interactions from the UI and delegates them to the worker classes

class Launcher : public QObject
{
    Q_OBJECT
public:
    explicit Launcher(QObject *parent = nullptr);
    ~Launcher();

    QFile *createTemporaryFile(const QString &filename, const QByteArrayView &data);

signals:

private:
    DownloadManager *downloads;
    TemporaryFileHandler *tempfiles;
    LauncherUserInterface *userinterface;
};

#endif // LAUNCHER_H
