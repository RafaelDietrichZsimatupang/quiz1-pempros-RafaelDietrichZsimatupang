#include <stdio.h>
#include <string.h>
struct Pakaian {
    char jenis[50];
    int jumlah;
};

int main() {
    char nama_pelanggan[100];
    float berat_cucian;
    int pilihan_hari;
    char *nama_hari[] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
    
    struct Pakaian daftar_pakaian[50];
    int jumlah_jenis = 0;
    int total_pcs = 0;

    printf("=======================================================\n");
    printf("   SISTEM PENCATATAN LAUNDRY INSTITUT TEKNOLOGI DEL    \n");
    printf("=======================================================\n");
    printf("Masukkan Nama Mahasiswa: ");
    fgets(nama_pelanggan, sizeof(nama_pelanggan), stdin);
    nama_pelanggan[strcspn(nama_pelanggan, "\n")] = 0;
    printf("Masukkan Berat Cucian (kg): ");
    scanf("%f", &berat_cucian);
    printf("\nPilih Hari Penjemputan:\n");
    printf("1=Senin, 2=Selasa, 3=Rabu, 4=Kamis, 5=Jumat, 6=Sabtu, 7=Minggu\n");
    printf("Masukkan angka hari (1-7): ");
    scanf("%d", &pilihan_hari);
    if (pilihan_hari < 1 || pilihan_hari > 7) {
        pilihan_hari = 1;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\n--- Rincian Pakaian ---\n");
    
    while (jumlah_jenis < 50) {
        printf("Jenis pakaian (ketik 'selesai' huruf kecil untuk mengakhiri): ");
        fgets(daftar_pakaian[jumlah_jenis].jenis, sizeof(daftar_pakaian[jumlah_jenis].jenis), stdin);
        daftar_pakaian[jumlah_jenis].jenis[strcspn(daftar_pakaian[jumlah_jenis].jenis, "\n")] = 0; 
        if (strcmp(daftar_pakaian[jumlah_jenis].jenis, "selesai") == 0) {
            break;
        }
        
        printf("Berapa banyak %s?: ", daftar_pakaian[jumlah_jenis].jenis);
        scanf("%d", &daftar_pakaian[jumlah_jenis].jumlah);
        
        total_pcs += daftar_pakaian[jumlah_jenis].jumlah;
        jumlah_jenis++;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    int index_hari_masuk = pilihan_hari - 1;
    int index_hari_keluar = (index_hari_masuk + 2) % 7; 
    printf("\n===================================\n");
    printf("          DATA CUCIAN LAUNDRY        \n");
    printf("=====================================\n");
    printf("Nama Mahasiswa    : %s\n", nama_pelanggan);
    printf("Hari Penjemputan  : %s\n", nama_hari[index_hari_masuk]);
    printf("Hari Pengembalian : %s\n", nama_hari[index_hari_keluar]);
    printf("Berat Total       : %.2f kg\n", berat_cucian);
    printf("Total Pakaian     : %d pcs\n", total_pcs);
    printf("----------------------------------------\n");
    
    printf("Detail Pakaian:\n");
    if (jumlah_jenis == 0) {
        printf("- (Tidak ada rincian pakaian)\n");
    } else {
        for (int i = 0; i < jumlah_jenis; i++) {
            printf("- %-15s : %d pcs\n", daftar_pakaian[i].jenis, daftar_pakaian[i].jumlah);
        }
    }
    printf("========================================\n");
    printf("     Mohon simpan resi ini dengan baik  \n");
    printf("========================================\n");

    return 0;
}