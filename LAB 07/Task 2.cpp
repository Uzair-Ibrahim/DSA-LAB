#include <iostream>
#include <vector>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void radixSort(int arr[], int n, bool ascending = true) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        vector<int> bucket[10];
        for (int i = 0; i < n; i++) {
            int index = (arr[i] / exp) % 10;
            bucket[index].push_back(arr[i]);
        }
        int k = 0;
        if (ascending) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < bucket[i].size(); j++)
                    arr[k++] = bucket[i][j];
            }
        } else {
            for (int i = 9; i >= 0; i--) {
                for (int j = 0; j < bucket[i].size(); j++)
                    arr[k++] = bucket[i][j];
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original Array:\n";
    printArray(arr, n);
    radixSort(arr, n, true);
    cout << "Ascending Order:\n";
    printArray(arr, n);
    radixSort(arr, n, false);
    cout << "Descending Order:\n";
    printArray(arr, n);
    return 0;
}
