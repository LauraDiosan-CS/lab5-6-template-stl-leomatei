#include "tonomat.h"
#include <fstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



template<class T> Repo<T>::Repo() {

}

template<class T> Repo<T>::Repo(const char* filename) {
	fis = filename;
	ifstream f(filename);
	string linie;
	char* numar = new char[10];
	char* tip = new char[100];
	int id;
	bool elib;
	while (!f.eof()) {
		f >> id >> numar >> tip >> elib;
		f.get();
		if (numar != "" && tip != "") {
			T r(id, numar, tip, elib);
			lista.push_back(r);
		}
	}
	delete[] numar;
	delete[] tip;
	f.close();
	
}

template<class T> void Repo<T>::loadFromFile(const char* filename) {
	lista.clear();
	fis = filename;
	ifstream f(filename);
	char* numar = new char[10];
	char* tip = new char[100];
	int id;
	bool elib;
	while (!f.eof()) {
		f >> id >> numar >> tip >> elib;
		if (numar != "") {
			T r(id, numar, tip, elib);
			lista.push_back(r);
		}
	}
	delete[] numar;
	delete[] tip;
	f.close();
	lista.pop_back();
}

template <class T> Repo<T>::~Repo() {

}

template<class T> void Repo<T>::saveToFile() {
	ofstream f(fis);
	for (int i = 0; i < lista.size(); i++) {
		f << lista[i];
	}
	f.close();
}


template<class T> vector<T> Repo<T>::getAll() {
	return lista;
}

template<class T> void Repo<T>::add(T r) {
	lista.push_back(r);
}

template <class T> void Repo<T>::del(int id) {
	int i = 0, gasit = 0;
	while (gasit == 0 && i < this->size()) {
		if (lista[i].getid() == id) gasit = 1;
		i++;
	}
	typename vector<T>::iterator it;
	it = find(lista.begin(), lista.end(), lista[i-1]);
	if (gasit) lista.erase(it);

}

template <class T> int Repo<T>::size() {
	return lista.size();
}

template <class T> void Repo<T>::update(T e) {
	typename vector<T>::iterator it;
	it = find(lista.begin(), lista.end(), e);
	if (it != lista.end()) {
		(*it).setid(e.getid());
		(*it).setnumar(e.getnumar());
		(*it).settip(e.gettip());
		(*it).setelib(e.getelib());
	}
}

template<class T> T Repo<T>::elemAtPos(int i)
{
	if (i < 0 or i >= lista.size()) return T(0,"" ,"", 0);
	return lista[i];
}

template <class T> int Repo<T>::findElem(T s)
{
	typename vector<T>::iterator it;
	it = find(lista->begin(), lista->end(), s);
	if (it != lista->end()) {
		return distance(lista->begin(), it);
	}
	return -1;
}