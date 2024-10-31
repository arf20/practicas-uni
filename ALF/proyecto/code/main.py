import sys
import re

import normalize
import sphone

phoneprog = re.compile("^[0-9]{3} [0-9]{3} [0-9]{3}$")

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
        print("No es telefono")
        exit(1)
    sphone.sphone(sys.argv[3], sys.argv[2])
elif sys.argv[1] == "-snif":
    exit(1)
elif sys.argv[1] == "-stime":
    exit(1)
elif sys.argv[1] == "-slocation":
    exit(1)
else:
    print("Argumentos incorrectos")
    exit(1)

    
