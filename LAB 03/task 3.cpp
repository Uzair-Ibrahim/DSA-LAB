#include <iostream>
using namespace std;

class node {
public:
    string name;
    node* next;
    node(string n) {
        name=n;
        next=0;
    }
};

class airline {
private:
    node* head;
public:
    airline() {
        head=0;
    }

    void reserve(string n) {
        node* temp=new node(n);
        if(head==0 || n<head->name) {
            temp->next=head;
            head=temp;
            cout<<n<<" reserved"<<endl;
            return;
        }
        node* curr=head;
        while(curr->next && curr->next->name<n) {
            curr=curr->next;
        }
        if(curr->next && curr->next->name==n) {
            cout<<"already reserved"<<endl;
            delete temp;
            return;
        }
        temp->next=curr->next;
        curr->next=temp;
        cout<<n<<" reserved"<<endl;
    }

    void cancel(string n) {
        if(head==0) {
            cout<<"no reservation"<<endl;
            return;
        }
        if(head->name==n) {
            node* t=head;
            head=head->next;
            delete t;
            cout<<n<<" cancelled"<<endl;
            return;
        }
        node* curr=head;
        while(curr->next && curr->next->name!=n) {
            curr=curr->next;
        }
        if(curr->next==0) {
            cout<<"not found"<<endl;
            return;
        }
        node* t=curr->next;
        curr->next=curr->next->next;
        delete t;
        cout<<n<<" cancelled"<<endl;
    }

    void check(string n) {
        node* curr=head;
        while(curr) {
            if(curr->name==n) {
                cout<<n<<" reserved"<<endl;
                return;
            }
            curr=curr->next;
        }
        cout<<"not reserved"<<endl;
    }

    void display() {
        if(head==0) {
            cout<<"no passengers"<<endl;
            return;
        }
        node* curr=head;
        while(curr) {
            cout<<curr->name<<""<<endl;
            curr=curr->next;
        }
    }
};

int main() {
    airline a;
    int c;
    string n;
    while(1) {
        cout<<"\n1.reserve"<<endl<<"2.cancel"<<endl<<"3.check"
        <<endl<<"4.display"<<endl<<"5.exit"<<endl;
        cin>>c;
        if(c==1) {
            cin>>n;
            a.reserve(n);
        }
        else if(c==2) {
            cin>>n;
            a.cancel(n);
        }
        else if(c==3) {
            cin>>n;
            a.check(n);
        }
        else if(c==4) {
            a.display();
        }
        else if(c==5) {
            break;
        }
    }
}
