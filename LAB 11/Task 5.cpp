#include <bits/stdc++.h>
using namespace std;
const int TABLE_SIZE = 15;

class Student {
public:
    int roll;
    string name;
    bool isOccupied;
    Student() {
        roll = -1;
        name = "";
        isOccupied = false;
    }
};

class StudentHashTable {
private:
    Student table[TABLE_SIZE];
    int hashFunction(int roll) {
        return roll % TABLE_SIZE;
    }
public:
    void InsertRecord(int roll, const string& name) {
        int index = hashFunction(roll);
        int attempt = 0;
        while (attempt < TABLE_SIZE) {
            int probeIndex = (index + attempt * attempt) % TABLE_SIZE;
            if (!table[probeIndex].isOccupied) {
                table[probeIndex].roll = roll;
                table[probeIndex].name = name;
                table[probeIndex].isOccupied = true;
                cout << "Inserted roll " << roll << " at index " << probeIndex << endl;
                return;
            }
            attempt++;
        }
        cout << "Hash table is full, cannot insert roll " << roll << endl;
    }
    void SearchRecord(int roll) {
        int index = hashFunction(roll);
        int attempt = 0;
        while (attempt < TABLE_SIZE) {
            int probeIndex = (index + attempt * attempt) % TABLE_SIZE;
            if (table[probeIndex].isOccupied && table[probeIndex].roll == roll) {
                cout << "Record found: " << table[probeIndex].name << endl;
                return;
            } else if (!table[probeIndex].isOccupied) {
                cout << "Record not found" << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found" << endl;
    }
    void DisplayTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].isOccupied)
                cout << "Index " << i << ": Roll " << table[i].roll << ", Name " << table[i].name << endl;
            else
                cout << "Index " << i << ": EMPTY" << endl;
        }
    }
};

int main() {
    StudentHashTable sht;
    sht.InsertRecord(101, "Ali");
    sht.InsertRecord(116, "Sara");
    sht.InsertRecord(121, "Raza");
    sht.InsertRecord(136, "Taha");
    sht.InsertRecord(150, "Imran");
    cout << endl;
    sht.SearchRecord(121);
    sht.SearchRecord(200);
    cout << "\nHash Table:\n";
    sht.DisplayTable();
    return 0;
}
