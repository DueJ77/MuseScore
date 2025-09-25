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

namespace muse::draw {
class Painter;
}

namespace mu::engraving {

//---------------------------------------------------------
//   Cipher
//    Cipher notation helper class
//---------------------------------------------------------

class Cipher
{
public:
    Cipher() = default;

    double textWidth(const Font& font, const String& string) const;
    double textHeight(const Font& font, const String& string) const;

    void setRelativeSize(double size) { m_relativeSize = size; }
    void setFretFont(const Font& font) { m_fretFont = font; }

    double getRelativeSize() const { return m_relativeSize; }
    RectF bbox(const Font& font, const PointF& pos, const String& string) const;
    String sharpString() const { return String(u"♯"); }
    String flatString() const { return String(u"♭"); }
    Font getFretFont() const { return m_fretFont; }

    void drawSharp(Painter* painter, const PointF& pos, const Font& font) const;
    void drawFlat(Painter* painter, const PointF& pos, const Font& font) const;

private:
    double m_relativeSize = 1.0;
    Font m_fretFont;
};

} // namespace mu::engraving

#endif // MU_ENGRAVING_CIPHER_H