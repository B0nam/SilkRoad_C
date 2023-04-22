class User
{
private:
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

	void generateName(string firtsName, string lastName)
	{
		_Name = (firtsName + " " + lastName);
	}

	void generateCPF()
	{
	}

	void generatePhone()
	{
	}

	void generateAdmin()
	{
		if ((rand() % 2) == 1)
		{
			this->_Admin = true;
		}
		else
		{
			this->_Admin = false;
		}
	}
};