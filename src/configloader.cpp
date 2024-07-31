#include "configloader.h"

#include <QDebug>
#include <QSettings>

ConfigLoader::ConfigLoader(QObject *parent)
    : QObject(parent)
{
    qDebug() << "[ConfigLoader]::CTOR Creating ConfigLoader at" << this;
}
