# MAC422 - Aula 2

## Processos

5 estados:

* Bloqueado => esperando algo acontecer (normalmente I/O ou algum timer acabar);

* Pronto => esperando S.O. chamar o processo para fazer poder rodar.

* Suspended => hardware interrompe um processo que está esperando ou rodando.

## Multiprogramação

* Os computadores eram muito caros. Logo, as empresas buscavam maximizar o uso destes. Como a maioria dos programas depende de I/O, ou seja, deve esperar entrada e saída para fazer algo, vários programas eram carregados de uma vez. Quando um era entrava no estado BLOQUEADO, outro programa era EXECUTADO.

* Pseudo paralelismo => Multiprocessamento => Rodava vários programas juntos pois era comum que um programa dependesse de algo de I/O (ficava bloqueado).  **Não é um paralelismo real**. Só se parece pois o processamento era tão rápido que parecia paralelo.

* Processo => Fechado, isolado dos outros em relação à memória.

* Thread => Compartilha recursos.

* Tabela de Processos => forma de gerenciar os diferentes processos rodando.

* Não se pode assumir nada em relação à execução em tempo real **pois há possíveis pausas e bloqueios entre instruções**.

## Processos Minix

* Processos se **comunicam** (o que pode não acontecer em outros S.O.) através de **mensagens, arquivos, pipes ou sinais (signals)**.

* O *signal* parece com uma interrupção (sinal mandado pelo hardware).

* Para **criar novos processos**, o *Minix* cria um **fork** de algum processo, ou seja, cria uma cópia ou um processo *filho*. O **Uid** (id do processo) se mantém para o pai e é **zero** para o filho.

## Arquivos Minix

* Minix inovou tendo um **único** *root*;
* Proteção (pegar com alguém...)
* ...
* Major device number (tipo) + minor device number => HD, SATA + número identificador(?)
* Pipe => trecho de memória no qual dados são inseridos (write) e depois retirados (read).

## Estrutura do Minix

* Várias camadas:
* 1ª - Kernel => mexe diretamente com processos;
* 2ª - Drivers => especifica como o hardware se comunica com as outras camadas. Baixo nível, mas roda como um processo;
* 3ª - Sistema de arquivos, 