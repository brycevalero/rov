#ifndef XUDPSOCKET_H
#define XUDPSOCKET_H

#include <QObject>
#include <QUdpSocket>

#include "master/masterlib_global.h"
#include "master/socket/xhostaddress.h"

class MASTERLIBSHARED_EXPORT XUdpSocket: public QObject
{
    Q_OBJECT
public:
    explicit XUdpSocket(QObject *parent = 0);
    void initSocket(XHostAddress *address);

signals:
    void gotDatagrams(QByteArray datagram);

public slots:
    void readPendingDatagrams();
    bool writeData(QByteArray data, XHostAddress *address);

private:
    QUdpSocket *mSocket;

};

#endif // XUDPSOCKET_H