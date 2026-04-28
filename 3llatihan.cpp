#include <bits/stdc++.h>
using namespace std;

void pushantrian(queue<string> &q, string nama) {
    q.push(nama);
    cout << "Status: " << nama << " masuk antrian" << endl;
}

void popantrian(queue<string> &q) {
    if (!q.empty()) {
        cout << q.front() << " dilayani" << endl;
        q.pop();
    }
}

void printantrian(queue<string> q) {
    cout << "\nKondisi antrian terkini:" << endl;
    int urutan = 1;
    while (!q.empty()) {
        cout << urutan << ". " << q.front() << endl;
        q.pop();
        urutan++;
    }
}

int main() {
    queue<string> antrian;
    cout << "-----------------------------------" << endl;
    pushantrian(antrian, "Mahasiswa A");
    pushantrian(antrian, "Mahasiswa B");
    pushantrian(antrian, "Mahasiswa C");
    cout << "-----------------------------------" << endl;
    popantrian(antrian);
    cout << "-----------------------------------" << endl;
    pushantrian(antrian, "Mahasiswa D");
    printantrian(antrian);

    return 0;
}