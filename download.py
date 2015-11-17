import os
import requests
import urllib2
import sys
import codecs
from bs4 import BeautifulSoup
url = "https://www.youtube.com"
ext = "/results?search_query="
query = sys.argv[1]
name = query.replace("+","_")
a = urllib2.urlopen(url+ext+query).read()
soup = BeautifulSoup(a)
for i in soup.findAll("a",{"class":"yt-uix-sessionlink yt-uix-tile-link yt-ui-ellipsis yt-ui-ellipsis-2       spf-link "}):
    link =  url+i["href"]
    break
print "This is The link"+link
os.system('youtube-dl -o "'+name+'.m4a" --extract-audio '+link)
if(len(sys.argv) == 3):
  if(sys.argv[2] == "play"):
    os.system("mplayer "+name+".m4a")
