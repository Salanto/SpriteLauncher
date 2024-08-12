#include "download.h"

#include <QDebug>
#include <QNetworkReply>
#include <algorithm>
#include <optional>

Download::Download(QNetworkReply *f_reply, QObject *parent)
    : QObject{parent}
    , status{Status::STARTING}
    , bytes_received{0}
    , max_bytes_availabe{0}
    , reply{f_reply}
{
    connect(reply.get(), &QNetworkReply::finished, this, &Download::finished);
    connect(reply.get(), &QNetworkReply::downloadProgress, this, &Download::downloadProgress);
}

std::optional<QByteArray> Download::data()
{
    if (status != Status::FINISHED) {
        qWarning()
            << "[Download]::data: Tried to obtain data from Download without being finished.";
        return std::nullopt;
    }
    return m_data;
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
    m_data = reply.get()->readAll();
    setStatus(Status::FINISHED);
}

void Download::setStatus(Status f_status)
{
    status = f_status;
    Q_EMIT statusChanged(status);
}
