#include "Escrita.h"
#include <ctime>
#include <boost/lexical_cast.hpp>

void escreve(string entrada, vector<int> valores){

	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
   
	ofstream saida;
	saida.open("reconhecimento_lexico.txt",fstream::app);
	// cout << valores[valores.size() -1] << " FL" <<endl ;
	saida << entrada << ": ";
	int passadas = 0;
	string mostra;
	string estado;
	for (int i = 0; i < valores.size() ; ++i){
		mostra = entrada;
		estado = "";

		if(valores[i] != -1)
			estado += boost::lexical_cast<std::string>(valores[i]);
			if(i < (valores.size() - 1)){
				mostra.insert(i, estado);
			} else {
				mostra += estado;
			}
			saida << mostra;
		if(valores[i] == 888){
			saida << "; Erro Simbolo nao Existente";
			break;
		} else if(valores[i] == 999){
			saida << "; Erro de Transicao";
			break;
		}
		if(i != (valores.size() - 1)){
			saida << ", ";
		}
	}
	saida << ";\n";
	
	saida.close();
	if(valores[valores.size() - 1] < 0)
		valores.pop_back();
	saida.open("analise_lexica.txt", fstream::app);
	saida << valores[valores.size()-1] << " ";

	saida.close();

}

void zeraSaida(){
	ofstream saida;
	saida.open("reconhecimento_lexico.txt");
	saida << "";
	saida.close();
	saida.open("analise_lexica.txt");
	saida << "";
	saida.close();
}