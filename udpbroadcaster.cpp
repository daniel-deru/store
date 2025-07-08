#include "UdpBroadcaster.h"
#include <QUdpSocket>
#include <QHostAddress>

UdpBroadcaster::UdpBroadcaster(const QString &xmlData, QObject *parent)
    : QThread(parent), xml(xmlData), socket(nullptr) {}

UdpBroadcaster::~UdpBroadcaster() {
    if (socket) {
        socket->close();
        delete socket;
    }
}

void UdpBroadcaster::run() {
    socket = new QUdpSocket();
    QByteArray data = xml.toUtf8();
    socket->writeDatagram(data, QHostAddress::Broadcast, 45454);
    msleep(100); // optional short delay to ensure sending
}
