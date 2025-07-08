#ifndef UDPBROADCASTER_H
#define UDPBROADCASTER_H

#include <QThread>
#include <QString>
#include <QUdpSocket>

// class QUdpSocket;

class UdpBroadcaster : public QThread {
    Q_OBJECT

public:
    explicit UdpBroadcaster(const QString &xmlData, QObject *parent = nullptr);
    ~UdpBroadcaster();

protected:
    void run() override;

private:
    QString xml;
    QUdpSocket *socket;
};

#endif // UDPBROADCASTER_H
