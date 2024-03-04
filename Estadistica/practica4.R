# practica repaso parcial
# 1

puntosMedios=seq(3, 21, 3)
freqAbs = seq(20, 50, 5)
mediaClases = sum(puntosMedios*freqAbs)/sum(freqAbs)
varianzaClases = sum((puntosMedios-mediaClases)^2*freqAbs)/sum(freqAbs)

# 2
setwd("~/practicas-uni/Estadistica")
scan("datosG1yG2.txt", sep=" ", what=numeric(), strip.white=TRUE)
datos=scan("datosG1yG2.txt", sep=" ", what=numeric(), strip.white=TRUE)
histo = hist(datos)
Q1 = quartile(datos, 0.25)
Q1 = quantile(datos, 0.25)
Q3 = quantile(datos, 0.75)
RIC = Q3-Q1
Vm = Q1-1.5*RIC
VM = Q3+1.5*RIC
atipicos = datos[datos>VM | datos<Vm]
atipicos
datoscor = cut(datos, breaks=histo$breaks, include.lowest = TRUE)
datoscor
nimbres = names(table(datoscor))
nombres = names(table(datoscor))
ni = as.numeric(table(datoscor))
fi = ni/length(ni)
Ni = cumsum(ni)
Fi = cumsum(fi)
tabla = data.frame(nombres, ni, fi, Ni, Fi)

# 3
freq = c(seq(300, 700, 100), seq(550, 950, 100), seq(1050, 1850, 200))
genero = c(rep("A", 5), rep("CC", 5), rep("T", 5))
años = rep(c(2017, 2018, 2019, 2020, 2021), 3)
tablaFreqAbs = xtabs(freq~genero+años)
tablaFreqRel = prop.table(tablaFreqAbs)
tablaFreqRel = tablaFreqAbs/sum(tablaFreqAbs)
tablaRelMar = addmargins(tablaFreqRel)


# 4
# NO ENTRA

# otro
T1 = as.numeric(quantile(datos, 0.3))
T2 = as.numeric(quantile(datos, 0.7))
datoscor2 = cut(datos, breaks=c(min(datos), T1, T2, max(datos)), labels=c("Ligero", "Medio", "Pesado"), include.lowest = TRUE)
summary = summary(datoscor2)
by(datos, datoscor2, summary)
boxplot(datos~datoscor2)

# otro
datoscor3 = cut(datos[datos>=65 & datos<=80], breaks=seq(65, 80, 3), include.lowest = TRUE)
barplot(table(datoscor3))
pie(table(datoscor3))
