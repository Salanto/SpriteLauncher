#ifndef LAUNCHERUSERINTERFACE_H
#define LAUNCHERUSERINTERFACE_H

#include <QMainWindow>

class LauncherUserInterface : public QMainWindow
{
    Q_OBJECT
public:
    explicit LauncherUserInterface(QWidget *parent = nullptr);
    void setupUI();

signals:

private:
    static const QString UI_FILE_PATH;
};

#endif // LAUNCHERUSERINTERFACE_H
