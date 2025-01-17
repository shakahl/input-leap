/*
 * InputLeap -- mouse and keyboard sharing utility
 * Copyright (C) 2012-2016 Symless Ltd.
 * Copyright (C) 2004 Chris Schoeneman
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "platform/XWindowsClipboard.h"

//! Convert to/from some text encoding
class XWindowsClipboardBMPConverter :
                public IXWindowsClipboardConverter {
public:
    XWindowsClipboardBMPConverter(Display* display);
    ~XWindowsClipboardBMPConverter() override;

    // IXWindowsClipboardConverter overrides
    IClipboard::EFormat getFormat() const override;
    Atom getAtom() const override;
    int getDataSize() const override;
    std::string fromIClipboard(const std::string&) const override;
    std::string toIClipboard(const std::string&) const override;

private:
    Atom m_atom;
};
