Program Manajemen Kota dan Warga (Array & Linked List)

Program ini dibuat untuk memenuhi tugas praktikum **Struktur Data dan Algoritma** dengan fokus pada penerapan **array statis** dan **linked list dinamis** secara bersamaan dalam satu sistem terintegrasi.

Tujuan Program

Membuat sebuah program berbasis C yang dapat mengelola:
- Data beberapa kota yang disimpan dalam array statis.
- Data nama-nama warga pada masing-masing kota yang disimpan dalam Single Linked List (SLL) secara dinamis.

Setiap kota memiliki list warga sendiri yang bisa dimanipulasi secara independen.

---

Cara Kerja Program

1. Data Kota disimpan secara statis menggunakan array pada saat inisialisasi.
2. Setiap elemen kota memiliki pointer ke linked list berisi data warga.
3. Menu interaktif disediakan untuk:
   - Menambahkan nama warga ke kota tertentu.
   - Menghapus nama warga dari kota tertentu.
   - Menampilkan semua kota beserta daftar nama warganya.
   - Menghapus seluruh warga dari kota tertentu.
4. Jika kota dihapus (meski secara teknis array-nya tetap ada), maka seluruh linked list warga pada kota tersebut akan dihapus (free memory).

---

Struktur File dan Fungsinya

Berikut penjelasan dari ke-7 file program:

1. main.c
- Titik masuk program int main().
- Memanggil jalankanMenu() dari menu.c untuk menjalankan antarmuka pengguna.

2. menu.h & menu.c
- Menyediakan fungsi-fungsi untuk menampilkan dan mengelola menu utama.
- Mengatur interaksi pengguna untuk memanggil fitur: tambah warga, hapus warga, tampilkan data, hapus semua warga kota.
- Berelasi langsung dengan city.h dan list.h.

3. city.h & city.c
- Mengatur data array kota (maksimum jumlah kota tetap).
- Setiap elemen menyimpan nama kota dan pointer ke linked list warga.
- Fungsi seperti tambahOrang() dan hapusKota() dan fungsi lain-lainya berada di sini.

4. list.h & list.c
- ADT (Abstract Data Type) Single Linked List.
- Digunakan untuk menyimpan, menambah, dan menghapus nama warga.
- Bebas digunakan oleh setiap kota karena bersifat reusable dan modular.

---

Lesson Learned

Selama proses pembuatan program ini, saya mempelajari:

- Cara menggabungkan struktur data **array (statis)** dan **linked list (dinamis)** secara terintegrasi.
- Perancangan ADT Linked List agar dapat digunakan kembali oleh banyak konteks (multi-instance).
- Manajemen memori dinamis menggunakan malloc() dan free() untuk linked list.
- Pentingnya struktur header yang **tidak circular** agar program dapat di-*compile* tanpa error.
- Pemisahan file berdasarkan tanggung jawab (modularisasi program) memudahkan debugging dan pengembangan.

---

Catatan

- Program ini **tidak memungkinkan penambahan kota baru**, karena data kota bersifat statis (jumlah dan nama kota ditentukan di awal dan tidak dapat diubah saat runtime).
- Yang bersifat dinamis hanyalah data nama warga di dalam masing-masing kota.



