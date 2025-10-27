#include <iostream>

using namespace std;

struct PolyNode {
    int coeff;
    int power;
    PolyNode* next;
};

PolyNode* createPolyNode(int coeff, int power) {
    PolyNode* newNode = new PolyNode;
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = nullptr;
    return newNode;
}

void insertPolyNode(PolyNode*& head, int coeff, int power) {
    PolyNode* newNode = createPolyNode(coeff, power);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Insert in descending order of power
    if (newNode->power > head->power) {
        newNode->next = head;
        head = newNode;
        return;
    }

    PolyNode* temp = head;
    while (temp->next != nullptr && temp->next->power >= newNode->power) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

PolyNode* addPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = nullptr;
    PolyNode* temp1 = poly1;
    PolyNode* temp2 = poly2;

    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->power > temp2->power) {
            insertPolyNode(result, temp1->coeff, temp1->power);
            temp1 = temp1->next;
        } else if (temp2->power > temp1->power) {
            insertPolyNode(result, temp2->coeff, temp2->power);
            temp2 = temp2->next;
        } else {
            int sum = temp1->coeff + temp2->coeff;
            if (sum != 0) {
                insertPolyNode(result, sum, temp1->power);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != nullptr) {
        insertPolyNode(result, temp1->coeff, temp1->power);
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
        insertPolyNode(result, temp2->coeff, temp2->power);
        temp2 = temp2->next;
    }

    return result;
}

void displayPolynomial(PolyNode* head) {
    if (head == nullptr) {
        cout << "0" << endl;
        return;
    }

    bool first = true;
    PolyNode* temp = head;

    while (temp != nullptr) {
        if (!first && temp->coeff > 0) {
            cout << " + ";
        } else if (temp->coeff < 0) {
            cout << " - ";
        }

        if (abs(temp->coeff) != 1 || temp->power == 0) {
            cout << abs(temp->coeff);
        }

        if (temp->power > 0) {
            cout << "x";
            if (temp->power > 1) {
                cout << "^" << temp->power;
            }
        }

        first = false;
        temp = temp->next;
    }
    cout << endl;
}

void displayPolynomialCompact(PolyNode* head) {
    if (head == nullptr) {
        cout << "[]" << endl;
        return;
    }

    cout << "[";
    PolyNode* temp = head;
    bool first = true;
    while (temp != nullptr) {
        if (!first) cout << ", ";
        cout << "[" << temp->coeff << ", " << temp->power << "]";
        first = false;
        temp = temp->next;
    }
    cout << "]" << endl;
}

int main() {
    PolyNode* poly1 = nullptr;
    PolyNode* poly2 = nullptr;
    int n1, n2, coeff, power;

    cout << "Enter number of terms in polynomial 1: ";
    cin >> n1;
    cout << "Enter polynomial 1 terms (coefficient power): " << endl;
    for (int i = 0; i < n1; i++) {
        cin >> coeff >> power;
        insertPolyNode(poly1, coeff, power);
    }

    cout << "\nEnter number of terms in polynomial 2: ";
    cin >> n2;
    cout << "Enter polynomial 2 terms (coefficient power): " << endl;
    for (int i = 0; i < n2; i++) {
        cin >> coeff >> power;
        insertPolyNode(poly2, coeff, power);
    }

    cout << "\nPolynomial 1: ";
    displayPolynomialCompact(poly1);
    cout << "Polynomial 2: ";
    displayPolynomialCompact(poly2);

    PolyNode* result = addPolynomials(poly1, poly2);

    cout << "\nResult: ";
    displayPolynomialCompact(result);

    // Free memory
    while (poly1 != nullptr) {
        PolyNode* temp = poly1;
        poly1 = poly1->next;
        delete temp;
    }
    while (poly2 != nullptr) {
        PolyNode* temp = poly2;
        poly2 = poly2->next;
        delete temp;
    }
    while (result != nullptr) {
        PolyNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}

