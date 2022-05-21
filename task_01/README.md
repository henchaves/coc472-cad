### Instruções de execução

Para compilar ambos os programas, com o console aberto no caminho desse diretório, basta executar `make all`.

1) Definir as variáveis a serem usadas
```
$ export NROWS = 1000
$ export OPT = 1
```
Sendo NROWS o número de linhas que terá na matriz quadrada e nos vetores, e OPT significando qual o percurso de iteração (`OPT = 0` para percorrer linha a linha e  `OPT = 1` para percorrer coluna a coluna).

2) Para executar o programa em C:
```
$ ./main_c $NROWS $OPT
```

3) Para executar o programa em Fortran:
```
$ ./main_f $NROWS $OPT
```
