#include "handlejson.hpp"

Utility::HandleJson::HandleJson(const QString &pJson)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(pJson.toUtf8());

    m_json = jsonDocument.object();
}

bool Utility::HandleJson::keyExist(const QString &pKey) const
{
    return m_json.contains(pKey);
}

QJsonValue Utility::HandleJson::getKey(const QString &pKey, QJsonValue pDefaultValue) const
{
    if (m_json.contains(pKey))
        return m_json[pKey];
    else
        return pDefaultValue;
}

void Utility::HandleJson::setKey(const QString &pKey, const QJsonValue &pValue)
{
    m_json.insert(pKey, pValue);
}

QString Utility::HandleJson::toString() const
{
    QJsonDocument doc(m_json);

    return doc.toJson(QJsonDocument::Compact);
}
