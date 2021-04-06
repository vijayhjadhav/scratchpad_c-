#pragma once
class Car
{
public:
	Car();
	Car(int fuel);
	Car(int fuel, int passengers);
	~Car();

private:
	int Fuel;
	int pass;
};

