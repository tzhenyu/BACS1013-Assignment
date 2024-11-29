#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>
#include <conio.h>

using namespace std;

//Function initialization
void welcomeScreen();
void modeSelection(string text);
void logIn(string text);

void loadData();
void saveData();

void adminEventList();
void guestEventList();
void showEvents();

void showEventDetails();
void createEvent();
void joinEvent();
void editEvent();
void deleteEvent();

void printReceipt();
void outputSucess();
void saveToFile();
void loadFromFile();

void eventBooking();
void eventMarketing();
void eventPayment();
void eventMonitoring();
void eventReporting();

//Constant variable declaration
const string FILE_PATH = "data.txt"; // File path
const int records = 100;         // Event Max Record 

//Vairiable declaration
int mode;
int eventId[records];
string eventName[records];
string eventStartDate[records];
string eventEndDate[records];
string eventPlace[records];
int eventPax[records];

int eventCount = 0;  // Current number of students
int nextEventId = 1;   // Auto-increment ID counter

//Main menu
int main() {
    welcomeScreen();
    modeSelection("Are you Host or Guest? Prompt to select");

}


//Other functions

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
}

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
}

void welcomeScreen()
{
    cout << "Hi test, press ENTER to continue...";
    cin.ignore();
    
}

void modeSelection(string text)
{
        system("cls");
        cout << text << endl;
        cout << "[1] Host" << endl;
        cout << "[2] Guest" << endl;
        cout << ">";
        cin >> mode;

        switch (mode) {
        case 1: logIn("Please log in."); break;
        case 2: guestEventList(); break;
        default: modeSelection("Invalid code. Please try again.");
        

    }
}

void logIn(string text)
{
    string username, password;

    system("cls");
    cout << text << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "admin") {
        adminEventList();
        
    }
    else {
        logIn("Wrong username or password");
            
    }
}



void showEvents() {
    
    loadData();

    cout << left; //make event list left justified

    cout << setw(3) << "ID"
        << setw(30) << "Name"
        << setw(15) << "Start Date"
        << setw(15) << "End Date"
        << setw(5) << "Pax" << endl;

    if (eventCount == 0) {
        cout << "\nNo event currently.\n";
        return;
    }

    for (int i = 0; i < eventCount; i++) {

        cout << setw(3) << eventId[i]
            << setw(30) << eventName[i]
            << setw(15) << eventStartDate[i]
            << setw(15) << eventEndDate[i]
            << setw(5) << eventPax[i] << endl;

    }
}


void adminEventList() {int nextEventId = 1;   // Auto-increment ID counter
    system("cls");
    cout << "You are: Host\n";
    showEvents();

    int choice;
    cout << "\n| 1 Edit Event | 2 Create Event | 3 Back to Menu | 0 Exit | >";
    cin >> choice;

    switch (choice) {
    case 1: editEvent(); break;
    case 2: createEvent(); break;
    case 3: modeSelection(""); break;
    case 0: cout << "Bye!"; break;
    default: guestEventList();
    }
}

void guestEventList() {
    int choice;
    system("cls");
    cout << "You are: Guest\n";
    showEvents();
    cout << "\n| 1 Event Details | 2 Back To Menu | 0 Exit | >";
    cin >> choice; 

    switch (choice) {
    case 1: showEventDetails(); break;
    case 2: modeSelection(""); break;
    case 0: cout << "Bye!"; break;
    default: guestEventList();
    }
}

void showEventDetails()
{
    cout << "\n| 1 Join Event | 2 Back | ";
}

void createEvent() {
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
    cout << '\a' << "Event added successfully!\n";
    cin.ignore();

    saveData(); // Save data after adding a student
    adminEventList();
}

void joinEvent()
{
}

void editEvent() {
    int id;
    system("cls");
    showEvents();
    cout << "\nSelect Event ID: >";
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
            adminEventList();
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";

    
}


void deleteEvent()
{
}

void printReceipt()
{
}

void outputSucess()
{
}

void saveToFile()
{
}

void loadFromFile()
{
}

void eventBooking()
{
}

void eventMarketing()
{
}

void eventPayment()
{
}

void eventMonitoring()
{
}

void eventReporting()
{
}
