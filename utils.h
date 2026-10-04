#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

int readInt(const char *prompt);
int readPositiveInt(const char *prompt);
float readNonNegativeFloat(const char *prompt);
void readText(const char *prompt, char *buffer, size_t size);

#endif
