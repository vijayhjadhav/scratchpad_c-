#include <iostream>
using namespace std;

enum class Color
{
	GREEN = 0,
	RED,
	BLUE
};

enum class TrafficLights : char
{
	GREEN = 'g',
	RED = 'r',
	YELLOW = 'y'
};

void Drive(TrafficLights color)
{
	switch (color)
	{
	case TrafficLights::GREEN:
		cout << "Go" << endl;
		break;

	case TrafficLights::RED:
		cout << "Stop" << endl;
		break;

	case TrafficLights::YELLOW:
		cout << "Slow down" << endl;
		break;

	default:
		cout << "Not working" << endl;
		break;
	}
}

void fillColor(Color color)
{
	switch (color)
	{
	case Color::GREEN:
		cout << "Green" << endl;
		break;

	case Color::RED:
		cout << "Red" << endl;
		break;
	case Color::BLUE:
		cout << "Blue" << endl;
		break;

	default:
		cout << "No color" << endl;
		break;
	}
}


int main()
{
	Drive(TrafficLights::GREEN);
	Drive(TrafficLights::YELLOW);
	Drive(TrafficLights::RED);

	fillColor(Color::BLUE);
	fillColor(Color::RED);
	fillColor(Color::GREEN);
	return 0;
}