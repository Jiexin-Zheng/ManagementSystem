#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include<QString>

class Equipment
{
private:
    QString name;
    QString category;
    QString brand;
    QString matchId;
    QString code;
    QString specification;
    QString source;
    QString state;
    QString starttime;
    QString limittime;
    QString note;
    QString modelNumber;
    QString areaId;
public:
    Equipment(QString name = "",
    QString category = "",
    QString brand = "",
    QString matchId = "",
    QString code = "",
    QString specification = "",
    QString source = "",
    QString state = "",
    QString starttime = "",
    QString limittime = "",
    QString note = "",
    QString modelNumber = "",
    QString areaId = "");

    QString getName() const;
    void setName(const QString &value);
    QString getCategory() const;
    void setCategory(const QString &value);
    QString getBrand() const;
    void setBrand(const QString &value);
    QString getCode() const;
    void setCode(const QString &value);
    QString getMatchId() const;
    void setMatchId(const QString &value);
    QString getStarttime() const;
    void setStarttime(const QString &value);
    QString getSpecification() const;
    void setSpecification(const QString &value);
    QString getSource() const;
    void setSource(const QString &value);
    QString getLimittime() const;
    void setLimittime(const QString &value);
    QString getNote() const;
    void setNote(const QString &value);
    QString getState() const;
    void setState(const QString &value);
    QString getModelNumber() const;
    void setModeNumber(const QString &value);
    QString getAreaId() const;
    void setAreaId(const QString &value);

    QString toString()const;
};

#endif // EQUIPMENT_H
