#include "ui.h"
#include "service.h"

using namespace std;

template<class T> UI<T>::UI(const char* fis) {
	serv.loadService(fis);
}

template<class T> void UI<T>::show_menu() {
	cout << "1.Adaugare" << '\n';
	cout << "2.Stergere" << '\n';
	cout << "3.Modificare" << '\n';
	cout << "4.procentaj camere libere" << '\n';
	cout << "a.Show all" << '\n';
	cout << "x.Exit" << '\n'<<'\n';
}

template<class T> void UI<T>::add() {
	int id;
	char* numar = new char[20];
	char* tip = new char[100];
	bool elib;
	cout << "Dati id-ul: "; cin >> id;
	cout << "Dati numarul: "; cin >> numar;
	cout << "Dati tipul: "; cin>>tip;
	cout << "Este libera?(1.DA/0.NU): "; cin >> elib;
	this->serv.add(id, numar, tip, elib);
	delete[]numar;
	delete[]tip;
	cout << "Rezervare adaugata!" << '\n' << '\n';
}

template<class T> void UI<T>::del() {
	int id;
	cout << "Dati id-ul: "; cin >> id;
	serv.del(id);
	cout << "Rezervare stearsa!" << '\n' << '\n';
}

template<class T> void UI<T>::update() {
	int id;
	char* numar = new char[20];
	char* tip = new char[100];
	bool elib;
	cout << "Dati id-ul: "; cin >> id;
	cout << "Dati numarul: "; cin >> numar;
	cout << "Dati tipul: "; cin>>tip;
	cout << "Este libera?(1.DA/0.NU) "; cin >> elib;
	this->serv.update(id, numar, tip, elib);
	delete[]numar;
	delete[]tip;
	cout << "Modificare adaugata!" << '\n' << '\n';
}

template<class T> void UI<T>::fun() {
	vector<a> func = serv.functionalitate();
	
	for (int i = 0; i<func.size() ; i++)
		if (func[i].tip != "") cout << func[i].tip << " " << func[i].procentaj << "%" << '\n';
	func.clear();
	cout << '\n';
}

template<class T> void UI<T>::show_list() {
	for (int i = 0; i < serv.lungime(); i++)
		if (serv.getAll()[i].getid() != 0)
			cout << serv.getAll()[i] << '\n';
}

template<class T> void UI<T>::run() {
	
	char op;
	show_menu();
	cout << "Alege: "; cin >> op;
	while (op != 'x') {
		if (op == '1') this->add();
		else if (op == '2') this->del();
		else if (op == '3') this->update();
		else if (op == '4') this->fun();
		else if (op == 'a') this->show_list();
		else cout << "Comanda invalida!" << '\n' << '\n';
		show_menu();
		cout << "Alege: "; cin >> op;
	}
	cout << "Paaaaaa!";
	serv.save();
	cin.get();
}
