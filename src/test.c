#include <check.h>
#include "s21_string.h"

START_TEST(strlen_check) {
fail_unless(strlen("222") == s21_strlen("222"));
fail_unless(strlen("") == s21_strlen(""));
fail_unless(strlen("fje3 \0") == s21_strlen("fje3 \0"));
fail_unless(strlen("\0") == s21_strlen("\0"));
fail_unless(strlen("...") == s21_strlen("..."));
}
END_TEST

START_TEST(memchr_check) {
const char str[20] = "website\0";
fail_unless(memchr(str, 'i', 5) == s21_memchr(str, 'i', 5));
fail_unless(memchr(str, 'i', 3) == s21_memchr(str, 'i', 3));
fail_unless(memchr(str, 'a', 8) == s21_memchr(str, 'a', 8));
fail_unless(memchr(str, '0', 15) == s21_memchr(str, '0', 15));
const char str1[20] = "5465754..@";
fail_unless(memchr(str1, '5', 5) == s21_memchr(str1, '5', 5));
fail_unless(memchr(str1, '6', 3) == s21_memchr(str1, '6', 3));
fail_unless(memchr(str1, '.', 8) == s21_memchr(str1, '.', 8));
fail_unless(memchr(str1, '@', 15) == s21_memchr(str1, '@', 15));
fail_unless(memchr(str1, '\0', 15) == s21_memchr(str1, '\0', 15));
}
END_TEST

START_TEST(memcmp_check) {
unsigned char src[15]="1234567890";
unsigned char dst[15]="1234567890";
fail_unless(memcmp(src, dst, 10) == s21_memcmp(src, dst, 10));
unsigned char src_2[15]="5678901234";
unsigned char dst_2[15]="1234567890";
fail_unless(memcmp(src_2, dst_2, 10) == s21_memcmp(src_2, dst_2, 10));
fail_unless(memcmp(dst_2, src_2, 10) == s21_memcmp(dst_2, src_2, 10));
unsigned char src_3[15]="mgdfgjkdf";
unsigned char dst_3[15]="MGDFGJKDF";
fail_unless(memcmp(src_3, dst_3, 10) == s21_memcmp(src_3, dst_3, 10));
fail_unless(memcmp(dst_3, src_3, 10) == s21_memcmp(dst_3, src_3, 10));
unsigned char src_4[15]="";
unsigned char dst_4[15]="MGDFGJKDF";
fail_unless(memcmp(src_4, dst_4, 10) == s21_memcmp(src_4, dst_4, 10));
fail_unless(memcmp(dst_4, src_4, 10) == s21_memcmp(dst_4, src_4, 10));
unsigned char src_5[15]="";
unsigned char dst_5[15]="";
fail_unless(memcmp(src_5, dst_5, 10) == s21_memcmp(src_5, dst_5, 10));
fail_unless(memcmp(dst_5, src_5, 10) == s21_memcmp(dst_5, src_5, 10));
fail_unless(memcmp(dst_5, src_5, 0) == s21_memcmp(dst_5, src_5, 0));
}
END_TEST

START_TEST(memcpy_check) {
char str1[10] = "string";
char str2[40], str4[40] = "", str5[40] = "", str6[40], str7[40];
char str3[40];
memcpy(str2, str1, 6);
s21_memcpy(str3, str1, 6);
fail_unless(strcmp(str2, str3) == 0);
memcpy(str4, str1, 0);
s21_memcpy(str5, str1, 0);
fail_unless(strcmp(str4, str5) == 0);
memcpy(str6, str1, 1);
s21_memcpy(str7, str1, 1);
str6[1] = '\0';
str7[1] = '\0';
fail_unless(strcmp(str6, str7) == 0);
char str8[] = "";
memcpy(str2, str8, 1);
s21_memcpy(str3, str8, 6);
fail_unless(strcmp(str2, str3) == 0);
}
END_TEST

START_TEST(memmove_check) {
char str[] = "1234567890";
char str_2[] = "1234567890";
memmove(str + 4, str + 3, 3);
s21_memmove(str_2 + 4, str_2 + 3, 3);
fail_unless(strcmp(str, str_2) == 0);
memmove(str + 1, str + 3, 3);
s21_memmove(str_2 + 1, str_2 + 3, 3);
fail_unless(strcmp(str, str_2) == 0);
memmove(str + 1, str + 3, 0);
s21_memmove(str_2 + 1, str_2 + 3, 0);
fail_unless(strcmp(str, str_2) == 0);
memmove(str + 4, str + 3, 3);
s21_memmove(str_2 + 4, str_2 + 3, 3);
fail_unless(strcmp(str, str_2) == 0);
memmove(str + 1, str + 3, 3);
s21_memmove(str_2 + 1, str_2 + 3, 3);
fail_unless(strcmp(str, str_2) == 0);
memmove(str + 1, str + 3, 0);
s21_memmove(str_2 + 1, str_2 + 3, 0);
fail_unless(strcmp(str, str_2) == 0);
}
END_TEST

START_TEST(memset_check) {
char str[] = "string";
char str_2[] = "string";
s21_memset(str, '*', 3);
memset(str_2, '*', 3);
fail_unless(strcmp(str, str_2) == 0);
int i = 0;
s21_memset(str, '-', 0);
memset(str_2, '-', i);
fail_unless(strcmp(str, str_2) == 0);
s21_memset(str, '-', 6);
memset(str_2, '-', 6);
fail_unless(strcmp(str, str_2) == 0);
s21_memset(str, '\0', 6);
memset(str_2, '\0', 6);
fail_unless(strcmp(str, str_2) == 0);
}
END_TEST

START_TEST(strcat_check) {
char str[30] = "string";
char str_2[] = "strong";
char str_3[30] = "string";
char str_4[20] = "";
char str_5[20] = "";
s21_strcat(str, str_2);
strcat(str_3, str_2);
fail_unless(strcmp(str, str_3) == 0);
s21_strcat(str, str_4);
strcat(str_3, str_4);
fail_unless(strcmp(str, str_3) == 0);
s21_strcat(str_4, str);
strcat(str_5, str);
fail_unless(strcmp(str_4, str_5) == 0);
char str6[160] = "rjefre er ferf JJHJIJ";
char str_7[] = "ferfHGVYGFUYGIJ";
char str_8[160] = "rjefre er ferf JJHJIJ";
char str_9[120] = "";
char str_10[120] = "";
s21_strcat(str6, str_7);
strcat(str_8, str_7);
fail_unless(strcmp(str6, str_8) == 0);
s21_strcat(str6, str_9);
strcat(str_8, str_9);
fail_unless(strcmp(str6, str_8) == 0);
s21_strcat(str_9, str6);
strcat(str_10, str6);
fail_unless(strcmp(str_9, str_10) == 0);
}
END_TEST

START_TEST(strcmp_check) {
char str[30] = "string";
char str_2[] = "strong";
fail_unless(strcmp(str, str_2) == s21_strcmp(str, str_2));
fail_unless(strcmp(str_2, str) == s21_strcmp(str_2, str));
char str2[30] = "string";
char str_3[] = "";
fail_unless(strcmp(str2, str_3) == s21_strcmp(str2, str_3));
fail_unless(strcmp(str_3, str2) == s21_strcmp(str_3, str2));
char str3[30] = "";
char str_4[] = "";
fail_unless(strcmp(str3, str_4) == s21_strcmp(str3, str_4));
}
END_TEST

START_TEST(strncat_check) {
char src1[10]="000";
char src2[10]="000";
char app[10]="12345";
strncat(src1, app, 3);
s21_strncat(src2, app, 3);
fail_unless(strcmp(src1, src2) == 0);
char src_1[10]="000";
char src_2[10]="000";
strncat(src_1, app, 7);
s21_strncat(src_2, app, 7);
fail_unless(strcmp(src_1, src_2) == 0);
strncat(src_1, app, 0);
s21_strncat(src_2, app, 0);
fail_unless(strcmp(src_1, src_2) == 0);
char src3[10]="";
char src4[10]="";
char app2[10]="12345";
strncat(src3, app2, 3);
s21_strncat(src4, app2, 3);
fail_unless(strcmp(src3, src4) == 0);
char src5[10]="12345";
char src6[10]="12345";
char app3[10]="";
strncat(src5, app3, 3);
s21_strncat(src6, app3, 3);
fail_unless(strcmp(src5, src6) == 0);
}
END_TEST

START_TEST(strchr_check) {
char str[30] = "string";
fail_unless(strchr(str, 's') == s21_strchr(str, 's'));
fail_unless(strchr(str, 'i') == s21_strchr(str, 'i'));
fail_unless(strchr(str, 'm') == s21_strchr(str, 'm'));
fail_unless(strchr(str, 'a') == s21_strchr(str, 'a'));
fail_unless(strchr(str, '\0') == s21_strchr(str, '\0'));
}
END_TEST

START_TEST(strncmp_check) {
char str[30] = "string";
char str_2[] = "strong";
char str_3[30] = "string";
fail_unless(strncmp(str, str_2, 2) == 0 && s21_strncmp(str, str_2, 2) == 0);
fail_unless(strncmp(str_2, str, 4) > 0 && s21_strncmp(str_2, str, 4) > 0);
fail_unless(strncmp(str, str_3, 20) == 0 && s21_strncmp(str, str_3, 20) == 0);
fail_unless(strncmp(str, str_2, 0) == 0 && s21_strncmp(str, str_2, 0) == 0);
char str_4[15] = "";
char str_5[30] = "";
fail_unless(strncmp(str_4, str_5, 10) == 0 && s21_strncmp(str_4, str_5, 10) == 0);
}
END_TEST

START_TEST(strpbrk_check) {
char str[30] = "string";
char str_2[] = "ar";
fail_unless(strpbrk(str, str_2) == s21_strpbrk(str, str_2));
char str_3[] = "ajk";
fail_unless(strpbrk(str, str_3) == s21_strpbrk(str, str_3));
char str_4[] = "mg";
fail_unless(strpbrk(str, str_4) == s21_strpbrk(str, str_4));
char str_5[] = "";
fail_unless(strpbrk(str, str_5) == s21_strpbrk(str, str_5));
fail_unless(strpbrk(str_5, str) == s21_strpbrk(str_5, str));
}
END_TEST

START_TEST(strcpy_check) {
char str1[] = "string";
char str2[40];
char str3[40];
strcpy(str2, str1);
s21_strcpy(str3, str1);
fail_unless(strcmp(str2, str3) == 0);
strcpy(str1, str2);
s21_strcpy(str2, str1);
fail_unless(strcmp(str2, str1) == 0);
char str4[] = "\0";
strcpy(str2, str4);
s21_strcpy(str3, str4);
fail_unless(strcmp(str2, str3) == 0);
char str5[] = "";
char str6[40];
char str7[40];
strcpy(str6, str5);
s21_strcpy(str7, str5);
fail_unless(strcmp(str6, str7) == 0);
}
END_TEST

START_TEST(strncpy_check) {
char str1[] = "string";
char str2[40];
char str3[40];
char str4[40], str5[40], str6[40];
strncpy(str2, str1, 5);
s21_strncpy(str3, str1, 5);
fail_unless(strcmp(str2, str3) == 0);
s21_strncpy(str4, str1, 30);
strncpy(str5, str1, 30);
fail_unless(strcmp(str4, str5) == 0);
int i = 0;
fail_unless(strncpy(str6, str1, i) == s21_strncpy(str6, str1, 0));
char str7[] = "";
strncpy(str2, str7, 5);
s21_strncpy(str3, str7, 5);
fail_unless(strcmp(str2, str3) == 0);
}
END_TEST

START_TEST(strcspn_check) {
char str[30] = "string";
char str_2[] = "ar";
fail_unless(strcspn(str, str_2) == s21_strcspn(str, str_2));
char str_3[] = "ajk";
fail_unless(strcspn(str, str_3) == s21_strcspn(str, str_3));
char str_4[] = "mg";
fail_unless(strcspn(str, str_4) == s21_strcspn(str, str_4));
char str_5[] = "";
fail_unless(strcspn(str, str_5) == s21_strcspn(str, str_5));
fail_unless(strcspn(str_5, str) == s21_strcspn(str_5, str));
}
END_TEST

START_TEST(strrchr_check) {
char str[30] = "string";
fail_unless(strrchr(str, 's') == s21_strrchr(str, 's'));
fail_unless(strrchr(str, 'i') == s21_strrchr(str, 'i'));
fail_unless(strrchr(str, 'm') == s21_strrchr(str, 'm'));
char str2[30] = "56445905";
fail_unless(strrchr(str2, '4') == s21_strrchr(str2, '4'));
fail_unless(strrchr(str2, '0') == s21_strrchr(str2, '0'));
fail_unless(strrchr(str2, '5') == s21_strrchr(str2, '5'));
fail_unless(strrchr(str2, '\0') == s21_strrchr(str2, '\0'));
}
END_TEST

START_TEST(strspn_check) {
char str[30] = "string";
char str_2[] = "ar";
fail_unless(strspn(str, str_2) == s21_strspn(str, str_2));
char str_3[] = "ajk";
fail_unless(strspn(str, str_3) == s21_strspn(str, str_3));
char str_4[] = "mg";
fail_unless(strspn(str, str_4) == s21_strspn(str, str_4));
char str_5[] = "string";
fail_unless(strspn(str, str_5) == s21_strspn(str, str_5));
char str_6[] = "strong";
fail_unless(strspn(str, str_6) == s21_strspn(str, str_6));
char str_7[] = "";
fail_unless(strspn(str, str_7) == s21_strspn(str, str_7));
}
END_TEST

START_TEST(strstr_check) {
char str[30] = "Leyzersonson";
fail_unless(strstr(str, "son") == s21_strstr(str, "son"));
fail_unless(strstr(str, "zer") == s21_strstr(str, "zer"));
fail_unless(strstr(str, "fon") == s21_strstr(str, "fon"));
fail_unless(strstr(str, "") == s21_strstr(str, ""));
fail_unless(strstr(str, "nson") == s21_strstr(str, "nson"));
char str2[30] = "";
fail_unless(strstr(str2, "nson") == s21_strstr(str2, "nson"));
}
END_TEST

START_TEST(strtok_check) {
char str[24]="test1/test2,test3.test4";
char sep[10]="/,.";
fail_unless(strtok(str, sep) == s21_strtok(str, sep));
char str_2[24]="test2,test3.test4";
fail_unless(strtok(str_2, sep) == s21_strtok(str_2, sep));
char str_3[24]="test3.test4";
fail_unless(strtok(str_3, sep) == s21_strtok(str_3, sep));
char str_4[25] = "test4";
fail_unless(strtok(str_4, sep) == s21_strtok(str_4, sep));
char dep[10] = "";
char str_5[25] = "test6";
fail_unless(strtok(str_5, dep) == s21_strtok(str_5, dep));
char str_6[25] = "";
fail_unless(strtok(str_6, sep) == s21_strtok(str_6, sep));
fail_unless(strtok(str_6, str_5) == s21_strtok(str_6, str_5));
char str_7[11]="//////////";
fail_unless(strtok(str_7, sep) == s21_strtok(str_7, sep));
char str_8[1]="";
fail_unless(strtok(str_8, sep) == s21_strtok(str_8, sep));
char *str_9 = s21_NULL;
fail_unless(strtok(str_9, sep) == s21_strtok(str_9, sep));
}
END_TEST

START_TEST(strerror_check) {
char *d = s21_strerror(50);
char *m = strerror(50);
fail_unless(strcmp(d, m) == 0);
d = s21_strerror(100);
m = strerror(100);
fail_unless(strcmp(d, m) == 0);
d = s21_strerror(13);
m = strerror(13);
fail_unless(strcmp(d, m) == 0);
m = strerror(40);
d = s21_strerror(40);
fail_unless(strcmp(d, m) == 0);
m = strerror(-1);
d = s21_strerror(-1);
fail_unless(strcmp(d, m) == 0);
m = strerror(200);
d = s21_strerror(200);
fail_unless(strcmp(d, m) == 0);
}
END_TEST

START_TEST(sprintf_c_check) {
char str[5100];
char str2[5100];
sprintf(str, "%11c %c", 'A', 'b');
s21_sprintf(str2, "%11c %c", 'A', 'b');
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%c %97c", 'n', 'j');
s21_sprintf(str2, "%c %97c", 'n', 'j');
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-c %-3c", 'j', 'z');
s21_sprintf(str2, "%-c %-3c", 'j', 'z');
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
s21_sprintf(str2, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%c", 'A');
s21_sprintf(str2, "%c", 'A');
fail_unless(strcmp(str, str2) == 0);
}
END_TEST

START_TEST(sprintf_s_check) {
char str[100];
char str2[100];
sprintf(str, "%s", "abcde");
s21_sprintf(str2, "%s", "abcde");
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%.1s", "abcde");
s21_sprintf(str2, "%.1s", "abcde");
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%.20s", "abcde");
s21_sprintf(str2, "%.20s", "abcde");
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%10s", "abcde");
s21_sprintf(str2, "%10s", "abcde");
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-10s", "abcde");
s21_sprintf(str2, "%-10s", "abcde");
fail_unless(strcmp(str, str2) == 0);
}
END_TEST

START_TEST(sprintf_u_check) {
char str[100];
char str2[100];
sprintf(str, "%u", (unsigned int)4);
s21_sprintf(str2, "%u", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2u", (unsigned int)4);
s21_sprintf(str2, "%2u", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.5u", (unsigned int)4);
s21_sprintf(str2, "%2.5u", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-u", (unsigned int)6);
s21_sprintf(str2, "%-u", 6);
fail_unless(strcmp(str, str2) == 0);
}
END_TEST

START_TEST(sprintf_d_check) {
char str[100];
char str2[100];
sprintf(str, "%d", 4);
s21_sprintf(str2, "%d", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%d", -4);
s21_sprintf(str2, "%d", -4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-10.3d", 4);
s21_sprintf(str2, "%-10.3d", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-10.3d", -4);
s21_sprintf(str2, "%-10.3d", -4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-3.10d", 4);
s21_sprintf(str2, "%-3.10d", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-3.10d", -4);
s21_sprintf(str2, "%-3.10d", -4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+2.2d", 4000000);
s21_sprintf(str2, "%+2.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+2.2d", -4000000);
s21_sprintf(str2, "%+2.2d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+.2d", 4000000);
s21_sprintf(str2, "%+.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+2.d", 4000000);
s21_sprintf(str2, "%+2.d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+.2d", -4000000);
s21_sprintf(str2, "%+.2d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%15.15d", 4000000);
s21_sprintf(str2, "%15.15d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%16.15d", -4000000);
s21_sprintf(str2, "%16.15d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%15.15d", -4000000);
s21_sprintf(str2, "%15.15d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%12.2d", -4000000);
s21_sprintf(str2, "%12.2d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%12.2d", 4000000);
s21_sprintf(str2, "%12.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.12d", 4000000);
s21_sprintf(str2, "%2.12d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.12d", -4000000);
s21_sprintf(str2, "%2.12d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.2d", 4000000);
s21_sprintf(str2, "%2.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.2d", -4000000);
s21_sprintf(str2, "%2.2d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+2.2d", 4000000);
s21_sprintf(str2, "%+2.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+2.2d", -4000000);
s21_sprintf(str2, "%+2.2d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%d%%\n", 4000000);
s21_sprintf(str2, "%d%%\n", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%.2d", 4000000);
s21_sprintf(str2, "%.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-2.2d", 4000000);
s21_sprintf(str2, "%+-2.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-2.2d", -4000000);
s21_sprintf(str2, "%+-2.2d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-15.15d", 4000000);
s21_sprintf(str2, "%-15.15d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-15.15d", -4000000);
s21_sprintf(str2, "%-15.15d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-12.2d", -4000000);
s21_sprintf(str2, "%-12.2d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-12.2d", 4000000);
s21_sprintf(str2, "%-12.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-2.12d", 4000000);
s21_sprintf(str2, "%-2.12d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-2.12d", -4000000);
s21_sprintf(str2, "%-2.12d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-2.2d", 4000000);
s21_sprintf(str2, "%+-2.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-2.2d", 4000000);
s21_sprintf(str2, "%+-2.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-d%%\n", 4000000);
s21_sprintf(str2, "%-d%%\n", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-.2d", 4000000);
s21_sprintf(str2, "%-.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-2d", 4000000);
s21_sprintf(str2, "%-2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-10d", 4000000);
s21_sprintf(str2, "%-10d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-2d", 4000000);
s21_sprintf(str2, "%+-2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-10d", 4000000);
s21_sprintf(str2, "%+-10d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%11.10d", 4000000);
s21_sprintf(str2, "%11.10d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "% 2.2d", 4000000);
s21_sprintf(str2, "% 2.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%.15d", -4000000);
s21_sprintf(str2, "%.15d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%.15d", 4000000);
s21_sprintf(str2, "%.15d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+.15d", 4000000);
s21_sprintf(str2, "%+.15d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+.15d", -4000000);
s21_sprintf(str2, "%+.15d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%15.2d", 4000000);
s21_sprintf(str2, "%15.2d", 4000000);
sprintf(str, "%+15.2d", 4000000);
s21_sprintf(str2, "%+15.2d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+15.2d", -4000000);
s21_sprintf(str2, "%+15.2d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%15.8d", -4000000);
s21_sprintf(str2, "%15.8d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-.8d", -4000000);
s21_sprintf(str2, "%-.8d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+.8d", 4000000);
s21_sprintf(str2, "%+.8d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-.8d", 4000000);
s21_sprintf(str2, "%+-.8d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-11d", -4000000);
s21_sprintf(str2, "%+-11d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-5d", -4000000);
s21_sprintf(str2, "%+-5d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-10.8d", -4000000);
s21_sprintf(str2, "%+-10.8d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-10.8d", 4000000);
s21_sprintf(str2, "%+-10.8d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-10.8d", -4000000);
s21_sprintf(str2, "%+-10.8d", -4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+13.10d", -4000000);
s21_sprintf(str2, "%+13.10d", -4000000);
ck_assert_str_eq(str, str2);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-11.11d", 4000000);
s21_sprintf(str2, "%+-11.11d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-5.11d", 4000000);
s21_sprintf(str2, "%+-5.11d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-9.7d", 4000000);
s21_sprintf(str2, "%+-9.7d", 4000000);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%u", (unsigned int)-4000000);
s21_sprintf(str2, "%u", -4000000);
ck_assert_str_eq(str, str2);
fail_unless(strcmp(str, str2) == 0);
}
END_TEST

START_TEST(sprintf_f_check) {
char str[100];
char str2[100];
sprintf(str, "%.2f", 4000.1);
s21_sprintf(str2, "%.2f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%.2f", -4000.1);
s21_sprintf(str2, "%.2f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%f", 4000.1);
s21_sprintf(str2, "%f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%f", -4000.1);
s21_sprintf(str2, "%f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2f", -4000.1);
s21_sprintf(str2, "%2f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2f", 4000.1);
s21_sprintf(str2, "%2f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "% 2f", 4000.1);
s21_sprintf(str2, "% 2f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%- 2f", 4000.1);
s21_sprintf(str2, "%- 2f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%.0f", 4000.6);
s21_sprintf(str2, "%.0f", 4000.6);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%0f", 4000.1);
s21_sprintf(str2, "%0f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%0f", -4000.1);
s21_sprintf(str2, "%0f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+f %+f", 4000.1, 30.9);
s21_sprintf(str2, "%+f %+f", 4000.1, 30.9);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-15f", 4000.1);
s21_sprintf(str2, "%-15f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+15f", 4000.1);
s21_sprintf(str2, "%+15f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-15f", -4000.1);
s21_sprintf(str2, "%-15f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+15f", -4000.1);
s21_sprintf(str2, "%+15f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-15f", 4000.1);
s21_sprintf(str2, "%+-15f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-15f", -4000.1);
s21_sprintf(str2, "%+-15f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.2f", 4.);
s21_sprintf(str2, "%2.2f", 4.);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.2f", -4.);
s21_sprintf(str2, "%2.2f", -4.);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%10.10f", -4.);
s21_sprintf(str2, "%10.10f", -4.);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%8.2f", 4000.1);
s21_sprintf(str2, "%8.2f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%8.2f", -4000.1);
s21_sprintf(str2, "%8.2f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.8f", 4000.1);
s21_sprintf(str2, "%2.8f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.8f", 4000.1);
s21_sprintf(str2, "%2.8f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%2.8f", -4000.1);
s21_sprintf(str2, "%2.8f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%8.8f", -4000.1);
s21_sprintf(str2, "%8.8f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%8.8f", 4000.1);
s21_sprintf(str2, "%8.8f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-2.2f", 4.);
s21_sprintf(str2, "%-2.2f", 4.);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-10.10f", 4.);
s21_sprintf(str2, "%-10.10f", 4.);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-2.2f", -4.);
s21_sprintf(str2, "%-2.2f", -4.);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-8.2f", 4000.1);
s21_sprintf(str2, "%-8.2f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-8.2f", -4000.1);
s21_sprintf(str2, "%-8.2f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-2.8f", 4000.1);
s21_sprintf(str2, "%-2.8f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-2.8f", 4000.1);
s21_sprintf(str2, "%-2.8f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-2.8f", -4000.1);
s21_sprintf(str2, "%-2.8f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-8.8f", -4000.1);
s21_sprintf(str2, "%-8.8f", -4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-8.8f", 4000.1);
s21_sprintf(str2, "%-8.8f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%9.0f", 4000.1);
s21_sprintf(str2, "%9.0f", 4000.1);
fail_unless(strcmp(str, str2) == 0);
}
END_TEST

START_TEST(sprintf_i_check) {
char str[100];
char str2[100];
sprintf(str, "%i", 4);
s21_sprintf(str2, "%i", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%10i", 4);
s21_sprintf(str2, "%10i", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%+-10i", 4);
s21_sprintf(str2, "%-+10i", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%-10i", 4);
s21_sprintf(str2, "%-10i", 4);
fail_unless(strcmp(str, str2) == 0);
}
END_TEST

START_TEST(sprintf_lhidu_check) {
char str[100];
char str2[100];
long int s = 4;
sprintf(str, "%ld", s);
s21_sprintf(str2, "%ld", s);
fail_unless(strcmp(str, str2) == 0);
long unsigned f = 10;
sprintf(str, "%lu", f);
s21_sprintf(str2, "%lu", f);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%hd", (short int)4);
s21_sprintf(str2, "%hd", 4);
fail_unless(strcmp(str, str2) == 0);
sprintf(str, "%hd", (short int)4);
s21_sprintf(str2, "%hd", 4);
fail_unless(strcmp(str, str2) == 0);
}
END_TEST

int main(void) {
Suite *s1 = suite_create("Core");
TCase *tc1_1 = tcase_create("Core");
SRunner *sr = srunner_create(s1);
int nf;

suite_add_tcase(s1, tc1_1);
tcase_add_test(tc1_1, strlen_check);
tcase_add_test(tc1_1, memchr_check);
tcase_add_test(tc1_1, memcmp_check);
tcase_add_test(tc1_1, memcpy_check);
tcase_add_test(tc1_1, memmove_check);
tcase_add_test(tc1_1, memset_check);
tcase_add_test(tc1_1, strcat_check);
tcase_add_test(tc1_1, strcmp_check);
tcase_add_test(tc1_1, strncat_check);
tcase_add_test(tc1_1, strchr_check);
tcase_add_test(tc1_1, strncmp_check);
tcase_add_test(tc1_1, strpbrk_check);
tcase_add_test(tc1_1, strcpy_check);
tcase_add_test(tc1_1, strncpy_check);
tcase_add_test(tc1_1, strcspn_check);
tcase_add_test(tc1_1, strrchr_check);
tcase_add_test(tc1_1, strspn_check);
tcase_add_test(tc1_1, strstr_check);
tcase_add_test(tc1_1, strtok_check);
tcase_add_test(tc1_1, strerror_check);
tcase_add_test(tc1_1, sprintf_c_check);
tcase_add_test(tc1_1, sprintf_s_check);
tcase_add_test(tc1_1, sprintf_u_check);
tcase_add_test(tc1_1, sprintf_d_check);
tcase_add_test(tc1_1, sprintf_f_check);
tcase_add_test(tc1_1, sprintf_i_check);
tcase_add_test(tc1_1, sprintf_lhidu_check);

srunner_run_all(sr, CK_ENV);
nf = srunner_ntests_failed(sr);
srunner_free(sr);
return nf == 0 ? 0 : 1;
}

