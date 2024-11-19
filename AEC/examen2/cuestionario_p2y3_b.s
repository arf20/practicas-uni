.data
a:  .float 1
b:  .float 2
va: .double 1,2,3,4,5,6,7,8,9,10
vb: .double 11,12,13,14,15,16,17,18,19,20
z:  .space 80
.text
.globl main
main:
    la $t1, va              # carga la dir vector va en $t1
    la $t2, vb              # carga la dir vector vb en $t2
    la $t7, vb              # carga la dir vector vb en $t7 para comprobar el final del bucle
    la $t5, z               # carga la dir z en $t5
    la $t6, a               # carga la dir de "a" en $t6
    lwc1 $f1, 0($t6)        # carga "a" en f0
    cvt.d.s $f0, $f1        # convertimos "a" en DP y lo guardamos en $f0:$f1
    la $t6, b               # carga la dir de "b" en $t6
    lwc1 $f3, 0($t6)        # carga "b" en f3
    cvt.d.s $f2, $f3        # convertimos "b" en DP y lo guardamos en $f2:$f3
loop:
    lwc1 $f8, 0($t1)
    lwc1 $f9, 4($t1)        # f8:f9=va[i]
    lwc1 $f11,4($t2)        # f10:f11=vb[i]
    lwc1 $f10,0($t2)
    div.d $f10,$f10,$f2     # f10=vb[i]*b
    mul.d $f8,$f8,$f0       # f8=va[i]*a
    addi $t1,$t1,8          # actualizamos todos los indices
    addi $t2,$t2,8
    addi $t5,$t5,8
    add.d $f16,$f8,$f10     # f16 = va[i]*a + vb[i]*b
    swc1 $f16, -8($t5)      # almacenamos la parte baja del resultado z[i]
    swc1 $f17, -4($t5)      # almacenamos la parte alta del resultado z[i]
    bne $t1, $t7, loop      # comprobamos si hemos terminado el bucle
    addi $v0, $0, 10
    syscall                 # llamada para salir del programa
