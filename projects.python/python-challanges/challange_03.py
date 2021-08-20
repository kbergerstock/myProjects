# python template
# k. r. bergerstock

#imports
import random
import os

def histogram(s):
    d = dict()
    for c in s:
        d[c] = 1 + d.get(c,0)
    return d
    
def print_hist(d):
    dl = []
    dl = d.keys()
    for c in dl:
        print(c,d[c])
        
def get_rare(data,d):
    s = ''
    o = dict()
    for key in d.keys():
        if d[key] == 1:
            k = data.find(key)
            o[k] = key
            
    for key in sorted(o.keys()):
        s = s + o[key]
        
    return s            
  
        
# main if used     
def main():
    path = 'c:\\projects\\python\\c3data.bin'
    try:
        f = open(path,'r')
        data = f.read();
        f.close()
        h = histogram(data)    
        print_hist(h)
        print(get_rare(data,h))
    except:
        print(__traceback__)        
    
if __name__ == '__main__':
    main()

#answer    
#    equality

# http://www.pythonchallenge.com/pc/def/equality.html