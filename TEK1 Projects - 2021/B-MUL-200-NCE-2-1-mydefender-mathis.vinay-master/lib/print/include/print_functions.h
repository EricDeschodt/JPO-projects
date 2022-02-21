/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-mathis.vinay
** File description:
** a header for preventing having to prototype all the functions in the
** fucking code.
*/
#ifndef B_PSU_100_NCE_1_1_MYPRINTF_MATHIS_VINAY_PRINTF_FUNCTIONS_H
#define B_PSU_100_NCE_1_1_MYPRINTF_MATHIS_VINAY_PRINTF_FUNCTIONS_H

int pf_u_int(unsigned int n, char *format);

int pf_u_octal(unsigned int n, char *format);

int pf_u_hexadecimal(unsigned int n, char *format);

int pf_u_maj_hexadecimal(unsigned int n, char *format);

int pf_pointer_adress(void *ptr, char *format);

int pf_u_bin(unsigned int n, char *format);

int pf_str_w_oct(char *str, char *format);

int pf_str(char const *str, char *format);

int pf_char(char c, char *format);

int pf_nbr(int n, char *format);

int pf_long(long n, char *format);

#endif //B_PSU_100_NCE_1_1_MYPRINTF_MATHIS_VINAY_PRINTF_FUNCTIONS_H
