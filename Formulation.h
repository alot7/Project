#pragma once
#include "Event.h"
class Formulation :
    public Event
{
    char MissionType;
    int TargetLocation;
    int MissionDuration;
    int Significance;
public:

    /* Constructor */             
    Formulation(char MissionType, int TargetLocation, int MissionDuration, int Significance, int MissionID, int EventDay);
    //void Execute(PriQueue<Missions>& Emergency, LinkedQueue<Missions>& Polar);

};