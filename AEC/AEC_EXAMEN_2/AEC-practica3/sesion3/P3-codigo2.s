#los datos
.data
a:  .float 1
b:  .float 2
c:  .float 3
d:  .float 4
va: .double 1,2,3,4,5,6,7,8,9,10
vb: .double 11,12,13,14,15,16,17,18,19,20
vc: .double 21,22,23,24,25,26,27,28,29,30
vd: .double 31,32,33,34,35,36,37,38,39,40
z: .space 80

#el código
.text
.globl main
main: 
      la $t1, va           #carga la dir vector va en $t1
      la $t7, vb           #carga la dir vector vb en $t7 para comprobar el final del bucle
      la $t2, vb           #carga la dir vector vb en $t2
      la $t3, vc           #carga la dir vector vc en $t3
      la $t4, vd           #carga la dir vector vd en $t4
      la $t5, z            #carga la dir vector  z en $t5
      la $t6, a            #carga la dir de "a" en $t6
      lwc1 $f1, 0($t6)     #carga "a" en f0
      cvt.d.s $f0, $f1     #convertimos "a" en DP y lo guardamos en $f0:$f1
      la $t6, b            #carga la dir de "b" en $t6
      lwc1 $f3, 0($t6)     #carga "b" en f3
      cvt.d.s $f2, $f3     #convertimos "b" en DP y lo guardamos en $f2:$f3
      la $t6, c            #carga la dir de "c" en $t6
      lwc1 $f5, 0($t6)     #carga "c" en f5
      cvt.d.s $f4, $f5     #convertimos "c" en DP y lo guardamos en $f4:$f5
      la $t6, d            #carga la dir de "d" en $t6
      lwc1 $f7, 0($t6)     #carga "d" en f7
      cvt.d.s $f6, $f7     #convertimos "d" en DP y lo guardamos en $f6:$f7

loop:
       lwc1 $f8, 0($t1)        #f8=va[i]
       lwc1 $f9, 4($t1)        #f8=va[i]
       lwc1 $f10,0($t2)        #f10=vb[i]
       lwc1 $f11,4($t2)        #f10=vb[i]
       lwc1 $f12,0($t3)        #f12=vc[i]
       lwc1 $f13,4($t3)        #f12=vc[i]
       lwc1 $f14,0($t4)        #f14=vd[i]
       lwc1 $f15,4($t4)        #f14=vd[i]
       mul.d $f8,$f8,$f0       #f8=a*va[i]
       mul.d $f10,$f10,$f2     #f10=b*vb[i]
       mul.d $f12,$f12,$f4     #f12=c*vc[i]
       mul.d $f14,$f14,$f6     #f14=d*vd[i]
       addi $t1,$t1,8          #actualizamos todos los indices
       addi $t2,$t2,8
       addi $t3,$t3,8
       addi $t4,$t4,8
       addi $t5,$t5,8
       add.d $f16,$f8,$f10     #f16 = a*va[i] + b*vb[i]
       add.d $f18,$f12,$f14    #f18 = c*vc[i] + d*vd[i]
       add.d $f20,$f16,$f18    #f20 = a*va[i] + b*vb[i] + c*vc[i] + d*vd[i]
       swc1 $f20, -8($t5)      #almacenamos la parte baja del resultado z[i]
       swc1 $f21, -4($t5)      #almacenamos la parte alta del resultado z[i]
       bne $t1, $t7, loop      #comprobamos si hemos terminado el bucle
       addi $v0, $0, 10        # llamada para salir del programa
       syscall

