# 1
pesos = c(72, 74, 72, 76, 72, 73)
notas = c(4, 5, 7, 8, 4, 5)
sexos = rep(c("M", "H"), c(4, 2))
consolas = scan(sep=" ", strip.white=TRUE, what="character")
so = rep(c("Linux", "Windows", "MacOS", "Sun Solaris", "Unix", "Embedded", Otro), c(138, 123, 6, 9, 9, 6, 9))
so = rep(c("Linux", "Windows", "MacOS", "Sun Solaris", "Unix", "Embedded", "Otro"), c(138, 123, 6, 9, 9, 6, 9))
table(so)
# 2
df = data.frame(pesos, notas, sexos)

# 3
setwd("practicas-uni/Estadistica/practica1")
leng_txt = scan("lenguajes.txt", sep="", what=character(), strip.white=TRUE)
peso_txt = scan("pesos.txt", sep="", what=numeric(), strip.white=TRUE)
juegos = read.table("Juegos.dat")

# 4
#  i
ni.Genero = as.numeric(table(Genero))
fi.Genero = ni/length(ni)
table.Genero = data.frame(ni.Genero, fi.Genero)

ni.Fecha = as.numeric(table(Fecha))
fi.Fecha = ni.Fecha/length(ni.Fecha)
tabla.Fecha = data.frame(ni.Fecha, fi.Fecha)

ni.Plataforma = as.numeric(table(Plataforma))
fi.Plataforma = ni.Plataforma/length(ni.Plataforma)
tabla.Plataforma = data.frame(ni.Plataforma, fi.Plataforma)

# ii
barplot(ni.Genero)
barplot(ni.Fecha)
barplot(ni.Plataforma)

# iii
pie(ni.Genero)
pie(ni.Fecha)
pie(ni.Plataforma)
# angulos
fi.Genero * 360
fi.Fecha * 360
fi.Plataforma * 360

# 5
internet = scan(what=double(), sep=",", strip.white=TRUE)
ni.internet = as.numeric(table(internet))
max(internet)
min(internet)
internet_intervalos1 = cut(internet, breaks=seq(0, 90, 10))
internet_intervalos2 = cut(internet, breaks=c(0, 30, 50, 70, 90), right=FALSE)
internet_intervalos3 = cut(internet, breaks=c(0, 20, 50, 70, 100), right=TRUE)

ni.internet_intervalos1 = as.numeric(table(internet_intervalos1))
#...
#barplot...
#pie

seleccion = internet[internet >= 65 & internet <= 80]
sort(seleccion)
sort(seleccion, decreasing=TRUE)
