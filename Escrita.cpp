#include "Escrita.h"
#include <ctime>
#include <sstream>

template <typename T>

std::string NumberToString ( T Number ){
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

void escreve(string entrada, vector<int> valores){

	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    string estados[176] = {"literal_numerico", "literal_numerico", "literal_numerico", "literal_numerico", "", "literal_numerico",
        "literal_numerico", "literal_numerico", "outros_tokens", "negacao", "atribuicao", "op_relacional","op_relacional", "agrupador",
        "op_arit_p4", "op_arit_p3", "op_arit_p2", "op_arit_p1", "identificador", "identificador", "identificador", "identificador",
        "identificador", "identificador", "identificador", "identificador", "identificador", "identificador", "identificador",
        "identificador", "identificador", "identificador", "identificador", "identificador", "identificador", "identificador",
        "identificador", "identificador", "identificador", "identificador", "op_logico", "identificador", "op_logico", "identificador",
        "identificador", "op_logico", "identificador", "identificador", "identificador", "op_logico", "identificador", "identificador",
        "identificador", "identificador", "inicio_bloco", "identificador", "identificador", "identificador", "identificador",
        "identificador", "identificador", "identificador", "identificador", "estr_cond_aninhada", "identificador", "identificador",
        "tipo_dado", "identificador", "identificador", "identificador", "identificador", "identificador", "identificador",
        "identificador", "controle_fluxo", "manip_arquivo", "identificador", "repeticao_controle", "identificador", "identificador",
        "identificador", "identificador", "identificador", "identificador", "desvio_cond", "identificador", "desvio_cond",
        "identificador", "fim_bloco", "identificador", "identificador", "identificador", "identificador", "identificador",
        "identificador", "identificador", "desvio_cond", "identificador", "identificador", "identificador", "entrada",
        "tipo_dado", "identificador", "identificador", "identificador", "identificador", "identificador", "identificador",
        "identificador", "identificador", "func_mat", "identificador", "identificador", "identificador", "identificador",
        "identificador", "identificador", "identificador", "identificador", "identificador", "saida", "identificador",
        "repeticao_controle", "identificador", "identificador", "identificador", "identificador", "identificador", "identificador",
        "identificador", "identificador", "identificador", "identificador", "func_mat", "identificador", "identificador", "identificador",
        "identificador", "identificador", "repeticao_controle", "identificador", "identificador", "identificador", "tipo_dado", "identificador",
        "identificador", "identificador", "identificador", "identificador", "estr_cond_aninhada", "identificador", "repeticao_controle",
        "identificador", "identificador", "outros_tokens", "identificador", "identificador", "identificador", "outros_tokens",
        "identificador", "identificador", "outros_tokens", "identificador", "identificador", "identificador", "identificador",
        "repeticao_test_ini", "func_mat", "controle_fluxo", "bool", "identificador", "identificador", "controle_fluxo",
        "manip_arquivo", "bool", "identificador"};
   
	ofstream saida;
	saida.open("reconhecimento_lexico.txt",fstream::app);
	saida << entrada << ": ";
	int passadas = 0;
	string mostra;
	string estado;
	for (int i = 0; i < valores.size() ; ++i){
		mostra = entrada;
		estado = "";

		if(valores[i] != -1) estado += NumberToString(valores[i]);

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
		} else {
			saida << "; ->";
			saida << estados[valores.back() - 1];
		}

		if(i != (valores.size() - 1)){
			saida << ", ";
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
