/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-Studio-CLA-applies
 *
 * MuseScore Studio
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore Limited
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

#include "cipher.h"

#include "draw/painter.h"
#include "draw/fontmetrics.h"

namespace mu::engraving {

//---------------------------------------------------------
//   textWidth
//---------------------------------------------------------

double Cipher::textWidth(const muse::draw::Font& font, const String& string) const
{
    muse::draw::FontMetrics fm(font);
    return fm.horizontalAdvance(string);
}

//---------------------------------------------------------
//   textHeight
//---------------------------------------------------------

double Cipher::textHeight(const muse::draw::Font& font, const String& string) const
{
    muse::draw::FontMetrics fm(font);
    RectF pos = fm.tightBoundingRect(string);
    return pos.height();
}

//---------------------------------------------------------
//   bbox
//---------------------------------------------------------

RectF Cipher::bbox(const muse::draw::Font& font, const PointF& pos, const String& string) const
{
    muse::draw::FontMetrics fm(font);
    return fm.tightBoundingRect(string).translated(pos);
}

//---------------------------------------------------------
//   drawSharp
//---------------------------------------------------------

void Cipher::drawSharp(muse::draw::Painter* painter, const PointF& pos, const muse::draw::Font& font) const
{
    muse::draw::Font fontOld = painter->font();
    painter->setFont(font);
    painter->drawText(pos, sharpString());
    painter->setFont(fontOld);
}

//---------------------------------------------------------
//   drawFlat
//---------------------------------------------------------

void Cipher::drawFlat(muse::draw::Painter* painter, const PointF& pos, const muse::draw::Font& font) const
{
    muse::draw::Font fontOld = painter->font();
    painter->setFont(font);
    painter->drawText(pos, flatString());
    painter->setFont(fontOld);
}

} // namespace mu::engraving