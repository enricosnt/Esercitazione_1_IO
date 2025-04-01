#include <iostream>
#include "irrational.hpp"

/* TOPIC: Operator overloading. Documentation at the address
 *   https://en.cppreference.com/w/cpp/language/operators
 */


/* /!\ NOTE: THIS CODE MUST BE COMPILED IN C++20 MODE /!\
 * USE THE FOLLOWING COMMAND TO COMPILE:
 *
 *     g++ -std=c++20 -o rational rational.cpp
 */

int main(void) {
    Irrational<double> i1(1.0,2.0);
	Irrational<double> i2(5.0,7.0);
    std::cout << "i1: "<<i1<<std::endl;
	std::cout << "i2: "<<i2<<std::endl;
	Irrational<double> somma = i1+i2;
	Irrational<double> prodotto = i1*i2;
	Irrational<double> couniugato_i1 = i1.coniugato();
	std::cout<<"Dato i1, la parte Reale é: "<<i1.reale()<<", mentre quella Immaginaria: "<<i1.imm()<<std::endl;
	std::cout << i1 << " + " << i2 << " = " << somma << std::endl;
	std::cout << i1 << " * " << i2 << " = " << prodotto << std::endl;
	std::cout<<"il coniugato di i1 è: "<< coniugato_i1<<std::endl;
    return 0;
}
