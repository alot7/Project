#include "Formulation.h"
Formulation::Formulation(char MT, int TL, int MD, int Signif, int MID, int ED) :Event(ED, MID)
{
    MissionType = MT;
    TargetLocation = TL;
    MissionDuration = MD;
    Significance = Signif;
}

//void Formulation::Execute(PriQueue<Missions>& Emergency, LinkedQueue<Missions>& Polar){}