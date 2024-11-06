#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nama[50];
    char jenisKlm;
    struct Node* next;
} Mahasiswa;

Mahasiswa* buatmhs(char nama[], char jenisKlm) {
    Mahasiswa* newmhs = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(newmhs->nama, nama);
    newmhs->jenisKlm = jenisKlm;
    newmhs->next = NULL;
    return newmhs;
}

void tambahmhs(Mahasiswa** head, char* nama, char jenisKlm) {
    Mahasiswa* newmhs = buatmhs(nama, jenisKlm);
    
    if (*head == NULL) {
        *head = newmhs;
    } else {
        Mahasiswa* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newmhs;
    }
}

void hapusmhs(Mahasiswa** head, char nama[]) {
    Mahasiswa* temp = *head;
    Mahasiswa* prev = NULL;
    
    while (temp != NULL && strcmp(temp->nama, nama) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Mahasiswa tidak ditemukan\n");
        return;
    }
    
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    
    free(temp);
    printf("Mahasiswa %s berhasil dihapus\n", nama);
}

void pisahLingkaran(Mahasiswa* head) {
    Mahasiswa* lingkaranLaki = NULL;
    Mahasiswa* lingkaranPrm = NULL;
    Mahasiswa* temp = head;
    
    while (temp != NULL) {
        if (temp->jenisKlm == 'L') {
            tambahmhs(&lingkaranLaki, temp->nama, 'L');
        } else {
            tambahmhs(&lingkaranPrm, temp->nama, 'P');
        }
        temp = temp->next;
    }
    
    printf("Lingkaran Laki-laki:\n");
    temp = lingkaranLaki;
    while (temp != NULL) {
        printf("%s\n", temp->nama);
        temp = temp->next;
    }
    
    printf("Lingkaran Perempuan:\n");
    temp = lingkaranPrm;
    while (temp != NULL) {
        printf("%s\n", temp->nama);
        temp = temp->next;
    }
}

void tampilLingkaran(Mahasiswa* head) {
    Mahasiswa* temp = head;
    printf("Lingkaran mahasiswa:\n");
    while (temp != NULL) {
        printf("Nama: %s, Jenis Kelamin: %c\n", temp->nama, temp->jenisKlm);
        temp = temp->next;
    }
}

int main() {
    Mahasiswa* head = NULL;
    int pilihan;
    char nama[50];
    char jenisKlm;
    
    while (1) {
        printf("1. Tambah Mahasiswa\n");
        printf("2. Hapus Mahasiswa\n");
        printf("3. Pisah Mahasiswa Berdasarkan Kelamin\n");
        printf("4. Tampil Lingkaran\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                printf("Masukkan Nama: ");
                scanf("%s", nama);
                printf("Jenis Kelamin L/P: ");
                scanf(" %c", &jenisKlm);
                
                if (strcmp(nama, "cindy") == 0 && jenisKlm == 'L') {
                    printf("Cindy hanya perempuan\n");
                } else {
                    tambahmhs(&head, nama, jenisKlm);
                }
                break;
            
            case 2:
                printf("Nama yang ingin dihapus: ");
                scanf("%s", nama);
                hapusmhs(&head, nama);
                break;
            
            case 3:
                pisahLingkaran(head);
                break;
                
            case 4:
                tampilLingkaran(head);
                break;
            
            case 5:
                return 0;
            
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    }
    return 0;
}

