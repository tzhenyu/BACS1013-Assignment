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
const string FILE_PATH = "info.txt"; // File path
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

//Main menu
int main() {
    welcomeScreen();
    modeSelection("Are you Host or Guest? Prompt to select: ");

}


//Other functions
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


void adminEventList() {
    system("cls");
    cout << "You are: Host\n";
    showEvents();
    int choice;
    cout << "\n| 1 Edit Event | 2 Create Event | 0 Exit | >";
    cin >> choice;

    switch (choice) {
    case 1: editEvent(); break;
    case 2: createEvent(); break;
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

void createEvent()
{
}

void joinEvent()
{
}

void editEvent()
{
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
