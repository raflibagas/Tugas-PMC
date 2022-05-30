#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

int HeadtoSpecific(int specific, int length, int witdh, int arr_data[][witdh]) {
	int i,j;
	int arr_head[witdh];
    for (i = 0; i<witdh; i++) {
		arr_head[i] = arr_data[0][i];
	}

	for (i = 0; i<length-1; i++) {
        for (j = 0; j<witdh; j++) {
            arr_data[i][j] = arr_data[i+1][j];
        }
	}
	
    for (i = 0; i<witdh; i++) {
		arr_data[specific][i] = arr_head[i];
	}
}

int Tabel_proses(int length, int witdh, int arr_data[][witdh]) {
	int i;
	printf("---------------------------------\n"
		   "| proses| datang|execute| now   |\n");
	for(i = 0; i<length; i++) {
		printf("| p%d\t| %d\t| %d\t| %d\t|\n", arr_data[i][0], arr_data[i][1], arr_data[i][2], arr_data[i][3]);
	}
	printf("---------------------------------\n\n");
}

int Tabel_hasil(int waktu_now, int length, int witdh, int arr_data[][witdh], int done) {
	int i;
	printf("|  %d\t", waktu_now);
	for(i = 0; i<length; i++) {
		printf("|  p%d\t", arr_data[i][0]);
	}
	printf("|  p%d\t|\n", done);
}

int main() {
// Script pembuka
	printf("\n\n\nROUND-ROBIN\n\n");

// Deklarasi variable
	// variable non-input
	int i = 0, j = 0, n = 0, m = 0, done = 0, waktu_now = 0, waktu_total = 0, counter_kuantum = 0;
	// variable input
	int jumlah_proses = 0, waktu_kuantum = 0, waktu_kedatangan = 0, waktu_eksekusi = 0, lanjut = 0;

	printf("Berapa waktu kuantum yang ingin dipakai? ");
	scanf("%d", &waktu_kuantum);
	printf("Ada berapa data jumlah prosesnya? ");
	scanf("%d", &jumlah_proses);

	// {id, kedatangan, eksekusi, counter}
	int arr_data[jumlah_proses][4];
	int arr_proses[jumlah_proses][4];
	for(i = 0; i<jumlah_proses; i++) {
		for(j = 0; j<4; j++) {
			arr_proses[i][j] = 0;
		}
	}

// Ambil input
	printf("!!!Silakan input sesuai urutan waktu kedatangan!!!\n");
	for(i = 0; i<jumlah_proses; i++) {
		arr_data[i][0] = i+1;
		printf("Waktu kedatangan p%d = ", i+1);
		scanf("%d", &waktu_kedatangan);
		arr_data[i][1] = waktu_kedatangan;
		printf("Waktu eksekusi p%d = ", i+1);
		scanf("%d", &waktu_eksekusi);
		arr_data[i][2] = waktu_eksekusi;
		arr_data[i][3] = 0;
	}

	for (i = 0; i<jumlah_proses; i++) { waktu_total += arr_data[i][2]; }
	printf("\nwaktu total = %d\n", waktu_total);

	printf("Data yang kamu masukan:\n");
	Tabel_proses(jumlah_proses, 4, arr_data);

	for (i = 5; i>0; i--) {
		sleep(1);
		printf("%d..", i);
	}

// Process
	
	waktu_now = -1, counter_kuantum = -1;
	while (waktu_now != waktu_total+1) {
		arr_proses[0][3] += 1;
		printf("waktu = %d  counter = %d\n", waktu_now, counter_kuantum);
		Tabel_proses(jumlah_proses, 4, arr_proses);
		if (arr_proses[0][3] == arr_proses[0][2]) { //kondisi tercapai
			printf("kondisi tercapai");
			for (i = 0; i<4; i++) { arr_proses[0][i] = 0; }
			HeadtoSpecific(n-1, jumlah_proses, 4, arr_proses);
			n--;
			counter_kuantum = 0;
			sleep(1);
		}
		else if (counter_kuantum == waktu_kuantum) { //kondisi gantian
			printf("kondisi gantian");
			HeadtoSpecific(n-1, jumlah_proses, 4, arr_proses);
			counter_kuantum = 0;
			sleep(1);
		}
		else if (waktu_now == arr_data[n][1]) { //kondisi kedatangan
			printf("kondisi kedatangan");
			for (i = 0; i<4; i++) { arr_proses[n][i] = arr_data[m][i]; }
			n++;
			m++;
			sleep(1);
		}
		else if (waktu_now == waktu_total) {	//kondisi selesai
			printf("kondisi selesai");
			sleep(1);
			break;
		}
		counter_kuantum ++;
		waktu_now++;
		usleep(100000);
		system("cls");
	}
	Tabel_proses(jumlah_proses, 4, arr_proses);
	for (i = 5; i>0; i--) {
		sleep(1);
		printf("%d..", i);
	}

	system("cls");
	if (jumlah_proses % 2 == 0) {
		printf("-----------------");
		for (i = 0; i<jumlah_proses; i++) { printf("--------"); }
		printf("\n| Waktu |    ");
		for (i = 0; i<jumlah_proses/2-1; i++) { printf("        "); }
		printf(" Antrian");
		for (i = 0; i<jumlah_proses/2-1; i++) { printf("        "); }
		printf("   |Selesai|\n");
	} else {
		printf("------------------");
		for (i = 0; i<jumlah_proses; i++) { printf("--------"); }
		printf("\n| Waktu |");
		for (i = 0; i<jumlah_proses/2; i++) { printf("        "); }
		printf("Antrian");
		for (i = 0; i<jumlah_proses/2; i++) { printf("        "); }
		printf("|Selesai|\n");
	}
	
	n = 0, m = 0, waktu_now = -1, counter_kuantum = -1;
	while (waktu_now != waktu_total+1) {
		arr_proses[0][3] += 1;
		if (arr_proses[0][3] == arr_proses[0][2]) { //kondisi tercapai
			int temp = arr_proses[0][0];
			for (i = 0; i<4; i++) { arr_proses[0][i] = 0; }
			HeadtoSpecific(n-1, jumlah_proses, 4, arr_proses);
			Tabel_hasil(waktu_now, jumlah_proses, 4, arr_proses, temp);
			n--;
			counter_kuantum = 0;
			sleep(1);
		}
		else if (counter_kuantum == waktu_kuantum) { //kondisi gantian
			HeadtoSpecific(n-1, jumlah_proses, 4, arr_proses);\
			Tabel_hasil(waktu_now, jumlah_proses, 4, arr_proses, 0);
			counter_kuantum = 0;
			sleep(1);
		}
		else if (waktu_now == arr_data[n][1]) { 	//kondisi kedatangan
			for (i = 0; i<4; i++) { arr_proses[n][i] = arr_data[m][i]; }
			Tabel_hasil(waktu_now, jumlah_proses, 4, arr_proses, 0);
			n++;
			m++;
			sleep(1);
		}
		else if (waktu_now == waktu_total) {		//kondisi selesai
			sleep(1);
			break;
		}
		counter_kuantum ++;
		waktu_now++;
		usleep(100000);
	}

// Output hasil
	if (jumlah_proses % 2 == 0) {
		printf("-----------------");
		for (i = 0; i<jumlah_proses; i++) { printf("--------"); }
	} else {
		printf("------------------");
		for (i = 0; i<jumlah_proses; i++) { printf("--------"); }
	}
	printf("\n");

}