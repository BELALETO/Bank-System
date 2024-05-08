#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonParseError>
#include "logger.h"
#include "datebasehandler.h"

class requestHandler
{
public:
    requestHandler();
    QByteArray handleReaquest(QByteArray request);
    // DateBaseHandler databaseManger;

private:
    enum requestIDs{LogIn_ID, GetAccuont_ID, ViewAccount_ID, ViewTransactionHistory_ID, MakeTransaction_ID, TransferAmount_ID, ViewBankDB_ID, CreateUser_ID, DeleteUser_ID, UpDateUser_ID};
    Logger *requestLogs;
    DateBaseHandler& dataBaseManager;
};

#endif // REQUESTHANDLER_H
