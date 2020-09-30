#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
} 

void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
    for (i = 0; i < n-1; i++)  
    {
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
        swap(&arr[min_idx], &arr[i]);  
    }  
} 

void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}
  
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

  
int main()  
{  
    int arr[7] ; 
    cout << "Enter the array Please !" ; 
    cout << "\n" ; 
    for(int i=0;i<7;i++){
        cin >> arr[i] ; 
    }  
    int n = sizeof(arr)/sizeof(arr[0]); 
    int choice ; 
    cout << "\n" << "Enter your choice" << "\n" ; 
    cout << "1. Bubble Sort" << "\n" ; 
    cout << "2. Insertion Sort" << "\n" ; 
    cout << "3. Selection Sort" << "\n" ;
    cin >> choice ; 
    switch (choice)
    {
    case 1: bubbleSort(arr , n) ; 
        break;
    case 2: insertionSort(arr , n) ; 
        break ; 
    case 3: selectionSort(arr , n) ; 
        break ;
    }
    cout<<"Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  

