#ifndef JOTTYWINDOW_H
#define JOTTYWINDOW_H

#include <QMainWindow>
#include "JottyEditor.h"

class JottyWindow : public QMainWindow {
Q_OBJECT

public:
    JottyWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    JottyEditor *editor;
};

#endif
