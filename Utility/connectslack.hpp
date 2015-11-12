#ifndef CONNECTSLACK_HPP
#define CONNECTSLACK_HPP

#include <QString>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QTimer>
#include <QElapsedTimer>
#include <QDebug>
#include "handlejson.hpp"
#include "settings.hpp"

namespace Utility
{
    class ConnectSlack : public QObject
    {
        Q_OBJECT

        public:
        ConnectSlack(QObject *p_parent = nullptr);
        QString getUrlWebSocket();

        private:
        QNetworkAccessManager m_network_manager;
        QNetworkRequest m_request;

        unsigned int getCodeResponse(QNetworkReply *reply) const;
        void waitResponse(QNetworkReply *p_reply);
    };
}

#endif // CONNECTSLACK_HPP

