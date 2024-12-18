#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>
#include <conio.h>
#include <sstream>
#include <windows.h> 
#include <vector>

using namespace std;

//Function initialization
void setColor(int textColor, int bgColor);
void welcomeScreen();
void modeSelection();
void logIn();

void loadData();
void saveData();

void hostEventList();
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
void exitProgram();
void changeCursorStyle(bool visible);

//zhengyuan function
void hostEventManagement();
//void guestEventManagement();
bool advertisementExists(size_t num);
void deleteAdvertisement(size_t num);
void editAdvertisement(size_t num, const string& newTitle, const string& newDescription, const string& newPax, const string& newFee);
void viewAdvertisement();
void addAdvertisement(const string& title, const string& description, const string& pax, const string& fee);
struct Advertisement;
//void eventAdvertisingMenu();

//Constant variable declaration
const string FILE_PATH = "data.txt"; // File path
const int records = 100;             // Event Max Record 

//vatriable data that need to save
int eventId[records];
string eventName[records];
string eventStartDate[records];
string eventEndDate[records];
string eventPlace[records];
string eventAdvertisement[records];
int eventPax[records];
vector<Advertisement> advertisements;



int eventCount = 0;  // Current number of events
int nextEventId = 1;   // Auto-increment ID counter
int headerColor = 8; // menu color
int selectedEventId;
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
            << eventAdvertisement[i]<< ","
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
        getline(ss, eventAdvertisement[eventCount]);
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
    case 2: hostEventList(); break;
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


void hostEventList() {
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
    default: hostEventList();
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
        cin.ignore();
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
    //case 2: guestEventManagement(); break;
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
    hostEventList();
}

struct EventRegistration {
    string name;
    string email;
    int eventId;
    EventRegistration(string n, string e, int id) : name(n), email(e), eventId(id) {}
};

vector<EventRegistration> registrations;  // Vector to store registrations

void joinEvent() {
    int eventId;
    string name, email;

    system("cls");  
    cout << "----- Join Event Form -----\n\n";

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "\nEnter the Event ID you want to join: ";
    cin >> eventId;
    cin.ignore();

    cout << "\nYou are about to join Event ID " << eventId << ".\n";
    cout << "Name: " << name << "\n";
    cout << "Email: " << email << "\n";

    char confirm;
    cout << "Do you want to confirm your registration? (Y/N): ";
    cin >> confirm;
    cin.ignore();

    if (confirm == 'Y' || confirm == 'y') {
        // Save the registration details to the vector
        registrations.push_back(EventRegistration(name, email, eventId));
        cout << "\nYou have successfully joined the event!\n";
    }
    else {
        cout << "\nRegistration canceled.\n";
    }

    cout << "\nPress any key to return to the event list...";
    cin.get();
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
        selectedEventId = id;
        system("clear");
        cout << "[1] Event Advertisement" << endl;
        cout << "[2] Event " << endl;
        cout << "[3] Event " << endl;
        cout << "[4] Event " << endl;
        cout << "[5] Back To Menu " << endl;
        id = _getch() - '0';

        switch (id) {
        case 1: hostEventManagement();
        case 5: hostEventList();
        }
    }
}


void deleteEvent(){ 
    int eventIdToDelete;
    setColor(8, 0);
    system("cls");

    setColor(15, headerColor);
    cout << setw(80) << ' ' << endl;
    cout << right << setw(55) << "Enter Event ID to delete (0 to cancel)" << setw(25) << ' ';

    setColor(8, 0);
    showEvents(); 

    eventIdToDelete = _getch() - '0'; // Assuming ID is a single digit for simplicity

    if (eventIdToDelete == 0) {
        guestEventList();  
        return;
    }

    // Validate if the event ID exists
    bool found = false;
    for (int i = 1; i < eventCount; ++i) {
        if (eventId[i] == eventIdToDelete) {
            found = true;
            // Shift events after the deleted event
            for (int j = i; j < eventCount - 1; ++j) {
                eventId[j] = eventId[j + 1];
                eventName[j] = eventName[j + 1];
                eventStartDate[j] = eventStartDate[j + 1];
                eventEndDate[j] = eventEndDate[j + 1];
                eventPlace[j] = eventPlace[j + 1];
                eventPax[j] = eventPax[j + 1];
            }

            eventCount--;  // Decrease event count
            cout << "Event deleted successfully!" << endl;
            saveData();  
            break;
        }
    }

    if (!found) {
        cout << "\aInvalid Event ID! No event found with the given ID." << endl;
    }

    cout << "Press any key to return to event list..." << endl;
    _getch();
    adminEventList();
    }

void printReceipt() {
    int eventIdSelected;
    setColor(8, 0);
    system("cls");

    setColor(15, headerColor);
    cout << setw(80) << ' ' << endl;
    cout << right << setw(55) << "Select Event ID for Receipt (0 to cancel)" << setw(25) << ' ';
    setColor(8, 0);

    showEvents();  // Show event list to select from

    eventIdSelected = _getch() - '0';

    if (eventIdSelected == 0) {
        adminEventList();  
        return;
    }

    if (eventIdSelected < 1 || eventIdSelected >= eventCount) {
        system("cls");
        cout << "\a" << "Invalid Event ID!" << endl;
        cout << "Press any key to continue..." << endl;
        _getch();
        printReceipt(); 
    }

    system("cls");
    setColor(15, headerColor);
    cout << setw(80) << ' ' << endl;
    cout << right << setw(50) << "Event Receipt" << setw(30) << ' ' << endl;
    setColor(8, 0);

    system("cls"); 
    setColor(15, 0);
    cout << "----------------------------------------\n";
    cout << "              Event Receipt             \n";
    cout << "----------------------------------------\n";
    cout << "\nEvent Name: " << eventName[eventIdSelected] << endl;
    cout << "Start Date: " << eventStartDate[eventIdSelected] << endl;
    cout << "End Date: " << eventEndDate[eventIdSelected] << endl;
    cout << "Location: " << eventPlace[eventIdSelected] << endl;
    cout << "Number of Participants: " << eventPax[eventIdSelected] << endl;
    cout << "\nThank you for registering!" << endl;
    cout << "----------------------------------------\n";
    cout << "Thank you for joining the event!\n";
    cout << "----------------------------------------\n";

    cout << "\nPress any key to return to the event list...";
    _getch();
    adminEventList();
  }

 

void outputSucess()
{   cout << "\a" << "Operation completed successfully!" << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore(2);
}

void saveToFile()
{   ofstream outFile(FILE_PATH);
    if (!outFile) {
        cout << "Error saving data to file." << endl;
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
    cout << "\a" << "Data saved successfully!" << endl;
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
{   setColor(8, 0);
    system("cls");

    cout << "-------- Event Monitoring --------" << endl;
    cout << "ID | Event Name                | Registrations" << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 1; i < eventCount; i++) {
        cout << eventId[i] << " | " << setw(25) << left << eventName[i]
            << " | " << eventPax[i] << endl;
    }

    cout << "\nPress Enter to continue..." << endl;
    cin.ignore();  
    adminEventList();
}

void eventReporting()
{
    setColor(8, 0);
    system("cls");

    cout << "-------- Event Report --------" << endl;
    for (int i = 1; i < eventCount; i++) {
        cout << "Event ID: " << eventId[i] << endl;
        cout << "Event Name: " << eventName[i] << endl;
        cout << "Start Date: " << eventStartDate[i] << endl;
        cout << "End Date: " << eventEndDate[i] << endl;
        cout << "Total Registrations: " << eventPax[i] << endl;
        cout << "----------------------------" << endl;
    }

    cout << "\nPress Enter to continue..." << endl;
    cin.ignore(); 
    adminEventList();
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

//ZHENGYUAN PART 
struct Advertisement {
    string title, description, pax, fee;

    Advertisement(string t, string d, string p, string f)
        : title(t), description(d), pax(p), fee(f) {
    }

    void display() const {
        system("clear");

        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Pax: " << pax << endl;
        cout << "Fee: " << fee << endl;
    }
};

void addAdvertisement(const string& title, const string& description, const string& pax, const string& fee) {
    advertisements.emplace_back(title, description, pax, fee);
    cout << "\a" << "Advertisement added successfully!" << endl;
    cin.ignore();
}

//void viewAdvertisement() {
//    system("clear");
//
//    if (advertisements.empty()) {
//        cout << "No advertisements available! Check back later." << endl;
//        cin.ignore();
//    }
//    else {
//        for (size_t i = 0; i < advertisements.size(); ++i) {
//            cout << "\nAdvertisement " << i + 1 << ":" << endl;
//            advertisements[i].display();
//        } cin.ignore();
//    }
//}

void viewAdvertisement() {
    system("clear");

    cout << "Name:" << eventName[selectedEventId] << endl;
    cout << "Start Date: " << eventStartDate[selectedEventId] << endl;
    cout << "End Date: " << eventEndDate[selectedEventId] << endl;
    cout << "Pax: " << eventPax[selectedEventId] << endl;
    cin.ignore();
}



void editAdvertisement(size_t num, const string& newTitle, const string& newDescription, const string& newPax, const string& newFee) {
    system("clear");

    if (num < advertisements.size()) {
        advertisements[num].title = newTitle;
        advertisements[num].description = newDescription;
        advertisements[num].pax = newPax;
        advertisements[num].fee = newFee;
        cout << "Advertisement updated successfully!" << endl;
    }
    else {
        cout << "Invalid advertisement number! Please try again." << endl;
    }
}

void deleteAdvertisement(size_t num) {
    system("clear");

    if (num < advertisements.size()) {
        advertisements.erase(advertisements.begin() + num);
        cout << "Advertisement deleted successfully!" << endl;
    }
    else {
        cout << "Invalid advertisement number! Please try again." << endl;
    }
}

bool advertisementExists(size_t num) {
    return num < advertisements.size();
}

void eventManagementDisplay() {
    system("clear");

    cout << "\n------- Advertisement Menu -------\n";
    cout << "[1] Add Advertisement\n";
    cout << "[2] View Advertisement\n";
    cout << "[3] Edit Advertisement\n";
    cout << "[4] Delete Advertisement\n";
    cout << "[5] Return to Main Menu\n";

}

void hostEventManagement() {
    int choice;
    system("clear");
    do {
        eventManagementDisplay();
        choice = _getch() - '0';

        switch (choice) {
        case 1: {
            string title, description, pax, fee;

            cout << "Enter the title: ";
            getline(cin, title);
            cout << "Enter the description: ";
            getline(cin, description);
            cout << "Number of pax: ";
            getline(cin, pax);
            cout << "Amount of fee: ";
            getline(cin, fee);

            addAdvertisement(title, description, pax, fee);
            break;
        }
        case 2:
            viewAdvertisement();
            break;

        case 3: {
            size_t num;
            cout << "Enter advertisement number to edit: ";
            cin >> num;
            cin.ignore();

            if (advertisementExists(num - 1)) {
                string newTitle, newDescription, newPax, newFee;
                cout << "Enter new title: ";
                getline(cin, newTitle);
                cout << "Enter new description: ";
                getline(cin, newDescription);
                cout << "Enter new number of pax: ";
                getline(cin, newPax);
                cout << "Enter new amount of fee: ";
                getline(cin, newFee);

                editAdvertisement(num - 1, newTitle, newDescription, newPax, newFee);
            }
            else {
                cout << "Advertisement does not exist! Please try again." << endl;
            }
            break;
        }

        case 4: {
            size_t num;
            cout << "Enter advertisement number to delete: ";
            cin >> num;

            if (advertisementExists(num - 1)) {
                deleteAdvertisement(num - 1);
            }
            else {
                cout << "Advertisement does not exist! Please try again." << endl;
            }
            break;
        }

        case 5:
            hostEventList();
            break;

        default:
            cout << "Invalid option! Please try again." << endl;
        }
    } while (choice != 5);
}

//NOT GONNA USE IT 
//BECAUSE ALREADY HAVE HOST AND GUEST SELECTION BEFORE THIS

//void eventAdvertisingMenu() {
//
//    int choice;
//
//    do {
//        system("clear");
//
//        cout << "\nMain Menu\n";
//        cout << "1. Host\n";
//        cout << "2. Guest\n";
//        cout << "3. Exit Program\n"; 
//        cout << "Enter your option: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            hostEventManagement();
//            break;
//
//        case 2:
//            cout << "GUEST VIEW" << endl;
//            viewAdvertisements();
//            break;
//
//        case 3:
//            cout << "Exiting Program. Goodbye!" << endl;
//            break;
//
//        default:
//            cout << "Invalid choice! Please try again." << endl;
//        }
//    } while (choice != 3);
//}