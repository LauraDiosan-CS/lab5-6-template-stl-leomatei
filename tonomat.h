#pragma once
#include "produs.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

template <class T>
class Repo {
private:
	vector<T> lista;
	const char* fis;
	int lungime=0;
public:
	Repo();
	//se da fisierul cu care lucreaza repoul
	Repo(const char*);
	~Repo();
	//se citesc elemente din repo
	void loadFromFile(const char*);
	//se salveaza elementele in fisier
	void saveToFile();
	//se da elementul in pozitiadata printr-un int
	T elemAtPos(int);
	//cauta un element dat
	int findElem(T);
	//adauga un element dat
	void add(T );
	//sterge un element dupa id
	void del(int);
	//modifica un element
	void update(T);
	int size();
	vector<T> getAll();
};
