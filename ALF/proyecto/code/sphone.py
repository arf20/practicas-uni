def sphone(fname, phone):
    stripfilter = phone.replace(" ", "")
    if stripfilter[0] != "+":
        stripfilter = "+34" + stripfilter

    file = open(fname, "r")
    for line in file:
        stripnum = line.split(";")[0].replace(" ", "")
        if stripnum[0] != "+":
            stripnum = "+34" + stripnum

        if stripfilter == stripnum:
            print(line, end='')
    file.close()
