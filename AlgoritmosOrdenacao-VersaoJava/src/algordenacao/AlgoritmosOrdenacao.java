package algordenacao;

import java.util.Scanner;

public class AlgoritmosOrdenacao {

    public static void main(String args[]) {

        int tam = 0, opcao = 0;
        boolean ok = true;
        long t1, t2;
        Scanner scanner = new Scanner(System.in);

        while (tam <= 1) {
            System.out.print("Por favor, insira o tamanho do array: ");
            tam = scanner.nextInt();
        }

        int[] original = new int[tam];
        int[] ordenado = new int[tam];
        int[] temporario = new int[tam];

        // Primeira etapa: criação array + desorganização
        original = desorganizar(criarArray(tam));

        // Segunda etapa: antes de ordenar, copiar o original para o outro vetor
        System.arraycopy(original, 0, ordenado, 0, original.length);

        while (ok) {

            imprimeMenu();
            opcao = scanner.nextInt();
            char cOp = (char) opcao;

            t1 = System.currentTimeMillis();;
            System.arraycopy(original, 0, ordenado, 0, original.length);

            switch (cOp) {
                case 1:
                    System.out.println("Insertion sort");
                    insertionSort(ordenado, tam);
                    break;
                case 2:
                    System.out.println("Shell Sort");
                    shellSort(ordenado, tam);
                    break;
                case 3:
                    System.out.println("Bubble Sort");
                    bubbleSort(ordenado, tam);
                    break;
                case 4:
                    System.out.println("Quick Sort");
                    quickSort(ordenado, 0, (tam - 1));
                    break;
                case 5:
                    System.out.println("Merge Sort");
                    mergeSort(ordenado, ordenado.length);
                    break;
                case 6:
                    System.out.println("Heap Sort");
                    heapSort(ordenado, tam);
                    break;
                case 7:
                    System.out.println("Imprimir array original");
                    imprimirArray(original, tam);
                    break;
                case 8:
                    System.out.println("Imprimir array ordenado");
                    quickSort(ordenado, 0, (tam - 1));
                    imprimirArray(ordenado, tam);
                    break;
                case 9:
                    System.out.println("");
                    ok = false;
                    break;
                default:
                    System.out.println("Opcao invalida!");
                    break;
            }

            int op = opcao - '0';

            if (cOp > 0 && cOp < 7) {
                t2 = System.currentTimeMillis();
                System.out.println("Duracao em microssegundos: " + (t2 - t1));
            }

        }
    }

    // Impressão dos elementos vetor
    public static void imprimirArray(int[] array, int tam) {
        for (int i = 0; i < tam; i++) {
            System.out.print(array[i] + "\t");
        }
        System.out.println("");
    }

    // Primeira etapa - criação do vetor
    public static int[] criarArray(int tam) {

        int array[] = new int[tam];

        for (int i = 0; i < tam; i++) {
            array[i] = i + 1;
        }

        return array;
    }

    // Primeira etapa - desorganização do vetor
    public static int[] desorganizar(int array[]) {

        for (int i = 0; i < array.length; i++) {
            int rand_pos = (int) (Math.random() * ((array.length - 1) + 1));
            int t = array[rand_pos];
            array[rand_pos] = array[i];
            array[i] = t;
        }

        return array;
    }

    static void imprimeMenu() {
        System.out.println("================================================================");
        System.out.println("|     Tempo de execucao de diferentes metodos de ordenacao     |");
        System.out.println("================================================================");
        System.out.println("| Operacoes:                                                   |");
        System.out.println("| 1) Insertion Sort                                            |");
        System.out.println("| 2) Shell Sort                                                |");
        System.out.println("| 3) Bubble Sort                                               |");
        System.out.println("| 4) Quick Sort                                                |");
        System.out.println("| 5) Merge Sort                                                |");
        System.out.println("| 6) Heap Sort                                                 |");
        System.out.println("| 7) Imprimir array original                                   |");
        System.out.println("| 8) Imprimir array ordenado                                   |");
        System.out.println("| 9) Sair                                                      |");
        System.out.println("+--------------------------------------------------------------+");
        System.out.print("Pressione a opcao desejada: ");
    }

    static void insertionSort(int array[], int tam) {

        int i, k, aux;

        for (k = 1; k < tam; k++) {
            aux = array[k];
            for (i = k - 1; i >= 0 && aux < array[i]; i--) {
                array[i + 1] = array[i];
            }
            array[i + 1] = aux;
        }
    }

    static void shellSort(int array[], int tam) {

        int gap, j, k, aux;

        for (gap = tam / 2; gap >= 1; gap = gap / 2) {
            for (j = gap; j < tam; j++) {
                aux = array[j];
                for (k = j - gap; k >= 0 && aux < array[k]; k -= gap) {
                    array[k + gap] = array[k];
                }
                array[k + gap] = aux;
            }
        }

    }

    static void bubbleSort(int v[], int n) {

        int i, j, aux;

        for (j = n - 1; j > 0; j--) {
            for (i = 0; i < j; i++) {
                if (v[i] > v[i + 1]) {
                    aux = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = aux;
                }
            }
        }
    }

    static void quickSort(int x[], int p, int u) {
        int i, j, pivo, aux;
        i = p;
        j = u;
        pivo = x[(i + j) / 2];

        do {
            while (x[i] < pivo && i < u) {
                i++;
            }
            while (x[j] > pivo && j > p) {
                j--;
            }
            if (i <= j) {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
                i++;
                j--;
            }
        } while (i <= j);
        if (p < j) {
            quickSort(x, p, j);
        }
        if (i < u) {
            quickSort(x, i, u);
        }
    }

    public static void merge(int[] a, int[] l, int[] r, int left, int right) {

        int i = 0, j = 0, k = 0;
        while (i < left && j < right) {
            if (l[i] <= r[j]) {
                a[k++] = l[i++];
            } else {
                a[k++] = r[j++];
            }
        }
        while (i < left) {
            a[k++] = l[i++];
        }
        while (j < right) {
            a[k++] = r[j++];
        }
    }

    public static void mergeSort(int[] a, int n) {
        if (n < 2) {
            return;
        }
        int mid = n / 2;
        int[] l = new int[mid];
        int[] r = new int[n - mid];

        for (int i = 0; i < mid; i++) {
            l[i] = a[i];
        }
        for (int i = mid; i < n; i++) {
            r[i - mid] = a[i];
        }
        mergeSort(l, mid);
        mergeSort(r, n - mid);

        merge(a, l, r, mid, n - mid);
    }

    static void heapfica(int[] x, int n) {

        int i, aux, s, f;

        for (i = 1; i < n; i++) {
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

    static void heapSort(int[] x, int n) {
        int i, s, f, ival;
        heapfica(x, n);
        for (i = n - 1; i > 0; i--) {

            // Copiar x[i] - última posição
            ival = x[i];

            // Inserir x[0] (raiz, maior valor) no final
            x[i] = x[0];

            // Ajustar o heap novamente
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
}
