#pragma once
using namespace std;
class missions
{
private:
	char TYP;
	int ED;
	int ID;
	int TLOC;
	int MDUR;
	int SIG;
public:
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
	~missions();
};