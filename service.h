#pragma once
#include "tonomat.h"

struct a {
	char* tip=new char[10];
	
	int procentaj=0,camere=0,camere_elib=0;
};

template<class T,class R> class Service {
private:
	R rep;
public:
	Service();
	Service(const char*);
	void loadService(const char*);
	~Service();
	//adauga un element
	void add(int, const char*, const char*, bool);
	//sterge un element
	void del(int);
	//modifica un element
	void update(int, const char*, const char*, bool);
	//salveaza in fisier elementele
	void save();
	//arata tipurile de camere si ce procentaj este liber pentru fiecare tip
	vector<a> functionalitate();
	vector<T> getAll();
	int lungime();
};