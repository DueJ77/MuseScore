# Cipher Style Dialog Integration - TODO

Die Grunddateien für das Cipher-Stil-Menü wurden erstellt:

## Erstellte Dateien:
1. `src/notation/view/styledialog/cipherpagemodel.h`
2. `src/notation/view/styledialog/cipherpagemodel.cpp`  
3. `src/notation/qml/MuseScore/NotationScene/internal/EditStyle/CipherPage.qml`
4. `src/notation/view/styledialog/styledialog.cmake` (aktualisiert)

## Noch zu erledigende Schritte:

### 1. QML-Registrierung
Die CipherPage.qml muss in der Haupt-Style-Dialog-Datei registriert werden.
Suchen Sie nach der Datei, die alle Style-Seiten verwaltet (vermutlich in `src/notation/qml/MuseScore/NotationScene/internal/`).

### 2. Menü-Eintrag
Fügen Sie einen Eintrag für "Cipher" oder "Ziffern" im Style-Dialog-Menü hinzu.
Dies erfolgt wahrscheinlich in einer Liste von Seiten-Definitionen.

### 3. FontStyleSelector-Komponente
Die QML-Datei verwendet `FontStyleSelector`, die möglicherweise:
- Umbenannt werden muss in `FontComboBox` oder ähnlich
- Oder aus einem anderen Modul importiert werden muss
  
Prüfen Sie andere QML-Seiten wie `FretboardsPage.qml` für die korrekte Verwendung.

### 4. qmldir-Datei
Falls vorhanden, muss die CipherPage in der entsprechenden qmldir-Datei registriert werden.

### 5. Translations
Alle `qsTrc("notation", "...")` Strings müssen in die Übersetzungsdateien aufgenommen werden.

## Referenz aus MuseScore 3

Das Original aus dem MuseScore3-Fork (ditoe/MuseScore/vergleich) befindet sich in:
- `mscore/editstyle.ui` (Zeilen 218, 12366+)
- Suche nach "Ziffern-System" und "PagecipherSystem"

## Test
Nach vollständiger Integration sollte im Menü Format > Stil... eine neue Seite "Ziffern" erscheinen.
