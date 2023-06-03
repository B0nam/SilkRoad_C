// https://learn.microsoft.com/en-us/sql/odbc/reference/develop-app/allocating-a-connection-handle-odbc?view=sql-server-ver16

class SeederContext
{
private:
    SQLHENV hEnv = NULL;        // Enviroment Handler.
    SQLHDBC hDbc = NULL;        // Connection Handler.
    SQLHSTMT hStmt = NULL;      // Querys Handler.
    
    SQLRETURN retCode = SQL_SUCCESS;   // Código de retorno

    string _OptionDriver;   // Driver ODBC.
    string _OptionServer;                          // Server name.
    string _OptionDatabase;                          // Database name.
    string _OptionUID;                                   // User name.
    string _OptionPWD;                           // User password.

    string _OptionsODBCO;
public:

    void setOptions(string OptionDriver, string OptionServer, string OptionDatabase, string OptionUID, string OptionPWD)
    {
        _OptionDriver = OptionDriver;
        _OptionServer = OptionServer;
        _OptionDatabase = OptionDatabase;
        _OptionUID = OptionUID;
        _OptionPWD = OptionPWD;
        applyOptions();
    }

    string applyOptions() // Define as opções
    {
        ostringstream config;
        config << "DRIVER=" << _OptionDriver << ";"
            << "SERVER=" << _OptionServer << ";"
            << "DATABASE=" << _OptionDatabase << ";"
            << "UID=" << _OptionUID << ";"
            << "PWD=" << _OptionPWD << ";";

        return config.str();
    }

    string getOptionDatabase(){
        return _OptionDatabase;
    }

    void startHandler()  // Inicializa o Handler.
    {
        retCode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
        retCode = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
        retCode = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

        if (retCode != SQL_SUCCESS) {
            showSQLError(hDbc, SQL_HANDLE_DBC);
            return;
        }
    }

    void startConnection() {
            SQLCHAR connStr[1024];
            const string options = applyOptions();
        
        if (options.length() < sizeof(connStr))
        {
            strcpy((char*)connStr, options.c_str());
            retCode = SQLDriverConnect(hDbc, NULL, connStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
        }
        else 
        {
            cout << "Erro: A string de configuração é muito grande." << endl;
        }
        if (retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO)
        {
            cout << "Conexão estabelecida com sucesso!" << endl;
        }
        else
        {
            // Lida com o erro de conexão
            showSQLError(hDbc, SQL_HANDLE_DBC);
        }
    }

    void sendQuery(string query)
    {
        retCode = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

        SQLCHAR sqlQuery[query.length() + 1];
        strcpy(reinterpret_cast<char*>(sqlQuery), query.c_str());
        retCode = SQLExecDirect(hStmt, sqlQuery, SQL_NTS);
        

        if (retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO)
        {
            // Processa o resultado da consulta aqui
            cout << "Query executada com sucesso!" << endl;
        }
        else
        {
            // Lida com o erro da execução da consulta
            showSQLError(hStmt, SQL_HANDLE_STMT);
        }
        endConnection();
        endHandler();
    }

    int sendScriptQuerys(string filename)
    {
        ifstream file(filename);
        string line;

        if (file.is_open())
        {
            cout << "Arquivo script aberto com sucesso." << endl;
            while (getline(file, line)) {
                sendQuery(line);
            }
        file.close();
        return 1;
        } else {
            cout << "Erro ao abrir o arquivo script." << endl;
            return -1;
        }
    }

    void endHandler() // Finaliza o Handler.
    {
        SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
        SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
        SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    }

    void endConnection() // Encerra a conexão.
    {
        SQLDisconnect(hDbc);
    }

    void showSQLError(SQLHANDLE handle, SQLSMALLINT handleType)
    {
        SQLCHAR sqlState[6];
        SQLINTEGER errorCode;
        SQLCHAR message[SQL_MAX_MESSAGE_LENGTH];
        SQLSMALLINT messageLength;
        SQLRETURN retCode;

        //cout << "Erro encontrado: " << endl;
        
        while (SQL_SUCCESS == (retCode = SQLGetDiagRec(handleType, handle, 1, sqlState, &errorCode, message, sizeof(message), &messageLength))) {
            cout << "SQLSTATE: " << sqlState << endl;
            cout << "ErrorCode: " << errorCode << endl;
            cout << "Mensagem: " << message << endl;
            endConnection();
            endHandler();
        }
    }
};