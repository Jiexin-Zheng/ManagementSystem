#include "equipment.h"

Equipment::Equipment(QString name,
QString category,
QString brand,
QString matchId,
QString code,
QString specification,
QString source,
QString state,
QString starttime,
QString limittime,
QString note,
QString modelNumber,
QString areaId)
    :name(name),
     category(category),
     brand(brand),
     matchId(matchId),
     code(code),
     specification(specification),
     source(source),
     state(state),
     starttime(starttime),
     limittime(limittime),
     note(note),
     modelNumber(modelNumber),
     areaId(areaId)
{

}

QString Equipment::getAreaId() const
{
    return areaId;
}

void Equipment::setAreaId(const QString &value)
{
    areaId = value;
}

QString Equipment::getName() const
{
    return name;
}

void Equipment::setName(const QString &value)
{
    name = value;
}

QString Equipment::getCategory() const
{
    return category;
}

void Equipment::setCategory(const QString &value)
{
    category = value;
}

QString Equipment::getBrand() const
{
    return brand;
}

void Equipment::setBrand(const QString &value)
{
    brand = value;
}

QString Equipment::getCode() const
{
    return code;
}

void Equipment::setCode(const QString &value)
{
    code = value;
}

QString Equipment::getMatchId() const
{
    return matchId;
}

void Equipment::setMatchId(const QString &value)
{
    matchId = value;
}

QString Equipment::getStarttime() const
{
    return starttime;
}

void Equipment::setStarttime(const QString &value)
{
    starttime = value;
}

QString Equipment::getSpecification() const
{
    return specification;
}

void Equipment::setSpecification(const QString &value)
{
    specification = value;
}

QString Equipment::getSource() const
{
    return source;
}

void Equipment::setSource(const QString &value)
{
    source = value;
}

QString Equipment::getLimittime() const
{
    return limittime;
}

void Equipment::setLimittime(const QString &value)
{
    limittime = value;
}

QString Equipment::getNote() const
{
    return note;
}

void Equipment::setNote(const QString &value)
{
    note = value;
}

QString Equipment::getState() const
{
    return state;
}

void Equipment::setState(const QString &value)
{
    state = value;
}

QString Equipment::getModelNumber() const
{
    return modelNumber;
}

void Equipment::setModeNumber(const QString &value)
{
    modelNumber = value;
}

QString Equipment::toString()const
{
    QString str;

    str += "name:";
    str += this->name;
    str += "category:";
    str += this->category;
    str += "note:";
    str += this->note;
    str += "code:";
    str += this->code;
    str += "state:";
    str += this->state;
    str += "starttime:";
    str += this->starttime;
    str += "limittime:";
    str += this->limittime;
    str += "brand:";
    str += this->brand;
    str += "matchId:";
    str += this->matchId;
    str += "source:";
    str += this->source;
    str += "specification:";
    str += this->specification;
    str += "modelNumber:";
    str += this->modelNumber;
    str += "areaId";
    str += this->areaId;

    return str;
}
