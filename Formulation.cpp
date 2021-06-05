#include "Formulation.h"
Formulation::Formulation(char MT, int TL, int MD, int Signif, int MID, int ED) :Event(ED, MID)
{
    MissionType = MT;
    TargetLocation = TL;
    MissionDuration = MD;
    Significance = Signif;
}

void Formulation::Execute(PriQueue<missions>& Emergency, LinkedQueue<missions>& Polar)
{
    if (MissionType == 'E')
    {
    missions* Emergenc = new missions(MissionType, MissionID, TargetLocation, MissionDuration, EventDay, Significance);
    int priority = (TargetLocation * MissionDuration * Significance) / (TargetLocation + MissionDuration + Significance);
    Emergency.enqueue(Emergenc, -priority);
    }

    else if (MissionType == 'P')
    {
        missions* Pola = new missions(MissionType, MissionID, TargetLocation, MissionDuration, EventDay, Significance);
        Polar.enqueue(Pola);
    }
   

}
