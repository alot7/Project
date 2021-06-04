#pragma once
#include <iostream>

class Rovers
{
private:
	char RoverType;
	int CheckupDuration;
	int Speed;
	int MissionCount;
	bool Inmaintainance;
	int Entercheck;
	int Checknumb;

public:
	/* Constructor */
	Rovers(char roverType, int checkupDuration, int speed, int Checknumb);

	void setRoverType(char);
	char getRoverType();

	void setCheckupDuration(int);
	int getCheckupDuration();

	void setSpeed(int);
	int getSpeed();

	void increamentMissionCount();
	int getMissionCount(int day);

	void setMaintain();
	void resetMaintain();

	bool Movetoavailable(int day);
};