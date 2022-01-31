#include <iostream>
#include <Windows.h>
#include "Vectorizm.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    Vectorizm<int> a(9);

    for (int i = 0; i < 20; i++) {
        a.setVect(rand() % 100);
    }
    a.displayVec();
    cout << a.getVecsize() << "\n";
    int asize = a.getVecsize();
    for (int i = asize; i > 8 ; i--) {
        a.set_i_Vec(0, i);
        asize = a.getVecsize();
    }
    a.clearVoid();
    a.displayVec();
    cout << a.getVecsize() << " \n";



};
