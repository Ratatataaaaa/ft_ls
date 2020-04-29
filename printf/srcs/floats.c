#include "../includes/ft_printf.h"
# define SIZE_E 127
# define SIZE_M 23

//void    bit_parcer(long double f)
//{
//    t_sun eeei;
//    //unsigned displayMask = 1 << 22;
//    int c;
//
//    eeei.f = f;
//    printf("\n");
////    printf("%d_ %d_ %d  %f\n", eeei.v.sign, eeei.v.exp, eeei.v.mant, eeei.f);
//    for (c=0; c<=23; c++)
//    {
//        ft_putchar(eeei.v.mant & (1 << c) ? '1' : '0');
//        //eeei.v.mant <<= 1;
//
////        if (c % 8 == 0)
////            putchar(' ');
//    }
//}

void    *ft_cpy(char *newptr, char *ptr, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (ptr[i] != '\0')
    {
        newptr[i] = ptr[i];
        i++;
    }
    while (i < size)
    {
        newptr[i] = '0';
        i++;
    }
    return (newptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
    char	*newptr;

    if (size == 64)
        printf("1\n");
    printf("realloc\n");
    if (!size && ptr)
    {
        if (!(newptr = (char *)malloc(1)))
            return (NULL);
        ft_memdel(&ptr);
        return (newptr);
    }
    if (!(newptr = (char *)malloc(size)))
        return (NULL);
    if (ptr)
    {
        ft_cpy(newptr, ptr, size);
        //free(ptr);
        //ft_memdel(&ptr);
    }
//    printf("newptr:%s\n", newptr);
    return (newptr);
}

int two_degree(int s)
{
    int i;
    unsigned long long a;

    a = 1;
    i = 0;
    while (i < s)
    {
        a *= 2;
        i++;
    }
    return (a);
}

void    *get_char(char *arr)
{
    char *mas;
    int i;
    int j;
    char tmp;

    j = ft_strlen(arr);
    i = 0;
    mas = ft_memalloc(ft_strlen(arr));
    while (arr[i] != '\0')
    {
        mas[i] = arr[j - 1];
        i++;
        j--;
    }
   // ft_memdel(&arr);
    return (mas);
}

void    *sum_char(char *ans, char *tmp)
{
    int i;
    int j;
    char symb;
    char *str;
    char *newptr;

    str = ft_memalloc(ft_strlen(tmp));
    ft_strcpy(str, tmp);
    i = ft_strlen(ans);
    j = ft_strlen(str);
    while ((i - 1) == j || j > i)
    {
        ans = ft_realloc(ans, (i*2));
        i = ft_strlen(ans);
        j = ft_strlen(str);
    }

    i = 0;
    while (str[i] != '\0' && ans[i] != '\0')
    {
        symb = str[i];
        ans[i] += symb - '0';
        if (ans[i] > '9')
        {
            if (ans[i + 1] == '\0')
            {
                newptr = ft_strnew(j + 1);
                ft_strcpy(newptr, ans);
                newptr[i] -= 10;
                newptr[i + 1] = 49;
                free(ans);
                return (newptr);
            }
            else
            {
                ans[i + 1]++;
                ans[i] -= 10;
            }
        }
        i++;
    }
    return (ans);
}

void    *sum_reverse(char *ans, char *tmp)
{
    int i;
    int j;
    char symb;
    char *arr;

    i = ft_strlen(ans);
    j = ft_strlen(tmp);
    arr = ft_memalloc(j);
    arr = get_char(tmp);
    while ((i - 1) == j || j > i)
    {
        ans = ft_realloc(ans, (i*2));
        i = ft_strlen(ans);
    }
//    while (i > j && ans[i - 1] == '0')
//        i--;
    i = 0;
    j = 0;
    while (arr[j] != '\0')
    {
        symb = arr[j];
        ans[i] += symb - '0';
        if (ans[i] > '9')
        {
            if (ans[i + 1] == '\0')
                ans[i + 1] = '0';
            ans[i - 1]++;
            ans[i] -= 10;
        }
        i++;
        j++;
    }
    return (ans);
}

void    *get_zero(char *arr)
{
    char *newptr;
    int i;

    newptr = ft_memalloc(ft_strlen(arr) + 1);
    i = 0;
    while (arr[i] != '\0')
    {
        newptr[i] = arr[i];
        i++;
    }
    newptr[i] = '0';
    ft_memdel(&arr);
    return (newptr);
}

void    *multiplication(char *arr, int num, int deg)
{
    int i;
    int j;
    char symb;
    char *newptr;

    i = ft_strlen(arr);
    newptr = ft_memalloc(ft_strlen(arr) + 1);
    ft_strcpy(newptr, arr);

    i = 0;
    while (i < num - 1)
    {
        j = 0;
        while (arr[j] != '\0')
        {
            symb = arr[j];
            newptr[j] += symb - '0';
            if (newptr[j] > '9')
            {
                if (newptr[j + 1] == '\0')
                    newptr[j + 1] = '0';
                newptr[j + 1]++;
                newptr[j] -= 10;
            }
            j++;
        }
        i++;
    }
    i = ft_strlen(newptr);
    if (ft_strlen(newptr) < deg)
        newptr = get_zero(newptr);
//    printf("newptr:%s\n", newptr);
    return (newptr);
}

void    ft_out(char *fp, char *sp)
{
    int i;
    int j;

    j = ft_strlen(sp);
    i = 0;
    while (fp[i] == '0')
        i++;
    while (fp[i] != '\0')
    {
        ft_putchar(fp[i]);
        i++;
    }
    ft_putchar('.');
    while (sp[j] == '0')
        j--;
    i = 0;
    while (i < j)
    {
        ft_putchar(sp[i]);
        i++;
    }
}

void    bit_parcer(float f)
{
    t_sun eeei;
    int c;
    int shift;
    int b;
    int count;
    unsigned long long sum;
    char *arr;
    char *fp;
    char *sp;
    int size;

    size = 8;
    sp = ft_memalloc(size);
    sp = ft_realloc(sp, size);
    fp = ft_memalloc(size);
    fp = ft_realloc(fp, size);
    arr = ft_memalloc(1);
    arr[0] = '1';
    printf("fp:%s\n", fp);
    eeei.f = f;
    sum = 0;
    c = sizeof(f);
    printf("%d_ %d_ %d  %.32f\n", eeei.v.sign, eeei.v.exp, eeei.v.mant, eeei.f);
    shift = exp_shift(eeei);
    printf("shift:%d\n", shift);
    for (c = (SIZE_M - shift); c < SIZE_M; c++)
        ft_putchar(eeei.v.mant & (1 << c) ? '1' : '0');
    printf("\n");
    for (c = (SIZE_M - shift); c < SIZE_M; c++)
    {
        if (c == (SIZE_M - shift))
            continue ;
        if (c < 0)
        {
            arr = sum_char(arr, arr);
            continue ;
        }
        eeei.v.mant & (1 << c) ? (b = 1) : (b = 0);
        arr = sum_char(arr, arr);
        if (b == 1)
        {
            fp = sum_char(fp, arr);
//            printf("fp:%s arr:%s c:%d %d %d\n", fp, arr, c, ft_strlen(fp), ft_strlen(arr));
        }
    }
    arr = sum_char(arr, arr);
    fp = sum_char(fp, arr);
    printf("fp:%s arr:%s c:%d %d %d\n", fp, arr, c, ft_strlen(fp), ft_strlen(arr));
    fp = get_char(fp);
    printf("\nfp:%s\n", fp);

    for (c = (SIZE_M - shift - 1); c >= 0; c--)
        ft_putchar(eeei.v.mant & (1 << c) ? '1' : '0');
    printf("\n");
    ft_memdel(&arr);
    arr = ft_memalloc(2);
    arr[0] = '1';
    printf("sp:%s\n", sp);
    count = 0;
    for (c = (SIZE_M - shift - 1); c >= 0; c--)
    {
        count++;
        eeei.v.mant & (1 << c) ? (b = 1) : (b = 0);
        arr = multiplication(arr, 5, count);
        if (b == 1)
        {
            sp = sum_reverse(sp, arr);
            printf("sp:%s arr:%s c:%d %d %d\n", sp, arr, c, ft_strlen(sp), ft_strlen(arr));
        }
    }
    printf("\n***********ANSWER***********\n");
    ft_out(fp, sp);
    printf("\n");
}

int exp_shift(t_sun eeei)
{
    int a;

    a = eeei.v.exp - SIZE_E;
    return (a);
}

//int two_degree(char *arr, int deg)
//{
//    int i;
//    int len;
//    char *newptr;
//
//    i = 0;
//    if (arr[i] == '\0')
//        arr[i] = '1';
//    i = ft_strlen(arr);
//    len = i;
//    while (deg > 0)
//    {
//        i--;
//        tmp = arr[i];
//        arr[i] += tmp - '0';
//        if (arr[i] > '9' && i == 0)
//        {
//            newptr = ft_strnew(len + 1);
//            fp[i]-= 10;
//            fp[i - 1]++;
//        }
//    }
//}