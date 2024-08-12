#ifndef SERVERINFORMATION_H
#define SERVERINFORMATION_H

#include <QIcon>
#include <QObject>
#include <optional>

#include "contentinformation.h"
#include "packageinformation.h"

class ServerInformation
{
public:
    void setServerName(const QString &server_name);
    QString serverName() const;

    void setServerIcon(const QString &encoded_icon);
    QIcon serverIcon();

    QList<ContentInformation> contentPacks();
    std::optional<PackageInformation> package(QString id);

private:
    QString m_server_name;
    QIcon m_server_icon;

    QList<ContentInformation> m_content_packs;
    QList<PackageInformation> m_packages;
};

#endif // SERVERINFORMATION_H
