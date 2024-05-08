#ifndef DATEBASEHANDLER_H
#define DATEBASEHANDLER_H
#include <QDebug>
#include <QByteArray>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QMutex>
#include <QMutexLocker>
#include <QRandomGenerator>
#include "logger.h"

class DateBaseHandler
{
public:

    static DateBaseHandler& getInstance();
    //response methods:
    QJsonObject logIn(QJsonObject data);
    QJsonObject getAccount_Number(QJsonObject data);
    QJsonObject viewAccount_Balance(QJsonObject data);
    QJsonObject viewTransaction_History(QJsonObject data);
    QJsonObject makeTransaction(QJsonObject data);
    QJsonObject transferAmount(QJsonObject data);
    QJsonObject viewBankDB(QJsonObject data);
    QJsonObject createUser(QJsonObject data);
    QJsonObject deleteUser(QJsonObject data);
    QJsonObject updateUser(QJsonObject data);

private:
    DateBaseHandler();
    QFile *DataBaseFile;
    Logger *DBLogger;
    QMutex mutex;// maybe changed.
    static qint16 userID;
};

#endif // DATEBASEHANDLER_H
