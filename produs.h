#pragma once
#include <fstream>
using namespace std;

class RezervareCamera {
private:
	int id;
	char* numar;
	char* tip;
	bool eliberat;

public:
	RezervareCamera();
	RezervareCamera(int, const char*, const char*, bool);
	RezervareCamera(const RezervareCamera&);
	RezervareCamera(string);
	int getid();
	char* getnumar();
	char* gettip();
	bool getelib();
	void setid(int);
	void setnumar(const char*);
	void settip(const char*);
	void setelib(bool);
	~RezervareCamera();
	RezervareCamera& operator=(const RezervareCamera&);
	bool operator==(const RezervareCamera&);
	friend ostream& operator<<(ostream& , RezervareCamera);
	friend istream& operator>>(istream& , RezervareCamera&);
};