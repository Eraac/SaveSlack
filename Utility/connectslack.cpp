#include "connectslack.hpp"

Utility::ConnectSlack::ConnectSlack(QObject *p_parent) : QObject(p_parent),
m_network_manager(), m_request()
{
    Settings setting{};

    QString urlAuth{setting.getSetting(KEY_BASE_URL_AUTH).toString()};
    QString token{setting.getSetting(KEY_SLACK_TOKEN).toString()};

    QString stringUrl = QString("%1?token=%2")
                            .arg(urlAuth).arg(token);

    QUrl url{stringUrl};

    m_request.setUrl(url);
}

QString Utility::ConnectSlack::getUrlWebSocket()
{
    auto reply = m_network_manager.get(m_request);

    waitResponse(reply);

    auto codeResponse = getCodeResponse(reply);

    QString url;

    if (200 == codeResponse)
    {
        HandleJson handleJson{reply->readAll()};
        url = handleJson.getKey("url").toString();
    }

    return std::move(url);
}

void Utility::ConnectSlack::waitResponse(QNetworkReply *p_reply)
{
    Settings setting{};

    unsigned int timeout = setting.getSetting(KEY_SLACK_TIMEOUT).toInt();

    QElapsedTimer timer{};
    timer.start();

    QEventLoop loop;
    QTimer time;
    time.setInterval(timeout);
    time.setSingleShot(true);
    connect(p_reply, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&time, SIGNAL(timeout()), &loop, SLOT(quit()));
    loop.exec();
}

unsigned int Utility::ConnectSlack::getCodeResponse(QNetworkReply *reply) const
{
    if (!reply->isFinished())
        return 999;

    return reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
}




























