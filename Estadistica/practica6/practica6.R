# 1.
# a.
sample(c("cara", "cruz"), 1)
# b.
sample(c(1, 2, 3, 4, 5, 6), 1)
# c.
sample(c("cara", "cruz"), prob = c(0.4, 0.6), 1)
# d.
exp = sample(c("cara", "cruz"), prob = c(0.4, 0.6), replace = TRUE, 1000)
ni = table(exp)
fi = table(exp)/length(exp)
fi

# 2.
# a.
# 1/3*(2/6+5/7+4/7) = 0.5396
# b.
urnas = list(c(rep("R", 2), rep("B", 4)), c(rep("R", 5), rep("B", 2)), c(rep("R", 4), rep("B", 3)))
sample(sample(urnas, 1)[[1]], 1)
# c.
exp = sample(sample(urnas, 1)[[1]], replace = TRUE, 10000)
table(exp)/length(exp)
# d.
P2R_U1<-1/choose(6,2)
P2R_U2<-choose(5,2)/choose(7,2)
P2R_U3<-choose(4,2)/choose(7,2)
P2R<-1/3*P2R_U1+1/3*P2R_U2+1/3*P2R_U3

cf = 0
n = 10000
for (i in 1:n) {
  if (identical(sample(sample(urnas, 1)[[1]], replace = TRUE, 2), c("R", "R"))) {
    cf = cf + 1
  }
}
Pd = cf/n

# 4
# a.
P = (choose(4,2)*5*4*21*20)/(26*25*24*23)
# b.
c(sample(letters, replace=FALSE, 4), sample(0:9, replace=TRUE, 3))
# c.
vocales = c("a", "e", "i", "o", "u")
t = 0
n = 100000
for (i in 1:n) {
  pw = c(sample(letters, replace=FALSE, 4), sample(0:9, replace=TRUE, 3))
  v = 0
  for (j in 1:4)
    if (pw[j] %in% vocales) v = v + 1
  if (v == 2) t = t + 1
}
t/n

# 5
# a.
P = 0.3 * choose(10, 6) * factorial(6) / 10^6 + 0.7 * choose(10, 7) * factorial(7) / 10^7
# b.
# distintos
sample(0:9, sample(c(6, 7), prob = c(0.3, 0.7), 1))
# repes
sample(0:9, sample(c(6, 7), prob = c(0.3, 0.7), 1), replace = TRUE)
# c.
n = 10000
v = 0
for (i in 1:n) {
  num = sample(0:9, sample(c(6, 7), prob = c(0.3, 0.7), 1), replace = TRUE)
  if (length(num) == length(unique(num))) v = v + 1
}
v/n