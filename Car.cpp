#include "Car.h"
#include <iostream>
Car::Car(): Car(0)
{
	std::cout << "Car::Car()" << std::endl;
}

Car::Car(int fuel): Car(fuel, 2)
{
	std::cout << "Car::Car(fuel)" << std::endl;
}

Car::Car(int fuel, int passengers)
{
	Fuel = fuel;
	pass = passengers;
	std::cout << "Car::Car(fuel, passenger)" << std::endl;
}

Car::~Car()
{
	std::cout << "Car::~Car()" << std::endl;
}
