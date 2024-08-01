#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;

//< Handles network interactions for fetching remote configs/downloading media.

class DownloadManager : public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager(QString user_agent, QObject *parent = nullptr);

signals:

private slots:
    void finished(QNetworkReply *reply);

private:
    QString user_agent;
    QNetworkAccessManager *downloader;
};

#endif // DOWNLOADMANAGER_H
