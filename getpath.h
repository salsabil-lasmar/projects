#ifndef GETPATH_H
#define GETPATH_H

#include<QString>
class getpath
{
public:
    getpath();
    QList<QString> getClientList();
    QList<QString> getPathList();
    QString replaceNameClient(QString path , QString Client);
    QString pathGlobal,pathInclude;
};

#endif // GETPATH_H
