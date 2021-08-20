#include <cstdlib>
#include <ios>
#include <iostream>
using namespace std;

int main()
{

    int d6,d20,d100;
    srand(101231);
    for(int i = 0; i < 1000; i++)
     {
        d6      = 1 + rand() % 6;
        d20     = 1 + rand() % 20;
        d100    = 1 + rand() % 100;
        cout.width(15);
        cout << d6;
        cout.width(15);
        cout << d20;
        cout.width(15);
        cout << d100;
        cout << endl;
     }
    return 0;
}
