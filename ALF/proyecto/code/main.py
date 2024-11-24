import sys
import re

import normalize
import sphone
import snif
import stime

phoneprog = re.compile("^[0-9]{3} [0-9]{3} [0-9]{3}$")
nifprog = re.compile("[0-9]{8}[A-Z]")
normdateprog = re.compile("[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}")

if (len(sys.argv) == 1):
    print("Argumentos incorrectos")
    exit(1)

if sys.argv[1] == "-n" and len(sys.argv) == 3:
    normalize.normalize(sys.argv[2])
elif sys.argv[1] == "-sphone":
    if (len(sys.argv) != 4):
        print("Faltan argumentos")
        exit(1)
    if (phoneprog.match(sys.argv[2]) == None):
        print("Telefono invalido")
        exit(1)
    sphone.sphone(sys.argv[3], sys.argv[2])
elif sys.argv[1] == "-snif":
    if (len(sys.argv) != 4):
        print("Faltan argumentos")
        exit(1)
    if (nifprog.match(sys.argv[2]) == None):
        print("NIF invalido")
        exit(1)
    snif.snif(sys.argv[3], sys.argv[2])
elif sys.argv[1] == "-stime":
    if (len(sys.argv) != 5):
        print("Faltan argumentos")
        exit(1)
    if (normdateprog.match(normalize.normalize_date(sys.argv[2])) or normdateprog.match(normalize.normalize_date(sys.argv[3])) == None):
        print("Fecha invalida")
        exit(1)
    stime.stime(sys.argv[4], normdateprog, normalize.normalize_date(sys.argv[2]), normalize.normalize_date(sys.argv[3]))
elif sys.argv[1] == "-slocation":
    exit(1)
else:
    print("Argumentos incorrectos")
    exit(1)

    
