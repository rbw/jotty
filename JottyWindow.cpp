#include "JottyWindow.h"
#include <QTimer>
#include <QCloseEvent>


JottyWindow::JottyWindow() {
    // Initialize the editor
    editor = new JottyEditor(this);
    setCentralWidget(editor);

    // Set up timer for autosaving
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, editor, &JottyEditor::saveState);
    timer->start(2000);

    // Set window properties
    setWindowTitle("Jotty: Scribble Today, Remember Tomorrow");
    setGeometry(100, 100, 600, 400);
}

void JottyWindow::closeEvent(QCloseEvent *event) {
    editor->saveState();
    event->accept();
}
