#include <bits/stdc++.h>
using namespace std;

int secret;

void play(int p) {
    int g;
    cout << "player " << p << " guess: ";
    cin >> g;
    if (g == secret) {
        cout << "player " << p << " wins! num was " << secret << endl;
        return;
    }
    if (g < secret) cout << "too low" << endl;
    else cout << "too high" << endl;
    play(p == 1 ? 2 : 1);
}

int main() {
    srand(time(0));
    secret = rand() % 100 + 1;
    cout << "game start"<< endl;
    play(1);
}
