#include "MarsStation.h"

using namespace std;
MarsStation::MarsStation()
{
	CurrentDay = 1;
}
void MarsStation::StartUp()
{
	ifstream filename;
	string filename;
	int EventsNo;
	filename >> EventsNo;
	for (int i = 0; i < EventsNo; i++)
	{
		char EventType;
		filename >> EventType;
		if (EventType == 'F')
		{
			char MissionType;
			int EventDay;
			int id;
			int location;
			int MissionD;
			int sig;
			filename >> MissionType >> EventDay >> id >> location >> MissionD >> sig;
			Formulation* form = new Formulation(MissionType, location, MissionD, sig, EventDay, id);
			Events.enqueue(form);
		}
		else
		{
			return;
		}
	}
}
void MarsStation::CurrentDayincreasing()
{
	CurrentDay++;
}
int MarsStation::getCurrentDay()
{
	return CurrentDay;
}
bool MarsStation::AvailableEvents()
{
	Event* item;
	if (Events.peek(item) && (item->getED() ==getCurrentDay())) // If there is event in the event list and its the event day then there is an availabe event
	{
		return true;
	}
	else
	{
		return false;
	}
}
void MarsStation::EventExecution()
{
	while (AvailableEvents())
	{
		Event* ava;
		Events.dequeue(ava);
		// creating mission
		dynamic_cast<Formulation*>(ava)->Execute(EMissions, PMissions);
	}
}
void MarsStation::CheckIEmissions()
{
	if (IEmissions.isEmpty()) //no IE rovers no IE missions
	{
		return;
	}
	missions item

	if ()

}
void MarsStation::MissionExecution()
{

}