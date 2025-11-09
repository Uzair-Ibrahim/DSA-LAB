#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Transaction {
public:
    int id;
    double amount;
    string description;
    int flag;
    Transaction* next;
    Transaction(int i, double a, string d, int f) {
        id = i;
        amount = a;
        description = d;
        flag = f;
        next = NULL;
    }
};

class Stack {
public:
    Transaction* top;
    Stack() {
        top = NULL;
    }
    void push(int id, double amount, string desc, int flag) {
        if (desc.length() > 20)
            desc = desc.substr(0, 20) + "...";
        if (flag == 1 && amount >= 500 && amount < 1000)
            amount -= amount * 0.05;
        else if (flag == 1 && amount >= 1000 && amount < 1500)
            amount -= amount * 0.15;
        else if (flag == 1 && amount >= 1500)
            amount -= amount * 0.30;
        Transaction* newNode = new Transaction(id, amount, desc, flag);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: ID=" << id << ", Amount=" << amount 
             << ", Desc=\"" << desc << "\", Flag=" << flag << endl;
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack empty!" << endl;
            return;
        }
        Transaction* temp = top;
        cout << "\nPopped Transaction: ";
        cout << "ID=" << temp->id << ", Desc=\"" << temp->description << "\"";
        temp->amount *= -1;
        temp->description += " [REVERSED]";
        temp->flag = 2;
        cout << "\nAfter Reversal → Amount=" << temp->amount 
             << ", Desc=\"" << temp->description << "\", Flag=" << temp->flag << endl;

        top = top->next;
        delete temp;
    }
    void display() {
        cout << "\nFinal Stack Output:\n";
        Transaction* temp = top;
        while (temp != NULL) {
            cout << "[id=" << temp->id 
                 << ", amt=" << temp->amount 
                 << ", desc=\"" << temp->description 
                 << "\", flag=" << temp->flag << "]\n";
            temp = temp->next;
        }
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

string infixToPostfix(string exp) {
    string result;
    char stack[100];
    int top = -1;
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (isdigit(c)) result += c;
        else if (c == ' ') continue;
        else if (c == '(') stack[++top] = c;
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                result += ' ';
                result += stack[top--];
            }
            top--;
        } else {
            result += ' ';
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                result += stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) {
        result += ' ';
        result += stack[top--];
    }
    return result;
}

double evaluatePostfix(string exp) {
    double stack[100];
    int top = -1;
    for (int i = 0; i < exp.length(); i++) {
        if (isdigit(exp[i])) {
            double num = 0;
            while (i < exp.length() && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            stack[++top] = num;
        }
        if (exp[i] == ' ') continue;
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            double b = stack[top--];
            double a = stack[top--];
            if (exp[i] == '+') stack[++top] = a + b;
            else if (exp[i] == '-') stack[++top] = a - b;
            else if (exp[i] == '*') stack[++top] = a * b;
            else if (exp[i] == '/') stack[++top] = a / b;
        }
    }
    return stack[top];
}

int main() {
    srand(time(0));
    Stack s;
    string desc[] = {"Blue Jacket", "Cotton Socks", "Leather Jacket", "Defective Shirt"};
    double amt[] = {1200, 450, 1700, -300};
    int flag[] = {1, 1, 1, 0};
    cout << "Pushed Transactions:\n";
    for (int i = 0; i < 4; i++) {
        s.push(i + 1, amt[i], desc[i], flag[i]);
    }
    s.pop();
    s.display();
    cout << "\nExpression Evaluation Example:\n";
    string infix = "(100 + 20) * 0.9 - 5";
    cout << "Infix: " << infix << endl;
    string postfix = infixToPostfix("100 + 20 * 0.9 - 5");
    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
