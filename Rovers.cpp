#pragma once
#include "Rovers.h"
Rovers::Rovers()
{
}
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
void Rovers::setN(int n)
{
	Checknumb = n;
}
int Rovers::getN()
{
	return Checknumb;
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
Rovers Rovers::operator=(Rovers const& rov)
{
	Rovers r;
	r.RoverType = rov.RoverType;
	r.CheckupDuration = rov.CheckupDuration;
    r.Speed = rov.Speed;
    r.MissionCount = rov.MissionCount;
	r.Inmaintainance = rov.Inmaintainance;
	r.Entercheck = rov.Entercheck;
	r.Checknumb = rov.Checknumb;
	return r;
}
