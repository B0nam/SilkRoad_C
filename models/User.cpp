class User
{
private:
	// atributos para os nomes
	int _FirstNamesNumber = 0;
	int _LastNamesNumber = 0;
	// atributos da classe
	string _Name;
	char _CPF[16];
	char _Phone[16];
	bool _Admin;

public:
	string getName() // getter name
	{
		return _Name;
	}

	const char *getCpf() // getter cpf
	{
		return _CPF;
	}

	const char *getPhone() // getter phone
	{
		return _Phone;
	}

	bool getAdmin() // getter admin
	{
		return _Admin;
	}

	void generateData(string FirstNamePath, string LastNamePath)
	{
		this->_FirstNamesNumber = countFileLines(FirstNamePath);
		this->_LastNamesNumber = countFileLines(LastNamePath);
		generateFirstName(FirstNamePath);
		generateLastName(LastNamePath);
		generateName();
		generateCPF();
		generatePhone();
		generateAdmin();
	}

	void countFileLines(string path)
	{
	}

	void generateFirstName()
	{

		return count;
	}

	void generateLastName()
	{
	}

	void generateName()
	{
	}

	void generateCPF()
	{
	}

	void generatePhone()
	{
	}

	void generateAdmin()
	{
		if ((rand() % 2 + 1) == 1)
		{
			this->_Admin = true;
		}
		else
		{
			this->_Admin = false;
		}
	}
};