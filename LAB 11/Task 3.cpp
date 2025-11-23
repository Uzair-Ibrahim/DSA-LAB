#include <bits/stdc++.h>
using namespace std;
const int TABLE_SIZE = 100;

class Hash {
private:
    list<pair<string, string>> table[TABLE_SIZE];
    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key)
            sum += int(c);
        return sum % TABLE_SIZE;
    }
public:
    void insert(const string& key, const string& value) {
        int index = hashFunction(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }
    void search(const string& key) {
        int index = hashFunction(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                cout << "search key " << key << ": " << p.second << endl;
                return;
            }
        }
        cout << "Error: " << key << " not found!" << endl;
    }
    void remove(const string& key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
        }
        cout << "Error: " << key << " not found!" << endl;
    }
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i].empty()) {
                cout << "index " << i << ": ";
                for (auto &p : table[i]) {
                    cout << "(" << p.first << ", " << p.second << ")";
                    if (&p != &table[i].back()) cout << " -> ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Hash dict;
    dict.insert("AB", "FASTNU");
    dict.insert("CD", "CS");
    dict.insert("EF", "ENG");
    dict.search("AB");
    dict.remove("EF");
    dict.display();
    return 0;
}
