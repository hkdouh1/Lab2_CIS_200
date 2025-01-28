#include "ElectricVehicle.h"

// Constructor
ElectricVehicle::ElectricVehicle(const string& make, const string& model, const string& color,
                                 double batteryCapacity, double efficiency)

    : make(make), model(model), color(color),
    batteryCapacityInKilowattHours(batteryCapacity),
    currentBatteryChargeInKilowattHours(0.0),
    kilometersPerKilowattHour(efficiency), kilometersDriven(0.0) {}

// Charge method
void ElectricVehicle::charge(double kilowattHoursToCharge) 
{

    if (currentBatteryChargeInKilowattHours + kilowattHoursToCharge > batteryCapacityInKilowattHours) 
    {
        throw invalid_argument("Charging exceeds battery capacity!");
    }

    currentBatteryChargeInKilowattHours += kilowattHoursToCharge;
}

// Drive method
void ElectricVehicle::drive(double kilometersToDrive) 
{
    double requiredCharge = kilometersToDrive / kilometersPerKilowattHour;

    if (requiredCharge > currentBatteryChargeInKilowattHours) 
    {
        throw invalid_argument("Not enough charge to drive the requested distance!");
    }

    currentBatteryChargeInKilowattHours -= requiredCharge;
    kilometersDriven += kilometersToDrive;
}

// Displaying the vehicle details
void ElectricVehicle::displayDetails() const 
{
    cout << "Vehicle Details:\n"
        << "Make: " << make << "\n"
        << "Model: " << model << "\n"
        << "Color: " << color << "\n"
        << "Battery Capacity: " << batteryCapacityInKilowattHours << " kWh\n"
        << "Current Charge: " << currentBatteryChargeInKilowattHours << " kWh\n"
        << "Efficiency: " << kilometersPerKilowattHour << " km/kWh\n"
        << "Kilometers Driven: " << kilometersDriven << " km\n";
}
