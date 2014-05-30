#ifndef ALGORITHMSTATE_H
#define ALGORITHMSTATE_H

#include <QObject>
#include <QMetaEnum>

class AlgorithmStates : public QObject{
    Q_OBJECT
    Q_ENUMS(AlgorithmStateEnum)
public:
    enum AlgorithmStateEnum{
        Stoping,
        Running
    };
    /** Получить метаобъект перечисления. @see QMetaEnum */
    static inline const QMetaEnum m(){
        const QMetaObject &mo = AlgorithmStates::staticMetaObject;
        return mo.enumerator(mo.indexOfEnumerator("AlgorithmStateEnum"));
    }

};

#endif // ALGORITHMSTATE_H
