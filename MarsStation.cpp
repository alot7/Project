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
	int RoverP;
	int RoverE;
	int RoverPSpeed;
	int RoverESpeed;
	int N;
	int RoverPCD;
	int RoverECD;
	filename >> RoverP >> RoverE;
	filename >> RoverPSpeed>> RoverESpeed;
	filename >>N>> RoverPCD >> RoverECD;
	Rovers RP('P', RoverPCD, RoverPSpeed,N);
	Rovers RE('E', RoverECD, RoverESpeed, N);
	for (int i = 0; i < RoverP; i++)
	{
		APRovers.enqueue(RP);
	}
	for (int i = 0; i < RoverE; i++)
	{
		AERovers.enqueue(RE);
	}
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
		dynamic_cast<Formulation*>(ava)->Execute(WEMissions, WPMissions);
	}
}
void MarsStation::FreeRover(Rovers R)
{
	if (R.getRoverType() == 'P')
	{
		R.increamentMissionCount();
		// here check the Check Up duratrion and add a function in mars station track the Check up list to 
		APRovers.enqueue(R);
	}
	else if (R.getRoverType() == 'E')
	{
		R.increamentMissionCount();
		AERovers.enqueue(R);
	}
}
void MarsStation::CheckIEmissions() // TO CHECK IF MISSION IS COMPLETED OR NOT
{
	if (IEmissions.isEmpty()) //no IE missions 
	{
		return;
	}
	missions mis;
	LinkedQueue<missions> m; // as a temp list
	while (IEmissions.isEmpty())
	{
		IEmissions.dequeue(mis);
		if (mis.getCD()== getCurrentDay())
		{
			FreeRover(mis.getrover());
			CMissions.enqueue(mis);
		}
		else
		{
			m.enqueue(mis);
		}
		while (m.isEmpty())
		{
			m.dequeue(mis);
			IEmissions.enqueue(mis);
		}
	}

	

}
void MarsStation::MissionAssigning()
{
	//first  Emrgency missions
	missions itemEM;
	Rovers itemER;
	while (!(WEMissions.isEmpty())) //there is an Em 
	{
		WEMissions.peek(itemEM);
		if (!AERovers.isEmpty()) // there is ER
		{
			WEMissions.dequeue(itemEM);
			IEmissions.enqueue(itemEM);
			AERovers.dequeue(itemER);
			itemEM.setrover(itemER);
			itemEM.CDED();
		}
		else if (!APRovers.isEmpty()) // there is PR
		{
			WEMissions.dequeue(itemEM);
			IEmissions.enqueue(itemEM);
			APRovers.dequeue(itemER);
			itemEM.setrover(itemER);
			itemEM.CDED();
		}
		else // there is no rover then break and leave it in waiting list
		{
			break;
		}
    }
	// second polar rovers
	missions itemPM;
	Rovers itemPR;
	while (!(WPMissions.isEmpty())) // there is PMISSION
	{
		WPMissions.peek(itemPM);
		if (!(APRovers.isEmpty())) // there is a polar rover
		{
			WPMissions.dequeue(itemPM);
			IEmissions.enqueue(itemPM);
			APRovers.dequeue(itemPR);
			itemPM.setrover(itemPR);
			itemPM.CDED();
		}
		else  //no polar rover then break and leave it in waiting list
		{
			break;
		}
	}

	
}
void MarsStation::WaitingMissions() 
{
	// E missions
	missions itemEM;
	LinkedQueue<missions> Em;
	while (!(WEMissions.isEmpty()))
	{
		WEMissions.peek(itemEM);
		itemEM.increasingWD();
		WEMissions.dequeue(itemEM);
		Em.enqueue(itemEM);
	}
	while (!(Em.isEmpty()))
	{
		Em.dequeue(itemEM);
		WEMissions.enqueue(itemEM);
	}
	// P missions
	missions itemPM;
	LinkedQueue<missions> Pm;
	while (!(WPMissions.isEmpty()))
	{
		WPMissions.peek(itemPM);
		itemPM.increasingWD();
		WPMissions.dequeue(itemPM);
		Pm.enqueue(itemPM);
	}
	while (!Pm.isEmpty())
	{
		Pm.dequeue(itemPM);
		WPMissions.enqueue(itemPM);
	}
}
void MarsStation::MissionExecution()
{
	CheckIEmissions();
	MissionAssigning();
	WaitingMissions();
}