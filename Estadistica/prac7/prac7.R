# 1.
# a.
prob = c(
  choose(6, 3)/choose(10, 3),
  choose(6, 2)*choose(4, 1)/choose(10, 3),
  choose(6, 1)*choose(4, 2)/choose(10, 3),
  choose(4, 3)/choose(10, 3)
)
# b.
# funcion de densidad de probabildiad
f = function(x) sum(prob[val==x])
# funcion de distribucion
F = function(x) sum(prob[val<=x])
plot(val, f(val))
plot(val, F(val), type='s')
# c.
media = sum(val*f(val))
var = sum((val-media)^2*f(val))
sd = sqrt(var)
# d.
datos = sample(val, prob=prob, replace=TRUE, 1000)
fa = table(datos)
fr = table(datos)/length(datos)
Fr = cumsum(fr)
barplot(fr)
mean(datos)
var(datos)
sd(datos)


# percentil de X
percentil=function(p){
  for(a in val){
    if(F(a)>=p){return(a)}
  }
}
percentil=Vectorize(percentil)

# P(x<2)
F(2)
# P(x>2)
1 - F(2)
# P(0 < x < 1)
F(1) - F(0)

# E[3X^2-X]
E = sum((3*val^2-val)*f(val))

# ==============
# X { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
val = 0:10
# P(X = i) = k(i + i^2)
k = 1/sum(val+val^2)
prob = k*(val+val^2)


