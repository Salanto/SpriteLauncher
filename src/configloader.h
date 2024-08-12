#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include <QJsonObject>
#include <QList>
#include <QObject>
#include <QUrl>

class QSettings;

class ConfigLoader : public QObject
{
    Q_OBJECT
public:
    inline static QString config_file;

    ConfigLoader(QObject *parent);
    ~ConfigLoader();

    const QList<QString> urls() const; //< Server Content Index

signals:

private:
    QJsonObject m_config;

    void createOrUpdateConfiguration();
    void createConfiguration();
    void updateConfiguration();

    void flushConfigToDisk();
    void readConfigToMemory();
};

#endif // CONFIGLOADER_H
