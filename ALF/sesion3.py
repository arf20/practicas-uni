import random
import math

def genera_nif(n):
    nifs = list()
    for i in range(n):
        num = random.randint(0, 99999999)
        dni = ""
        if random.randint(0, 1) % 2:
            dni += str(random.randint(0, 2))
        dni += str()
        nifs.append(format(num, "08") + letra_nif(num))
    return nifs

def letra_nif(num):
    if len(str(num)) == 9:
        num = ((ord('X')-ord(num[0]))*100000000)+int(num[1:9])
    return "TRWAGMYFPDXBNJZSQVHLCKE"[num % 23]

def genera_tlf(n):
    tlfs = list()
    for i in range(n):
        num = random.randint(0, 999999999)
        num = format(num, "09")
        num = num[:3] + " " + num[3:6] + " " + num[6:]
        tlfs.append(num)
    return tlfs

def genera_tiempo(n):
    tiempos = list()
    for i in range(n):
        fmt = random.randint(1, 3)
        time = ""
        if (fmt == 1):
            time += str(random.randint(2000, 2024)) + "-"
            time += format(random.randint(1, 12), "02") + "-"
            time += format(random.randint(1, 28), "02") + " "
            time += format(random.randint(0, 23), "02") + ":"
            time += format(random.randint(0, 59), "02")
        if (fmt == 2):
            time += ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"][random.randint(0, 11)] + " "
            time += format(random.randint(1, 28), "02") + ", "
            time += str(random.randint(2000, 2024)) + " "
            time += format(random.randint(0, 11), "02") + ":"
            time += format(random.randint(0, 59), "02") + " "
            time += ["AM", "PM"][random.randint(0, 1)]
        if (fmt == 3):
            time += format(random.randint(0, 23), "02") + ":"
            time += format(random.randint(0, 59), "02") + ":"
            time += format(random.randint(0, 59), "02") + " "
            time += format(random.randint(1, 28), "02") + "/"
            time += format(random.randint(1, 12), "02") + "/"
            time += str(random.randint(2000, 2024))

        tiempos.append(str(time))
    return tiempos

def genera_coord(n):
    coords = list()
    for i in range(n):
        fmt = random.randint(1, 3)
        lat = random.uniform(-90, 90)
        long = random.uniform(-180, 180)
        latdir = "N"
        longdir = "W"
        if fmt == 1:
            coords.append(str(lat) + ", " + str(long) + "")
        if fmt == 2:
            if lat < 0:
                latdir = "S"
                lat *= -1
            if long < 0:
                longdir = "E"
                long *= -1
            latsex = str(math.floor(lat)) + "° "
            lat -= math.floor(lat)
            lat *= 60
            latsex += str(math.floor(lat)) + "' "
            lat -= math.floor(lat)
            lat *= 60
            latsex += str(math.floor(lat)) + "\" " + latdir

            longsex = str(math.floor(long)) + "° "
            long -= math.floor(long)
            long *= 60
            longsex += str(math.floor(long)) + "' "
            long -= math.floor(long)
            long *= 60
            longsex += str(math.floor(long)) + "\" " + longdir

            coords.append(latsex + ", " + longsex)
        if fmt == 3:
            if lat < 0:
                latdir = "S"
                lat *= -1
            if long < 0:
                longdir = "E"
                long *= -1
            latsex = "{:03d}".format(math.floor(lat))
            lat -= math.floor(lat)
            lat *= 60
            latsex += "{:02d}".format(math.floor(lat))
            lat -= math.floor(lat)
            lat *= 60
            latsex += "{:07.4f}".format(math.floor(lat)) + latdir

            longsex = "{:03d}".format(math.floor(long))
            long -= math.floor(long)
            long *= 60
            longsex += "{:02d}".format(math.floor(long))
            long -= math.floor(long)
            long *= 60
            longsex += "{:07.4f}".format(math.floor(long)) + longdir

            coords.append(latsex + longsex)
    return coords

def genera_producto(n):
    prods = list()
    for i in range(n):
        prods.append("CAT" + format(random.randint(0, 999999), "06"))
    return prods

def genera_precio(n):
    precios = list()
    for i in range(n):
        precios.append(str(random.randint(1, 9999)) + ".99€")
    return precios
    

tlfs = genera_tlf(10000)
nifs = genera_nif(10000)
tiempos = genera_tiempo(10000)
coords = genera_coord(10000)
prods = genera_producto(10000)
precios = genera_precio(10000)

file = open("compras.txt", "+w")
for i in range(10000):
    file.write(tlfs[i] + "; " + nifs[i] + "; " + tiempos[i] + "; " + coords[i] + "; " + prods[i] + "; " + precios[i] + ";\n")
file.close()


