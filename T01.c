#include <stdio.h>
#include <string.h>

struct Menu {
    char kode[5];
    char nama[30];
    int harga;
};

struct Pesanan {
    char namaMenu[30];
    int porsiTotal;
    int hargaSatuan;
    int subTotal;
};

int main() {
    struct Menu daftarMenu[] = {
        {"NGS", "Nasi Goreng Spesial", 15000},
        {"AP",  "Ayam Penyet",          20000},
        {"SA",  "Sate Ayam (10 Tusuk)", 25000},
        {"BU",  "Bakso Urat",           18000},
        {"MAP", "Mie Ayam Pangsit",     15000},
        {"GG",  "Gado-Gado",            15000},
        {"SAM", "Soto Ayam",            17000},
        {"RD",  "Rendang Daging",       25000},
        {"IB",  "Ikan Bakar",           35000},
        {"NUK", "Nasi Uduk Komplit",    20000}
    };
    
    int jumlahMenu = sizeof(daftarMenu) / sizeof(daftarMenu[0]);
    struct Pesanan keranjang[50];
    int jumlahPesanan = 0;
    char inputKode[10];
    int inputPorsiButet;
    long totalBelanja = 0;
    
    while (1) {
        scanf("%s", inputKode);
        if (strcmp(inputKode, "END") == 0) {
            break;
        }
        
        scanf("%d", &inputPorsiButet);
        int ditemukan = 0;
        for (int i = 0; i < jumlahMenu; i++) {
            if (strcmp(inputKode, daftarMenu[i].kode) == 0) {
                int totalPorsi = inputPorsiButet * 3;
                int subTotal = totalPorsi * daftarMenu[i].harga;
                strcpy(keranjang[jumlahPesanan].namaMenu, daftarMenu[i].nama);
                keranjang[jumlahPesanan].porsiTotal = totalPorsi;
                keranjang[jumlahPesanan].hargaSatuan = daftarMenu[i].harga;
                keranjang[jumlahPesanan].subTotal = subTotal;
                
                totalBelanja += subTotal;
                jumlahPesanan++;
                ditemukan = 1;
                break;
            }
        }
        
        if (!ditemukan) {
            printf("Kode menu '%s' tidak ditemukan!\n", inputKode);
        }
    }
    float diskonPersen = 0.0;
    char namaKupon[20] = "Tidak Ada";
    
    if (totalBelanja >= 500000) {
        diskonPersen = 0.25;
        strcpy(namaKupon, "Kupon Hitam");
    } else if (totalBelanja >= 400000) {
        diskonPersen = 0.20;
        strcpy(namaKupon, "Kupon Hijau");
    } else if (totalBelanja >= 300000) {
        diskonPersen = 0.15;
        strcpy(namaKupon, "Kupon Merah");
    } else if (totalBelanja >= 200000) {
        diskonPersen = 0.10;
        strcpy(namaKupon, "Kupon Kuning");
    } else if (totalBelanja >= 100000) {
        diskonPersen = 0.05;
        strcpy(namaKupon, "Kupon Biru");
    }
    
    long jumlahDiskon = totalBelanja * diskonPersen;
    long totalBayar = totalBelanja - jumlahDiskon;
    printf("\n\n");
    printf("%-25s %-8s %-12s %-12s\n", "Menu", "Porsi", "Harga", "Total");
    printf("===============================================================\n");
    
    for (int i = 0; i < jumlahPesanan; i++) {
        printf("%-25s %-8d %-12d %-12d\n", 
               keranjang[i].namaMenu, 
               keranjang[i].porsiTotal, 
               keranjang[i].hargaSatuan, 
               keranjang[i].subTotal);
    }
    
    printf("===============================================================\n");
    printf("Subtotal         : %ld\n", totalBelanja);
    printf("Diskon (%s) : -%ld\n", namaKupon, jumlahDiskon);
    printf("===============================================================\n");
    printf("Total Pembayaran : %ld\n", totalBayar);
    
    return 0;
}