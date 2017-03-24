#include "Leitura.h"
string leitura(){
	char simbolos[100];
	ifstream arquivo;
	arquivo.open("entrada.txt");
	char output[100];
	vector<char> s;
	string p;
	int maior = -1;
	string texto;
	if(arquivo.is_open()){
		//cout << "Palavras Lidas: " << endl << endl;
		while(!arquivo.eof()){
			arquivo >> p;
			//cout << p << endl;
			texto += p;
			texto += "\n";
			int siz = p.size();
			if(siz > maior){
				maior = p.size();
			}

			for (int i = 0; i < p.size(); ++i)
			{
				bool existe = false;
				for (int j = 0; j < s.size(); ++j)
				{
					if(p[i] == s[j])
						existe = true;
				}
				if(!existe)
					s.push_back(p[i]);
				existe = false;
			}
		}
	}
	arquivo.close();
	return texto;
}