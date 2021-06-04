#include "Rovers.h"


Rovers::Rovers(char roverType, int checkupDuration, int speed, int N)
{
	RoverType = roverType;
	CheckupDuration = checkupDuration;
	Speed = speed;
	MissionCount = 0;
	Inmaintainance = false;
	Entercheck = 0;
	Checknumb = N;
}



void Rovers::setRoverType(char RTYP)
{
	RoverType = RTYP;
}
char Rovers::getRoverType()
{
	return RoverType;
}

void Rovers::setCheckupDuration(int CUD)
{
	CheckupDuration = CUD;
}
int Rovers::getCheckupDuration()
{
	return CheckupDuration;
}

void Rovers::setSpeed(int s)
{
	Speed = s;
}
int Rovers::getSpeed()
{
	return Speed;
}
void Rovers::increamentMissionCount()
{
	MissionCount++;
}
int Rovers::getMissionCount(int d)
{
	if (MissionCount == Checknumb)
	{
		MissionCount = 0;
		Entercheck = d;
		return -1;
	}
	return MissionCount;
}

void Rovers::setMaintain()
{
	if (!Inmaintainance)
	{
		Speed = Speed / 2;
		Inmaintainance = true;
	}

}
void Rovers::resetMaintain()
{
	if (Inmaintainance)
	{
		Speed = Speed * 2;
		Inmaintainance = false;
	}
}
bool Rovers::Movetoavailable(int day)
{
	return (day - Entercheck == CheckupDuration);
}