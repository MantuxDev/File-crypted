// Crittografia

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Colori 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// Funzioni
int menu();
void genera_chiave(char caratteri[]);
bool cerca_numero(int numeri[], int &x);
void cripta(char caratteri[]);
void decripta(char caratteri[]);
void avanti();

// Costanti
const int LMAX=90; // numero dei caratteri


int main(){

    int s;

    char caratteri[LMAX]={
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        '0','1','2','3','4','5','6','7','8','9',' ',
        '.',',','!','?','@','#','$','%','^','&','*','(',')','[',']',
        '-','_','+',';','{','}','|','\\','/','<','>','='
    };

    do{
        s=menu();

        switch(s){

            case 1:{
                genera_chiave(caratteri);
                avanti();
                break;
            }

            case 2:{
                cripta(caratteri);
                avanti();
                break;
            }

            case 3:{
                decripta(caratteri);
                avanti();
                break;
            }

            case 0:{
                cout<<GREEN<<"Ciao!"<<RESET<<endl;
                break;
            }

            default:{
                cout<<RED<<"Scelta non valida!"<<RESET<<endl;
                avanti();
                break;
            }
        }
    }while(s!=0);

    return 0;
}


int menu(){

    int s;

    cout<<BLUE<<"\t-----MENU-----"<<RESET<<endl;
    cout<<BLUE<<"1. "<<RESET<<"Crea una chiave di crittografia"<<endl;
    cout<<BLUE<<"2. "<<RESET<<"Cripta un file"<<endl;
    cout<<BLUE<<"3. "<<RESET<<"Decripta un file"<<endl;
    cout<<BLUE<<"0. "<<RESET<<"Esci"<<endl;

    cout<<"\nInserisci la scelta: ";
    cin>>s;

    cout<<endl;

    return s;
}

// Funzioni

void genera_chiave(char caratteri[]){

    int numeri[LMAX],x;
    string chiave;

    cin.ignore();
    cout<<"\nCome vuoi chiamare la chiave: ";
    getline(cin,chiave);

    ofstream out(chiave+".txt");

    srand(time(NULL));

    for(int i=0;i<LMAX;i++){
        do{
            x=rand()%LMAX;
        }while(cerca_numero(numeri,x));
        numeri[i]=x;
        out<<caratteri[x];
    }
    out.close();

    cout<<GREEN<<"Chiave generata correttamente!"<<RESET<<endl;
    cout<<"La chiave si trova nello stesso percorso file di questo programma."<<endl;
    cout<<"\nChiave: "<<chiave<<".txt"<<endl;
}

bool cerca_numero(int numeri[], int &x){
    int i=0;
    bool c=false;

    while(i<LMAX && c==false){
        if(numeri[i]==x){
            c=true;
        }
        i++;
    }
    return c;
}

void cripta(char caratteri[]){

    string chiave,testo;

    cin.ignore();
    cout<<BLUE<<"Inserisci la chiave: "<<RESET;
    getline(cin,chiave);


    cout<<BLUE<<"Inserisci il testo da criptare: "<<RESET;
    getline(cin,testo);

    for(int i=0;i<testo.length();i++){
        char t=testo[i];
        for(int j=0;j<LMAX;j++){
            if(t==caratteri[j]){
                testo[i]=chiave[j];
            }
        }
    }

    ofstream criptato("file_crittato.txt");

    criptato<<testo;

    cout<<GREEN<<"\nTesto criptato correttamente!"<<RESET<<endl;
    cout<<"\nIl file si trova nello stesso percorso file di questo programma."<<endl;
    cout<<"File: file_crittato.txt"<<endl;
}

void decripta(char caratteri[]){

    string chiave,testo;
    char t;

    cin.ignore();
    cout<<BLUE<<"Inserisci la chiave: "<<RESET;
    getline(cin,chiave);


    cout<<BLUE<<"Inserisci il testo da decriptare: "<<RESET;
    getline(cin,testo);

    for(int i=0;i<testo.length();i++){
        t=testo[i];
        for(int j=0;j<LMAX;j++){
            if(t==chiave[j]){
                testo[i]=caratteri[j];
            }
        }
    }


    ofstream decriptato("file_decriptato.txt");

    decriptato<<testo;

    cout<<GREEN<<"\nTesto decriptato correttamente!"<<RESET<<endl;
    cout<<"\nIl file si trova nello stesso percorso file di questo programma."<<endl;
    cout<<"File: file_decriptato.txt"<<endl;
}

void avanti(){
    cout<<BLUE<<"\nPremi un tasto per continuare..."<<RESET<<endl;
    cin.ignore();
    system("cls");
}