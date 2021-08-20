// hello world in cpp
#include <iostream>
using namespace std;

class cHW
{
    private:
    public:
    cHW(){
        cout<< "Hello Word" << endl << 
        "     what a beautiful day" << endl;
    }
    ~cHW(){
        cerr << "    War is horrible" << endl <<
        "goodby cruel world" << endl;
    }

};

int main(){
    cHW hw;
    return 0;
}