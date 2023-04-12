#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstring>

class Usuario {
	private:
		char nome[50];
		char cpf[16];
 		char telefone[16];
	public:
		Usuario() {
			gerarDados();
		}
	
	const char* getNome(){
		return nome;
	}

	const char* getCpf(){
		return cpf;
	}

	const char* getTelefone(){
		return telefone;
	}
	
	void gerarDados() {
		// Gera um nome
		strcpy(this->nome, std::to_string((rand()%9999999999)).c_str());
		// Gera um CPF
		strcpy(this->cpf, std::to_string((rand()%9999999999)).c_str());
		// Gera um telefone
		strcpy(this->telefone, std::to_string((rand()%9999999999)).c_str());
	}

};

int main(){
	srand(time(NULL));

	int quantidade = 5;

	Usuario* usuarios = new Usuario[quantidade]; //array de usuários com [quantidade] elementos. ponteiro do tipo Usuario.

	for (int i=0; i < quantidade; i++) {
		std::cout << "## Usuario " << i << " ##" << std::endl;
		usuarios[i].gerarDados();
		std::cout << "Nome:     " << usuarios[i].getNome() << std::endl;
		std::cout << "Cpf:      " << usuarios[i].getCpf() << std::endl;
		std::cout << "Telefone: " << usuarios[i].getTelefone() << std::endl;
		std::cout << " " << std::endl;
	}

	return 0;
}
