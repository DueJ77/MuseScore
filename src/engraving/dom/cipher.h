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

#include <QFont>
#include <QPointF>
#include <QRectF>
#include <QString>

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

    qreal textWidth(const QFont& font, const QString& string) const;
    qreal textHeight(const QFont& font, const QString& string) const;

    void setRelativeSize(qreal size) { m_relativeSize = size; }
    void setFretFont(const QFont& font) { m_fretFont = font; }

    qreal getRelativeSize() const { return m_relativeSize; }
    QRectF bbox(const QFont& font, const QPointF& pos, const QString& string) const;
    QString sharpString() const { return QString("♯"); }
    QString flatString() const { return QString("♭"); }
    QFont getFretFont() const { return m_fretFont; }

    void drawSharp(QPainter* painter, const QPointF& pos, const QFont& font) const;
    void drawFlat(QPainter* painter, const QPointF& pos, const QFont& font) const;

private:
    qreal m_relativeSize = 1.0;
    QFont m_fretFont;
};

} // namespace mu::engraving

#endif // MU_ENGRAVING_CIPHER_H