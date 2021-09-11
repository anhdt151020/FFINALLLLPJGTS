//
// Created by TuanAnh on 9/11/2021.
//

#ifndef FFINALLPROJECT_TIMKHOANGPHANLI_H
#define FFINALLPROJECT_TIMKHOANGPHANLI_H

// Ham tim khoang phan ly nghiem (a,b) voi |a-b| = buocNhay
void timKhoangPLNghiem(float buocNhay) {
    double arrGT[10000], check = 0, temp = cD;
    int k = 0;
    int count = 0, index;
    for (int i = 0; i < 100000; ++i) {
        if (temp > cT) {
            break;
        }
        arrGT[i] = giaTriHamSoTai(temp);
        temp = temp + buocNhay;
    }
    temp = cD;
    for (int i = 0; i < 100000; ++i) {
        if (temp > cT) {
            break;
        }
        check = arrGT[i] * arrGT[i + 1];
        if (check < 0) {
            arrKPL[k].a = temp;
            arrKPL[k].b = temp + buocNhay;
            k++;
            count++;
        }
        temp = temp + buocNhay;
    }
    index = 1;
    fprintf(fpop,"\n");
    fprintf(fpop,"\t\t\t+------------------+--------------------+----------------------+\n");
    fprintf(fpop,"\t\t\t|  Khoang phan ly  |         a          |           b          |\n");
    fprintf(fpop,"\t\t\t+------------------+--------------------+----------------------+\n");
    printf("\n");
    printf("\t\t\t+------------------+--------------------+----------------------+\n");
    printf("\t\t\t|  Khoang phan ly  |         a          |           b          |\n");
    printf("\t\t\t+------------------+--------------------+----------------------+\n");
    for (int i = 0; i < n * 2; ++i) {
        if ((arrKPL[i].a != 0) || (arrKPL[i].b != 0)) {
            printf("\t\t\t|         %d        |         %1.2f      |          %1.2f       |\n", index, arrKPL[i].a,arrKPL[i].b);
            printf("\t\t\t+------------------+--------------------+----------------------+\n");
            fprintf(fpop,"\t\t\t|         %d        |         %1.2f      |          %1.2f       |\n", index, arrKPL[i].a,arrKPL[i].b);
            fprintf(fpop,"\t\t\t+------------------+--------------------+----------------------+\n");
            index++;
        }
    }
}

#endif //FFINALLPROJECT_TIMKHOANGPHANLI_H
