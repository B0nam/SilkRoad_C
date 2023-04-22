class Menu{
    private:
        int _index;  // escolha do tipo de dado a ser gerado
        int _number; // escolha da quantidade de dados a serem gerados
    public:
        Menu(){
            ApresentarMenu();
        }

    int getIndex(){
        return _index;
    }

    int setIndex(int value){
        _index = value;
        return _index;
    }

    int getNumber(){
        return _number;
    }

    int setNumber(int value){
        _number = value;
        return _number;
    }

    void ApresentarMenu(){
        std::cout << " " << std::endl;
        std::cout << "-------------------------------------------------------------------------" << std::endl;
        std::cout << "Seeder de dados para banco mySQL - Software feito para trabalho ESOFT3S" << std::endl;
        std::cout << "-------------------------------------------------------------------------" << std::endl;
        std::cout << "Escolha o tipo de dado que será gerado: " << std::endl;
        std::cout << "(1) Usuário." << std::endl;
        std::cout << "(2) Veículos." << std::endl;
        std::cout << "(3) Diario de bordo." << std::endl;
        // escolha das opcoes
        while (_index == 0 || _index > 3){
            std::cout << "Opção: ";
            std::cin  >> _index;
        }

        std::cout << " ### " << _index << " ### " << std::endl;

        // quantidade de dados que serão gerados
        while (_number <= 0){
            std::cout << "Quantidade: ";
            std::cin  >> _number ;
        }

        std::cout << " ### " << _number << " ### " << std::endl;

        OpcaoMenu(_index, _number);
    }

    void OpcaoMenu(int index, int number){
        std::cout << " ### " << _index << " ### " << std::endl;
        std::cout << " ### " << _number << " ### " << std::endl;
        switch (index) {
            case 1: //usuario
                std::cout << " " << std::endl;
                std::cout << "Gerando " << number << " usuários. "<< std::endl;
                break;
            case 2: //veiculo
                std::cout << " " << std::endl;
                std::cout << "Gerando " << number << " veículos. "<< std::endl;
                break;
            case 3: //diario de bordo
                std::cout << " " << std::endl;
                std::cout << "Gerando " << number << " Diários. "<< std::endl;
                break;
        }
    }

};