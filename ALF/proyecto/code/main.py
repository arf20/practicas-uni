import sys
import re

import normalize
import sphone
import snif
import stime
import slocation

strippedphoneprog = re.compile("^[+]?\d{9,15}$")
nifprog = re.compile("[0-9]{8}[A-Z]")
normdateprog = re.compile("([0-9]{4})-([0-9]{2})-([0-9]{2}) ([0-9]{2}):([0-9]{2})")
normgeoprog = re.compile("^(\d{7}.\d{4}[NS])(\d{7}.\d{4}[WE])$")

def isnumeric(string):
    try:
        float(string)
        return True
    except ValueError:
        return False

if (len(sys.argv) == 1):
    print("Argumentos incorrectos")
    exit(1)

if sys.argv[1] == "-n" and len(sys.argv) == 3:
    normalize.normalize(sys.argv[2])
elif sys.argv[1] == "-sphone":
    if (len(sys.argv) != 4):
        print("Numero de argumentos invalido")
        exit(1)
    if (strippedphoneprog.match(normalize.normalize_phone(sys.argv[2])) == None):
        print("Telefono invalido")
        exit(1)
    sphone.sphone(sys.argv[3], normalize.normalize_phone(sys.argv[2]))
elif sys.argv[1] == "-snif":
    if (len(sys.argv) != 4):
        print("Numero de argumentos invalido")
        exit(1)
    if (nifprog.match(sys.argv[2]) == None):
        print("NIF invalido")
        exit(1)
    snif.snif(sys.argv[3], sys.argv[2])
elif sys.argv[1] == "-stime":
    if (len(sys.argv) != 5):
        print("Numero de argumentos invalido")
        exit(1)
    if (normdateprog.match(normalize.normalize_date(sys.argv[2])) == None or normdateprog.match(normalize.normalize_date(sys.argv[3])) == None):
        print("Fecha invalida")
        exit(1)
    stime.stime(sys.argv[4], normdateprog, normalize.normalize_date(sys.argv[2]), normalize.normalize_date(sys.argv[3]))
elif sys.argv[1] == "-slocation":
    if (len(sys.argv) != 5):
        print("Numero de argumentos invalido")
        exit(1)
    if (normgeoprog.match(normalize.normalize_coord(sys.argv[2])) == None or not isnumeric(sys.argv[3])):
        print("Coordenadas invalidas")
        exit(1)
    slocation.slocation(sys.argv[4], normgeoprog, normalize.normalize_coord(sys.argv[2]), sys.argv[3])
else:
    print("Argumentos invalidos")
    exit(1)

    
