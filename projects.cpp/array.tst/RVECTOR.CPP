#define STRICT
#define WIN32_LEAN_AND_MEAM
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "tArray.h"


class rVector 
{
	private:
        f64ARRAY vector;    
    public:
    	rVector(IDX nElem = 1000) : vector(nElem)
        {
        	srand(19);
        	for(IDX i = 0 ; i < nElem; i++)
             {
                vector[i] = rand() / double(RAND_MAX);
             }
        };

        inline double operator[](IDX i) { return vector[i]; }
        inline IDX len(){return vector.Size();}

		void Swap(IDX i, IDX j)
         {
         	double tmp = vector[i];
            vector[i] = vector[j];
            vector[j] = tmp;
         };

		long Random(IDX i,IDX  j)
         {
            IDX n = i < j ? j - i: i - j ;
            return i + (rand() % n);
         }
};

void quicksort(rVector &v, IDX left, IDX right)
{
	if(left >= right)
    	return;

	IDX last = left;
    IDX pivot = v.Random(left,right);
    v.Swap(left, pivot);
    for(IDX i = left+1 ; i < right; i++)
    	if(v[i] < v[left])
        	v.Swap(++last,i);

	v.Swap(left,last);
    quicksort(v,left,last);
    quicksort(v,last+1,right);
}

void bubblesort(rVector &v)
{
	IDX l = v.len();
	for(IDX i = 0; i < l; i++)
    	for(IDX j = i+1; j < l; j++)
        	if(v[i] > v[j])
            	v.Swap(i,j);
}

void onePass(std::ofstream &out, unsigned int  nElem)
{
	unsigned int s, e;
    unsigned int tFill,tqSort,tbSort;
    bool isok = true;

    s = GetTickCount();
	rVector qTest(nElem);
    rVector bTest(qTest);
    e = GetTickCount();
    tFill = e - s;

	s = GetTickCount();
    bubblesort(bTest);
    e = GetTickCount();
    tbSort = e - s;

	s = GetTickCount();
    quicksort(qTest,0,qTest.len() );
    e = GetTickCount();
    tqSort = e - s;

    std::cout << "Time To Fill Array "<< (std::dec) << tFill << " milliseconds " << std::endl;
    std::cout << "Time To quick sort Array "<< (std::dec) << tqSort << " milliseconds of " <<  qTest.len() << " elements "<< std::endl;
    std::cout << "Time To bubble sort Array "<< (std::dec) << tbSort << " milliseconds of " << bTest.len() << " elements "<< std::endl;

    for(unsigned int i = 0; i < qTest.len() && isok == true; i++)
    	isok &= ((qTest[i]) == (bTest[i]));

    if(isok)
    	std::cout << " the sorted arrays are identical " << std::endl;
	else
    	std::cout << " ERR ERR -- the sorted arrays do not MATCH - ERR ERR " << std::endl;

	out << (std::dec) << nElem << "," << tFill << "," << tbSort << "," << tqSort << "," << isok << std::endl;
}

void main(void)
{
	ofstream ofile("RESULTS.TXT");
	for(int i = 0; i < 50; i++)
     	onePass(ofile,1500 + (i*1000) );
}

