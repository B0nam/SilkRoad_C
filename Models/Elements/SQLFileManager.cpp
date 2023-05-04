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
        oss << put_time(&timeinfo, "%Y-%m-%d_%H:%M:%S");

        string formated = oss.str();

        setCreationDate(formated);
    }

    void createFolder()
    {
        if (!filesystem::exists(getFilePath())) // Verifica a existencia do Diretório GeneratedFiles
        {
            cout << "O ARQUIVO NÃO EXISTE" << endl;
            filesystem::create_directory(getFilePath()); // Caso não exista, o mesmo é criado
        } else {
            cout << "O ARQUIVO EXISTE ------" << endl;
        }
        string folderName = getFilePath() + getCreationDate();
        filesystem::create_directory(folderName);
    }
};