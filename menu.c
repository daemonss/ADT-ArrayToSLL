#include "City.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//menampilkan pilihan menu utama
void tampilkanMenu() {
    printf("\nMenu Program Data Kota:\n");
    printf("1. Tambah Penduduk ke Kota\n");
    printf("2. Hapus Data Kota\n");
    printf("3. Tampilkan Semua Data\n");
    printf("4. Tampilkan Data Kota Tertentu\n");
    printf("5. Keluar\n");
    printf("Pilihan: ");
}

void inputKota(char* prompt, char* buffer) {
    while (1) {
        printf("%s", prompt);
        tampilkanDaftarKota();
        printf("): ");
        fgets(buffer, MAX_CITY_NAME, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // Konversi ke lowercase untuk case insensitive
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        
        // Cek kecocokan dengan daftar kota
        bool valid = false;
        for (int i = 0; i < MAX_CITIES; i++) {
            char kotaLower[MAX_CITY_NAME];
            strcpy(kotaLower, DAFTAR_KOTA[i]);
            for (int j = 0; kotaLower[j]; j++) {
                kotaLower[j] = tolower(kotaLower[j]);
            }
            
            if (strcmp(buffer, kotaLower) == 0) {
                strcpy(buffer, DAFTAR_KOTA[i]);
                valid = true;
                break;
            }
        }
        
        if (valid) break;
        printf("Kota tidak valid! ");
    }
}

//fungsi utama program
void jalankanMenu() {
    Kota cities[MAX_CITIES];
    initKota(cities);
    
    int pilihan;
    char namaKota[MAX_CITY_NAME];
    char namaOrang[MAX_NAME_LENGTH];
    
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar();
        
        switch (pilihan) {
            case 1: //tambah orang
                inputKota("Masukkan nama kota (", namaKota);
                
                printf("Masukkan nama penduduk: ");
                fgets(namaOrang, MAX_NAME_LENGTH, stdin);
                namaOrang[strcspn(namaOrang, "\n")] = '\0';
                
                int index = cariIndexKota(cities, namaKota);
                if (index != -1) {
                    tambahOrang(&cities[index], namaOrang);
                    printf("%s berhasil ditambahkan ke kota %s.\n", namaOrang, namaKota);
                }
                break;
                
            case 2: //hapus kota
                inputKota("Masukkan nama kota yang akan dihapus (", namaKota);
                
                index = cariIndexKota(cities, namaKota);
                if (index != -1) {
                    hapusKota(&cities[index]);
                    printf("Semua penduduk di kota %s telah dihapus.\n", namaKota);
                }
                break;
                
            case 3: //tampilkan semua
                tampilkanSemua(cities);
                break;
                
            case 4: //cari kota
                inputKota("Masukkan nama kota yang akan ditampilkan (", namaKota);
                
                index = cariIndexKota(cities, namaKota);
                if (index != -1) {
                    tampilkanKota(&cities[index]);
                }
                break;
                
            case 5: //keluar
                printf("Program selesai.\n");
                break;
                
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);
}