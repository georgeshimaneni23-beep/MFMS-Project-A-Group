#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

static void trimNewline(char *buffer)
{
    size_t len;

    if (buffer == NULL)
    {
        return;
    }

    len = strlen(buffer);
    while (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r'))
    {
        buffer[len - 1] = '\0';
        len--;
    }
}

static int isBlank(const char *text)
{
    if (text == NULL)
    {
        return 1;
    }

    while (*text != '\0')
    {
        if (!isspace((unsigned char)*text))
        {
            return 0;
        }
        text++;
    }

    return 1;
}

int readInt(const char *prompt)
{
    char input[64];
    char *end = NULL;
    long value;

    while (1)
    {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        trimNewline(input);
        if (input[0] == '\0')
        {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        value = strtol(input, &end, 10);
        if (end == input || *end != '\0')
        {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        return (int)value;
    }
}

int readPositiveInt(const char *prompt)
{
    int value;

    while (1)
    {
        value = readInt(prompt);
        if (value > 0)
        {
            return value;
        }
        printf("Value must be greater than 0.\n");
    }
}

float readNonNegativeFloat(const char *prompt)
{
    char input[128];
    char *end = NULL;
    double value;

    while (1)
    {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        trimNewline(input);
        if (input[0] == '\0')
        {
            printf("Value cannot be empty.\n");
            continue;
        }

        value = strtod(input, &end);
        if (end == input || *end != '\0')
        {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (value < 0)
        {
            printf("Value cannot be negative.\n");
            continue;
        }

        return (float)value;
    }
}

void readText(const char *prompt, char *buffer, size_t size)
{
    if (buffer == NULL || size == 0)
    {
        return;
    }

    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, (int)size, stdin) == NULL)
        {
            printf("This field cannot be empty.\n");
            continue;
        }

        trimNewline(buffer);
        if (isBlank(buffer))
        {
            printf("This field cannot be empty.\n");
            continue;
        }

        return;
    }
}
