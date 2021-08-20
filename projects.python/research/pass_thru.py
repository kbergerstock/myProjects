# python template
# k. r. bergerstock

#imports
import sys
from ods import odsW

     
# main if used     
def main():
    odsW("press enter to exit")
    sys.stdin.readline()
    odsW("exiting spawned process")
    quit()
 
if __name__ == '__main__':
    main()