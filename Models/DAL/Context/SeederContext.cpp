// https://learn.microsoft.com/en-us/sql/odbc/reference/develop-app/allocating-a-connection-handle-odbc?view=sql-server-ver16

class SeederContext
{
    private:
        SQLHENV hEnv = NULL;   // Enviroment Handler.
        SQLHENV hDbc = NULL;   // Connection Handler.
        SQLHSTMT hStmt = NULL; // Statement Handler.

    public:
        void startHandler()  // Inicializa o Handler.
        {
            if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
            {
                cout << " --------- [env] Error to Alloc enviroment handler ---------" << endl;
                //endHandler();
            }
            if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
            {
                cout << " --------- [dbc] Error to Alloc enviroment handler ---------" << endl;
                //endHandler();
            }
            if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) != SQL_SUCCESS)
            {
                cout << " --------- [stmt] Error to Alloc enviroment handler ---------" << endl;
                //endHandler();
            }
        }
        
        void endHandler() // Finaliza o Handler.
        {
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
            SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
        }
};