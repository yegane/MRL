
#include <iostream>
using namespace std;


void mergeSort(int arr[], int l, int r);
void merge(int arr[], int p, int q, int r);
void bubblesort(int arr[],int size);
void printArray(int arr[] , int size);

int menu(){
        int choose;
        cout<<"Which sort do you want?"<<endl;
        cout<<"Merge sort=1,bubble sort=2,insertion sort=3, quickSort=4"<<endl;
        cin>> choose;
        return(choose);
    }

int main()
{
    int size;
    int number;
    cout<<" please enter the size of array"<<endl;
    cin>> size;
    int arr[size];
    cout<<"Randomly Enter "<<size<<" Number : \n";
    for(int i=0;i<size;i++){
		cin>>number;
		arr[i] = number;
    }
    switch (menu())
    {
    case 1:
        mergeSort(arr,0,size-1);
        break;
    case 2:
       bubblesort(arr, size);
       break;

    default:
        cout<<"pleade enter the valid number!";
        exit(0);
    }
    	
    for (auto i = 0; i < size; i++)
        cout <<arr[i] << " ";   
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void bubblesort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}
