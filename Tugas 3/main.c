#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <stdbool.h>

int main()
{
    char ch, file_name[25];
    char arr_data[6][2];
    char arr_data2[12][2];
    char arr_pdf[5][2]   = {"25","50","44","46","2D"};
    char arr_jpg1[4][2]  = {"FF","D8","FF","DB"};
    char arr_jpg2[12][2] = {"FF","D8","FF","E0","00","10","4A","46","49","46","00","01"};
    char arr_jpg3[4][2]  = {"FF","D8","FF","EE"};
    char arr_jpg4[12][2] = {"FF","D8","FF","E1","??","??","45","78","69","66","00","00"};
    bool isPDF = true;
    bool isJPG1 = true;
    bool isJPG2 = true;
    bool isJPG3 = true;
    bool isJPG4 = true;
    bool isOther = false;
    FILE *fp;
 
    printf("Enter the name of file you wish to see\n");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strlen(file_name)-1] = 0x00;
 
    fp = fopen(file_name,"rb"); // read binary mode
 
    if( fp == NULL ) { //error checking 
       perror("Error while opening the file.\n");
       exit(EXIT_FAILURE);
    }
 
    printf("The contents of %s file are :\n", file_name);

    int i = 0;
    int j = 0;
    while( ( ch = fgetc(fp) ) != EOF ) {
        arr_data[i][0] = ch;
        i++;
        //    printf("%02X ",ch);
        // if( !(++i % 16) ) putc('\n', stdout);
    }

    fclose(fp);
    putc('\n', stdout);
    
    int k = 1;
    for (i = 0; i<12; i++) {
        for (j = 0; j<2; j++) {
            arr_data2[i][j] = arr_data[i/2][k/2];
            if (k == 4) {
                k = 1;
            }
            else {
                k++;
            }
        }
    }

    for (i = 0; i<12; i++) {
        for (j = 0; j<2; j++) {
            printf("%02X%d%d ", arr_data2[i][j], i,j);
        }
    }

    // Cek PDF: 5 Hex Signature
    for (i = 0; i<5; i++) {
        if (arr_data[i] != arr_pdf[i]) {
            isPDF = false;
        }
    }
    // Cek JPG1: 4 Hex Signature
    for (i = 0; i<4; i++) {
        if (arr_data[i] != arr_jpg1[i]) {
            isJPG1 = false;
        }
    }
    // Cek JPG2: 12 Hex Signature
    for (i = 0; i<12; i++) {
        if (arr_data[i] != arr_jpg2[i]) {
            isJPG2 = false;
        }
    }
    // Cek JPG3: 4 Hex Signature
    for (i = 0; i<4; i++) {
        if (arr_data[i] != arr_jpg3[i]) {
            isJPG3 = false;
        }
    }
    // Cek JPG4: 12 Hex Signature
    for (i = 0; i<12; i++) {
        if (arr_data[i] != arr_jpg4[i]) {
            isJPG4 = false;
        };
    }

    if (isPDF == true) {
        printf("\nFormat file adalah PDF.");
    }
    else if (isJPG1 == true || isJPG2 == true || isJPG3 == true || isJPG4 == true) {
        printf("\nFormat file adalah JPG.");
    }
    else {
        printf("\nFormat file tidak diketahui.");
    }

    system("pause");
 
    return 0;
}