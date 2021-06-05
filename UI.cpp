/*#include "UI.h"
#include "MarsStation.h"
#include "Formulation.h"
UI::UI(MarsStation* Mars)
{
	pMars = Mars;
}

void UI::PrintWait(PriQueue<missions> Emergency, LinkedQueue<missions> Polar)
{
	int CountP = 0;
	int CountE = 0;
	int CountW = 0;
	int CountInEx = 0;
	LinkedQueue<missions> TempEP;
	Node<int>* TempID;
	Node<missions>* TempMission;
	int TempInt;
	while (!Emergency.isEmpty())
	{
		Emergency.dequeue(TempMission);
		CountE++;
		CountW++;
		TempEP.enqueue(TempMission->getItem());
	}
	while (!Polar.isEmpty())
	{
		Polar.dequeue(TempMission);
		CountP++;
		CountW++;
		TempEP.enqueue(TempMission->getItem());
	}
	cout << "Current Day: " << pMars->getCurrentDay() << endl;
	cout << CountW << " Waiting Missions: ";
	if (TempEP.isEmpty())
	{
		cout << "[ ] ( ) { } ";
	}
	while (!TempEP.isEmpty())
	{
		cout << "[ ";
		for (int i = 0; i < CountE; i++)
		{
			TempEP.dequeue(TempMission);
			cout << TempMission->getItem()->getID() << ",";

		}
		cout << "\b ]" << "  ";
		cout << "( ";
		for (int i = 0; i < CountP; i++)
		{
			TempEP.dequeue(TempMission);
			cout << TempMission->getItem()->getID() << ",";
		}
		cout << "\b )" << "  ";

	}
	cout << endl;
	cout << "--------------------------------------" << endl;
}
void UI::PrintInEx(PriQueue<missions> InEx)
{
	int CountP = 0;
	int CountE = 0;
	int CountInEx = 0;
	LinkedQueue<missions> Emerge;
	LinkedQueue<missions> Polar;
	Node<missions>* MissionNode;
	while (!InEx.isEmpty())
	{
		InEx.dequeue(MissionNode);
		if (MissionNode->getItem()->getMissionType() == 'E')
		{
			CountE++;
			CountInEx++;
			Emerge.enqueue(MissionNode->getItem());
		}
		else if (MissionNode->getItem()->getMissionType() == 'P')
		{
			CountP++;
			CountInEx++;
			Polar.enqueue(MissionNode->getItem());
		}
	}
	cout << CountInEx << " In-Execution Missions/Rovers: ";

	cout << "[  ";
	while (!Emerge.isEmpty())
	{
		Emerge.dequeue(MissionNode);
		cout << MissionNode->getItem()->getID() << "/" << MissionNode->getItem()->getRover()->getID() << ", ";

	}
	cout << "\b\b  ] ";
	cout << "(  ";
	while (!Polar.isEmpty())
	{
		Polar.dequeue(MissionNode);
		cout << MissionNode->getItem()->getID() << "/" << MissionNode->getItem()->getRover()->getID() << ", ";

	}
	cout << "\b\b  ) ";
	cout << endl;
	cout << "--------------------------------------" << endl;
}

void UI::PrintAvailRovers(PriQueue<Rovers>AvailERovers, PriQueue<Rovers>AvailPRovers)
{
	int CountR = 0;
	int CountP = 0;
	int CountE = 0;
	LinkedQueue<Rovers> Rovers;
	Node<Rovers>* Temp;
	while (!AvailERovers.isEmpty())
	{
		AvailERovers.dequeue(Temp);
		Rovers.enqueue(Temp->getItem());
		CountE++;
		CountR++;
	}
	while (!AvailPRovers.isEmpty())
	{
		AvailPRovers.dequeue(Temp);
		Rovers.enqueue(Temp->getItem());
		CountP++;
		CountR++;
	}
	cout << CountR << " Available Rovers: ";
	if (Rovers.isEmpty())
	{
		cout << "[ ] ( ) { } ";
	}
	while (!Rovers.isEmpty())
	{
		cout << "[  ";
		for (int i = 0; i < CountE; i++)
		{
			Rovers.dequeue(Temp);
			cout << Temp->getItem()->getID() << ",";
		}
		cout << "\b  ]" << "  ";
		cout << "(  ";
		for (int i = 0; i < CountP; i++)
		{
			Rovers.dequeue(Temp);
			cout << Temp->getItem()->getID() << ",";
		}
		cout << "\b  )" << "  ";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;
}

void UI::PrintInCheckUp(LinkedQueue<Rovers> ICUERovers, LinkedQueue<Rovers> ICUPRovers)
{
	int CountC = 0;
	int CountP = 0;
	int CountE = 0;
	LinkedQueue<Rovers> CheckRovers;
	Node<Rovers>* Temp;
	while (!ICUERovers.isEmpty())
	{
		ICUERovers.dequeue(Temp);
		CheckRovers.enqueue(Temp->getItem());
		CountE++;
		CountC++;
	}
	while (!ICUPRovers.isEmpty())
	{
		ICUPRovers.dequeue(Temp);
		CheckRovers.enqueue(Temp->getItem());
		CountP++;
		CountC++;
	}
	cout << CountC << " In-Checkup Rovers: ";
	if (CheckRovers.isEmpty())
	{
		cout << "[ ] ( ) { } ";
	}
	while (!CheckRovers.isEmpty())
	{
		cout << "[  ";
		for (int i = 0; i < CountE; i++)
		{
			CheckRovers.dequeue(Temp);
			cout << Temp->getItem()->getID() << ",";
		}

		cout << "\b  ]" << "  ";
		cout << "(  ";
		for (int i = 0; i < CountP; i++)
		{
			CheckRovers.dequeue(Temp);
			cout << Temp->getItem()->getID() << ",";
		}
		cout << "\b  )" << "  ";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;
}
void UI::PrintComplete(LinkedQueue<missions> CMissions)
{
	int CountP = 0;
	int CountE = 0;
	int CountComp = 0;
	LinkedQueue<missions> Emerge;
	LinkedQueue<missions> Polar;
	Node<missions>* MissionNode;
	while (!CMissions.isEmpty())
	{
		CMissions.dequeue(MissionNode);
		if (MissionNode->getItem()->getMissionType() == 'E')
		{
			CountE++;
			CountComp++;
			Emerge.enqueue(MissionNode->getItem());
		}
		else if (MissionNode->getItem()->getMissionType() == 'P')
		{
			CountP++;
			CountComp++;
			Polar.enqueue(MissionNode->getItem());
		}
	}
	cout << CountComp << " Completed Missions: ";
	cout << "[  ";
	while (!Emerge.isEmpty())
	{
		Emerge.dequeue(MissionNode);
		cout << MissionNode->getItem()->getID() << ", ";

	}
	cout << "\b\b  ] ";
	cout << "(  ";
	while (!Polar.isEmpty())
	{
		Polar.dequeue(MissionNode);
		cout << MissionNode->getItem()->getID() << ", ";

	}
	cout << "\b\b  ) ";
	cout << endl;
	cout << "--------------------------------------" << endl;
}
void UI::Mode(PriQueue<missions> Emergency, LinkedQueue<missions> Polar, PriQueue<missions> InEx, PriQueue<Rovers> AvailERovers, PriQueue<Rovers> AvailPRovers, LinkedQueue<Rovers> ICUERovers, LinkedQueue<Rovers> ICUPRovers, LinkedQueue<missions> CMissions)
{
	PrintWait(Emergency, Polar);
	PrintInEx(InEx);
	PrintAvailRovers(AvailERovers, AvailPRovers);
	PrintInCheckUp(ICUERovers, ICUPRovers);
	PrintComplete(CMissions);
	cout << "======================= New Day ======================" << endl;
}*\