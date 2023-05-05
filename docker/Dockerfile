# Importa a imagem MySql.
FROM mcr.microsoft.com/mssql/server:2019-latest

# Declaracao variavel contendo a senha do usuario sa
ENV DB_PASSWORD=Abacate123

# Aceita a EULA.
ENV ACCEPT_EULA=Y

# Define a senha do usuario SA
ENV MSSQL_SA_PASSWORD=${DB_PASSWORD}

RUN mkdir /var/opt/mssql/app/
RUN mkdir /var/opt/mssql/app/database-sql-script/

# Copia o script MySQL para o diretorio de inicializacao.
COPY init.sql /var/opt/mssql/app/database-sql-script/

# Expoem a porta 1433
EXPOSE 1433

VOLUME ["/opt/mssql/app/database-data"]

# Executa o comando de inicializacao do banco e o comando para executar o script.
#CMD ["/bin/bash", "-c", "/opt/mssql/bin/sqlservr & sleep 30 && /opt/mssql-tools/bin/sqlcmd -S localhost -U sa -P ${DB_PASSWORD} -i /var/opt/mssql/app/database-sql-script/init.sql"]