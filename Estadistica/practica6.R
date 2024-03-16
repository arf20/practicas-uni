# practica 6
# 1a
moneda = c("cara", "cruz")
sample(moneda, 1)
# 1b
dado = c(1, 2, 3, 4, 5, 6)
sample(dado, 1)
# 1c
moneda2 = c(rep("cara", 4), rep("cruz", 6))
sample(moneda2, 1)
# 1d
muestras = sample(moneda2, 1000, replace = TRUE)
table(muestras)

# 2
U1 = c("R", "R", "B", "B", "B", "B")
U2 = c("R", "R", "R", "R", "R", "B", "B")
U3 = c("R", "R", "R", "R", "B", "B", "B")
urnas = c(U1, U2, U3)
# 2a
PR = length(urnas[urnas == "R"])/length(urnas)
# 2b
sample(urnas, 1, replace = TRUE)
# 2c
muestras = sample(urnas, 1000, replace = TRUE)
table(muestras)
# si
# 2d


