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

#ifndef CHORDSYMBOLEDITORMODEL_H
#define CHORDSYMBOLEDITORMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "modularity/ioc.h"
#include "context/iglobalcontext.h"
#include "engraving/libmscore/style.h"
#include "notation/internal/chordsymbolstylemanager.h"

class ChordSymbolEditorModel : public QAbstractListModel
{
    INJECT(notation, mu::context::IGlobalContext, globalContext)

    Q_OBJECT

    Q_PROPERTY(QStringList chordSpellingList READ chordSpellingList NOTIFY chordSpellingListChanged)
    Q_PROPERTY(QStringList majorSeventhList READ majorSeventhList NOTIFY majorSeventhListChanged)
    Q_PROPERTY(QStringList halfDiminishedList READ halfDiminishedList NOTIFY halfDiminishedListChanged)
    Q_PROPERTY(QStringList minorList READ minorList NOTIFY minorListChanged)
    Q_PROPERTY(QStringList augmentedList READ augmentedList NOTIFY augmentedListChanged)
    Q_PROPERTY(QStringList diminishedList READ diminishedList NOTIFY diminishedListChanged)

    Q_PROPERTY(int chordSpellingIndex READ chordSpellingIndex NOTIFY chordSpellingIndexChanged)
    Q_PROPERTY(int currentStyleIndex READ currentStyleIndex NOTIFY currentStyleIndexChanged)
    Q_PROPERTY(int majorSeventhIndex READ majorSeventhIndex NOTIFY majorSeventhIndexChanged)
    Q_PROPERTY(int halfDiminishedIndex READ halfDiminishedIndex NOTIFY halfDiminishedIndexChanged)
    Q_PROPERTY(int minorIndex READ minorIndex NOTIFY minorIndexChanged)
    Q_PROPERTY(int augmentedIndex READ augmentedIndex NOTIFY augmentedIndexChanged)
    Q_PROPERTY(int diminishedIndex READ diminishedIndex NOTIFY diminishedIndexChanged)

    Q_PROPERTY(qreal qualityMag READ qualityMag NOTIFY qualityMagChanged)
    Q_PROPERTY(qreal qualityAdjust READ qualityAdjust NOTIFY qualityAdjustChanged)
    Q_PROPERTY(qreal extensionMag READ extensionMag NOTIFY extensionMagChanged)
    Q_PROPERTY(qreal extensionAdjust READ extensionAdjust NOTIFY extensionAdjustChanged)
    Q_PROPERTY(qreal modifierMag READ modifierMag NOTIFY modifierMagChanged)
    Q_PROPERTY(qreal modifierAdjust READ modifierAdjust NOTIFY modifierAdjustChanged)
    Q_PROPERTY(qreal harmonyFretDistance READ harmonyFretDistance NOTIFY harmonyFretDistanceChanged)
    Q_PROPERTY(qreal minHarmonyDistance READ minHarmonyDistance NOTIFY minHarmonyDistanceChanged)
    Q_PROPERTY(qreal maxHarmonyBarDistance READ maxHarmonyBarDistance NOTIFY maxHarmonyBarDistanceChanged)
    Q_PROPERTY(qreal maxChordShiftAbove READ maxChordShiftAbove NOTIFY maxChordShiftAboveChanged)
    Q_PROPERTY(qreal maxChordShiftBelow READ maxChordShiftBelow NOTIFY maxChordShiftBelowChanged)
    Q_PROPERTY(qreal capoFretPosition READ capoFretPosition NOTIFY capoFretPositionChanged)

//    { StyleId::harmonyFretDist,         false, harmonyFretDist,         0 },
//    { StyleId::minHarmonyDistance,      false, minHarmonyDistance,      0 },
//    { StyleId::maxHarmonyBarDistance,   false, maxHarmonyBarDistance,   0 },
//    { StyleId::maxChordShiftAbove,      false, maxChordShiftAbove,      resetMaxChordShiftAbove },
//    { StyleId::maxChordShiftBelow,      false, maxChordShiftBelow,      resetMaxChordShiftBelow },
public:
    ChordSymbolEditorModel(QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;

    QStringList chordSpellingList() const;
    QStringList majorSeventhList() const;
    QStringList halfDiminishedList() const;
    QStringList minorList() const;
    QStringList augmentedList() const;
    QStringList diminishedList() const;

    int chordSpellingIndex() const;
    int currentStyleIndex() const;
    int majorSeventhIndex() const;
    int halfDiminishedIndex() const;
    int minorIndex() const;
    int augmentedIndex() const;
    int diminishedIndex() const;

    qreal qualityMag() const;
    qreal qualityAdjust() const;
    qreal extensionMag() const;
    qreal extensionAdjust() const;
    qreal modifierMag() const;
    qreal modifierAdjust() const;
    qreal harmonyFretDistance() const;
    qreal minHarmonyDistance() const;
    qreal maxHarmonyBarDistance() const;
    qreal maxChordShiftAbove() const;
    qreal maxChordShiftBelow() const;
    qreal capoFretPosition() const;

    void initChordSpellingList();
    void initCurrentStyleIndex();
    void initProperties();
    void updatePropertyIndices();
    void updateQualitySymbolsIndices();
    void setQualitySymbolsLists();
    void refreshChordSymbols();

    Q_INVOKABLE void setChordStyle(QString styleName);
    Q_INVOKABLE void setChordSpelling(QString spelling);
    Q_INVOKABLE void setQualitySymbol(QString quality, QString symbol);
    Q_INVOKABLE void setProperty(QString property, qreal val);

signals:
    void chordSpellingListChanged();
    void majorSeventhListChanged();
    void halfDiminishedListChanged();
    void minorListChanged();
    void augmentedListChanged();
    void diminishedListChanged();

    void chordSpellingIndexChanged();
    void currentStyleIndexChanged();
    void majorSeventhIndexChanged();
    void halfDiminishedIndexChanged();
    void minorIndexChanged();
    void augmentedIndexChanged();
    void diminishedIndexChanged();

    void qualityMagChanged();
    void qualityAdjustChanged();
    void extensionMagChanged();
    void extensionAdjustChanged();
    void modifierMagChanged();
    void modifierAdjustChanged();
    void harmonyFretDistanceChanged();
    void minHarmonyDistanceChanged();
    void maxHarmonyBarDistanceChanged();
    void maxChordShiftAboveChanged();
    void maxChordShiftBelowChanged();
    void capoFretPositionChanged();

private:
    enum RoleNames {
        StyleNameRole = Qt::UserRole + 1,
        FileRole
    };

    QList<Ms::ChordSymbolStyle> m_styles;
    ChordSymbolStyleManager* styleManager;
    QHash<QString, QStringList> m_qualitySymbols;

    QStringList m_chordSpellingList;
    QStringList m_majorSeventhList;
    QStringList m_halfDiminishedList;
    QStringList m_minorList;
    QStringList m_augmentedList;
    QStringList m_diminishedList;

    int m_chordSpellingIndex;
    int m_currentStyleIndex;
    int m_majorSeventhIndex;
    int m_halfDiminishedIndex;
    int m_minorIndex;
    int m_augmentedIndex;
    int m_diminishedIndex;

    qreal m_qualityMag;
    qreal m_qualityAdjust;
    qreal m_extensionMag;
    qreal m_extensionAdjust;
    qreal m_modifierMag;
    qreal m_modifierAdjust;
    qreal m_harmonyFretDistance;
    qreal m_minHarmonyDistance;
    qreal m_maxHarmonyBarDistance;
    qreal m_maxChordShiftAbove;
    qreal m_maxChordShiftBelow;
    qreal m_capoFretPosition;

    QHash<QString, Ms::Sid> chordSpellingMap = {
        { "Standard", Ms::Sid::useStandardNoteNames },
        { "German", Ms::Sid::useGermanNoteNames },
        { "German Full", Ms::Sid::useFullGermanNoteNames },
        { "Solfege", Ms::Sid::useSolfeggioNoteNames },
        { "French", Ms::Sid::useFrenchNoteNames }
    };
};

#endif // CHORDSYMBOLEDITORMODEL_H
