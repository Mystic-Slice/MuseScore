#include "chordsymbolstylemanager.h"
#include "framework/global/io/path.h"


namespace mu::notation{
ChordSymbolStyleManager::ChordSymbolStyleManager()
{
    retrieveChordStyles();
}
QList<ChordSymbolStyle> ChordSymbolStyleManager::retrieveChordStyles()
{
    QList<ChordSymbolStyle> result;
    io::paths chordStyleFiles = scanFileSystemForChordStyles();

    for (io::path& file: chordStyleFiles) {
        if(isChordSymbolStylesFile(file)){
            extractChordStyleInfo(file);
        }
    }

    return result;
}

mu::io::paths ChordSymbolStyleManager::scanFileSystemForChordStyles() const
{
    io::paths result;

    io::path dirPath = globalConfiguration()->sharePath();
    RetVal<io::paths> files = fileSystem()->scanFiles(dirPath, { "*.xml" });

    result.insert(result.end(), files.val.begin(), files.val.end());

    return result;
}
bool ChordSymbolStyleManager::isChordSymbolStylesFile(io::path& f) const{
    bool isStyleFile = false;
    QString path = f.toQString();
    QFile file(path);
    Ms::XmlReader e(&file);

    while (e.readNextStartElement()) {
        if (e.name() == "museScore") {
            if(e.attribute("type")=="chordStyle"){
                isStyleFile = true;
                break;
            }
        }
    }
    return isStyleFile;
}
void ChordSymbolStyleManager::extractChordStyleInfo(io::path& f) {
    QString path = f.toQString();
    QFile file(path);
    Ms::XmlReader e(&file);
    QString styleName = "";
    while (e.readNextStartElement()) {
        if (e.name() == "museScore") {
            if(e.attribute("type")=="chordStyle"){
                styleName = e.attribute("styleName");
                break;
            }
        }
    }
    QHash<QString,QHash<QString,bool>> dummyDefaults = {
                 {"major",{{"maj",0},{"Ma",1}}},
                 {"minor",{{"min",0},{"m",1}}},
    };
    _chordStyles.push_back({styleName,path,dummyDefaults});
}
}
