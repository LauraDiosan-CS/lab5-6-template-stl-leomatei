#include "service.h"



template <class T, class R> void Service<T, R>::loadService(const char* fis) {
	rep.loadFromFile(fis);
	
}

template <class T, class R> void Service<T, R>::save() {
	rep.saveToFile();

}

template<class T, class R> Service<T, R>::~Service() {
	this->rep.~Repo();
}

template<class T, class R> void Service<T, R>::add(int id, const char* numar, const char* tip, bool elib) {
	T r(id, numar, tip, elib);
	this->rep.add(r);
}

template<class T, class R> void Service<T, R>::del(int id) {
	this->rep.del(id);
}

template<class T, class R> void Service<T, R>::update(int id, const char* numar, const char* tip, bool elib) {
	T r(id, numar, tip, elib);
	this->rep.update(r);
}

template<class T, class R> vector<a> Service<T, R>::functionalitate() {
	vector<a> rezultat ;
	int i = 0;
	for (int j = 0; j < rep.size(); j++)
	
		if (rezultat.empty()) {
			a elem;
			elem.tip = new char[strlen(rep.getAll()[j].gettip()) + 1];
			strcpy_s(elem.tip, strlen(rep.getAll()[j].gettip()) + 1, rep.getAll()[j].gettip());
			elem.camere = 1;
			if (rep.getAll()[j].getelib()) elem.camere_elib++;
			rezultat.push_back(elem);
			//delete[] elem.tip;
		}
		else {
			int gasit = 0;
			int i;
			for(i=0;i<rezultat.size();i++)
				if (strcmp(rezultat[i].tip, rep.getAll()[j].gettip()) == 0) {
					gasit = 1;
					rezultat[i].camere++;
					if (rep.getAll()[j].getelib()) rezultat[i].camere_elib++;

				}
			if (!gasit) {
				a elem;
				elem.tip = new char[strlen(rep.getAll()[j].gettip()) + 1];
				strcpy_s(elem.tip, strlen(rep.getAll()[j].gettip()) + 1, rep.getAll()[j].gettip());
				elem.camere = 1;
				if (rep.getAll()[j].getelib()) elem.camere_elib++;
				rezultat.push_back(elem);
				//delete[] elem.tip;
			}
		}
	
	for (int i = 0; i < rezultat.size(); i++)
		rezultat[i].procentaj = int(rezultat[i].camere_elib * 100 / rezultat[i].camere) ;
	return rezultat;
}

template<class T, class R> vector<T> Service<T, R>::getAll() {
	return this->rep.getAll();
}

template<class T, class R> int Service<T, R>::lungime() {
	return this->rep.size();
}