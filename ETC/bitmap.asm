	.data
	
	.text
	.globl main
main:	
	la $v0, 0x10010000
	move $t0, $v0
	li $t1, 0
	
loop:	beq $t0, 0x10110000, end
	li $v0, 41
	syscall
	sw $a0, ($t0)
	add $t0, $t0, 4
	j loop
	
end:	move $t0, $v0
	j loop

	li $v0, 10
	syscall