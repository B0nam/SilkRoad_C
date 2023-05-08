# SilkRoad_C
Repositório criado para armazenar seeder de dados escrito em linguagem C/C++ para o trabalho do 3 semestre da faculdade de engenharia de software. O programa em questão , gera uma sequancia de dados aleatórios para o banco de dados da aplicação principal. <br>

O código presente neste repositório está adapatado ao banco GESTAOFRATA de nosso trabalho.



## Para realizar o deploy do bando de dados, siga os passos abaixo:
Para o banco de dados, o mesmo possui uma imagem docker o qual permite que tenhamos acesso a estutura do banco em poucos minutos de forma simples.<br>
#### Crie a imagem a partido do Dockerfile fornecido no repositorio:
`docker buid -t <nome da imagem> .`.<br>

#### Após gerado a imagem, execute o conteíner expondo a porta 1433 para o localhost:
`docker run --rm -p 1433:1433 <nome da imagem>`<br>
(use a opção --rm para remover todos os componentes do conteiner quando o mesmo for finalizado, desta forma não haverá problemas relacionados ao VOLUME)<br>

#### O usuário para acessar o banco de dados é o padrão da imagem docker base, já a senha, pode ser alterada através do Dockerfile.

Usuário: sa<br>
Senha: Abacate123<br>
