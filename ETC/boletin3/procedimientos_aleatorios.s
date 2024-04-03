#* Bolet�n 3 - Convenios y procedimientos
#-
#* Ejercicio propuesto en clase "procedimientos_aleatorios"
#============================================================
#
# Elabore un programa en ensamblador de MIPS con las siguientes especificaciones:
#
# a) Implemente la funci�n "obtener_cuadrado_aleatorio" que obtiene el resultado de elevar al cuadrado un n�mero aleatorio 
#   y tiene como argumento un n�mero que es el l�mite superior del n�mero aleatorio. Esta funci�n
#   deber� usar la funci�n ya implementada en ensamblador cuya etiqueta de comienzo es "generar_aleatorio"
#   y cuyo c�digo se indica a continuaci�n:
#
# generar_aleatorio:
#	move	$t0, $a0	# carga en $t0 el argumento $a0 (limite superior del n�mero aleatorio a generar)
#	li 	$v0, 42  	# c�digo de llamada al sistema 42 para generar un entero aleatorio
#	move 	$a1, $t0 	# asignamos a $a1 el limite superior cargado en $t0 
#	syscall     		# el n�mero aleatorio lo deja en $a0
#	move	$v0, $a0	# carga en $v0 el n�mero aleatorio obtenido
#	jr	$ra
#	
# b) Partiendo de un c�digo escrito en lenguaje C, elabore el procedimiento "imprimir_lista_aleatoria" que obtiene una
#   lista formada por un n�mero de l�neas aleatorio hasta MAX_LINEAS que es una variable global cuyo valor es 20.
#   En cada l�nea imprime el cuadrado de un n�mero aleatorio cuyo l�mite superior se especifica en el primer y �nico argumento.
#   Cada dos l�neas de la lista imprime una l�nea en blanco. 
#   En este caso, debe traducir el siguiente procedimiento en C que usa las funciones "generar_aleatorio" 
#   y "cuadrado_aleatorio" citadas en el apartado a):
#
# ...
# int MAX_LINEAS = 20;
# ...
# void imprimir_lista_aleatoria (int lim) {
#	int n = generar_aleatorio (MAX_LINEAS);
#	if (n > 0) {
#		printf ("Lista de aleatorios al cuadrado:\n");
#		for (i = 1; i <= n; i++) {
#			printf ("%d\n", obtener_cuadrado_aleatorio (lim));
#			if (i%2 = 0) {
#				printf ("\n");
#			}
#		}
#	} else {
#		printf ("Nada que imprimir\n");
#	}
# }
#
# c) Otras consideraciones:
# - El programa pedir� por teclado el l�mite superior de los n�meros aleatorios y seguidamente invocar� 
#   al procedimiento "imprimir_lista_aleatoria" al que se le pasar� como argumento el n�mero entero introducido.
#   El mensaje de solicitud del n�mero ser� "Introduce un entero como l�mite superior de los n�meros aleatorios: ".
#   Estas acciones se llevar�n a cabo en el fragmento de c�digo correspondientes al procedimiento "main".
#    
# - A continuaci�n, se proporciona una versi�n inicial del c�digo fuente del programa que deber� completarse
#   (ambos segmentos) seg�n se requiera por las anteriores especificaciones.
#
		.data
str001:		.asciiz "Introduce un entero como l�mite superior de los n�meros aleatorios: "
str002:		.asciiz "Lista de aleatorios al cuadrado:\n"
str003:		.asciiz "Nada que imprimir.\n"
str004:		.asciiz "\n"
MAX_LINEAS:	.word 20
		.text
		.globl main
		j main
		
# funci�n 'generar_aleatorio'		
generar_aleatorio:			# en $a0 tiene el l�mite superior del n�mero aleatorio
		move	$t0, $a0	# carga en $t0 el argumento $a0 (limite superior del n�mero aleatorio a generar)
		li 	$v0, 42  	# c�digo de llamada al sistema 42 para generar un entero aleatorio
		move 	$a1, $t0 	# asignamos a $a1 el limite superior cargado en $t0 
		syscall     		# el n�mero aleatorio lo deja en $a0
		move	$v0, $a0	# carga en $v0 el n�mero aleatorio obtenido
		jr	$ra

# procedimiento 'obtener_cuadrado_aleatorio' cuyo �nico argumento $a0=l�mite superior del n�mero aleatorio
obtener_cuadrado_aleatorio:  # void obtener_cuadrado_aleatorio(int ul) {
		addiu $sp, $sp, -4	# push ra
		sw $ra, ($sp)
		# a0 ul
		#   int r = generar_aleatorio(ul);
		jal generar_aleatorio
		# v0 r
		#   return r*r;
		mul $v0, $v0, $v0
		# }
		lw $ra, ($sp)		# pop ra
		addiu $sp, $sp, 4
		jr $ra
		

# procedimiento 'imprimir_lista_aleatoria' cuyo �nico argumento $a0=l�mite superior de los n�meros aleatorios		
imprimir_lista_aleatoria:	# void imprimir_lista_aleatoria (int lim) {
		addiu $sp, $sp, -4	# push ra
		sw $ra, ($sp)
		addiu $sp, $sp, -4	# push s0
		sw $ra, ($sp)
		addiu $sp, $sp, -4	# push s1
		sw $ra, ($sp)
		addiu $sp, $sp, -4	# push s2
		sw $ra, ($sp)
		move $s2, $a0		# s2 lim
		#   int n = generar_aleatorio (MAX_LINEAS);
		lw $a0, MAX_LINEAS
		jal generar_aleatorio
		move $s0, $v0	# s0 n
		#   if (n > 0) {
		beqz $v0, ice
		#     printf ("Lista de aleatorios al cuadrado:\n");
		li $v0, 4
		la $a0, str002
		syscall
		#     for (i = 1; i <= n; i++) {
		li $s1, 1	# s0 i
il:		bgt $s1, $s0, ile
		#       printf ("%d\n", obtener_cuadrado_aleatorio (lim));
		move $a0, $s2
		jal obtener_cuadrado_aleatorio
		move $a0, $v0
		li $v0, 1
		syscall
		la $a0, str004
		li $v0, 4
		syscall
		#       }
		add $s1, $s1, 1
		j il
ile:
		#     }
icei:
		#   }
		break

# procedimiento principal "main" que solicita la introducci�n de un n�mero e invoca al procedimiento "imprimir_lista_aleatoria"		
main:
		#TODO
		break
		
