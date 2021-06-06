#pragma once
#include "MarsStation.h"


using namespace std;

MarsStation::MarsStation()
{
	CurrentDay = 1;
}
void MarsStation::StartUp()
{
	ifstream filename;
	string file;
	cin >> file;
	filename.open(file);
	if (!filename)
	{
		exit;
	}
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
			// we have only formulation
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
		if (R.getMissionCount(CurrentDay) == -1 )
		{
			CUPRover.enqueue(R);
		}
		             // here check the Check Up duratrion  
		else
		{
			APRovers.enqueue(R);
		}
	}
	else if (R.getRoverType() == 'E')
	{
		R.increamentMissionCount();
		if(R.getMissionCount(CurrentDay) == -1)
		 {
			CUERover.enqueue(R);
		 }               // here check the Check Up duratrion 
	    else
	    {
		AERovers.enqueue(R);
	    }
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
	if (WEMissions.isEmpty() && WPMissions.isEmpty())
	{
		return;
	}
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
		int p = (itemEM.getTLOC() * itemEM.getMDUR() * itemEM.getSIG()) / (itemEM.getTLOC() + itemEM.getMDUR() + itemEM.getSIG());
		WEMissions.enqueue(itemEM,p);
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
void MarsStation::CheckUpERover()
{
	Rovers rov;
	LinkedQueue<Rovers> r;
	while (!CUERover.isEmpty())
	{
		CUERover.dequeue(rov);
		if (rov.Movetoavailable(CurrentDay))
		{
			AERovers.enqueue(rov);
		}
		else
		{
			r.enqueue(rov);
		}
	}
	while (!r.isEmpty())
	{
		r.dequeue(rov);
		CUERover.enqueue(rov);
	}
}
void MarsStation::CheckUpPRover()
{
	Rovers rov;
	LinkedQueue<Rovers> r;
	while (!CUPRover.isEmpty())
	{
		CUPRover.dequeue(rov);
		if (rov.Movetoavailable(CurrentDay))
		{
			APRovers.enqueue(rov);
		}
		else
		{
			r.enqueue(rov);
		}
	}
	while (!r.isEmpty())
	{
		r.dequeue(rov);
		CUPRover.enqueue(rov);
	}
}
void MarsStation::CheckingSystem()
{

	while (!(WEMissions.isEmpty()&& WPMissions.isEmpty() && IEmissions.isEmpty()))
	{

		EventExecution(); // Execute the events that should be executed at that day
		MissionExecution(); //first it checks IE missions then assign missions to rovers then it checks waiting mission
		CheckUpERover(); //checking on emergency rover
		CheckUpPRover();// checking on polar rover
		CurrentDayincreasing(); // in order to get to next day

	}
}