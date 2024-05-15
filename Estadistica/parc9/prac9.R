# 1.
# 1: binom
p = 1-(var(dat1)/mean(dat1))
n = mean(dat1)/p
# 2: uniform
a = (2*mean(dat2)-sqrt(12)*sd(dat2))/2
b = (2*mean(dat2)+sqrt(12)*sd(dat2))/2
# 3: exponencial
lambda = 1/mean(dat3)
# 4: normal
u = mean(dat4)
s = sd(dat4)

Q1 = quantile(dat4, Q)
Q2 = qnorm(Q, u, s)
plot(Q1, Q2)
abline(0, 1)
