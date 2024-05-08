#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

#include "view.h"
#include "control.h"
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    ~Client();

signals:

private slots:

private:
    View *m_view;
    Control *m_control;
};

#endif // CLIENT_H
