
	.data	
	.align	2
conjunto:
	.space	40
	.align	2
tam_conjunto:
	.word	0
	.align	2
total_primos:
	.word	0
str000:
	.asciiz		"Error: Posición inválida\n"
str001:
	.asciiz		" es primo.\n"
str002:
	.asciiz		"\n\nExamen Parcial de ETC de ensamblador\n\n 1. Ordena conjunto\n 2. Cuenta primos\n 0. Salir\n\nElige una opción: "
str003:
	.asciiz		"\n\n"
str004:
	.asciiz		"El conjunto de elementos a ordenar es:\n"
str005:
	.asciiz		", "
str006:
	.asciiz		"El resultado de la ordenación es:\n"
str007:
	.asciiz		"Límite inferior de búsqueda de primos: "
str008:
	.asciiz		"Límite superior de búsqueda de primos: "
str009:
	.asciiz		"Número total de primos encontrados: "
str010:
	.asciiz		"¡Adiós!\n"
str011:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"

	.text	

leer_elemento:
	addiu	$sp, $sp, -24
	sw	$ra, 20($sp)
	bltz	$a0, B0_3
	lw	$t1, tam_conjunto
	slt	$t1, $a0, $t1
	beqz	$t1, B0_3
	sll	$t1, $a0, 2
	la	$v0, conjunto
	addu	$t1, $v0, $t1
	lw	$v0, 0($t1)
	lw	$ra, 20($sp)
	addiu	$sp, $sp, 24
	jr	$ra
B0_3:	la	$a0, str000
	jal	print_string
	li	$a0, 1
	jal	mips_exit

escribir_elemento:
	addiu	$sp, $sp, -24
	sw	$ra, 20($sp)
	sltiu	$t1, $a0, 10
	beqz	$t1, B1_4
	sll	$t1, $a0, 2
	la	$v0, conjunto
	addu	$t1, $v0, $t1
	sw	$a1, 0($t1)
	lw	$t1, tam_conjunto
	slt	$t1, $a0, $t1
	bnez	$t1, B1_3
	addiu	$t1, $a0, 1
	sw	$t1, tam_conjunto
B1_3:	lw	$ra, 20($sp)
	addiu	$sp, $sp, 24
	jr	$ra
B1_4:	la	$a0, str000
	jal	print_string
	li	$a0, 1
	jal	mips_exit

es_primo:
	slti	$t1, $a0, 2
	li	$v0, 0
	bnez	$t1, B2_9
	li	$t1, 2
	li	$v0, 1
	beq	$a0, $t1, B2_9
	andi	$t1, $a0, 1
	li	$v0, 0
	beqz	$t1, B2_9
	li	$t1, 3
	slt	$v0, $t1, $a0
	slti	$t1, $a0, 4
	bnez	$t1, B2_8
	lui	$t1, 21845
	ori	$t1, $t1, 21846
	mult	$a0, $t1
	mfhi	$t1
	srl	$v1, $t1, 31
	addu	$t1, $t1, $v1
	sll	$v1, $t1, 1
	addu	$t1, $v1, $t1
	subu	$t1, $a0, $t1
	beqz	$t1, B2_8
	li	$v1, 5
B2_6:	slt	$v0, $v1, $a0
	beqz	$v0, B2_8
	div	$zero, $a0, $v1
	teq	$v1, $zero
	mfhi	$t1
	addiu	$v1, $v1, 2
	bnez	$t1, B2_6
B2_8:	xori	$v0, $v0, 1
B2_9:	jr	$ra



# EJERCICIO 1. TRADUCIR.
# Ordena un conjunto de números enteros.
ordenar:	# no tiene parámetros ni devuelve datos
	lw $t9, tam_conjunto
	sub $t9, $t9, 1	# t9 tam_conjunto - 1

	ld $t0, 0	# t0 i
ol1:	bge $t0, $t9, ol1e

	ld $t1, 0	# t1 j
ol2:	sub $t2, $t9, $t0	# t2 tam_conjunto - i - 1
	bge $t1, $t2, ol2e
	
	jal leer_elemento

ol2e:

ol1e:
	break



# EJERCICIO 2. IMPLEMENTAR
# Muestra los primos entre a y b y los cuenta en la variable global «total_primos».
# Usa la función «es_primo» ya implementada.
mostrar_y_contar_primos:	# $a0 es a y $a1 es b
	# POR HACER
	break




	.globl	main
main:
	addiu	$sp, $sp, -80
	sw	$ra, 76($sp)
	sw	$fp, 72($sp)
	sw	$s7, 68($sp)
	sw	$s6, 64($sp)
	sw	$s5, 60($sp)
	sw	$s4, 56($sp)
	sw	$s3, 52($sp)
	sw	$s2, 48($sp)
	sw	$s1, 44($sp)
	sw	$s0, 40($sp)
	jal	clear_screen
	la	$s0, str002
	la	$s1, str003
	lui	$s4, 12544
	la	$t1, str004
	sw	$t1, 36($sp)
	la	$s3, str005
	la	$t1, str006
	sw	$t1, 32($sp)
	la	$t1, str007
	sw	$t1, 28($sp)
	la	$t1, str008
	sw	$t1, 24($sp)
	la	$t1, str009
	sw	$t1, 20($sp)
	la	$fp, str011
	j	B5_2
B5_1:	lw	$a0, 28($sp)
	jal	print_string
	jal	read_integer
	lw	$a0, 24($sp)
	move	$s2, $v0
	jal	print_string
	jal	read_integer
	move	$a1, $v0
	sw	$zero, total_primos
	move	$a0, $s2
	jal	mostrar_y_contar_primos
	lw	$a0, 20($sp)
	jal	print_string
	lw	$a0, total_primos
	jal	print_integer
	li	$a0, 10
	jal	print_character
B5_2:	move	$a0, $s0
	jal	print_string
	jal	read_character
	move	$s2, $v0
	move	$a0, $s1
	jal	print_string
	sll	$v0, $s2, 24
	beq	$v0, $s4, B5_6
	lui	$t1, 12800
	beq	$v0, $t1, B5_1
	lui	$t1, 12288
	beq	$v0, $t1, B5_17
	move	$a0, $fp
	jal	print_string
	jal	read_character
	j	B5_2
B5_6:	li	$a0, 0
	li	$a1, 7
	jal	escribir_elemento
	li	$a0, 1
	li	$a1, 1
	jal	escribir_elemento
	li	$a0, 2
	li	$a1, 10
	jal	escribir_elemento
	li	$a0, 3
	li	$a1, 2
	jal	escribir_elemento
	li	$a0, 4
	li	$a1, 9
	jal	escribir_elemento
	li	$a0, 5
	li	$a1, 8
	jal	escribir_elemento
	li	$a0, 6
	li	$a1, 5
	jal	escribir_elemento
	li	$a0, 7
	li	$a1, 6
	jal	escribir_elemento
	li	$a0, 8
	li	$a1, 3
	jal	escribir_elemento
	li	$a0, 9
	li	$a1, 4
	jal	escribir_elemento
	lw	$a0, 36($sp)
	jal	print_string
	li	$a0, 123
	jal	print_character
	lw	$t1, tam_conjunto
	blez	$t1, B5_11
	li	$s2, 0
	j	B5_9
B5_8:	lw	$t1, tam_conjunto
	addiu	$s2, $s2, 1
	slt	$t1, $s2, $t1
	beqz	$t1, B5_11
B5_9:	move	$a0, $s2
	jal	leer_elemento
	move	$a0, $v0
	jal	print_integer
	lw	$t1, tam_conjunto
	addiu	$t1, $t1, -1
	slt	$t1, $s2, $t1
	beqz	$t1, B5_8
	move	$a0, $s3
	jal	print_string
	j	B5_8
B5_11:	li	$a0, 125
	jal	print_character
	li	$a0, 10
	jal	print_character
	jal	ordenar
	li	$a0, 10
	jal	print_character
	lw	$a0, 32($sp)
	jal	print_string
	li	$a0, 123
	jal	print_character
	lw	$t1, tam_conjunto
	blez	$t1, B5_16
	li	$s2, 0
	j	B5_14
B5_13:	lw	$t1, tam_conjunto
	addiu	$s2, $s2, 1
	slt	$t1, $s2, $t1
	beqz	$t1, B5_16
B5_14:	move	$a0, $s2
	jal	leer_elemento
	move	$a0, $v0
	jal	print_integer
	lw	$t1, tam_conjunto
	addiu	$t1, $t1, -1
	slt	$t1, $s2, $t1
	beqz	$t1, B5_13
	la	$a0, str005
	jal	print_string
	j	B5_13
B5_16:	li	$a0, 125
	jal	print_character
	li	$a0, 10
	jal	print_character
	j	B5_2
B5_17:	la	$a0, str010
	jal	print_string
	li	$a0, 0
	jal	mips_exit

print_integer:
	li	$v0, 1
	syscall	
	jr	$ra

read_integer:
	li	$v0, 5
	syscall	
	jr	$ra

print_character:
	li	$v0, 11
	syscall	
	jr	$ra

print_string:
	li	$v0, 4
	syscall	
	jr	$ra

read_character:
	li	$v0, 12
	syscall	
	jr	$ra

clear_screen:
	li	$v0, 39
	syscall	
	jr	$ra

mips_exit:
	li	$v0, 17
	syscall	
	jr	$ra
