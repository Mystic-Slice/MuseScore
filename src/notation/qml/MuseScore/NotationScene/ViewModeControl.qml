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

import MuseScore.Ui 1.0
import MuseScore.UiComponents 1.0

FlatButton {
    id: root

    property var currentViewMode
    property var availableViewModeList: []

    signal changeCurrentViewModeRequested(var newViewMode)

    normalStateColor: menu.isMenuOpened ? ui.theme.accentColor : "transparent"

    text: Boolean(root.currentViewMode) ? root.currentViewMode.title : ""
    icon: Boolean(root.currentViewMode) ? root.currentViewMode.icon : IconCode.NONE

    orientation: Qt.Horizontal

    visible: Boolean(root.currentViewMode)

    contentItem: Row {
        spacing: 4

        StyledIconLabel {
            iconCode: root.icon
        }

        StyledTextLabel {
            text: root.text
        }

        StyledIconLabel {
            iconCode: IconCode.SMALL_ARROW_DOWN
        }
    }

    onClicked: {
        menu.toggleOpened(root.availableViewModeList, root.navigation)
    }

    StyledMenuLoader {
        id: menu

        anchorItem: ui.rootItem

        onHandleAction: {
            Qt.callLater(root.changeCurrentViewModeRequested, actionCode)
        }
    }
}
