#include "ConfigManager.h"

ConfigManager::ConfigManager(const QString& filename) : settings(filename, QSettings::IniFormat) {}

QString ConfigManager::getSetting(const QString& key, const QString& defaultValue) {
    return settings.value(key, defaultValue).toString();
}
