#ifndef CHORDSYMBOLSTYLEMANAGER_H
#define CHORDSYMBOLSTYLEMANAGER_H

#include "modularity/ioc.h"
#include "iglobalconfiguration.h"
#include "system/ifilesystem.h"
#include "engraving/libmscore/xml.h"

struct ChordSymbolStyle{
    QString styleName;
    QString fileName;
    QHash<QString,QHash<QString,bool>> styleDefaults;
};

namespace mu::notation{
class ChordSymbolStyleManager
{
    INJECT(notation, framework::IGlobalConfiguration, globalConfiguration)
    INJECT(notation, system::IFileSystem, fileSystem)
public:
    ChordSymbolStyleManager();
    mu::io::paths scanFileSystemForChordStyles() const;
    QList<ChordSymbolStyle> retrieveChordStyles();
    bool isChordSymbolStylesFile(io::path& f) const;
    void extractChordStyleInfo(io::path& f);

    QList<ChordSymbolStyle> _chordStyles;

    QList<ChordSymbolStyle> getChordStyles(){
        return _chordStyles;
    }
};
}
#endif // CHORDSYMBOLSTYLEMANAGER_H
