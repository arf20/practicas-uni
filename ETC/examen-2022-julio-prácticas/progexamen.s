
	.data	
	.align	2
jump_table000:
	.word	B9_1
	.word	B9_4
	.word	B9_6
	.word	B9_9
	.align	2
montanas:
	.asciiz		"Dhaulagiri\0\0\0\0\0\0\0"
	.space	2
	.word	8167
	.asciiz		"Cho Oyu\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	8188
	.asciiz		"Lhotse\0\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	8516
	.asciiz		"Makalu\0\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	8485
	.asciiz		"Annapurna\0\0\0\0\0\0\0\0"
	.space	2
	.word	8091
	.asciiz		"Nanga Parbat\0\0\0\0\0"
	.space	2
	.word	8126
	.asciiz		"K2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	8611
	.asciiz		"Everest\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	8848
	.asciiz		"Manaslu\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	8163
	.asciiz		"Kangchenjunga\0\0\0\0"
	.space	2
	.word	8586
	.space	240
	.align	2
nmontanas:
	.word	10
	.align	2
almacen:
	.asciiz		"Manzana\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	10
	.word	100
	.asciiz		"Pera\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	8
	.word	100
	.asciiz		"Sandía\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	50
	.word	17
	.asciiz		"Plátano\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	7
	.word	88
	.asciiz		"Fresa\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	11
	.word	124
	.asciiz		"Cereza\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	10
	.word	175
	.asciiz		"Melocotón\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	13
	.word	75
	.space	3348
	.align	2
nproductos:
	.word	7
	.align	2
__const.main.tests:
	.word	3
	.asciiz		"Manzana\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	4
	.asciiz		"Pera\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	5
	.asciiz		"Sandía\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	1
	.space	3104
	.word	2
	.asciiz		"Fresa\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	25
	.asciiz		"Cereza\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	20
	.space	3136
	.word	4
	.asciiz		"Plátano\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	3
	.asciiz		"Coco\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	20
	.asciiz		"Manzana\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	5
	.asciiz		"Melocotón\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	3
	.word	2
	.space	3072
	.align	2
__const.main.tests.16:
	.word	100
	.word	15
	.word	1000
str000:
	.asciiz		" es más alta que "
str001:
	.asciiz		"Producto: "
str002:
	.asciiz		"  Precio: "
str003:
	.asciiz		"  Stock: "
str004:
	.asciiz		"Aviso: producto no encontrado: "
str005:
	.asciiz		"Cantidad: "
str006:
	.asciiz		"  Producto: "
str007:
	.asciiz		"Desconocido"
str008:
	.asciiz		"\n\nExamen de ETC de ensamblador\n\n 1. Buscar la montaña más alta\n 2. Calcular precio de pedidos\n 3. Calcular coste y crear pedido para llenar el almacén\n 0. Salir\n\nElige una opción: "
str009:
	.asciiz		"\n\n"
str010:
	.asciiz		"Buscando la montaña más alta...\n"
str011:
	.asciiz		"La montaña más alta es: "
str012:
	.asciiz		"Productos en el almacén:\n"
str013:
	.asciiz		"Pedido "
str014:
	.asciiz		":\n"
str015:
	.asciiz		"Precio total: "
str016:
	.asciiz		"El coste para tener al menos "
str017:
	.asciiz		" items de cada producto en el almacén es: "
str018:
	.asciiz		"Hay que pedir los siguientes productos:\n"
str019:
	.asciiz		"¡Adiós!\n"
str020:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"

	.text	
	j main
	
# EJERCICIO 1
buscar_montana_mas_alta:
	addiu	$sp, $sp, -20	# -- restar
	sw	$ra, 16($sp)
	sw	$s3, 12($sp)	# -- guardar $s3
	sw	$s2, 8($sp)	# -- guardar $s2
	sw	$s1, 4($sp)
	sw	$s0, 0($sp)
	
	lw	$s1, nmontanas	# $s1 = nmontanas
	blez	$s1, B0_6
	la	$s0, montanas   # $s0 = candidata = &montanas[0];
	# for (int i = 1;
        li      $s2, 1          # $s2 = i
B0_1:   bge     $s2, $s1, B0_7	# i < nmontanas
	# dentro del for
        lw      $t0, 20($s0)	# $t0 = candidata->altura
        mul     $t1, $s2, 24	# -- tamaño 24
        la      $t2, montanas
        addu    $s3, $t1, $t2   # $s3 = &montanas[i]
        lw      $t1, 20($s3)	# -- $t1 = montanas[i].altura está en off 20
        bge     $t0, $t1, B0_2	# if candidata->altura < montanas[i].altura
        move    $a0, $s3	
        jal     print_string	# print montanas[i].nombre
        la      $a0, str000
        jal     print_string	# print nosequemierdas
        move    $a0, $s0
        jal     print_string	# print candidata.nombre
        li      $a0, '\n'
        jal     print_character	# print '\n'
        move    $s0, $s3	# candidata = &montanas[i]
        # } final del for
B0_2:   addiu   $s2, $s2, 1	# i++
        j       B0_1
        
B0_6:	li	$s0, 0          # candidata = NULL
B0_7:	move	$v0, $s0	# return candidata;

	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)	# -- desapilar $s2
	lw	$s3, 12($sp)	# -- desapilar $s3
	lw	$ra, 16($sp)
	addiu	$sp, $sp, 20	# -- sumar
	jr	$ra

comparar_cadenas:
	lbu	$v0, 0($a0)
	beqz	$v0, B1_5
	addiu	$v1, $a0, 1
B1_2:	lbu	$a0, 0($a1)
	beqz	$a0, B1_5
	andi	$t1, $v0, 255
	bne	$a0, $t1, B1_5
	addiu	$t1, $v1, 1
	lbu	$v0, 0($v1)
	addiu	$a1, $a1, 1
	move	$v1, $t1
	bnez	$v0, B1_2
B1_5:	lbu	$t1, 0($a1)
	andi	$v0, $v0, 255
	xor	$t1, $v0, $t1
	sltiu	$v0, $t1, 1
	jr	$ra

copiar_cadena:
	slti	$t1, $a2, 2
	li	$v0, 0
	bnez	$t1, B2_4
	addiu	$v1, $a2, -1
	li	$v0, 0
B2_2:	addu	$t1, $a1, $v0
	lbu	$a2, 0($t1)
	beqz	$a2, B2_4
	addu	$t1, $a0, $v0
	addiu	$v0, $v0, 1
	sb	$a2, 0($t1)
	bne	$v1, $v0, B2_2
B2_4:	addu	$t1, $a0, $v0
	sb	$zero, 0($t1)
	move	$v0, $a0
	jr	$ra

listar_almacen:
	addiu	$sp, $sp, -48
	sw	$ra, 44($sp)
	sw	$s5, 40($sp)
	sw	$s4, 36($sp)
	sw	$s3, 32($sp)
	sw	$s2, 28($sp)
	sw	$s1, 24($sp)
	sw	$s0, 20($sp)
	lw	$t1, nproductos
	blez	$t1, B3_3
	la	$s0, almacen
	li	$s5, 0
	la	$s1, str001
	la	$s2, str002
	la	$s3, str003
B3_2:	move	$a0, $s1
	jal	print_string
	move	$a0, $s0
	jal	print_string
	move	$a0, $s2
	jal	print_string
	lw	$a0, 28($s0)
	jal	print_integer
	move	$a0, $s3
	jal	print_string
	lw	$a0, 32($s0)
	jal	print_integer
	li	$a0, 10
	jal	print_character
	addiu	$s5, $s5, 1
	lw	$t1, nproductos
	slt	$t1, $s5, $t1
	addiu	$s0, $s0, 36
	bnez	$t1, B3_2
B3_3:	lw	$s0, 20($sp)
	lw	$s1, 24($sp)
	lw	$s2, 28($sp)
	lw	$s3, 32($sp)
	lw	$s4, 36($sp)
	lw	$s5, 40($sp)
	lw	$ra, 44($sp)
	addiu	$sp, $sp, 48
	jr	$ra

# EJERCICIO 2a
	#ProductoAlmacen* buscar_producto(char* nombre) {
buscar_producto:
	# $a0 = nombre
	addiu 	$sp, $sp, -24
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s3, 16($sp)
	sw	$s4, 20($sp)
	
	move 	$s0, $a0	# $s0 = nombre
	lw	$s1, nproductos	# $s1 = nproductos
	la	$s2, almacen	# $s2 = almacen
	
	#  for (int i = 0; i < nproductos; ++i) {
	li	$s3, 0		# $s3 = i = 0
b_for:	bge	$s3, $s1, b_for_end
	#    if (comparar_cadenas(almacen[i].nombre, nombre)) {
	mul	$t0, $s3, 36	# $t0 = 36 * i
	add	$s4, $t0, $s2	# $s4 = almacen[i].nombre
	move	$a0, $s4	# $a0 = almacen[i].nombre
	move	$a1, $s0	# $a1 = nombre
	jal	comparar_cadenas
	beqz	$v0, b_if_end
	#      return &almacen[i];
	move	$v0, $s4	# $v0 = $a1 = almacen[i].nombre ; lo de antes
	j	b_end
	#    }
b_if_end:
	#  }
	addi	$s3, $s3, 1	# i++
	j	b_for
b_for_end:
	#  return NULL; // NULL representa un puntero que apunta a la dirección 0
	li	$v0, 0
	#}
b_end:
	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	lw	$s3, 16($sp)
	lw	$s4, 20($sp)
	addiu 	$sp, $sp, 24
	
	jr	$ra

# EJERCICIO 2b
#int calcular_precio_pedido(Pedido* pedido) {
calcular_precio_pedido:
	addiu 	$sp, $sp, -24
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s3, 16($sp)
	sw	$s4, 20($sp)
	
	move	$s0, $a0	# $s0 = pedido
#  int total = 0;
	li	$s1, 0		# $s1 = total = 0
#  for (int i = 0; i < pedido->num_items; ++i) {
	li	$s2, 0		# $s2 = i
	lw	$s3, 0($s0)	# $s3 = pedido->num_items
c_for:	bge	$s2, $s3, c_for_end	# i >= pedido->num_items : j c_for_end
#    ProductoAlmacen* producto = buscar_producto(pedido->items[i].nombre_item);
	mul	$t0, $s2, 32	# $t0 = 32 * i
	addiu	$t0, $t0, 4	# $t0 = 4 + $t0;   
	addu	$s4, $s0, $t0	# $s4 = &pedido->items[i].nombre_item
	lw	$a0, ($s4)	# $a0 = pedido->items[i].nombre_item = *$t1
	jal	buscar_producto	# $v0 = producto
#    if (producto != NULL) {
	beqz	$v0, c_else
#      total = total + producto->precio * pedido->items[i].cantidad;
	addiu	$t0, $s4, 28	# $t0 = $s4 + 28 = &pedido->items[i].cantidad
	lw	$t1, ($t0)	# $t1 = pedido->items[i].cantidad = *$t0
	addiu	$v0, $v0, 28	# $v0 = $v0 + 28 = &producto->precio
	lw	$t2, ($v0)	# $t2 = producto->precio = *$v0
	mul	$t3, $t2, $t1	# $t3 = $t2 * $t1 = producto->precio * pedido->items[i].cantidad;
	add	$s1, $s1, $t3	# total = $s1 = $s1 + $t3 = total + producto->precio * pedido->items[i].cantidad;
	j	c_else_end
#    } else {
c_else:
#      print_string("Aviso: producto no encontrado: " );
	la	$a0, str004
	jal	print_string
#      print_string(pedido->items[i].nombre_item);
	move	$a0, $s4
	jal	print_string
#      print_character('\n');
	li	$a0, '\n'
	jal	print_character
#    }
c_else_end:
#  }
	addiu	$s2, $s2, 1
	j	c_for
c_for_end:
#  return total;
	move	$v0, $s1
#}
	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	lw	$s3, 16($sp)
	lw	$s4, 20($sp)
	addiu 	$sp, $sp, 24
	
	jr	$ra

listar_pedido:
	addiu	$sp, $sp, -56
	sw	$ra, 52($sp)
	sw	$s7, 48($sp)
	sw	$s6, 44($sp)
	sw	$s5, 40($sp)
	sw	$s4, 36($sp)
	sw	$s3, 32($sp)
	sw	$s2, 28($sp)
	sw	$s1, 24($sp)
	sw	$s0, 20($sp)
	lw	$t1, 0($a0)
	blez	$t1, B6_6
	move	$s0, $a0
	addiu	$s6, $a0, 32
	li	$s7, 0
	la	$s1, str005
	la	$s2, str006
	la	$s3, str002
	la	$s4, str007
	j	B6_4
B6_2:	move	$a0, $s4
	jal	print_string
B6_3:	li	$a0, 10
	jal	print_character
	addiu	$s7, $s7, 1
	lw	$t1, 0($s0)
	slt	$t1, $s7, $t1
	addiu	$s6, $s6, 32
	beqz	$t1, B6_6
B6_4:	move	$a0, $s1
	jal	print_string
	lw	$a0, 0($s6)
	jal	print_integer
	move	$a0, $s2
	jal	print_string
	addiu	$s5, $s6, -28
	move	$a0, $s5
	jal	print_string
	move	$a0, $s3
	jal	print_string
	move	$a0, $s5
	jal	buscar_producto
	beqz	$v0, B6_2
	lw	$a0, 28($v0)
	jal	print_integer
	j	B6_3
B6_6:	lw	$s0, 20($sp)
	lw	$s1, 24($sp)
	lw	$s2, 28($sp)
	lw	$s3, 32($sp)
	lw	$s4, 36($sp)
	lw	$s5, 40($sp)
	lw	$s6, 44($sp)
	lw	$s7, 48($sp)
	lw	$ra, 52($sp)
	addiu	$sp, $sp, 56
	jr	$ra

anadir_producto_a_pedido:
	addiu	$sp, $sp, -32
	sw	$ra, 28($sp)
	sw	$s2, 24($sp)
	sw	$s1, 20($sp)
	sw	$s0, 16($sp)
	move	$s0, $a2
	move	$s1, $a0
	addiu	$s2, $a0, 4
	lw	$t1, 0($a0)
	sll	$t1, $t1, 5
	addu	$a0, $s2, $t1
	li	$a2, 25
	jal	copiar_cadena
	lw	$t1, 0($s1)
	sll	$v0, $t1, 5
	addu	$v0, $s2, $v0
	sw	$s0, 28($v0)
	addiu	$t1, $t1, 1
	sw	$t1, 0($s1)
	lw	$s0, 16($sp)
	lw	$s1, 20($sp)
	lw	$s2, 24($sp)
	lw	$ra, 28($sp)
	addiu	$sp, $sp, 32
	jr	$ra

# EJERCICIO 3
crear_pedido_llenar_almacen_y_calcular_coste:
        # POR HACER
        break

	.globl	main
main:
	addiu	$sp, $sp, -9728
	sw	$ra, 9724($sp)
	sw	$fp, 9720($sp)
	sw	$s7, 9716($sp)
	sw	$s6, 9712($sp)
	sw	$s5, 9708($sp)
	sw	$s4, 9704($sp)
	sw	$s3, 9700($sp)
	sw	$s2, 9696($sp)
	sw	$s1, 9692($sp)
	sw	$s0, 9688($sp)
	jal	clear_screen
	la	$t1, str008
	sw	$t1, 68($sp)
	la	$t1, str009
	sw	$t1, 64($sp)
	la	$t1, str020
	sw	$t1, 60($sp)
	la	$t1, str019
	sw	$t1, 56($sp)
	la	$t1, str010
	sw	$t1, 52($sp)
	la	$t1, str011
	sw	$t1, 48($sp)
	la	$t1, str012
	sw	$t1, 44($sp)
	la	$t1, __const.main.tests
	sw	$t1, 40($sp)
	addiu	$s1, $sp, 72
	la	$t1, str013
	sw	$t1, 36($sp)
	la	$t1, str014
	sw	$t1, 20($sp)
	la	$s5, str015
	la	$s4, str016
	la	$s6, __const.main.tests.16
	la	$fp, str017
	la	$s7, str018
	sw	$s4, 32($sp)
	sw	$s6, 28($sp)
	sw	$fp, 24($sp)
	j	B9_2
B9_1:	lw	$a0, 56($sp)
	jal	print_string
	li	$a0, 0
	jal	mips_exit
B9_2:	lw	$a0, 68($sp)
	jal	print_string
	jal	read_character
	lw	$a0, 64($sp)
	move	$s0, $v0
	jal	print_string
	andi	$t1, $s0, 255
	addiu	$v0, $t1, -48
	sltiu	$t1, $v0, 4
	beqz	$t1, B9_5
	sll	$t1, $v0, 2
	lw	$t1, jump_table000($t1)
	jr	$t1
B9_4:	lw	$a0, 52($sp)
	jal	print_string
	jal	buscar_montana_mas_alta
	lw	$a0, 48($sp)
	move	$s0, $v0
	jal	print_string
	move	$a0, $s0
	jal	print_string
	j	B9_2
B9_5:	lw	$a0, 60($sp)
	jal	print_string
	jal	read_character
	j	B9_2
B9_6:	lw	$a0, 44($sp)
	jal	print_string
	jal	listar_almacen
	li	$a0, 10
	jal	print_character
	move	$a0, $s1
	lw	$a1, 40($sp)
	li	$a2, 9612
	jal	memcpy
	li	$s0, 0
	move	$fp, $s1
	lw	$s3, 20($sp)
	li	$s6, 3
	lw	$s4, 36($sp)
B9_7:	move	$a0, $s4
	jal	print_string
	move	$a0, $s0
	jal	print_integer
	move	$a0, $s3
	jal	print_string
	move	$a0, $fp
	jal	listar_pedido
	move	$a0, $fp
	jal	calcular_precio_pedido
	move	$s2, $v0
	move	$a0, $s5
	jal	print_string
	move	$a0, $s2
	jal	print_integer
	li	$a0, 10
	jal	print_character
	li	$a0, 10
	jal	print_character
	addiu	$s0, $s0, 1
	addiu	$fp, $fp, 3204
	bne	$s0, $s6, B9_7
	lw	$s4, 32($sp)
	lw	$s6, 28($sp)
	j	B9_2
B9_9:	la	$a0, str012
	jal	print_string
	jal	listar_almacen
	li	$a0, 10
	jal	print_character
	li	$s2, 0
	lw	$fp, 24($sp)
	li	$s3, 12
B9_10:	move	$a0, $s1
	li	$a1, 0
	li	$a2, 3204
	jal	memset
	move	$a0, $s4
	jal	print_string
	addu	$t1, $s6, $s2
	lw	$s0, 0($t1)
	move	$a0, $s0
	jal	print_integer
	move	$a0, $fp
	jal	print_string
	move	$a0, $s0
	move	$a1, $s1
	jal	crear_pedido_llenar_almacen_y_calcular_coste
	move	$a0, $v0
	jal	print_integer
	li	$a0, 10
	jal	print_character
	move	$a0, $s7
	jal	print_string
	move	$a0, $s1
	jal	listar_pedido
	li	$a0, 10
	jal	print_character
	addiu	$s2, $s2, 4
	bne	$s2, $s3, B9_10
	j	B9_2

print_integer:
	li	$v0, 1
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
	#li	$v0, 39
	#syscall	
	jr	$ra

mips_exit:
	li	$v0, 17
	syscall	
	jr	$ra

memcpy:
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

memset:
	move	$v0, $a0
memset_loop:
	beqz	$a2, memset_return
	sb	$a1, 0($a0)
	addiu	$a0, $a0, 1
	addiu	$a2, $a2, -1
	j	memset_loop
memset_return:
	jr	$ra

