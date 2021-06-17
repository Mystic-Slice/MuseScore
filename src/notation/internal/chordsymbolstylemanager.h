#ifndef CHORDSYMBOLSTYLEMANAGER_H
#define CHORDSYMBOLSTYLEMANAGER_H

#include "modularity/ioc.h"
#include "iglobalconfiguration.h"
#include "system/ifilesystem.h"
#include "engraving/libmscore/xml.h"

class ChordSymbolStyleManager
{
    INJECT(notation, mu::framework::IGlobalConfiguration, globalConfiguration)
    INJECT(notation, mu::system::IFileSystem, fileSystem)
public:
    ChordSymbolStyleManager();
    mu::io::paths scanFileSystemForChordStyles();
    void retrieveChordStyles();
    bool isChordSymbolStylesFile(mu::io::path& f);
    void extractChordStyleInfo(mu::io::path& f);

    QList<Ms::ChordSymbolStyle> _chordStyles;/* = {
        {"Standard","chords_std.xml",{
             {"major",{{"maj",0},{"Ma",1}}},
             {"minor",{{"min",0},{"m",1}}},
         }
        },{"Jazz","chords_jazz.xml",{
               {"major",{{"maj",0},{"Ma",1}}},
               {"minor",{{"min",0},{"m",1}}},
           }
        }
    };*/
    QList<Ms::ChordSymbolStyle> getChordStyles(){
        return _chordStyles;
    }
};

#endif // CHORDSYMBOLSTYLEMANAGER_H
