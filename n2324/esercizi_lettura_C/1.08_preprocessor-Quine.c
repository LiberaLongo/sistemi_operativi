#define Q(x)char*s=#x;x
Q(int printf(const char *format, ...);int main(){printf("#define Q(x)char*s=#x;x\nQ(%s)\n",s);})

