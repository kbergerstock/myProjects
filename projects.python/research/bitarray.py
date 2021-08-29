# bitarray.py
import numpy as np

def setZ(ba,ndx):
    i  = ndx >> 3
    m = np.array([(1<<(ndx & 0x07))],dtype=np.uint8)
    ba[i] |= m[0]

def bitarray(_size):
    print(_size)
    return np.zeros((_size,),dtype=np.uint8)

def main():
    pl = 1000000
    _bit_array = bitarray(pl//8)
    print(_bit_array.size,_bit_array.itemsize)
    setZ(_bit_array,4)
    setZ(_bit_array,995)
    setZ(_bit_array,16)
    print(_bit_array)


if __name__ == "__main__":
    main()
