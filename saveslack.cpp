#include "saveslack.hpp"

SaveSlack::SaveSlack() : m_socket()
{
    Utility::ConnectSlack connectSlack{};
    QString wssUrl = connectSlack.getUrlWebSocket();

    m_socket.open(QUrl(wssUrl));

    connect(&m_socket, &QWebSocket::textMessageReceived, this, &SaveSlack::onMessage);
}

void SaveSlack::onMessage(QString const& message)
{
    qDebug() << message;
}
