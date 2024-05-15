setwd("~/practicas-uni/Estadistica/prac8")

#1a

#dat1 y 2
#dat3 y 5
#dat4
#dat6

layout(matrix(1:6,3,2))
hist(dat1)
#
layout(1)

#b

Q = seq(0, 1, 0.1)
Qdat1 = quantile(dat1, Q)
Qdat2 = quantile(dat2, Q)
plot(Qdat3, Qdat5)
abline(0, 1)

#c

dat3tip = (dat3-mean(dat3))/sd(dat3)
dat5tip = (dat5-mean(dat5))/sd(dat5)
Qdat3tip = quantile(dat3tip, Q)
Qdat5tip = quantile(dat5tip, Q)
plot(Qdat3tip, Qdat5tip)
abline(0, 1)

# 2

# todas discretas (uniforme, bernouilli, geometrica,
#  binomial, poisson)

# 1. poisson o binomial p pequeña
# 2. poisson o binomial p pequeña
# 3. binomial
p = 1 - (var(dat3)/mean(dat3))
n = mean(dat3)/p
Q = seq(0, 1, 0.1)
Qdat3 = quantile(dat3, Q)
Qdat3t = qbinom(Q, p, q)
plot(Qdat3, Qdat3t)
abline(0, 1)
# ok
# 4. decreciente
p = 1/(1+mean(dat4))
Qdat4 = quantile(dat4, Q)
Qdat4t = qgeom(Q, p)
plot(Qdat4, Qdat4t)
abline(0, 1)
# ok
# 5. poisson o binomial p pequeña
# 6. uniforme



# 3
dat3a = rbinom(1000, 200, 0.1)
dat3b = rbinom(5000, 200, 0.7)
dat3a = rbinom(10000, 200, 0.1)
dat3c = rpois(10000, 200*0.1)
dat3d = rpois(10000, 200*0.7)
dat3e = rgeom(7000, 0.3)

p=1-(var(dat3b)/mean(dat3b))
n=mean(dat3b)/p


