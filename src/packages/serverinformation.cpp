#include "serverinformation.h"
#include "qpixmap.h"
#include <optional>

void ServerInformation::setServerName(const QString &server_name)
{
    m_server_name = server_name;
}

QString ServerInformation::serverName() const
{
    return m_server_name;
}

void ServerInformation::setServerIcon(const QString &encoded_icon)
{
    QPixmap pixmap;
    pixmap.loadFromData(encoded_icon.toUtf8());
    m_server_icon = QIcon(pixmap);
}

QIcon ServerInformation::serverIcon()
{
    return m_server_icon;
}

QList<ContentInformation> ServerInformation::contentPacks()
{
    return m_content_packs;
}

std::optional<PackageInformation> ServerInformation::package(QString id)
{
    for (const PackageInformation &package : m_packages) {
        if (package.id() == id) {
            return std::optional<PackageInformation>(package);
        }
    }
    return std::nullopt;
}
