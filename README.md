# Tugas kecil 1 Strategi Algoritma

## Daftar Isi

- [Tugas kecil 1 Strategi Algoritma](#tugas-kecil-1-strategi-algoritma)
  - [Daftar Isi](#daftar-isi)
  - [24 Card Game Solver](#24-card-game-solver)
  - [Deskripsi Permasalahan](#deskripsi-permasalahan)
  - [Algoritma yang digunakan](#algoritma-yang-digunakan)
  - [Struktur Program](#struktur-program)
  - [Menjalankan Program](#menjalankan-program)
  - [Libraries Used](#libraries-used)

## 24 Card Game Solver

Made by Kenneth Ezekiel, 13521089, for the completion of Algorithm & Design Course 


## Deskripsi Permasalahan

Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan hasil akhir sejumlah 24. 

Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas.

Projek ini adalah membuat suatu algoritma dengan pendekatan *brute force* untuk menyelesaikan permainan kartu 24.

## Algoritma yang digunakan

Pencarian solusi permainan kartu 24 dilakukan dengan pendekatan *brute force*, secara intuisi, algoritma yang dijalankan adalah sebagai berikut:


* misalkan a b c d sebagai 4 kartu/angka yang dipilih
* lakukan permutasi dari 4 kartu jika dipilih 2 kartu, sehingga didapatkan 3 angka (mis: (a .. b), sudah menjadi 1 angka), lalu operasikan (4 operasi)
* untuk semua permutasi * operasi tersebut, lakukan permutasi kembali dari 3 angka jika dipilih 2 angka, lalu operasikan (4 operasi) kembali (mis: ((a .. b) .. c) atau (c .. d))
* sisa 2 angka yang terakhir akan menentukan hasil akhir adalah 24 atau tidak jika dioperasikan (4 operasi)


## Struktur Program

```
│ .gitignore
│ README.md
│ run.bat
├─── bin
│       │ readme.txt
│       │ main.exe
│       │ test.exe
│       │ testalgo.exe
│       │ testalgo1.exe
│       │ testalgo2.exe
│       │ testalgo3.exe
│       │ testalgo4.exe
│       │ testalgo5.exe
│       │ testalgo6.exe
│       │ testalgo7.exe
│       │ testop.exe
│
├─── doc
│       │ 
│
├─── src
│       │ checker.py
│       │ input.txt
│       │ main.cpp
│
├─── test
        │ all outputs from tests goes here
```

## Menjalankan Program

Untuk menjalankan program, pada *root directory*, jalankan run.bat (pada *windows*):
```
./run.bat
```
Program akan berjalan, mulai dari *compile main.cpp*, menjalankan *main.exe*, lalu menjalankan *checker.py*

## Libraries Used

1. iostream (c++)
2. vector (c++)
3. string (c++)
4. fstream (c++)
5. sstream (c++)
6. cstdlib (c++)
7. ctime (c++)
8. chrono (c++)
9. os (python)
10. pathlib (python)