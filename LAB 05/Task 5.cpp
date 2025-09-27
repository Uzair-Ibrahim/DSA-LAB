#include <bits/stdc++.h>
using namespace std;

int rsum(int* arr[], int sz[], int d) {
    if (d == 1) {
        int s = 0;
        for (int i = 0; i < sz[0]; i++) s += arr[0][i];
        return s;
    }
    int s = 0;
    for (int i = 0; i < sz[0]; i++) s += rsum((int**)arr[i], sz + 1, d - 1);
    return s;
}

int main() {
    int r1[] = {1,2,3};
    int r2[] = {4,5};
    int r3[] = {6,7,8,9};
    int* arr[] = {r1,r2,r3};
    int sz[] = {3,4};
    cout << rsum(arr, sz, 2) << endl;
}
