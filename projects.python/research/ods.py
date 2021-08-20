# ods for python
# k.r.bergerstock

import ctypes
kernel32 = ctypes.windll.kernel32

def odsW(szBuffer):
    # output debug string multibyte - matches python defaults
    kernel32.OutputDebugStringW(szBuffer)

def odsA(szBuffer):
    #output debug string ascii
    kernel32.OutputDebugStringA(szBuffer)    
    
def main():
    odsW("this is a test")
    odsW("this is not a good test")
    odsW("but never the less , this is a test")
    

if __name__ == '__main__':
    main()    
    
