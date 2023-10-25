// Enrico Najjar Galdeano - 32260407
// Rodrigo Mironiuc Fernandes - 32274823
// Mauricio Gabriel Gutierrez Garcia - 32266601

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define m 5 // número total de linhas na matriz
#define n 5 // número total de colunas na matriz
#define thread_count 5 // número total de threads

double A[m][n] = {{1, 2, 3,4,5}, {6,7, 8, 8, 10}, {11,12, 13, 14,15},{16,17,18,19,20},{21,22,23,24,25}}; //$
double x[n] = {1, 2, 3,4,5}; // vetor x
double y[m]; // vetor y

void Pth_mat_vect(void rank) {
    long my_rank = (long) rank;
    int i, j;
    int local_m = m/thread_count;
    int my_first_row = my_ranklocal_m;
    int my_last_row = (my_rank+1)local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0;
        for (j = 0; j < n; j++)
            y[i] += A[i][j]x[j];
    }

    return NULL;
}

int main() {
    pthread_t thread_handles;

    thread_handles = malloc(thread_countsizeof(pthread_t));

    for (long thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void) thread);

    for (long thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);

    free(thread_handles);

    printf("Resultado da multiplicação da matriz pelo vetor:\n");
    for(int i=0; i<m; i++) 
        printf("%f\n", y[i]);

    return 0;
}