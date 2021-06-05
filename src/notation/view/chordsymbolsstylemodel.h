#ifndef CHORDSYMBOLSSTYLEMODEL_H
#define CHORDSYMBOLSSTYLEMODEL_H

#include <QObject>
#include "modularity/ioc.h"
#include "context/iglobalcontext.h"

namespace mu::notation {
class chordsymbolsstylemodel : public QObject
{
    Q_OBJECT

    INJECT(notation, mu::context::IGlobalContext, globalContext)


public:
    explicit chordsymbolsstylemodel(QObject *parent = nullptr);

    void extensionMagChanged(double value);
    Q_INVOKABLE int setExtensionMag(double value);

signals:


private:


};
}
#endif // CHORDSYMBOLSSTYLEMODEL_H
