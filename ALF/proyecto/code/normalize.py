import re
import math

months = ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"]

date2prog = re.compile("([a-zA-Z]+) ([0-9]{2}), ([0-9]{4}) ([0-9]{2}):([0-9]{2}) (AM|PM)")
date3prog = re.compile("([0-9]{2}):([0-9]{2}):([0-9]{2}) ([0-9]{2})\/([0-9]{2})\/([0-9]{4})")
geo2prog  = re.compile("(\d*)\° (\d*)\' (\d*)\" ([NS]), (\d*)\° (\d*)\' (\d*)\" ([WE])")
geo1prog  = re.compile("([+-]?\d*\.\d+), ([+-]?\d*\.\d+)")

def normalize_date(line):
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

        return line.replace(line[m.start():m.end()], newdate)

    m = re.search(date3prog, line)
    if (m != None):
        grps = m.groups()

        newdate = grps[5] + "-" + grps[4] + "-" + grps[3] + " " + grps[0] + ":" + grps[1]

        return line.replace(line[m.start():m.end()], newdate)

    return line





def normalize(fname):
    file = open(fname, "r")
    
    for line in file:
        line = normalize_date(line)

        m = re.search(geo2prog, line)
        if (m != None):
            grps = m.groups()
            
            gps =  "{:03d}".format(int(grps[0])) + "{:02d}".format(int(grps[1]))
            gps += "{:07.4f}".format(float(grps[2])) + grps[3]
            gps += "{:03d}".format(int(grps[4])) + "{:02d}".format(int(grps[5]))
            gps += "{:07.4f}".format(float(grps[6])) + grps[7]

            line = line.replace(line[m.start():m.end()], gps)

        m = re.search(geo1prog, line)
        if (m != None):
            grps = m.groups()
            lat = float(grps[0])
            lon = float(grps[1])
            latdir = "N"
            londir = "W"
            if lat < 0:
                latdir = "S"
                lat *= -1
            if lon < 0:
                londir = "E"
                lon *= -1
            gps  = "{:03d}".format(math.floor(lat))
            lat -= math.floor(lat)
            lat *= 60
            gps += "{:02d}".format(math.floor(lat))
            lat -= math.floor(lat)
            lat *= 60
            gps += "{:07.4f}".format(math.floor(lat)) + latdir

            gps  += "{:03d}".format(math.floor(lon))
            lon  -= math.floor(lon)
            lon  *= 60
            gps  += "{:02d}".format(math.floor(lon))
            lon  -= math.floor(lon)
            lon  *= 60
            gps  += "{:07.4f}".format(math.floor(lon)) + londir

            line = line.replace(line[m.start():m.end()], gps)

        print(line, end='')
    file.close()

