#fnv hash sum

fnv_prime = 0x01000193
fnv_offset= 0x811C9DC5

def hash(word):
    # fnv hash function
    hash = fnv_offset
    for c in word:
        hash ^= ord(c)
        hash *= fnv_prime
        hash &= 0xffffffff
    hash = (hash >> 16) ^ (hash & 0x0000ffff)
    return hash

def main():
    print( hex(hash("a")),"\n" )
    print( hex(hash("aa")),"\n" )
    print( hex(hash("be")),"\n" )
    print( hex(hash("keith")),"\n" )


if __name__ == '__main__':
    main()     
            