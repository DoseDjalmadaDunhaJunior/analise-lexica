//
// Created by djalma on 15/11/2019.
//

#ifndef ANALISE_LEXICA_LEXICO_H
#define ANALISE_LEXICA_LEXICO_H
#include <iostream>
using namespace std;

class Lexico {
public:
    Lexico(char* vetor){
        int i;
        for (i = 0; vetor[i] != 0 ; i++) {
            txt[i] = vetor[i];
        }
        txt[i] = 0;
    }

    void e0() {
        if (txt[posicao] == 0) {
            cout << "aceita" << endl;
        } else if (txt[posicao] == ' ') {
            e4();
        } else if ((txt[posicao] >= 'a' && txt[posicao] <= 'z') ||
                   (txt[posicao] >= 'A' && txt[posicao] <= 'Z')) {
            e1();
        } else if (txt[posicao] >= '0' && txt[posicao] <= '9') {
            e2();
        } else if (txt[posicao] == '>' || txt[posicao] == '<' ||
                   txt[posicao] == '=' || txt[posicao] == ':' ||
                   txt[posicao] == '%' || txt[posicao] == '+' ||
                   txt[posicao] == '-' || txt[posicao] == '*' ||
                   txt[posicao] == '/') {
            e3();
        }
        else{
            cout<<"rejeita"<<endl;
        }
    }

private:
    int posicao = 0;
    char txt[200];

    void e1() {
        posicao++;
        if ((txt[posicao] >= 'a' && txt[posicao] <= 'z') ||
            (txt[posicao] >= 'A' && txt[posicao] <= 'Z')) {
            e1();
        }
        else{
            e0();
        }
    }

    void e2(){
        posicao++;
        if(txt[posicao] >= '0' && txt[posicao] <= '9'){
            e2();
        } else{
            e0();
        }
    }

    void e3() {
        posicao++;
        if (txt[posicao] == '>' || txt[posicao] == '<' ||
            txt[posicao] == '=' || txt[posicao] == ':' ||
            txt[posicao] == '%' || txt[posicao] == '+' ||
            txt[posicao] == '-' || txt[posicao] == '*' ||
            txt[posicao] == '/') {
            e3();
        } else{
            e0();
        }
    }

    void e4() {
        posicao++;
        if (txt[posicao] == ' ') {
            e4();
        } else{
            e0();
        }
    }

};


#endif //ANALISE_LEXICA_LEXICO_H
