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

import MuseScore.UiComponents 1.0
import MuseScore.Ui 1.0

Item {
    id: root

    property var editorModel: null

    Row{
        Column{
            id: leftColumn

            StyledTextLabel{
                text: qsTrc("notation","Extensions")
            }

            Row{
                Column{
                    StyledTextLabel{
                        text: qsTrc("notation","Vertical Offset")
                    }

                    IncrementalPropertyControl {
                        id: extensionAdjustSpinBox

                        width: root.width/4

                        currentValue: editorModel.extensionAdjust

                        step: 1
                        minValue: 0.1
                        maxValue: 10

                        onValueEdited: editorModel.setProperty("ExtensionAdjust", newValue)
                    }
                }

                Column{
                    StyledTextLabel{
                        text: qsTrc("notation","Scaling")
                    }

                    IncrementalPropertyControl {
                        id: extensionMagSpinBox

                        width: root.width/4

                        currentValue: editorModel.extensionMag

                        step: 0.1
                        minValue: 0.1
                        maxValue: 10

                        onValueEdited: editorModel.setProperty("ExtensionMag", newValue)
                    }
                }

            }

            StyledTextLabel{
                text: qsTrc("notation","Alterations")
            }

            Row{
                Column{
                    StyledTextLabel{
                        text: qsTrc("notation","Vertical Offset")
                    }

                    IncrementalPropertyControl {
                        id: modifierAdjustSpinBox

                        width: root.width/4

                        currentValue: editorModel.modifierAdjust

                        step: 1
                        minValue: 0.1
                        maxValue: 10

                        onValueEdited: editorModel.setProperty("ModifierAdjust", newValue)
                    }
                }

                Column{
                    StyledTextLabel{
                        text: qsTrc("notation","Scaling")
                    }

                    IncrementalPropertyControl {
                        id: modifierMagSpinBox

                        width: root.width/4

                        currentValue: editorModel.modifierMag

                        step: 0.1
                        minValue: 0.1
                        maxValue: 10

                        onValueEdited: editorModel.setProperty("ModifierMag", newValue)
                    }
                }

            }
        }
        Column{
            id: rightColumn
        }
    }
}
