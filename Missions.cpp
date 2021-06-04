#include "Missions.h"
using namespace std;
missions::missions(char TYP, int ID, int TLOC, int MDUR, int FD, int SIG)
{

}
void missions::setTYP(char type)
{
	TYP = type;
}
char missions::getTYP()
{
	return TYP;
}
void missions::setED(int eventday)
{
	ED = eventday;
}
int missions::getED()
{
	return ED;
}
void missions::setID(int id)
{
	ID = id;
}
int missions::getID()
{
	return ID;
}
void missions::setTLOC(int location)
{
	TLOC = location;
}
int missions::getTLOC()
{
	return TLOC;
}
void missions::setMDUR(int duration)
{
	MDUR = duration;
}
int missions::getMDUR()
{
	return MDUR;
}
void missions::setSIG(int significance)
{
	SIG = significance;
}
int missions::getSIG()
{
	return SIG;
}
missions::~missions()
{
}