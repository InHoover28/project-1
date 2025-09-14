/*
Program: Cypress Cyborg's Ticket Sales
Author:India Hoover
Date:11/28/2024
This program helps the ticket sales team complete three different, yet necessary tasks
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// The function to calculate ticket order cost-
void calculateTicketOrder() {
    double numTickets, costPerTicket;
    while (true) {
        cout << "Enter the number of tickets: ";
        cin >> numTickets;
        if (cin.fail() || numTickets <= 0) {
            cin.clear(); // This is only to clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This is to ignore the invalid input so as not to affect the rest of the program
            cout << "Invalid input. Number of tickets must be a positive number.\n";
            continue;
        }

        cout << "Enter the cost per ticket: ";
        cin >> costPerTicket;
        if (cin.fail() || costPerTicket <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Cost per ticket must be a positive number.\n";
            continue;
        }

        double totalCost = numTickets * costPerTicket;
        cout << fixed << setprecision(2) << "The total cost of the order is: $" << totalCost << "\n\n";
        break;
    }
}

// The function to generate a promotional offer-
void promotionalOffer() {
    string patronName;
    double discountAmount;

    cout << "Enter the patron's name: ";
    cin.ignore(); // This is to clear the input buffer
    getline(cin, patronName);

    while (true) {
        cout << "Enter the discount amount: ";
        cin >> discountAmount;
        if (cin.fail() || discountAmount <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Discount amount must be a positive number.\n";
            continue;
        }

        cout << "Hello " << patronName << ", Call today to get $" << fixed << setprecision(2)
            << discountAmount << " Off Cypress Cyborgs tickets for this week's game!\n\n";
        break;
    }
}

// The function to calculate percentage of tickets sold-
void percentageTicketsSold() {
    double totalCapacity, availableTickets;

    while (true) {
        cout << "Enter the total capacity (number of tickets available): ";
        cin >> totalCapacity;
        if (cin.fail() || totalCapacity <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Total capacity must be a positive number.\n";
            continue;
        }

        cout << "Enter the number of tickets still available: ";
        cin >> availableTickets;
        if (cin.fail() || availableTickets < 0 || availableTickets > totalCapacity) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Available tickets must be a positive number less than or equal to total capacity.\n";
            continue;
        }

        double ticketsSold = totalCapacity - availableTickets;
        int percentageSold = static_cast<int>((ticketsSold / totalCapacity) * 100 + 0.5); // This is to round to nearest whole number
        cout << "Percentage of tickets sold: " << percentageSold << "%\n\n";
        break;
    }
}

// This is the Main function
int main() {
    int choice;

    do {
        cout << "Welcome Cypress Cyborgs Sales Team!\n\n";
        cout << "1. Calculate the cost of a ticket order\n";
        cout << "2. Get a promotional offer for your patron\n";
        cout << "3. Calculate the percentage of total tickets sold\n";
        cout << "4. Quit\n";
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0; // This forces invalid choice message
        }

        switch (choice) {
        case 1:
            calculateTicketOrder();
            break;
        case 2:
            promotionalOffer();
            break;
        case 3:
            percentageTicketsSold();
            break;
        case 4:
            cout << "Thank you for using the Cypress Cyborgs program. Goodbye!\n";
            break;
        default:
            cout << "Invalid input! Please enter a valid number (1-4).\n\n";
        }

        if (choice != 4) {
            char repeat;
            cout << "Would you like to perform another task? (Y/N): ";
            cin >> repeat;
            if (tolower(repeat) != 'y') {
                cout << "Thank you for using the Cypress Cyborgs program. Goodbye!\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

