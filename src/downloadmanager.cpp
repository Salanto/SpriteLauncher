#include "downloadmanager.h"
#include "download.h"

#include <QNetworkAccessManager>

DownloadManager::DownloadManager(QString f_user_agent, QObject *parent)
    : QObject{parent}
    , user_agent{f_user_agent}
    , downloader{new QNetworkAccessManager(this)}
{
    qDebug() << "[DownloadManager]::CTOR: Creating Downloadmanager at" << this;
}

Download *DownloadManager::requestData(QUrl url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, user_agent);
    return new Download(downloader->get(request));
}

Download *DownloadManager::requestRangedData(QUrl url, int start)
{
    return nullptr;
}
