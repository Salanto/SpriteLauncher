#ifndef SETTINGSUSERINTERFACE_H
#define SETTINGSUSERINTERFACE_H

#include <QWidget>

namespace ui {

class SettingsUserDialog : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsUserDialog(QWidget *parent = nullptr);

signals:
};

} // namespace ui

#endif // SETTINGSUSERINTERFACE_H
