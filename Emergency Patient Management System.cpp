#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    int severity;

    Patient() {}

    Patient(int i, string n, int a, int s) {
        id = i;
        name = n;
        age = a;
        severity = s;
    }
};

class HospitalSystem {
private:
    unordered_map<int, Patient> patientMap;

    queue<int> normalQueue;

    priority_queue<pair<int, int>> criticalQueue;

public:
    void addPatient() {
        int id, age, severity;
        string name;

        cout << "Enter Patient ID: ";
        cin >> id;

        if (patientMap.find(id) != patientMap.end()) {
            cout << "Patient with this ID already exists.\n";
            return;
        }

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Severity (1-10): ";
        cin >> severity;

        Patient p(id, name, age, severity);
        patientMap[id] = p;

        if (severity >= 7) {
            criticalQueue.push({severity, id});
        } else {
            normalQueue.push(id);
        }

        cout << "Patient Added Successfully.\n";
    }

    void servePatient() {
        if (!criticalQueue.empty()) {
            int id = criticalQueue.top().second;
            criticalQueue.pop();

            cout << "Serving Critical Patient:\n";
            cout << "ID: " << patientMap[id].id
                 << " Name: " << patientMap[id].name
                 << " Age: " << patientMap[id].age
                 << " Severity: " << patientMap[id].severity << "\n";

            patientMap.erase(id);
        }
        else if (!normalQueue.empty()) {
            int id = normalQueue.front();
            normalQueue.pop();

            cout << "Serving Normal Patient:\n";
            cout << "ID: " << patientMap[id].id
                 << " Name: " << patientMap[id].name
                 << " Age: " << patientMap[id].age
                 << " Severity: " << patientMap[id].severity << "\n";

            patientMap.erase(id);
        }
        else {
            cout << "No Patients in Queue.\n";
        }
    }

    void searchPatient() {
        int id;
        cout << "Enter Patient ID to Search: ";
        cin >> id;

        if (patientMap.find(id) != patientMap.end()) {
            Patient p = patientMap[id];
            cout << "Patient Found:\n";
            cout << "ID: " << p.id
                 << " Name: " << p.name
                 << " Age: " << p.age
                 << " Severity: " << p.severity << "\n";
        } else {
            cout << "Patient Not Found.\n";
        }
    }

    void displayWaitingList() {
        if (patientMap.empty()) {
            cout << "No Patients Waiting.\n";
            return;
        }

        cout << "\n--- Critical Patients ---\n";
        priority_queue<pair<int, int>> tempCritical = criticalQueue;

        while (!tempCritical.empty()) {
            int id = tempCritical.top().second;
            cout << "ID: " << patientMap[id].id
                 << " Name: " << patientMap[id].name
                 << " Severity: " << patientMap[id].severity << "\n";
            tempCritical.pop();
        }

        cout << "\n--- Normal Patients ---\n";
        queue<int> tempNormal = normalQueue;

        while (!tempNormal.empty()) {
            int id = tempNormal.front();
            cout << "ID: " << patientMap[id].id
                 << " Name: " << patientMap[id].name
                 << " Severity: " << patientMap[id].severity << "\n";
            tempNormal.pop();
        }
    }
};

int main() {
    HospitalSystem hs;
    int choice;

    do {
        cout << "\n===== Hospital Patient Queue System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Serve Next Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. Display Waiting List\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: hs.addPatient(); break;
            case 2: hs.servePatient(); break;
            case 3: hs.searchPatient(); break;
            case 4: hs.displayWaitingList(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice.\n";
        }

    } while (choice != 0);

    return 0;
}
