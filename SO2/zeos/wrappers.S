#include <asm.h>

.extern errno

// int gettime();
ENTRY(gettime)
    mov $10, %eax
    int $0x80
    cmp $0, %eax
    jge syscall_ok

    neg %eax
    mov %eax, errno
    mov -1, %eax
    ret

// int write(int fd, const void buf, size_t count)
ENTRY(write)
    mov $4, %eax
    mov -12(%esp), %edx
    mov -8(%esp), %ecx
    mov -4(%esp), %ebx
    int $0x80

    cmp $0, %eax
    jge syscall_ok

    neg %eax
    mov %eax, errno
    mov -1, %eax
    ret

syscall_ok:
    ret

