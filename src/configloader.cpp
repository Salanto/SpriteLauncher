#include "configloader.h"
#include "filefunctions.h"
#include "version.h"

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <qjsondocument.h>
#include <qjsonvalue.h>

ConfigLoader::ConfigLoader(QObject *parent)
    : QObject(parent)
{
    qDebug() << "[ConfigLoader]::CTOR Creating ConfigLoader at" << this;
    ConfigLoader::config_file = spritelauncher::FileFunctions::appDir() + "/config.json";
    createOrUpdateConfiguration();
}

ConfigLoader::~ConfigLoader()
{
    flushConfigToDisk();
}

const QList<QString> ConfigLoader::urls() const
{
    QJsonObject config = m_config["config"].toObject();

    QList<QString> urls;
    const QJsonArray entries = config["urls"].toArray();
    for (const QJsonValue &entry : entries) {
        urls.append(entry.toString());
    }
    return urls;
}

void ConfigLoader::createOrUpdateConfiguration()
{
    if (!QFile::exists(config_file)) {
        createConfiguration();
    } else {
        updateConfiguration();
    }
}

void ConfigLoader::createConfiguration()
{
    qDebug() << "[ConfigLoader]::CreateConfiguration: Creating new configuration file.";

    QJsonObject config;
    config["urls"] = QJsonArray::fromStringList(QList<QString>{});

    QJsonArray packages_installed;

    QJsonObject body;
    body["installed"] = packages_installed;
    body["config"] = config;
    body["version"] = spritelauncher::version();

    m_config = body;

    flushConfigToDisk();
}

void ConfigLoader::updateConfiguration()
{
    readConfigToMemory();
    flushConfigToDisk();
}

void ConfigLoader::flushConfigToDisk()
{
    QFile file(config_file);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning()
            << "[ConfigLoader]::FlushConfigToDisk: Unable to obtain file handle to write config.";
        return;
    }
    file.write(QJsonDocument(m_config).toJson(QJsonDocument::Indented));
}

void ConfigLoader::readConfigToMemory()
{
    QFile file(config_file);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning()
            << "[ConfigLoader]::FlushConfigToDisk: Unable to obtain file handle to write config.";
        return;
    }
    m_config = QJsonDocument::fromJson(file.readAll()).object();
}
