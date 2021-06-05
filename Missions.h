#pragma once
#include "Rovers.h"
using namespace std;
class missions
{
private:
	char TYP;
	int FD;
	int ID;
	int TLOC;
	int MDUR;
	int SIG;
	int ExD;
	int CD;
	int WD;
	Rovers rover;
public:
	missions();
	missions(char TYP, int ID, int TLOC, int MDUR, int FD, int SIG);
	char getTYP();
	void setTYP(char type);
	void setED(int eventday);
	int getED();
	void setID(int id);
	int getID();
	void setTLOC(int location);
	int getTLOC();
	void setMDUR(int duration);
	int getMDUR();
	void setSIG(int significance);
	int getSIG();
	int getWD();
	void increasingWD();
	int getCD();
	int getExD();
	void CDED();
	void setrover(Rovers rov);
	Rovers getrover();
	~missions();
};