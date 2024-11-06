#include <stdio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *right;  
    struct node *left;   
};
typedef struct node node;

void tambahAwal(node **head);
void tambahAkhir(node **head);
void tambahData(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void tranverse(node *head);
int totalData(node *head);
int countNodes(node *head);
node* cariData(node *head, int key);
void bersihkanBufferInput();

//========================================================

int main() {
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("masukkan pilihan\n");
        printf("1. tambah data di awal\n");
        printf("2. tambah data di tengah list\n");
        printf("3. tambah data di akhir\n");
        printf("4. hapus data di awal\n");
        printf("5. hapus data di tengah\n");
        printf("6. hapus data di akhir\n");
        printf("7. cari data dalam list\n");
        printf("8. cetak isi list\n");
        printf("9. tampilkan total jumlah data\n");
        printf("10. tampilkan penjumlahan semua data\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        bersihkanBufferInput();
        scanf("%c", &pilih);
        
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4')
            hapusAwal(&head);
        else if (pilih == '5')
            hapusTengah(&head);
        else if (pilih == '6')
            hapusAkhir(&head);
        else if (pilih == '7') {
            int key;
            printf("Masukkan nilai yang ingin dicari: ");
            scanf("%d", &key);
            node *hasil = cariData(head, key);
            if (hasil != NULL)
                printf("Data %d ditemukan!\n", key);
            else
                printf("Data %d tidak ditemukan!\n");
            getchar();
            getchar();
        }
        else if (pilih == '8') {
            tranverse(head);
            getchar();
            getchar();
        }
        else if (pilih == '9') {
            printf("Jumlah node: %d\n", countNodes(head));
            getchar();
            getchar();
        }
        else if (pilih == '10') {
            printf("Total penjumlahan data: %d\n", totalData(head));
            getchar();
            getchar();
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = *head;
        pNew->left = NULL;

        if (*head != NULL) {
            (*head)->left = pNew;
        }

        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
        getchar();
    }
}

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pLast;

    system("cls");
    printf("masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = NULL;

        if (*head == NULL) {
            pNew->left = NULL;
            *head = pNew;
        } else {
            pLast = *head;
            while (pLast->right != NULL) {
                pLast = pLast->right;
            }
            pLast->right = pNew;
            pNew->left = pLast;
        }
    } else {
        printf("Alokasi memori gagal");
        getchar();
    }
}

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai: ");
    scanf("%d", &pos);
    printf("\nbilangan: ");
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->right;
    }

    if (pCur == NULL) {
        printf("\nNode tidak ditemukan");
        getchar();
    } else {
        pNew = (node *)malloc(sizeof(node));
        if (pNew != NULL) {
            pNew->data = bil;
            pNew->right = pCur->right;
            pNew->left = pCur;

            if (pCur->right != NULL) {
                pCur->right->left = pNew;
            }

            pCur->right = pNew;
        } else {
            printf("\nAlokasi memori gagal");
            getchar();
        }
    }
}

//========================================================

void hapusAwal(node **head) {
    node *pDel;

    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    pDel = *head;
    *head = (*head)->right;

    if (*head != NULL) {
        (*head)->left = NULL;
    }

    free(pDel);
    printf("Data awal berhasil dihapus.\n");
}

void hapusTengah(node **head) {
    int key;
    node *pCur, *pDel;

    system("cls");
    tranverse(*head);
    printf("\nData yang ingin dihapus: ");
    scanf("%d", &key);

    pCur = *head;
    while (pCur != NULL && pCur->data != key) {
        pCur = pCur->right;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan.\n");
    } else {
        pDel = pCur;
        if (pCur->left != NULL) {
            pCur->left->right = pCur->right;
        }
        if (pCur->right != NULL) {
            pCur->right->left = pCur->left;
        }
        if (pCur == *head) {
            *head = pCur->right;
        }
        free(pDel);
        printf("Data berhasil dihapus.\n");
    }
    getchar();
}

void hapusAkhir(node **head) {
    node *pCur;

    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    pCur = *head;
    while (pCur->right != NULL) {
        pCur = pCur->right;
    }

    if (pCur->left != NULL) {
        pCur->left->right = NULL;
    } else {
        *head = NULL;
    }

    free(pCur);
    printf("Data akhir berhasil dihapus.\n");
}

//========================================================

void tranverse(node *head) {
    node *pWalker = head;
    system("cls");

    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }

    while (pWalker != NULL) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->right;
    }
    printf("NULL\n");
}

//========================================================

int totalData(node *head) {
    int sum = 0;
    node *pCur = head;
    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->right;
    }
    return sum;
}

int countNodes(node *head) {
    int count = 0;
    node *pWalker = head;

    while (pWalker != NULL) {
        count++;
        pWalker = pWalker->right;
    }

    return count;
}

node* cariData(node *head, int key) {
    node *pWalker = head;

    while (pWalker != NULL) {
        if (pWalker->data == key)
            return pWalker;
        pWalker = pWalker->right;
    }

    return NULL;
}

//========================================================

void bersihkanBufferInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
