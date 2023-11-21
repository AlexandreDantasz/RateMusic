<h1>Rate Music</h1>

<h2>Requisitos do usuário:</h2>


- O sistema deve ser capaz de realizar o cadastro de um usuário no banco de dados, utilizando e-mail e senha.
- É necessário que o sistema efetue o login de um usuário e valide, usando seu e-mail e senha.
- O sistema deve apresentar a possibilidade de exclusão de conta, por meio da confirmação por senha.
- O sistema deve apresentar a possibilidade de atualizar o e-mail da conta, também, por meio da confirmação por senha.


<h2>Requisitos das músicas:</h2>

	
- O sistema deve ser capaz de inserir músicas em um banco de dados, deve conter o nome da música, id da música, chave do usuário, nome do autor e a avaliação do usuário (0 ou 5 estrelas).
- No banco de dados,  a chave do usuário deve referenciar o id do usuário no modo cascata (ON DELETE CASCADE) para, caso um usuário seja excluído, todas as músicas da biblioteca do usuário sejam deletadas.


<h2>Requisitos da interação (usuário e músicas):</h2>


- O usuário deve ser capaz de adicionar informações sobre música e inserir em sua biblioteca de músicas.
- O usuário deve ser capaz de poder realizar buscas na sua própria biblioteca de músicas.
- O usuário deve ser capaz de poder listar sua biblioteca de músicas.


<h2>Requisitos da interação (usuário e usuário):</h2>


- Um usuário deve ser capaz de visualizar a biblioteca de músicas de outro usuário, realizando uma busca por e-mail.