#ifndef CDEFINE_H
#define CDEFINE_H
#include<QString>
#include<QVector>
enum State { activated, deactivated, pending};
class CDefine
{
public:
    CDefine();

    QString name;
    QString value;
    State eState;
    QVector<QString> parent;
    QString type_file;
};

#endif // CDEFINE_H

