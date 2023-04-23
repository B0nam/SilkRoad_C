class Vehicle
{
private:
    string _Renavam = ""; // renavam
    string _Plate = "";   // placa
    int _TypeId = 0;      // tipo do veiculo, moto, carro, caminhão
    int _ModelYear = 0;   // ano do veiculo
    int _EntraceYear = 0; // ano de entrada na garage
    // int _modelId;     //codigo do modelo
    // int _slotId;      //codigo da vaga
    // int _driverId;    //codigo do motorista
public:
    string getRenavam()
    {
        return _Renavam;
    }

    string getPlate()
    {
        return _Plate;
    }

    int getType()
    {
        return _TypeId;
    }

    int getModelYear()
    {
        return _ModelYear;
    }

    int getEntraceYear()
    {
        return _EntraceYear;
    }

    void generateRenavam()
    {
        // Gera os 11 primeiros dígitos do Renavam
        string renavam;
        for (int i = 0; i < 11; i++)
        {
            renavam += to_string(rand() % 10);
        }

        // Calcula o último dígito do Renavam
        int sum = 0;
        for (int i = 0; i < 8; i++)
        {
            sum += (renavam[i] - '0') * (i + 2);
        }
        sum += (renavam[8] - '0') * 2 + renavam[9] * 3 + renavam[10] * 4;
        int digit = 11 - (sum % 11);
        if (digit >= 10)
            digit = 0;
        renavam += to_string(digit);

        _Renavam = renavam;
    }

    void generatePlate()
    {
        string plate = "";
        char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        // Gera 3 letras aleatórias
        for (int i = 0; i < 3; i++)
        {
            int index = rand() % 26; // Gera um número aleatório entre 0 e 25
            plate += letters[index];
        }

        // Gera 4 números aleatórios
        for (int i = 0; i < 4; i++)
        {
            int index = rand() % 10; // Gera um número aleatório entre 0 e 9
            plate += to_string(numbers[index]);
        }

        // Adiciona o traço no meio da placa
        plate.insert(3, "-");

        _Plate = plate;
    }

    void generateType()
    {
        _TypeId = (rand() % 5);
    }

    void generateModelYear()
    {
        int year = 1980;
        year = (year + (rand() % 40));

        _ModelYear = year;
    }

    void generateEntraceYear()
    {
        int year = 2018;
        year = (year + (rand() % 5));

        _EntraceYear = year;
    }
};