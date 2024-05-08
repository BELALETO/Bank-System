#include "requesthandler.h"

requestHandler::requestHandler()
    :dataBaseManager{DateBaseHandler::getInstance()}
{
   // dataBaseManager = dataBaseManager.getInstance();
    qInfo()<<"db request"<<&dataBaseManager;
    requestLogs = new Logger("./requsetLogs.log");
}

QByteArray requestHandler::handleReaquest(QByteArray request)
{
    QJsonDocument doc = QJsonDocument::fromJson(request);

    QJsonObject requestObj = doc.object();

    QByteArray response;
    QJsonObject DB_response;

    int val = requestObj.value("RequestID").toString().toInt();
    qInfo() << "The value of Val: " << val;
    switch(val)
    {
    case LogIn_ID:
       DB_response = dataBaseManager.logIn(requestObj);
        qInfo() << "Login reached";
        break;
    case GetAccuont_ID:
        DB_response = dataBaseManager.getAccount_Number(requestObj);
        break;
    case ViewAccount_ID:
        DB_response = dataBaseManager.viewAccount_Balance(requestObj);
        break;
    case ViewTransactionHistory_ID:
        DB_response = dataBaseManager.viewTransaction_History(requestObj);
        break;
    case MakeTransaction_ID:
        DB_response = dataBaseManager.makeTransaction(requestObj);
        break;
    case TransferAmount_ID:
        DB_response = dataBaseManager.transferAmount(requestObj);
        break;
    case ViewBankDB_ID:
        DB_response = dataBaseManager.viewBankDB(requestObj);
        break;
    case CreateUser_ID:
        DB_response = dataBaseManager.createUser(requestObj);
         qInfo() << "create user reached";
         qInfo() << DB_response["ResponseID"].toString().toInt();
        break;
    case DeleteUser_ID:
        DB_response = dataBaseManager.deleteUser(requestObj);
        break;
    case UpDateUser_ID:
        DB_response = dataBaseManager.updateUser(requestObj);
        break;
    default:
        response.append(1);
    }
    QJsonDocument docResponse(DB_response);
    response = docResponse.toJson();
    return response;
}
