/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** core of print function
*/

#include <stdarg.h>
#include "../../include/print.h"
#include "../../include/print_functions.h"

bool is_element_format(char c, int element)
{
    if (element == 1)
        return my_is_char_in_str(c, "-+ #0");
    else if (element == 0)
        return my_is_char_in_str(c, "csdiuoxXpbS%nlN");
    return false;
}

int is_format(const char *format)
{
    int i = 0;
    while (is_element_format(format[i], 1))
        i++;
    if (is_element_format(format[i], 0))
        i++;
    else
        i = 0;
    return i;
}

char get_element_format(char const *format, int element)
{
    for (int i = 0; i < is_format(format); i++) {
        if (is_element_format(format[i], element))
            return format[i];
    }
    return '\0';
}

int flag_operations(const char *format, va_list args, int res)
{
    int (*functions[])() = {(int (*)()) pf_char, (int (*)()) pf_str, (int (*)
                            ()) pf_nbr, (int (*)()) pf_nbr, (int (*)())
                            pf_u_int, (int (*)()) pf_u_octal, (int (*)())
                            pf_u_hexadecimal, (int (*)())
                            pf_u_maj_hexadecimal, (int (*)()) pf_pointer_adress,
                            (int (*)()) pf_u_bin, (int (*)()) pf_str_w_oct,
                            (int (*)()) pf_long};
    char characters[] = "csdiuoxXpbSl";
    if (get_element_format(format, 0) == '%') {
        my_putchar('%');
        return 1;
    } else if (get_element_format(format, 0) == 'n')
        *va_arg(args, int (*)) = res;
    if (get_element_format(format, 0) == 'N')
        va_arg(args, void (*));
    for (int i = 0; characters[i]; i++)
        if (characters[i] == get_element_format(format, 0))
            return functions[i](va_arg(args,
    void (*)), format);
    return 0;
}