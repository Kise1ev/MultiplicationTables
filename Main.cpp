#include "MultiplicationTables.h"

void practice() {
    int selection = 0;

    cout << "1. Table sets in numerical order" << endl;
    cout << "2. Random multiplication problems" << endl;
    cout << "Please choose which you would like to practice: ";
    cin >> selection;

    switch (selection) {
    case 1:
        tableSets();
        break;
    case 2:
        generateTables();
        break;
    default:
        cout << "Invalid input." << endl << endl;
        practice();
        break;
    }
}

void generateTables() {
    int max = 0, numProblems = 0;
    int product = 0, guess = 0;

    cout << endl << "How high would you like the randomizer to go? ";
    cin >> max;
    cout << "How many problems would you like to do? ";
    cin >> numProblems;

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < numProblems; i++) {
        int x = rand() % max + 1;
        int y = rand() % max + 1;

        product = x * y;

        cout << "What is " << x << " x " << y << "? ";
        cin >> guess;

        if (guess == product)
            cout << "Good job, that's correct!" << endl << endl;
         else 
            cout << "Actually, the correct answer to " << x << " x " << y << " is " << product << endl << endl;
    }

    morePractice();
}

void tableSets() {
    int tableChoice = 0, maxTable = 0;
    int product = 0, guess = 0;

    cout << endl << "Which number multiplication table would you like to practice? ";
    cin >> tableChoice;
    cout << "How high would you like the tables to go? ";
    cin >> maxTable;

    for (int i = 0; i <= maxTable; i++) {
        product = tableChoice * i;
        cout << tableChoice << " x " << i << " = ";
        cin >> guess;

        if (guess == product)
            cout << "Correct!" << endl << endl;
         else 
            cout << "Incorrect, " << tableChoice << " x " << i << " = " << product << endl << endl;
    }

    morePractice();
}

void morePractice() {
    char yesNo = ' ';

    cout << "Would you like to keep practicing? (Y/N): ";
    cin >> yesNo;
    cout << endl;

    if (tolower(yesNo) == 'y') {
        practice();
        return;
    }
    
    if (tolower(yesNo) == 'n') {
        cout << "Come back soon!" << endl;
        return;
    }

    cout << "Invalid input." << endl << endl;
    morePractice();
}

int main() {
    practice();

    cout << endl;

    system("pause");
    return 0;
}
