import normalize

def sphone(fname, phone):
    filter = normalize.normalize_phone(phone)

    file = open(fname, "r")
    for line in file:
        if line == "\n":
            continue

        num = normalize.normalize_phone(line.split(";")[0])
        if filter in num:
            print(line, end='')
    file.close()
