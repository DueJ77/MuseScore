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

#ifndef MU_ENGRAVING_CIPHER_H
#define MU_ENGRAVING_CIPHER_H

#include "draw/types/font.h"
#include "draw/types/geometry.h"
#include "global/types/string.h"

class QPainter;

namespace mu::engraving {

//---------------------------------------------------------
//   Cipher
//    Cipher notation helper class
//---------------------------------------------------------

class Cipher
{
public:
    Cipher() = default;

    double textWidth(const muse::draw::Font& font, const String& string) const;
    double textHeight(const muse::draw::Font& font, const String& string) const;

    void setRelativeSize(double size) { m_relativeSize = size; }
    void setFretFont(const muse::draw::Font& font) { m_fretFont = font; }

    double getRelativeSize() const { return m_relativeSize; }
    RectF bbox(const muse::draw::Font& font, const PointF& pos, const String& string) const;
    String sharpString() const { return String(u"♯"); }
    String flatString() const { return String(u"♭"); }
    muse::draw::Font getFretFont() const { return m_fretFont; }

    void drawSharp(muse::draw::Painter* painter, const PointF& pos, const muse::draw::Font& font) const;
    void drawFlat(muse::draw::Painter* painter, const PointF& pos, const muse::draw::Font& font) const;

private:
    double m_relativeSize = 1.0;
    muse::draw::Font m_fretFont;
};

} // namespace mu::engraving

#endif // MU_ENGRAVING_CIPHER_H