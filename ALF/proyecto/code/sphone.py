def sphone(fname, phone):
    file = open(fname, "r")
    for line in file:
        if phone in line:
            print(line, end=None)
    file.close()
