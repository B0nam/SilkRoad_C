// https://learn.microsoft.com/en-us/sql/odbc/reference/develop-app/allocating-a-connection-handle-odbc?view=sql-server-ver16

class SeederContext
{
private:
    SQLHENV hEnv = NULL;        // Enviroment Handler.
    SQLHDBC hDbc = NULL;        // Connection Handler.
    SQLRETURN retCode = SQL_SUCCESS;   // Código de retorno

    std::string _OptionDriver = "{ODBC Driver 17 for SQL Server}";   // Driver ODBC.
    std::string _OptionServer = "127.0.0.1";                          // Server name.
    std::string _OptionDatabase = "master";                          // Database name.
    std::string _OptionUID = "sa";                                   // User name.
    std::string _OptionPWD = "Abacate123";                           // User password.

    std::string _OptionsODBCO;
public:
    std::string setOptions()
    {
        std::ostringstream config;
        config << "DRIVER=" << _OptionDriver << ";"
            << "SERVER=" << _OptionServer << ";"
            << "DATABASE=" << _OptionDatabase << ";"
            << "UID=" << _OptionUID << ";"
            << "PWD=" << _OptionPWD << ";";

        return config.str();
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
            const std::string options = setOptions();
        
        if (options.length() < sizeof(connStr))
        {
            strcpy((char*)connStr, options.c_str());
            retCode = SQLDriverConnect(hDbc, NULL, connStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
        }
    else {
        std::cout << "Erro: A string de configuração é muito grande." << std::endl;
    }
        if (retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) {
            std::cout << "Conexão estabelecida com sucesso!" << std::endl;

            // Executa uma consulta
            SQLHSTMT hStmt;
            retCode = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

            SQLCHAR query[] = "SELECT * FROM teste";
            retCode = SQLExecDirect(hStmt, query, SQL_NTS);

            if (retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) {
                // Processa o resultado da consulta aqui
                std::cout << "Consulta executada com sucesso!" << std::endl;
            }
            else {
                // Lida com o erro da execução da consulta
                showSQLError(hStmt, SQL_HANDLE_STMT);
            }

            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            SQLDisconnect(hDbc);

        }
        else
        {
            // Lida com o erro de conexão
            showSQLError(hDbc, SQL_HANDLE_DBC);
        }

        endHandler();
    }

    void endHandler() // Finaliza o Handler.
    {
        SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
        SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
    }

        void showSQLError(SQLHANDLE handle, SQLSMALLINT handleType)
        {
            SQLCHAR sqlState[6];
            SQLINTEGER errorCode;
            SQLCHAR message[SQL_MAX_MESSAGE_LENGTH];
            SQLSMALLINT messageLength;
            SQLRETURN retCode;

            std::cout << "Erro encontrado: " << std::endl;
        
            while (SQL_SUCCESS == (retCode = SQLGetDiagRec(handleType, handle, 1, sqlState, &errorCode, message, sizeof(message), &messageLength))) {
                std::cout << "SQLSTATE: " << sqlState << std::endl;
                std::cout << "ErrorCode: " << errorCode << std::endl;
                std::cout << "Mensagem: " << message << std::endl;
            }
        }
};