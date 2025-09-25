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

#include <string>

namespace muse {
    class String;
}

namespace muse::draw {
    class Font;
    class Painter;
    class PointF;
    class RectF;
}

namespace mu::engraving {

//---------------------------------------------------------
//   Cipher
//    Cipher notation helper class
//---------------------------------------------------------

class Cipher
{
public:
    Cipher();
    ~Cipher();
    Cipher(const Cipher& other);
    Cipher& operator=(const Cipher& other);

    double textWidth(const muse::draw::Font& font, const muse::String& string) const;
    double textHeight(const muse::draw::Font& font, const muse::String& string) const;

    void setRelativeSize(double size) { m_relativeSize = size; }
    void setFretFont(const muse::draw::Font& font);

    double getRelativeSize() const { return m_relativeSize; }
    muse::draw::RectF bbox(const muse::draw::Font& font, const muse::draw::PointF& pos, const muse::String& string) const;
    muse::String sharpString() const;
    muse::String flatString() const;
    muse::draw::Font getFretFont() const;

    void drawSharp(muse::draw::Painter* painter, const muse::draw::PointF& pos, const muse::draw::Font& font) const;
    void drawFlat(muse::draw::Painter* painter, const muse::draw::PointF& pos, const muse::draw::Font& font) const;

private:
    double m_relativeSize = 1.0;
    // Use void* to avoid template instantiation issues
    void* m_fretFont = nullptr;
};

} // namespace mu::engraving

#endif // MU_ENGRAVING_CIPHER_H