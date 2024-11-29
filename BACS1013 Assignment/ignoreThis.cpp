#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Constants
const int records = 100;

// Arrays for student fields
int eventId[records];
string eventName[records];
string eventStartDate[records];
string eventEndDate[records];
string eventPlace[records];
int eventPax[records];

int eventCount = 0;  // Current number of students
int nextEventId = 1;   // Auto-increment ID counter

// File path
const string FILE_PATH = "data.txt";

// Function to Save Data to File
void saveData() {
    ofstream outFile(FILE_PATH);
    if (!outFile) {
        cout << "Error saving data to file.\n";
        return;
    }

    for (int i = 0; i < eventCount; i++) {
        outFile << eventId[i] << ","
            << eventName[i] << ","
            << eventStartDate[i] << ","
            << eventEndDate[i] << ","
            << eventPlace[i] << ","
            << eventPax[i] << "\n";
    }
    outFile.close();
    cout << "Data saved to file successfully.\n";
}

// Function to Load Data from File
void loadData() {
    ifstream inFile(FILE_PATH);
    if (!inFile) {
        cout << "No existing data file found. Creating new.\n";
        return;
    }

    eventCount = 0; // Reset the count
    string line;
    while (getline(inFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);
        size_t pos4 = line.find(',', pos3 + 1);
        size_t pos5 = line.find(',', pos4 + 1);

        // Parse each variable from the line
        eventId[eventCount] = stoi(line.substr(0, pos1));
        eventName[eventCount] = line.substr(pos1 + 1, pos2 - pos1 - 1);
        eventStartDate[eventCount] = line.substr(pos2 + 1, pos3 - pos2 - 1);
        eventEndDate[eventCount] = line.substr(pos3 + 1, pos4 - pos3 - 1);
        eventPlace[eventCount] = line.substr(pos4 + 1, pos5 - pos4 - 1);
        eventPax[eventCount] = stoi(line.substr(pos5 + 1));

        eventCount++;
        if (eventCount >= records) {
            cout << "Error! Max record reached.\n";
            break;
        }
    }

    // Update nextEventId to avoid overwriting IDs
    if (eventCount > 0) {
        nextEventId = eventId[eventCount - 1] + 1;
    }

    inFile.close();
    cout << "Data loaded from file successfully.\n";
}

// CRUD Operations
void createStudent() {
    system("cls");
    if (eventCount >= records) {
        cout << "Student database is full!\n";
        return;
    }

    eventId[eventCount] = nextEventId++;  // Assign auto-increment ID
    cout << "Enter event name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, eventName[eventCount]);
    cout << "Enter event pax: ";
    cin >> eventPax[eventCount];

    eventCount++; // Increment the count
    cout << "Event added successfully!\n";

    saveData(); // Save data after adding a student
}

void eventList() {

    if (eventCount == 0) {
        cout << "No event currently.\n";
        return;
    }
    system("cls");
    cout << left; //make event list left justified

    cout << setw(3) << "ID" 
        << setw(30) << "Name" 
        << setw(15) << "Start Date"
        << setw(15) << "End Date"
        << setw(5) << "Pax" << endl;

    for (int i = 0; i < eventCount; i++) {

        cout << setw(3) << eventId[i]
            << setw(30) << eventName[i]
            << setw(15) << eventStartDate[i]
            << setw(15) << eventEndDate[i]
            << setw(5) << eventPax[i] << endl;

    }
}

void updateStudent() {
    system("cls");
    eventList();
    int id;
    cout << "\nEnter the ID of the student to update: ";
    cin >> id;

    for (int i = 0; i < eventCount; i++) {
        if (eventId[i] == id) {
            cout << "Enter new Name: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, eventName[i]);
            cout << "Enter new Pax: ";
            cin >> eventPax[i];
            cout << "Event updated successfully!\n";

            saveData(); // Save data after updating
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

void deleteStudent() {
    int id;
    cout << "Enter the ID of the student to delete: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < eventCount; i++) {
        if (eventId[i] == id) {
            // Found the record to delete
            found = true;

            // Shift all subsequent records left
            for (int j = i; j < eventCount - 1; j++) {
                eventId[j] = eventId[j + 1];
                eventName[j] = eventName[j + 1];
                eventStartDate[j] = eventStartDate[j + 1];
                eventEndDate[j] = eventEndDate[j + 1];
                eventPlace[j] = eventPlace[j + 1];
                eventPax[j] = eventPax[j + 1];
            }
            eventCount--; // Decrement the count

            // Renumber IDs
            for (int j = 0; j < eventCount; j++) {
                eventId[j] = j + 1;
            }

            saveData(); // Save data after deleting
            return;
        }
    }

    if (!found) {
        cout << "Student with ID " << id << " not found.\n";
    }
}

// Main Menu
int main() {
    loadData(); // Load data when the program starts
    

    int choice;
    while (true) {

        eventList();


        cout << setw(8) << "\n1 Add  2 Update  3 Delete  4 Exit ";

        cin >> choice;

        switch (choice) {
        case 1:
            createStudent();
            break;
        case 2:
            updateStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            system("cls");
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
