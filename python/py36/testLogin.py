import requests
from bs4 import BeautifulSoup
import bs4


def getGTMLText(url):
    try:
        r = requests.get(url, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""


def login(url, usr, psw):
    s = requests.Session()
    s.post(url, {
        "username": usr,
        "password": psw,
    })
    r = s.get(url)
    return r


a = input()
b = input()
url = "http://cas.whu.edu.cn/authserver/login?service=http://my.whu.edu.cn"
print(login(url, a, b).text)
