#include "pf_format.h"

void pf_pad(t_output *str, int len, char char_padding)
{
    int rest;

    if ((rest = len - str->length) > 0)
    {
        while (rest > 0)
        {
            write(1, &char_padding, 1);
            rest--;
        }
    }
}