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
};