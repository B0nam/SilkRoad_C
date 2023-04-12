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