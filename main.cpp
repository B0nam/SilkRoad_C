#include "source/headers.h"
#include "models/Menu.cpp"
#include "models/User.cpp"
#include "models/Vehicle.cpp"

int main()
{
	srand(time(NULL));

	Menu sMenu;
	sMenu.ShowMenu();
	sMenu.GetAnswer();

	int userMenuChoice = sMenu.getIndex();
	int userMenuNumber = sMenu.getNumber();

	User *users = new User[userMenuNumber];
	string FirstNamePath = "../source/names/first_names.txt";
	string LastNamePath = "../source/names/last_names.txt";

	switch (userMenuChoice)
	{
	case 1:
		// O usuario escolheu gerar dados para a tabela usuario
		for (int i = 0; i < userMenuNumber; i++)
		{
			users[i].generateData(FirstNamePath, LastNamePath);
			cout << "" << endl;
			cout << "### USER " << i << " ## " << endl;
			cout << "NAME: " << users[i].getName() << endl;
			cout << "CPF: " << users[i].getCpf() << endl;
			cout << "PHONE: " << users[i].getPhone() << endl;
			cout << "Admin: " << users[i].getAdmin() << endl;
		}

		delete[] users;
		break;
	case 2:
		// O usuario escolheu gerar dados para a tabela veiculos
		break;
	case 3:
		// O usuario escolheu gerar dados para a tablea diario de bordo
		break;
	default:
		// Opcao invalida
		break;
	}

	return 0;
}