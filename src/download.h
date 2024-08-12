#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <qscopedpointer.h>

class QNetworkReply;

class Download : public QObject
{
    Q_OBJECT
public:
    explicit Download(QNetworkReply *f_reply, QObject *parent = nullptr);

    std::optional<QByteArray> data();

    enum class Status { STARTING, RUNNING, FINISHED, PAUSED, ABORTED, FAILED };
    Q_ENUM(Status)

signals:
    void statusChanged(Status status);
    void progress(int percent);

private slots:
    void downloadProgress(qint64 received, qint64 maximum);
    void finished();

private:
    void setStatus(Download::Status f_status);

    Status status;
    QByteArray m_data;
    qint64 bytes_received;
    qint64 max_bytes_availabe;
    QScopedPointer<QNetworkReply> reply;
};

#endif // DOWNLOAD_H
