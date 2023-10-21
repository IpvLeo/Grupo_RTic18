# Prova em Grupo_RTic18

Acrescente um menu inicial ao seu programa com as seguintes opções. 

1. Gestão de Pacientes. 
2. Gestão de Médicos. 
3. Gestão de Consultas. 
ZERO. Sair do Programa. 

A primeira opção leva o programa para o menu de pacientes (feito na tarefa anterior). 

A segunda opção leva ao menu de Médicos (feito na tarefa anterior) 

A terceira opção leva ao menu de Consultas, onde o usuário tem acesso ao módulo de gestão de
consultas. 

Crie um módulo de gestão de consultas. 

1. Incluir consultas 
Solicita o CPF do paciente e o CRM do Médico
Checa inconsistências (CPF não existe, CRM não existe) 
Registra a consulta na coleção de consultas. 
Solicita a data, a hora e a duração da consulta. O atributo "Realizada" deve ser iniciado 
com o valor "n". 

2. Excluir uma consulta 
Solicita o CRM do Médico
Lista todos os paciente com consultas por aquele médico 
Solicita o CPF do paciente que não realizou/realizará a consulta 
Exclui o registro 

3. Alterar consulta 
Solicita o CRM do Médico
Lista todos os pacientes com consultas por aquele médico 
Solicita CPF. 
Pergunta se quer registrar a consulta como "Realizada". Em caso positivo, altera o 
atributo "Realizada" para "s". 
Em caso negativo. 
Pergunta se deseja alterar a data. Em seguida se deseja alterar a hora. Em 
seguida se deseja alterar a duração. Em seguida se deseja alterar o convênio. 
Altera o registro com as alterações feitas. 

4. Listar todos as consultas 
Identificando as já realizadas e as não realizadas 

ZERO. Sair. Retorna para um menu anterior.
