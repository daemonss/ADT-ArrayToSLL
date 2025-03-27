#ifndef CITY_H
#define CITY_H

#include "List.h"

#define MAX_CITIES 5
#define MAX_CITY_NAME 20

// Daftar kota yang valid
static const char* DAFTAR_KOTA[] = {
    "Bandung", "Jakarta", "Surabaya", "Yogyakarta", "Medan"
};

// Struktur data kota (menggunakan LinkedList dari List.h)
typedef struct {
    char kt[MAX_CITY_NAME];  // Nama kota (statis)
    LinkedList listNama;     // List nama penduduk (dinamis)
} Kota;

//Deklarasi fungsi manajemen data kota
void initKota(Kota cities[]); // Inisialisasi array kota
bool kotaValid(const char* namaKota);   // Validasi input kota
void tampilkanDaftarKota(); //Menampilkan pilihan kota yang valid
void tambahOrang(Kota *kota, const char *nama); //Menambah penduduk
void hapusKota(Kota *kota); //Menghapus semua orang di kota
void tampilkanSemua(Kota cities[]); //Menampilkan semua data
void tampilkanKota(Kota *kota);  //Menampilkan data kota tertentu
int cariIndexKota(Kota cities[], const char *namaKota); //Mencari index kota

#endif