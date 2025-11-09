#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int partitionFirst(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}
int partitionMiddle(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    swap(arr[low], arr[mid]);
    return partitionFirst(arr, low, high);
}
int partitionRandom(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[low], arr[randomIndex]);
    return partitionFirst(arr, low, high);
}
int medianOfThree(vector<int>& arr, int a, int b, int c) {
    if ((arr[a] > arr[b]) != (arr[a] > arr[c])) return a;
    else if ((arr[b] > arr[a]) != (arr[b] > arr[c])) return b;
    else return c;
}
int partitionMedian(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    int medianIndex = medianOfThree(arr, low, mid, high);
    swap(arr[low], arr[medianIndex]);
    return partitionFirst(arr, low, high);
}
void quickSort(vector<int>& arr, int low, int high, int pivotType) {
    if (low < high) {
        int pi;
        switch (pivotType) {
            case 1: pi = partitionFirst(arr, low, high); break;
            case 2: pi = partitionRandom(arr, low, high); break;
            case 3: pi = partitionMiddle(arr, low, high); break;
            case 4: pi = partitionMedian(arr, low, high); break;
        }
        quickSort(arr, low, pi - 1, pivotType);
        quickSort(arr, pi + 1, high, pivotType);
    }
}
void runExperiment(vector<int> arr, const string& name, int pivotType) {
    comparisons = 0;
    quickSort(arr, 0, arr.size() - 1, pivotType);
    cout << name << " pivot: " << comparisons << " comparisons" << endl;
}

int main() {
    srand(time(0));
    vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> reverseArr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> randomArr = {5, 9, 1, 7, 3, 8, 4, 2, 10, 6};
    cout << "=== Sorted Array ===" << endl;
    runExperiment(sortedArr, "First", 1);
    runExperiment(sortedArr, "Random", 2);
    runExperiment(sortedArr, "Middle", 3);
    runExperiment(sortedArr, "Median", 4);
    cout << "\n=== Reverse Sorted Array ===" << endl;
    runExperiment(reverseArr, "First", 1);
    runExperiment(reverseArr, "Random", 2);
    runExperiment(reverseArr, "Middle", 3);
    runExperiment(reverseArr, "Median", 4);
    cout << "\n=== Random Array ===" << endl;
    runExperiment(randomArr, "First", 1);
    runExperiment(randomArr, "Random", 2);
    runExperiment(randomArr, "Middle", 3);
    runExperiment(randomArr, "Median", 4);
    return 0;
}
