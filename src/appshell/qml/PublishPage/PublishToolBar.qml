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
import MuseScore.AppShell 1.0

Rectangle {
    id: root

    color: ui.theme.backgroundPrimaryColor

    PublishToolBarModel {
        id: model
    }

    Component.onCompleted: {
        model.load()
    }

    Row {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 12

        spacing: 16

        FlatButton {
            text: qsTrc("appshell", "Print")
            icon: IconCode.PRINT

            enabled: model.printScoreEnabled
            orientation: Qt.Horizontal
            normalStateColor: "transparent"

            onClicked: {
                model.printScore()
            }
        }

        FlatButton {
            text: qsTrc("appshell", "Upload to MuseScore.com")
            icon: IconCode.CLOUD_FILE

            enabled: model.uploadScoreEnabled
            orientation: Qt.Horizontal
            normalStateColor: "transparent"

            onClicked: {
                model.uploadScore()
            }
        }

        FlatButton {
            text: qsTrc("appshell", "Export")
            icon: IconCode.SHARE_FILE

            enabled: model.exportScoreEnabled
            orientation: Qt.Horizontal
            normalStateColor: "transparent"

            onClicked: {
                model.exportScore()
            }
        }

        FlatButton {
            text: qsTrc("appshell", "Image Capture")
            icon: IconCode.CAMERA

            enabled: model.imageCaptureEnabled
            orientation: Qt.Horizontal
            normalStateColor: "transparent"

            onClicked: {
                model.startImageCapture()
            }
        }
    }
}
