class Menu
{
private:
    int _index = 0;  // escolha do tipo de dado a ser gerado
    int _number = 0; // escolha da quantidade de dados a serem gerados

public:
    int getIndex()
    {
        return _index;
    }

    int setIndex(int value)
    {
        _index = value;
        return _index;
    }

    int getNumber()
    {
        return _number;
    }

    int setNumber(int value)
    {
        _number = value;
        return _number;
    }

    void ShowMenu()
    {
        cout << " " << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Seeder de dados para banco mySQL - Software feito para trabalho ESOFT3S" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Escolha o tipo de dado que sera gerado: " << endl;
        cout << "(1) Usuario." << endl;
        cout << "(2) Veiculos." << endl;
        cout << "(3) Diario de bordo." << endl;
        cout << "(4) DEBUG." << endl;
    }

    void GetAnswer()
    {
        // escolha das opcoes
        while (_index == 0 || _index > 4)
        {
            cout << "Opcao: ";
            cin >> _index;
        }

        // quantidade de dados que serão gerados
        while (_number <= 0)
        {
            cout << "Quantidade: ";
            cin >> _number;
        }

        OptionMenu(_index, _number);
    }

    void OptionMenu(int index, int number)
    {
        switch (index)
        {
        case 1: // usuario
            cout << " " << endl;
            cout << "-_- Gerando " << number << " Usuarios. -_-" << endl;
            break;
        case 2: // veiculo
            cout << " " << endl;
            cout << "-_- Gerando " << number << " Veiculos. -_-" << endl;
            break;
        case 3: // diario de bordo
            cout << " " << endl;
            cout << "-_- Gerando " << number << " Diarios. -_-" << endl;
            break;
        case 4: // DEBUG
            cout << "" << endl;
            cout << "-_- DEBUG -_-";
            break;
        }
    }
};