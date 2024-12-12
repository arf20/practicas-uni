def snif(fname, nif):
    file = open(fname, "r")
    for line in file:
        if line == "\n":
            continue

        if nif in line:
            print(line, end='')
    file.close()
