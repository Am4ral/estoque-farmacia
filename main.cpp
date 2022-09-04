#include <iostream>
#include <fstream>
#include <cstring>


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


void mergeSort(Medicamento* meds, int nMeds){
    //TODO implement

}

void increaseArr(Medicamento* &meds, int& size, int& nMeds){
    size += 2;

    // auto *biggerMeds = new Medicamento[size];
    // for(int i=0; i<nMeds; i++){
    //     biggerMeds[i] = meds[i];
    // }
    // delete[] meds;

    // meds = biggerMeds;

    meds = (Medicamento*)realloc(meds, sizeof(Medicamento)*size);


}

int cadMedicamento(Medicamento* &meds, int& size, int& nMeds){
    clear_terminal();
    int index = nMeds;
    char code[4];


    cout << "+------------------------------+" << endl;
    cout << "|    Cadastrar Medicamento     |" << endl;
    cout << "+------------------------------+" << endl;
    
    cout << "Codigo de Identificação: ";
    cin >> code;

    //Checking if it's already registered
    for(int i=0; i<nMeds;i++){
        if(strcmp(meds[i].code, code) == 0){
            return 1;
        }
    }


    //Checking if the struct have avaliabe space
    //if not increase it
    if(nMeds == size){
        cout << "Estoque insuficiente..." << endl << "Aumentando!" << endl;
        increaseArr(meds, size, nMeds);
        cout << "Aumento realizado!" << endl;
        cout << "Novo tamanho de estoque: " << size << endl;
    }
    nMeds++;
    return 0;
    
    cout << "Nome do Medicamento: ";
    cin >> meds[index].name;
    cout << "Descricao do Medicamento: ";
    cin >> meds[index].description;

    strcpy(meds[index].code, code);

    cout << "Laboratorio de Origem: ";
    cin >> meds[index].lab;
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

    nMeds++;


    //TODO sort the data by code

    return 0;

}

void consultMedicamentos(Medicamento* meds, int size){
    clear_terminal();
    char code[4];
    cout << "+------------------------------+" << endl;
    cout << "|    Consultar Medicamento     |" << endl;
    cout << "+------------------------------+" << endl;
    
    cout << "Codigo de Identificacao: ";
    cin >> code;

    for(int i=0; i<size; i++){
        
        if(meds[i].code == code){
            cout << "Nome do Medicamento: " << meds[i].name << endl;
            cout << "Descricao do Medicamento: " << meds[i].description << endl;
            cout << "Laboratorio de Origem: " << meds[i].lab << endl;
            cout << "Codigo de Identificacao: " << meds[i].code << endl;
            cout << "Qtd. Disponivel: " << meds[i].stock << endl;
            cout << "Preco da Unidade: " << meds[i].price << endl;
            if(meds[i].status){
                cout << "Situacao: Ativo" << endl;
            }
            else{
                cout << "Situacao: Inativo" << endl;
            }

        }
    }
}

void listStock(Medicamento* meds, int& nMeds){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|     Listar Medicamentos      |" << endl;
    cout << "+------------------------------+" << endl;
    //TODO sort by name
    for(int i=0;i<nMeds; i++){
        cout << "+-----------------------------------------+" << endl;
        cout << "Nome do Medicamento: " << meds[i].name << endl;
        cout << "Descricao do Medicamento: " << meds[i].description<< endl;
        cout << "Laboratorio de Origem: " << meds[i].lab << endl;
        cout << "Codigo de Identificacao: " << meds[i].code << endl;
        cout << "Qtd. Disponivel: " << meds[i].stock << endl;
        cout << "Preco da Unidade: " << meds[i].price << endl;
        if(meds[i].status){
            cout << "Situacao: Ativo" << endl;
        }
        else{
            cout << "Situacao: Inativo" << endl;
        }
        cout << "+-----------------------------------------+" << endl << endl;
    }
}

void delMedicamento(){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|      Apagar Medicamento      |" << endl;
    cout << "+------------------------------+" << endl;
}

int sellMedicamento(Medicamento* meds){
    clear_terminal();
    char code[4];
    int index;
    cout << "+------------------------------+" << endl;
    cout << "|        Efetuar Venda         |" << endl;
    cout << "+------------------------------+" << endl;

    cout << "Codigo de Identificacao: ";
    cin >> code;

    //TODO find the med through binary srch

    if(meds[index].status){
        cout << "Descricao do Medicamento: " << meds[index].description << endl;
        meds[index].stock--;
        cout << meds[index].stock;
        return 0;
    }
    else{
        return 1;
    }
}

void listMedData(Medicamento* meds){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|   Listar Dados do Estoque    |" << endl;
    cout << "+------------------------------+" << endl;

    //TODO list stock data
}

void saveToFile(Medicamento* meds){
    clear_terminal();
    ofstream file("saida");
    cout << "+------------------------------+" << endl;
    cout << "|      Salvar em Arquivo       |" << endl;
    cout << "+------------------------------+" << endl;

    //file.write();
}



int main(){
    bool menu = true;
    int menuOpt;
    int size = 2, nMeds = 0;
    // auto* meds = new Medicamento[size];
    Medicamento* meds = (Medicamento*) malloc(sizeof(Medicamento)*size);



    while(menu){
        printMenu();
        cin >> menuOpt;
        switch (menuOpt){
            case 1:
                if(cadMedicamento(meds, size, nMeds) != 0){
                    cout << "Erro! \nMedicamento ja cadastrado!" << endl;
                }
                else{
                    cout << "Cadastro Realizado com Sucesso !" << endl;
                }
                break;
            case 2: 
                consultMedicamentos(meds, size);
                break;
            case 3: 
                listStock(meds, nMeds);
                break;
            case 4: 
                delMedicamento();
                break;
            case 5: 
                if(sellMedicamento(meds) != 0){
                    cout << "Medicamento indisponivel!" << endl;
                }
                else{
                    cout << "Venda realizada com sucesso !" << endl;
                }
                break;
            case 6: 
                listMedData(meds);
                break;
            case 7: 
                saveToFile(meds);
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