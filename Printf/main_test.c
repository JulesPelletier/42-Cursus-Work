#include "includes/lib_printf.h"

#include <stdio.h>
#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRE  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"

int main()
{
    char    char1;
    char    char2;
    char    char3;
    char    char4;

    int int1;
    int int2;
    int int3;
    int int4;

    char    *str1;
    char    *str2;
    char    *str3;
    char    *str4;

    unsigned int uint1;
    unsigned int uint2;
    unsigned int uint3;
    unsigned int uint4;

    char1 = 'c';
    char2 = 's';
    char3 = 'E';
    char4 = '0';

    int1 = 12;
    int2 = -12;
    int3 = 0;
    int4 = -13401345;

    str1 = "lolilol";
    str2 = "Prout";
    str3 = "Pas drole !";
    str4 = "MDR";

    uint1 = 0;
    uint2 = 1234;
    uint3 = 12;
    uint4 = 23141234122;

    /*
    printf(YEL"\n============== TEST CHAR ===============\n\n");

    printf(MAG"ORIGINAL TEST\t"YEL": %c : %c : %c : %c \n", char1, char2, char3, char4);
    ft_printf(MAG"MY TEST\t\t"YEL": %c : %c : %c : %c \n", char1, char2, char3, char4);

    printf("\n============== TEST STRING ===============\n\n");

    printf(MAG"ORIGINAL TEST\t"YEL": %s : %s : %s : %s \n", str1, str2, str3, str4);
    ft_printf(MAG"MY TEST\t\t"YEL": %s : %s : %s : %s \n", str1, str2, str3, str4);

    printf("\n============== TEST POINTEUR ===============\n\n");

    printf(MAG"ORIGINAL TEST\t"YEL": %p : %p : %p : %p \n", &int1, &int2, &int3, &int4);
    ft_printf(MAG"MY TEST\t\t"YEL": %p : %p : %p : %p \n", &int1, &int2, &int3, &int4);

    printf("\n============== TEST DECIMAL ===============\n\n");

    printf(MAG"ORIGINAL TEST\t"YEL": %d : %d : %d : %d \n", int1, int2, int3, int4);
    ft_printf(MAG"MY TEST\t\t"YEL": %d : %d : %d : %d \n", int1, int2, int3, int4);

    printf("\n============== TEST INT ===============\n\n");

    printf(MAG"ORIGINAL TEST\t"YEL": %i : %i : %i : %i \n", int1, int2, int3, int4);
    ft_printf(MAG"MY TEST\t\t"YEL": %i : %i : %i : %i \n", int1, int2, int3, int4);

    printf("\n============== TEST UNSIGNED INT ===============\n\n");

    printf(MAG"ORIGINAL TEST\t"YEL": %u : %u : %u : %u \n", uint1, uint2, uint3, uint4);
    ft_printf(MAG"MY TEST\t\t"YEL": %u : %u : %u : %u \n", uint1, uint2, uint3, uint4);

    printf("\n============== TEST HEXADECIMAL INT (lower case) ===============\n\n");

    printf(MAG"ORIGINAL TEST\t"YEL": %x : %x : %x : %x \n", uint1, uint2, uint3, uint4);
    ft_printf(MAG"MY TEST\t\t"YEL": %x : %x : %x : %x \n", uint1, uint2, uint3, uint4);

    printf("\n============== TEST HEXADECIMAL INT (upper case) ===============\n\n");

    printf(MAG"ORIGINAL TEST\t"YEL": %X : %X : %X : %X \n", uint1, uint2, uint3, uint4);
    ft_printf(MAG"MY TEST\t\t"YEL": %X : %X : %X : %X \n", uint1, uint2, uint3, uint4);

    printf("\n============== TEST NO %% (upper case) ===============\n\n");

    printf(MAG"ORIGINAL TEST\t"YEL": blableo iwealiuhfaloihfbal.fiq\n");
    ft_printf(MAG"MY TEST\t\t"YEL": blableo iwealiuhfaloihfbal.fiq\n");

    printf("\n============== ADDITIONAL TESTS ===============\n\n");
    int a;

    a = printf(NRM"%%");
    ft_printf(YEL"%%");
    printf("A : %d\n\n", a);

    a = printf(NRM"%5%");
    ft_printf(YEL"%5%");
    printf("A : %d\n\n", a);

    a = printf(NRM"%-5%");
    ft_printf(YEL"%-5%");
    printf("A : %d\n\n", a);

    a = printf(NRM"%05%");
    ft_printf(YEL"%05%");
    printf("A : %d\n\n", a);

    a = printf(NRM"%-05%");
    ft_printf(YEL"%-05%");
    printf("A : %d\n\n", a);


    ft_printf("%d\n", ft_printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
    printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42);
    printf("\n");
    ft_printf("%d\n", ft_printf("4hexa-maj 1 %12X hexa-maj 2 %int12X\n", 42, -42));
    printf("4hexa-maj 1 %12X hexa-maj 2 %int12X\n", 42, -42);
    printf("\n");
    ft_printf("%d\n", ft_printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
    printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42);
    printf("\n");
    ft_printf("%d\n", ft_printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
    printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42);
    printf("\n");
    ft_printf("%d\n", ft_printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
    printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42);
    printf("\n");
    ft_printf("%d\n", ft_printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n", 42, 6, 6, 6));
    printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n", 42, 6, 6, 6);
    printf("\n");
    ft_printf("%d\n", ft_printf("1unsigned 1 %u unsigned 2 %u\n", 42, -42));
    printf("1unsigned 1 %u unsigned 2 %u\n", 42, -42);
    printf("\n");
    */

    ft_printf("%d\n", ft_printf("4unsigned 1 %12u unsigned 2 %12u\n", 42, -42));
    printf("4unsigned 1 %12u unsigned 2 %12u\n", 42, -42);
    printf("\n");
    ft_printf("%d\n", ft_printf("4unsigned 1 %-12u unsigned 2 %-12u\n", 42, -42));
    printf("4unsigned 1 %-12u unsigned 2 %-12u\n", 42, -42);
    printf("\n");
    ft_printf("%d\n", ft_printf("5unsigned 1 %0u unsigned 2 %0u\n", 42, -42));
     printf("5unsigned 1 %0u unsigned 2 %0u\n", 42, -42);
    printf("\n");
    ft_printf("%d\n", ft_printf("6unsigned 1 %012u unsigned 2 %012u\n", 42, -42));
    printf("6unsigned 1 %012u unsigned 2 %012u\n", 42, -42);
    printf("\n");
    ft_printf("%d\n", ft_printf("8unsigned 1 %*u unsigned 2 %*u\n", 42, 6, 6, 6));
    printf("8unsigned 1 %*u unsigned 2 %*u\n", 42, 6, 6, 6);
    printf("\n");
    ft_printf("%d\n", ft_printf("15unsigned 1 %.u unsigned 2 %.u\n", 42, -42));
    printf("15unsigned 1 %.u unsigned 2 %.u\n", 42, -42);
    printf("\n");
    printf("\n");
    printf("\n");

    printf("%");
    ft_printf("%");


    return (0);
}