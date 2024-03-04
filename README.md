# Benchmark de algorítmos em C para Linux

## O que faz:

Testa o tempo de execução do algorítmo no arquivo teste.c

## Como usar:

- copie o seu codigo para dentro do arquivo teste.c
	(Substitua todo o conteúdo de teste.c para evitar erros).

- compile o programa com o comando `make`
	(necessário ter o GCC instalado)

- execute o programa com o comando `$./build/benchmark`
Será criado um arquivo de texto chamado logs.txt com os dados do benchmark.

## Observações:

- É possível utilizar de alguns parâmetros para alterar opções do programa:

- `-f <nome_do_arquivo>`: Para definir o nome do arquivo a ser gerado.

- `-r <numero>`: Para mudar o número de vezes que o teste é executado.
	(melhora a precisão do cálculo de pontos, porém demora mais para obter o resultado).
- Exemplo de uso: `$benchmark -r 3 -f benchmark.txt`
- A coluna Pontos exibe um valor de referência somente para comparação entre computadores diferentes.