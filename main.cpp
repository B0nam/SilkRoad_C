#include "source/headers.h"
#include "models/Usuario.cpp"

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

