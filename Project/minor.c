#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <sys/time.h>
#include <fstream>
#include <math.h>

using namespace std;
 
int* b;
bool odd;
bool enablePrinting=false;
struct SortingAlgorithm{
    string name;
    long long time;
    void (*algorithm)(int*,int);
};
//Selection Sort
void selectionSort(int* a, int size)
{
    for (int i = 2; i < size; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
}
/////////////////////////////
 
//Insertion Sort
void insertionSort(int* a, int size)
{
    for (int i = 1;i < size;i++)
    {
        int x = a[i];
        int j = i;
        while (j > 0 && a[j-1] > a[j])
        {
            int temporaryVariable=a[j];
            a[j] = a[j-1];
            a[j-1]=temporaryVariable;
            j --;
        }
        a[j] = x;
    }
}
/////////////////////////////
//Merge Sort
void merge(int* a, int first, int middle, int last)
{
    int j,i0,i1;
    i0 = first;
    i1 = middle;
 
    // While there are elements in the left or right runs
     
    for (j = first; j < last; j++) {
        // If left run head exists and is <= existing right run head.
        if (i0 < middle && (i1 >= last || a[i0] <= a[i1])){
            b[j] = a[i0];
            i0++;
        }
        else{
            b[j] = a[i1];
            i1++;
        }
    } 
     
}
///////////////////////////////
//Bubble Sort
void bubbleSort(int* a, int size) {
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < size - j; i++) {
                  if (a[i] > a[i + 1]){
                        tmp = a[i];
                        a[i] = a[i + 1];
                        a[i + 1] = tmp;
                        swapped = true;
                  }
            }
      }
}
//////////////////////////////////
//Quick Sort
 
int partition(int* a, int top, int bottom)
{
     int x = a[top];
     int i = top - 1;
     int j = bottom + 1;
     int temp;
     do
     {
           do    
           {
                  j--;
           }while (x >a[j]);
 
          do 
         {
                 i++;
          } while (x <a[i]);
 
          if (i < j)
         { 
                 temp = a[i];   
                 a[i] = a[j];
                 a[j] = temp;
         }
     }while (i < j);    
     return j;           
}
 
void _quickSort(int * a, int top, int bottom)
{
     int middle;
     if (top < bottom)
    {
          middle = partition(a, top, bottom);
          _quickSort(a, top, middle); 
          _quickSort(a, middle+1, bottom);   
     }
     return;
}
 
 
 
void quickSort(int * a, int size)
{
     _quickSort(a,0,size);
     return;
}
 
///////////////////////////////////////////////////////
//HEAPSORT
struct MaxHeap
{
    int size;
    int* a;
};

// A utility function to swap to integers
void swap(int* x, int* y) { int t = *x; *x = *y;  *y = t; }

// The main function to heapify a Max Heap. The function
// assumes that everything under given root (element at
// index idx) is already heapified
void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
    int largest = idx;  // Initialize largest as root
    int left = (idx << 1) + 1;  // left = 2*idx + 1
    int right = (idx + 1) << 1; // right = 2*idx + 2

    // See if left child of root exists and is greater than
    // root
    if (left < maxHeap->size &&
        maxHeap->a[left] > maxHeap->a[largest])
        largest = left;

    // See if right child of root exists and is greater than
    // the largest so far
    if (right < maxHeap->size &&
        maxHeap->a[right] > maxHeap->a[largest])
        largest = right;

    // Change root, if needed
    if (largest != idx)
    {
        swap(&maxHeap->a[largest], &maxHeap->a[idx]);
        maxHeapify(maxHeap, largest);
    }
}

// A utility function to create a max heap of given capacity
struct MaxHeap* createAndBuildHeap(int *a, int size)
{
    int i;
    struct MaxHeap* maxHeap =
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;   // initialize size of heap
    maxHeap->a = a; // Assign address of first element of array
    // Start from bottommost and rightmost internal mode and heapify all
    // internal modes in bottom up way
    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}

// The main function to sort an array of given size
void heapSort(int* a, int size)
{
    // Build a heap from the input data.
    struct MaxHeap* maxHeap = createAndBuildHeap(a, size);

    // Repeat following steps while heap size is greater than 1.
    // The last element in max heap will be the minimum element
    while (maxHeap->size > 1)
    {
        // The largest item in Heap is stored at the root. Replace
        // it with the last item of the heap followed by reducing the
        // size of heap by 1.
        swap(&maxHeap->a[0], &maxHeap->a[maxHeap->size - 1]);
        --maxHeap->size;  // Reduce heap size

        // Finally, heapify the root of tree.
        maxHeapify(maxHeap, 0);
    }
}


///////////////////////////////////////////////////////
//BUCKET SORT
/* Function for bucket sort */
void Bucket_Sort(int a[], int size)
{  
    int i, j;  
    int count[size]; 
    for (i = 0; i < size; i++)
        count[i] = 0;
 
    for (i = 0; i < size; i++)
        (count[a[i]])++;
for (i = 0, j = 0; i < size; i++)  
        for(; count[i] > 0; (count[i])--)
            a[j++] = i;
}   
/* End of Bucket_Sort() */
 

///////////////////////////////////////////////////////
//Radix Sort
int getMax(int a[], int size) {
    int mx = a[0];
    int i;
    for (i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}
 
void countSort(int a[], int size, int exp) {
    int output[size]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < size; i++)
        count[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = size - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
 
    for (i = 0; i < size; i++)
        a[i] = output[i];
}
void radixsort(int a[], int size) {
    int m = getMax(a, size);
 
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(a, size, exp);
}
 
void print(int a[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
}
 

///////////////////////////////////////////////////////
void copyArray(int* a,int* b, int first, int last)
{
    for(int k = first; k < last; k++)
        a[k] = b[k];
}
 
void split(int* a, int first, int last)
{
     
    if (last - first<2)
        return;
    int middle = floor((first + last) / 2);
    //cout<<first<<" "<<middle<<" "<<last<<endl;
    split(a, first, middle);
    split(a, middle, last);
    merge(a, first, middle, last);
    copyArray(a,b, first, last);
}
void mergeSort(int *a, int size){
    split(a,0,size);
}
/////////////////////////////
int* populateArray(int size)
{
    b=new int[size];
    int* a = new int[size];
    for (int i = 0;i < size;i++)
    {
         
        a[i] = rand() % 50000;
        b[i]=-1;
    }
    return a;
}
void printArray(int* a,int size)
{
    for (int i = 0;i < size;i++)
    {
        if(enablePrinting)
            cout<<a[i]<<"  ";
    }
    if(enablePrinting)
        cout<<endl;
}

int diff(timespec end, timespec start)
{
    timespec temp;
    if ((end.tv_nsec-start.tv_nsec)<0) {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }
    return temp.tv_sec;
}
 
 
SortingAlgorithm createSortingAlgorithm(string name,void (* f)(int*,int)){
    SortingAlgorithm sortingAlgorithm;
    sortingAlgorithm.name=name;
    sortingAlgorithm.algorithm=f;
    sortingAlgorithm.time=0;
    return sortingAlgorithm;
}
int main()
{
    int numberOfAlgorithms=7;
    SortingAlgorithm* sortingAlgorithms=new SortingAlgorithm[numberOfAlgorithms];
     
    sortingAlgorithms[0]=createSortingAlgorithm("Bubble",&bubbleSort);
    sortingAlgorithms[1]=createSortingAlgorithm("Selection",&selectionSort);
    sortingAlgorithms[2]=createSortingAlgorithm("Insertion",&insertionSort);
    sortingAlgorithms[3]=createSortingAlgorithm("Merge",&mergeSort);
    sortingAlgorithms[4]=createSortingAlgorithm("Quick",&quickSort);
    sortingAlgorithms[5]=createSortingAlgorithm("Heap",&heapSort);
    sortingAlgorithms[6]=createSortingAlgorithm("Bucket",&Bucket_Sort);
    sortingAlgorithms[7]=createSortingAlgorithm("Radix",&radixsort); 
    
    int sizes[10] ={10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
     
    long long start, end;
 
    ofstream CFile ("comparison.csv"); 
    CFile<<"SIZE;";
    for( int k =0 ;k<numberOfAlgorithms;k++){
        CFile<<sortingAlgorithms[k].name<<";";
    }
    CFile<<endl;
    for (int i = 0;i < 10;i++)
    {
        srand(rand());
        int size = sizes[i];
         
         
        for (int j = 0;j < 1;j++)
        {
            for( int k =0 ;k<numberOfAlgorithms;k++){
                int* a = populateArray(size);
                start = now();
                sortingAlgorithms[k].algorithm(a, size);
                end = now();
                sortingAlgorithms[k].time+= end- start;
            }
        }
        CFile<<size<<";";
        for( int k =0 ;k<numberOfAlgorithms;k++){
                cout << sortingAlgorithms[k].name<<" " << size << " : " << sortingAlgorithms[k].time << endl;
                CFile<<sortingAlgorithms[k].time<<";";
                sortingAlgorithms[k].time=0;
        }
        CFile<<endl;
         
    }
    return 0 ;
}