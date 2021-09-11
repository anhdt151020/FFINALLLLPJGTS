/*
 * GTS 20202
 * ĐINH TUẤN ANH 20185429
 * 125002 - NHÓM 6
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* KHÔNG XÓA INCLUDE TRÊN DÒNG NÀY */

#include "fx.h"
#include "bankinh.h"
#include "cuctri.h"
#include "timkhoangphanli.h"
#include "chiadoi.h"
#include "daycung.h"
#include "tieptuyen.h"

//Menu chọn thuật toán lặp
void menu(){
    int choose;
    do {
        printf("\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                           ***  CHON PHUONG PHAP LAP  ***                            |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [1]. PHUONG PHAP CHIA DOI                                   |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [2]. PHUONG PHAP DAY CUNG                                   |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [3]. PHUONG PHAP TIEP TUYEN                                 |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [4]. THOAT                                                  |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("Nhap vao lua chon:");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                fprintf(fpop,"\n\t [1]. PHUONG PHAP CHIA DOI  \n");
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].a = arrKPL1[i].a;
                    arrKPL[i].b = arrKPL1[i].b;
                }
                printf("Su dung phuong phap chia doi thu gon cac khoang phan li nghiem da cho ta duoc: \n");
                fprintf(fpop,"Su dung phuong phap chia doi thu gon cac khoang phan li nghiem da cho ta duoc: \n");
                chiaDoi(1e-10);
                break;
            case 2:
                fprintf(fpop,"\n\t [2]. PHUONG PHAP DAY CUNG  \n");
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].a = arrKPL1[i].a;
                    arrKPL[i].b = arrKPL1[i].b;
                }
                printf("Su dung phuong phap day cung thu gon cac khoang phan li nghiem da cho ta duoc: \n");
                fprintf(fpop,"Su dung phuong phap day cung thu gon cac khoang phan li nghiem da cho ta duoc: \n");
                dayCung(1e-10);
                break;
            case 3:
                fprintf(fpop,"\n\t [3]. PHUONG PHAP TIEP TUYEN  \n");
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].a = arrKPL1[i].a;
                    arrKPL[i].b = arrKPL1[i].b;
                }
                printf("Su dung phuong phap tiep tuyen thu gon cac khoang phan li nghiem da cho ta duoc: \n");
                fprintf(fpop,"Su dung phuong phap tiep tuyen thu gon cac khoang phan li nghiem da cho ta duoc: \n");
                tiepTuyen(1e-10);
                break;
            case 4:
                printf("Quay lai menu chon cach tinh sai so !!!");
                break;
            default:
                printf("Nhap sai lua chon moi nhap lai:\n");
        }
    }while (choose != 4);
}

// Main
void main() {
    fpop = fopen("output.txt","w");
    int choose;
    float buocNhay;
    float ssCD;
    nhapHamSo();
    printf("Ham so da cho co nghiem nam trong mat tron tam O ban kinh R=[%f] o trong mat phang phuc", banKinhNghiem());
    fprintf(fpop,"Ham so da cho co nghiem nam trong mat tron tam O ban kinh R=[%f] o trong mat phang phuc", banKinhNghiem());
    printf("\nCan tren va can duoi cua mien chua nghiem thuc: \nCan tren =[%f], Can duoi =[%f]", canTren(), canDuoi());
    fprintf(fpop,"\nCan tren va can duoi cua mien chua nghiem thuc: \nCan tren =[%f], Can duoi =[%f]", canTren(), canDuoi());
    do {
        printf("\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         GIAI TICH SO 20202 NHOM 1 - CHU DE 6                        |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [1]. SU DUNG KHOANG PHAN LY TIM BANG BUOC NHAY              |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [2]. SU DUNG KHOANG PHAN LY TIM BANG CUC TRI                |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [3]. QUAY LAI                                               |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [4]. THOAT                                                  |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("Nhap vao lua chon:");
        scanf("%d", &choose);
        switch (choose) {
            case 1:
                fprintf(fpop,"\n[1]. SU DUNG KHOANG PHAN LY TIM BANG BUOC NHAY");
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].b = 0;
                    arrKPL[i].a = 0;
                }
                buocNhay = 0;
                ssCD = 0;

                // Tìm khoảng phân ly nghiệm từ bán kính nghiệm và cận trên cận dưới miền chứa nghiệm.
                buocNhay = (cT-cD)/100;
                printf("Voi khoang cach k = 1/100 khoang chua nghiem ta su dung thuat toan vet can de tim khoang phan ly nghiem duoc:");
                fprintf(fpop,"\n\tVoi khoang cach k = 1/100 khoang chua nghiem ta su dung thuat toan vet can de tim khoang phan ly nghiem duoc:");
                timKhoangPLNghiem(buocNhay);
                for (int i = 0; i < n; ++i) {
                    arrKPL1[i].a = arrKPL[i].a;
                    arrKPL1[i].b = arrKPL[i].b;
                }
                //Thu gọn khoảng phân ly nghiệm
                printf("\n");
                printf("Chon thuat toan thu gon khoang phan li nghiem:\n");
                menu();
                break;
            case 2:
                printf("\n");
                fprintf(fpop,"\n");
                printf("Su dung thuat toan Gradient Descent tim cuc tri cua ham so da cho ta duoc:");
                fprintf(fpop,"Su dung thuat toan Gradient Descent tim cuc tri cua ham so da cho ta duoc:");
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].b = 0;
                    arrKPL[i].a = 0;
                }
                buocNhay = 0;
                ssCD = 0;
                cucTriFx(cD);
                for (int i = 0; i < sCT; ++i) {
                    if (arayCT[i] != 0){
                        printf("\n Tai x = [%f] ham so da cho co 1 cuc tri",arayCT[i]);
                        fprintf(fpop,"\n Tai x = [%f] ham so da cho co 1 cuc tri",arayCT[i]);
                    }
                    if ((arayCT[i] == 0) && (daoHamTai(arayCT[i]) == 0)){
                        printf("\n Tai x = [%f] ham so da cho co 1 cuc tri",arayCT[i]);
                        fprintf(fpop,"\n Tai x = [%f] ham so da cho co 1 cuc tri",arayCT[i]);
                    }
                }
                for (int i = 0; i < sCT; ++i) {
                    if (arayCT[i] != 0){
                        if (fabs(giaTriHamSoTai(arayCT[i])) < 0.001){
                            printf("\nCuc tri x = [%f] la mot nghiem cua ham so da cho",arayCT[i]);
                            fprintf(fpop,"\nCuc tri x = [%f] la mot nghiem cua ham so da cho",arayCT[i]);
                        }
                    }
                    if ((arayCT[i] == 0) && (daoHamTai(arayCT[i]) == 0)){
                        if (fabs(giaTriHamSoTai(arayCT[i])) < 0.001){
                            printf("\nCuc tri x = [%f] la mot nghiem cua ham so da cho",arayCT[i]);
                            fprintf(fpop,"\nCuc tri x = [%f] la mot nghiem cua ham so da cho",arayCT[i]);
                        }
                    }
                }
                printf("\n Voi cac cuc tri da tim duoc ta co the xet cac khoang phan ly nghiem sau day:\n");
                fprintf(fpop,"\n Voi cac cuc tri da tim duoc ta co the xet cac khoang phan ly nghiem sau day:\n");
                int j = 1;
                arrKPL[0].a = cD;
                arrKPL[0].b = arayCT[0];
                for (int i = 0; i < sCT; ++i) {
                    arrKPL[j].a = arayCT[i];
                    arrKPL[j].b = arayCT[i+1];
                    if (arayCT[i + 1] == arayCT[i + 2]){
                        arrKPL[j].b = cT;
                    }
                    j++;
                }

                int index = 1;
                printf("\n\n");
                printf("\t\t\t+------------------+--------------------+----------------------+\n");
                printf("\t\t\t|  Khoang phan ly  |         a          |           b          |\n");
                printf("\t\t\t+------------------+--------------------+----------------------+\n");
                fprintf(fpop,"\n\n");
                fprintf(fpop,"\t\t\t+------------------+--------------------+----------------------+\n");
                fprintf(fpop,"\t\t\t|  Khoang phan ly  |         a          |           b          |\n");
                fprintf(fpop,"\t\t\t+------------------+--------------------+----------------------+\n");
                for (int i = 0; i < n * 2; ++i) {
                    if (giaTriHamSoTai(arrKPL[i].a) * giaTriHamSoTai(arrKPL[i].b) > 0){
                        continue;
                    }
                    if ((arrKPL[i].a != 0) || (arrKPL[i].b != 0)) {
                        printf("\t\t\t|         %d        |         %1.2f      |          %1.2f       |\n", index, arrKPL[i].a,arrKPL[i].b);
                        printf("\t\t\t+------------------+--------------------+----------------------+\n");
                        fprintf(fpop,"\t\t\t|         %d        |         %1.2f      |          %1.2f       |\n", index, arrKPL[i].a,arrKPL[i].b);
                        fprintf(fpop,"\t\t\t+------------------+--------------------+----------------------+\n");
                        index++;
                    }
                }
                if (index != 1){
                    printf("Chon thuat toan rut gon khoang phan li nghiem\n");
                }
                if (index == 1){
                    printf("\n Khong tim duoc nghiem cua phuong trinh\n");
                }
                for (int i = 0; i < n; ++i) {
                    arrKPL1[i].a = arrKPL[i].a;
                    arrKPL1[i].b = arrKPL[i].b;
                }
                menu();
                break;
            case 3:
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].b = 0;
                    arrKPL[i].a = 0;
                }
                cT = 0;
                cD = 0;
                buocNhay = 0;
                ssCD = 0;
                main();
            case 4:
                printf("\n");
                printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
                printf("\t\t\t|                          THANKS FOR LISTENING !!!!                                  |\n");
                printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
                exit(0);
            default:
                printf("Nhap sai lua chon moi nhap lai:\n");
        }
    }while (choose != 4);
    // Tìm khoảng phân ly nghiệm từ bán kính nghiệm và cận trên cận dưới miền chứa nghiệm.
    buocNhay = (cT-cD)/100;
    timKhoangPLNghiem(buocNhay);

    //Thu gọn khoảng phân ly nghiệm bằng phương pháp chia đôi
    printf("\n");
    chiaDoi(0.0001);
    do {
        printf("\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         GIAI TICH SO 20202 NHOM 1 - CHU DE 6                        |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [1]. NHAP LAI PHUONG TRINH DA THUC                          |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("\t\t\t|                         [2]. THOAT                                                  |\n");
        printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
        printf("Nhap vao lua chon:");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].b = 0;
                    arrKPL[i].a = 0;
                }
                cT = 0;
                cD = 0;
                buocNhay = 0;
                ssCD = 0;
                main();
                break;
            case 2:
                printf("\n");
                printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
                printf("\t\t\t|                          THANKS FOR LISTENING !!!!                                  |\n");
                printf("\t\t\t+-------------------------------------------------------------------------------------+\n");
                exit(0);
            default:
                printf("Nhap sai lua chon moi nhap lai:\n");
        }
    }while (choose != 2);
    fclose(fpop);
}
