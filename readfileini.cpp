#include "readfileini.h"

#include<QSettings>
#include<QDebug>
readfileini::readfileini()
{
    QSettings* settings = new QSettings("C:\\Users\\salsabil.lasmar\\Desktop\\Settings.ini", QSettings::IniFormat);
    settings->beginGroup("paths");
    const QStringList childKeys = settings->childKeys();
    QStringList values;
    foreach (const QString &childKey, childKeys)
        values << settings->value(childKey).toString();
    qDebug()<<values;
    settings->endGroup();
}
