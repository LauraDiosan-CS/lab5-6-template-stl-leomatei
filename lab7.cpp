
#include <iostream>
#include "test.h"
#include "test.cpp"
#include "produs.h"
#include "produs.cpp"
#include "tonamat.cpp"
#include "tonomat.h"
#include "service.h"
#include "service.cpp"
#include "ui.cpp"

using namespace std;

int main()
{
    test();
    cout << "succes";
    cin.get();
    UI<Service<RezervareCamera, Repo<RezervareCamera>>> ui("produse.txt");
    ui.run();
    return 0;

}
