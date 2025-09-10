#include <bits/stdc++.h>
using namespace std;

class Flight{
    public:
    string name;
    Flight*next;
    Flight(string n){
       name=n;
       next=NULL;
    }
};

class Passenger{
    Flight* head;
    Flight* tail;
    public:
    Passenger(){
        head=tail=NULL;
    }

    void displayll(){
        Flight* temp=head;
        while(temp!=NULL){
            cout<<temp->name<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void pushback(string n){
        Flight* newFlight = new Flight(n);
        if(head==NULL||n<head->name){
            newFlight->next=head;
            head=newFlight;
            if(tail==NULL)tail=newFlight;
            return;
        }
        Flight* temp=head;
        while(temp->next!=NULL && temp->next->name<n){
            temp = temp->next;
        }
        newFlight->next = temp->next;
        temp->next = newFlight;
        if(newFlight->next == NULL) tail = newFlight;
    }

    int search(string n){
        Flight* temp=head;
        int ind=0;
        while(temp!=NULL){
            if(temp->name==n){
                return ind;
            }
            temp=temp->next;
            ind++;
        }
        return -1;
    }

    void deleten(string n){
        Flight*temp=head;
        Flight*prev=NULL;
        while(temp!=NULL){
            if(temp->name==n){
                if(prev==NULL) head=temp->next;
                else prev->next=temp->next;
                delete temp; 
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }
};

int main() {
    Passenger ll;
    int choice;
    string name;
    while(true){
        cout << "\n--- Airline Reservation Menu ---\n";
        cout << "1. Reserve a ticket\n";
        cout << "2. Cancel a reservation\n";
        cout << "3. Check if a ticket is reserved for a person\n";
        cout << "4. Display all passengers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter name to reserve: ";
                cin >> name;
                ll.pushback(name);
                break;
            case 2:
                cout << "Enter name to cancel reservation: ";
                cin >> name;
                ll.deleten(name);
                cout << "Deleted if present." << endl;
                break;
            case 3:
                cout << "Enter name to check: ";
                cin >> name;
                int idx;
                idx = ll.search(name);
                if(idx != -1) cout << name << " has a reservation at index " << idx << endl;
                else cout << name << " has no reservation." << endl;
                break;
            case 4:
                ll.displayll();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
