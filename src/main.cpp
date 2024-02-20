#include "JottyWindow.h"
#include "ConfigManager.h"
#include <QApplication>
#include <QFont>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ConfigManager config("jotty.conf");
    QString fontFamily = config.getSetting("style/Font", "Arial");
    int fontSize = config.getSetting("style/FontSize", "16").toInt();

    QString backgroundColor = config.getSetting("style/BackgroundColor", "#FFFFFF");
    QString textColor = config.getSetting("style/TextColor", "#000000");
    QString padding = config.getSetting("style/Padding", "10");

    QString styleSheet = QString("QTextEdit {"
                                 "background-color: %1;"
                                 "color: %2;"
                                 "padding: %3px;"
                                 "}").arg(backgroundColor, textColor, padding);

    QFont font(fontFamily, fontSize);

    JottyWindow window;
    window.setFont(font);
    window.setStyleSheet(styleSheet);
    window.setWindowTitle("Jotty: Scribble Today, Remember Tomorrow");
    window.show();

    return app.exec();
}
