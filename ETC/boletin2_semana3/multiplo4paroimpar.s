	.data
nmulmsg:.asciiz "No es multiplo de 4\n"
mulmsg:	.asciiz "Es multiplo de 4\n"
evmsg:	.asciiz "El cociente /4 es par: "
nevmsg:	.asciiz "El cociente /4 es impar: "

	.text
	.globl main
main:
	# leer entero a $v0
	li $v0, 5
	syscall
	move $v1, $v0
	
	# comprobar si es multiplo de 4 ($v0 AND 0b11 == 0)
	and $t0, $v1, 3
	# saltar si es 0
	beqz $t0, ismult
	# si no es multiplo imprimir
	li $v0, 4
	la $a0, nmulmsg
	syscall
	# terminar
	li $v0, 10
	syscall
	
ismult:
	# si es multiplo imprimir
	li $v0, 4
	la $a0, mulmsg
	syscall
	# calcular cociente
	div $t0, $v1, 4
	# comprobar si cociente es par
	and $t1, $t0, 1
	beqz $t1, qisev
	# si no es par, imprimir
	li $v0, 4
	la $a0, nevmsg
	syscall
	li $v0, 1
	move $a0, $t0
	syscall
	# terminar
	li $v0, 10
	syscall
	
qisev:	
	# si es par, imprimir
	li $v0, 4
	la $a0, evmsg
	syscall
	li $v0, 1
	move $a0, $t0
	syscall
	# terminar
	li $v0, 10
	syscall
	