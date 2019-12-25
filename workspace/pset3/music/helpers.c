// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int X = atoi(&fraction[0]);
    int Y = atoi(&fraction[2]);
    return 8 * X / Y;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char letter = note[0];
    char accidental = '\0';
    int octave = 4;
    int len = strlen(note);

    if (len == 2)
    {
        octave = atoi(&note[1]);
    }
    else if (len == 3)
    {
        accidental = note[1];
        octave = atoi(&note[2]);
    }

    int a = 0;
    if (accidental == '#')
    {
        a = 1;
    }
    else if (accidental == 'b')
    {
        a = -1;
    }

    int n = 0;
    switch (letter)
    {
        case 'C':
            n = -9;
            break;
        case 'D':
            n = -7;
            break;
        case 'E':
            n = -5;
            break;
        case 'F':
            n = -4;
            break;
        case 'G':
            n = -2;
            break;
        case 'B':
            n = 2;
            break;
        case 'A':
        default:
            n = 0;
            break;
    }

    // return round(440 * pow(2, octave - 4) * pow(2, a / 12.) * pow(2, n / 12.));
    return round(440 * pow(2, (octave - 4) + (a + n) / 12.));
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return strlen(s) == 0;
}
