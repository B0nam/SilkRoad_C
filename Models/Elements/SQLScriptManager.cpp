//#include "../DAL/Context/SeederContext.cpp"
/*
 Responsavel por montar os scripts que inserem e removem os dados gerados.
 O ideal é seguir o seguinte fluxo:
    
    [gerar dados]
          |
          V
    (gerar arquivos)
       |         |
       V         V
 (inserção)    (remoção)
       |           |
       V           V 
[inserir dados  [Permito a
 no banco]       reversão]

*/

class SQLScriptManager{
    private:
      ofstream queryFileInsert;
      ofstream queryFileRemove;
      string _DBName;
    public:

      void setDBName(string DBName)
      {
            _DBName = DBName;
      }

      string getDBName()
      {
            return _DBName;
      }

      int openQueryFiles(string fileNameInsert, string fileNameRemove)
      {
            queryFileInsert.open(fileNameInsert); // Abre o arquivo para escrita
            queryFileRemove.open(fileNameRemove); // Abre o arquivo para escrita

            if (queryFileInsert.is_open())
            {
                  cout << "Arquivo Insert aberto com sucesso." << endl;
                  queryFileInsert << "USE " << _DBName << ";\n";
            } else {
                  cout << "Erro ao abrir o arquivo Insert." << endl;
                  return 0;
            }

            if (queryFileRemove.is_open()) 
            {
                  cout << "Arquivo Remove aberto com sucesso." << endl;
                  queryFileRemove << "USE " << _DBName << ";\n";
            } else {
                  cout << "Erro ao abrir o arquivo Remove." << endl;
                  queryFileInsert.close(); // Fecha o arquivo Insert aberto
            return 0;
            }
      // Ambos os arquivos foram abertos com sucesso
      return 1;
      }


      void generateQuerys(string tableName, string columnName, string generatedData)
      {
            // Insert
            queryFileInsert << "INSERT INTO " << tableName << "(" << columnName << ")" << "VALUES" << "(" << generatedData << ");\n" ;
      
            // Remove
            queryFileRemove << "DELETE FROM " << tableName << "WHERE" << columnName << " = " << generatedData << ");\n" ;
      
      }
};