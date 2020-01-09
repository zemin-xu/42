#include "pf_format.h"

void pf_pad(t_output *str, size_t pad_len, size_t prec_len, char c)
{
    int rest;

    if (prec_len == 0 || str->length > pad_len)
    {
        if ((rest = pad_len - str->length) > 0)
        {
            while (rest > 0)
            {
                write(1, &c, 1);
                rest--;
            }
        }
    }
    else
    {
        if ((rest = pad_len - prec_len) > 0)
        {
            while (rest > 0)
            {
                write(1, &c, 1);
                rest--;
            }
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
    else if (str->format_type == 'i' || str->format_type == 'u' || 
            str->format_type == 'x' || str->format_type == 'X')
    {
        if ((rest = len - ft_strlen(str->content)) > 0)
        {
            while (--rest > -1)
                write(1, &c, 1);
        }
    }
}