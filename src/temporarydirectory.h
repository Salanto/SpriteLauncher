#ifndef TEMPORARYDIRECTORY_H
#define TEMPORARYDIRECTORY_H

#include <QDir>
#include <QString>

class TemporaryDirectory
{
public:
    TemporaryDirectory(QString path, QString name);
    ~TemporaryDirectory();

    void remove();

    void setAutoRemove(bool f_state);
    bool autoRemove();

private:
    QDir directory;
    bool m_auto_remove = true;
};

#endif // TEMPORARYDIRECTORY_H
