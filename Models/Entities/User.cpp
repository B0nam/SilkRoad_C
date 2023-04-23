class User
{
private:
	// atributos da classe
	string _Name = "";
	string _CPF = "";
	string _Phone = "";
	bool _Admin = false;

public:
	string getName() // getter name
	{
		return _Name;
	}

	string getCpf() // getter cpf
	{
		return _CPF;
	}

	string getPhone() // getter phone
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
		int cpf[11];
		string formattedCpf = "";
		int sum;

		// Gera 9 numeros aleatorios
		for (int i = 0; i < 9; i++)
		{
			cpf[i] = rand() % 10;
		}

		// Calculo do primeiro digito verificador
		sum = 0;
		for (int i = 0; i < 9; i++)
		{
			sum += cpf[i] * (10 - i);
		}
		int digit1 = 11 - (sum % 11);
		if (digit1 >= 10)
		{
			digit1 = 0;
		}
		cpf[9] = digit1;

		// Calculo do segundo digito verificador
		sum = 0;
		for (int i = 0; i < 10; i++)
		{
			sum += cpf[i] * (11 - i);
		}
		int digit2 = 11 - (sum % 11);
		if (digit2 >= 10)
		{
			digit2 = 0;
		}
		cpf[10] = digit2;

		// Formata o CPF
		for (int i = 0; i < 11; i++)
		{
			formattedCpf += to_string(cpf[i]);
			if (i == 2 || i == 5)
			{
				formattedCpf += ".";
			}
			else if (i == 8)
			{
				formattedCpf += "-";
			}
		}

		_CPF = formattedCpf;
	}

	void generatePhone()
	{
		string formattedCellNumber = "(44)9xxxx-xxxx";

		for (int i = 0; i < 14; i++)
		{
			if (formattedCellNumber[i] == 'x')
			{
				formattedCellNumber[i] = to_string(rand() % 10)[0];
			}
		}
		// checa se o primeiro numero apos o primeiro 9 é igual a 0
		while (formattedCellNumber[5] == 0)
		{
			formattedCellNumber[5] = to_string(rand() % 10)[0];
		}

		_Phone = formattedCellNumber;
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