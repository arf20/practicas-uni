# 0 "wrappers.S"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "wrappers.S"
# 1 "include/asm.h" 1
# 2 "wrappers.S" 2

.extern errno


.globl gettime; .type gettime, @function; .align 0; gettime:
    mov $10, %eax
    int $0x80
    cmp $0, %eax
    jge syscall_ok

    neg %eax
    mov %eax, errno
    mov -1, %eax
    ret


.globl write; .type write, @function; .align 0; write:
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
