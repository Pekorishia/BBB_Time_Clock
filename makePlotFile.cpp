#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char *argv[]){
	
	//n�o d� para usar o argv na IDE
	//string file1;
	 // file1 = argv[1];
	//string file2;
	 // file1 = argv[2];
	//string file3;
	 // file1 = argv[3];
	//string saida; 	
	 // file1 = argv[4];

	list<string> lista;
	
	string file1;
	cout << "arquivo 1" << endl;
	cin >> file1;
	
	string file2;
	cout << "arquivo 2" << endl;
	cin >> file2;
	
	string file3;
	cout << "arquivo 3" << endl;
	cin >> file3;
	
	string saida;
	cout << "arquivo de saida" << endl;
	cin >> saida;
	
	//colocando a primeira coluna
	//eixo x - tamanho do vetor
	int tamanho = 5000;
	while(tamanho != 500000){
		lista.push_back(i);
		i += 5000;
	}
	
	
	string line;
	
	ifstream f1 (file1.c_str());
	if(f1.is_open()){
		int x = 0;
		while( getline (infile,line)){
			if (x != 0){
				// 1    -    l� a linha e para quando chegar num espa�o,  salva o valor encontrado como double
				
				//2     -    l� depois do espa�o e para quando chegar em outro, salva o valor como double
			
				//3     -    subtrai o 2 do 1 e teremos o desvio padr�o
				
				//pega a string na posi��o x - 1 da lista e concatena com " 2 3", deixando espa�o entre os numeros
			}
			x += 1;
		}
		infile.close();
	}
	else cout << "unable to open file";
	
	
	ifstream f2 (file2.c_str());
	if(f2.is_open()){
		int x = 0;
		while( getline (infile,line)){
			if (x != 0){
				// 1    -    l� a linha e para quando chegar num espa�o,  salva o valor encontrado como double
				
				//2     -    l� depois do espa�o e para quando chegar em outro, salva o valor como double
			
				//3     -    subtrai o 2 do 1 e teremos o desvio padr�o
				
				//pega a string na posi��o x - 1 da lista e concatena com " 2 3", deixando espa�o entre os numeros
			}
			x += 1;
		}
		infile.close();
	}
	else cout << "unable to open file";
	
	
	ifstream f3 (file3.c_str());
	if(f3.is_open()){
		int x = 0;
		while( getline (infile,line)){
			if (x != 0){
				// 1    -    l� a linha e para quando chegar num espa�o,  salva o valor encontrado como double
				
				//2     -    l� depois do espa�o e para quando chegar em outro, salva o valor como double
			
				//3     -    subtrai o 2 do 1 e teremos o desvio padr�o
				
				//pega a string na posi��o x - 1 da lista e concatena com " 2 3", deixando espa�o entre os numeros
			}
			x += 1;
		}
		infile.close();
	}
	else cout << "unable to open file";
	
	
	//n�o sei como criar um novo .txt com o nome recebido da saida
	
	//arquivo .txt de saida
	ofstream myfile (saida.c_str());	
	if(myfile.is_open()){
		
		//passar cada string de lista para o arquivo final
		myfile << "\n";
		myfile.close();
	}
	return 0;
}

