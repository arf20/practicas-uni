# 0 "entry.S"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "entry.S"




# 1 "include/asm.h" 1
# 6 "entry.S" 2
# 1 "include/segment.h" 1
# 7 "entry.S" 2
# 1 "include/errno.h" 1




# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 6 "include/errno.h" 2
# 8 "entry.S" 2
# 74 "entry.S"
.globl keyboard_handler; .type keyboard_handler, @function; .align 0; keyboard_handler:
    pushl %gs; pushl %fs; pushl %es; pushl %ds; pushl %eax; pushl %ebp; pushl %edi; pushl %esi; pushl %ebx; pushl %ecx; pushl %edx; movl $0x18, %edx; movl %edx, %ds; movl %edx, %es;
    call keyboard_routine
    popl %edx; popl %ecx; popl %ebx; popl %esi; popl %edi; popl %ebp; popl %eax; popl %ds; popl %es; popl %fs; popl %gs;
    movb $0x20, %al ; outb %al, $0x20 ;
    iret

.globl clock_handler; .type clock_handler, @function; .align 0; clock_handler:
    pushl %gs; pushl %fs; pushl %es; pushl %ds; pushl %eax; pushl %ebp; pushl %edi; pushl %esi; pushl %ebx; pushl %ecx; pushl %edx; movl $0x18, %edx; movl %edx, %ds; movl %edx, %es;
    movb $0x20, %al ; outb %al, $0x20 ;
    call clock_routine
    popl %edx; popl %ecx; popl %ebx; popl %esi; popl %edi; popl %ebp; popl %eax; popl %ds; popl %es; popl %fs; popl %gs;
    iret



.globl syscall_handler; .type syscall_handler, @function; .align 0; syscall_handler:
    pushl %gs; pushl %fs; pushl %es; pushl %ds; pushl %eax; pushl %ebp; pushl %edi; pushl %esi; pushl %ebx; pushl %ecx; pushl %edx; movl $0x18, %edx; movl %edx, %ds; movl %edx, %es;
    cmpl $0, %eax
    jl err
    cmpl $10, %eax
    jg err
    call *sys_call_table(, %eax, 0x04)
    jmp fin
err:
    movl $-38, %eax
fin:
    movl %eax, 0x18(%esp)
    popl %edx; popl %ecx; popl %ebx; popl %esi; popl %edi; popl %ebp; popl %eax; popl %ds; popl %es; popl %fs; popl %gs;
    iret
