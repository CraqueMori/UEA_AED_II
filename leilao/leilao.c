#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int priority;
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int size;
} PriorityQueue;

PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

void slice(const char* str, char* result, size_t start, size_t end){
    strncpy(result, str + start, end - start);
}

void oferta(PriorityQueue* pq, char* name, int priority) {
    Element element;
    strcpy(element.name, name);
    element.priority = priority;

    int i = pq->size;
    pq->heap[i] = element;

    while (i > 0 && pq->heap[(i - 1) / 2].priority < pq->heap[i].priority) {
        // Swap parent and child if child has higher priority
        Element temp = pq->heap[i];
        pq->heap[i] = pq->heap[(i - 1) / 2];
        pq->heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2; // Move up to the parent index
    }

    pq->size++;
}

Element dequeue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Sem ofertas. impossível concretizar venda.\n");
        Element empty;
        empty.priority = -1;
        return empty;
    }

    Element root = pq->heap[0];
    pq->size--;

    pq->heap[0] = pq->heap[pq->size];

    int i = 0;
    while (1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild >= pq->size)
            break; // No children

        int maxChild = leftChild;
        if (rightChild < pq->size && pq->heap[rightChild].priority > pq->heap[leftChild].priority)
            maxChild = rightChild;

        if (pq->heap[i].priority >= pq->heap[maxChild].priority)
            break; // Parent has higher priority

        // Swap parent and child if child has higher priority
        Element temp = pq->heap[i];
        pq->heap[i] = pq->heap[maxChild];
        pq->heap[maxChild] = temp;

        i = maxChild; // Move down to the child index
    }

    return root;
}

void venda(PriorityQueue* pq) {
    Element ofertor = dequeue(pq);
    printf("Vendido para %s por %d.\n\n", ofertor.name, ofertor.priority);

}

int main() {
    PriorityQueue* pq = createPriorityQueue();

    int n = 0;
    printf("Insira numero de eventos: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char event[20];
        char name[50];
        int priority;
        char instruction[10];

        printf("Enter event #%d: ", i + 1);
        scanf("%s", event);

        if (strcmp(event, "SAIR") == 0){
            printf("Adeus.\n");
            return 0;
        }
        
        if (strcmp(event, "VENDA") == 0) {
            venda(pq);
        } 

        else if (strcmp(event, "COMPRA") == 0) {
            char name[50];
            printf("Digite o nome do ofertor: \n");
            scanf("%s", name);

            int price;
            printf("Digite o valor da oferta: \n");
            scanf("%d", &price);

            oferta(pq, name, price);
        } 

        else {
            printf("Invalid event. Skipping.\n");
            i--;
        }
    }
}
