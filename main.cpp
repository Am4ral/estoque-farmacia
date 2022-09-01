#include <iostream>
#include <fstream>


using namespace std;

struct Medicamento{
    char name[100];
    char description[1000];
    char lab[50];
    char code[4];
    int stock;
    float price;
    bool status;
};

void clear_terminal(){
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void printMenu(){
    cout << "+------------------------------+" << endl;
    cout << "| [1] Cadastrar Medicamento    |" << endl;
    cout << "|------------------------------|" << endl;
    cout << "| [2] Consultar Medicamento    |" << endl;
    cout << "|------------------------------|" << endl;
    cout << "| [3] Listar Medicamentos      |" << endl;
    cout << "|------------------------------|" << endl;
    cout << "| [4] Apagar Medicamento       |" << endl;
    cout << "|------------------------------|" << endl;
    cout << "| [5] Efeturar Venda           |" << endl;
    cout << "|------------------------------|" << endl;
    cout << "| [6] Listar Dados do Estoque  |" << endl;
    cout << "|------------------------------|" << endl;
    cout << "| [7] Salvar em Arquivo        |" << endl;
    cout << "|------------------------------|" << endl;
    cout << "| [8] Sair                     |" << endl;
    cout << "+------------------------------+" << endl;
}

void increaseArr(int *medSize, Medicamento *meds){
    *medSize += 3;
    Medicamento *temp =  new Medicamento[*medSize];
    for(int i=0;i<((*medSize)-3);i++){
        temp[i] = meds[i];
    }
    meds = &temp[0];
}

void cadMedicamento(){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|    Cadastrar Medicamento     |" << endl;
    cout << "+------------------------------+" << endl;
    

}

void consultMedicamentos(){
    cout << "+------------------------------+" << endl;
    cout << "|    Consultar Medicamento     |" << endl;
    cout << "+------------------------------+" << endl;
}

void listStock(){
    cout << "+------------------------------+" << endl;
    cout << "|     Listar Medicamentos      |" << endl;
    cout << "+------------------------------+" << endl;
}

void delMedicamento(){
    cout << "+------------------------------+" << endl;
    cout << "|      Apagar Medicamento      |" << endl;
    cout << "+------------------------------+" << endl;
}

void sellMedicamento(){
    cout << "+------------------------------+" << endl;
    cout << "|        Efetuar Venda         |" << endl;
    cout << "+------------------------------+" << endl;
}

void listMedData(){
    cout << "+------------------------------+" << endl;
    cout << "|   Listar Dados do Estoque    |" << endl;
    cout << "+------------------------------+" << endl;
}

void saveToFile(){
    cout << "+------------------------------+" << endl;
    cout << "|      Salvar em Arquivo       |" << endl;
    cout << "+------------------------------+" << endl;
}



int main(){
    bool menu = true;
    int menuOpt, medSize=3, contMed=0;
    Medicamento* meds = new Medicamento[medSize];


    printMenu();
    cin >> menuOpt;


    while(true){
        switch (menuOpt){
            case 1:
                if(contMed > 3){
                    increaseArr(&medSize, meds);
                    contMed = 0;
                }
                cadMedicamento();
                contMed++;
                break;
            case 2: 
                consultMedicamentos();
                break;
            case 3: 
                listStock();
                break;
            case 4: 
                delMedicamento();
                break;
            case 5: 
                sellMedicamento();
                break;
            case 6: 
                listMedData();
                break;
            case 7: 
                saveToFile();
                break;
            case 8: 
                cout << "Ecerrando programa!" << endl;
                cout << "Bye........" << endl;
                menu = false;
                break;
            default:
                cout << "Opcao Invalida!" << endl;
                break;
        }
    }
    




    return 0;
}