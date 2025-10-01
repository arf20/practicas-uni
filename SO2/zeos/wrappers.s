# 0 "wrappers.S"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "wrappers.S"
# 1 "include/asm.h" 1
# 2 "wrappers.S" 2

.extern errno





    mov 20(%esp), %ebp
    mov 16(%esp), %edi
    mov 12(%esp), %esi
    mov 8(%esp), %ebx
    mov 4(%esp), %ecx
    mov 0(%esp), %edx

    int $0x80

    cmp $0, %eax
    jge syscall_ok

    neg %eax
    mov %eax, errno
    mov -1, %eax
    ret


.globl gettime; .type gettime, @function; .align 0; gettime: mov 10, %eax

.globl write; .type write, @function; .align 0; write: mov 4, %eax

syscall_ok:
    ret
