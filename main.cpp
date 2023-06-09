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

	SQLScriptManager sSQLScriptManager;							// Criação do objeto que gerencia o conteúdo dos arquivos scripts
	sSQLScriptManager.setDBName("master");						// NOME BANCO ONDE O SCRIPT É EXECUTADO


	SeederContext sSeederContext;								// Criação do objeto que gerencia a cconexão do programa com o servidor SQL

	if (sMenu.getServerConnection() == 1)
	{
		sSeederContext.setOptions(
			"{ODBC Driver 17 for SQL Server}",
			sMenu.getDatabaseAddress(),
			sMenu.getDatabaseName(),
			sMenu.getDatabaseUsername(),
			sMenu.getDatabasePassword()
		);
	}

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
			string nomeTabela = "Users";


			users[i].generateName(firtsName, lastName);
			users[i].generateCPF();
			users[i].generatePhone();
			users[i].generateAdmin();

			cout << "" << endl;
			cout << "### USERS " << i << " ## " << endl;
			cout << "[+] Gerado NOME:  " << users[i].getName() << endl;
			cout << "[+] Gerado CPF:   " << users[i].getCpf() << endl;
			cout << "[+] Gerado PHONE: " << users[i].getPhone() << endl;
			cout << "[+] Gerado ADMIN: " << users[i].getAdmin() << endl;

			sSQLScriptManager.generateQuerys(nomeTabela, "Name", users[i].getName(), true);
			sSQLScriptManager.generateQuerys(nomeTabela, "Cpf", users[i].getCpf(), true);
			sSQLScriptManager.generateQuerys(nomeTabela, "phone", users[i].getPhone(), true);
			sSQLScriptManager.generateQuerys(nomeTabela, "Admin", users[i].getAdmin(), false);
		}
		cout << "[ --- Os dados foram gerados e salvos. --- ]" << endl;
		if (sMenu.getServerConnection() == 1)
		{
			cout << "Aplicando dados ao servidor..." << endl;
			sSeederContext.startHandler();
			sSeederContext.startConnection();
			sSeederContext.sendScriptQuerys(sSQLFileManager.getInsertName());
			sSeederContext.endConnection();
			sSeederContext.endHandler();
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
		sSeederContext.sendQuery("SELECT 1");
		sSeederContext.endConnection();
		sSeederContext.endHandler();
	*/
		break;
	}

	delete[] users;
	delete[] vehicles;

	return 0;
}