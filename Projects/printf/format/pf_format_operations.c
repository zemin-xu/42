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

void pf_precise(t_output *str, size_t len)
{
    int rest;
    char c;

    c = '0';
    if (str->format_type == 's' && len < ft_strlen(str->content))
        *(str->content + len) = '\0';
    else if (str->format_type == 'i')
    {
        if ((rest = len - ft_strlen(str->content)) > 0)
        {
            while (--rest > -1)
                write(1, &c, 1);
        }
    }
}