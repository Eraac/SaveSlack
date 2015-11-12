#ifndef SAVESLACK_HPP
#define SAVESLACK_HPP

#include <QWebSocket>
#include <QString>
#include <QDebug>
#include "Utility/connectslack.hpp"
#include "Utility/handlejson.hpp"

class SaveSlack : public QObject
{
    Q_OBJECT

    public:
    SaveSlack();
    ~SaveSlack() = default;

    public slots:
    void onMessage(QString const& message);

    private:
    QWebSocket m_socket;
};

#endif // SAVESLACK_HPP

