# Importa a imagem MySql.
FROM mcr.microsoft.com/mssql/server:2019-latest

# Aceita a EULA.
ENV ACCEPT_EULA=Y
# Define a senha do usuario SA
ENV MSSQL_SA_PASSWORD=Abacate123

# Copia o script MySQL para o diretorio de inicializacao.
COPY init.sql /docker-entrypoint-initdb.d/

# Expoem a porta 1433
EXPOSE 1433

# Executa o comando de inicializacao do banco.
CMD ["/opt/mssql/bin/sqlservr"]
