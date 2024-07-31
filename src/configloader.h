#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include <QList>
#include <QObject>
#include <QUrl>

class QSettings;

class ConfigLoader : public QObject
{
    Q_OBJECT
public:
    ConfigLoader(QObject *parent);

    QList<QUrl> sci_urls(); //< Server Content Index

signals:

private:
};

#endif // CONFIGLOADER_H
