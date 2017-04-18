#include "Separador.h"
vector<string> split(string str){

    vector<string> strings;
    string str2 = "";
    for (int i = 0; i < str.size() ; ++i) {
        try {
           cout << str[i] << endl;
            if( str[i] != ' ' && str[i] != '\0' && str[i] != '\n'){
                str2 += str[i];
//                cout <<  str[i] << endl;
            }
            if(str[i] == ' ' || str[i] == '\0' || str[i] == '\n')
            {
//                cout << str2 << endl;
                strings.push_back(str2);
                str2 = "";
            }
            try{
                char z = str[i+1];
            }
            catch (...){
//                cout << "aa";
            }

        }catch (...){
//            cout << "Erro valor de i: " << i << endl;
        }

    }
    cout << "STRINGS" << endl;
    for (int i = 0; i < strings.size(); ++i){
        cout << strings[i] << endl;
    }
    return strings;



}
