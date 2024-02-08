#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QSettings>

class ConfigManager {
public:
    ConfigManager(const QString& filename);

    QString getSetting(const QString& key, const QString& defaultValue = QString());

private:
    QSettings settings;
};

#endif
