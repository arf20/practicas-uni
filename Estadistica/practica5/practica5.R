setwd("~/practicas-uni/Estadistica/practica5/")
datos = read.table("datos.dat")
attach(datos)

# a.
plot(x = pesos, y = alturas)
# b.
reg = lm(alturas ~ pesos, datos)
abline(reg, col='magenta')
# c.
r = cor(pesos, alturas)
R = r^2
# la corrleación no es muy buena
# d.
peso = (180 - reg$coefficients[1])/ reg$coefficients[2]
# e.
altadj = reg$coefficients[2] * pesos + reg$coefficients[1]
residuos = alturas - altadj
mean(residuos) # casi 0
var(residuos) # alta, >4
relacion = var(altadj)/var(alturas) # 0.52

