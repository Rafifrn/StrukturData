#include <stdio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
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
                printf("Data %d tidak ditemukan!\n", key);
            getchar();
        }
        else if (pilih == '8') {
            tranverse(head);
            getchar();
        }
        else if (pilih == '9') {
            printf("Jumlah node: %d\n", countNodes(head));
            getchar();
        }
        else if (pilih == '10') {
            printf("Total penjumlahan data: %d\n", totalData(head));
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
        pNew->next = *head;
        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
        getchar();
    }
}

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
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
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL) {
        printf("\nnode tidak ditemukan");
        getchar();
    } else if (pNew == NULL) {
        printf("\nalokasi memori gagal");
        getchar();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

//========================================================

void hapusAwal(node **head) {
    node *pDel;
    if (*head != NULL) {
        pDel = *head;
        *head = (*head)->next;
        free(pDel);
        printf("Data awal berhasil dihapus.\n");
    } else {
        printf("List kosong.\n");
    }
    getchar();
}

void hapusTengah(node **head) {
    int key;
    node *pCur, *pDel;

    system("cls");
    tranverse(*head);
    printf("\nData yang ingin dihapus: ");
    scanf("%d", &key);

    pCur = *head;
    if (pCur == NULL) {
        printf("List kosong.\n");
    } else if (pCur->data == key) {
        hapusAwal(head);
    } else {
        while (pCur->next != NULL && pCur->next->data != key) {
            pCur = pCur->next;
        }
        if (pCur->next == NULL) {
            printf("Data tidak ditemukan.\n");
        } else {
            pDel = pCur->next;
            pCur->next = pCur->next->next;
            free(pDel);
            printf("Data berhasil dihapus.\n");
        }
    }
    getchar();
}

void hapusAkhir(node **head) {
    node *pCur, *pDel;

    if (*head == NULL) {
        printf("List kosong.\n");
    } else if ((*head)->next == NULL) {
        pDel = *head;
        *head = NULL;
        free(pDel);
        printf("Data akhir berhasil dihapus.\n");
    } else {
        pCur = *head;
        while (pCur->next->next != NULL) {
            pCur = pCur->next;
        }
        pDel = pCur->next;
        pCur->next = NULL;
        free(pDel);
        printf("Data akhir berhasil dihapus.\n");
    }
    getchar();
}

//========================================================

void tranverse(node *head) {
    node *pWalker = head;
    system("cls");
    while (pWalker != NULL) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("NULL\n");
}

//========================================================

int totalData(node *head) {
    int total = 0;
    node *pWalker = head;

    while (pWalker != NULL) {
        total += pWalker->data;
        pWalker = pWalker->next;
    }

    return total;
}

int countNodes(node *head) {
    int count = 0;
    node *pWalker = head;

    while (pWalker != NULL) {
        count++;
        pWalker = pWalker->next;
    }

    return count;
}

node* cariData(node *head, int key) {
    node *pWalker = head;

    while (pWalker != NULL) {
        if (pWalker->data == key)
            return pWalker;
        pWalker = pWalker->next;
    }

    return NULL;
}

//========================================================

void bersihkanBufferInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

