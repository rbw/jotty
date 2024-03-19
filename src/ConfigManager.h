#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QSettings>
#include <QString>
#include <QCoreApplication>

class ConfigManager {
private:
    QSettings* settings = nullptr; // allow reassignment

public:
    ConfigManager(const QString& filePath = QString()) {
        if (!filePath.isEmpty()) {
            settings = new QSettings(filePath, QSettings::IniFormat);
        } else {
            settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());
        }
    }

    // Clean up the QSettings pointer
    ~ConfigManager() {
        delete settings;
    }

    // Prevent copy and assignment to avoid double deletion issues
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    // Load a new configuration file at runtime
    void loadConfig(const QString &filePath) {
        delete settings; // Clean up the old QSettings object
        settings = new QSettings(filePath, QSettings::IniFormat); // Create a new QSettings object with the new path
    }

    QVariant getSetting(const QString &key, const QVariant &defaultValue) const {
        return settings->value(key, defaultValue);
    }

    QFont getFontSetting() const;
    QString getStyleSheet() const;
};
#endif
