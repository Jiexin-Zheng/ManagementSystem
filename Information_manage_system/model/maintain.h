#ifndef MAINTAIN_H
#define MAINTAIN_H

#include<QString>

class Maintain
{
private:
    QString id;
    QString matchId;
    QString date;
    QString maintainer;
    QString state;
    QString problem;
    QString details;
    QString faultLevel;

public:
    Maintain(QString id = "",
    QString matchId = "",
    QString date = "",
    QString maintainer = "",
    QString state = "",
    QString problem = "",
    QString details = "",
    QString faultLevel = 0);

    QString getId() const;
    void setId(const QString &value);
    QString getDate() const;
    void setDate(const QString &value);
    QString getMaintainer() const;
    void setMaintainer(const QString &value);
    QString getProblem() const;
    void setProblem(const QString &value);
    QString getMatchId() const;
    void setMatchId(const QString &value);
    QString getDetails() const;
    void setDetails(const QString &value);
    QString getState() const;
    void setState(const QString &value);
    QString getFaultLevel()const;
    void setFaultLevel(const int &value);

    QString toString() const;
};

#endif // MAINTAIN_H
