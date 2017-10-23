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
#ifdef __cplusplus
}
#endif
