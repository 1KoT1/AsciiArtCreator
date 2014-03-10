#ifndef ALGORITHMES_H
#define ALGORITHMES_H

#include <QObject>
#include <QMetaEnum>

class Algorithmes: public QObject{
    Q_OBJECT
    Q_ENUMS(AlgorithmesEnum)
public:
    enum AlgorithmesEnum{
        OnePixelOneChar,
        OnePixelMoneyChars
    };
    /** Получить метаобъект перечисления. @see QMetaEnum */
    static inline const QMetaEnum m(){
        const QMetaObject &mo = Algorithmes::staticMetaObject;
        return mo.enumerator(mo.indexOfEnumerator("AlgorithmesEnum"));
    }
};

#endif // ALGORITHMES_H
