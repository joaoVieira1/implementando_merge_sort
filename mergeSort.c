#include <stdio.h>

void merge(int array[], int esquerda, int meio, int direita);
void mergeSort(int array[], int esquerda, int direita);

int main(){

    int vetor[6] = {4, 2, 1, 5, 6, 3};

    mergeSort(vetor, 0, 6);

    for(int i = 0; i < 6; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}

void mergeSort(int array[], int esquerda, int direita){

    if(esquerda < direita){
        int meio = esquerda + (direita - esquerda) / 2;

        //recursão
        mergeSort(array, esquerda, meio);
        mergeSort(array, (meio+1), direita);

        //intercalação
        merge(array, esquerda, meio, direita);
    }

}

void merge(int array[], int esquerda, int meio, int direita){
    
    //medindo o tamanho dos subvetores esquerda e direita 
    int tamanhoVetorEsquerda = meio - esquerda + 1;
    int tamanhoVetorDireita = direita - meio;

    //criando subvetores
    int vetorDireita[tamanhoVetorDireita];
    int vetorEsquerda[tamanhoVetorEsquerda];

    //alocando valores do array principal pros subvetores
    for(int i = 0; i < tamanhoVetorEsquerda; i++){
        vetorEsquerda[i] = array[esquerda + i];
    }

    for(int i = 0; i < tamanhoVetorDireita; i++){
        vetorDireita[i] = array[meio + 1 + i];
    }

    //mesclagem (coração do algoritmo)
    int a = esquerda, e = 0, d = 0;

    while(e <= (tamanhoVetorEsquerda-1) && d <= (tamanhoVetorDireita-1)){
        if(vetorEsquerda[e] < vetorDireita[d]){
            array[a] = vetorEsquerda[e];
            a++;
            e++;
        }else{
            array[a] = vetorDireita[d];
            a++;
            d++;
        }
    }

    while(e <= (tamanhoVetorEsquerda-1)){
        array[a] = vetorEsquerda[e];
        a++;
        e++;
    }

    while(d <= (tamanhoVetorDireita-1)){
        array[a] = vetorDireita[d];
        a++;
        d++;
    }

}