#include "database.hpp"

QSqlDatabase Utility::Database::m_db = QSqlDatabase{};

void Utility::Database::initDb()
{
    if (m_db.isOpen())
        return;

    Settings setting{};

    QString db_host = setting.getSetting(KEY_DB_HOST).toString();
    QString db_name = setting.getSetting(KEY_DB_NAME).toString();
    QString db_user = setting.getSetting(KEY_DB_USER).toString();
    QString db_pass = setting.getSetting(KEY_DB_PASS).toString();
    unsigned int db_port = setting.getSetting(KEY_DB_PORT).toInt();

    // qDebug () << db_host << db_name << db_user << db_pass << db_port;

    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName(db_host);
    m_db.setDatabaseName(db_name);
    m_db.setUserName(db_user);
    m_db.setPassword(db_pass);
    m_db.setPort(db_port);

    bool ok = m_db.open();

    //qDebug() << "Last error database (init) :" << m_db.lastError().text();
    //qDebug() << "Status database :" << ok;

    if (!ok) {
        throw std::runtime_error("Database is not open");
    }
}

std::unique_ptr<QSqlQuery> Utility::Database::makeQuery(const QString &p_query)
{
    initDb();

    auto query = new QSqlQuery(m_db);

    query->prepare(p_query);

    return std::move(std::unique_ptr<QSqlQuery> (query));
}
