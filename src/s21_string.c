#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    while (*str++ != '\0') {
        len++;
    }
    return len;
}

int s21_strcmp(char *str, char *str1) {
    char *s = str;
    char *s1 = str1;
    for (; *s && *s == *s1; s++, s1++) {}
    return (*s-*s1);
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    if (n == 0) {
        return 0;
    }
    while (n-- && *(char *)str1 == *(char *)str2) {
        str1 = (char *)str1 + 1;
        str2 = (char *)str2 + 1;
    }
    return (*((char*)str1) - *((char*)str2));
}

int s21_strncmp(const char *str, const char *str1, s21_size_t n) {
    char *s = (char*)str;
    char *s1 = (char*)str1;
        for (s21_size_t i = 0; *s && *s == *s1 && i < n; s++, s1++, i++) {}
        return (*s-*s1);
}


s21_size_t s21_strcspn(const char *str, const char *str1) {
    char *s = (char*)str;
    char *s1 = (char*)str1;
    int i = 0;
    int flag = 0;
    while (*s) {
        while (*s1) {
            if (*s == *s1) {
                flag = 1;
            }
            s1++;
        }
        if (flag == 1) {
            break;
        } else {
            i++;
        }
        s++;
        s1 = (char*)str1;
        flag = 0;
    }
    return i;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
    void * ptr = s21_NULL;
    for (s21_size_t i = 0; i < n; i++) {
        if (((char *)str)[i] == (unsigned char)c) {
            ptr = (char *)str + i;
            break;
        }
    }
    return ptr;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char * destination = dest;
    const char * source = src;
    for (s21_size_t i = 0; i < n; i++) {
        destination[i] = source[i];
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    char * destination = str;
    for (s21_size_t i = 0; i < n; i++) {
        destination[i] = (unsigned char)c;
    }
    return str;
}


void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    if (dest < src) {
        char *d = (char*)dest;
        char *s = (char*)src;
        for (s21_size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else {
        char *d = (char*)dest + n;
        char *s = (char*)src + n;
        for (int i = n - 1; i >= 0; i--) {
            *(d - (n - i)) = *(s - (n - i));
        }
    }
    return dest;
}

char *s21_strrchr(const char *str, int c) {
    char * ptr = s21_NULL;
    s21_size_t i = 0;
    for (; str[i]!= '\0'; i++) {
        if ((unsigned char)c == str[i]) {
            ptr = (char *)str + i;
        }
    }
    if (str[i] == '\0' && c == '\0') {
        ptr = (char *)str + i;
    }
    return ptr;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *d = (char*)dest;
    char *s = (char*)src;
    for (; *d; d++) {}
    for (s21_size_t i = 0; *s && i < n; i++, s++, d++) {
        *d = *s;
    }
    *s = 0;
    return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t j = 0;
    while (*src && src[j] != '\0' && j < n) {
        dest[j] = src[j];
        j++;
    }
    if (src[j] == '\0') {
        while (j < n) {
            dest[j] = '\0';
            j++;
        }
    }
    return dest;
}

char *s21_strcpy(char *dest, const char *src) {
    s21_size_t i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

char *s21_strcat(char *dest, const char *src) {
    char *d = dest;
    while (*dest) {
        dest++;
    }
    while ((*dest++ = *src++) != '\0') {}
    return d;
}

char *s21_strchr(const char *str, int c) {
    char *j = 0;

        while (*str != '\0') {
            if (*str == c) {
                j = (char *)str;
                break;
            }
            str++;
        }
        if (*str == '\0' && *str == c) {
            j = (char *)str;
        }
    return j;
}


char *s21_strstr(const char *haystack, const char *needle) {
    char *j = 0;
    int i = s21_strlen(needle);
    while (*haystack != '\0') {
        char *tmp_1 = (char *)haystack;
        char *tmp_2 = (char *)needle;

        while (*tmp_1 == *tmp_2 && i > 0) {
            tmp_1++;
            tmp_2++;
            if (*tmp_2 == '\0') {
                j = (char *)haystack;
                break;
            }
        }
        if (j != 0) {
            break;
        }
        if (i == 0) {
            j = (char *)haystack;
            break;
        }
        haystack++;
    }
return j;
}

char *s21_strtok(char *str, char *delim) {
    char *j = str;
    static char *last;

    if (!str) {
        str = last;
    }

    if (str) {
        while (1) {
            for (int i = 0; i < (int)s21_strlen(delim); i++) {
                if (*str == delim[i]) {
                    str++;
                    continue;
                }
            }
            if (*str == '\0') {
                j = s21_NULL;
            }
            break;
        }
        if (*str != '\0') {
            j = str;
            while (1) {
                if (*str == '\0') {
                    last = str;
                    break;
                }
                for (int i = 0; i < (int)s21_strlen(delim); i++) {
                    if (*str == delim[i]) {
                        *str = '\0';
                        last = str + 1;
                        break;
                    }
                }
                str++;
            }
        }
        if ((j != s21_NULL) && (j[0] == '\0')) {
            j = s21_NULL;
        }
    } else {
        j = s21_NULL;
    }
    return j;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *ptr = s21_NULL;
    for (s21_size_t i = 0; (str1[i] != '\0'); i++) {
        for (s21_size_t j=0; (str2[j] != '\0'); j++) {
            if (str1[i] == str2[j]) {
                ptr = (char*)&str1[i];
                break;
            }
        }
        if (ptr != s21_NULL) {
            break;
        }
    }
    return ptr;
}

char *s21_strerror(int errnum) {
    char *errors[] = ERRORS;
    char buf[512];
    static char result[512] = {'\0'};
    for (int i = 0; i < 512; i++) {
        buf[i] = '\0';
    }
    int max = 106;
#if defined(__unix__) || defined(unix) || defined(__unix) || defined(__linux__) \
|| defined(__linux) || defined(linux)
max = 133;
#endif
#if defined(__APPLE__) || defined(__MACH__)
max = 106;
#endif
    if (errnum > max || errnum < 0) {
        int i = 0;
        int znak = 0;
        char str_2[256];
        if (errnum < 0) {
            znak = 1;
            errnum*=-1;
        }
        while (errnum != 0) {
            int rem = errnum % 10;
            str_2[i++] = rem + '0';
            errnum = errnum/10;
        }
        if (znak) {
            str_2[i++] = '-';
        }
        str_2[i++] = '\0';
#if defined(__unix__) || defined(unix) || defined(__unix) || defined(__linux__) \
|| defined(__linux) || defined(linux)
s21_strcat(buf, "Unknown error ");
#endif
#if defined(__APPLE__) || defined(__MACH__)
s21_strcat(buf, "Unknown error: ");
#endif
        for (int j = s21_strlen(str_2) - 1; j > -1; j--) {
            s21_strncat(buf, str_2 + j, 1);
        }
    } else {
        s21_strcat(buf, errors[errnum]);
    }
    s21_strcpy(result, buf);
    return result;
}

s21_size_t s21_strspn(const char *str, const char *str1) {
    char *s = (char*)str;
    char *s1 = (char*)str1;
    s21_size_t i = 0;
    int flag = 0;
    while (*s) {
        while (*s1) {
            if (*s == *s1) {
                flag = 1;
            }
            s1++;
        }
        if (flag == 0) {
            break;
        } else {
            i++;
        }
        s++;
        s1 = (char*)str1;
        flag = 0;
    }
    return i;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    char *q = str;
    int flag_plus = 0, flag_probel = 0, flag_minus = 0, flag_tocka = 0 \
    , flag_shirina = 0, flag_tochnost = 0, flag_long = 0;
    for (const char *p = format; *p; p++) {
        initialize_flags(&flag_plus, &flag_probel, &flag_minus, &flag_tocka \
        , &flag_shirina, &flag_tochnost, &flag_long);
        if (*p != '%') {
            *q = *p;
            q++;
        } else {
            int a = 0;
            int b = 0;
            format_handler(&q, &p, &a, &b, &flag_plus, &flag_probel, &flag_minus \
            , &flag_tocka, &flag_shirina, &flag_tochnost, &flag_long);
            if (*p == 'd' || *p == 'i' || *p == 'u') {
                int_handler(&q, &p, ap, a, b, flag_tocka, flag_tochnost \
                , flag_minus, flag_plus, flag_probel, flag_shirina, flag_long);
            } else if (*p == 's') {
                string_handler(&q, flag_shirina, a, b, flag_minus, ap);
            } else if (*p == 'c') {
                char_handler(&q, a, flag_minus, ap);
            }
            if (*p == 'f') {
                float_handler(&q, ap, a, b, flag_tocka, flag_tochnost, flag_minus \
                , flag_plus, flag_probel, flag_shirina);
            }
        }
        *q = '\0';
        va_end(ap);
    }
    return s21_strlen(q);
}

void initialize_flags(int *flag_plus, int *flag_probel, int *flag_minus \
, int *flag_tocka, int *flag_shirina, int *flag_tochnost, int *flag_long) {
    *flag_plus = 0;
    *flag_probel = 0;
    *flag_minus = 0;
    *flag_tocka = 0;
    *flag_shirina = 0;
    *flag_tochnost = 0;
    *flag_long = 0;
    return;
}

void format_handler(char **q, const char **p, int *a, int *b, int *flag_plus \
, int *flag_probel, int *flag_minus, int *flag_tocka, int *flag_shirina \
, int *flag_tochnost, int *flag_long) {
    (*p)++;
    if (*(*p) == '%') {
        *(*q) = '%';
        (*q)++;
    }
    for (int i = 0; i < 6; i++) {
        if (*(*p) == ' ') {
            *flag_probel = 1;
            (*p)++;
        }
        if (*(*p) == '+') {
            *flag_plus = 1;
            (*p)++;
        }
        if (*(*p) == '-') {
            *flag_minus = 1;
            (*p)++;
        }
        if (*(*p) >= '0' && *(*p) <= '9') {
            if (*(*p) != '0') {
                *flag_shirina = 1;
                *a = *(*p) - 48;
            }
            (*p)++;
            while (*(*p) >= '0' && *(*p) <= '9') {
                int o = *(*p) - 48;
                *a = 10*(*a) + o;
                (*p)++;
            }
        }
        if (*(*p) == '.') {
            *flag_tocka = 1;
            (*p)++;
            if (*(*p) >= '1' && *(*p) <= '9') {
                *flag_tochnost = 1;
                *b = *(*p) - 48;
                (*p)++;
                while (*(*p) >= '0' && *(*p) <= '9') {
                    int z = *(*p) - 48;
                    *b = 10*(*b) + z;
                    (*p)++;
                }
            }
        }
        if (*(*p) == 'l') {
            *flag_long = 1;
            (*p)++;
        }
        if (*(*p) == 'h') {
            *flag_long = -1;
            (*p)++;
        }
    }
    return;
}

char* convert(char* buff, int size, unsigned int num, int base) {
    char *p = 0;

    if (size >= INT_STR_SIZE) {
        p = &buff[size - 1];
        *p = '\0';

        while (num && base) {
            *--p = "0123456789abcdef"[num % base];
            num /= base;
        }
    }
    return p;
}


char * filling_str(char **q, const char **ptr, int n) {
    for (int i = 0; i < n; i++) {
        *(*q + i) = *(*ptr + i);
    }
    for (int i = 0; i < n; i++) {
        (*q)++;
    }
    return *q;
}

void filling_str_float(char **q, char **ptrt, int n) {
    int digit = 0;
    if (*(*ptrt + n - 1) - 48 >= 5) {
      digit = 1;
    }
    for (int i = n - 2; i > -1; i--) {
      *((*q) + i) = (*(*ptrt + i) + digit - 48) % 10 + 48;
      digit = (*(*ptrt + i) + digit - 48) / 10;
    }
    if (digit > 0) {
      for (int i = -1; digit > 0; i--) {
          int tmp_val = 0;
          tmp_val = *((*q) + i);
          *((*q) + i) = (tmp_val + digit - 48) % 10 + 48;
          digit = (tmp_val + digit - 48) / 10;
      }
    }
    *((*q) + n - 1) = '\0';
    for (int i = 0; i < n - 1; i++) {
      (*q)++;
      (*ptrt)++;
    }
    return;
}

void int_handler(char **q, const char **p, va_list ap, int a, int b \
, int flag_tocka, int flag_tochnost, int flag_minus, int flag_plus \
, int flag_probel, int flag_shirina, int flag_long) {
    long long int iuv = 0;
    int_id(p, &iuv, flag_long, ap);
    long long int uiv = 0;
    uiv = iuv;
    int k = 0;
    int sign = 1;
    if (iuv < 0) {
        uiv *= -1;
        sign = -1;
        k++;
    }
    iuv *= sign;
    while (iuv) {
        k += 1;
        iuv /= 10;
    }
    if ((flag_plus == 1 || flag_probel == 1) && sign == -1) {
        k++;
    }
    if (flag_minus == 0) {
        int_flag_minus_zero(q, a, b, k, uiv, sign, flag_plus, flag_shirina, \
                            flag_tocka, flag_tochnost, flag_probel);
    } else {
        int_flag_minus_one(q, a, b, k, uiv, sign, flag_plus, flag_shirina, flag_tocka, flag_tochnost);
    }
    return;
}

void int_flag_minus_zero(char **q, int a, int b, int k, long long int uiv, int sign \
    , int flag_plus, int flag_shirina, int flag_tocka, int flag_tochnost \
                         , int flag_probel) {
    char temp[INT_STR_SIZE*2];
    if (flag_shirina == 1) {
        int_shirina_one(q, a, b, k, sign, flag_tocka, flag_tochnost, flag_plus);
    } else {
        if (sign == -1) {
            *(*q) = '-';
            (*q)++;
        }
        if (flag_plus == 1 && sign == 1) {
            *(*q) = '+';
            (*q)++;
        }
        if (b > k) {
            if (flag_plus == 1 && sign == -1) {
                *(*q) = '0';
                (*q)++;
            }
            for (int i = 0; i < b - k + (1-sign)/2; i++) {
                *(*q) = '0';
                (*q)++;
            }
        }
    }
    if (flag_plus == 1 && sign == 1 && flag_shirina == 1) {
        *(*q) = '+';
        (*q)++;
    }
    if (flag_probel == 1 && sign == 1) {
        *(*q) = ' ';
        (*q)++;
    }
    const char *ptr = itoa(temp, sizeof(temp), uiv);
    filling_str(q, &ptr, k);
    return;
}

void int_shirina_one(char **q, int a, int b, int k, int sign \
                     , int flag_tocka, int flag_tochnost, int flag_plus) {
    if (flag_tocka == 1 && flag_tochnost == 1) {
        int_prefix(q, a, b, k, sign, flag_plus);
        if (k < b && k < a) {
            if (b >= a) {
                int_shirina_one_ba(q, b, k, sign);
            } else {
                int_shirina_one_ba_else(q, a, b, k, sign);
                if (flag_plus) {
                    *(*q) = '0';
                    (*q)++;
                }
            }
        }
        if (k >= a && k >= b && sign == -1) {
            *(*q) = '-';
            (*q)++;
        }
    } else {
        if (a > k) {
            for (int i = 0; i < a - k; i++) {
                *(*q) = ' ';
                (*q)++;
            }
        }
    }
    return;
}

void int_shirina_one_ba(char **q, int b, int k, int sign) {
    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
    }
    if (sign == 1) {
        for (int i = 0; i < b - k; i++) {
            *(*q) = '0';
            (*q)++;
        }
    } else {
        for (int i = 0; i < b - k + 1; i++) {
            *(*q) = '0';
            (*q)++;
        }
    }
    return;
}

void int_shirina_one_ba_else(char **q, int a, int b, int k, int sign) {
    if (sign == 1) {
        for (int i = 0; i < a - b; i++) {
            *(*q) = ' ';
            (*q)++;
        }
    } else {
        for (int i = 0; i < a - b - 1; i++) {
            *(*q) = ' ';
            (*q)++;
        }
    }

    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
    }
    for (int i = 0; i < b - k + (1 - sign)/2; i++) {
        *(*q) = '0';
        (*q)++;
    }
    *(*q) = '\0';
    return;
}

void int_flag_minus_one(char **q, int a, int b, int k, long long int uiv \
                        , int sign, int flag_plus, int flag_shirina \
                        , int flag_tocka, int flag_tochnost) {
    if (flag_shirina == 1) {
        if (flag_tocka == 1 && flag_tochnost == 1) {
            if (k >= b && k < a) {
                int_shirina_tocka_bka(q, a, b, k, sign, flag_plus, uiv);
            }
            if (k < b && k >= a) {
                int_shirina_tocka_kba(q, b, k, sign, flag_plus, uiv);
            }
            if (k < b && k < a) {
                if (b >= a) {
                    int_shirina_tocka_kab(q, b, k, sign, flag_plus, uiv);
                } else {
                    int_shirina_tocka_kab_else(q, a, b, k, sign, flag_plus, uiv);
                }
            }
            if (k >= b && k >= a) {
                int_shirina_tocka_abk(q, k, sign, flag_plus, uiv);
            }
        } else {
            int_tochnost_tocka(q, a, k, sign, flag_plus, uiv);
        }
    } else {
        int_shirina(q, b, k, sign, flag_plus, flag_tocka, flag_tochnost, uiv);
    }
    return;
}

void int_shirina_tocka_abk(char **q, int k, int sign, int flag_plus, long long int uiv) {
    char temp[INT_STR_SIZE*2];
    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
        k--;
    }
    if (sign == 1 && flag_plus == 1) {
        *(*q) = '+';
        (*q)++;
    }
    const char *ptr = itoa(temp, sizeof(temp), uiv);
    filling_str(q, &ptr, k);
    *(*q) = '\0';
    return;
}

void int_shirina_tocka_kab_else(char **q, int a, int b, int k, int sign, int flag_plus, long long int uiv) {
    char temp[INT_STR_SIZE*2];
    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
        k--;
    }
    if (sign == 1 && flag_plus == 1) {
        *(*q) = '+';
        (*q)++;
    }
    for (int i = 0; i < b - k; i++) {
        *(*q) = '0';
        (*q)++;
    }
    const char *ptr = itoa(temp, sizeof(temp), uiv);
    filling_str(q, &ptr, k);
    for (int i = 0; i < a - b - flag_plus - ((1-flag_plus)*(1-sign)/2); i++) {
        *(*q) = ' ';
        (*q)++;
    }
    *(*q) = '\0';
    return;
}

void int_shirina_tocka_kab(char **q, int b, int k, int sign, int flag_plus, long long int uiv) {
    char temp[INT_STR_SIZE*2];
    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
        k -= flag_plus + 1;
    }
    if (sign == 1 && flag_plus == 1) {
        *(*q) = '+';
        (*q)++;
    }
    for (int i = 0; i < b - k; i++) {
        *(*q) = '0';
        (*q)++;
    }
    const char *ptr = itoa(temp, sizeof(temp), uiv);
    filling_str(q, &ptr, k);
    *(*q) = '\0';
    return;
}

void int_shirina_tocka_kba(char **q, int b, int k, int sign, int flag_plus, long long int uiv) {
    char temp[INT_STR_SIZE*2];
    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
        k--;
    }
    if (sign == 1 && flag_plus == 1) {
        *(*q) = '+';
        (*q)++;
    }
    if (sign == 1) {
        for (int i = 0; i < b - k; i++) {
            *(*q) = '0';
            (*q)++;
        }
    } else {
        for (int i = 0; i < b - k ; i++) {
            *(*q) = '0';
            (*q)++;
        }
    }
    const char *ptr = itoa(temp, sizeof(temp), uiv);
    filling_str(q, &ptr, k);
    *(*q) = '\0';
    return;
}

void int_shirina_tocka_bka(char **q, int a, int b, int k, int sign, int flag_plus, long long int uiv) {
    char temp[INT_STR_SIZE*2];
    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
        k--;
    }
    if (sign == 1 && flag_plus == 1) {
        *(*q) = '+';
        (*q)++;
        k--;
    }
    int eq = 0;
    if (k == b) {
        *(*q) = '0';
        (*q)++;
        eq = 1;
    }
    const char *ptr = itoa(temp, sizeof(temp), uiv);
    int new_k = s21_strlen(ptr);
    filling_str(q, &ptr, new_k);
    for (int i = 0; i < a - new_k - eq - flag_plus - ((1 - flag_plus) * (1 - sign) / 2); i++) {
        *(*q) = ' ';
        (*q)++;
    }
    *(*q) = '\0';
}

void int_id(const char **p, long long int *iuv, int flag_long, va_list ap) {
    if (*(*p) == 'i' || *(*p) == 'd') {
        long long int ival = 0;
        if (flag_long == 1) {
            ival = (long long int)va_arg(ap, long int);
            *iuv = ival;
        } else {
            ival = (long long int)va_arg(ap, int);
            *iuv = ival;
        }
    } else {
        long long int uv = 0;
        unsigned long int uval = 0;
        if (flag_long) {
            uv = (long long int)va_arg(ap, long int);
        } else {
            uv = (long long int)va_arg(ap, int);
        }
        if (uv < 0) {
            uval = UINT_MAX + uv + 1;
        } else {
            uval = uv;
        }
        *iuv = uval;
    }
    return;
}

void int_prefix(char **q, int a, int b, int k, int sign, int flag_plus) {
    if (k >= b && k < a) {
        int eq = 0;
        if (b == k) {
            eq = 1;
        }
        for (int i = 0; i < a - k - flag_plus * sign - eq; i++) {
            *(*q) = ' ';
            (*q)++;
        }

        if (sign == -1) {
            *(*q) = '-';
            (*q)++;
        }
        for (int i = 0; i < b - k + (1 - sign) / 2; i++) {
            *(*q) = '0';
            (*q)++;
        }
    }
    if (k < b && k >= a) {
        if (sign == -1) {
            *(*q) = '-';
            (*q)++;
        }
        if (sign == 1) {
            for (int i = 0; i < b - k; i++) {
                *(*q) = '0';
                (*q)++;
            }
        } else {
            for (int i = 0; i < b - k + 1; i++) {
                *(*q) = '0';
                (*q)++;
            }
        }
    }
    return;
}

void int_tochnost_tocka(char **q, int a, int k, int sign, int flag_plus, long long int uiv) {
    char temp[INT_STR_SIZE*2];
    if (a > k) {
        if (sign == -1) {
            *(*q) = '-';
            (*q)++;
        }
        if (sign == 1 && flag_plus == 1) {
            *(*q) = '+';
            (*q)++;
        }
        const char *ptr = itoa(temp, sizeof(temp), uiv);
        int new_k = s21_strlen(ptr);
        filling_str(q, &ptr, s21_strlen(ptr));
        if (flag_plus == 1) {
            for (int i = 0; i < a - new_k - 1; i++) {
                *(*q) = ' ';
                (*q)++;
            }
        } else {
            for (int i = 0; i < a - new_k ; i++) {
                *(*q) = ' ';
                (*q)++;
            }
        }
        *(*q) = '\0';
    } else {
        if (sign == -1) {
            *(*q) = '-';
            (*q)++;
        }
        if (sign == 1 && flag_plus == 1) {
            *(*q) = '+';
            (*q)++;
        }
        const char *ptr = itoa(temp, sizeof(temp), uiv);
        filling_str(q, &ptr, k);
        *(*q) = '\0';
    }
    return;
}

void int_shirina(char **q, int b, int k, int sign, int flag_plus \
                 , int flag_tocka, int flag_tochnost \
                 , long long int uiv) {
    char temp[INT_STR_SIZE*2];
    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
    }
    if (sign == 1 && flag_plus == 1) {
        *(*q) = '+';
        (*q)++;
    }
    if (flag_tocka == 1 && flag_tochnost == 1) {
        if (b >= k) {
            for (int i = 0; i < b - k + (1 - sign) / 2; i++) {
                *(*q) = '0';
                (*q)++;
            }
        }
    }
    const char *ptr = itoa(temp, sizeof(temp), uiv);
    filling_str(q, &ptr, k);
    *(*q) = '\0';
    return;
}


void string_handler(char **q, int flag_shirina, int a, int b, int flag_minus, va_list ap) {
    char *sval = va_arg(ap, char *);
    int len = s21_strlen(sval);
    if (b != 0 && b < len) {
        len = b;
    }
    if (flag_shirina == 1 && len < a) {
        int shift = a - len;
        if (flag_minus) {
            for (int i = 0; i < len; i++) {
                *(*q) = *sval;
                (*q)++;
                sval++;
            }
            for (int i = 0; i< shift; i++) {
                **q = ' ';
                (*q)++;
            }
        } else {
            for (int i = 0; i< shift; i++) {
                **q = ' ';
                (*q)++;
            }
            for (int i = 0; i < len; i++) {
                **q = *sval;
                (*q)++;
                sval++;
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            **q = *sval;
            (*q)++;
            sval++;
        }
    }
}

void char_handler(char **q, int a, int flag_minus, va_list ap) {
    char ival;
    ival = (char)va_arg(ap, int);
    if (flag_minus == 0 && a != 0) {
        for (int i = 0; i < a - 1; ++i) {
            **q = ' ';
            (*q)++;
        }
        **q = ival;
        (*q)++;
    } else {
        **q = ival;
        (*q)++;
        for (int i = 0; i < a - 1; ++i) {
            **q = ' ';
            (*q)++;
        }
    }
}

void float_handler(char **q, va_list ap, int a, int b \
, int flag_tocka, int flag_tochnost, int flag_minus \
, int flag_plus, int flag_probel, int flag_shirina) {
    double fval = 0;
    char temp[INT_STR_SIZE*2];
    fval = va_arg(ap, double);
    int sign = 1;
    if (fval < 0) {
        fval *= -1;
        sign = -1;
    }
    int fk = (int)fval;
    double ft0 = fval - fk;
    if (flag_tocka == 1 && flag_tochnost == 0 && ft0 >= 0.5) {
        fk++;
    }
    int k = 0;
    int t = 0;
    int ft = ((int)(ft0 * PRECISION)) % PRECISION;
    char *char_float = itoa(temp, sizeof(temp), ft);
    int len_ft = s21_strlen(char_float);
    int fval_k = fk;
    int fval_t = ft;
    while (fk) {
        k++;
        fk /= 10;
    }
    while (ft) {
        t++;
        ft /= 10;
    }
    float_routine(q, a, b, k, t, fval_k, fval_t, len_ft \
                  , sign, flag_tocka, flag_tochnost, flag_minus \
                  , flag_plus, flag_probel, flag_shirina);
    return;
}

void float_routine(char **q, int a, int b, int k, int t \
, int fval_k, int fval_t, int len_ft, int sign \
, int flag_tocka, int flag_tochnost, int flag_minus \
, int flag_plus, int flag_probel, int flag_shirina) {
    if (flag_tocka == 1 && flag_tochnost == 0) {
        t = 0;
    }
    if (flag_minus == 0) {
        float_minus_zero(q, a, b, k, t, fval_k, fval_t \
                         , len_ft, sign, flag_tocka \
                         , flag_tochnost, flag_plus \
                         , flag_probel, flag_shirina);
    } else {
        float_minus_one(q, a, b, k, t, fval_k, fval_t \
                        , len_ft, sign, flag_tocka \
                        , flag_tochnost, flag_plus \
                        , flag_probel, flag_shirina);
    }
    return;
}

void float_minus_zero(char **q, int a, int b, int k \
, int t, int fval_k, int fval_t, int len_ft, int sign \
, int flag_tocka, int flag_tochnost, int flag_plus \
, int flag_probel, int flag_shirina) {
    char temp[INT_STR_SIZE*2];
    if (flag_shirina == 1) {
        float_shirina(q, a, b, k, flag_plus, sign, flag_tocka);
    }
    if (flag_plus == 1 && sign == 1) {
        *(*q) = '+';
        (*q)++;
    }
    if (flag_probel == 1 && sign == 1) {
        *(*q) = ' ';
        (*q)++;
    }
    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
    }
    const char *ptr = itoa(temp, sizeof(temp), fval_k);
    filling_str(q, &ptr, k);
    if (flag_tochnost == 1 && flag_tocka == 1) {
        float_minus_zero_routine(q, b, t, fval_t, len_ft);
    }
    if (flag_tochnost == 0 && flag_tocka == 0) {
        float_tochnost_tocka(q, fval_t, len_ft);
    }
    return;
}

void float_minus_zero_routine(char **q, int b, int t \
, int fval_t, int len_ft) {
    char temp[INT_STR_SIZE*2];
    *(*q) = '.';
    (*q)++;
    if (b > t) {
        const char *ptrt = itoa(temp, sizeof(temp), fval_t);
        if (len_ft < 9) {
            for (int i = 0; i < 9 - len_ft && i < b ; i++) {
                *(*q) = '0';
                (*q)++;
            }
        }
        filling_str(q, &ptrt, t);
        for (int i = 0; i < b - t - 9 + len_ft; i++) {
            *(*q) = '0';
            (*q)++;
        }
    }
    if (b == t) {
        char *ptrt = itoa(temp, sizeof(temp), fval_t);
        if (len_ft < 9) {
            for (int i = 0; i < 9 - len_ft && i < b; i++) {
                *(*q) = '0';
                (*q)++;
            }
        }
        filling_str_float(q, &ptrt, b);
    }
    if (b < t) {
        char *ptrt = itoa(temp, sizeof(temp), fval_t);
        int left = b;
        if (len_ft < 9) {
            for (int i = 0; i < 9 - len_ft; i++) {
                *(*q) = '0';
                (*q)++;
            }
            left -= 9 - len_ft;
        }
        filling_str_float(q, &ptrt, left + 1);
    }
    return;
}

void float_minus_one(char **q, int a, int b, int k \
, int t, int fval_k, int fval_t, int len_ft, int sign \
, int flag_tocka, int flag_tochnost, int flag_plus \
, int flag_probel, int flag_shirina) {
    char temp[INT_STR_SIZE*2];
    if (flag_plus == 1 && sign == 1) {
        *(*q) = '+';
        (*q)++;
    }
    if (flag_probel == 1 && sign == 1) {
        *(*q) = ' ';
        (*q)++;
    }
    if (sign == -1) {
        *(*q) = '-';
        (*q)++;
    }
    const char *ptrt = itoa(temp, sizeof(temp), fval_k);
    filling_str(q, &ptrt, k);
    if (flag_tochnost == 1 && flag_tocka == 1) {
        float_minus_one_routine(q, b, t, fval_t, len_ft);
    }
    if (flag_tochnost == 0 && flag_tocka == 0) {
        float_tochnost_tocka(q, fval_t, len_ft);
    }
    if (flag_shirina == 1) {
        float_shirina(q, a, b, k, flag_plus, sign, flag_tocka);
    }
    return;
}

void float_minus_one_routine(char **q, int b, int t, int fval_t, int len_ft) {
    char temp[INT_STR_SIZE*2];
    *(*q) = '.';
    (*q)++;
    if (b > t) {
        const char *ptrt = itoa(temp, sizeof(temp), fval_t);
        if (len_ft < 9) {
            for (int i = 0; i < 9 - len_ft && i < b; i++) {
                *(*q) = '0';
                (*q)++;
            }
        }
        filling_str(q, &ptrt, t);
        for (int i = 0; i < b - t - 9 + len_ft; i++) {
            *(*q) = '0';
            (*q)++;
        }
    }
    if (b == t) {
        char *ptrt = itoa(temp, sizeof(temp), fval_t);
        if (len_ft < 9) {
            for (int i = 0; i < 9 - len_ft && i < b; i++) {
                *(*q) = '0';
                (*q)++;
            }
        }
        filling_str_float(q, &ptrt, b);
    }
    if (b < t) {
        char *ptrt = itoa(temp, sizeof(temp), fval_t);
        int left = b;
        if (len_ft < 9) {
            for (int i = 0; i < 9 - len_ft; i++) {
                *(*q) = '0';
                (*q)++;
            }
            left -= 9 - len_ft;
        }
        filling_str_float(q, &ptrt, left + 1);
    }
    return;
}

void float_shirina(char **q, int a, int b, int k, int flag_plus, int sign, int flag_tocka) {
    int digits_b = b;
    if (b == 0 && flag_tocka == 0) {
        digits_b = 7;
    }
    if (b !=0 && flag_tocka) {
        digits_b += 1;
    }
    if (a > k + digits_b) {
        for (int i = 0; i < a - k - digits_b - flag_plus - ((1 - flag_plus) * (1 - sign) / 2); i++) {
            *(*q) = ' ';
            (*q)++;
        }
    }
    return;
}

void float_tochnost_tocka(char **q, int fval_t, int len_ft) {
    *(*q) = '.';
    (*q)++;
    char temp[INT_STR_SIZE*2];
    char *ptrt = itoa(temp, sizeof(temp), fval_t);
    int left = 6;
    if (len_ft < 9) {
        for (int i = 0; i < 9 - len_ft; i++) {
            *(*q) = '0';
            (*q)++;
        }
        left -= 9 - len_ft;
    }
    filling_str_float(q, &ptrt, left + 1);
    return;
}

char* itoa(char* buff, int size, unsigned int val) {
    char *p;
    p = convert(buff, size, val, 10);
    return p;
}

