# Submitear a mooshak

import requests
import magic

from bs4 import *


mime = magic.Magic(mime=True)


scheme = "https://"
host = "mooshak.inf.um.es"
endpoint = "/~mooshak/cgi-bin/execute/1883244818022123"

contest = "AED1_25_Practica"
user = "B117"
password = "u89t6w"
problem = "P004"

name = "G2 RUIZ FERNANDEZ, ANGEL"

url = scheme + host + endpoint

s = requests.Session() 
# all cookies received will be stored in the session object

# LOGIN
res = s.post(url, data={"command": "relogin", "arguments": "", "contest": contest, "user": user, "password": password})

print("LOGIN: " + str(res.status_code))
#print(res.text)
if res.status_code != 200:
    print("AUTH ERROR")
    exit

# set lines
res = s.post(url, data={"command": "listing", "problem": problem, "page": 0,
    "all_problems": "false", "all_teams": "false", "type": "submissions",
    "time": 5, "lines": 200})

print("LISTING COMMAND: " + str(res.status_code))
if res.status_code != 200:
    print("LISTING COMMAND ERROR")
    exit

res = s.get(url + "?listing")

print("LISTING: " + str(res.status_code))
if res.status_code != 200:
    print("LISTING ERROR")
    exit


soup = BeautifulSoup(res.text, "lxml")

submissions = list()
for row in soup.find_all("tr"):
    cols = list()
    for col in row.children:
        if col.name == "td" and col.text and col.text.strip():
            cols.append(col.text.strip())
            #print(col.text.strip() + " ", end="")
    submissions.append(cols)
    #print()
    

#submisions = list(filter(None, submisions))

print("SID   PID  NAME                                 STATUS")
print("======================================================")
for sub in submissions:
    if len(sub) > 0:
        print("{0: <5}".format(sub[0]) + " " + "{0: <4}".format(sub[3]) + " " + "{0: <35}".format(sub[2]) + ": " + sub[5])

#print(soup.find_all("tr"))
#print(res.text)

# LOGOUT
res = s.get(url + "?logout")
print("LOGOUT: " + str(res.status_code))
