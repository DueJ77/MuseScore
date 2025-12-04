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
#ifndef MU_NOTATION_CIPHERPAGEMODEL_H
#define MU_NOTATION_CIPHERPAGEMODEL_H

#include "abstractstyledialogmodel.h"

namespace mu::notation {
class CipherPageModel : public AbstractStyleDialogModel
{
    Q_OBJECT

    // Font settings
    Q_PROPERTY(StyleItem * cipherFont READ cipherFont CONSTANT)
    Q_PROPERTY(StyleItem * cipherFontSize READ cipherFontSize CONSTANT)
    
    // Note settings
    Q_PROPERTY(StyleItem * cipherDistanceOctave READ cipherDistanceOctave CONSTANT)
    Q_PROPERTY(StyleItem * cipherNoteDistanc READ cipherNoteDistanc CONSTANT)
    Q_PROPERTY(StyleItem * cipherRestDistanc READ cipherRestDistanc CONSTANT)
    
    // Ledger line settings
    Q_PROPERTY(StyleItem * cipherLedgerlineLength READ cipherLedgerlineLength CONSTANT)
    Q_PROPERTY(StyleItem * cipherLedgerlineThick READ cipherLedgerlineThick CONSTANT)
    Q_PROPERTY(StyleItem * cipherLedgerlineShift READ cipherLedgerlineShift CONSTANT)
    Q_PROPERTY(StyleItem * cipherOffsetLine READ cipherOffsetLine CONSTANT)
    Q_PROPERTY(StyleItem * cipherHeigthLine READ cipherHeigthLine CONSTANT)
    Q_PROPERTY(StyleItem * cipherWideLine READ cipherWideLine CONSTANT)
    Q_PROPERTY(StyleItem * cipherThickLine READ cipherThickLine CONSTANT)
    Q_PROPERTY(StyleItem * cipherDistanceBetweenLines READ cipherDistanceBetweenLines CONSTANT)
    Q_PROPERTY(StyleItem * cipherHeightDisplacement READ cipherHeightDisplacement CONSTANT)
    
    // Accidental settings
    Q_PROPERTY(StyleItem * cipherSizeSignSharp READ cipherSizeSignSharp CONSTANT)
    Q_PROPERTY(StyleItem * cipherSizeSignFlat READ cipherSizeSignFlat CONSTANT)
    Q_PROPERTY(StyleItem * cipherDistanceSignSharp READ cipherDistanceSignSharp CONSTANT)
    Q_PROPERTY(StyleItem * cipherDistanceSignFlat READ cipherDistanceSignFlat CONSTANT)
    Q_PROPERTY(StyleItem * cipherHeigthSignSharp READ cipherHeigthSignSharp CONSTANT)
    Q_PROPERTY(StyleItem * cipherHeigthSignFlat READ cipherHeigthSignFlat CONSTANT)
    
    // Key signature settings
    Q_PROPERTY(StyleItem * cipherKeySigFont READ cipherKeySigFont CONSTANT)
    Q_PROPERTY(StyleItem * cipherKeySigFontSize READ cipherKeySigFontSize CONSTANT)
    
    // Time signature settings
    Q_PROPERTY(StyleItem * cipherTimeSigFont READ cipherTimeSigFont CONSTANT)
    Q_PROPERTY(StyleItem * cipherTimeSigFontSize READ cipherTimeSigFontSize CONSTANT)

public:
    explicit CipherPageModel(QObject* parent = nullptr);

    // Font settings
    StyleItem* cipherFont() const;
    StyleItem* cipherFontSize() const;
    
    // Note settings
    StyleItem* cipherDistanceOctave() const;
    StyleItem* cipherNoteDistanc() const;
    StyleItem* cipherRestDistanc() const;
    
    // Ledger line settings
    StyleItem* cipherLedgerlineLength() const;
    StyleItem* cipherLedgerlineThick() const;
    StyleItem* cipherLedgerlineShift() const;
    StyleItem* cipherOffsetLine() const;
    StyleItem* cipherHeigthLine() const;
    StyleItem* cipherWideLine() const;
    StyleItem* cipherThickLine() const;
    StyleItem* cipherDistanceBetweenLines() const;
    StyleItem* cipherHeightDisplacement() const;
    
    // Accidental settings
    StyleItem* cipherSizeSignSharp() const;
    StyleItem* cipherSizeSignFlat() const;
    StyleItem* cipherDistanceSignSharp() const;
    StyleItem* cipherDistanceSignFlat() const;
    StyleItem* cipherHeigthSignSharp() const;
    StyleItem* cipherHeigthSignFlat() const;
    
    // Key signature settings
    StyleItem* cipherKeySigFont() const;
    StyleItem* cipherKeySigFontSize() const;
    
    // Time signature settings
    StyleItem* cipherTimeSigFont() const;
    StyleItem* cipherTimeSigFontSize() const;
};
}

#endif // MU_NOTATION_CIPHERPAGEMODEL_H
