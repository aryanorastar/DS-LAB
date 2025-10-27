#include <iostream>
#include <queue>

using namespace std;

int countStudents(int students[], int sandwiches[], int n) {
    queue<int> q;

    // Add all students to queue
    for (int i = 0; i < n; i++) {
        q.push(students[i]);
    }

    int sandwichIndex = 0;
    int consecutiveUnable = 0;

    while (!q.empty() && consecutiveUnable < q.size()) {
        int student = q.front();
        q.pop();

        // If student prefers the sandwich on top, they take it
        if (student == sandwiches[sandwichIndex]) {
            sandwichIndex++;
            consecutiveUnable = 0;
        } else {
            // Student goes to back of queue
            q.push(student);
            consecutiveUnable++;
        }
    }

    return q.size();
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int* students = new int[n];
    int* sandwiches = new int[n];

    cout << "Enter student preferences (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    cout << "Enter sandwich types (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++) {
        cin >> sandwiches[i];
    }

    int unable = countStudents(students, sandwiches, n);
    cout << "Number of students unable to eat: " << unable << endl;

    delete[] students;
    delete[] sandwiches;

    return 0;
}

