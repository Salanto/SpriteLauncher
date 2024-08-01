#include "settingsuserdialog.h"

#include <QDebug>

ui::SettingsUserDialog::SettingsUserDialog(QWidget *parent)
    : QWidget{parent}
{
    qDebug() << "[SettingsUserDialog]::CTOR: Creating SettingsUserDialog at" << this;
}
