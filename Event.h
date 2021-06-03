#pragma once
#include <iostream>
#include "PriQueue.h"
#include "LinkedQueue.h"
#include "Event.h"
#include "Missions.h"
#include "Rovers.h"


class Event
{
protected:
	int EventDay;
	int MissionID;

public:

	/* Constructor */
	Event(int, int);
	int getED();//get event date
	/* Check and execute to create mission and add it to the appropriate list */
	//virtual void Execute(PriQueue<Missions>& Emergency, LinkedQueue<Missions>& Polar) = 0;
};