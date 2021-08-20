# python test file for json files
# k.r.bergerstock

import sys
import os
import json

def readCfg(fileName):
    try:
        jf = open(fileName,'r')
        cfg = json.load(jf)
        jf.close()
    except OSError as err:
        print("file exception {0}".format(err))
        exit(-2)
    return cfg

def main(argv):
      
    if len(argv) < 2:
        print("missing file parameter")
        exit(-1)
        
    cfg = readCfg(argv[1])
    db = cfg['database']
    print(db)
    for item in db:
        print(item,db[item])

    db['username'] = 'krbergerstock'
    try:
        jf = open(argv[1],'w')
        json.dump(cfg,jf)
        jf.close()
    except OSError as err:
        print("file exception {0}".format(err))
        exit(-3)    
    return 0
    
if __name__ == '__main__':
    main(sys.argv)