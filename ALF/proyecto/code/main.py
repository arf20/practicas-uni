import sys

import normalize

if (len(sys.argv) == 1):
    print("Argumentos incorrectos")
    exit(1)

if sys.argv[1] == "-n" and len(sys.argv) == 3:
    normalize.normalize(sys.argv[2])
elif sys.argv[1] == "-sphone":
    exit(1)
elif sys.argv[1] == "-snif":
    exit(1)
elif sys.argv[1] == "-stime":
    exit(1)
elif sys.argv[1] == "-slocation":
    exit(1)
else:
    print("Argumentos incorrectos")
    exit(1)

    
