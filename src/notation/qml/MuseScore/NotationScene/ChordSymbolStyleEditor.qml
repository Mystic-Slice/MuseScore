/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
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
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import MuseScore.Ui 1.0
import MuseScore.UiComponents 1.0
import MuseScore.NotationScene 1.0

import "internal"

StyledDialogView {
    id: root

    contentWidth: 400
    contentHeight: 500
    margins: 12

    ChordSymbolStyle {
        id: chordSymbolStyle
    }

    Column{
        // Add canvas here
        Rectangle{
            id: canvas
            anchors.left: root.left
            anchors.right: root.right
            anchors.top: root.top
            height: 200
            color: "red"

        }

        Column {
            anchors.left: root.left
            anchors.right: root.right
            anchors.top: canvas.bottom

            spacing: 20
            enabled: withTempo.checked

            Row{
                StyledTextLabel {
                    text: "Extension Scaling"
                    font: ui.theme.headerFont
                }

                SpinBox{
                    stepSize: 1
                    onValueChanged: {
                        chordSymbolStyle.extensionMagChanged(value.toFixed(2));
                    }
                }
            }
        }
    }
}
