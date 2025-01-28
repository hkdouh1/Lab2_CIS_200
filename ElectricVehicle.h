#pragma once

#ifndef ELECTRIC_VEHICLE_H
#define ELECTRIC_VEHICLE_H

#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

class ElectricVehicle {
private:
    string make;
    string model;
    string color;
    double batteryCapacityInKilowattHours;
    double currentBatteryChargeInKilowattHours;
    double kilometersPerKilowattHour;
    double kilometersDriven;

public:
    // Constructor
    ElectricVehicle(const string& make, const string& model, const string& color,
        double batteryCapacity, double efficiency);

    // Getters
    string getMake() const { return make; }
    string getModel() const { return model; }
    string getColor() const { return color; }
    double getBatteryCapacity() const { return batteryCapacityInKilowattHours; }
    double getCurrentCharge() const { return currentBatteryChargeInKilowattHours; }
    double getEfficiency() const { return kilometersPerKilowattHour; }
    double getKilometersDriven() const { return kilometersDriven; }

    // Methods
    void charge(double kilowattHoursToCharge);
    void drive(double kilometersToDrive);
    void displayDetails() const;
};

#endif // ELECTRIC_VEHICLE_H
