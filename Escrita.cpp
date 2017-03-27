#include "Escrita.h"
#include <ctime>
void escreve(string entrada, vector<int> valores){

	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
   
	ofstream saida;
	saida.open("reconhecimento_lexico.txt",fstream::app);
	// cout << valores[valores.size() -1] << " FL" <<endl ;
	saida << entrada << ": ";
	int passadas = 0;
	for (int i = 0; i < valores.size() ; ++i){

		if(valores[i] != -1)
			saida << valores[i];
		if(i < entrada.size())
			saida << entrada[i];
		if(valores[i] == 888){
			saida << "; Erro Simbolo nao Existente";
			break;
		}

		if(valores[i] == 999){
			saida << "; Erro de Transicao";
			break;
		}

	}
	saida << "\n";
	
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