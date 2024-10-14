# Submitear a mooshak

import requests
import magic

mime = magic.Magic(mime=True)


scheme = "https://"
host = "mooshak.inf.um.es"
endpoint = "/~mooshak/cgi-bin/execute/8304314929202345"

contest = "AED1_25_Practica"
user = "B117"
password = "u89t6w"
problem = "P004"
filename = "buscador.tar"

url = scheme + host + endpoint
#url = "http://arf20.com"

s = requests.Session() 
# all cookies received will be stored in the session object

# LOGIN
res = s.post(url, data={"command": "relogin", "arguments": "", "contest": contest, "user": user, "password": password})

print("LOGIN: " + str(res.status_code))

if res.status_code != 200:
    print("AUTH ERROR")
    exit

#print(s.cookies)

payload = {
    "command": (None, "analyze"),
    "problem": (None, problem),
    "program": (filename, open(filename, "rb"), mime.from_file(filename)),
    "analyze": (None, "Submit")
}
# SUBMISSION
res = s.post(url, files=payload)

print("SUBMISSION: " + str(res.status_code))

if res.status_code != 200 or "Submission received" not in res.text:
    print("SUBMIT ERROR: " + res.text)
else:
    print("SUCCESS")
