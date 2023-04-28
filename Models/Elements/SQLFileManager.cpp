class SQLFileManager
{
private:
    string _FilePath;
    string _CreationDate;

public:
    void setFilePath(string path)
    {
        _FilePath = path;
    }

    void setCreationDate(string date)
    {
        _CreationDate = date;
    }

    string getCreationDate()
    {
        return _CreationDate;
    }

    string fetchDateTime()
    {
        time_t actualTime = time(nullptr);

        string dateTimeStr = ctime(&now);
        string dateStr = dateTimeStr.substr(0, 10);
        string timeStr = dateTimeStr.substr(0, 10);

        cout << dateTimeStr << endl;

        return creationDateTime;
    }

    void createFile()
    {
        string createPath = path + creationDate;
        filesystem::create_directory(path + this < -getCreationDate())
    }
};