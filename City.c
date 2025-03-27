#include "City.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Inisialisasi array kota (alokasi statis)
void initKota(Kota cities[]) {
    for (int i = 0; i < MAX_CITIES; i++) {
        strcpy(cities[i].kt, DAFTAR_KOTA[i]); //nama kota
        createList(&cities[i].listNama); //
    }
}

// Validasi input kota (hanya menerima 5 kota yang ditentukan)
bool kotaValid(const char* namaKota) {
    for (int i = 0; i < MAX_CITIES; i++) {
        if (strcmp(namaKota, DAFTAR_KOTA[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Menampilkan daftar kota
void tampilkanDaftarKota() {
    printf("Daftar kota: ");
    for (int i = 0; i < MAX_CITIES; i++) {
        printf("%s", DAFTAR_KOTA[i]);
        if (i < MAX_CITIES - 1) printf(", ");
    }
}

// Menambahkan orang ke kota (menggunakan insertLast dari List.c)
void tambahOrang(Kota *kota, const char *nama) {
    insertLast(&kota->listNama, nama);
}

// Menghapus semua orang di kota (menggunakan deleteAll dari List.c)
void hapusKota(Kota *kota) {
    deleteAll(&kota->listNama);
}

//menampilkan semua orang di kota-kota yang berbeda
void tampilkanSemua(Kota cities[]) {
    printf("\nDaftar Kota dan Penduduk:\n");
    for (int i = 0; i < MAX_CITIES; i++) {
        printf("%s: ", cities[i].kt);
        printList(cities[i].listNama);
    }
}

//menampilkan kota tertentu dengan orangnya
void tampilkanKota(Kota *kota) {
    printf("%s: ", kota->kt);
    printList(kota->listNama);
}

int cariIndexKota(Kota cities[], const char *namaKota) {
    for (int i = 0; i < MAX_CITIES; i++) {
        if (strcmp(cities[i].kt, namaKota) == 0) {
            return i;
        }
    }
    return -1;
}