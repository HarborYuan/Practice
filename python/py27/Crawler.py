#coding=utf-8
import urllib
import re
weba="http://ymj.qcpai.com/wwtstudentcard/Web/public/appupload/10486/big/"
def getHtml(url):
    page = urllib.urlopen(url)
    html = page.read()
    return html
def getImg(html):
    reg = r"\d{13}\.jpg"
    imgre = re.compile(reg) 
    imglist = re.findall(imgre,html)
    for imgurl in imglist:
        urllib.urlretrieve(weba+imgurl,imgurl)
html = getHtml(weba)
getImg(html)
