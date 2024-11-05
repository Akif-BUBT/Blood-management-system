
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include<thread>
#include<windows.h>
#include<chrono>



using namespace std;
void display_dashboard();
void refresh_screen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For macOS/Linux
#endif
}

void register_user() {
    string name, phone, email, blood_group, last_donation, password;

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your phone (this will be your ID): ";
    getline(cin, phone);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your blood group: ";
    getline(cin, blood_group);

    cout << "Enter your last donation time: ";
    getline(cin, last_donation);

    cout << "Create a password: ";
    getline(cin, password);

    // Save user data to the corresponding blood group file
    ofstream file(blood_group + ".txt", ios::app);
    file << phone << "," << password << "," << name << "," << email << "," << blood_group << "," << last_donation << endl;
    file.close();

    cout << "Registration successful!\n";\
    display_dashboard();
}

void login_user() {
    string phone, password;
    cout << "Enter your phone (user ID): ";
    cin >> phone;

    cout << "Enter your password: ";
    cin >> password;

    // Check the corresponding blood group file (you can enhance this part by getting the blood group first)
    string blood_group;
    cout << "Enter your blood group for login: ";
    cin >> blood_group;

    ifstream file(blood_group + ".txt");
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(",");
        string stored_phone = line.substr(0, pos);

        size_t pos2 = line.find(",", pos + 1);
        string stored_password = line.substr(pos + 1, pos2 - pos - 1);

        if (stored_phone == phone && stored_password == password) {
            cout << "Login successful! Welcome, " << line.substr(pos2 + 1) << "!\n";
            return;  // User found and logged in
        }
    }

    cout << "Invalid phone number or password.\n";
}

void display_dashboard()
{
    cout << "\t\t\t\t\t*****************************************\n";
    cout << "\t\t\t\t\t*               Dashboard               *\n";
    cout << "\t\t\t\t\t*****************************************\n\n";

    // Sign Up button
    cout << "\t\t\t\t\t\t  *********************\n";
    cout << "\t\t\t\t\t\t  *     [1] Register   *\n";
    cout << "\t\t\t\t\t\t  *********************\n\n";

    // Log In button
    cout << "\t\t\t\t\t\t  *********************\n";
    cout << "\t\t\t\t\t\t  *     [2] Log In    *\n";
    cout << "\t\t\t\t\t\t  *********************\n\n";

    // Exit button
    cout << "\t\t\t\t\t\t  *********************\n";
    cout << "\t\t\t\t\t\t  *      [3] Exit     *\n";
    cout << "\t\t\t\t\t\t  *********************\n\n";

    cout << "\t\t\t\t\t\t  Enter your choice: ";
    int dashboard_option;
label2:
    cin >> dashboard_option;

    if (dashboard_option == 1)
    {
        register_user();
    }
    else if (dashboard_option == 2)
    {
        login_user();
    }
    else if (dashboard_option == 3)
    {
        exit(0);
    }
    else
    {
        // Centered error message
        cout << "\t\t\t\t\t\t  Invalid input. Enter again: ";
        goto label2;
    }
}

void welcome_message()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle
    SetConsoleTextAttribute(hConsole, 11);
     cout << "\t\t\t**********************************************************************\n";
    cout << "\t\t\t*                                                                    *\n";
    cout << "\t\t\t*                             WELCOME TO                             *\n";
    cout << "\t\t\t*                              RedAid                                *\n";
    cout << "\t\t\t*                  A Centralized Blood Solution Platform             *\n";
    cout << "\t\t\t*                                                                    *\n";
    cout << "\t\t\t**********************************************************************\n\n";

    cout << "\t\t\t\t\t\"Bound by Blood, Driven by Compassion\"\n\n\n";
    cout << "\t\t\t\tAuthors:\n";
    cout << "\t\t\t\t  - Mashfi Rejoan Saikat\n";
    cout << "\t\t\t\t  - Akif Uz Zaman\n";
    cout << "\t\t\t\t  - Nowshin Ashrafi\n\n";
    cout << "\t\t\t\t******************************************\n";
    cout << "\t\t\t\t*         Press 1 to continue...         *\n";
    cout << "\t\t\t\t******************************************\n\n";

    this_thread::sleep_for(chrono::seconds(4));
    system("cls");


        display_dashboard();

}

int main()
{
    welcome_message();
    return 0;
}
