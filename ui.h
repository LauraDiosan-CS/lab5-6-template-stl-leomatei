#pragma once
#include "service.h"

using namespace std;

template<class T> class UI {
private:
	T serv;
	void show_menu();
	void add();
	void del();
	void update();
	void fun();
	void show_list();
public:
	UI(const char*);
	void run();
};