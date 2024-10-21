import re 

def gettlf(str):
    return re.findall("[0-9]{3} [0-9]{3} [0-9]{3}", str)[0]

def letra(num):
    if len(str(num)) == 9:
        num = ((ord('X')-ord(num[0]))*100000000)+int(num[1:9])
    return "TRWAGMYFPDXBNJZSQVHLCKE"[num % 23]

def validanif(nif):
    return letra(int(nif[0:len(nif)-1])) == nif[len(nif)-1]

def getnif(str):
    return re.findall("[0-9]{8}[A-Z]", str)[0]

def gettime(str):
    strs = re.search("([0-9]{4})-([0-9]{2})-([0-9]{2}) ([0-9]{2}):([0-9]{2}):([0-9]{2})", str).groups()
    nums = list()
    for s in strs:
        nums.append(int(s))
    return nums

def validatime(list):
    return list[1] > 0 and list[1] <= 12 and list[2] > 0 and list[2] <= 31 and list[3] >= 0 and list[3] <= 23 and list[4] >= 0 and list[4] <= 59 and list[5] >= 0 and list[5] <= 59

def getcoord(str):
    strs = re.search("([+-]?\d*\.\d+), ([+-]?\d*\.\d+)", str).groups()
    return [float(strs[0]), float(strs[1])]

def validacoord(list):
    return list[0] > -90 and list[0] < 90 and list[1] > -180 and list[1] < 180

print(gettlf("kahdsad123 456 789isfdh98"))
print(validanif(getnif("983hfq98323836363Zsdqes2")))
print(validatime(gettime("123142005-11-29 14:59:59u3qr3iuf")))
print(validacoord(getcoord("o83f9832fh1.2434, -37.8179187319847284732498322638eufiewugmi73q")))
