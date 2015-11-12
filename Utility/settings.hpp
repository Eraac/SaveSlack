#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QSettings>
#include <QString>

// Database
const QString KEY_DB_HOST   = "db_host";
const QString KEY_DB_NAME   = "db_name";
const QString KEY_DB_USER   = "db_user";
const QString KEY_DB_PASS   = "db_pass";
const QString KEY_DB_PORT   = "db_port";

// Params
const QString KEY_BASE_URL_AUTH = "slack_auth_url";
const QString KEY_SLACK_TOKEN = "slack_token";
const QString KEY_SLACK_TIMEOUT = "slack_auth_timeout";

// File
const QString FILE_INI = "settings.ini";

namespace Utility
{
    class Settings
    {
        public:
        QVariant getSetting(QString const& p_key, QVariant const& p_default_value = "");

        private:
        static QSettings m_ini;
    };
}

#endif // SETTINGS_HPP

