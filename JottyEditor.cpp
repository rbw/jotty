#include "JottyEditor.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMimeData>

JottyEditor::JottyEditor(QWidget *parent)
        : QTextEdit(parent), stateFile("state.json"), storeNext(false) {
    connect(this, &JottyEditor::textChanged, this, &JottyEditor::onTextChanged);
    loadState();
}

void JottyEditor::onTextChanged() {
    storeNext = true;
}

void JottyEditor::saveState() {
    if (!storeNext) {
        return;
    }

    QFile file(stateFile);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonObject state;
        state["text"] = toPlainText();
        state["cursor_position"] = textCursor().position();

        QJsonDocument doc(state);
        file.write(doc.toJson());
    }

    storeNext = false;
}

void JottyEditor::loadState() {
    QFile file(stateFile);
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject state = doc.object();

        setPlainText(state["text"].toString());
        QTextCursor cursor = textCursor();
        cursor.setPosition(state["cursor_position"].toInt());
        setTextCursor(cursor);
    }
}

void JottyEditor::insertFromMimeData(const QMimeData *source) {
    if (source->hasText()) {
        insertPlainText(source->text()); // Insert text without formatting
    }
}
