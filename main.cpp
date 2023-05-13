#include "Source/headers.h"						// Headers necessários para o funcionamento do programa.
#include "Models/Elements/Menu.cpp"				// Gerencia o menu do programa.
#include "Models/Elements/DataFileManager.cpp"	// Gerencia os arquivos que contem informações usadas para gerar dados.
#include "Models/Elements/SQLFileManager.cpp"	// Gerencia os arquivos gerados pelo programa que serão usados no banco de dados.
#include "Models/Entities/User.cpp"				// Gerencia a geração de dados do tipo usuário.
#include "Models/Entities/Vehicle.cpp"			// Gerencia a geração de dados do tipo veículo.
#include "Models/DAL/Context/SeederContext.cpp" // Gerencia a conexão do programa com o servidor mssql

int main()
{
	srand(time(NULL));							// Define um seed para a função rand().

	Menu sMenu;													// Criação do objeto sMenu.
	sMenu.ShowMenu();											// Apresentação do Menu.
	sMenu.GetAnswer();											// Obtem a resposta do usuário.

	int userMenuChoice = sMenu.getIndex();						// Armazena o tipo de dado a ser gerado do usuário.
	int userMenuNumber = sMenu.getNumber();						// Armazena a quantidade de dados que serão gerados.

	string FirstNamePath = "../Source/names/first_names.txt";	// Define o localização do arquivo que contem os nomes.
	string LastNamePath = "../Source/names/last_names.txt";		// Define o localização do arquivo que contem os sobrenomes.
	string GeneratedFilesPath = "GeneratedFiles";				// Define a localização do diretório que irá conter os dados gerados.

	FileManager sManagerFirstName;								// Criação do objeto que gerencia os primeiros nomes.
	FileManager sManagerLastName;								// Criação do objeto que gerencia os sobrenomes.

	User *users = new User[userMenuNumber];						
	Vehicle *vehicles = new Vehicle[userMenuNumber];

	SQLFileManager sSQLManager;
	sSQLManager.setFilePath(GeneratedFilesPath);
	sSQLManager.fetchDateTime();
	sSQLManager.createFolder();

	SeederContext sSeederContext;

	switch (userMenuChoice)
	{
	case 1:
		sManagerFirstName.startManager(FirstNamePath); // Obtem as linhas do primeiro arquivo.
		sManagerLastName.startManager(LastNamePath);   // Obtem as linhas do segundo arquivo.

		// Gera os dados
		for (int i = 0; i < userMenuNumber; i++)
		{
			string firtsName = sManagerFirstName.getRandomLine();
			string lastName = sManagerLastName.getRandomLine();

			users[i].generateName(firtsName, lastName);
			users[i].generateCPF();
			users[i].generatePhone();
			users[i].generateAdmin();
			cout << "" << endl;
			cout << "### USER " << i << " ## " << endl;
			cout << "[+] Gerado NAME: : " << users[i].getName() << endl;
			cout << "[+] Gerado CPF: " << users[i].getCpf() << endl;
			cout << "[+] Gerado PHONE: " << users[i].getPhone() << endl;
			cout << "[+] Gerado Admin: " << users[i].getAdmin() << endl;
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
		sSeederContext.startHandler();
		sSeederContext.startConnection();
		//sSeederContext.endHandler();
		break;
	}

	delete[] users;
	delete[] vehicles;

	return 0;
}