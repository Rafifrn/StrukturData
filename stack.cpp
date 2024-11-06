#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack penuh, tidak dapat menambahkan data.\n");
    } else {
        stack->top++;
        stack->data[stack->top] = value;
        printf("Data %d ditambahkan ke stack.\n", value);
    }
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack kosong, tidak dapat melakukan operasi pop.\n");
        return -1;
    } else {
        int value = stack->data[stack->top];
        stack->top--;
        return value;
    }
}

int stackTop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack kosong.\n");
        return -1;
    } else {
        return stack->data[stack->top];
    }
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int stackCount(Stack *stack) {
    return stack->top + 1;
}

void destroyStack(Stack *stack) {
    stack->top = -1;
    printf("Stack telah dikosongkan.\n");
}

int main() {
    Stack stack;
    initializeStack(&stack);
    int pilihan, value;

    do {
        printf("\nMenu Operasi Stack:\n");
        printf("1. Push (Tambah data ke stack)\n");
        printf("2. Pop (Hapus data dari stack)\n");
        printf("3. Lihat elemen teratas\n");
        printf("4. Hitung jumlah elemen dalam stack\n");
        printf("5. Hancurkan stack\n");
        printf("6. Keluar\n");
        printf("Pilih operasi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan data yang akan ditambahkan: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Data %d dihapus dari stack\n", value);
                }
                break;
            case 3:
                value = stackTop(&stack);
                if (value != -1) {
                    printf("Elemen teratas adalah: %d\n", value);
                }
                break;
            case 4:
                printf("Jumlah elemen dalam stack: %d\n", stackCount(&stack));
                break;
            case 5:
                destroyStack(&stack);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 6);

    return 0;
}

