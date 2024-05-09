# Examen de ETC de ensamblador

	.data	
	.align	2
jump_table000:
	.word	B11_1
	.word	B11_4
	.word	B11_12
	.word	B11_18
	.align	2
pacientes:
	.word	7
	.asciiz		"Zorka Setare Kuhn\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	1956
	.word	8
	.word	6
	.word	162
	.byte	77
	.space	3
	.word	6
	.asciiz		"Elin Konstantin Silva\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	1967
	.word	11
	.word	1
	.word	168
	.byte	77
	.space	3
	.word	3
	.asciiz		"Robert Susanoo Van Bokhoven\0\0\0\0\0\0\0"
	.space	1
	.word	1987
	.word	2
	.word	16
	.word	172
	.byte	72
	.space	3
	.word	8
	.asciiz		"Astraia Agostino Saari\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	1995
	.word	1
	.word	24
	.word	187
	.byte	77
	.space	3
	.word	2
	.asciiz		"Farouk Akmad Bridges\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	1978
	.word	3
	.word	17
	.word	180
	.byte	72
	.space	3
	.space	900
	.align	2
num_pacientes:
	.word	5
	.align	2
consultas:
	.word	6
	.word	2015
	.word	4
	.word	5
	.asciiz		"Resfriado."
	.space	139
	.space	2
	.word	8
	.word	2015
	.word	6
	.word	18
	.asciiz		"Bronquiolitis."
	.space	135
	.space	2
	.word	2
	.word	2015
	.word	7
	.word	3
	.asciiz		"Faringitis."
	.space	138
	.space	2
	.word	6
	.word	2015
	.word	7
	.word	9
	.asciiz		"Otitis."
	.space	142
	.space	2
	.word	7
	.word	2015
	.word	10
	.word	4
	.asciiz		"Pierna izquierda rota."
	.space	127
	.space	2
	.word	3
	.word	2015
	.word	11
	.word	15
	.asciiz		"Dolor de muelas."
	.space	133
	.space	2
	.word	2
	.word	2015
	.word	1
	.word	17
	.asciiz		"Astigmatismo."
	.space	136
	.space	2
	.word	2
	.word	2015
	.word	4
	.word	12
	.asciiz		"Conjuntivitis."
	.space	135
	.space	2
	.word	6
	.word	2015
	.word	4
	.word	16
	.asciiz		"Miopía."
	.space	141
	.space	2
	.word	2
	.word	2015
	.word	5
	.word	15
	.asciiz		"Lipotimia."
	.space	139
	.space	2
	.word	8
	.word	2016
	.word	6
	.word	26
	.asciiz		"Rubéola."
	.space	140
	.space	2
	.word	7
	.word	2016
	.word	9
	.word	26
	.asciiz		"Gripe."
	.space	143
	.space	2
	.word	7
	.word	2016
	.word	9
	.word	30
	.asciiz		"Hipocondria."
	.space	137
	.space	2
	.word	3
	.word	2016
	.word	10
	.word	24
	.asciiz		"Sinusitis."
	.space	139
	.space	2
	.word	3
	.word	2016
	.word	1
	.word	14
	.asciiz		"Dolor de garganta."
	.space	131
	.space	2
	.word	2
	.word	2016
	.word	3
	.word	15
	.asciiz		"Gota."
	.space	144
	.space	2
	.word	2
	.word	2016
	.word	3
	.word	23
	.asciiz		"Lepra."
	.space	143
	.space	2
	.word	3
	.word	2016
	.word	3
	.word	26
	.asciiz		"Gastroenteritis."
	.space	133
	.space	2
	.word	3
	.word	2016
	.word	4
	.word	13
	.asciiz		"Bronquitis."
	.space	138
	.space	2
	.word	7
	.word	2016
	.word	6
	.word	7
	.asciiz		"Pierna derecha rota."
	.space	129
	.space	2
	.space	13440
	.align	2
num_consultas:
	.word	20
str000:
	.asciiz		"ID: "
str001:
	.asciiz		", Nombre: "
str002:
	.asciiz		", Fecha nacimiento: "
str003:
	.asciiz		", Altura: "
str004:
	.asciiz		"cm\n"
str005:
	.asciiz		"\n\nExamen de ETC de ensamblador\n\n 1. Ordenar pacientes por edad\n 2. Mostrar estadísticas anuales\n 3. Mostrar y contar consultas por paciente\n 0. Salir\n\nElige una opción: "
str006:
	.asciiz		"\n\n"
str007:
	.asciiz		"Pacientes antes de ordenarlos:\n"
str008:
	.asciiz		"\nPacientes después de ordenarlos:\n"
str009:
	.asciiz		"Estadísticas anuales de "
str010:
	.asciiz		":\nTotal de consultas: "
str011:
	.asciiz		"\nTotal de pacientes: "
str012:
	.asciiz		" ["
str013:
	.asciiz		"]"
str014:
	.asciiz		"\nAltura media de los pacientes: "
str015:
	.asciiz		"Total de consultas para el paciente "
str016:
	.asciiz		": "
str017:
	.asciiz		"¡Adiós!\n"
str018:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"

	.text	

# EJERCICIO 1
ordenar_pacientes_por_nacimiento:
	addiu	$sp, $sp, -4
	sw	$ra, ($sp)	# escribir en $sp no $sp-4
	addiu	$sp, $sp, -4	# pushear $sx
	sw	$s0, ($sp)
	addiu	$sp, $sp, -4	# pushear $sx
	sw	$s1, ($sp)
	addiu	$sp, $sp, -4	# pushear $sx
	sw	$s2, ($sp)
	addiu	$sp, $sp, -4	# pushear $sx
	sw	$s3, ($sp)
	li      $s0, 0		# no usar $at
	lw      $s1, num_pacientes # no usar $tx
        la      $s2, pacientes	# no usar $tx
B0_0:   bge     $s0, $s1, B0_1	# no usar $at
	beq     $s0, 0, B0_2	# no usar $at
	mul     $s3, $s0, 60	# no usar $at, tamaño 60?, no usar $v0
	addu    $a0, $s2, $s3
	addiu	$a0, $a0, 40
	addiu   $a1, $a0, -60	# no usar $a1, tamaño 60
	jal     comparar_fechas
	beq     $v0, $0, B0_2
	move    $a0, $s0
	addiu   $a1, $s4, -1
	jal     intercambiar_pacientes
	addiu   $s0, $s0, -1
	j       B0_0
B0_2:   addiu   $s0, $s0, 1	# no usar $at
	j       B0_0
B0_1:   lw	$s3, -4($sp)
	addiu	$sp, $sp, 4
	lw	$s2, -4($sp)
	addiu	$sp, $sp, 4
	lw	$s1, -4($sp)
	addiu	$sp, $sp, 4
	lw	$s0, -4($sp)
	addiu	$sp, $sp, 4
	lw	$ra, -4($sp)
	addiu	$sp, $sp, 4
	
	jr      $ra

# EJERCICIO 2
calcular_estadisticas:

#	void calcular_estadisticas(int ano, Estadisticas *estadisticas) {
	# $s6 = ano
	# $s7 = estadisticas
	move $s6, $a0
	move $s7, $a1
	addiu	$sp, $sp, -4
	sw	$ra, ($sp)	# escribir en $sp no $sp-4
	addiu	$sp, $sp, -4	# pushear $a0
	sw	$a0, ($sp)
	addiu	$sp, $sp, -4	# pushear $a1
	sw	$a1, ($sp)
	addiu	$sp, $sp, -4	# pushear $s0
	sw	$s0, ($sp)
	addiu	$sp, $sp, -4	# pushear $s1
	sw	$s1, ($sp)
	addiu	$sp, $sp, -4	# pushear $s2
	sw	$s2, ($sp)
	addiu	$sp, $sp, -4	# pushear $s3
	sw	$s3, ($sp)
	addiu	$sp, $sp, -4	# pushear $s4
	sw	$s4, ($sp)
	addiu	$sp, $sp, -4	# pushear $s6
	sw	$s6, ($sp)
	addiu	$sp, $sp, -4	# pushear $s7
	sw	$s7, ($sp)
	
	lw	$s1, num_consultas	# $s1 = num_consultas
	
#  for (int i = 0; i < num_consultas; ++i) {
	li	$s0, 0		# $s0 = i
for:	bge 	$s0, $s1, forend
#    if (consultas[i].fecha.ano == ano) {
	# consultas[i] -> consultas + (168*i)	168 es el tamaño de cada consulta
	mul	$s2, $s0, 168	# $s2 = 168 * i
	la	$s3, consultas	# $s3 = consultas
	addu	$s2, $s2, $s3	# $s2 = consultas + (168*i)
	addu	$s2, $s2, 4	# *(consultas + (168*i)).fecha.ano -> $s2 = consultas + (168*i) + 4
	lw	$s4, ($s2)	# $s4 = consultas[i].fecha.ano
	bne	$s4, $s6, ifend
#      estadisticas->num_consultas_totales++;
	lw	$s3, ($s7)	# $s3 = *estadisticas = estadisticas->num_consultas_totales;
	add	$s3, $s3, 1	# $s3++
	sw	$s3, ($s7)	# estadisticas->num_consultas_totales = $s3
#      if (paciente_ya_visto(estadisticas,
#                            consultas[i].paciente_id)) {
	move	$a0, $s7	# $a0 = estadisticas
	add	$s2, $s2, -4	# $s2 = consultas + (168*i)
	lw	$a1, ($s2)	# $a1 = consultas[i].paciente_id   -> $a1 = *(consultas + (168*i))
	jal	paciente_ya_visto
	beqz	$v0, if2end
#        int indice = estadisticas->num_pacientes_id_vistos;
	add	$s3, $s7, 4	# $s2 = estadisticas + 4
	lw	$s4, ($s3)	# $s3 = *(estadisticas + 4) = estadisticas->num_pacientes_id_vistos
#        estadisticas->num_pacientes_id_vistos = indice + 1;
	add	$s4, $s4, 1
#        estadisticas->pacientes_id_vistos[indice] = consultas[i].paciente_id;
	
#        Paciente *p = buscar_paciente_por_id(consultas[i].paciente_id);
#        estadisticas->altura_media_pacientes_cm = estadisticas->altura_media_pacientes_cm + p->altura_cm;
#      }
if2end:
#    }
ifend:
#  }
	j	for
forend:

#  if (estadisticas->num_pacientes_id_vistos > 0) {
#      estadisticas->altura_media_pacientes_cm = estadisticas->altura_media_pacientes_cm / estadisticas->num_pacientes_id_vistos;
#  }
#}
        # deapiar
        jr	$ra

# EJERCICIO 3
mostrar_y_contar_consultas:
        # POR HACER
        break

mostrar_fecha:
	addiu	$sp, $sp, -32
	sw	$ra, 28($sp)
	sw	$s1, 24($sp)
	sw	$s0, 20($sp)
	move	$s0, $a0
	lw	$a0, 0($a0)
	jal	longitud_integer
	li	$t1, 4
	subu	$a1, $t1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 0($s0)
	jal	print_integer
	li	$a0, 45
	jal	print_character
	lw	$a0, 4($s0)
	jal	longitud_integer
	li	$s1, 2
	subu	$a1, $s1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 4($s0)
	jal	print_integer
	li	$a0, 45
	jal	print_character
	lw	$a0, 8($s0)
	jal	longitud_integer
	subu	$a1, $s1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 8($s0)
	jal	print_integer
	lw	$s0, 20($sp)
	lw	$s1, 24($sp)
	lw	$ra, 28($sp)
	addiu	$sp, $sp, 32
	jr	$ra

longitud_integer:
	slti	$v0, $a0, 1
	beqz	$a0, B8_3
	lui	$t1, 26214
	ori	$v1, $t1, 26215
B8_2:	mult	$a0, $v1
	mfhi	$t1
	srl	$a1, $t1, 31
	sra	$t1, $t1, 2
	addu	$t1, $t1, $a1
	addiu	$v0, $v0, 1
	addiu	$a0, $a0, 9
	sltiu	$a1, $a0, 19
	move	$a0, $t1
	beqz	$a1, B8_2
B8_3:	jr	$ra

repite_caracter:
	addiu	$sp, $sp, -32
	sw	$ra, 28($sp)
	sw	$s1, 24($sp)
	sw	$s0, 20($sp)
	blez	$a1, B9_3
	move	$s0, $a1
	move	$s1, $a0
B9_2:	move	$a0, $s1
	jal	print_character
	addiu	$s0, $s0, -1
	bnez	$s0, B9_2
B9_3:	lw	$s0, 20($sp)
	lw	$s1, 24($sp)
	lw	$ra, 28($sp)
	addiu	$sp, $sp, 32
	jr	$ra

mostrar_paciente:
	addiu	$sp, $sp, -24
	sw	$ra, 20($sp)
	sw	$s0, 16($sp)
	move	$s0, $a0
	la	$a0, str000
	jal	print_string
	lw	$a0, 0($s0)
	jal	longitud_integer
	li	$t1, 4
	subu	$a1, $t1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 0($s0)
	jal	print_integer
	la	$a0, str001
	jal	print_string
	addiu	$a0, $s0, 4
	jal	print_string
	la	$a0, str002
	jal	print_string
	addiu	$a0, $s0, 40
	jal	mostrar_fecha
	la	$a0, str003
	jal	print_string
	lw	$a0, 52($s0)
	jal	print_integer
	la	$a0, str004
	jal	print_string
	lw	$s0, 16($sp)
	lw	$ra, 20($sp)
	addiu	$sp, $sp, 24
	jr	$ra

intercambiar_pacientes:
	addiu	$sp, $sp, -96
	sw	$ra, 92($sp)
	sw	$s3, 88($sp)
	sw	$s2, 84($sp)
	sw	$s1, 80($sp)
	sw	$s0, 76($sp)
	move	$s0, $a1
	sll	$t1, $a0, 2
	sll	$v0, $a0, 6
	subu	$t1, $v0, $t1
	la	$s3, pacientes
	addu	$s1, $s3, $t1
	addiu	$s2, $sp, 16
	move	$a0, $s2
	move	$a1, $s1
	li	$a2, 60
	jal	memcpy
	sll	$t1, $s0, 2
	sll	$v0, $s0, 6
	subu	$t1, $v0, $t1
	addu	$s0, $s3, $t1
	move	$a0, $s1
	move	$a1, $s0
	li	$a2, 60
	jal	memcpy
	move	$a0, $s0
	move	$a1, $s2
	li	$a2, 60
	jal	memcpy
	lw	$s0, 76($sp)
	lw	$s1, 80($sp)
	lw	$s2, 84($sp)
	lw	$s3, 88($sp)
	lw	$ra, 92($sp)
	addiu	$sp, $sp, 96
	jr	$ra

buscar_paciente_por_id:
	lw	$v1, num_pacientes
	li	$v0, 0
	blez	$v1, B5_4
	la	$a1, pacientes
B5_2:	lw	$t1, 0($a1)
	beq	$t1, $a0, B5_5
	addiu	$v1, $v1, -1
	addiu	$a1, $a1, 60
	bnez	$v1, B5_2
B5_4:	jr	$ra
B5_5:	move	$v0, $a1
	jr	$ra

comparar_fechas:
	lw	$v1, 0($a1)
	lw	$a2, 0($a0)
	slt	$t1, $a2, $v1
	li	$v0, 1
	bnez	$t1, B1_6
	li	$v0, 0
	bne	$a2, $v1, B1_6
	lw	$t1, 4($a1)
	lw	$v0, 4($a0)
	slt	$v0, $v0, $t1
	bnez	$v0, B1_6
	bne	$a2, $v1, B1_6
	lw	$t1, 4($a1)
	lw	$v1, 4($a0)
	li	$v0, 0
	bne	$v1, $t1, B1_6
	lw	$t1, 8($a1)
	lw	$v0, 8($a0)
	slt	$v0, $v0, $t1
B1_6:	jr	$ra

paciente_ya_visto:
	lw	$v1, 4($a0)
	slt	$v0, $zero, $v1
	blez	$v1, B4_6
	lw	$t1, 8($a0)
	beq	$t1, $a1, B4_6
	addiu	$v0, $a0, 12
	li	$a2, 1
B4_3:	move	$a0, $a2
	beq	$v1, $a2, B4_5
	addiu	$t1, $v0, 4
	addiu	$a2, $a0, 1
	lw	$a3, 0($v0)
	move	$v0, $t1
	bne	$a3, $a1, B4_3
B4_5:	slt	$v0, $a0, $v1
B4_6:	jr	$ra

	.globl	main
main:
	addiu	$sp, $sp, -200
	sw	$ra, 196($sp)
	sw	$fp, 192($sp)
	sw	$s7, 188($sp)
	sw	$s6, 184($sp)
	sw	$s5, 180($sp)
	sw	$s4, 176($sp)
	sw	$s3, 172($sp)
	sw	$s2, 168($sp)
	sw	$s1, 164($sp)
	sw	$s0, 160($sp)
	jal	clear_screen
	addiu	$s0, $sp, 64
	addiu	$t1, $s0, 8
	sw	$t1, 60($sp)
	la	$t1, str005
	sw	$t1, 40($sp)
	la	$t1, str006
	sw	$t1, 36($sp)
	la	$t1, str018
	sw	$t1, 32($sp)
	la	$t1, str017
	sw	$t1, 28($sp)
	la	$t1, str007
	sw	$t1, 24($sp)
	la	$t1, str008
	sw	$t1, 20($sp)
	la	$s7, str009
	la	$fp, str010
	la	$s3, str011
	la	$t1, str012
	sw	$t1, 56($sp)
	la	$t1, str013
	sw	$t1, 52($sp)
	la	$s6, str014
	la	$t1, str015
	sw	$t1, 48($sp)
	la	$t1, str016
	sw	$t1, 44($sp)
	j	B11_2
B11_1:	lw	$a0, 28($sp)
	jal	print_string
	li	$a0, 0
	jal	mips_exit
B11_2:	lw	$a0, 40($sp)
	jal	print_string
	jal	read_character
	lw	$a0, 36($sp)
	move	$s4, $v0
	jal	print_string
	andi	$t1, $s4, 255
	addiu	$v0, $t1, -48
	sltiu	$t1, $v0, 4
	beqz	$t1, B11_11
	sll	$t1, $v0, 2
	lw	$t1, jump_table000($t1)
	jr	$t1
B11_4:	lw	$a0, 24($sp)
	jal	print_string
	lw	$t1, num_pacientes
	blez	$t1, B11_7
	la	$s4, pacientes
	li	$s1, 0
B11_6:	move	$a0, $s4
	jal	mostrar_paciente
	addiu	$s1, $s1, 1
	lw	$t1, num_pacientes
	slt	$t1, $s1, $t1
	addiu	$s4, $s4, 60
	bnez	$t1, B11_6
B11_7:	jal	ordenar_pacientes_por_nacimiento
	lw	$a0, 20($sp)
	jal	print_string
	lw	$t1, num_pacientes
	blez	$t1, B11_10
	la	$s4, pacientes
	li	$s1, 0
B11_9:	move	$a0, $s4
	jal	mostrar_paciente
	addiu	$s1, $s1, 1
	lw	$t1, num_pacientes
	slt	$t1, $s1, $t1
	addiu	$s4, $s4, 60
	bnez	$t1, B11_9
B11_10:	li	$a0, 10
	jal	print_character
	j	B11_2
B11_11:	lw	$a0, 32($sp)
	jal	print_string
	jal	read_character
	j	B11_2
B11_12:	li	$s4, 2015
	j	B11_14
B11_13:	move	$a0, $s6
	jal	print_string
	lw	$a0, 152($sp)
	jal	print_integer
	la	$a0, str006
	jal	print_string
	addiu	$s4, $s4, 1
	li	$t1, 2017
	beq	$s4, $t1, B11_2
B11_14:	move	$a0, $s7
	jal	print_string
	move	$a0, $s4
	jal	print_integer
	move	$a0, $s0
	li	$a1, 0
	li	$a2, 92
	jal	memset
	move	$a0, $s4
	move	$a1, $s0
	jal	calcular_estadisticas
	move	$a0, $fp
	jal	print_string
	lw	$a0, 64($sp)
	jal	print_integer
	move	$a0, $s3
	jal	print_string
	lw	$s5, 68($sp)
	move	$a0, $s5
	jal	print_integer
	blez	$s5, B11_13
	lw	$a0, 56($sp)
	jal	print_string
	lw	$s1, 60($sp)
B11_16:	li	$a0, 32
	jal	print_character
	lw	$a0, 0($s1)
	jal	print_integer
	addiu	$s5, $s5, -1
	addiu	$s1, $s1, 4
	bnez	$s5, B11_16
	lw	$a0, 52($sp)
	jal	print_string
	j	B11_13
B11_18:	lw	$t1, num_pacientes
	blez	$t1, B11_2
	la	$s4, pacientes
	li	$s1, 0
B11_20:	move	$a0, $s4
	jal	mostrar_paciente
	move	$a0, $s4
	jal	mostrar_y_contar_consultas
	lw	$a0, 48($sp)
	move	$s5, $v0
	jal	print_string
	lw	$a0, 0($s4)
	jal	longitud_integer
	li	$t1, 4
	subu	$a1, $t1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 0($s4)
	jal	print_integer
	lw	$a0, 44($sp)
	jal	print_string
	move	$a0, $s5
	jal	print_integer
	la	$a0, str006
	jal	print_string
	addiu	$s1, $s1, 1
	lw	$t1, num_pacientes
	slt	$t1, $s1, $t1
	addiu	$s4, $s4, 60
	bnez	$t1, B11_20
	j	B11_2

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
	li	$v0, 39
	syscall	
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

