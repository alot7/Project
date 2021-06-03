using namespace std;
class mission
{
protected:
	char TYP;
	int ED;
	int ID;
	int TLOC;
	int MDUR;
	int SIG;
public:
	mission();
	void setTYP(char type);
	char getTYP();
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
	~ mission();
};
