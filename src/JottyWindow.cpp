#include "JottyWindow.h"
#include <QTimer>
#include <QCloseEvent>


JottyWindow::JottyWindow() {
    // Initialize the editor
    editor = new JottyEditor(this);
    setCentralWidget(editor);

    // Set up timer for auto save
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, editor, &JottyEditor::saveState);
    timer->start(2000);
}

void JottyWindow::closeEvent(QCloseEvent *event) {
    editor->saveState();
    event->accept();
}
