import requests
import re
from bs4 import BeautifulSoup
import urllib
import os

def Path(path):
    if not os.path.isdir(path):
        os.mkdir(path)

def getHTML(url):
    try:
        r=requests.get(url)
        r.raise_for_status()
        return r
    except:
        return ""

def getHTMLText(url):
    try:
        kv={"user-agent":"Mozilla/5.0"}
        r=requests.get(url)
        r.raise_for_status()
        r.encoding=r.apparent_encoding
        return r.text
    except:
        return ""

def Find(html):
    return re.findall(r'"objURL":"(.*?)"', html)

def Down(urls):
    index=1
    for url in urls:
        res=getHTML(url)
        if (res==""):
            continue
        filename=os.path.join(path,str(index)+".jpg")
        with open(filename,'wb') as f:
            f.write(res.content)
            index+=1
        print("第",index-1,"张图片已下载成功")

url=r"http://image.baidu.com/search/index?tn=baiduimage&ie=utf-8&word="
path=r"D:\img"
Path(path)

keyword=input("请输入关键字\n")
word=urllib.parse.quote(keyword)

html=getHTMLText(url+word)

urllist=Find(html)
Down(urllist)
