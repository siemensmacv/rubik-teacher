#pragma once
enum class RubikFace
{
	Up = 0,
	Left,
	Front,
	Right,
	Back,
	Down
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
