#chapter 9 examples list/string
# chop, mid and is-sorted, has_duplicates

def chop(t):
    l = len(t) - 1
    del t[l]
    del t[0]

def mid(t):
    l = len(t) - 1
    return t[1:l]


def is_sorted(t):
    for i in range((len(t)-1)):
        if t[i] > t[i+1]:
            return False
    return True


def has_duplicates(t):
    k=t[:]
    k.sort()
    for i in range((len(k)-1)):
        if k[i] == k[i+1]:
            return True
    return False


def main():
    r = [9,8,7,6,5,4,3,2,1]
    w=['this','is','a','test']
    b =[23,45,67,78,89,90,100,123,124,23]

    print(mid(r))
    print(mid(w))

    print(r)
    print(w)

    print(is_sorted(r))
    print(is_sorted([1,2,2]))
    print(is_sorted(['b','a']))

    print(b,is_sorted(b))
    print(mid(b),is_sorted(mid(b)))

    print(has_duplicates(r))
    print(has_duplicates(w))
    print(has_duplicates(b))
    print(has_duplicates(r+r))


if __name__ == '__main__':
    main()
