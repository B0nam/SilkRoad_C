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
    public:
      int openQueryFiles(string fileNameInsert, string fileNameRemove)
      {
            ofstream queryFileInsert(fileNameInsert); // Abre o arquivo para escrita
            ofstream queryFileRemove(fileNameRemove); // Abre o arquivo para escrita

            if (queryFileInsert.is_open()) {
                  // queryFile << "INSERT INTO " << tableName << "(" << columnName << ")" << "VALUES" << "(" << generatedData << ")\n" ;
                  // queryFile.close(); // Fecha o arquivo
            } else {
                  std::cout << "Erro ao abrir o arquivo Insert." << std::endl;
                  closeQueryFiles();
                  return 0;
            } if (queryFileRemove.is_open()) {
                  // queryFile << "INSERT INTO " << tableName << "(" << columnName << ")" << "VALUES" << "(" << generatedData << ")\n" ;
                  // queryFile.close(); // Fecha o arquivo
            } else {
                  std::cout << "Erro ao abrir o arquivo Remove." << std::endl;
                  closeQueryFiles();
                  return 0;
            }
      return 1;
      }

      int closeQueryFiles()
      {
            queryFileInsert.close();
            queryFileRemove.close();
            cout << "Arquivos fechados com sucesso." << endl;
      }

      generateInsertQuery(string InsertName)
      {
            queryFile << "INSERT INTO " << tableName << "(" << columnName << ")" << "VALUES" << "(" << generatedData << ")\n" ;
      }

      generateRemoveQuery(string InsertName)
      {
            //queryFile << "INSERT INTO " << tableName << "(" << columnName << ")" << "VALUES" << "(" << generatedData << ")\n" ;
      }

};