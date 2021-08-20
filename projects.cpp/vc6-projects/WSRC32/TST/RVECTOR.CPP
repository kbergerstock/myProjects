#define STRICT
#define WIN32_LEAN_AND_MEAM
#include <windows.h>
#include <mmsystem.h>
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include "array.h"

class rVector  : public  ArrayDb
{
	private:

    public:
    	rVector(long nElem = 1000) : ArrayDb(nElem)
        {
        	randomize();
        	for(int i = 0 ; i < size; i++)
             {
                arr[i] = rand() / double(RAND_MAX);
             }
        };

		void Swap(long i, long j)
         {
         	double tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
         };

		long Random(long i, long j)
         {
         	long n = abs(j-i);
            return i + (rand() % n);
         }
};

void quicksort(rVector &v, long left, long right)
{
	if(left >= right)
    	return;

	long last = left;
    long pivot = v.Random(left,right);
    v.Swap(left, pivot);
    for(long i = left+1 ; i < right; i++)
    	if(v[i] < v[left])
        	v.Swap(++last,i);

	v.Swap(left,last);
    quicksort(v,left,last);
    quicksort(v,last+1,right);
}

void bubblesort(rVector &v)
{
	long l = v.ArSize();
	for(long i = 0; i < l; i++)
    	for(long j = i+1; j < l; j++)
        	if(v[i] > v[j])
            	v.Swap(i,j);
}

void onePass(ofstream &out, int  nElem)
{
	DWORD s,e;
    DWORD tFill,tqSort,tbSort;
    int isok = true;

    s = GetTickCount();
	rVector qTest(nElem);
    e = GetTickCount();
    tFill = e - s;

    rVector bTest = qTest;

	s = GetTickCount();
    bubblesort(bTest);
    e = GetTickCount();
    tbSort = e - s;

	s = GetTickCount();
    quicksort(qTest,0,qTest.ArSize() );
    e = GetTickCount();
    tqSort = e - s;

    cout << "Time To Fill Array "<< (dec) << tFill << " milliseconds " << endl;
    cout << "Time To quick sort Array "<< (dec) << tqSort << " milliseconds of " <<  qTest.ArSize() << " elements "<< endl;
    cout << "Time To bubble sort Array "<< (dec) << tbSort << " milliseconds of " << bTest.ArSize() << " elements "<< endl;

    for(unsigned long i = 0; i < qTest.ArSize() && isok == true; i++)
    	isok &= (qTest[i] == bTest[i]);

    if(isok)
    	cout << " the sorted arrays are identical " << endl;
	else
    	cout << " ERR ERR -- the sorted arrays do not MATCH - ERR ERR " << endl;

	out << (dec) << nElem << "," << tFill << "," << tbSort << "," << tqSort << "," << isok << endl;
}

void main(void)
{
	ofstream ofile("RESULTS.TXT");
	for(int i = 0; i < 50; i++)
     	onePass(ofile, 500 + (i*500) );
}

