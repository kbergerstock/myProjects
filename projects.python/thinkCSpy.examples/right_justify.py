def right_justify(szStr):
    sl = 70 - len(szStr)
    print(' '*sl,szStr)


def print_twice(szStr):
    print(szStr)
    print(szStr)


def do_twice(f,szStr):
    f(szStr)
    f(szStr)

do_twice(print_twice,"keith")