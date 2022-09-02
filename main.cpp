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

int getArrSize(Medicamento* meds){
    return sizeof(meds)/sizeof(Medicamento);
}

void increaseArr(Medicamento *meds){
    int size = getArrSize(meds);
    size += 3;

    Medicamento *temp =  new Medicamento[size];
    for(int i=0;i<((size)-3);i++){
        temp[i] = meds[i];
    }
    meds = &temp[0];
}

int getLastUnused(Medicamento* meds){
    int size = getArrSize(meds);
    for(int i=0; i<size; i++){
        if(meds[i].free){
            return i;
        }
    }
    return -1;
}

int cadMedicamento(Medicamento* meds){
    clear_terminal();
    int index = getLastUnused(meds);
    int size = getArrSize(meds);
    char code[4];


    cout << "+------------------------------+" << endl;
    cout << "|    Cadastrar Medicamento     |" << endl;
    cout << "+------------------------------+" << endl;
    
    cout << "Codigo de Identificação: ";
    cin >> code;

    //Checking if it's already registered
    for(int i=0; i<size;i++){
        if(meds[i].code == code){
            return 1;
        }
    }

    //Checking if the struct have avaliabe space
    //if not increase it
    if(index == -1){
        cout << "Estoque insuficiente..." << endl << "Aumentando!";
        increaseArr(meds);
        cout << "Aumento realizado!";
    }
    
    cout << "Nome do Medicamento: ";
    cin >> meds[index].name;
    cout << "Descricao do Medicamento: ";
    cin >> meds[index].description;
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
    return 0;

}

void consultMedicamentos(Medicamento* meds){
    clear_terminal();
    int size = getArrSize(meds);
    char code[4];
    cout << "+------------------------------+" << endl;
    cout << "|    Consultar Medicamento     |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "Codigo de Identificacao: ";
    cin >> code;
    for(int i=0; i<size; i++){
        
        if(meds[i].code == code){
            cout << "Nome do Medicamento: " << meds[i].name;
            cout << "Descricao do Medicamento: " << meds[i].description;
            cout << "Laboratorio de Origem: " << meds[i].lab;
            cout << "Codigo de Identificacao: " << meds[i].code;
            cout << "Qtd. Disponivel: " << meds[i].stock;
            cout << "Preco da Unidade: " << meds[i].price;
            if(meds[i].status){
                cout << "Situacao: Ativo";
            }
            else{
                cout << "Situacao: Inativo";
            }

        }
    }
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

void listMedData(Medicamento meds){
    clear_terminal();
    cout << "+------------------------------+" << endl;
    cout << "|   Listar Dados do Estoque    |" << endl;
    cout << "+------------------------------+" << endl;

    for(int i = 0; meds.free == true; i++){
        cout << meds[i];
        //cout all the informations, check later if that's doable
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
    int menuOpt;
    Medicamento* meds = new Medicamento[3];


    printMenu();
    cin >> menuOpt;


    while(true){
        printMenu();
        cin >> menuOpt;
        switch (menuOpt){
            case 1:
                if(cadMedicamento(meds) != 0){
                    cout << "Erro! \n Medicamento ja cadastrado";
                }
                else{
                    cout << "Cadastro Realizado com Sucesso";
                }
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