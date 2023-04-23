#include "Source/headers.h"
#include "Models/Elements/Menu.cpp"
#include "Models/Elements/FileManager.cpp"
#include "Models/Entities/User.cpp"
#include "Models/Entities/Vehicle.cpp"

int main()
{
	srand(time(NULL));

	Menu sMenu;
	sMenu.ShowMenu();
	sMenu.GetAnswer();

	int userMenuChoice = sMenu.getIndex();
	int userMenuNumber = sMenu.getNumber();

	string FirstNamePath = "../source/names/first_names.txt";
	string LastNamePath = "../source/names/last_names.txt";

	FileManager sManagerFirstName;
	FileManager sManagerLastName;

	User *users = new User[userMenuNumber];
	Vehicle *vehicles = new Vehicle[userMenuNumber];

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
			cout << "NAME: " << users[i].getName() << endl;
			cout << "CPF: " << users[i].getCpf() << endl;
			cout << "PHONE: " << users[i].getPhone() << endl;
			cout << "Admin: " << users[i].getAdmin() << endl;
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
			cout << "RENAVAM: " << vehicles[i].getRenavam() << endl;
			cout << "PLATE: " << vehicles[i].getPlate() << endl;
			cout << "TYPE ID: " << vehicles[i].getType() << endl;
			cout << "MODEL YEAR: " << vehicles[i].getModelYear() << endl;
			cout << "ENTRACE YEAR: " << vehicles[i].getEntraceYear() << endl;
		}
		break;
	case 3:
		// O usuario escolheu gerar dados para a tablea diario de bordo
		break;
	default:
		// Opcao invalida
		break;
	}
	delete[] users;

	return 0;
}