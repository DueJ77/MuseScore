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
#include "cipherpagemodel.h"

#include "engraving/dom/masterscore.h"
#include "engraving/types/types.h"

using namespace mu::notation;
using namespace mu::engraving;

CipherPageModel::CipherPageModel(QObject* parent)
    : AbstractStyleDialogModel(parent, std::set<StyleId>{
        StyleId::cipherFont,
        StyleId::cipherFontSize,
        StyleId::cipherDistanceOctave,
        StyleId::cipherNoteDistanc,
        StyleId::cipherRestDistanc,
        StyleId::cipherLedgerlineLength,
        StyleId::cipherLedgerlineThick,
        StyleId::cipherLedgerlineShift,
        StyleId::cipherOffsetLine,
        StyleId::cipherHeigthLine,
        StyleId::cipherWideLine,
        StyleId::cipherThickLine,
        StyleId::cipherDistanceBetweenLines,
        StyleId::cipherHeightDisplacement,
        StyleId::cipherSizeSignSharp,
        StyleId::cipherSizeSignFlat,
        StyleId::cipherDistanceSignSharp,
        StyleId::cipherDistanceSignFlat,
        StyleId::cipherHeigthSignSharp,
        StyleId::cipherHeigthSignFlat,
        StyleId::cipherKeySigFont,
        StyleId::cipherKeySigSize,
        StyleId::cipherTimeSigFont,
        StyleId::cipherTimeSigSize
    })
{
}

// Font settings
StyleItem* CipherPageModel::cipherFont() const
{
    return styleItem(StyleId::cipherFont);
}

StyleItem* CipherPageModel::cipherFontSize() const
{
    return styleItem(StyleId::cipherFontSize);
}

// Note settings
StyleItem* CipherPageModel::cipherDistanceOctave() const
{
    return styleItem(StyleId::cipherDistanceOctave);
}

StyleItem* CipherPageModel::cipherNoteDistanc() const
{
    return styleItem(StyleId::cipherNoteDistanc);
}

StyleItem* CipherPageModel::cipherRestDistanc() const
{
    return styleItem(StyleId::cipherRestDistanc);
}

// Ledger line settings
StyleItem* CipherPageModel::cipherLedgerlineLength() const
{
    return styleItem(StyleId::cipherLedgerlineLength);
}

StyleItem* CipherPageModel::cipherLedgerlineThick() const
{
    return styleItem(StyleId::cipherLedgerlineThick);
}

StyleItem* CipherPageModel::cipherLedgerlineShift() const
{
    return styleItem(StyleId::cipherLedgerlineShift);
}

StyleItem* CipherPageModel::cipherOffsetLine() const
{
    return styleItem(StyleId::cipherOffsetLine);
}

StyleItem* CipherPageModel::cipherHeigthLine() const
{
    return styleItem(StyleId::cipherHeigthLine);
}

StyleItem* CipherPageModel::cipherWideLine() const
{
    return styleItem(StyleId::cipherWideLine);
}

StyleItem* CipherPageModel::cipherThickLine() const
{
    return styleItem(StyleId::cipherThickLine);
}

StyleItem* CipherPageModel::cipherDistanceBetweenLines() const
{
    return styleItem(StyleId::cipherDistanceBetweenLines);
}

StyleItem* CipherPageModel::cipherHeightDisplacement() const
{
    return styleItem(StyleId::cipherHeightDisplacement);
}

// Accidental settings
StyleItem* CipherPageModel::cipherSizeSignSharp() const
{
    return styleItem(StyleId::cipherSizeSignSharp);
}

StyleItem* CipherPageModel::cipherSizeSignFlat() const
{
    return styleItem(StyleId::cipherSizeSignFlat);
}

StyleItem* CipherPageModel::cipherDistanceSignSharp() const
{
    return styleItem(StyleId::cipherDistanceSignSharp);
}

StyleItem* CipherPageModel::cipherDistanceSignFlat() const
{
    return styleItem(StyleId::cipherDistanceSignFlat);
}

StyleItem* CipherPageModel::cipherHeigthSignSharp() const
{
    return styleItem(StyleId::cipherHeigthSignSharp);
}

StyleItem* CipherPageModel::cipherHeigthSignFlat() const
{
    return styleItem(StyleId::cipherHeigthSignFlat);
}

// Key signature settings
StyleItem* CipherPageModel::cipherKeySigFont() const
{
    return styleItem(StyleId::cipherKeySigFont);
}

StyleItem* CipherPageModel::cipherKeySigFontSize() const
{
    return styleItem(StyleId::cipherKeySigSize);
}

// Time signature settings
StyleItem* CipherPageModel::cipherTimeSigFont() const
{
    return styleItem(StyleId::cipherTimeSigFont);
}

StyleItem* CipherPageModel::cipherTimeSigFontSize() const
{
    return styleItem(StyleId::cipherTimeSigSize);
}
