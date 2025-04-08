#ifndef PARENTHESIS_H
#define PARENTHESIS_H

#include <stdbool.h>

bool Algorithm_Parenthesis_IsValid(char *expression);
bool isOpen(char character);
char getOpen(char closeCharacter);

#endif