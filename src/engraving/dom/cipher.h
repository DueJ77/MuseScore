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

#pragma once

#include "draw/types/font.h"
#include "draw/types/geometry.h"

namespace muse::draw {
class Painter;
}

namespace mu::engraving {

//---------------------------------------------------------
//   Cipher
//   Helper class for cipher notation rendering
//---------------------------------------------------------

class Cipher
{
public:
    Cipher() = default;

    double textWidth(const muse::draw::Font& font, const muse::String& string) const;
    double textHeight(const muse::draw::Font& font, const muse::String& string) const;

    void setRelativeSize(double size) { m_relativeSize = size; }
    void setFretFont(const muse::draw::Font& font) { m_fretFont = font; }

    double relativeSize() const { return m_relativeSize; }
    muse::RectF bbox(const muse::draw::Font& font, const muse::PointF& pos, const muse::String& string) const;
    muse::String sharpString() const { return u"♯"; }
    muse::String flatString() const { return u"♭"; }
    muse::draw::Font fretFont() const { return m_fretFont; }

    void drawSharp(muse::draw::Painter* painter, const muse::PointF& pos, const muse::draw::Font& font) const;
    void drawFlat(muse::draw::Painter* painter, const muse::PointF& pos, const muse::draw::Font& font) const;

private:
    double m_relativeSize = 1.0;
    muse::draw::Font m_fretFont;
};
} // namespace mu::engraving
