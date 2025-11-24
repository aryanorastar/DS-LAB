#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Helper function to print vector
void printVector(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// a. Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// b. Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// c. Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// d. Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// e. Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    vector<int> arrMerge(arr1, arr1 + n);
    
    cout << "Original array: ";
    printArray(arr1, n);
    cout << endl;
    
    // a. Selection Sort
    cout << "a. Selection Sort:" << endl;
    cout << "Before: ";
    printArray(arr1, n);
    selectionSort(arr1, n);
    cout << "After:  ";
    printArray(arr1, n);
    cout << endl;
    
    // b. Insertion Sort
    cout << "b. Insertion Sort:" << endl;
    cout << "Before: ";
    printArray(arr2, n);
    insertionSort(arr2, n);
    cout << "After:  ";
    printArray(arr2, n);
    cout << endl;
    
    // c. Bubble Sort
    cout << "c. Bubble Sort:" << endl;
    cout << "Before: ";
    printArray(arr3, n);
    bubbleSort(arr3, n);
    cout << "After:  ";
    printArray(arr3, n);
    cout << endl;
    
    // d. Merge Sort
    cout << "d. Merge Sort:" << endl;
    cout << "Before: ";
    printVector(arrMerge);
    mergeSort(arrMerge, 0, arrMerge.size() - 1);
    cout << "After:  ";
    printVector(arrMerge);
    cout << endl;
    
    // e. Quick Sort
    cout << "e. Quick Sort:" << endl;
    cout << "Before: ";
    printArray(arr5, n);
    quickSort(arr5, 0, n - 1);
    cout << "After:  ";
    printArray(arr5, n);
    cout << endl;
    
    return 0;
}

