#include "Source/headers.h"						// Headers necessários para o funcionamento do programa.
#include "Models/Elements/Menu.cpp"				// Gerencia o menu do programa.
#include "Models/Elements/DataFileManager.cpp"	// Gerencia os arquivos que contem informações usadas para gerar dados.
#include "Models/Elements/SQLFileManager.cpp"	// Gerencia os arquivos gerados pelo programa que serão usados no banco de dados.
#include "Models/Entities/User.cpp"				// Gerencia a geração de dados do tipo usuário.
#include "Models/Entities/Vehicle.cpp"			// Gerencia a geração de dados do tipo veículo.
#include "Models/DAL/Context/SeederContext.cpp" // Gerencia a conexão do programa com o servidor mssql.
#include "Models/Elements/SQLScriptManager.cpp" // Gerencia a criação e escrita dos scripts sql include e remove.

// g++ -std=c++17 main.cpp -o programa

int main()
{
	srand(time(NULL));							// Define um seed para a função rand().

	Menu sMenu;													// Criação do objeto sMenu.
	sMenu.ShowMenu();											// Apresentação do Menu.
	sMenu.GetAnswer();											// Obtem a resposta do usuário.

	int userMenuChoice = sMenu.getIndex();						// Armazena o tipo de dado a ser gerado do usuário.
	int userMenuNumber = sMenu.getNumber();						// Armazena a quantidade de dados que serão gerados.

	string FirstNamePath = "Source/names/first_names.txt"; 	    // Define o localização do arquivo que contem os nomes.
	string LastNamePath = "Source/names/last_names.txt";		// Define o localização do arquivo que contem os sobrenomes.
	string GeneratedFilesPath = "GeneratedFiles";				// Define a localização do diretório que irá conter os dados gerados.

	DataFileManager sManagerFirstName;							// Criação do objeto que gerencia os primeiros nomes.
	DataFileManager sManagerLastName;							// Criação do objeto que gerencia os sobrenomes.

	User *users = new User[userMenuNumber];						// Criação dos Objetos Usuário.
	Vehicle *vehicles = new Vehicle[userMenuNumber];			// Criação dos objetos Veículo.

	SQLFileManager sSQLFileManager;								// Criação do objeto que gerencia os arquivos com os scripts .sql.
	sSQLFileManager.setFilePath(GeneratedFilesPath);			// Define o Path onde os arquivos gerados serão armazenados.
	sSQLFileManager.fetchDateTime();							// Obtem o tempo atual.
	sSQLFileManager.createFolder();								// Cria o diretorio dos scripts.
	sSQLFileManager.createScriptFiles();						// Cria os scripts no diretório.

	SeederContext sSeederContext;								// Criação do objeto que gerencia a cconexão do programa com o servidor SQL
	sSeederContext.setOptions(
		"{ODBC Driver 17 for SQL Server}",
		"127.0.0.1",
		"master",
		"sa",
		"Abacate123"
		);

	SQLScriptManager sSQLScriptManager;							// Criação do objeto que gerencia o conteúdo dos arquivos scripts
	sSQLScriptManager.setDBName("master");						// NOME BANCO ONDE O SCRIPT É EXECUTADO

	switch (userMenuChoice)
	{
	case 1:
		sManagerFirstName.startManager(FirstNamePath);		// Obtem as linhas do primeiro arquivo.
		sManagerLastName.startManager(LastNamePath);   		// Obtem as linhas do segundo arquivo.

		sSQLScriptManager.openQueryFiles(sSQLFileManager.getInsertName(), sSQLFileManager.getRemoveName());

		for (int i = 0; i < userMenuNumber; i++)
		{
			string firtsName = sManagerFirstName.getRandomLine();
			string lastName = sManagerLastName.getRandomLine();
			string nomeTabela = "vehicle";


			users[i].generateName(firtsName, lastName);
			users[i].generateCPF();
			users[i].generatePhone();
			users[i].generateAdmin();


			sSQLScriptManager.generateQuerys(nomeTabela, "NOMECOLUNA", users[i].getName());
			sSQLScriptManager.generateQuerys(nomeTabela, "NOMECOLUNA", users[i].getCpf());
			sSQLScriptManager.generateQuerys(nomeTabela, "NOMECOLUNA", users[i].getPhone());
			sSQLScriptManager.generateQuerys(nomeTabela, "NOMECOLUNA", users[i].getAdmin());
		}
		break;
	case 2:
		// O usuario escolheu gerar dados para a tabela veiculos
		for (int i = 0; i < userMenuNumber; i++)
		{
			vehicles[i].generateRenavam();
			vehicles[i].generatePlate();
			vehicles[i].generateType();
			vehicles[i].generateModelYear();
			vehicles[i].generateEntraceYear();
			cout << "" << endl;
			cout << "### VEHICLE " << i << " ## " << endl;
			cout << "[+] Gerado RENAVAM: " << vehicles[i].getRenavam() << endl;
			cout << "[+] Gerado PLATE: " << vehicles[i].getPlate() << endl;
			cout << "[+] Gerado TYPE ID: " << vehicles[i].getType() << endl;
			cout << "[+] Gerado MODEL YEAR: " << vehicles[i].getModelYear() << endl;
			cout << "[+] Gerado ENTRACE YEAR: " << vehicles[i].getEntraceYear() << endl;
		}
		break;
	case 3:
		// O usuario escolheu gerar dados para a tablea diario de bordo
		break;
	case 4:

	/*
		sSeederContext.startHandler();
		sSeederContext.startConnection();
		sSeederContext.makeQuery("SELECT 1");
		sSeederContext.endConnection();
		sSeederContext.endHandler();
	*/
		break;
	}

	delete[] users;
	delete[] vehicles;

	return 0;
}