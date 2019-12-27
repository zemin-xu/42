#ifndef PF_FORMAT_H
# define PF_FORMAT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../utils/ft_utils.h"

typedef struct      s_output
{
    char            *content;
    size_t          length;
    struct s_output *next;
}                   t_output;

int			pf_signed_int(va_list argp, t_output **res, int ret);
int			pf_unsigned_int(va_list argp, t_output **res, int ret);
int			pf_hex(va_list argp, t_output **res, int ret, int is_maj);
int			pf_pointer(va_list argp, t_output **res, int ret);

int			pf_char(va_list argp, t_output **res, int ret);
int			pf_str(va_list argp, t_output **res, int ret);
int			pf_percentage(t_output **res, int ret);

t_output        *t_output_new(void *content);
t_output        *t_output_last(t_output **head);
void    	    t_output_add(t_output **head, t_output *new);
void            t_output_free(t_output **head);
void            t_output_read(t_output *head);

#endif


