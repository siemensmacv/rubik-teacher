#pragma once
enum class RubikFace
{
	Up = 0,
    Right,
    Front,
    Down,
	Left,
    Back
};

#ifdef __cplusplus
extern "C" {
#endif
int colorLetterToDigit(char c);
char colorDigitToLetter(int d);
char colorEnumToLetter(RubikFace face);
#ifdef __cplusplus
}
#endif
