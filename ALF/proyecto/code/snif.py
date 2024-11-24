def snif(fname, nif):
    file = open(fname, "r")
    for line in file:
        if nif in line:
            print(line, end=None)
    file.close()
