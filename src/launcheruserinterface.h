#ifndef LAUNCHERUSERINTERFACE_H
#define LAUNCHERUSERINTERFACE_H

#include <QMainWindow>

namespace ui {
class LauncherUserInterface : public QMainWindow
{
    Q_OBJECT
public:
    explicit LauncherUserInterface(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event) override;

Q_SIGNALS:
    void closed();
    void settingsRequested();

private:
    static const QString UI_FILE_PATH;

    QWidget *ui_widget;
};
} // namespace ui

#endif // LAUNCHERUSERINTERFACE_H
