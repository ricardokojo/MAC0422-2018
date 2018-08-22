# MAC422 - Aula 5 21/08

## Tabelas de processos do Minix

## Processos

### Como funciona o esquema de interrupção

Hardware => o dispositivo emite um sinal para o barramento. Esse sinal eletrônico chega na CPU, que empilha esse sinal junto com outras informações

Software => armazena conteúdos dos registradores na tabela de processos, salva informações do processo atual. Rotina em C cuida da interrupção.

Rotina em C => cria uma mensagem baseada no tipo de interrupção; manda para o respectivo driver.

**Apenas o kernel roda sem interrupção**.

## Exclusão Mútua

