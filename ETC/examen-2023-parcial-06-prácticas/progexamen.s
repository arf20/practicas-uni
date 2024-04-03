
	.data	
maxima_potencia:
        .word		0
str000:
	.asciiz		"El número ha de ser mayor que cero.\n"
str001:
	.asciiz		"Factorización de "
str002:
	.asciiz		":"
str003:
	.asciiz		"\nOperación inválida.\n"
str004:
	.asciiz		"\nSerie: "
str005:
	.asciiz		"\n\nExamen de ETC de ensamblador\n\n 1. Factorizar en potencias de 2\n 2. Generar serie numérica\n 0. Salir\n\nElige una opción: "
str006:
	.asciiz		"\n\n"
str007:
	.asciiz		"Introduce el número a factorizar: "
str008:
	.asciiz		"Introduce x0: "
str009:
	.asciiz		"Introduce n: "
str010:
	.asciiz		"Introduce y: "
str011:
	.asciiz		"Introduce la operación (+ o *): "
str012:
	.asciiz		"¡Adiós!\n"
str013:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"
	.text	
	j main
# EJERCICIO 1. TRADUCIR.
# Descompone un número pasado como parámetro en potencias de 2.
factorizar_potencia_2: # void factorizar_potencia_2([$a0] int n) {
        addiu $sp, $sp, -4	# push $ra
        sw $ra, ($sp)
        addiu $sp, $sp, -4	# push $s0
        sw $s0, ($sp)
        addiu $sp, $sp, -4	# push $s1
        sw $s1, ($sp)
        addiu $sp, $sp, -4	# push $s2
        sw $s2, ($sp)
        move $s0, $a0		# $s0 n
        lw $s1, maxima_potencia	# $s1 global maxima_potencia
        #   if (n <= 0) {
        bgtz $s0, fce
        #     print_string("El número ha de ser mayor que cero.\n");
        la $a0, str000
        jal print_string
        j fe
        #   }
fce:
	#   print_string("Factorización de ");
        la $a0, str001
        jal print_string
        #   print_integer(n);
        move $a0, $s0
        jal print_integer
        #   print_string(":");
        la $a0, str002
        jal print_string
        #   int potencia = 1;
        li $s2, 1		# $s2 potencia
        #   while (n > 0) {
fl:	blez $s0, fle
	#     if (n & 1) {
	and $t0, $s0, 1
	beqz $t0, fc2e
	#       print_character(' ');
	li $a0, ' '
	jal print_character
	#       print_integer(potencia);
	move $a0, $s2
	jal print_integer
	#       maxima_potencia = potencia;
	move $s1, $s2
	#     }
fc2e:
	#     potencia = potencia << 1;
	sll $s2, $s2, 1
	#     n = n >> 1;
	srl $s0, $s0, 1
        #   }
        j fl
fle:
	#   print_character('\n');
	li $a0, '\n'
	jal print_character
	# }
fe:
	lw $s2, ($sp)		# pop $s2
	addiu $sp, $sp, 4
	lw $s1, ($sp)		# pop $s1
	addiu $sp, $sp, 4
	lw $s0, ($sp)		# pop $s0
	addiu $sp, $sp, 4
	lw $ra, ($sp)		# pop $ra
	addiu $sp, $sp, 4
	jr $ra

# EJERCICIO 2. IMPLEMENTAR.
# Genera una serie numérica desde x_0 hasta x_n (ambos inclusive) donde
# x_n = x_n-1 OP Y. La función recibe x_0, n, Y y OP como parámetros 
# y se debe generar la secuencia tras comprobar que OP sea «+» o «*».
generar_serie:	# void generar_serie(int x0, int n, int y, char op) {
	addiu $sp, $sp, -4	# push $ra
        sw $ra, ($sp)
        addiu $sp, $sp, -4	# push $s0
        sw $s0, ($sp)
        addiu $sp, $sp, -4	# push $s1
        sw $s1, ($sp)
        addiu $sp, $sp, -4	# push $s2
        sw $s2, ($sp)
        addiu $sp, $sp, -4	# push $s3
        sw $s3, ($sp)
        addiu $sp, $sp, -4	# push $s4
        sw $s4, ($sp)
        addiu $sp, $sp, -4	# push $s5
        sw $s5, ($sp)
        
        move $s0, $a0		# $s0 xn_1 = x0
        move $s1, $a1		# $s1 n
        move $s2, $a2		# $s2 y
        move $s3, $a3		# $s3 op
        li $s4, 0		# $s4 xn
	#   if (op != '+' && op != '*')  {
	beq $s3, '+', gce
	beq $s3, '*', gce
	#     print_string("\nOperación inválida\n");
	la $a0, str003
	jal print_string
	#     return;
	j ge
	#   }
gce:
	#   print_string("\nSerie: ");
	la $a0, str004
	jal print_string
	#   print_integer(xn_1);
	move $a0, $s0
	jal print_integer
	#     print_character(' ');
	li $a0, ' '
	jal print_character
	#   for (int i = 0; i <= n; i++) {
	li $s5, 0
gl:	bgt $s5, $s1, gle
	#     if (op == '+') {
	bne $s3, '+', gc2el
	#       xn = xn_1 + y;
	add $s4, $s0, $s2
	#     } else {
gc2el:
	#       xn = xn_1 * y;
	mul $s4, $s0, $s2
	#     }
	#     print_integer(xn);
	move $a0, $s4
	jal print_integer
	#     print_character(' ');
	li $a0, ' '
	jal print_character
	#     xn_1 = xn;
	move $s0, $s4
	#   }
	add $s5, $s5, 1
	j gl
gle:
	# }
ge:
	lw $s5, ($sp)		# pop $s5
	addiu $sp, $sp, 4
	lw $s4, ($sp)		# pop $s4
	addiu $sp, $sp, 4
	lw $s3, ($sp)		# pop $s3
	addiu $sp, $sp, 4
	lw $s2, ($sp)		# pop $s2
	addiu $sp, $sp, 4
	lw $s1, ($sp)		# pop $s1
	addiu $sp, $sp, 4
	lw $s0, ($sp)		# pop $s0
	addiu $sp, $sp, 4
	lw $ra, ($sp)		# pop $ra
	addiu $sp, $sp, 4
	jr $ra
        

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
	la	$s0, str005
	la	$s1, str006
	lui	$s5, 12288
	la	$t1, str012
	sw	$t1, 36($sp)
	lui	$s6, 12800
	la	$t1, str008
	sw	$t1, 32($sp)
	la	$t1, str009
	sw	$t1, 28($sp)
	la	$t1, str010
	sw	$t1, 24($sp)
	la	$t1, str011
	sw	$t1, 20($sp)
	lui	$s3, 12544
	la	$s7, str007
	la	$fp, str013
	j	B2_2
B2_1:	lw	$a0, 32($sp)
	jal	print_string
	jal	read_integer
	lw	$a0, 28($sp)
	move	$s2, $v0
	jal	print_string
	jal	read_integer
	lw	$a0, 24($sp)
	move	$s3, $v0
	jal	print_string
	jal	read_integer
	lw	$a0, 20($sp)
	move	$s4, $v0
	jal	print_string
	jal	read_character
	sll	$a3, $v0, 24
	sra	$a3, $a3, 24
	move	$a0, $s2
	move	$a1, $s3
	lui	$s3, 12544
	move	$a2, $s4
	jal	generar_serie
B2_2:	move	$a0, $s0
	jal	print_string
	jal	read_character
	move	$s2, $v0
	move	$a0, $s1
	jal	print_string
	sll	$v0, $s2, 24
	beq	$v0, $s5, B2_6
	beq	$v0, $s6, B2_1
	bne	$v0, $s3, B2_7
	move	$a0, $s7
	jal	print_string
	jal	read_integer
	move	$a0, $v0
	jal	factorizar_potencia_2
	j	B2_2
B2_6:	lw	$a0, 36($sp)
	jal	print_string
	li	$a0, 0
	jal	mips_exit
	j	B2_2
B2_7:	move	$a0, $fp
	jal	print_string
	jal	read_character
	j	B2_2

print_integer:
	li	$v0, 1
	syscall	
	jr	$ra

read_integer:
	li	$v0, 5
	syscall	
	jr	$ra
	li	$v0, 8
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
	li	$v0, 30
	syscall	
	move	$v0, $a0
	move	$v1, $a1
	jr	$ra
	li	$v0, 32
	syscall	
	jr	$ra

read_character:
	li	$v0, 12
	syscall	
	jr	$ra

clear_screen:
	li	$v0, 39
	#syscall	
	jr	$ra

mips_exit:
	li	$v0, 17
	syscall	
	jr	$ra
	li	$v0, 41
	syscall	
	move	$v0, $a0
	jr	$ra
	li	$v0, 42
	syscall	
	move	$v0, $a0
	jr	$ra
	li	$v0, 0
	lb	$t0, 4294901760
	andi	$t0, $t0, 1
	beqz	$t0, keyio_poll_key_return
	lb	$v0, 4294901764
keyio_poll_key_return:
	jr	$ra
	move	$v0, $a0
memcpy_loop:
	beqz	$a2, memcpy_return
	lbu	$t0, 0($a1)
	sb	$t0, 0($a0)
	addiu	$a0, $a0, 1
	addiu	$a1, $a1, 1
	addiu	$a2, $a2, -1
	j	memcpy_loop
memcpy_return:
	jr	$ra
	move	$v0, $a0
memset_loop:
	beqz	$a2, memset_return
	sb	$a1, 0($a0)
	addiu	$a0, $a0, 1
	addiu	$a2, $a2, -1
	j	memset_loop
memset_return:
	jr	$ra
