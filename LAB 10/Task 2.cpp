#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] < arr[left])
            return false;
        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {8, 7, 6, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isMaxHeap(arr, n))
        cout << "The array represents a Max Heap." << endl;
    else
        cout << "The array does NOT represent a Max Heap." << endl;
   heapSort(arr, n);
    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
