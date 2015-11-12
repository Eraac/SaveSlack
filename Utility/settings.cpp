#include "settings.hpp"

QSettings Utility::Settings::m_ini(FILE_INI, QSettings::Format::IniFormat);

QVariant Utility::Settings::getSetting(const QString &p_key, const QVariant &p_default_value)
{
    return m_ini.value(p_key, p_default_value);
}
