#include "temporarydirectory.h"

#include <QDebug>
#include <QDir>

TemporaryDirectory::TemporaryDirectory(QString path, QString name)
{
    qDebug() << "[TemporaryDirectory]::CTOR: Creating temporary folder" << name << "at" << path;
    directory.mkdir(path + "/" + name);
    directory.setPath(path + "/" + name);
}

TemporaryDirectory::~TemporaryDirectory()
{
    if (autoRemove()) {
        qDebug() << "[TemporaryDirectory]::DTOR: Deleting temporary folder at" << directory.path();
        directory.removeRecursively();
    }
}

void TemporaryDirectory::remove() {}

void TemporaryDirectory::setAutoRemove(bool f_state)
{
    m_auto_remove = f_state;
}

bool TemporaryDirectory::autoRemove()
{
    return m_auto_remove;
}
