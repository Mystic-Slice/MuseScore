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
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import MuseScore.UiComponents 1.0
import MuseScore.Ui 1.0
import MuseScore.NotationScene 1.0

Rectangle {
    id: root
    color: ui.theme.backgroundPrimaryColor

    ChordSymbolEditorModel {
        id: chordSymbolEditorModel
    }

    height: grid.height

    Component {
        id: chordStyleDelegate

        FlatButton {
            id: button

            width: grid.cellWidth-5
            height: grid.cellHeight-5

            Text {
                id: buttontext
                text: styleName

                width: button.width
                height: button.height

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.Wrap
            }

            onClicked: {
                chordSymbolEditorModel.setChordStyle(styleName)
                grid.currentIndex = index
            }
        }
    }

    Column {
        anchors.fill: parent
        StyledTextLabel{
            text: qsTrc("notation","Chord symbols")
            font.pixelSize: ui.theme.bodyFont.pixelSize * 1.5
        }

        StyledTextLabel{
            text: qsTrc("notation","Choose a style")
        }

        GridView {
            id: grid

            height: 2*cellHeight
            width: root.width

            cellWidth: 120
            cellHeight: 60

            model: chordSymbolEditorModel

            delegate: chordStyleDelegate
            clip: true

            highlight: Rectangle {
                color: ui.theme.accentColor
                radius: 3
            }
        }

        Rectangle {
            width: root.width
            height: 2
            color: ui.theme.backgroundSecondaryColor
        }

        StyledTextLabel{
            text: qsTrc("notation","Adjust settings for ")
        }

        TabBar {
            id: bar

            width: root.width
            implicitHeight: 60

            StyledTabButton {
                text: qsTrc("notation", "Basic")
                sideMargin: 120
                height: 60
                isCurrent: bar.currentIndex === 0
            }

            StyledTabButton {
                text: qsTrc("notation", "Advanced")
                sideMargin: 120
                height: 60
                isCurrent: bar.currentIndex === 1
            }
        }

        StackLayout {
            id: editorStack

            anchors.top: bar.bottom

            currentIndex: bar.currentIndex

            ChordSymbolEditorBasic {
                width: root.width
                height: 200
            }

            ChordSymbolEditorAdvanced {
                width: root.width
                height: 200
            }
        }
    }
}
