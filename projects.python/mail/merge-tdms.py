#merge pgn files 
#k.r.bergerstock

#imports
import os


def  process_file(fn, path):
    #reads file
    print(path)
    f = open(path,mode = 'rb')
    print('read')
    bytes = f.read()
    print('write')
    fn(bytes)
    f.close()

def walk(fn,dir):
    for name in os.listdir(dir):
        path = os.path.join(dir,name)
        # add a check her to ensure that it is a pgn file
        if  not ('index' in path):
            process_file(fn,path)

def main():
    path = 'K:\\m1.data\\temp\\tdms2013'
    save_path = 'K:\\m1.data\\temp'
    mTDMS = os.path.join(save_path,'mrg_m1_2013_data.tdms')
    try:
        fout = open(mTDMS,mode = 'wb')
        walk(fout.write,path)
        fout.close()
    except:
        print('oops')
    print('done')

if __name__ == '__main__':
    main()
