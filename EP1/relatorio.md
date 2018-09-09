# Relatório - EP1 - MAC422

Nome: **Ricardo Hideki Hangai Kojo**

NUSP: **10295429**

**Sem dupla**

## Funções

* `int main(int argc, char **argv)`
    * Contém o *loop* do *shell*;
    * Dentro do *loop*, lê o comando através de um *fgets()*. Se o comando lido for `exit` ou `quit`, sai do *shell*. Senão, chama `shell_exec_cmd()` passando o comando lido como argumento.
* `void shell_exec_cmd(char *cmd_line)`
    * Chama `shell_split_cmd()` para separar o `char*` em comando e argumentos;
    * Verifica se o comando é um dos comandos válidos: *`rode, rodeveja, protegepracaramba, liberageral`*;
    * Se for `rode ou rodeveja`, chama `shell_run()`;
    * Se for `protegepracaramba ou liberageral`, chama `shell_change_permission`;
    * Para qualquer outro comando, printa `command not found` e volta para o *loop* do *shell*.
* `int shell_change_permission(char* file_path, int p_type, char *cmd_name)`
    * Recebe o `file_path` do arquivo a ter permissões alteradas;
    * Recebe `p_type` ou *permission_type*, que pode ser: `PROTECT == 0` para `protegepracaramba` ou `CONCEDE == 1` para `liberageral`;
    * Recebe `cmd_name` apenas para printar *feedback* do comando, como *success* ou *error*;
    * Verifica se `file_path != NULL`;
    * Chama a função `chmod()` para alterar permissões do arquivo. Se `p_type == PROTECT`, executa o equivalente a `chmod 000`. Se `p_type == CONCEDE`, executa o equivalente a `chmod 777`.
* `int shell_run(char* file_path, int opt, char *cmd_name)`
    * Recebe o `file_path` do arquivo a ser executado;
    * Recebe `opt`, que pode ser: `IN_BACKGROUND == 0` para `rode` ou `WAIT_RETURN == 1` para `rodeveja`;
    * Recebe `cmd_name` apenas para printar *feedback* do comando, como mensagens de erro;
    * Verifica se `file_path != NULL`;
    * Chama `fork()` para criar um processo filho;
    * Chama `execve()` para executar o arquivo do `file_path`;
    * Se `opt == WAIT_RETURN`, o processo pai chama o `waitpid()` para esperar o programa terminar de rodar e retornar o `status`. 
* `char** shell_split_cmd(char* cmd_line)`
    * Recebe um `char*` e utiliza `strtok()` para separar o conjunto de caractéres em *tokens*;
    * Retorna uma lista de *tokens*, contendo o nome do comando e os argumentos.

## Chamadas de sistema utilizadas

* `chmod()`
  
Chamado em `shell_change_permission()` para os comandos `protegepracaramba e liberageral`.

* `fork()`

Chamado em `shell_run()` para os comandos `rode e rodeveja`.

* `execve()`

Chamado em `shell_run()` para os comandos `rode e rodeveja`.

* `waitpid()`

Chamado em `shell_run()` em modo `WAIT_RETURN`, ou seja, para o comando `rodeveja`. Apenas para o processo pai.

## Testes e bugs conhecidos

