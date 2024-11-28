#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void createQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Antrian penuh! Tidak dapat menambah elemen.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = value;
        printf("Elemen %d ditambahkan ke antrian.\n", value);
    }
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Antrian kosong! Tidak ada elemen untuk dihapus.\n");
    } else {
        printf("Elemen %d dihapus dari antrian.\n", q->data[q->front]);
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

void queueFront(Queue *q) {
    if (isEmpty(q)) {
        printf("Antrian kosong! Tidak ada elemen di depan.\n");
    } else {
        printf("Elemen di depan antrian: %d\n", q->data[q->front]);
    }
}

void queueRear(Queue *q) {
    if (isEmpty(q)) {
        printf("Antrian kosong! Tidak ada elemen di belakang.\n");
    } else {
        printf("Elemen di belakang antrian: %d\n", q->data[q->rear]);
    }
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Antrian kosong!\n");
    } else {
        printf("Isi antrian: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    createQueue(&q);

    int choice, value;
    do {
        printf("\nMenu Queue:\n");
        printf("1. Enqueue (Tambah Elemen)\n");
        printf("2. Dequeue (Hapus Elemen)\n");
        printf("3. Tampilkan Antrian\n");
        printf("4. Queue Front (Elemen Depan)\n");
        printf("5. Queue Rear (Elemen Belakang)\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan elemen yang ingin ditambahkan: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                queueFront(&q);
                break;
            case 5:
                queueRear(&q);
                break;
            case 6:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (choice != 6);

    return 0;
}

