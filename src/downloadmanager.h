#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;
class Download;

//< Handles network interactions for fetching remote configs/downloading media.

class DownloadManager : public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager(QString f_user_agent, QObject *parent = nullptr);

    Download *requestData(QUrl url);
    Download *requestRangedData(QUrl url, int start);

signals:

private:
    QString user_agent;
    QNetworkAccessManager *downloader;
};

#endif // DOWNLOADMANAGER_H
