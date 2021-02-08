#ifndef SQLDAO_H
#define SQLDAO_H

#include "model/user.h"
#include "model/maintain.h"
#include "model/equipment.h"
#include <QVector>

class SqlDao
{
public:
    SqlDao();

    bool insertUser(const User& user)const;
    bool deleteUser(const User& user)const;
    bool searchUserByUsername(User& users)const;
    bool searchUserByUsername(const QString& username)const;
    bool searchUserByOnline(const QString& username, bool online)const;
    bool searchUserByUserpwd(const QString& username, const QString& userpwd)const;
    QVector<User> searchUserByArea(const QString& areaId)const;
    bool updateUesrpwd(const QString& username, const QString& userpwd)const;
    bool updateUserOnline(const QString& username, bool online)const;
    bool updateUserAreaId(const QString& username, QString areaId)const;
    QVector<User> sortAllUserByAreaId()const;
    QVector<User> sortAllUserByName()const;

    bool insertEquipment(const Equipment& equipment)const;
    bool deleteEquipment(const Equipment& equipment)const;
    QVector<Equipment> searchEquipmentByName(const QString& name)const;
    Equipment searchEquipmentByMatchId(const QString& matchId,int& result)const;
    QVector<Equipment> searchEquipmentByArea(const QString& areaId)const;
    bool updateEquipment(const Equipment& equipment)const;
    QVector<Equipment> sortAllEquipmentByMatchId()const;
    QVector<Equipment> sortAllEquipmentByArea()const;
    QVector<Equipment> sortAllEquipmentByName()const;

    bool insertMaintain(const Maintain& maintain)const;
    bool deleteMaintain(const Maintain& maintain)const;
    bool updateMaintain(const Maintain& maintain)const;
    Maintain searchMaintainById(const QString& id,int& result)const;
    QVector<Maintain>searchMaintainByMatchId(const QString& matchId)const;
    QVector<Maintain>sortAllMaintainByTime()const;
    QVector<Maintain>sortAllMaintainByMatchId()const;
};

#endif // SQLDAO_H
