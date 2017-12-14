#include "rubikfaceutils.h"

int RubikFaceUtils::colorLetterToDigit(char c)
{
    RubikFace face;
    switch(c)
    {
    case 'U':
        face = RubikFace::Up;
        break;
    case 'R':
        face = RubikFace::Right;
        break;
    case 'F':
        face = RubikFace::Front;
        break;
    case 'D':
        face = RubikFace::Down;
        break;
    case 'L':
        face = RubikFace::Left;
        break;
    case 'B':
        face = RubikFace::Back;
        break;
    default:
        face = RubikFace::Grey;
    }

    return static_cast<int>(face);
}

char RubikFaceUtils::colorDigitToLetter(int d)
{
    RubikFace face = static_cast<RubikFace>(d);
    return colorEnumToLetter(face);
}

char RubikFaceUtils::colorEnumToLetter(RubikFace face)
{
    char result('\0');
    switch(face)
    {
    case RubikFace::Back:
        result = 'B';
        break;
    case RubikFace::Down:
        result = 'D';
        break;
    case RubikFace::Front:
        result = 'F';
        break;
    case RubikFace::Left:
        result = 'L';
        break;
    case RubikFace::Right:
        result = 'R';
        break;
    case RubikFace::Up:
        result = 'U';
        break;
    case RubikFace::Grey:
        result = 'G';
        break;
    default:
      result = 'G';
    }
    return result;
}

QColor RubikFaceUtils::colorDigitToQColor(int d)
{
    RubikFace face = static_cast<RubikFace>(d);
    return colorEnumToQColor(face);
}

QColor RubikFaceUtils::colorEnumToQColor(RubikFace face)
{
    QColor result = QColor(0,0,0);
    switch(face)
    {
    case RubikFace::Up:
        result = QColor(255, 255, 0);
        break;
    case RubikFace::Right:
        result = QColor(255, 130, 0);
        break;
    case RubikFace::Front:
        result = QColor(0, 255, 0);
        break;
    case RubikFace::Down:
        result = QColor(255, 255, 255);
        break;
    case RubikFace::Left:
        result = QColor(255, 0, 0);
        break;
    case RubikFace::Back:
        result = QColor(0, 0, 255);
        break;
    case RubikFace::Grey:
        result = QColor(128,128,128);
        break;
    default:
        result = QColor(128,128,128);
    }
    return result;
}

RubikFace RubikFaceUtils::qColorToEnum(QColor color)
{
    if(color == QColor(255, 255, 0))
        return RubikFace::Up;

    if(color == QColor(255, 130, 0))
        return RubikFace::Right;

    if(color == QColor(0, 255, 0))
        return RubikFace::Front;

    if(color == QColor(255, 255, 255))
        return RubikFace::Down;

    if(color == QColor(255, 0, 0))
        return RubikFace::Left;

    if(color == QColor(0, 0, 255))
        return RubikFace::Back;

    return RubikFace::Grey;
}
