# MAC422 - Aula 3

Aula com o monitor Renato

**Referência:** https://www.github.com/torvals/linux

## Minix

### Processos

Unidade básica de organização do SO.

Organização hierárquica

**htop** => comando que mostra a árvore de processos.

### Arquivos

Informalmente, o sistema de arquivos são as *pastas*.

Pasta **usr** => *Unix System Resources*, **NÃO É USER**.

Sistema simples de permissões => *rwx* = *Read, write, execute*

**Tudo são arquivos** => pastas são arquivos com outros arquivos dentro, por exemplo.

No Unix, não são necessárias extensões, ao contrário do Windows.

Pipes

### Estrutura

Minix => Multi-kernel

Linux => Kernel monolítico

*daemon* => Servidores. Programas que rodam em loop, esperando chamadas.

### As chamadas de sistema do Minix: administração de processos

* fork()
* wait()
* execve(name, argv, envp)
* exit()
* BRK()
* GETPID()