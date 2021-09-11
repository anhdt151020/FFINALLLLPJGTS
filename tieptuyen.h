//
// Created by TuanAnh on 9/11/2021.
//

#ifndef FFINALLPROJECT_TIEPTUYEN_H
#define FFINALLPROJECT_TIEPTUYEN_H

// Rút gọn khoảng phân ly nghiệm bằng phương pháp tiếp tuyến
void tiepTuyen(double ssTT) {
    double mi1, ma1, mi2, ma2, check, temp, checkss, tempss;
    int count = 0;
    daoHamTai(0);
    for (int i = 0; i < n; ++i) {
        count = 1;
        mi1 = fabs(daoHamTai(arrKPL[i].a));
        ma1 = fabs(daoHamTai(arrKPL[i].b));
        if (mi1 > ma1){
            temp = mi1;
            mi1 = ma1;
            ma1 = temp;
            temp = 0;
        }
        mi2 = fabs(daoHamCap2Tai(arrKPL[i].a));
        ma2 = fabs(daoHamCap2Tai(arrKPL[i].b));
        if (mi2 > ma2){
            temp = mi2;
            mi2 = ma2;
            ma2 = temp;
            temp = 0;
        }
        if (arrKPL[i].a * daoHamCap2Tai(arrKPL[i].a) > 0) {
            temp = arrKPL[i].a - (giaTriHamSoTai(arrKPL[i].a) / daoHamTai(arrKPL[i].a));
            printf("Chon xap xi dau la can duoi cua khoang phan li, giao diem giua tiep tuyen tai xap xi dau voi truc hoanh x0= %f \n", temp);
            fprintf(fpop,"Chon xap xi dau la can duoi cua khoang phan li, giao diem giua tiep tuyen tai xap xi dau voi truc hoanh x0= %f \n", temp);
        } else if (arrKPL[i].b * daoHamCap2Tai(arrKPL[i].b > 0)) {
            temp = arrKPL[i].b - (giaTriHamSoTai(arrKPL[i].b) / daoHamTai(arrKPL[i].b));
            printf("Chon xap xi dau la can tren cua khoang phan li, giao diem giua tiep tuyen tai xap xi dau voi truc hoanh x0= %f \n", temp);
            fprintf(fpop,"Chon xap xi dau la can tren cua khoang phan li, giao diem giua tiep tuyen tai xap xi dau voi truc hoanh x0= %f \n", temp);
        }
        check = fabs(giaTriHamSoTai(temp));
        printf("\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
        printf("\t\t\t|  i |         xn         |        xn-1        |       sai so       |       sai so < ssDC    |\n");
        printf("\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
        fprintf(fpop,"\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
        fprintf(fpop,"\t\t\t|  i |         xn         |        xn-1        |       sai so       |       sai so < ssDC    |\n");
        fprintf(fpop,"\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
        while (check > ssTT) {
            tempss = temp;
            temp = temp - (giaTriHamSoTai(temp) / daoHamTai(temp));
            checkss = ma2/(2*mi1)* fabs(temp - tempss) * fabs(temp - tempss);
            check = fabs(giaTriHamSoTai(temp));
            if (check <= ssTT) {
                printf("\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          true          |\n",count,temp,tempss,check);
                printf("\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
                printf("x = %.15f\n", temp);
                printf("sai so hai lan lap lien tiep = %.25f\n",checkss);
                printf("sai so = %.25f\n",check);
                printf("\t\t\t\t\t\t\t\t *-*-* \n");

                fprintf(fpop,"\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          true          |\n",count,temp,tempss,check);
                fprintf(fpop,"\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
                fprintf(fpop,"x = %.15f\n", temp);
                fprintf(fpop,"sai so hai lan lap lien tiep = %.25f\n",checkss);
                fprintf(fpop,"sai so = %.25f\n",check);
                fprintf(fpop,"\t\t\t\t\t\t\t\t *-*-* \n");
            }
            if (check > ssTT) {
                printf("\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          false         |\n",count,temp,tempss,check);
                fprintf(fpop,"\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          false         |\n",count,temp,tempss,check);
            }
            count ++;
        }
    }
}

#endif //FFINALLPROJECT_TIEPTUYEN_H
