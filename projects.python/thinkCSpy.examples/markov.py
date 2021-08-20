#krb
#markov analysis

# step 1 create a word list from a file

def  read_words(word_list, file):
    #reads file and stores in a buffer
    f = open(file)
    for line in f:
        word_list.extend(line.split())
    f.close()
    
def main():
    wl = []        # empty word list
    
    path = 'c:\\projects\\python\\alpha-beta.txt'
    read_words(wl,path)
        
if __name__ == '__main__':
    main()    