#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <memory>
#include "settings.hpp"

namespace Utility
{
    class Database
    {
        public:
        std::unique_ptr<QSqlQuery> makeQuery(QString const& p_query);

        private:
        void initDb();

        static QSqlDatabase m_db;
    };
}

#endif // DATABASE_HPP

