class DataFileManager
{
private:
    string _FilePath;
    string _RandomLine;
    int _LinesCount;

public:
    void setFilePath(string path)
    {
        _FilePath = path;
    }

    int getLinesCount()
    {
        return _LinesCount;
    }

    string getRandomLine()
    {
        chooseRandomLine(_LinesCount);
        return _RandomLine;
    }

    void startManager(const string &path)
    {
        _FilePath = path;
        _LinesCount = 0;
        string line;
        ifstream file(_FilePath);
        if (file.is_open())
        {
            while (getline(file, line))
            {
                _LinesCount++;
            }
            file.close();
        }
        else
        {
            cout << "ERRO ao abrir arquivo: " << _FilePath << endl;
        }
    }

    void chooseRandomLine(int _LinesCount)
    {
        string line;
        ifstream file(_FilePath);

        if (file.is_open())
        {
            int randomLineNumber = (rand() % _LinesCount);
            for (int i = 0; i < randomLineNumber; i++)
            {
                getline(file, _RandomLine);
            }
            file.close();
        }
        else
        {
            cout << "ERRO ao abrir arquivo: " << _FilePath << endl;
        }
    }
};