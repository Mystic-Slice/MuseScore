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

    function changeExtensionMag(val){
        var x = 1;
        x = chordSymbolStyle.setExtensionMag(val);
        name.text = qsTr("Hi");
        if(x === 0)button.text = qsTr("Yes");

    }

    function setStandardChord(str){
        chordSymbolStyle.setStandardChords(str);
    }

    ChordSymbolStyle {
        id: chordSymbolStyle
    }

    Column{
        width: root.width
        height: root.height
        Rectangle{
            id: canvas
            width: parent.width
            height: 200
            color: "steelblue"
            Text {
                id: name
                text: qsTr("HelloWorld")
            }

        }
        Button{
            id: buttonstd

            onClicked: setStandardChord("std")
            text: qsTr("std");
        }
        Button{
            id: buttonjazz

            onClicked: setStandardChord("jazz")
            text: qsTr("jazz");
        }
        SpinBox{
            id: spinBox

            onValueChanged: changeExtensionMag(value)
        }


            SpinBox{
                property int decimals: 1
                property real realValue: 1.0
                property real realFrom: 0.0
                property real realTo: 10.0
                property real realStepSize: 0.1
                property real factor: Math.pow(10, decimals)
                id: spinbox
                stepSize: realStepSize*factor
                value: realValue*factor
                to : realTo*factor
                from : realFrom*factor
                validator: DoubleValidator {
                    bottom: Math.min(spinbox.from, spinbox.to)*spinbox.factor
                    top:  Math.max(spinbox.from, spinbox.to)*spinbox.factor
                }
                textFromValue: function(value, locale) {
                            return parseFloat(value*1.0/factor).toFixed(decimals);
                        }
                onValueChanged: changeExtensionMag((value*1.0/factor).toFixed(decimals))
            }
    }
}
