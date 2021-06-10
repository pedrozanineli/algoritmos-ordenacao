## Algoritmos de Ordenação em Java e em C

Nesse repositório, é possível encontrar <strong>6 diferentes algoritmos de ordenação de dados</strong>, um campo de estudo que se faz de grande importância na Computação. Com isso, o principal objetivo é a disposição dos dados em uma ordem, sendo muito útil para a realização de operações de busca e de indexação de registros.

de forma que, ao iniciar o programa, é pedido ao usuário um inteiro para criação de um vetor que será desorganizado e depois organizado conforme a opção escolhida.

Os algoritmos aqui contidos são:
- Insertion Sort;
- Shell Sort;
- Bubble Sort
- Quick Sort;
- Merge Sort;
- Heap Sort.

Uma importante característica a ser levada em consideração na utilização desses algoritmos é o <storng>tempo de execução</strong>, de forma a ter sido testado conforme mostrado nos códigos abaixo. No primeiro de ambos os exemplos, a variável é definida em um momento anterior à ordenação, sendo o segundo após, e sua diferença sendo o tempo de fato que foi utilizado.

Em Java:

```java
t1 = System.currentTimeMillis();
```

```java
t2 = System.currentTimeMillis();
System.out.println("Duracao em microssegundos: " + (t2 - t1));
```


Em C:

```C
unsigned long long current_timestamp() {
    struct timeval tv;
    unsigned long long tim;
    gettimeofday(&tv, NULL);
    tim = 1000000 * tv.tv_sec + tv.tv_usec;
    return tim;
}
```

```C
printf("Duracao em microssegundos: %lld\n", t2 - t1);
```

