import re

months = ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"]

def normalize(fname):
    date2prog = re.compile("([a-zA-Z]+) ([0-9]{2}), ([0-9]{4}) ([0-9]{2}):([0-9]{2}) (AM|PM)")
    date3prog = re.compile("([0-9]{2}):([0-9]{2}):([0-9]{2}) ([0-9]{2})\/([0-9]{2})\/([0-9]{4})")

    file = open(fname, "r")
    for line in file:
        m = re.search(date2prog, line)
        if (m != None):
            grps = m.groups()

            newdate = grps[2] + "-"
            newdate += "{:02d}".format(months.index(grps[0]) + 1) + "-"
            newdate += grps[1] + " "
            if (grps[5] == "AM"):
                newdate += str(grps[3]) + ":"
            else:
                newdate += str(int(grps[3]) + 12) + ":"
            newdate += grps[4]

            line = line.replace(line[m.start():m.end()], newdate)

        m = re.search(date3prog, line)
        if (m != None):
            grps = m.groups()

            newdate = grps[5] + "-" + grps[4] + "-" + grps[3] + " " + grps[0] + ":" + grps[1]
            line = line.replace(line[m.start():m.end()], newdate)

        print(line, end='')
    file.close()

