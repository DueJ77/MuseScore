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

#include "draw/fontmetrics.h"
#include "draw/painter.h"

using namespace mu;
using namespace muse;
using namespace muse::draw;

namespace mu::engraving {
//---------------------------------------------------------
//   textWidth
//---------------------------------------------------------

double Cipher::textWidth(const Font& font, const String& string) const
{
    return FontMetrics::width(font, string);
}

//---------------------------------------------------------
//   textHeight
//---------------------------------------------------------

double Cipher::textHeight(const Font& font, const String& string) const
{
    RectF rect = FontMetrics::tightBoundingRect(font, string);
    return rect.height();
}

//---------------------------------------------------------
//   bbox
//---------------------------------------------------------

RectF Cipher::bbox(const Font& font, const PointF& pos, const String& string) const
{
    return FontMetrics::tightBoundingRect(font, string).translated(pos);
}

//---------------------------------------------------------
//   drawSharp
//---------------------------------------------------------

void Cipher::drawSharp(Painter* painter, const PointF& pos, const Font& font) const
{
    Font oldFont = painter->font();
    painter->setFont(font);
    painter->drawText(pos, u"♯");
    painter->setFont(oldFont);
}

//---------------------------------------------------------
//   drawFlat
//---------------------------------------------------------

void Cipher::drawFlat(Painter* painter, const PointF& pos, const Font& font) const
{
    Font oldFont = painter->font();
    painter->setFont(font);
    painter->drawText(pos, u"♭");
    painter->setFont(oldFont);
}
} // namespace mu::engraving
