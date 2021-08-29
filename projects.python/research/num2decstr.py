#num2decstr.py

def num2decstr(n):
    s = ''
    i = 0
    while n > 0:
        d = n % 10
        n = n // 10
        s.join(d | 0x30)
        i+=1
    return s.reverse()    



s = num2decstr(503)
print("503  , ",s)
