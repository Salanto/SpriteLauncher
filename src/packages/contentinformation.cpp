#include "contentinformation.h"

void ContentInformation::setLabel(const QString &label)
{
    m_label = label;
}

QString ContentInformation::label() const
{
    return m_label;
}

void ContentInformation::setId(const QString &id)
{
    m_id = id;
}

QString ContentInformation::id()
{
    return m_id;
}

void ContentInformation::setVersion(const QString &version)
{
    m_version = QVersionNumber::fromString(version);
}

QVersionNumber ContentInformation::version() const
{
    return m_version;
}

void ContentInformation::setDescription(const QString &description)
{
    m_description = description;
}

QString ContentInformation::description() const
{
    return m_description;
}

void ContentInformation::setRequiredPackages(const QStringList &required_packages)
{
    m_required_packages = required_packages;
}

QStringList ContentInformation::requiredPackages() const
{
    return m_required_packages;
}
