#include "clienthandler.h"

ClientHandler::ClientHandler(qintptr socketDescriptor, QObject *parent)
    : QObject{parent}, m_socketDescriptor{socketDescriptor}
{
    ClientLogs = new Logger("./ClientLogs.log");
    l_handler = new requestHandler(); //it have to changed to be QObject to use parent child or destroy it with a destructor
}

void ClientHandler::disconnected()
{
    ClientLogs->log("socket has disconnected..");
    qInfo() << QThread::currentThread();
    socket->deleteLater();
}

void ClientHandler::readyRead()
{
    QByteArray data = socket->readAll();
    qInfo()<<QString::fromUtf8(data);

    QByteArray l_response = l_handler->handleReaquest(data);
    //block
    QJsonDocument l_doc = QJsonDocument::fromJson(l_response);
    QJsonObject l_obj = l_doc.object();
    qInfo() << "ResponseID>>>>>>>: " << l_obj.value("ResponseID").toString().toInt();

    socket->write(l_response);
    socket->waitForBytesWritten();

    qInfo() << QThread::currentThread();

}

void ClientHandler::run()
{
    socket = new QTcpSocket();
    QEventLoop loop;
    if(!socket->setSocketDescriptor(m_socketDescriptor))
    {
        ClientLogs->log("Failed"); //have to be changed to log.
        qCritical() << socket->errorString();
        ClientLogs->log(socket->errorString());
        delete socket;
        return;
    }

    //we've the use Qt::DirectConnection when we connect signals and slots to ensure that slots will be invoked in the singling thread.
    connect(socket, &QTcpSocket::disconnected, &loop, &QEventLoop::quit, Qt::DirectConnection);
    connect(socket, &QTcpSocket::disconnected, this, &ClientHandler::disconnected, Qt::DirectConnection);
    connect(socket, &QTcpSocket::readyRead, this, &ClientHandler::readyRead, Qt::DirectConnection);
    qInfo() << QThread::currentThread();

    loop.exec();
}
