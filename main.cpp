#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Different OSs use different CLI commands to run Python
#ifdef _WIN32
// TODO: If your Windows machine runs Python in CLI with "python" instead of "py", update this line.
const string python = "python";
#else
// TODO: If your Mac/Linux machine runs Python in CLI with "python" instead of "python3", update this line.
const string python = "python3";
#endif

/*
 * Prompts the user for a filename.
 * Allows the user to enter nothing to use the default pic (autumn.jpg).
 * If the file has extension jpg, jpeg, jpe, or png
 * and it exists in the project folder, return it.
 * Otherwise, return the default pic filename.
 */
string get_filename();


/*
 * Prints the main menu of options:
 * (a) flip, (b) mirror, (c) invert, or (d) exit
 */
void print_menu();

/*
 * Prompts the user for one of the options from the menu.
 * Validates input: makes sure the user enters exactly one character
 * and that it is one of the four valid options.
 * If it isn't valid, keep prompting for input until a valid option
 * is entered.
 */
char get_manip_choice();

int main() {
    cout << "Welcome to the image manipulator!" << endl;
    string filename = get_filename();
    cout << "Using file " << filename << "." << endl;
    print_menu();
    char choice = get_manip_choice();
    cout << "Processing. Go to Python program when it opens. May take a few seconds." << endl;
    string command;
    switch (choice) {
        // Use command-line arguments to pass the filename and manip to the Python file
        case 'a': command = python + " ../render.py " + filename + " flip";
            break;
        case 'b': command = python + " ../render.py " + filename + " mirror";
            break;
        case 'c': command = python + " ../render.py " + filename + " invert";
            break;
    }
    system(command.c_str());
    return 0;
}

string get_filename() {
    string filename;
    string defaultName = "autumn.jpg";
    vector<string> existType;
    existType.resize(4);
    existType.push_back("jpg");
    existType.push_back("jpeg");
    existType.push_back("jpe");
    existType.push_back("png");
    cout << "Please enter a filename with an extension of jpg, jpeg,jpe, or png: "  << endl;
    cin >> filename;
    if (filename.empty()) {
        cout << "Entered nothing, using the default filename..."<< endl;
        return defaultName;
    }
    string::size_type index;
    index = filename.rfind('.');
    if (index != string::npos) {
        string extension = filename.substr(index+1);
        for ( string item : existType) {
            if (item == extension) {
                return filename;
            }
        }
    }
    cout << "Given extension does not exist. Using the default filename..." << endl;
    return defaultName;
}

void print_menu() {
    cout << "(a) flip" << endl
         << "(b) mirror" << endl
         << "(c) invert" << endl
         << "(d) exit" << endl;
}

char get_manip_choice() {
    cout << "Please choose one of the options from the menu:" << endl;
    char choice;
    string input;
    cin >> input;
    while ((input != "a") && (input != "b") && (input != "c") && (input != "d")) {
        cout << "Invalid input: Please choose one option from the menu:" << endl;
        cin.clear();
        cin >> input;
    }
    choice = input[0];
    return choice;
}

