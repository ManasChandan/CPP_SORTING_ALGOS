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

int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
}
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    }
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
}
void radixsort(int arr[], int n) 
{ 
    int m = getMax(arr, n); 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
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
    cout << "4. Radix Sort" << "\n" ; 
    cout << "5. Merge Sort" << "\n" ; 
    cin >> choice ; 
    switch (choice)
    {
    case 1: bubbleSort(arr , n) ; 
        break;
    case 2: insertionSort(arr , n) ; 
        break ; 
    case 3: selectionSort(arr , n) ; 
        break ; 
    case 4: radixsort(arr , n) ; 
        break ; 
    case 5: mergesort(arr , n) ; 
        break ;
    }
    cout<<"Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}