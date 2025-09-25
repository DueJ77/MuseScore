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
#include "draw/types/font.h"
#include "draw/types/geometry.h"
#include "global/types/string.h"

using namespace mu::engraving;

//---------------------------------------------------------
//   Cipher constructor
//---------------------------------------------------------

Cipher::Cipher()
{
    m_fretFont = new muse::draw::Font();
}

//---------------------------------------------------------
//   Cipher destructor
//---------------------------------------------------------

Cipher::~Cipher()
{
    delete static_cast<muse::draw::Font*>(m_fretFont);
}

//---------------------------------------------------------
//   Copy constructor
//---------------------------------------------------------

Cipher::Cipher(const Cipher& other)
    : m_relativeSize(other.m_relativeSize)
{
    if (other.m_fretFont) {
        m_fretFont = new muse::draw::Font(*static_cast<muse::draw::Font*>(other.m_fretFont));
    } else {
        m_fretFont = new muse::draw::Font();
    }
}

//---------------------------------------------------------
//   Assignment operator
//---------------------------------------------------------

Cipher& Cipher::operator=(const Cipher& other)
{
    if (this != &other) {
        m_relativeSize = other.m_relativeSize;
        delete static_cast<muse::draw::Font*>(m_fretFont);
        if (other.m_fretFont) {
            m_fretFont = new muse::draw::Font(*static_cast<muse::draw::Font*>(other.m_fretFont));
        } else {
            m_fretFont = new muse::draw::Font();
        }
    }
    return *this;
}

//---------------------------------------------------------
//   setFretFont
//---------------------------------------------------------

void Cipher::setFretFont(const muse::draw::Font& font)
{
    if (!m_fretFont) {
        m_fretFont = new muse::draw::Font();
    }
    *static_cast<muse::draw::Font*>(m_fretFont) = font;
}

//---------------------------------------------------------
//   getFretFont
//---------------------------------------------------------

muse::draw::Font Cipher::getFretFont() const
{
    if (m_fretFont) {
        return *static_cast<muse::draw::Font*>(m_fretFont);
    }
    return muse::draw::Font();
}

//---------------------------------------------------------
//   sharpString
//---------------------------------------------------------

muse::String Cipher::sharpString() const
{
    return muse::String(u"♯");
}

//---------------------------------------------------------
//   flatString
//---------------------------------------------------------

muse::String Cipher::flatString() const
{
    return muse::String(u"♭");
}

//---------------------------------------------------------
//   textWidth
//---------------------------------------------------------

double Cipher::textWidth(const muse::draw::Font& font, const muse::String& string) const
{
    muse::draw::FontMetrics fm(font);
    return fm.horizontalAdvance(string);
}

//---------------------------------------------------------
//   textHeight
//---------------------------------------------------------

double Cipher::textHeight(const muse::draw::Font& font, const muse::String& string) const
{
    muse::draw::FontMetrics fm(font);
    muse::draw::RectF pos = fm.tightBoundingRect(string);
    return pos.height();
}

//---------------------------------------------------------
//   bbox
//---------------------------------------------------------

muse::draw::RectF Cipher::bbox(const muse::draw::Font& font, const muse::draw::PointF& pos, const muse::String& string) const
{
    muse::draw::FontMetrics fm(font);
    return fm.tightBoundingRect(string).translated(pos);
}

//---------------------------------------------------------
//   drawSharp
//---------------------------------------------------------

void Cipher::drawSharp(muse::draw::Painter* painter, const muse::draw::PointF& pos, const muse::draw::Font& font) const
{
    muse::draw::Font fontOld = painter->font();
    painter->setFont(font);
    painter->drawText(pos, sharpString());
    painter->setFont(fontOld);
}

//---------------------------------------------------------
//   drawFlat
//---------------------------------------------------------

void Cipher::drawFlat(muse::draw::Painter* painter, const muse::draw::PointF& pos, const muse::draw::Font& font) const
{
    muse::draw::Font fontOld = painter->font();
    painter->setFont(font);
    painter->drawText(pos, flatString());
    painter->setFont(fontOld);
}