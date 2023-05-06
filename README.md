# SilkRoad_C
Repositório criado para armazenar seeder de dadis escrito em linguagem C/C++ para o trabalho do 3 semestre da faculdade de engenharia de software.
O software em questão gera uma sequancia de dados aleatórios para o banco de dados da aplicação principal.

Para o banco de dados, o mesmo possui uma imagem docker o qual permite que tenhamos acesso a estutura do banco em poucos minutos de forma simples.

Para realizar o deploy do bando de dados, siga os passos abaixo:

`docker buid -t <nome da imagem> .`.

Após gerado a imagem, execute o conteíner expondo a porta 1433 para o localhost.

`docker run -p 1433:1433 <nome da imagem>`

O usuário para acesso ao banco é o padrão da imagem docker base, já a senha, pode ser alterada através do Dockerfile.
Usuário: sa
Senha: Abacate123
