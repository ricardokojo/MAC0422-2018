# MAC422 - Aula 4

## As chamadas de sistema do Minix

### Sinais

* **SIGNAL(sig, func)**: baixo nível. Registra o tratamento do sinal.
* **KILL(pid, signal)**: manda um sinal a um processo. **NÃO MATA O PROCESSO IMEDIATAMENTE**. O processo só é morto se não tratar o sinal.
* **ALARM(seconds)**: agenda um envio de um sinal *SIGALARM* após *seconds*.
* **PAUSE()**: suspende o processo até que ele recebe outro sinal.

### Administração de Arquivos

* **CREAT(name, mode)**: cria infraestrutura para um novo arquivo. Cria, abre, seta tamanho para 0, retorna descritor.
* **Mknod(name, mode, addr)**: cria indexador do arquivo.
* **Open(file, how)**: *file* = caminho do arquivo, retorna descritor.
* **Close(fd)**: fecha o arquivo a partir de um descritor (ponteiro direto para o arquivo).
* **Read(fd, buffer, nbytes)**: lê dados de um buffer e retorna os bytes lidos.
* **Write(fd, buffer, nbytes)**: grava dados de um buffer, retorna número de bytes gravados.
* **Lseek(fd, offset, whence)**: muda o ponteiro do arquivo.
* **stat(name, &buf); fstat(fd, &buf)**
* **Dup(df1)**: de duplicar. Usado para redirecionar *stdin, stdout*.
* **Pipe(&df[0])**: aloca um pedaço de memória, cria dois ponteiros (inicial e final). Para escrever, mexe no ponteiro final. Para leitura, mexe no ponteiro inicial.
* **loctl(fd, request, argp)**