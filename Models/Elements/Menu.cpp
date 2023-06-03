class Menu
{
private:
    int _index = 0;  // escolha do tipo de dado a ser gerado
    int _number = 0; // escolha da quantidade de dados a serem gerados
    int _serverConnection = 0;
    string _tableName = "";
    string _databaseAddress = "";
    string _databaseName = "";
    string _databaseUsername = "";
    string _databasePassword = "";

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

    int getServerConnection()
    {
        return _serverConnection;
    }

    string getDatabaseAddress()
    {
        return _databaseAddress;
    }

    string getDatabaseName()
    {
        return _databaseName;
    }


    string getDatabaseUsername()
    {
        return _databaseUsername;
    }

    string getDatabasePassword()
    {
        return _databasePassword;
    }

    void ShowMenu()
    {
        int saveInfo = 0;

        cout << " " << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Seeder de dados para banco mySQL - Software feito para trabalho ESOFT3S" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << " " << endl;
        cout << "[ Conexão com o servidor ] " << endl;
        cout << "Caso não queria, ou não seja possivel estabelecer a conexão com o serividor, os dados gerados pelo seeder ainda poderão ser utilizados!" << endl;
        cout << "Deseja conectar ao servidor? (1 = Sim | 2 = Não)" << endl;
        while (_serverConnection == 0 || _serverConnection > 2)
        {
            cout << "Opção: ";
            cin >> _serverConnection;
            cout << " " << endl;
        }

        if (_serverConnection == 1)
        {
            cout << "[ Digite as informações do servidor MSSQL: ]" << endl;
            cout << "Endereço do servidor: ";
            cin  >> _databaseAddress;
            cout << "Usuário: ";
            cin  >> _databaseUsername;
            cout << "Senha: ";
            cin  >> _databasePassword;
            // cout << "Deseja salvar estas informações? (1 = Sim | 2 = Não)" << endl;
            // while (saveInfo == 0 || saveInfo > 2)
            // {
            //     cin >> saveInfo;
            // }
        }

        // if (saveInfo == 1)
        // {
        //     ofstream includeFile(user.cfg);       // Cria o arquivo de CFG
        //     queryFileInsert.open("user.cfg"); // Abre o arquivo para escrita
            
        //     if (queryFileInsert.is_open())
        //     {
        //           cout << "Arquivo de configuração aberto com sucesso." << endl;
        //     } else {
        //           cout << "Erro ao abrir o arquivo Insert." << endl;
        //           return 0;
        //     }
        // }

        cout << " " << endl;
        cout << "[ Informações do banco de dados ]" << endl;
        cout << "Digite o nome do banco de dados: " << endl;
        cout << "nome: ";
        cin  >> _databaseName;
        cout << " " << endl;

        cout << "[ Escolha o tipo de dado que sera gerado: ]" << endl;
        cout << "(1) Usuario." << endl;
        cout << "(2) Veiculos." << endl;
        cout << "(3) Diario de bordo." << endl;
        cout << "(4) DEBUG." << endl;
        while (_index == 0 || _index > 4)
        {
            cout << "Opcao: ";
            cin >> _index;    
        }
    
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
            cout << "-_- DEBUG -_-" << endl;
            break;
        }
    }
};