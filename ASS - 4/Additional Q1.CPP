#include <iostream>
#include <queue>
#include <string>

using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");

    cout << "Binary numbers from 1 to " << n << ": ";

    for (int i = 0; i < n; i++) {
        string binary = q.front();
        q.pop();

        cout << binary;
        if (i < n - 1) cout << ", ";

        // Generate next two binary numbers
        q.push(binary + "0");
        q.push(binary + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    generateBinaryNumbers(n);

    return 0;
}

