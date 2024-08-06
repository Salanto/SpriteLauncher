#include "packageinformation.h"
#include "qurl.h"

void PackageInformation::setId(const QString &id)
{
    m_id = id;
}

QString PackageInformation::id() const
{
    return m_id;
}

void PackageInformation::setVersion(const QString &version)
{
    m_version = QVersionNumber::fromString(version);
}

QVersionNumber PackageInformation::version() const
{
    return m_version;
}

void PackageInformation::setUrl(const QString &url)
{
    m_url = QUrl(url);
}

QUrl PackageInformation::url() const
{
    return m_url;
}

void PackageInformation::setHash(const QString &filehash)
{
    m_hash = filehash;
}

QString PackageInformation::hash() const
{
    return m_hash;
}
