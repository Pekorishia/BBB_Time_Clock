#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdlib>

std::vector<std::string> getData(std::string file){
    std::vector<std::string> lines;
    while(true){
        std::ifstream Data(file.c_str());
        if(Data.is_open()){
            std::string str;
            while(!Data.eof()){
                getline(Data, str);
                lines.push_back(str);
            }
            return lines;
        }
        else{
            std::cout << "Seu arquivo não foi encontrado, digite um nome correto ";
            return lines;
        }
    }
}

std::vector<std::string> dataPrepare(std::vector<std::string> sort){
    std::vector<std::string> output;
    double temp[3], media, desvio;
    int i = 0;
    for(int j=0; j<sort.size(); j++){
        std::string s = sort[j];
        std::stringstream ss(s);
        std::string pal;
        while(ss >> pal){
            temp[i] = atof(pal.c_str());
            i++;
        }
        std::stringstream saida_temp;
        media = temp[1];
        desvio = temp[2]-temp[1];
        saida_temp << media << " " << desvio;
        output.push_back(saida_temp.str());
        i=0;
    }
    return output;
}

void geraSaida(std::vector<std::string> Bubble, std::vector<std::string> Quick, std::vector<std::string> Shell, std::string nome){
    std::ofstream saida;
    saida.open(nome.c_str());
        int j = 5000;
        for(int i=0; i<100; i++){
            if(Bubble.size()<=i)
                saida << j << " " << Quick[i] << " " << Shell[i] << std::endl;
            else
                saida << j << " " << Quick[i] << " " << Shell[i] << " " << Bubble[i] << std::endl;
            j += 5000;
        }
    saida.close();
}

int main(int argc, char *argv[]){
    std::vector<std::string> Bubble = getData(argv[1]);
    std::vector<std::string> Quick = getData(argv[2]);
    std::vector<std::string> Shell = getData(argv[3]);
    std::cout << argc << std::endl;
    Bubble = dataPrepare(Bubble);
    Quick = dataPrepare(Quick);
    Shell = dataPrepare(Shell);

    geraSaida(Bubble, Quick, Shell, argv[4]);



    return 0;
}
