#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>
#include "logger.h"
#include "clienthandler.h"
#include "datebasehandler.h" // addition
class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
signals:

public slots:
    void startServer(qint16 port);
    void quitServer();


    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

private:
    QThreadPool *pool;
    Logger *ServerLogs;
    // DateBaseHandler *m_dataBase;
    // DateBaseHandler dataBaseManager;
};


#endif // SERVER_H
