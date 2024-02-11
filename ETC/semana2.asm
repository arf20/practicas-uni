	.data
intro:	.asciiz	"Introduce numero entre 0 y 31> "
error:	.asciiz "Numero fuera de rango\n "
ok:	.asciiz "Numero dentro de rango\n"
	.text
	.globl main
main:
	li $v0, 4
	la $a0, intro
	syscall
	
	li $v0, 5
	syscall
	
	bltz $v0, outbounds
	bgt $v0, 31, outbounds
	
	li $v0, 4
	la $a0, ok
	syscall
	
	li $v0, 10
	syscall
	
outbounds:
	li $v0, 4
	la $a0, error
	syscall
	
	j main
	