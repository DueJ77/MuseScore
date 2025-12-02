/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-Studio-CLA-applies
 *
 * MuseScore Studio
 * Music Composition & Notation
 *
 * Copyright (C) 2024 MuseScore Limited
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import MuseScore.NotationScene 1.0
import Muse.UiComponents 1.0
import Muse.Ui 1.0

StyledFlickable {
    id: root

    contentWidth: mainColumn.implicitWidth
    contentHeight: mainColumn.implicitHeight

    readonly property real controlAreaWidth: 204

    CipherPageModel {
        id: cipherPage
    }

    ColumnLayout {
        id: mainColumn
        anchors.fill: parent
        spacing: 24

        // Font Settings
        StyledGroupBox {
            Layout.fillWidth: true
            title: qsTrc("notation", "Font settings")

            ColumnLayout {
                spacing: 12
                width: parent.width

                Row {
                    spacing: 12

                    StyledTextLabel {
                        anchors.verticalCenter: parent.verticalCenter
                        text: qsTrc("notation", "Font:")
                        width: root.controlAreaWidth - 12
                    }

                    FontStyleSelector {
                        width: 200
                        fontFamily: cipherPage.cipherFont ? cipherPage.cipherFont.value : ""
                        onFontFamilyChanged: {
                            if (cipherPage.cipherFont) {
                                cipherPage.cipherFont.value = fontFamily
                            }
                        }
                    }

                    StyleResetButton {
                        styleItem: cipherPage.cipherFont
                    }
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherFontSize
                    label: qsTrc("notation", "Font size:")
                    suffix: qsTrc("global", "pt")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.5
                    decimals: 1
                }
            }
        }

        // Note Distance Settings
        StyledGroupBox {
            Layout.fillWidth: true
            title: qsTrc("notation", "Note spacing")

            ColumnLayout {
                spacing: 12
                width: parent.width

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherDistanceOctave
                    label: qsTrc("notation", "Distance between octaves:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherNoteDistanc
                    label: qsTrc("notation", "Distance cipher to cipher/rest:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherRestDistanc
                    label: qsTrc("notation", "Distance rest to cipher/rest:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }
            }
        }

        // Ledger Lines
        StyledGroupBox {
            Layout.fillWidth: true
            title: qsTrc("notation", "Ledger lines")

            ColumnLayout {
                spacing: 12
                width: parent.width

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherLedgerlineLength
                    label: qsTrc("notation", "Length:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherLedgerlineThick
                    label: qsTrc("notation", "Thickness:")
                    suffix: qsTrc("global", "sp")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.01
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherLedgerlineShift
                    label: qsTrc("notation", "Vertical shift:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherOffsetLine
                    label: qsTrc("notation", "Horizontal shift of line above cipher:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherHeigthLine
                    label: qsTrc("notation", "Height of line above cipher:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherWideLine
                    label: qsTrc("notation", "Width of line above cipher:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherThickLine
                    label: qsTrc("notation", "Thickness of line above cipher:")
                    suffix: qsTrc("global", "sp")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.01
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherDistanceBetweenLines
                    label: qsTrc("notation", "Distance between lines:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherHeightDisplacement
                    label: qsTrc("notation", "Height displacement:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }
            }
        }

        // Accidentals
        StyledGroupBox {
            Layout.fillWidth: true
            title: qsTrc("notation", "Accidentals")

            ColumnLayout {
                spacing: 12
                width: parent.width

                StyledTextLabel {
                    text: qsTrc("notation", "Sharp")
                    font: ui.theme.headerBoldFont
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherSizeSignSharp
                    label: qsTrc("notation", "Size:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherDistanceSignSharp
                    label: qsTrc("notation", "Distance:")
                    suffix: qsTrc("global", "sp")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherHeigthSignSharp
                    label: qsTrc("notation", "Height offset:")
                    suffix: qsTrc("global", "sp")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                Item { height: 12 }

                StyledTextLabel {
                    text: qsTrc("notation", "Flat")
                    font: ui.theme.headerBoldFont
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherSizeSignFlat
                    label: qsTrc("notation", "Size:")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherDistanceSignFlat
                    label: qsTrc("notation", "Distance:")
                    suffix: qsTrc("global", "sp")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherHeigthSignFlat
                    label: qsTrc("notation", "Height offset:")
                    suffix: qsTrc("global", "sp")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.1
                    decimals: 2
                }
            }
        }

        // Key Signature
        StyledGroupBox {
            Layout.fillWidth: true
            title: qsTrc("notation", "Key signature")

            ColumnLayout {
                spacing: 12
                width: parent.width

                Row {
                    spacing: 12

                    StyledTextLabel {
                        anchors.verticalCenter: parent.verticalCenter
                        text: qsTrc("notation", "Font:")
                        width: root.controlAreaWidth - 12
                    }

                    FontStyleSelector {
                        width: 200
                        fontFamily: cipherPage.cipherKeySigFont ? cipherPage.cipherKeySigFont.value : ""
                        onFontFamilyChanged: {
                            if (cipherPage.cipherKeySigFont) {
                                cipherPage.cipherKeySigFont.value = fontFamily
                            }
                        }
                    }

                    StyleResetButton {
                        styleItem: cipherPage.cipherKeySigFont
                    }
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherKeySigFontSize
                    label: qsTrc("notation", "Font size:")
                    suffix: qsTrc("global", "pt")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.5
                    decimals: 1
                }
            }
        }

        // Time Signature
        StyledGroupBox {
            Layout.fillWidth: true
            title: qsTrc("notation", "Time signature")

            ColumnLayout {
                spacing: 12
                width: parent.width

                Row {
                    spacing: 12

                    StyledTextLabel {
                        anchors.verticalCenter: parent.verticalCenter
                        text: qsTrc("notation", "Font:")
                        width: root.controlAreaWidth - 12
                    }

                    FontStyleSelector {
                        width: 200
                        fontFamily: cipherPage.cipherTimeSigFont ? cipherPage.cipherTimeSigFont.value : ""
                        onFontFamilyChanged: {
                            if (cipherPage.cipherTimeSigFont) {
                                cipherPage.cipherTimeSigFont.value = fontFamily
                            }
                        }
                    }

                    StyleResetButton {
                        styleItem: cipherPage.cipherTimeSigFont
                    }
                }

                StyleSpinboxWithReset {
                    styleItem: cipherPage.cipherTimeSigFontSize
                    label: qsTrc("notation", "Font size:")
                    suffix: qsTrc("global", "pt")
                    controlAreaWidth: root.controlAreaWidth
                    step: 0.5
                    decimals: 1
                }
            }
        }
    }
}
