#include "download.h"

#include <QDebug>
#include <QNetworkReply>
#include <algorithm>

Download::Download(QNetworkReply *f_reply, QObject *parent)
    : QObject{parent}
    , status{Status::STARTING}
    , bytes_received{0}
    , max_bytes_availabe{0}
    , reply{f_reply}
{
    connect(reply, &QNetworkReply::finished, this, &Download::finished);
    connect(reply, &QNetworkReply::downloadProgress, this, &Download::downloadProgress);
}

void Download::downloadProgress(qint64 received, qint64 maximum)
{
    if (status != Status::RUNNING) {
        setStatus(Status::RUNNING);
    }

    int percentage = std::clamp(static_cast<int>(float(received) / float(maximum) * 100), 0, 100);
    qDebug() << "Downloaded" << percentage << "percent of file" << reply->url().fileName();

    Q_EMIT progress(percentage);
}

void Download::finished()
{
    setStatus(Status::FINISHED);
    qDebug() << reply->readAll();
}

void Download::setStatus(Status f_status)
{
    status = f_status;
    Q_EMIT statusChanged(status);
}
