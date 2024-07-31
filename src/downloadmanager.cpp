#include "downloadmanager.h"

#include <QNetworkAccessManager>

DownloadManager::DownloadManager(QString user_agent, QObject *parent)
    : QObject{parent}
    , downloader{new QNetworkAccessManager(this)}
{
    qDebug() << "[DownloadManager]::CTOR: Creating Downloadmanager at" << this;
}

void DownloadManager::finished(QNetworkReply *reply) {}

void queryServerIndex(QList<QUrl> sci_urls)
{
    for (const QUrl &url : sci_urls) {
        if (!url.isValid()) {
            qWarning() << "[DownloadManager::queryServerIndex: Provided server URL" << url
                       << "is invalid";
        }

        qInfo() << "[DownloadManager]::queryServerIndex: Querying Server Content Index of URL"
                << url;
    }
}
