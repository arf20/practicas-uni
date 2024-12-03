import re
import math

import normalize

def sextodec(deg, min, sec):
    return (sec + min * 60 + deg * 3600)/3600

def coordtofloat(gps):
    lat = sextodec(float(gps[0:2]), float(gps[3:4]), float(gps[5:11]))
    if (gps[12] == "S"):
        lat = -lat
    lon = sextodec(float(gps[13:16]), float(gps[17:18]), float(gps[19:25]))
    if (gps[25] == "S"):
        lon = -lon

    return lat, lon

def distance(lat1, lon1, lat2, lon2):
    lat1 = math.radians(lat1)
    lon1 = math.radians(lon1)
    lat2 = math.radians(lat2)
    lon2 = math.radians(lon2)
    dlat = lat2 - lat1
    dlon = lon2 - lon1
    a = math.sin(dlat/2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon/2)**2
    c = 2 * math.atan2(math.sqrt(a),  math.sqrt(1-a))
    return 6371 * c


def slocation(fname, normgeoprog, orggps, range):
    file = open(fname, "r")

    orggps = normalize.normalize_coord(orggps)

    if re.match(normgeoprog, orggps) == None or len(orggps) != 26:
        print("Invalid location argument")
        return
    
    org = coordtofloat(orggps)
    range = float(range)

    for line in file:
        linenorm = normalize.normalize_coord(line)
        locgps = linenorm.split(";")[3].strip()
        if re.match(normgeoprog, locgps) == None or len(locgps) != 26:
            continue

        loc = coordtofloat(locgps)
        
        d = distance(loc[0], loc[1], org[0], org[1])

        if d < range:
            print(line, end='')

    file.close()
