#include "ConfigManager.h"
#include <QString>
#include <QFont>


QFont ConfigManager::getFontSetting() const {
    QString fontFamily = getSetting("style/Font", "Arial").toString();
    int fontSize = getSetting("style/FontSize", "15").toInt();
    return QFont(fontFamily, fontSize);
}

QString ConfigManager::getStyleSheet() const {
    QString backgroundColor = getSetting("style/BackgroundColor", "#FFFFFF").toString();
    QString textColor = getSetting("style/TextColor", "#000000").toString();
    QString padding = getSetting("style/Padding", "10").toString();
    return QString("QTextEdit {"
                   "background-color: %1;"
                   "color: %2;"
                   "padding: %3px;"
                   "}").arg(backgroundColor, textColor, padding);
}
