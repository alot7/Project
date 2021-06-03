#include "Mission.h"
using namespace std;
mission::mission()
{
}
void mission::setTYP(char type)
{
	TYP = type;
}
char mission::getTYP()
{
	return TYP;
}
void mission::setED(int eventday)
{
	ED = eventday;
}
int mission::getED()
{
	return ED;
}
void mission::setID(int id)
{
	ID = id;
}
int mission::getID()
{
	return ID;
}
void mission::setTLOC(int location)
{
	TLOC = location;
}
int mission::getTLOC()
{
	return TLOC;
}
void mission::setMDUR(int duration)
{
	MDUR = duration;
}
int mission::getMDUR()
{
	return MDUR;
}
void mission::setSIG(int significance)
{
	SIG = significance;
}
int mission::getSIG()
{
	return SIG;
}
mission::~mission()
{
}