#include "chordsymbolsstylemodel.h"

namespace mu::notation {
chordsymbolsstylemodel::chordsymbolsstylemodel(QObject *parent) : QObject(parent)
{

}

void chordsymbolsstylemodel::extensionMagChanged(double value){
    StyleId id = StyleId::chordExtensionMag;
    globalContext()->currentNotation()->style()->setStyleValue(id, value);
}

int chordsymbolsstylemodel::setExtensionMag(double value){
    StyleId id = StyleId::chordExtensionMag;
    globalContext()->currentNotation()->style()->setStyleValue(id, value);
    return 0;
}

}

