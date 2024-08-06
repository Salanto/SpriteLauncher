#ifndef CONTENTINFORMATION_H
#define CONTENTINFORMATION_H

#include <QString>
#include <QStringList>
#include <QVersionNumber>

class ContentInformation
{
public:
    void setLabel(const QString &label);
    QString label() const;

    void setId(const QString &id);
    QString id();

    void setVersion(const QString &version);
    QVersionNumber version() const;

    void setDescription(const QString &description);
    QString description() const;

    void setRequiredPackages(const QStringList &required_packages);
    QStringList requiredPackages() const;

private:
    QString m_label;
    QString m_id;
    QVersionNumber m_version;
    QString m_description;
    QStringList m_required_packages;
};

#endif // CONTENTINFORMATION_H
