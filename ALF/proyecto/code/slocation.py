import re
import math

def sextodec(geo3prog, deg, min, sec):
    min = min + int(sec) / 60
    sec = sec % 60
    deg = deg + int(min) / 60
    min = min % 60
    dfrac,  dint = math.modf(deg)
    min = min + dfrac * 60
    deg = dint
    mfrac,  mint = math.modf(min)
    sec = sec + mfrac * 60
    min = mint
    return sec

def coordtofloat(gps):
    lat = sextodec(float(gps[0:2]), float(gps[3:4]), float(gps[5:11]))
    if (gps[12] == "S"):
        lat = -lat
    lon = sextodec(float(gps[12:15]), float(gps[16:17]), float(gps[18:24]))
    if (gps[25] == "S"):
        lon = -lon

    return lat, lon

def sloaction(fname, orggps, range):
    file = open(fname, "r")

    for line in file:
        locgps = line.split(";")[3]
        if re.match(orggps, locgps) == None or len(locgps) != 25:
            continue

        loc = coordtofloat(locgps)
        





    file.close()
