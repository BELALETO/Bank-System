#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent}
{
    // m_dataBase = new DateBaseHandler();
    qInfo()<<"db server"<< &(DateBaseHandler::getInstance());
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(200);

    ServerLogs = new Logger("./serverLogs");
}

Server::~Server()
{
    // delete m_dataBase;
    delete pool;
}

void Server::startServer(qint16 port)
{
    if(!this->listen(QHostAddress::Any, port))
    {
        ServerLogs->log("Faild to Initialzie server!!");
        qInfo() << this->errorString();
        return;
    }
    ServerLogs->log ("Listening on port: " + QString::number(port));
    qInfo() << ("Listening on port: " + QString::number(port));
}



void Server::quitServer()
{
    ServerLogs->log("Closing server...");
    delete pool;
    this->close();
}

void Server::incomingConnection(qintptr handle)
{
    qInfo() << QThread::currentThread();
    ClientHandler *handler = new ClientHandler(handle); //creating  a new connection in another thread.
    handler->setAutoDelete(true);
    pool->start(handler);
}

