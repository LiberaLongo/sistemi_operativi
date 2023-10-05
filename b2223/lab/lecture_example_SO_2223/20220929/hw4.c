long mywrite(int fd, const char *s, unsigned long count) {
  long addr = (long) s;
  register long r_syscallno asm("rax") = 1;
  register long r_arg1 asm("rdi") = fd;
  register long r_arg2 asm("rsi") = addr;
  register long r_arg3 asm("rdx") = count;
  register long r_retvalue asm("rax");
  asm("syscall");
  return r_retvalue;
}

int main(int argc, char *argv[]) {
	mywrite(1, "hello world\n", 12);
}
