#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QSqlDatabase>
//EquipmentInfo MaintainInfo
class SqlManager
{
private:
    SqlManager();
    QSqlDatabase db;
    static SqlManager* instance;
public:
    static SqlManager *getInstance();
    void openDatabase();
    void closeDatabase();
};

#endif // SQLMANAGER_H
