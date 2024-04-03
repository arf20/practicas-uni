# 1a
setwd("~/practicas-uni/Estadistica/practica4")
datos = read.csv("tiempos.csv")
attach(datos)
Categoria = cut(Tiempo, breaks = c(0, as.numeric(quantile(Tiempo, 0.25)), as.numeric(quantile(Tiempo, 0.75)), 1), labels = c("Rapido", "Normal", "Lento"), include.lowest = TRUE)
nuevosdatos = data.frame(datos, Categoria)
ni = table(Categoria, Algoritmo)
fi = prop.table(ni)
addmargins(fi)
# b
Genero = c(rep("Hombre", 3), rep("Mujer", 3))
Pelo = rep(c("Castaño", "Moreno", "Rubio"), 2)
Freqs = c(12, 8, 5, 20, 10, 25)
xtabs(Freqs~Genero+Pelo)

# 2
barplot(ni)

rowSums(ni)
colSums(ni)

prop.table(ni, 1)
prop.table(ni, 2)

#yikes

# 3
summary(Tiempo)
hist(Tiempo)

by(Tiempo, Algoritmo, summary)
boxplot(Tiempo~Algoritmo)

by(Tiempo, Max_repeticiones, summary)
boxplot(Tiempo~Max_repeticiones)

by(Tiempo[Algoritmo==0], Max_repeticiones[Algoritmo==0], summary)
by(Tiempo[Algoritmo==1], Max_repeticiones[Algoritmo==1], summary)
by(Tiempo[Algoritmo==2], Max_repeticiones[Algoritmo==2], summary)
boxplot(Tiempo[Algoritmo==0]~Max_repeticiones[Algoritmo==0])
boxplot(Tiempo[Algoritmo==1]~Max_repeticiones[Algoritmo==1])
boxplot(Tiempo[Algoritmo==2]~Max_repeticiones[Algoritmo==2])
