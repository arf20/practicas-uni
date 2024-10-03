import random
import sys

def letra(num):
    if len(str(num)) == 9:
        num = ((ord('X')-ord(num[0]))*100000000)+int(num[1:9])
    return "TRWAGMYFPDXBNJZSQVHLCKE"[num % 23]

def valida(dni):
    return letra(int(dni[0:len(dni)-1])) == dni[len(dni)-1]

def genera(n):
    nifs = list()
    for i in range(n):
        num = random.randrange(0, 99999999)
        dni = ""
        if random.randint % 2:
            dni += str(random.randrange(0, 2))
        dni += str()
        nifs.append(format(num, "08") + letra(num))
    return nifs

dni = "Z12345678"
print(dni + ": " + letra(dni) + "\n")


nifs = genera(int(sys.argv[1]))
for i in range(int(sys.argv[1])):
    print(nifs[i] + ": " + str(valida(nifs[i])))

