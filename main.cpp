#include <iostream>
#include <fstream>


using namespace std;

struct Medicamento{
    bool free = true;
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

int getLastUnused(Medicamento* meds){
    for(int i=0; i<meds.size(); i++){
        if(meds[i].free){
            return i;
        }
    }
    return -1;
    //There's no error case cuz it's already being verified before cadMedicamento() is called
}

void cadMedicamento(Medicamento* meds){
    clear_terminal();
    int index;
    index = getLastUnused(meds);
    if(index != -1){
        cout << "+------------------------------+" << endl;
        cout << "|    Cadastrar Medicamento     |" << endl;
        cout << "+------------------------------+" << endl;
        cout << "Nome do Medicamento: ";
        cin >> meds[index].name;
        cout << "Descricao do Medicamento: ";
        cin >> meds[index].description;
        cout << "Laboratorio de Origem: ";
        cin >> meds[index].lab;
        cout << "Codigo de Identificação: ";
        cin >> meds[index].code;
        cout << "Qtd. Disponivel: ";
        cin >> meds[index].stock;
        cout << "Preco da Unidade: ";
        cin >> meds[index].price;
        cout << "Situacao: ";
        string stts;
        cin >> stts;
        if(stts == "Ativo"){
            meds[index].status = true;
        }
        else{
            meds[index].status = false;
        }
    }
}

void consultMedicamentos(){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|    Consultar Medicamento     |" << endl;
    cout << "+------------------------------+" << endl;
}

void listStock(){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|     Listar Medicamentos      |" << endl;
    cout << "+------------------------------+" << endl;
}

void delMedicamento(){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|      Apagar Medicamento      |" << endl;
    cout << "+------------------------------+" << endl;
}

void sellMedicamento(){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|        Efetuar Venda         |" << endl;
    cout << "+------------------------------+" << endl;
}

void listMedData(){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|   Listar Dados do Estoque    |" << endl;
    cout << "+------------------------------+" << endl;
    for(){
    
    }
}

void saveToFile(){
    clear_terminal();
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
        printMenu();
        cin >> menuOpt;
        switch (menuOpt){
            case 1:
                if(contMed > 3){
                    increaseArr(&medSize, meds);
                    contMed = 0;
                }
                cadMedicamento(meds);
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