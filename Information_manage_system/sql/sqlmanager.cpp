#include "sqlmanager.h"
#include <QDebug>
#include <QSqlError>

SqlManager::SqlManager()
    :db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName("data.db");
}

SqlManager* SqlManager::instance = new SqlManager;

SqlManager *SqlManager::getInstance()
{
    return instance;
}

void SqlManager::openDatabase()
{
    if(!db.open()){
        qDebug()<<"database open failed: "<<db.lastError().text();
    }else{
        qDebug()<<"database open successfully ";
    }
}

void SqlManager::closeDatabase()
{
    db.close();
}
