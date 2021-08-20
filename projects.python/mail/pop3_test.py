# POP3 reader function to read verion.net email
# pop3 test function
# k.r.bergerstock @09/2016

import poplib

def main():

    data = []
    
    out = open("c:\pl\mail.txt","w")
    
    
    Mail = poplib.POP3('pop.verizon.net')
    Mail.user('kbergerstock@verizon.net')
    Mail.pass_('z86n7kh0')
    
    cnt,size = Mail.stat() 
    print("count ",cnt)
    print("size  ",size)
    
    data = Mail.list()
    numMsgs = len(Mail.list()[1])
  
    for i in range(numMsgs):
        for j in Mail.retr(i+1)[1]:
            print(j)
            #out.write(j)
    
    Mail.quit()
    
        
if __name__ == '__main__':
    main()            

