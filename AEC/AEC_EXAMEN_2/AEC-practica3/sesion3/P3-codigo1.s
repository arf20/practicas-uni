# Datos
.data
a: .float 10
b: .float 5
#vector x
x:  .double 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
x1: .double 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
x2: .double 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
x3: .double 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
x4: .double 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
# IEEE 754 64 bits, 1 = 0x3FF00000 00000000
#vector y
y:    .double 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10
y1:   .double 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10
y2:   .double 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10
y3:   .double 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10
y4:   .double 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10
# IEEE 754 64 bits, 10 = 0x40240000 00000000

#vector z
z:    .space 800

# Código: z[i]=(a*x[i]+y[i])/b
.text
.globl main
main:
        la $t1, x            #carga la dir de x[0] en $t1
        la $t2, y            #carga la dir de y[0] en $t2
        la $t3, z            #carga la dir de z[0] en $t3
        la $t4, a            #carga la dir de "a" en $t4
        la $t5, b            #carga la dir de "b" en $t5
        addi $t6,$t1,800     #preparamos el contador para detectar el final
        lwc1 $f0, 0($t4)     #carga "a" en f0
        cvt.d.s $f0, $f0     #convertimos "a" en DP y lo guardamos en $f0:$f1
        lwc1 $f2, 0($t5)     #carga "b" en f2
        cvt.d.s $f2, $f2     #convertimos "b" en DP y lo guardamos en $f2:$f3

loop: 
        lwc1 $f4,0($t1)      #f4=x[i] (parte alta)
        lwc1 $f5,4($t1)      #f5=x[i] (parte baja)
        lwc1 $f6,0($t2)      #f6=y[i] (parte baja)
        lwc1 $f7,4($t2)      #f7=x[i] (parte baja)
        mul.d $f8,$f0,$f4    #f8=a*x[i]
        add.d $f8,$f8,$f6    #f8=a*x[i]+y[i]
        div.d $f8,$f8,$f2    #f8=(a*x[i]+y[i])/b
        swc1 $f8, 0($t3)     #z[i]=(a*x[i]+y[i])/b (Parte alta)
        swc1 $f9, 4($t3)     #z[i]=(a*x[i]+y[i])/b (Parte baja)
        addi $t1,$t1,8       #actualizamos todos los índices
        addi $t2,$t2,8
        addi $t3,$t3,8
        bne $t1, $t6, loop   #comprobamos si hemos terminado el bucle
        addi $v0, $0, 10     # llamada para salir del programa
        syscall
