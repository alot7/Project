#include "Event.h"
#include "Formulation.h"
#include "Missions.h"
#include "Rovers.h"
#include <fstream>
using std::ifstream;
using namespace std;

class MarsStation
{
private:
	PriQueue<missions> EMissions;
	LinkedQueue<missions> PMissions;
	PriQueue<missions> WEMission;
	LinkedQueue<missions> WPMissions;
	LinkedQueue<missions> CMissions;
	 
	LinkedQueue<Rovers> AERovers;
	LinkedQueue<Rovers> APRovers;
	PriQueue<missions> IEmissions;
	LinkedQueue<Rovers> CURover;
	LinkedQueue<Event*> Events;
	int CurrentDay;
public:
	MarsStation();
	void StartUp();
	void CurrentDayincreasing();
	bool AvailableEvents();
	void EventExecution();
	int getCurrentDay();
	void CheckIEmissions();
	void MissionExecution();




};
