#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <conio.h>
#define CLEAR "CLS"

unsigned long long current_timestamp() {
    struct timeval tv;
    unsigned long long tim;
    gettimeofday(&tv, NULL);
    tim = 1000000 * tv.tv_sec + tv.tv_usec;
    return tim;
}

void imprimirArray(int *array, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
}

int *criarArray(int tam) {
    int *array = (int *) malloc(sizeof(int) * tam);

    for (int i = 0; i < tam; i++) {
        array[i] = i + 1;
    }
    return array;
}

int *desorganizar(int array[], int tam) {
    time_t tim;
    srand((unsigned) time(&tim));

    for (int i = 0; i < tam; i++) {
        int rand_pos = (int)(((double)rand()/RAND_MAX) * tam);
        int t = array[rand_pos];
        array[rand_pos] = array[i];
        array[i] = t;
    }
    return array;
}

void imprimeMenu() {
    printf("================================================================\n");
    printf("|     Tempo de execucao de diferentes metodos de ordenacao     |\n");
    printf("================================================================\n");
    printf("| Operacoes:                                                   |\n");
    printf("| 1) Insertion Sort                                            |\n");
    printf("| 2) Shell Sort                                                |\n");
    printf("| 3) Bubble Sort                                               |\n");
    printf("| 4) Quick Sort                                                |\n");
    printf("| 5) Merge Sort                                                |\n");
    printf("| 6) Heap Sort                                                 |\n");
    printf("| 7) Imprimir array original                                   |\n");
    printf("| 8) Imprimir array ordenado                                   |\n");
    printf("| 9) Sair                                                      |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("Pressione a opcao desejada: ");
}

void insertionSort(int array[], int tam) {

    int i, k, aux;

    for (k = 1; k < tam; k++) {
        aux = array[k];
        for (i = k - 1; i >= 0 && aux < array[i]; i--) {
            array[i + 1] = array[i];
        }
        array[i + 1] = aux;
    }

}

void shellSort(int *array, int tam) {
    unsigned long long t1, t2;
    t1 = current_timestamp();

    int gap, j, k, aux;
    for(gap = tam / 2; gap >= 1; gap = gap / 2) {
        for(j = gap; j < tam; j++) {
            aux = array[j];
            for(k = j - gap; k >= 0 && aux < array[k]; k-=gap) {
                array[k + gap] = array[k];
            }
            array[k + gap] = aux;
        }
    }

}

void bubbleSort(int v[], int n){

    int i, j, aux;

    for(j = n - 1; j > 0; j--) {
        for(i = 0; i < j; i++) {
            if(v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
    }
}

void quickSort(int x[], int p, int u){
    int i, j, pivo, aux;
    i = p;
    j = u;
    pivo = x[(i + j)/2];

    do{
    while(x[i] < pivo && i < u) i++;
    while(x[j] > pivo && j > p) j--;
        if(i <= j){
            aux = x[i];
            x[i] = x[j];
            x[j] = aux;
            i++;
            j--;
        }
    } while(i <= j);
    if(p < j) quickSort(x, p, j);
    if(i < u) quickSort(x, i, u);
}

void merge(int *x, int *temp, int esq, int meio, int dir) {
    int i, esq_fim, tam, tmp_pos;
    esq_fim = meio - 1;
    tmp_pos = esq;
    tam = dir - esq + 1;
    while ((esq <= esq_fim) && (meio <= dir)) {
        if (x[esq] <= x[meio]) {
            temp[tmp_pos] = x[esq];
            tmp_pos++;
            esq++;
        }
        else {
            temp[tmp_pos] = x[meio];
            tmp_pos++;
            meio++;
        }
    }
    if (esq <= esq_fim) {
        memcpy(&temp[tmp_pos], &x[esq], (esq_fim - esq + 1)*sizeof(int));
    }
    if (meio <= dir) {
        memcpy(&temp[tmp_pos], &x[meio], (dir - meio + 1)*sizeof(int));
    }

    memcpy(&x[dir - tam + 1], &temp[dir - tam + 1], tam*sizeof(int));
}

void mergesort(int *x, int *temp, int esq, int dir) {
    int meio;
    if (dir > esq) {
        meio = (dir + esq) / 2;
        mergesort(x, temp, esq, meio);
        mergesort(x, temp, meio+1, dir);
        merge(x, temp, esq, meio+1, dir);
    }
}

void heapfica(int *x, int n) {
    int i, aux, s, f;
	for (int i = 1; i < n; i++) {
		aux = x[i];
		s = i;
		f = (s - 1) / 2;
		while (s > 0 && x[f] < aux) {
			x[s] = x[f];
			s = f;
			f = (s - 1) / 2;
		}
		x[s] = aux;
	}
}

void heapSort(int *x, int n) {
	int i, s, f, ival;
    heapfica(x, n);
	for(i = n - 1; i > 0; i--) {

		ival = x[i];

		x[i] = x[0];

		f = 0;

		if (i == 1) {
			s = -1;
		} else {
			s = 1;
		}
		if (i > 2 && x[2] > x[1]) {
			s = 2;
		}
		while (s >= 0 && ival < x[s]) {
			x[f] = x[s];
			f = s;
			s = 2 * f + 1;
			if (s + 1 <= i - 1 && x[s] < x[s + 1]) {
				s = s + 1;
			}
			if (s > i - 1) {
				s = -1;
			}
		}
		x[f] = ival;
	}
}

int main() {
    int *original, *ordenado, tam, *temporario;

    tam = 0;
    while(tam <= 1){
        char palavra[20];
        printf("Por favor, insira o tamanho do array: ");
        gets(palavra);
        tam = atoi(palavra);
    }

    // Primeira etapa: criação array + desorganização
    original = desorganizar(criarArray(tam), tam);

    // Segunda etapa: criando espaço para o outro vetor
    ordenado = (int *) malloc(sizeof(int) * tam);

    // Terceira etapa: antes de ordenar, copiar o original para o outro vetor
    memcpy(ordenado, original, sizeof(int) * tam);

    char opcao = '0';
    int ok = 1;

    unsigned long long t1, t2;

    while(ok){
        system(CLEAR);
        imprimeMenu();
        opcao = getch();

        t1=current_timestamp();
        memcpy(ordenado, original, sizeof(int) * tam);

        switch(opcao) {
            case '1':   printf("Insertion sort\n\n");
                        insertionSort(ordenado,tam);
						break;
            case '2': 	printf("Shell Sort\n\n");
                        shellSort(ordenado,tam);
						break;
            case '3': 	printf("Bubble Sort\n\n");
                        bubbleSort(ordenado,tam);
						break;
            case '4': 	printf("Quick Sort\n\n");
                        quickSort(ordenado,0,(tam-1));
						break;
            case '5': 	printf("Merge Sort\n\n");
                        temporario = (int *) malloc(sizeof(int) * tam);
                        mergesort(ordenado, temporario, 0, (tam-1));
						break;
            case '6': 	printf("Heap Sort\n\n");
                        heapSort(ordenado, tam);
						break;
            case '7': 	printf("Imprimir array original\n\n");
                        imprimirArray(original, tam);
						getchar();
						break;
			case '8':   printf("Imprimir array ordenado\n\n");
                        quickSort(ordenado,0,(tam-1));
                        imprimirArray(ordenado, tam);
						getchar();
						break;
            case '9': 	printf("\n");
                        ok = 0;
						break;
            default: 	printf("\n\nOpcao invalida!");
						getchar();
						break;
        }

        int op = opcao - '0';

        if(op > 0 && op < 7){
            t2=current_timestamp();
            printf("Duracao em microssegundos: %lld\n", t2 - t1);
            getchar();
        }

    }
    return 0;
}
