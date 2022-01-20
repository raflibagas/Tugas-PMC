#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pilihan, a = 0, b = 0;
    printf("Dapatkan ceret berisi 4 liter dengan menggunakan 2 ceret masing-masing berkapasitas 3 liter dan 5 liter \n");
    while (b != 4){
        printf("a = %d", a);
        printf("\n");
        printf("b = %d", b);
        printf("\n");
        printf("Pilih nomor intsruksi \n");
        printf("1. Isi ceret 3 liter \n");
        printf("2. Isi ceret 5 liter \n");
        printf("3. Kosongkan ceret 3 liter \n");
        printf("4. Kosongkan ceret 5 liter \n");
        printf("5. Tuangkan isi ceret 3 liter ke dalam ceret 5 liter \n");
        printf("6. Tuangkan isi ceret 5 liter ke dalam ceret 3 liter \n");
        printf("Masukkan nomor instruksi : \n");
        scanf("%d", &pilihan);
        if (pilihan == 1){
            a = 3;
        }
        else if (pilihan == 2){
            b = 5;
        }
        else if (pilihan == 3){
            a = 0;
        }
        else if (pilihan == 4){
            b = 0;
        }
        else if (pilihan == 5){
            b = a + b;
            if (b > 5){
                a = b - 5;
                b = 5;
            }
            else{
                a = 0;
            }
        }
        else if (pilihan == 6){
            a = a + b;
            if (a > 3){
                b = a - 3;
                a = 3;
            }
            else{
                b = 0;
            }
        }
        else{
            printf("Masukkan nomor instruksi yang tersedia /n");
        }
    }
    printf("a = %d", a);
    printf("\n");
    printf("b = %d", b);
    printf("\n");
    printf("Selamat, anda telah berhasil mendapatkan ceret berisi 4 liter \n");
    return 0;
}
