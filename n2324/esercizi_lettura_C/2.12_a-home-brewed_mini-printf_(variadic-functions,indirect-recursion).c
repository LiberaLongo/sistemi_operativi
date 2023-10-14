#include <stdio.h>
#include <stdarg.h>
 
int vrprintf(const char *format, va_list ap);
 
static int putcx(int c) {
    if (c!=0) {
        putchar(c);
        return 1;
    } else
        return 0;
}
 
static char backchar[128] = {
        [0 ... 127] = 0,
        ['a'] = '\a',
        ['b'] = '\b',
        ['f'] = '\f',
        ['n'] = '\n',
        ['r'] = '\r',
        ['t'] = '\t',
        ['v'] = '\v',
        ['\\'] = '\\', 
        ['\''] = '\'', 
        ['"'] = '"',
        ['?'] = '?',
};
 
static int put_backslash(char escapeChar) {
    return putcx(backchar[escapeChar & 0x7f]);
}
 
static int rvrp_int(int val) {
    if (val == 0)
        return 0;
    else  
        return rvrp_int(val / 10) + putcx('0' + val % 10);
}
 
static int vrp_int(int val) {
    if (val != 0) {
        if (val < 0)
            return putcx('-') + rvrp_int(-val);
        else
            return rvrp_int(val);
    } else
        return putcx('0');
}
 
static int vrp_string(char *s) {
    switch (*s) {
        case 0:
            return 0;
        case '\\':
            
            return put_backslash(*(s+1)) ? vrp_string(s + 2) + 1 : 0;
        default:
            return putcx(*s) + vrp_string(s + 1);
    }
}
 
static int vrp_percent(const char *format, va_list ap) {
    switch (*format) {
        case 0:
            return 0;
        case '%':
            return putcx(*format) + vrprintf(format + 1, ap);
        case 'd':
            return vrp_int(va_arg(ap, int)) + vrprintf(format + 1, ap);
        case 's':
            return vrp_string(va_arg(ap, char *)) + vrprintf(format + 1, ap);;
        default:
            printf("ERROR\n");
            return 0;
    }
}
 
int vrprintf(const char *format, va_list ap) {
    switch (*format) {
        case 0:
            return 0;
        case '%':
            return vrp_percent(format + 1, ap);
        case '\\':
            return put_backslash(*(format+1)) ? vrprintf(format + 2, ap) + 1 : 0;
        default:
            return putcx(*format) + vrprintf(format + 1, ap);
    }
}
 

int rprintf(const char *format, ...) {
    int rval;
    va_list ap;
    va_start (ap, format);
    rval = vrprintf(format, ap);
    va_end(ap);
    return rval;
}
 
int main() {
    int v;
    v = rprintf("hello world\n");
    printf("%d\n", v);
    v = printf("hello world\n");
    printf("%d\n", v);
    v = rprintf("hello world %d\n", 10);
    printf("%d\n", v);
    v = printf("hello world %d\n", 10);
    printf("%d\n", v);
    v = rprintf("hello world %s %d\n", "piripicchio", 42);
    printf("%d\n", v);
    v = printf("hello world %s %d\n", "piripicchio", 42);
    printf("%d\n", v);
    v = rprintf("hello world %% \"%s\" %d\n", "piripicchio\tbackslash", 42);
    printf("%d\n", v);
    v = printf("hello world %% \"%s\" %d\n", "piripicchio\tbackslash", 42);
    printf("%d\n", v);
    v = rprintf("%%\n");
    printf("%d\n", v);
    v = printf("%%\n");
    printf("%d\n", v);
}

