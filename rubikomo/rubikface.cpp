#include "rubikface.h"

int colorLetterToDigit(char c)
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
    }

    return static_cast<int>(face);
}

char colorDigitToLetter(int d)
{
    RubikFace face = static_cast<RubikFace>(d);
    switch(face)
    {
    case RubikFace::Up:
        return 'U';
    case RubikFace::Right:
        return 'R';
    case RubikFace::Front:
        return 'F';
    case RubikFace::Down:
        return 'D';
    case RubikFace::Left:
        return 'L';
    case RubikFace::Back:
        return 'B';
    }
}

char colorEnumToLetter(RubikFace face)
{
    switch(face)
    {
    case RubikFace::Back:
        return 'B';
    case RubikFace::Down:
        return 'D';
    case RubikFace::Front:
        return 'F';
    case RubikFace::Left:
        return 'L';
    case RubikFace::Right:
        return 'R';
    case RubikFace::Up:
        return 'U';
    }
}
