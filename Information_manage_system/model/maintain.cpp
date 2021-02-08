#include "maintain.h"

QString Maintain::getId() const
{
    return id;
}

void Maintain::setId(const QString &value)
{
    id = value;
}

QString Maintain::getDate() const
{
    return date;
}

void Maintain::setDate(const QString &value)
{
    date = value;
}

QString Maintain::getMaintainer() const
{
    return maintainer;
}

void Maintain::setMaintainer(const QString &value)
{
    maintainer = value;
}

QString Maintain::getProblem() const
{
    return problem;
}

void Maintain::setProblem(const QString &value)
{
    problem = value;
}

QString Maintain::getMatchId() const
{
    return matchId;
}

void Maintain::setMatchId(const QString &value)
{
    matchId = value;
}

QString Maintain::getDetails() const
{
    return details;
}

void Maintain::setDetails(const QString &value)
{
    details = value;
}

QString Maintain::getState() const
{
    return state;
}

void Maintain::setState(const QString &value)
{
    state = value;
}

QString Maintain::getFaultLevel()const
{
    return faultLevel;
}

void Maintain::setFaultLevel(const int &value)
{
    faultLevel = value;
}

QString Maintain::toString()const
{
    QString str;
    str += "id: ";
    str += this->id;
    str += "match: ";
    str += this->matchId;
    str += "peoblem: ";
    str += this->problem;
    str += "details: ";
    str += this->details;
    str += "maintainer: ";
    str += this->maintainer;
    str += "date: ";
    str += this->date;
    str += "faultLevel: ";
    str += this->faultLevel;
    str += "state: ";
    str += this->state;

    return str;
}

Maintain::Maintain(QString id,
QString matchId,
QString date,
QString maintainer,
QString state,
QString problem,
QString details,
QString faultLevel)
    :id(id),
     matchId(matchId),
     date(date),
     maintainer(maintainer),
     state(state),
     problem(problem),
     details(details),
     faultLevel(faultLevel)
{

}
