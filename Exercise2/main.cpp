#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
double func_cambio(double N){
	double y = 0.5 + 0.75*(N-3);
	return y;
}
int main()
{
	std::ifstream file("data.txt");
	if(file.fail())
	{ 
        std::cerr << "errore nell'apertura "
                 	 "del file" <<std::endl;
		return 1;
	}
	std::string filename = "result.txt";
	std::ofstream ofs(filename);
	if (! ofs.is_open()){
		std::cerr << "errore nell'apertura "
                 	 "del file output" <<std::endl;	
		return 1
	}
	double val;
	double sum = 0;
	int k = 1;
	ofs <<"#N Mean"<<std::endl;
	while(file >>val){
		double valore2 = func_cambio(val);
		sum += valore2;
		double media = sum/k;
		k++;
		//std::cout <<std::setprecision(16)<<std::scientific <<media<<std::endl;
		ofs <<std::setprecision(16)<<std::scientific << media <<std::endl;
	}
	ofs.close();
    return 0;
}
