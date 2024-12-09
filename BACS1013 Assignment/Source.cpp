#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>
#include <conio.h>
#include <sstream>
using namespace std;

//Function initialization
void welcomeScreen();
void modeSelection();
void logIn();

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
void viewAdvertisement();
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
const int records = 100;             // Event Max Record 

//vatriable data that need to save
int eventId[records];
string eventName[records];
string eventStartDate[records];
string eventEndDate[records];
string eventPlace[records];
int eventPax[records];

int eventCount = 0;  // Current number of events
int nextEventId = 1;   // Auto-increment ID counter

//Main menu
int main() {
    int mode;

    system("cls"); //clear console screen

    cout << "are you ?" << endl;
    cout << "1 guest" << endl;
    cout << "2 host" << endl;
    cin >> mode; 

    switch (mode) {
    case 1: guestEventList(); break;
    case 2: adminEventList(); break;
    default: cout << '\a'; main(); break;
    }

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

    eventCount = 0;
    string line;
    while (getline(inFile, line) && eventCount < records) {
        istringstream ss(line);
        string token;

        getline(ss, token, ',');
        eventId[eventCount] = stoi(token);

        getline(ss, eventName[eventCount], ',');
        getline(ss, eventStartDate[eventCount], ',');
        getline(ss, eventEndDate[eventCount], ',');
        getline(ss, eventPlace[eventCount], ',');

        getline(ss, token);
        eventPax[eventCount] = stoi(token);

        eventCount++;
    }

    if (eventCount > 0) {
        nextEventId = eventId[eventCount - 1] + 1;
    }
    inFile.close();
}

void welcomeScreen()
{
    
}

void modeSelection()
{

}

void logIn()
{
    string username, password;

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
    case 3: modeSelection(); break;
    case 0: cout << "Bye!"; break;
    default: adminEventList();
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
    case 2: modeSelection(); break;
    case 0: cout << "Bye!"; break;
    default: guestEventList();
    }
}

void showEventDetails()
{
    int id, choice;
    system("cls");
    showEvents();
    cout << "\nSelect Event ID: >";
    cin >> id;

    system("cls");
    for (int i = 0; i < eventCount; i++) {
        if (eventId[i] == id) {

            cout << "Name: " << eventName[i] << endl;
            cout << "Start Date: " << eventStartDate[i] << endl;
            cout << "End Date: " << eventEndDate[i] << endl;
            cout << "Pax: " << eventPax[i] << endl;
           
            cout << "\n| 1 Join Event | 2 View Advertisement | 3 Back to menu | >";
            cin >> choice;

            switch (choice) {
            case 1: joinEvent(); break;
            case 2: viewAdvertisement(); break;
            case 3: guestEventList(); break;
            default: cout << '\a'; guestEventList();
            }
        }
    }
}

void createEvent() {
    system("cls");
    if (eventCount >= records) {
        cout << "Cannot add event! Reached maximum storage!\n";
        return;
    }

    eventId[eventCount] = nextEventId++;  // Assign auto-increment ID
    cout << "Enter event name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, eventName[eventCount]);
    cout << "Enter event pax: ";
    cin >> eventPax[eventCount];

    eventCount++; // Increment the count


    cout << '\a' << "Event added successfully! Press Enter to continue...";

    cin.ignore(2); 

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

    //do your thing
    cout << "Options..." << endl;
    
}


void deleteEvent()
{
}

void viewAdvertisement()
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
