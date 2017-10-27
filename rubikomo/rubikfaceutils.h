#ifndef RUBIKFACEUTILS_H
#define RUBIKFACEUTILS_H

#include <QColor>
#include "rubikface.h"

class RubikFaceUtils
{
public:
    static int colorLetterToDigit(char c);
    static char colorDigitToLetter(int d);
    static char colorEnumToLetter(RubikFace face);
    static QColor colorDigitToQColor(int d);
    static QColor colorEnumToQColor(RubikFace face);
    static RubikFace qColorToEnum(QColor color);
};

#endif // RUBIKFACEUTILS_H
