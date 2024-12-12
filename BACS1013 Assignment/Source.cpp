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
void exitProgram();
void changeCursorStyle(bool visible);

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
int headerColor = 8; // menu color

//box character for aesthetic purpose

int topRightCorner = 191;
int topLeftCorner = 218; 
int btmRightCorner = 217;
int btmLeftCorder = 192;
int topInter = 194;
int btmInter = 193;
int leftInter = 195;
int rightInter = 180;
int centerInter = 197;
int horizon = 196;
int vert = 179;

//Main menu
int main() {
    SetConsoleCP(437);        //able to display character box
    SetConsoleOutputCP(437);  //able to display character box
    changeCursorStyle(false); //make text cursor disappear
    modeSelection();
}


//Other functions
void setColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,
        (bgColor << 4) | textColor);
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

    eventCount = 1;
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
    cout << "\n\n\n\n\n\n\n\n\n" << endl;
    cout << right << setw(43) << "Are you?" << endl;
    cout << right << setw(44) << "[1]  Guest" << endl;
    cout << right << setw(44) << "[2]   Host" << endl;
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

    cout << right << setfill((char)horizon) << (char)topLeftCorner << setw(3) << (char)topInter << setw(38) << (char)topInter << setw(16) << (char)topInter << setw(16) << (char)topInter << setw(6) << (char)topRightCorner;

    cout << left << setfill(' ');
    cout << (char)vert
        << setw(2) << left << "ID" << right << (char)vert
        << setw(37) << left << "Title" << right << (char)vert
        << setw(15) << left << "Start Date" << right << (char)vert
        << setw(15) << left << "End Date" << right << (char)vert
        << setw(5) << left << "Pax" << right << (char)vert << endl;

    cout << right << setfill((char)horizon) << (char)leftInter << setw(3) << (char)centerInter << setw(38) << (char)centerInter << setw(16) << (char)centerInter << setw(16) << (char)centerInter << setw(6) << (char)rightInter;


    cout << setfill(' ');

    if (eventCount == 0) {
        cout << "\nNo event currently.\n";
        return;
    }

    for (int i = 1; i < 19; i++) {
        if (eventId[i] == 0) {
            cout << (char)vert << setw(2) << left << " "
                << (char)vert<< setw(37) << left << " "
                << (char)vert<< setw(15) << left << " "
                << (char)vert<< setw(15) << left << " "
                << (char)vert<< setw(5) << left << " "
                << (char)vert<< endl;
        }
        else {
            cout << (char)vert << setw(2) << left << eventId[i]
                << (char)vert << setw(37) << left << eventName[i]
                << (char)vert << setw(15) << left << eventStartDate[i]
                << (char)vert << setw(15) << left << eventEndDate[i]
                << (char)vert << setw(5) << left << eventPax[i]
                << (char)vert << endl;
        }





    }
    cout << right << setfill((char)horizon) << (char)btmLeftCorder << setw(3) << (char)btmInter << setw(38) << (char)btmInter << setw(16) << (char)btmInter << setw(16) << (char)btmInter << setw(6) << (char)btmRightCorner;
    cout << setfill(' ');
}


void adminEventList() {
    int nextEventId = 1;   // Auto-increment ID counter
    int choice;
    setColor(8, 0);
    system("cls");

    setColor(15, headerColor);
    cout << setw(44) << right << "Host Menu" << setw(36) << ' ' << endl;
    cout << setw(67) << right << "[1] Edit Event [2] Create Event [3] Back to Menu [0] Exit" << setw(13) << ' ' << endl;
    setColor(8, 0);

    showEvents();

    choice = _getch() - '0';


    switch (choice) {
    case 1: editEvent(); break;
    case 2: createEvent(); break;
    case 3: modeSelection(); break;
    case 0: exitProgram(); break;
    default: adminEventList();
    }
}

void guestEventList() {
    int choice;
    setColor(8, 0);
    system("cls");

    setColor(15, headerColor);
    cout << setw(45) << right << "Guest Menu" << setw(35) << ' ' << endl;
    cout << setw(63) << right << "[1] Show Concert Detail [2] Back To Menu [0] Exit" << setw(17) << ' ' << endl;
    setColor(8, 0);

    showEvents();


    choice = _getch() - '0';

    switch (choice) {
    case 1: showEventDetails(); break;
    case 2: modeSelection(); break;
    case 0: exitProgram(); break;
    default: guestEventList();
    }
}

void showEventDetails()
{
    int id, choice;
    setColor(8, 0);
    system("cls");

    setColor(15, headerColor);
    cout << setw(80) << ' ' << endl;
    cout << right << setw(55) << "Select Concert ID (0 to cancel)" << setw(25) << ' ';

    setColor(8, 0);
    showEvents();

    id = _getch() - '0';

    if (id == 0) {
        guestEventList();
    }

    if (id  < 1 || id >= eventCount) {
        system("cls");
        cout << "\a" << "Invalid ID!" << endl;
        cout << "Press Anything to continue..." << endl;
        _getch();
        showEventDetails();

    }
    system("cls");
    setColor(15, headerColor);
    cout << setw(80) << ' ' << endl;
    cout << right << setw(68) << "[1] Participate [2] View Advertisement [3] Back to menu" << setw(12) << " " << "\n\n";
    setColor(8, 0);

    cout << setw(15) << left << "Name: " << eventName[id] << endl;
    cout << setw(15) << left << "Start Date: " << eventStartDate[id] << endl;
    cout << setw(15) << left << "End Date: " << eventEndDate[id] << endl;
    cout << setw(15) << left << "Pax: " << eventPax[id] << endl;

    choice = _getch() - '0';

    switch (choice) {
    case 1: joinEvent(); break;
    case 2: viewAdvertisement(); break;
    case 3: guestEventList(); break;
    default: cout << '\a'; guestEventList();
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

    setColor(15, headerColor);
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
        //do your thing
        system("cls");
        cout << "Options..." << endl;
    }


    
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

void exitProgram()
{
    system("cls");

    cout << "\n\n\n\n\n\n";
    cout << "                               ____              _ " << endl;
    cout << "                              (  _ \\            ( )" << endl;
    cout << "                              | (_) )_   _   __ | | " << endl;
    cout << "                              |  _ (( ) ( )/ __ \\ |" << endl;
    cout << "                              | (_) ) (_) |  ___/_) " << endl;
    cout << "                              (____/ \\__  |\\____) " << endl;
    cout << "                                    ( )_| |     (_) " << endl;
    cout << "                                     \\___/         " << endl;
    cout << "\n                          Press Anything to Continue..." << endl;


    setColor(0,0);

}

void changeCursorStyle(bool visible) {
    // Obtain handle to the console output
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Create a cursor info structure
    CONSOLE_CURSOR_INFO cursorInfo;

    // Set cursor visibility and size
    cursorInfo.bVisible = visible;  // Visibility: true or false
    cursorInfo.dwSize = 100;

    // Apply the settings
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}