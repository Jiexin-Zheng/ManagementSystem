#include "sqldao.h"
#include "sqlmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

SqlDao::SqlDao()
{

}

bool SqlDao::insertUser(const User &user) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("insert into UserInfo(username,userpwd,areaId)values(:username,:userpwd,:areaId);");
    query.bindValue(":username", user.getUsername());
    query.bindValue(":userpwd", user.getUserpwd());
    query.bindValue(":areaId", user.getAreaId());

    if(!(ret = query.exec())){
        qDebug()<<"debug in insertUser: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::deleteUser(const User &user) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("delete from UserInfo where username = :username;");
    query.bindValue(":username", user.getUsername());

    if(!(ret = query.exec())){
        qDebug()<<"debug in deletetUser: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;

}

bool SqlDao::searchUserByUsername(User &users) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select username from UserInfo where username = :username;");
    query.bindValue(":username", users.getUsername());

    if(!(ret = query.exec())){
        qDebug()<<"debug in searchUserByUsername: "<<query.lastError().text();
    }else{
        while(query.next()){
            qDebug()<<"search hahahaha";
            QString username = query.value(0).toString();
            QString userpwd = query.value(1).toString();
            bool online = query.value(2).toBool();
            QString areaId_tmp = query.value(3).toString();

            User user(username,userpwd,online,areaId_tmp);
            users = user;
        }
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::searchUserByUsername(const QString &username) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select username from UserInfo where username = :username;");
    query.bindValue(":username", username);

    if(!(ret = query.exec())){
        qDebug()<<"debug in searchUserByUsername: "<<query.lastError().text();
    }else{
        if(query.next()){
            ret = true;
        }else{
            ret = false;
        }
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::searchUserByOnline(const QString& username, bool online)const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select username from UserInfo where username = :username and online = :online;");
    query.bindValue(":username", username);
    query.bindValue(":online", online);

    if(!(ret = query.exec())){
        qDebug()<<query.lastError().text();
    }else{
        if(query.next()){
            ret = true;
        }else{
            ret = false;
        }
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::searchUserByUserpwd(const QString &username, const QString &userpwd) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select username from UserInfo where username = :username and userpwd = :userpwd;");
    query.bindValue(":username", username);
    query.bindValue(":userpwd", userpwd);

    if(!(ret = query.exec())){
        qDebug()<<"debug in searchUserByUserpwd: "<<query.lastError().text();
    }else{
        if(query.next()){
            ret = true;
        }else{
            ret = false;
        }
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

QVector<User> SqlDao::searchUserByArea(const QString& areaId)const
{
    QVector<User> users;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select username from UserInfo where areaId = :areaId;");
    query.bindValue(":areaId", areaId);

    if(!query.exec()){
        qDebug()<<"debug in searchUserByArea: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString username = query.value(0).toString();
            QString userpwd = query.value(1).toString();
            bool online = query.value(2).toBool();
            QString areaId_tmp = query.value(3).toString();

            User user(username,userpwd,online,areaId_tmp);
            users.push_back(user);
        }
    }

    SqlManager::getInstance()->closeDatabase();
    return users;
}

bool SqlDao::updateUesrpwd(const QString &username, const QString &userpwd) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("update UserInfo set userpwd = :userpwd where username = :username;");
    query.bindValue(":userpwd", userpwd);
    query.bindValue(":username", username);

    if(!(ret = query.exec())){
        qDebug()<<"debug in updateUesrpwd: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::updateUserAreaId(const QString &username, QString areaId) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("update UserInfo set areaId = :areaId where username = :username;");
    query.bindValue(":areaId", areaId);
    query.bindValue(":username", username);

    if(!(ret = query.exec())){
        qDebug()<<"debug in updateUserAreaId: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::updateUserOnline(const QString &username, bool online)const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("update UserInfo set online = :online where username = :username;");
    query.bindValue(":online", online);
    query.bindValue(":username", username);

    if(!(ret = query.exec())){
        qDebug()<<"debug in updateUserOnline: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

QVector<User> SqlDao::sortAllUserByName() const
{
    QVector<User> users;

    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from UserInfo order by username desc;");
    if(!query.exec()){
        qDebug()<<"debug in sortAllUserByName: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString username = query.value(0).toString();
            QString userpwd = query.value(1).toString();
            bool online = query.value(2).toBool();
            QString adminId = query.value(3).toString();

            User user(username,userpwd,online,adminId);
            users.push_back(user);
        }
    }

    SqlManager::getInstance()->closeDatabase();

    return users;
}

QVector<User> SqlDao::sortAllUserByAreaId() const
{
    QVector<User> users;

    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from UserInfo order by areaId desc;");
    if(!query.exec()){
        qDebug()<<"debug in sortAllUserByAreaId: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString username = query.value(0).toString();
            QString userpwd = query.value(1).toString();
            bool online = query.value(2).toBool();
            QString adminId = query.value(3).toString();

            User user(username,userpwd,online,adminId);
            users.push_back(user);
        }
    }

    SqlManager::getInstance()->closeDatabase();

    return users;
}

//bool deleteEquipment(const Equipment& equipment)const;

bool SqlDao::insertEquipment(const Equipment &equipment) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("insert into EquipmentInfo(name,\
                  category,\
                  brand,\
                  matchId,\
                  code,\
                  specification,\
                  source,\
                  state,\
                  starttime,\
                  limittime,\
                  note,\
                  modelNumber,\
                  areaId)values(:name,\
            :category,\
            :brand,\
            :matchId,\
            :code,\
            :specification,\
            :source,\
            :state,\
            :starttime,\
            :limittime,\
            :note,\
            :modelNumber,\
            :areaId);");
    query.bindValue(":name", equipment.getName());
    query.bindValue(":category", equipment.getCategory());
    query.bindValue(":brand", equipment.getBrand());
    query.bindValue(":matchId",equipment.getMatchId());
    query.bindValue(":code", equipment.getCode());
    query.bindValue(":specification",equipment.getSpecification());
    query.bindValue(":source", equipment.getSource());
    query.bindValue(":state", equipment.getState());
    query.bindValue(":starttime", equipment.getStarttime());
    query.bindValue(":limittime", equipment.getLimittime());
    query.bindValue(":note", equipment.getNote());
    query.bindValue(":modelNumber", equipment.getModelNumber());
    query.bindValue(":areaId", equipment.getAreaId());

    if(!(ret = query.exec())){
        qDebug()<<"debug in insertEquipment: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::deleteEquipment(const Equipment &equipment) const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("delete from EquipmentInfo where matchId = :matchId;");
    query.bindValue(":matchId", equipment.getMatchId());

    if(!(ret = query.exec())){
        qDebug()<<"debug in deletetEquipment: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;

}

QVector<Equipment> SqlDao::searchEquipmentByName(const QString &name) const
{
    QVector<Equipment> equipments;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from EquipmentInfo where name = :name;");
    query.bindValue(":name", name);

    if(!query.exec()){
        qDebug()<<"debug in searchEquipmentByName: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString name = query.value(0).toString();
            QString category = query.value(1).toString();
            QString brand = query.value(2).toString();
            QString matchId = query.value(3).toString();
            QString code = query.value(4).toString();
            QString specification = query.value(5).toString();
            QString source = query.value(6).toString();
            QString state = query.value(7).toString();
            QString starttime = query.value(8).toString();
            QString limittime = query.value(9).toString();
            QString note = query.value(10).toString();
            QString modelNumber = query.value(11).toString();
            QString areaId = query.value(12).toString();

            Equipment equipment(name,\
                                category,\
                                brand,\
                                matchId,\
                                code,\
                                specification,\
                                source,\
                                state,\
                                starttime,\
                                limittime,\
                                note,\
                                modelNumber,\
                                areaId);

            equipments.push_back(equipment);
        }
    }

    SqlManager::getInstance()->closeDatabase();
    return equipments;
}

Equipment SqlDao::searchEquipmentByMatchId(const QString& matchId, int& result)const
{
    Equipment equipments;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;

    query.prepare("select * from EquipmentInfo where matchId = :matchId;");
    query.bindValue(":matchId", matchId);

    if(!query.exec()){
        qDebug()<<"debug in searchEquipmentByMatchId: "<<query.lastError().text();
    }else{
        while(query.next()){
            result = 1;
            QString name = query.value(0).toString();
            QString category = query.value(1).toString();
            QString brand = query.value(2).toString();
            QString matchId = query.value(3).toString();
            QString code = query.value(4).toString();
            QString specification = query.value(5).toString();
            QString source = query.value(6).toString();
            QString state = query.value(7).toString();
            QString starttime = query.value(8).toString();
            QString limittime = query.value(9).toString();
            QString note = query.value(10).toString();
            QString modelNumber = query.value(11).toString();
            QString areaId = query.value(12).toString();

            Equipment equipment(name,\
                                category,\
                                brand,\
                                matchId,\
                                code,\
                                specification,\
                                source,\
                                state,\
                                starttime,\
                                limittime,\
                                note,\
                                modelNumber,\
                                areaId);
            equipments = equipment;
        }
    }
    SqlManager::getInstance()->closeDatabase();
    return equipments;
}

QVector<Equipment> SqlDao::searchEquipmentByArea(const QString& areaId)const
{
    QVector<Equipment> equipments;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from EquipmentInfo where areaId = :areaId;");
    query.bindValue(":areaId", areaId);

    if(!query.exec()){
        qDebug()<<"debug in searchEquipmentByArea: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString name = query.value(0).toString();
            QString category = query.value(1).toString();
            QString brand = query.value(2).toString();
            QString matchId = query.value(3).toString();
            QString code = query.value(4).toString();
            QString specification = query.value(5).toString();
            QString source = query.value(6).toString();
            QString state = query.value(7).toString();
            QString starttime = query.value(8).toString();
            QString limittime = query.value(9).toString();
            QString note = query.value(10).toString();
            QString modelNumber = query.value(11).toString();
            QString areaId = query.value(12).toString();

            Equipment equipment(name,\
                                category,\
                                brand,\
                                matchId,\
                                code,\
                                specification,\
                                source,\
                                state,\
                                starttime,\
                                limittime,\
                                note,\
                                modelNumber,\
                                areaId);

            equipments.push_back(equipment);
        }
    }

    SqlManager::getInstance()->closeDatabase();
    return equipments;
}

bool SqlDao::updateEquipment(const Equipment& equipment)const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    qDebug()<<"update !!"<<equipment.getMatchId();

    QSqlQuery query;

    query.prepare("update EquipmentInfo set name = :name,\
                  category = :category,\
                  brand = :brand,\
                  matchId = :matchId,\
                  code = :code,\
                  specification = :specification,\
                  source = :source,\
                  state = :state,\
                  starttime = :starttime,\
                  limittime = :limittime,\
                  note = :note,\
                  modelNumber = :modelNumber,\
                  areaId = :areaId where matchId = :matchId;");
            query.bindValue(":name", equipment.getName());
            query.bindValue(":category", equipment.getCategory());
            query.bindValue(":brand", equipment.getBrand());
            query.bindValue(":matchId",equipment.getMatchId());
            query.bindValue(":code", equipment.getCode());
            query.bindValue(":specification",equipment.getSpecification());
            query.bindValue(":source", equipment.getSource());
            query.bindValue(":state", equipment.getState());
            query.bindValue(":starttime", equipment.getStarttime());
            query.bindValue(":limittime", equipment.getLimittime());
            query.bindValue(":note", equipment.getNote());
            query.bindValue(":modelNumber", equipment.getModelNumber());
            query.bindValue(":areaId", equipment.getAreaId());
    if(!(ret = query.exec())){
        qDebug()<<"debug in updateEquipment: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

QVector<Equipment> SqlDao::sortAllEquipmentByMatchId()const
{
    QVector<Equipment> equipments;

    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from EquipmentInfo order by matchId desc;");
    if(!query.exec()){
        qDebug()<<"debug in sortAllEquipmentByMatchId: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString name = query.value(0).toString();
            QString category = query.value(1).toString();
            QString brand = query.value(2).toString();
            QString matchId = query.value(3).toString();
            QString code = query.value(4).toString();
            QString specification = query.value(5).toString();
            QString source = query.value(6).toString();
            QString state = query.value(7).toString();
            QString starttime = query.value(8).toString();
            QString limittime = query.value(9).toString();
            QString note = query.value(10).toString();
            QString modelNumber = query.value(11).toString();
            QString areaId = query.value(12).toString();

            Equipment equipment(name,\
                                category,\
                                brand,\
                                matchId,\
                                code,\
                                specification,\
                                source,\
                                state,\
                                starttime,\
                                limittime,\
                                note,\
                                modelNumber,\
                                areaId);

            equipments.push_back(equipment);
        }
    }

    SqlManager::getInstance()->closeDatabase();

    return equipments;
}

QVector<Equipment> SqlDao::sortAllEquipmentByArea()const
{
    QVector<Equipment> equipments;

    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from EquipmentInfo order by areaId desc;");
    if(!query.exec()){
        qDebug()<<"debug in sortAllEquipmentByArea: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString name = query.value(0).toString();
            QString category = query.value(1).toString();
            QString brand = query.value(2).toString();
            QString matchId = query.value(3).toString();
            QString code = query.value(4).toString();
            QString specification = query.value(5).toString();
            QString source = query.value(6).toString();
            QString state = query.value(7).toString();
            QString starttime = query.value(8).toString();
            QString limittime = query.value(9).toString();
            QString note = query.value(10).toString();
            QString modelNumber = query.value(11).toString();
            QString areaId = query.value(12).toString();

            Equipment equipment(name,\
                                category,\
                                brand,\
                                matchId,\
                                code,\
                                specification,\
                                source,\
                                state,\
                                starttime,\
                                limittime,\
                                note,\
                                modelNumber,\
                                areaId);

            equipments.push_back(equipment);
        }
    }

    SqlManager::getInstance()->closeDatabase();

    return equipments;
}

QVector<Equipment> SqlDao::sortAllEquipmentByName()const
{
    QVector<Equipment> equipments;

    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from EquipmentInfo order by name desc;");
    if(!query.exec()){
        qDebug()<<"debug in sortAllEquipmentByName: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString name = query.value(0).toString();
            QString category = query.value(1).toString();
            QString brand = query.value(2).toString();
            QString matchId = query.value(3).toString();
            QString code = query.value(4).toString();
            QString specification = query.value(5).toString();
            QString source = query.value(6).toString();
            QString state = query.value(7).toString();
            QString starttime = query.value(8).toString();
            QString limittime = query.value(9).toString();
            QString note = query.value(10).toString();
            QString modelNumber = query.value(11).toString();
            QString areaId = query.value(12).toString();

            Equipment equipment(name,\
                                category,\
                                brand,\
                                matchId,\
                                code,\
                                specification,\
                                source,\
                                state,\
                                starttime,\
                                limittime,\
                                note,\
                                modelNumber,\
                                areaId);

            equipments.push_back(equipment);
        }
    }

    SqlManager::getInstance()->closeDatabase();

    return equipments;
}

bool SqlDao::insertMaintain(const Maintain& maintain)const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("insert into MaintainInfo(id,\
                  matchId,\
                  date,\
                  maintainer,\
                  state,\
                  problem,\
                  details,\
                  faultLevel)values(:id,\
                                    :matchId,\
                                    :date,\
                                    :maintainer,\
                                    :state,\
                                    :problem,\
                                    :details,\
                                    :faultLevel);");
    query.bindValue(":id", maintain.getId());
    query.bindValue(":matchId", maintain.getMatchId());
    query.bindValue(":date", maintain.getDate());
    query.bindValue(":maintainer", maintain.getMaintainer());
    query.bindValue(":state", maintain.getState());
    query.bindValue(":problem", maintain.getProblem());
    query.bindValue(":details", maintain.getDetails());
    query.bindValue(":faultLevel", maintain.getFaultLevel());

    if(!(ret = query.exec())){
        qDebug()<<"debug in insertMaintain: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

bool SqlDao::deleteMaintain(const Maintain& maintain)const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("delete from MaintainInfo where id = :id;");
    query.bindValue(":id", maintain.getId());

    if(!(ret = query.exec())){
        qDebug()<<"debug in deletetMaintain: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;

}

bool SqlDao::updateMaintain(const Maintain& maintain)const
{
    bool ret = false;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;

    query.prepare("update MaintainInfo set id = :id,\
                  matchId = :matchId,\
                  date = :date,\
                  maintainer = :maintainer,\
                  state = :state,\
                  problem = :problem,\
                  details = :details,\
                  faultLevel = :faultLevel,\
                  where id = :id;");

    query.bindValue(":id", maintain.getId());
    query.bindValue(":matchId", maintain.getMatchId());
    query.bindValue(":date", maintain.getDate());
    query.bindValue(":maintainer", maintain.getMaintainer());
    query.bindValue(":state", maintain.getState());
    query.bindValue(":problem", maintain.getProblem());
    query.bindValue(":details", maintain.getDetails());
    query.bindValue(":faultLevel", maintain.getFaultLevel());

    if(!(ret = query.exec())){
        qDebug()<<"debug in updateMaintain: "<<query.lastError().text();
    }

    SqlManager::getInstance()->closeDatabase();
    return ret;
}

Maintain SqlDao::searchMaintainById(const QString& id,int& result)const
{

    Maintain maintains;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from MaintainInfo where Id = :Id;");
    query.bindValue(":Id", id);

    if(!query.exec()){
        qDebug()<<"debug in searchMaintainById: "<<query.lastError().text();
    }else{
        while(query.next()){
            result = 1;
            QString id = query.value(0).toString();
            QString matchId = query.value(1).toString();
            QString date = query.value(2).toString();
            QString maintainer = query.value(3).toString();
            QString state = query.value(4).toString();
            QString problem = query.value(5).toString();
            QString details = query.value(6).toString();
            QString faultLevel = query.value(7).toString();

            Maintain maintain(id,\
                                matchId,\
                                date,\
                                maintainer,\
                                state,\
                                problem,\
                                details,\
                                faultLevel);
            maintains = maintain;
        }
    }
    SqlManager::getInstance()->closeDatabase();
    return maintains;
}

QVector<Maintain>SqlDao::searchMaintainByMatchId(const QString& matchId)const
{
    QVector<Maintain> maintains;
    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from MaintainInfo where matchId = :matchId;");
    query.bindValue(":matchId", matchId);

    if(!query.exec()){
        qDebug()<<"debug in searchMaintainByMatchId: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString id = query.value(0).toString();
            QString matchId = query.value(1).toString();
            QString date = query.value(2).toString();
            QString maintainer = query.value(3).toString();
            QString state = query.value(4).toString();
            QString problem = query.value(5).toString();
            QString details = query.value(6).toString();
            QString faultLevel = query.value(7).toString();

            Maintain maintain(id,\
                                matchId,\
                                date,\
                                maintainer,\
                                state,\
                                problem,\
                                details,\
                                faultLevel);

            maintains.push_back(maintain);
        }
    }

    SqlManager::getInstance()->closeDatabase();
    return maintains;
}

QVector<Maintain>SqlDao::sortAllMaintainByTime()const
{
    QVector<Maintain> maintains;

    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from MaintainInfo order by date desc;");
    if(!query.exec()){
        qDebug()<<"debug in sortAllMaintainByTime: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString id = query.value(0).toString();
            QString matchId = query.value(1).toString();
            QString date = query.value(2).toString();
            QString maintainer = query.value(3).toString();
            QString state = query.value(4).toString();
            QString problem = query.value(5).toString();
            QString details = query.value(6).toString();
            QString faultLevel = query.value(7).toString();

            Maintain maintain(id,\
                                matchId,\
                                date,\
                                maintainer,\
                                state,\
                                problem,\
                                details,\
                                faultLevel);

            maintains.push_back(maintain);
        }
    }

    SqlManager::getInstance()->closeDatabase();

    return maintains;
}

QVector<Maintain>SqlDao::sortAllMaintainByMatchId()const
{
    QVector<Maintain> maintains;

    SqlManager::getInstance()->openDatabase();

    QSqlQuery query;
    query.prepare("select * from MaintainInfo order by matchId desc;");
    if(!query.exec()){
        qDebug()<<"debug in sortAllMaintainByMatchId: "<<query.lastError().text();
    }else{
        while(query.next()){
            QString id = query.value(0).toString();
            QString matchId = query.value(1).toString();
            QString date = query.value(2).toString();
            QString maintainer = query.value(3).toString();
            QString state = query.value(4).toString();
            QString problem = query.value(5).toString();
            QString details = query.value(6).toString();
            QString faultLevel = query.value(7).toString();

            Maintain maintain(id,\
                                matchId,\
                                date,\
                                maintainer,\
                                state,\
                                problem,\
                                details,\
                                faultLevel);

            maintains.push_back(maintain);
        }
    }

    SqlManager::getInstance()->closeDatabase();

    return maintains;
}
