# SilkRoad_C
Repositório criado para armazenar seeder de dadis escrito em linguagem C/C++ para o trabalho do 3 semestre da faculdade de engenharia de software. O programa em questão , gera uma sequancia de dados aleatórios para o banco de dados da aplicação principal. <br>

O código presente neste repositório está adapatado ao banco GESTAOFRATA de nosso trabalho.



## Para realizar o deploy do banco de dados, siga os passos abaixo:
Para o banco de dados, o mesmo possui uma imagem docker o qual permite que tenhamos acesso a estutura do banco em poucos minutos de forma simples.<br>
#### Crie a imagem a partido do Dockerfile fornecido no repositorio:
`docker buid -t <nome da imagem> .`.<br>

#### Após gerado a imagem, execute o conteíner expondo a porta 1433 para o localhost:
`docker run --rm -p 1433:1433 <nome da imagem>`<br>
(use a opção --rm para remover todos os componentes do conteiner quando o mesmo for finalizado, desta forma não haverá problemas relacionados ao VOLUME)<br>

#### O usuário para acessar o banco de dados é o padrão da imagem docker base, já a senha, pode ser alterada através do Dockerfile.

Usuário: sa<br>
Senha: Abacate123<br>

## Software em execução.
![1](https://github.com/B0nam/SilkRoad_C/assets/85623265/f32fb26d-484c-49d9-b6fe-111cf721e9b8)
Realizando a conexão com o banco de dados.

![2](https://github.com/B0nam/SilkRoad_C/assets/85623265/2b40d89f-9f22-452c-a918-c6f29f091957)
Escolhendo os dados a serem gerandos.

![3](https://github.com/B0nam/SilkRoad_C/assets/85623265/0c95a025-7a1c-454a-b4af-3855178ed246)
Script .sql gerado pelo software e inserido ao servidor conectado.

# Software INCOMPLETO, talvez no futuro eu finalize este código.
O programa foi realizado no inicio dos meus estudos em POO
