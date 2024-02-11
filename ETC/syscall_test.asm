	.data
msg1:	.asciiz "Introduce un numero> "
msg2:	.asciiz "El numero es: "

	.text
	.globl main
main:
	# print msg1
	li $v0, 4
	la $a0, msg1
	syscall
	# get number
	li $v0, 5
	syscall
	move $t0, $v0
	# print msg2
	li $v0, 4
	la $a0, msg2
	syscall
	# print number
	li $v0, 1
	move $a0, $t0
	syscall
	
	li $v0, 56
	la $a0, msg2
	move $a1, $t0
	syscall
	
	# exit
	li $v0, 10
	syscall
	