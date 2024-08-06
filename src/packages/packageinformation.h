#ifndef PACKAGEINFORMATION_H
#define PACKAGEINFORMATION_H

#include <QString>
#include <QUrl>
#include <QVersionNumber>

class PackageInformation
{
public:
    void setId(const QString &id);
    QString id() const;

    void setVersion(const QString &version);
    QVersionNumber version() const;

    void setUrl(const QString &url);
    QUrl url() const;

    void setHash(const QString &filehash);
    QString hash() const;

private:
    QString m_id;
    QVersionNumber m_version;
    QUrl m_url;
    QString m_hash;
};

#endif // PACKAGEINFORMATION_H
