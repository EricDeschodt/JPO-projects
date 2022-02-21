/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-mathis.vinay
** File description:
** printf_pointer_adress
*/

#include "../../include/my.h"

void print_hex_min_chiffre(int n);

int pf_pointer_adress(void *ptr, char *format)
{
    int res = 2;
    unsigned long long n = (unsigned long long)ptr;
    {
        unsigned long long div = 0x1000000000000000;
        bool printed = false;
        my_putstr("0x");
        while (div != 0) {
            if ((n / div > 0) || printed) {
                printed = true;
                res++;
                print_hex_min_chiffre(n / div);
                n = n % div;
            }
            div = (div != 1) ? div / 16 : 0;
        }
    }
    return res;
}