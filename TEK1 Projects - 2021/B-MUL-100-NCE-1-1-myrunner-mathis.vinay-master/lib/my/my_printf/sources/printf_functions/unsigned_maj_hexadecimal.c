/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-mathis.vinay
** File description:
** printf_unsigned_maj_hexadecimal
*/

#include "../../include/my.h"

void print_hex_maj_chiffre(int n);

int flags_long_long_gestionner(long long n, char *format);

int pf_u_maj_hexadecimal(unsigned int n, char *format)
{
    int res = flags_long_long_gestionner(n, format);
    unsigned int div = 0x10000000;
    bool printed = false;
    while (div != 0) {
        if ((n / div > 0) || printed) {
            res++;
            printed = true;
            print_hex_maj_chiffre(n / div);
            n = n % div;
        }
        div = (div != 1) ? div / 16 : 0;
    }
    return res;
}