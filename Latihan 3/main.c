#include <stdio.h>

int main(){
    struct mahasiswa
    {
        int nim;
        char nama[80];
        int kehadiran;
    };

    int n;
    printf("Masukan jumlah mahasiswa!\n");
    scanf("%d", &n);

    struct mahasiswa data[n];
    for (int i = 0; i < n; i++)
    {
        printf("Masukkan NIM mahasiswa\n");
        scanf("%d", &data[i].nim);

        printf("Masukkan nama mahasiswa\n");
        scanf("%s", &data[i].nama);

        printf("Masukkan kehadiran mahasiswa dalam persen\n");
        scanf("%d", &data[i].kehadiran);
    }
    
    for (int j = 0; j < n; j++)
    {
        if (data[j].kehadiran < 80)
        {
            printf("Mahasiswa %s kehadirannya kurang dari 80 persen\n", data[j].nama);
        }
    }
    
    return 0;
    
}