#include <asm.h>

.extern errno

#define SYSCALL(name, num) \
ENTRY(name) \
    mov     $num, %eax;      \
                            \
    mov     24(%esp), %ebp; \
    mov     20(%esp), %edi; \
    mov     16(%esp), %esi; \
    mov     12(%esp), %ebx;  \
    mov     8(%esp), %ecx;  \
    mov     4(%esp), %edx;  \
                            \
    int     $0x80;          \
                            \
    cmp     $0, %eax;       \
    jge     syscall_ok;     \
                            \
    neg     %eax;           \
    mov     %eax, errno;    \
    mov     $-1, %eax;      \
    ret

// int gettime();
SYSCALL(gettime, 10)
// int write(int fd, const void buf, size_t count)
SYSCALL(write, 4)

syscall_ok:
    ret

