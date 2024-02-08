#ifndef JOTTYEDITOR_H
#define JOTTYEDITOR_H

#include <QTextEdit>

class JottyEditor : public QTextEdit {
Q_OBJECT

public:
    explicit JottyEditor(QWidget *parent = nullptr);
    void saveState();
    void loadState();

private slots:
    void onTextChanged();

private:
    QString stateFile;
    bool storeNext = false;
};

#endif
