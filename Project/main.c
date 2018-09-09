#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int sorting(int arr[], int n);

int main(){
	int n = 5000;
	int arr[n];
            clock_t t;
            srand((unsigned) time(&t));
            for(int i = 0 ; i < n ; i++ ) 
            {
                arr[i] =  rand() % 1000000;
            }
}
int sorting(int arr[], int n){
    int tmp[n];
    for(int i = 0 ; i < n ; i++ ) 
    {
        tmp[i] = arr[i];
    }

    clock_t begin_selectionSort = clock();
    selectionSort(arr, n);
    clock_t end_selectionSort = clock();
    double time_spent_selectionSort = (double)(end_selectionSort - begin_selectionSort) / CLOCKS_PER_SEC;
    printf("Time taken by Selection Sort %f", time_spent_selectionSort);
    clock_t begin_insertionSort = clock();
    insertionSort(arr, n);
    clock_t end_insertionSort = clock();
    double time_spent_insertionSort = (double)(end_insertionSort - begin_insertionSort) / CLOCKS_PER_SEC;
    printf("Time taken by Insertion Sort %f", time_spent_insertionSort);
    clock_t begin_merge = clock();
    merge(arr, n,);
    clock_t end_merge = clock();
    double time_spent_merge = (double)(end_merge - begin_merge) / CLOCKS_PER_SEC;
    printf("Time taken by Merge Sort %f", time_spent_merge);
    clock_t begin_bubbleSort = clock();
    bubbleSort(arr, n);
    clock_t end_bubbleSort = clock();
    double time_spent_bubbleSort = (double)(end_bubbleSort - begin_bubbleSort) / CLOCKS_PER_SEC;
    printf("Time taken by Bubble Sort %f", time_spent_bubbleSort);
    clock_t begin_quickSort = clock();
    quickSort(arr, n);
    clock_t end_quickSort = clock();
    double time_spent_quickSort = (double)(end_quickSort - begin_quickSort) / CLOCKS_PER_SEC;
    printf("Time taken by Quick Sort %f", time_spent_quickSort);
    clock_t begin_radixsort = clock();
    radixsort(arr, n);
    clock_t end_radixsort = clock();
    double time_spent_radixsort = (double)(end_radixsort - begin_radixsort) / CLOCKS_PER_SEC;
    printf("Time taken by Radix Sort %f", time_spent_radixsort);
    clock_t begin_heapSort = clock();
    heapSort(arr, n);
    clock_t end_heapSort = clock();
    double time_spent_heapSort = (double)(end_heapSort- begin_heapSort) / CLOCKS_PER_SEC;
    printf("Time taken by Heap Sort %f", time_spent_heapSort);
    for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }
    
    

    return 0;
}
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
}
///////////////////////////////
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
 
void quickSort(int * a, int top, int bottom)
{
     int middle;
     if (top < bottom)
    {
          middle = partition(a, top, bottom);
          quickSort(a, top, middle); 
          quickSort(a, middle+1, bottom);   
     }
     return;
}
/////////////////////////////////////////////
 
 
void quickSort(int * a, int size)
{
     _quickSort(a,0,size);
     return;
}
//////////////////////////////////////////////
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
///////////////////////////////////////////
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
///////////////////////////////////