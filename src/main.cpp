#include "JottyWindow.h"
#include "ConfigManager.h"
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QStandardPaths>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QString configFilePath;

    if (argc > 1) {
        configFilePath = argv[1];
    } else {
        QString defaultConfigPath = QDir(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)).filePath(".config/jotty/jotty.conf");
        if (QFile::exists(defaultConfigPath)) {
            configFilePath = defaultConfigPath;
        }
    }

    ConfigManager config;
    if (!configFilePath.isEmpty() && QFile::exists(configFilePath)) {
        config.loadConfig(configFilePath);
    }

    JottyWindow window;
    window.setFont(config.getFontSetting());
    window.setStyleSheet(config.getStyleSheet());
    window.setWindowTitle("Jotty: Scribble Today, Remember Tomorrow");
    window.setGeometry(100, 100, 600, 400);
    window.show();

    return app.exec();
}
