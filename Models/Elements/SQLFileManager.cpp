class SQLFileManager
{
private:
    string _GeneratedFilesPath;
    string _CreationDate;
    string _folderName;

public:
    void setFilePath(string path)
    {
        _GeneratedFilesPath = path;
    }
    
    string getFilePath()
    {
        return _GeneratedFilesPath;
    }

    void setCreationDate(string date)
    {
        _CreationDate = date;
    }

    string getCreationDate()
    {
        return _CreationDate;
    }

    void fetchDateTime()
    {
        time_t actualTime = time(nullptr);

        //string dateTimeStr = ctime(&actualTime);
        tm timeinfo = *localtime(&actualTime);

        ostringstream oss;
        oss << put_time(&timeinfo, "%Y-%m-%d");

        string formated = oss.str();

        setCreationDate(formated);
    }

    void createFolder() // Responsável por criar os diretórios que irão armazenar os dados comandos SQL
    {
        if (!filesystem::exists(getFilePath())) // Verifica a existencia do Diretório raiz GeneratedFiles
        {
            filesystem::create_directory(getFilePath()); // Caso não exista, o mesmo é criado
        }



        _folderName = getFilePath() + "/" + getCreationDate(); // Gera um nome de diretório com a data atual para armazenar os arquivos gerados
        string includePath = _folderName + "/Include";
        string removePath = _folderName + "/Remove";

        if (!filesystem::exists(_folderName)) // Verifica a existencia da pasta com a data atual.
        {
            filesystem::create_directory(_folderName); // Caso não exista, o mesmo é criado.
            filesystem::create_directory(includePath);  // Cria o diretório para incluir dados.
            filesystem::create_directory(removePath);   // Cria o diretório para excluir dados.
        }
    }
    
    void createScriptFiles()
    {
        ostringstream includeScript;
        ostringstream removeScript;
    
        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);

        ostringstream timeStr;
        timeStr << put_time(localTime, "%H%M%S");

        includeScript << _folderName << "/Include/" << timeStr.str() << ".sql";
        removeScript << _folderName << "/Remove/" << timeStr.str() << ".sql";

        ofstream includeFile(includeScript.str());
        ofstream removeFile(removeScript.str());
    }
};