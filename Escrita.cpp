#include "Escrita.h"
#include <ctime>
void escreve(string entrada, vector<int> valores){

	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
   
	ofstream saida;
	saida.open("reconhecimento_lexico.txt",fstream::app);

	saida << entrada << ": ";
	int passadas = 0;
	for (int i = 0; i < valores.size() -1; ++i){
		// cout << s[i];
		
		saida << valores[i];
		if(entrada[i] !=  NULL)
			saida << entrada[i];
		if(valores[i] == 122){
			saida << "; Erro Simbolo nao Existente";
			break;
		}

		if(valores[i] == 9999){
			saida << "; Erro de Transicao";
			break;
		}

	}
	saida << "\n";
	
	saida.close();
	valores.pop_back();
	saida.open("analise_lexica.txt", fstream::app);
	saida << valores[valores.size()-1] << " ";

	saida.close();

}