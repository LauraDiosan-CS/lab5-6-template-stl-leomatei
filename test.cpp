#include "produs.h"
#include "tonomat.h"
#include "service.h"
#include <assert.h>
using namespace std;

void test_repo() {
	Repo<RezervareCamera> re("produse_test.txt");
	//RezervareCamera r1(1, "2e", "mare", 0), r2(2, "3er", "mica", 1);
	//re.add(r1);
	//re.add(r2);
	assert(re.getAll()[0].getid() == 1);
	re.del(1);
	//cout << re.getAll()[0].getid();
	//cout << re.size();
	RezervareCamera r3(2, "ttt", "rr", 1);
	re.update(r3);
	//cout << re.getAll()[0].getnumar();
	assert(strcmp(re.getAll()[0].getnumar(),"ttt")==0);
	assert(re.size() == 2);
	//re.saveToFile();
	
}

void test_serv() {
	Service<RezervareCamera, Repo<RezervareCamera>> serv;
	serv.loadService("produse_s.txt");
	//serv.add(1, "23", "mare", 1);
	//cout << serv.getAll()[0].getid();
	assert(serv.getAll()[0].getid() == 1);
	serv.update(1, "44", "mic", 0);
	assert(strcmp(serv.getAll()[0].getnumar(), "44") == 0 && strcmp(serv.getAll()[0].gettip(), "mic") == 0);
	assert(serv.functionalitate()[0].procentaj == 0);
	serv.del(1);
	assert(serv.lungime() == 0);
	
}