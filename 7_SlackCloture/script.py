import requests
from datetime import datetime
from time import strftime

url = ''
data = {"text":"Hello, World!"}
try:
    r = requests.post(url, json=data)
except ImportError:
    print("KO")
print(r.status_code)

time = strftime('%Y-%m-%d %H:%M:%S', datetime.now())
print(time)
