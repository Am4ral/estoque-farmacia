#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cmath>


using namespace std;

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
    cout << "+-------------------------------------+" << endl;
    cout << "| [1] Cadastrar Medicamento           |" << endl;
    cout << "|-------------------------------------|" << endl;
    cout << "| [2] Consultar Medicamento           |" << endl;
    cout << "|-------------------------------------|" << endl;
    cout << "| [3] Listar Todos os Medicamentos    |" << endl;
    cout << "|-------------------------------------|" << endl;
    cout << "| [4] Apagar Medicamento              |" << endl;
    cout << "|-------------------------------------|" << endl;
    cout << "| [5] Efeturar Venda                  |" << endl;
    cout << "|-------------------------------------|" << endl;
    cout << "| [6] Listar Medicamentos em Estoque  |" << endl;
    cout << "|-------------------------------------|" << endl;
    cout << "| [7] Salvar em Arquivo               |" << endl;
    cout << "|-------------------------------------|" << endl;
    cout << "| [8] Sair                            |" << endl;
    cout << "+-------------------------------------+" << endl;
}

struct Medicamento{
    char name[100];
    char description[1000];
    char lab[50];
    char code[4];
    int stock;
    float price;
    bool status;
};

//If your sort by alphabetical order it'll be reversed
void merge(Medicamento* &meds, int init, int mid, int end, int mode){
    auto aux = new Medicamento[end-init+1];

    //Copying meds to an auxilar array;
    for(int i = init; i <= end; i++){
        aux[i] = meds[i];
    }

    int i = init; //Begin of the first half of the aux array
    int j = mid + 1; //Begin of the second half of the aux array
    int k = init; //K runs through the final array

    //Interleaving the two arrays
    while((i <= mid) and (j <= end)){
        if(mode == 1){
            if(strcmp(aux[i].name, aux[j].name) < 0){
                meds[k] = aux[i];
                i++;
            }
            else{
                meds[k] = aux[j];
                j++;
            }
            k++;
        }
        else{
            if(strcmp(aux[i].code, aux[j].code) < 0){
                meds[k] = aux[i];
                i++;
            }
            else{
                meds[k] = aux[j];
                j++;
            }
            k++;
        }
        
    }

    //If the first half was not fully consumed, append it
    while(i <= mid){
        meds[k] = aux[i];
        i++;
        k++;
    }

    //If the second half was not fully consumed, append it
    while(j <= end){
        meds[k] = aux[j];
        j++;
        k++;
    }
}

//Mode: 0 for code 
//Mode: 1 for lexico
void mergeSort(Medicamento* &meds, int init, int end, int mode = 0){

    //Stop code, the arr is only one element in length
    if(init >= end){
        return;
    }
    else{
        int mid = floor((init+end)/2);
        mergeSort(meds, init, mid, mode);
        mergeSort(meds, mid+1, end, mode);

        merge(meds, init, mid, end, mode);
    }
}

int binSearch(Medicamento* meds, int nMeds){
    int index = 0;
    return index;//Checking if mode is valid
}

//Resizing the Medicamento array to support more entries
void increaseArr(Medicamento* &meds, int& size, int& nMeds){
    //Setting the new size
    //Test wise -- change back to 3 after debbug is done
    size += 2;


    auto *biggerMeds = new Medicamento[size];
    for(int i=0; i<nMeds; i++){
        biggerMeds[i] = meds[i];
    }
    delete[] meds;

    meds = biggerMeds;

    //meds = (Medicamento*)realloc(meds, sizeof(Medicamento)*size);   
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

    //REMOVE AFTER TESTS
    //-----------------------
    nMeds++;
    return 0;
    //-----------------------
    
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

    //sorting by code, default mode
    mergeSort(meds, 0, nMeds);

    return 0;

}

void consultMedicamentos(Medicamento* &meds, int size){
    clear_terminal();
    char code[4];
    int index;
    cout << "+------------------------------+" << endl;
    cout << "|    Consultar Medicamento     |" << endl;
    cout << "+------------------------------+" << endl;
    
    cout << "Codigo de Identificacao: ";
    cin >> code;

    index = binSearch(meds, size);
        
    cout << "Nome do Medicamento: " << meds[index].name << endl;
    cout << "Descricao do Medicamento: " << meds[index].description << endl;
    cout << "Laboratorio de Origem: " << meds[index].lab << endl;
    cout << "Codigo de Identificacao: " << meds[index].code << endl;
    cout << "Qtd. Disponivel: " << meds[index].stock << endl;
    cout << "Preco da Unidade: " << meds[index].price << endl;
    if(meds[index].status){
        cout << "Situacao: Ativo" << endl;
    }
    else{
        cout << "Situacao: Inativo" << endl;
    }
}

void listStock(Medicamento* &meds, int size, int nMeds){
    clear_terminal();
    int index;
    cout << "+---------------------------------------+" << endl;
    cout << "|     Listar Todos os Medicamentos      |" << endl;
    cout << "+---------------------------------------+" << endl;

    //sorting by name, mode = 1
    mergeSort(meds, 0, nMeds, 1);
    
    for(index=0; index<nMeds; index++){
        cout << "Nome do Medicamento: " << meds[index].name << endl;
        cout << "Descricao do Medicamento: " << meds[index].description << endl;
        cout << "Laboratorio de Origem: " << meds[index].lab << endl;
        cout << "Codigo de Identificacao: " << meds[index].code << endl;
        cout << "Qtd. Disponivel: " << meds[index].stock << endl;
        cout << "Preco da Unidade: " << meds[index].price << endl;
        if(meds[index].status){
            cout << "Situacao: Ativo" << endl;
        }
        else{
            cout << "Situacao: Inativo" << endl;
        }
    }
    
}

void delMedicamento(Medicamento* &meds, int size, int nMeds){
    clear_terminal();
    char code[4];
    int index;
    char conf;
    cout << "+------------------------------+" << endl;
    cout << "|      Apagar Medicamento      |" << endl;
    cout << "+------------------------------+" << endl;

    cout << "Codigo de Identificacao: ";
    cin >> code;

    index =  binSearch(meds, size);

    cout << "Descricao do Medicamento: " << meds[index].description << endl;
    cout << "Confimar Exclusao ? ([S]im/[N]ao): ";
    cin >> conf;

    //switch style menu for the exclusion confirmation
    bool sent = true;
    while(sent){
        switch (tolower(conf))
        {
        case 'y':
            meds[index].status = false;
            cout << "Exclusao realizada com sucesso!" << endl;
            break;
        case 'n':
            cout << "Exclusao Cancelada!" << endl;
            sent = false;
            break;
        
        default:
            cout << "Opcao Invalida!" << endl;
            break;
        }
    }
}

int sellMedicamento(Medicamento* &meds, int size){
    clear_terminal();
    char code[4];
    int index;
    cout << "+------------------------------+" << endl;
    cout << "|        Efetuar Venda         |" << endl;
    cout << "+------------------------------+" << endl;

    cout << "Codigo de Identificacao: ";
    cin >> code;

    //TODO find the med through binary srch
    index = binSearch(meds, size);

    //Checking if it's avaliable on stock
    if(meds[index].status){
        cout << "Descricao do Medicamento: " << meds[index].description << endl;
        meds[index].stock--;
        cout << "Estoque restante: " << meds[index].stock;
        //Setting med as unavaliable if stock size = 0
        if(meds[index].stock == 0){
            meds[index].status = false;
        }
        return 0;
    }
    else{
        return 1;
    }
}

void listMedStock(Medicamento* meds, int nMeds){
    clear_terminal();
    cout << "+--------------------------------------+" << endl;
    cout << "|    Listar Medicamentos em Estoque    |" << endl;
    cout << "+--------------------------------------+" << endl;

    //TODO list stock data
    for(int i=0; i<nMeds; i++){
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
    auto* meds = new Medicamento[size];
    //Medicamento* meds = (Medicamento*) malloc(sizeof(Medicamento)*size);

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
                listStock(meds, size, nMeds);
                break;
            case 4: 
                delMedicamento(meds, size, nMeds);
                break;
            case 5: 
                if(sellMedicamento(meds, size) != 0){
                    cout << "Medicamento indisponivel!" << endl;
                }
                else{
                    cout << "Venda realizada com sucesso !" << endl;
                }
                break;
            case 6: 
                listMedStock(meds, nMeds);
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
