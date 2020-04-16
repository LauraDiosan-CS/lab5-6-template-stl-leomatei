#include "produs.h"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;


RezervareCamera::RezervareCamera() {
	this->id = 0;
	this->numar = NULL;
	this->tip = NULL;
	this->eliberat = 0;
}

RezervareCamera::RezervareCamera(int id, const char* numar,const char* tip, bool elib) {
	this->id = id;
	this->numar = new char[strlen(numar) + 1];
	strcpy_s(this->numar, strlen(numar) + 1, numar);
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->eliberat = elib;
}

RezervareCamera::RezervareCamera(const RezervareCamera& p) {
	this->id = p.id;
	this->numar = new char[strlen(p.numar) + 1];
	strcpy_s(this->numar, strlen(p.numar) + 1, p.numar);
	this->tip = new char[strlen(p.tip) + 1];
	strcpy_s(this->tip, strlen(p.tip) + 1, p.tip);
	this->eliberat = p.eliberat;
}

RezervareCamera::RezervareCamera(string linie) {
	std::istringstream iss(linie);
	string tok1, tok2,tok3,tok4;
	iss >> tok1 >> tok2>>tok3>>tok4;
	id = stoi(tok1);
	numar = new char[tok2.length() + 1];
	strcpy_s(numar, tok2.length() + 1, tok2.c_str());
	tip = new char[tok3.length() + 1];
	strcpy_s(tip, tok3.length() + 1, tok3.c_str());
	eliberat = stoi(tok4);
}

int RezervareCamera::getid() {
	return this->id;
}

char* RezervareCamera::getnumar() {
	return this->numar;
}

char* RezervareCamera::gettip() {
	return this->tip;
}

bool RezervareCamera::getelib() {
	return this->eliberat;
}

void RezervareCamera::setid(int id) {
	this->id = id;
}

void RezervareCamera::setnumar(const char* numar) {
	if (this->numar) delete[] this->numar;
	this->numar = new char[strlen(numar) + 1];
	strcpy_s(this->numar, strlen(numar) + 1, numar);
}

void RezervareCamera::settip(const char* tip) {
	if (this->tip) delete[] this->tip;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

void RezervareCamera::setelib(bool el) {
	this->eliberat = el;
}

RezervareCamera::~RezervareCamera() {
	this->id = 0;
	
}

RezervareCamera& RezervareCamera::operator=(const RezervareCamera& p) {
	if (this == &p) return *this; 
	id = p.id;
	if (numar) delete[] numar;
	numar = new char[strlen(p.numar) + 1];
	strcpy_s(numar, strlen(p.numar) + 1, p.numar);
	if (tip) delete[] tip;
	tip = new char[strlen(p.tip) + 1];
	strcpy_s(tip, strlen(p.tip) + 1, p.tip);
	eliberat = p.eliberat;
	return *this;
}

bool RezervareCamera::operator==(const RezervareCamera& p) {
	return this->id == p.id;
}

ostream& operator<<(ostream& os, RezervareCamera p) {
	os << p.getid()<<" "<<p.getnumar()<<" "<<p.gettip()<<" "<<p.getelib() << '\n';
	return os;
}

istream& operator>>(istream& is, RezervareCamera p) {
	int id;
	cout << "Dati id: ";
	is >> id;
	cout << "Dati numele: ";
	char* numar = new char[10];
	is >> numar;
	cout << "Dati tip: ";
	char* tip = new char[10];
	is >> tip ;
	cout << "este libera: ";
	bool pret;
	is >> pret;
	p.setid(id);
	p.setnumar(numar);
	p.settip(tip);
	p.setelib(pret);
	delete[] numar;
	delete[] tip;
	return is;
}