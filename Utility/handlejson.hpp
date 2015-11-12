#ifndef HANDLEJSON
#define HANDLEJSON

#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>
#include <QString>

namespace Utility
{
    class HandleJson
    {
        public:
        HandleJson() = default;
        HandleJson(QString const& pJson);

        bool keyExist(QString const& pKey) const;

        QJsonValue getKey(QString const& pKey, QJsonValue pDefaultValue = QJsonValue()) const;
        void setKey(QString const& pKey, QJsonValue const& pValue);

        QString toString() const;

        private:
        QJsonObject m_json;
    };
}

#endif // HANDLEJSON

