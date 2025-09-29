#include <asm.h>

.extern errno

// int gettime();
ENTRY(gettime)
    mov $10, %eax
    int $0x80
    cmp $0, %eax
    jge gettime_ok

    neg %eax
    mov %eax, errno
    mov -1, %eax
gettime_ok:
    ret

