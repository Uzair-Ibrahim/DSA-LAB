//using radix

#include <iostream>
#include <vector>
using namespace std;

int getMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    int exp = 1;

    while (maxVal / exp > 0) {
        vector<int> bucket[10];
        for (int i = 0; i < arr.size(); i++) {
            int digit = (arr[i] / exp) % 10;
            bucket[digit].push_back(arr[i]);
        }

        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < bucket[i].size(); j++) {
                arr[index++] = bucket[i][j];
            }
        }

        exp *= 10;
    }
}

int main() {
    int arr1[10] = {12, 45, 23, 51, 19, 8, 33, 7, 4, 21};
    int arr2[10] = {18, 11, 3, 27, 6, 9, 30, 22, 14, 5};

    vector<int> combined;
    for (int i = 0; i < 10; i++)
        combined.push_back(arr1[i]);
    for (int i = 0; i < 10; i++)
        combined.push_back(arr2[i]);

    cout << "Original combined array: ";
    for (int i = 0; i < combined.size(); i++)
        cout << combined[i] << " ";
    cout << endl;

    radixSort(combined);

    cout << "Sorted array using Radix Sort: ";
    for (int i = 0; i < combined.size(); i++)
        cout << combined[i] << " ";
    cout << endl;

    return 0;
}



//using merge sort

#include <iostream>
#include <vector>
using namespace std;

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
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr1[10] = {12, 45, 23, 51, 19, 8, 33, 7, 4, 21};
    int arr2[10] = {18, 11, 3, 27, 6, 9, 30, 22, 14, 5};
    vector<int> combined;
    combined.insert(combined.end(), arr1, arr1 + 10);
    combined.insert(combined.end(), arr2, arr2 + 10);
    mergeSort(combined, 0, combined.size() - 1);
    cout << "Sorted array using Merge Sort: ";
    for (int num : combined)
        cout << num << " ";
    cout << endl;
    return 0;
}
