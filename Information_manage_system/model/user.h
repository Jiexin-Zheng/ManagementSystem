#ifndef USER_H
#define USER_H

#include<QString>

class User
{
private:
    QString username;
    QString userpwd;
    bool online;
    QString areaId;
public:
    User(QString username = "",QString userpwd = "",bool online = false,QString areaId = "");
    QString getUsername() const;
    void setUsername(const QString &value);
    QString getUserpwd() const;
    void setUserpwd(const QString &value);
    bool getOnline() const;
    void setOnline(bool value);
    QString getAreaId()const;
    void setAreaId(const QString &value);

    QString toString()const;
};

#endif // USER_H
