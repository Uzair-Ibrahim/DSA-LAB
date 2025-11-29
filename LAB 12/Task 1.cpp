#include <iostream>
#include <string>
using namespace std;
int bfs(const string &text, const string &pattern, int indices[], int &k) {
    int n = text.length();
    int m = pattern.length();
    int comparisons = 0;
    k = 0;
    for (int i = 0; i <= n - m; i++) {
        bool found = true;
        for (int j = 0; j < m; j++) {
            comparisons++;
            if (text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            indices[k] = i;
            k++;
        }
    }
    return comparisons;
}

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    int indices[100];
    int k;
    int comparisons = bfs(text, pattern, indices, k);
    cout << "[";
    for (int i = 0; i < k; i++) {
        cout << indices[i];
        if (i < k - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << comparisons << endl;
    return 0;
}
