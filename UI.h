/*#pragma once
#include <fstream>
#include <iostream>
#include "PriQueue.h"
#include "LinkedQueue.h"
#include "Missions.h"

using namespace std;
class MarsStation;
class Event;


class UI
{
	MarsStation* pMars;


public:
	UI(MarsStation* Mars);
	void Mode(PriQueue<missions> Emergency,LinkedQueue<missions> Polar, PriQueue<missions> InEx, PriQueue<Rovers> AvailERovers, PriQueue<Rovers> AvailPRovers, LinkedQueue<Rovers> ICUERovers, LinkedQueue<Rovers> ICUPRovers, LinkedQueue<missions> CMissions);
	void PrintWait(PriQueue<missions> Emergency,LinkedQueue<missions> Polar);
	void PrintInEx(PriQueue<missions> InEx);
	void PrintAvailRovers(PriQueue<Rovers>AvailERovers, PriQueue<Rovers>AvailPRovers);
	void PrintInCheckUp(LinkedQueue<Rovers> ICUERovers, LinkedQueue<Rovers> ICUPRovers);
	void PrintComplete(LinkedQueue<missions> CMissions);
	void SilentMode();
};*\
