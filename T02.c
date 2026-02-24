#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int kode_kelompok;
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &N);
    int *rak_nilai = (int*) malloc(N * sizeof(int));
    printf("Masukkan %d deret nilai (pisahkan dengan spasi):\n", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &rak_nilai[i]);
    }
    printf("Masukkan kode kelompok (1 untuk Ganjil, 0 untuk Genap): ");
    scanf("%d", &kode_kelompok);
    printf("\n--- Hasil Data Kelompok ---\n");
    
    if (kode_kelompok == 1) {
        printf("Kelompok Ganjil: ");
        for(int i = 0; i < N; i++) {
            if(rak_nilai[i] % 2 != 0) {
                printf("%d ", rak_nilai[i]);
            }
        }
    } 
    else if (kode_kelompok == 0) {
        printf("Kelompok Genap: ");
        for(int i = 0; i < N; i++) {
            if(rak_nilai[i] % 2 == 0) {
                printf("%d ", rak_nilai[i]);
            }
        }
    }
    else {
        printf("Kode kelompok tidak dikenali.");
    }
    printf("\n");
    free(rak_nilai);

    return 0;
}