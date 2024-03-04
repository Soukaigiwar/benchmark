/*
 * Nome do Arquivo: benchmark.c
 * Autor: SoukaigWar (Sergio Mello)
 * Data: 04/03/2024
 * Descrição: Testa o tempo de execução do algorítmo no arquivo teste.c
 */

#include <stdio.h>
#include <time.h>
#include "benchmark.h"

void parametersList();
int errorHandle(int argc, char *argv[]);

char *filename = "./logs.txt";
int RUNS = 1;

void functionToExecute(int i, int runs) {
    if(i < runs) {
        teste();
        functionToExecute(i + 1, runs);
    }
}

double getTime(int runs) {
    clock_t start;
    clock_t end;
    double cpuTimeUsed;

    start = clock();

    functionToExecute(0, runs);

    end = clock();
    cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    return cpuTimeUsed;
}

double writeTimeToFile(int runs, FILE *file) {
    int i;
    const int ROUNDS = 5000;
    double times[ROUNDS];
    double media = 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    for(i = 0; i < ROUNDS; i++){
        times[i] = getTime(runs);
    }


    for(i = 0; i < 100; i++){
        media += times[i];
    }

    media = media / runs;

    fprintf(file, "%04d/%02d/%02d %02d:%02d:%02d | %f ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, (media));

    return media; 
}

int main(int argc, char *argv[]) {
    clock_t startTotal, endTotal;
    double cpuTimeUsedTotal;

    startTotal = clock();

    int errorNumber = errorHandle(argc, argv);

    if (errorNumber > 0) return errorNumber;

    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo, ou inexistente.\n");
        return 31;
    }

    fseek(file, 0, SEEK_END);

    long fileSize = ftell(file);

    if (fileSize == 0) {
        fprintf(file, "Data                | Média    | Total    | Pontos\n");
    }

    double pontos;
    int benchmarkPoints;

    pontos = writeTimeToFile(RUNS, file);
    benchmarkPoints = (int)(60 / pontos);

    endTotal = clock();
    cpuTimeUsedTotal = ((double) (endTotal - startTotal)) / CLOCKS_PER_SEC;

    fprintf(file, "| %f | %d\n", cpuTimeUsedTotal, benchmarkPoints);

    fclose(file);

    return 0;
}

int errorHandle(int argc, char *argv[]){
    if (argc % 2 == 0) {
        parametersList();

        return 20;
    }

    if (argc > 2){
        int countR = 0;
        int countF = 0;

        for (int i = 1; i < argc; i += 2){
            // parametro -f repetido
            if ((strcmp(argv[i], "-f") == 0) && countF > 0) {
                parametersList();

                return 21;
            }

            // parametro -r repetido
            if ((strcmp(argv[i], "-r") == 0) && countR > 0) {
                parametersList();

                return 22;
            }

            if ((strcmp(argv[i], "-r") == 0) && argv[i+1] && countR == 0) {
                RUNS = atoi(argv[i+1]);
                countR++;
            } 
            
            if ((strcmp(argv[i], "-f") == 0) && argv[i+1] && countF == 0) {
                filename = argv[i+1];
                countF++;
            }
        }
    }

    return 0;
}

void parametersList(){
    printf("Uso de parâmetros inválido ou incompleto.\n\n");
    printf("Formato: benchmark <parametro> <valor> ... <parametro> <valor>\n");
    printf("Exemplo: benchmark -f log.txt\n\n");
    printf("Parâmetros e valores válidos:\n");
    printf("-f <nome_do_arquivo> - Nome do arquivo a ser criado\n");
    printf("-r <número_de_rounds> - Número de vezes que o algorítmo é executado\n\n");
    printf("Para mais informações veja em: github.com/Soukaigiwar\n\n");
}
