#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <assert.h>
#include <iostream>

class DataAccess {
public:
    DataAccess(const QString& path);
    QStringList filePaths;
    void IterateThroughJSON(QJsonObject& jsonObj);
private:
    QSqlDatabase m_db;
};



#endif // DATAACCESS_H
