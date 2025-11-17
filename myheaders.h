// DO NOT forget to add the prototypes for your ASort, BSort, and other functions below!


#include <string>
#include <unistd.h>
#define MAXSIZE	 2100000
///#define MAXSIZE 10000
using namespace std;

void	printmenu();
void	printarray(long data[], long size);
int		readfile(string infilename, long data[]);
int		writefile(long data[], long size, string outfilename);
void	swap(long& x, long& y);

//sorts
void Bubblesort(long arr[], int n);
void Combsort(long arr[], int n);
void Selectionsort(long arr[], int n);
void Countingsort(long arr[], int n);
void Radixsort(long arr[], int n);
void countSort(long arr[], int n, long exp); //radix helper
long getMax(long arr[], int n); //radix helper

void Shellsort(long arr[], int n);
