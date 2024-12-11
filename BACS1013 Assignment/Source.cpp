#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>
#include <conio.h>
#include <sstream>
#include <windows.h> 
using namespace std;

//Function initialization
void setColor(int textColor, int bgColor);
void centralizeWord(const string word);
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
    modeSelection();
}


//Other functions

void setColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,
        (bgColor << 4) | textColor);
}


void centralizeWord(const string word) {
    const int consoleWidth = 77; // Width of the console
    int padding = (consoleWidth - word.length()) / 2; // Calculate padding

    // Ensure padding is non-negative
    if (padding < 0) {
        padding = 0;
    }

    // Output spaces for padding and then the word
    cout << string(padding, ' ') << word << endl;
}

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
    setColor(8, 0);

    int mode;

    system("cls"); //clear console screen
    cout << "\n\n\n\n\n\n\n\n" << endl;
    centralizeWord("Are you?");
    centralizeWord("[1] Guest");
    centralizeWord("[2] Host");
    mode = _getch() - '0';

    switch (mode) {
    case 1: guestEventList(); break;
    case 2: adminEventList(); break;
    default: cout << '\a'; main(); break;
    }
}

void logIn()
{
    string username, password;

}



void showEvents() {
    loadData();


    //cout << setw(80) <<  << '-';
    cout << "+--+-------------------------------------+---------------+---------------+-----+";
    cout << left << setfill(' ');
    cout << setw(3) << left << "|ID" << right << "|"
        << setw(37) << left << "Title" << right << "|"
        << setw(15) << left << "Start Date" << right << "|"
        << setw(15) << left << "End Date" << right << "|"
        << setw(5) << left << "Pax" << right << "|" << endl;
    cout << "+--+-------------------------------------+---------------+---------------+-----+";

    cout << setfill(' ');

    if (eventCount == 0) {
        cout << "\nNo event currently.\n";
        return;
    }

    for (int i = 0; i < 18; i++) {

        //cout << " " << setw(3) << left << eventId[i]
        //    << setw(38) << left << eventName[i]
        //    << setw(16) << left << eventStartDate[i]
        //    << setw(16) << left << eventEndDate[i]
        //    << setw(6) << left << eventPax[i] << endl;

        cout << "|" << setw(2) << left << eventId[i]
            << "|" << setw(37) << left << eventName[i]
            << "|" << setw(15) << left << eventStartDate[i]
            << "|" << setw(15) << left << eventEndDate[i]
            << "|" << setw(5) << left << eventPax[i] 
            << "|" << endl;



    }
    cout << "+--+-------------------------------------+---------------+---------------+-----+" << endl;

}


void adminEventList() {
    int nextEventId = 1;   // Auto-increment ID counter
    int choice;
    setColor(8, 0);
    system("cls");

    setColor(15, 1);
    cout << setw(44) << right << "Host Menu" << setw(36) << ' ' << endl;
    cout << setw(67) << right << "[1] Edit Event [2] Create Event [3] Back to Menu [0] Exit" << setw(13) << ' ' << endl;
    setColor(8, 0);

    showEvents();

    choice = _getch() - '0';


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
    setColor(8, 0);
    system("cls");
    setColor(15, 1);
    cout << setw(45) << right << "Guest Menu" << setw(35) << ' ' << endl;
    cout << setw(63) << right << "[1] Show Concert Detail [2] Back To Menu [0] Exit" << setw(17) << ' ' << endl;
    setColor(8, 0);

    showEvents();


    choice = _getch() - '0';

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
    setColor(8, 0);
    system("cls");
    setColor(15, 1);
    cout << setw(80) << ' ' << endl;
    cout << right << setw(55) << "Select Concert ID (0 to cancel)" << setw(25) << ' ';

    setColor(8, 0);

    showEvents();
    id = _getch() - '0';
    if (id == 0) {
        cout << "huh" << endl;
        guestEventList();
    }
    else {
        system("cls");
        for (int i = 0; i < eventCount; i++) {
            if (eventId[i] == id) {
                setColor(15, 1);
                cout << setw(80) << left << "[1] Join Event [2] View Advertisement [3] Back to menu" << "\n\n";
                setColor(8, 0);

                cout << setw(15) << left << "Name: " << eventName[i] << endl;
                cout << setw(15) << left << "Start Date: " << eventStartDate[i] << endl;
                cout << setw(15) << left << "End Date: " << eventEndDate[i] << endl;
                cout << setw(15) << left << "Pax: " << eventPax[i] << endl;

                choice = _getch() - '0';


                switch (choice) {
                case 1: joinEvent(); break;
                case 2: viewAdvertisement(); break;
                case 3: guestEventList(); break;
                default: cout << '\a'; guestEventList();
                }
            }
        }

    }


}



void createEvent() {
    setColor(8, 0);
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
    setColor(8, 0);
    system("cls");

    setColor(15, 1);
    cout << setw(80) << left << "Select Concert ID (0 to cancel)" << "\n\n";
    setColor(8, 0);

    showEvents();

    

    id = _getch() + '0';

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
