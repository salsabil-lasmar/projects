#ifndef CDEFINELIST_H
#define CDEFINELIST_H
#include"cdefine.h"
#include<QString>
#include<QMap>

class CDefineList
{
public:
    CDefineList();
    QMap<QString, CDefine> mDefineList;
    void setDefineList(QString path);
    int pendingDefines = 0;
    QVector<QString> parents;
    void managePendingPreprocessor();
    void init();
    void  undefinePreprocessor(QString sNameUndef);

};

#endif // CDEFINELIST_H
