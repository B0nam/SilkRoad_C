class SQLFileManager
{
private:
    string _GeneratedFilesPath;
    string _CreationDate;

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

        string folderName = getFilePath() + "/" + getCreationDate(); // Gera um nome de diretório com a data atual para armazenar os arquivos gerados

        if (!filesystem::exists(folderName)) // Verifica a existencia da pasta com a data atual.
        {
            filesystem::create_directory(folderName); // Caso não exista, o mesmo é criado.
        }
    }

    void createFile() // Responsável por criar os arquivos contendo os códigos SQL
    {

    }
};