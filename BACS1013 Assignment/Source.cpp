#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

//Function initialization
void welcomeScreen();
void modeSelection();
void logIn();
void showEventList();
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
const int MAX_RECORDS = 100;

//Vairiable declaration

//main menu
int main() {
    welcomeScreen();
    modeSelection();

}

void welcomeScreen()
{
    cout << "Hi test, press ENTER to continue...";
    cin.ignore();
    
}

void modeSelection()
{
    system("cls");
    cout << "Are you Host or Guest? Prompt to select: " << endl;
    cout << "[1] Host" << endl;
    cout << "[2] Guest" << endl;
    
}

void logIn()
{
}

void showEventList()
{
}

void showEventDetails()
{
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
