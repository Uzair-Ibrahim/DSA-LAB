#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int hp;
    int attack;
    int id;
    Combatant() {}
    Combatant(string n, int h, int a, int i) {
        name = n;
        hp = h;
        attack = a;
        id = i;
    }
    void display() const {
        cout << name << " (HP:" << hp << ", ATK:" << attack << ")";
    }
};

class Node {
public:
    Combatant data;
    Node* left;
    Node* right;
    Node(Combatant c) {
        data = c;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }
    Node* insert(Node* node, Combatant c) {
        if (node == nullptr)
            return new Node(c);
        if (c.id < node->data.id)
            node->left = insert(node->left, c);
        else
            node->right = insert(node->right, c);
        return node;
    }
    void insert(Combatant c) {
        root = insert(root, c);
    }
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }
    Node* deleteNode(Node* node, int id) {
        if (node == nullptr)
            return node;
        if (id < node->data.id)
            node->left = deleteNode(node->left, id);
        else if (id > node->data.id)
            node->right = deleteNode(node->right, id);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data.id);
        }
        return node;
    }
    void deleteByID(int id) {
        root = deleteNode(root, id);
    }
    Node* getFrontline() {
        return findMin(root);
    }
    bool isEmpty() {
        return root == nullptr;
    }
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            node->data.display();
            cout << "  ";
            inorder(node->right);
        }
    }
    void showTeam() {
        inorder(root);
        cout << endl;
    }
};
void attackTurn(BST &attackerTree, BST &defenderTree, bool isPlayerTurn, int round) {
    Node* attacker = attackerTree.getFrontline();
    Node* defender = defenderTree.getFrontline();
    if (!attacker || !defender) return;
    int randomBonus = rand() % 5; // 0–4
    int damage = attacker->data.attack + randomBonus;
    defender->data.hp -= damage;
    cout << (isPlayerTurn ? "[Player]" : "[Enemy]") << " "
         << attacker->data.name << " attacks "
         << defender->data.name << " for " << damage << " damage!" << endl;
    if (defender->data.hp <= 0) {
        cout << defender->data.name << " has been defeated!" << endl;
        defenderTree.deleteByID(defender->data.id);
    } else {
        cout << defender->data.name << " now has " << defender->data.hp << " HP left.\n";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    BST playerTeam, enemyTeam;
    playerTeam.insert(Combatant("Hero_A", 30, 8, 10));
    playerTeam.insert(Combatant("Hero_B", 25, 10, 20));
    playerTeam.insert(Combatant("Hero_C", 35, 6, 30));
    playerTeam.insert(Combatant("Hero_D", 28, 9, 40));
    playerTeam.insert(Combatant("Hero_E", 20, 12, 50));
    enemyTeam.insert(Combatant("Enemy_1", 25, 7, 10));
    enemyTeam.insert(Combatant("Enemy_2", 30, 6, 20));
    enemyTeam.insert(Combatant("Enemy_3", 22, 8, 30));
    enemyTeam.insert(Combatant("Enemy_4", 27, 9, 40));
    enemyTeam.insert(Combatant("Enemy_5", 35, 5, 50));
    int round = 1;
    cout << "=== BattleQuest: BST Arena ===\n\n";
    while (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
        cout << "----- Round " << round << " -----\n";
        cout << "Player Team: ";
        playerTeam.showTeam();
        cout << "Enemy Team:  ";
        enemyTeam.showTeam();
        cout << endl;
        attackTurn(playerTeam, enemyTeam, true, round);
        if (enemyTeam.isEmpty()) break;
        attackTurn(enemyTeam, playerTeam, false, round);
        if (playerTeam.isEmpty()) break;
        round++;
    }
    if (enemyTeam.isEmpty())
        cout << "=== Victory! Player team wins the battle! ===" << endl;
    else
        cout << "=== Defeat... Enemy team wins. ===" << endl;
    return 0;
}
