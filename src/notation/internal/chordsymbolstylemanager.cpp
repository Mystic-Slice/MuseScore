#include "chordsymbolstylemanager.h"
#include "framework/global/io/path.h"


ChordSymbolStyleManager::ChordSymbolStyleManager()
{
    retrieveChordStyles();
}
void ChordSymbolStyleManager::retrieveChordStyles()
{
    mu::io::paths chordStyleFiles = scanFileSystemForChordStyles();

    for (mu::io::path& file: chordStyleFiles) {
        if(isChordSymbolStylesFile(file)){
            extractChordStyleInfo(file);
        }
    }
}

mu::io::paths ChordSymbolStyleManager::scanFileSystemForChordStyles()
{
    mu::io::paths result;

    mu::io::path dirPath = globalConfiguration()->sharePath();
    mu::RetVal<mu::io::paths> files = fileSystem()->scanFiles(dirPath, { "*.xml" });

    result.insert(result.end(), files.val.begin(), files.val.end());
    return result;
}
bool ChordSymbolStyleManager::isChordSymbolStylesFile(mu::io::path& f) {
    bool isStyleFile = false;
    QString path = f.toQString();
    QFile file(path);
    Ms::XmlReader e(&file);

    while (e.readNextStartElement()) {
        if (e.name().toString() == "museScore") {
            if(e.attribute("type")=="chordStyle"){
                isStyleFile = true;
                break;
            }
        }
    }
    return isStyleFile;
}
void ChordSymbolStyleManager::extractChordStyleInfo(mu::io::path& f) {
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
