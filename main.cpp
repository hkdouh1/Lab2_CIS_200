#include "ElectricVehicle.h"
#include <iostream>
using namespace std;

int main() 
{
    string make, model, color;
    double batteryCapacity, efficiency;

    cout << "Enter the vehicle's make: ";
    cin >> make;
    cout << "Enter the vehicle's model: ";
    cin >> model;
    cout << "Enter the vehicle's color: ";
    cin >> color;
    cout << "Enter the battery capacity (kWh): ";
    cin >> batteryCapacity;
    cout << "Enter the efficiency (km/kWh): ";
    cin >> efficiency;

    ElectricVehicle ev(make, model, color, batteryCapacity, efficiency);

    char choice;

    do {
        ev.displayDetails();
        cout << "\nMenu:\n"
            << "1. Charge the battery\n"
            << "2. Drive the vehicle\n"
            << "3. Quit\n"
            << "Enter your choice: ";
        cin >> choice;

        try {
            if (choice == '1') 
            {
                double chargeAmount;
                cout << "Enter the amount of charge (kWh): ";
                cin >> chargeAmount;
                ev.charge(chargeAmount);
                cout << "Battery charged successfully.\n";
            }
            else if (choice == '2') 
            {
                double driveDistance;
                cout << "Enter the distance to drive (km): ";
                cin >> driveDistance;
                ev.drive(driveDistance);
                cout << "Drive successful.\n";
            }
            else if (choice == '3') 
            {
                cout << "Exiting the program.\n";
            }
            else 
            {
                cout << "Invalid choice! Please try again.\n";
            }
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << "\n";
        }
    } while (choice != '3');

    return 0;
}
