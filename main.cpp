#include "vector.hpp"
#include <iostream>

template <class T>
void Isvedimas(Vector<T>);
Vector<int> VektoriausSukurimas(int, int);        
template <class T>      
void ArTuscias(Vector<T>);

int main(){
    Vector<int> A = VektoriausSukurimas(3, 5);          // Vektoriaus priskyrimas
    Isvedimas(A);

    ArTuscias(A);                         
}

Vector<int> VektoriausSukurimas(int size, int value){   // Vektoriaus sukurimas konstruktoriumi
    Vector<int> A(size, value);
    Isvedimas(A);
    return A;
}

template <class T>
void Isvedimas(Vector<T> A){
    cout << "Vektoriaus elementai: ";
    for (int i=0; i<A.size(); i++)                      // Spausdina vektoriaus elementus pasinaudojus size() funkcija
        cout << A[i] << " ";                            // Pasiekia atitinkama elementa su [] operatoriumi
    cout << endl;
}

template <class T>
void ArTuscias(Vector<T> A){                            // Patikrina ar vektorius yra tuscias
    if (A.empty())
        cout << "Vektorius: tuscias" << endl;
    else
        cout << "Vektorius: ne tuscias" << endl;
}