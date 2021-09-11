//
// Created by TuanAnh on 9/11/2021.
//

#ifndef FFINALLPROJECT_DAYCUNG_H
#define FFINALLPROJECT_DAYCUNG_H

// Rút gọn khoảng phân ly nghiệm bằng phương pháp dây cung
void dayCung(double ssDC){
    double mi,ma,c,temp,check;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count = 1;
        if (giaTriHamSoTai(arrKPL[i].a) * giaTriHamSoTai(arrKPL[i].b) > 0) {
            continue;
        }
        mi = fabs(daoHamTai(arrKPL[i].a));
        ma = fabs(daoHamTai(arrKPL[i].b));
        if (mi > ma){
            float k;
            k = mi;
            mi = ma;
            ma = k;
        }
        c = arrKPL[i].a - giaTriHamSoTai(arrKPL[i].a)*((arrKPL[i].b-arrKPL[i].a)/(giaTriHamSoTai(arrKPL[i].b)- giaTriHamSoTai(arrKPL[i].a)));
        temp = c;
        if (giaTriHamSoTai(c) * giaTriHamSoTai(arrKPL[i].a) < 0){
            arrKPL[i].b = c;
        }
        if (giaTriHamSoTai(c) * giaTriHamSoTai(arrKPL[i].b) < 0){
            arrKPL[i].a = c;
        }
        c = arrKPL[i].a - giaTriHamSoTai(arrKPL[i].a)*((arrKPL[i].b-arrKPL[i].a)/(giaTriHamSoTai(arrKPL[i].b)- giaTriHamSoTai(arrKPL[i].a)));
        check = ((ma - mi)/mi) * fabs(c - temp);
        printf("x0 = %.15f\n",c);
        printf("\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
        printf("\t\t\t|  i |         xn         |        xn-1        |       sai so       |       sai so < ssDC    |\n");
        printf("\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
        fprintf(fpop,"x0 = %.15f\n",c);
        fprintf(fpop,"\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
        fprintf(fpop,"\t\t\t|  i |         xn         |        xn-1        |       sai so       |       sai so < ssDC    |\n");
        fprintf(fpop,"\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
        while (check > ssDC){
            temp = c;
            if (giaTriHamSoTai(c) * giaTriHamSoTai(arrKPL[i].a) < 0){
                arrKPL[i].b = c;
            }
            if (giaTriHamSoTai(c) * giaTriHamSoTai(arrKPL[i].b) < 0){
                arrKPL[i].a = c;
            }
            c = arrKPL[i].a - giaTriHamSoTai(arrKPL[i].a)*((arrKPL[i].b-arrKPL[i].a)/(giaTriHamSoTai(arrKPL[i].b)- giaTriHamSoTai(arrKPL[i].a)));
            check = ((ma - mi)/mi) * fabs(c - temp);
            if( check < ssDC){
                printf("\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          true          |\n",count,c,temp,check);
                printf("\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
                printf("nghiem x = %.15f\n",c);
                printf("sai so hai lan lap lien tiep = %.15f\n",check);
                printf("sai so = %.15f\n", fabs(giaTriHamSoTai(c)));
                printf("\t\t\t\t\t\t\t\t *-*-* \n");

                fprintf(fpop,"\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          true          |\n",count,c,temp,check);
                fprintf(fpop,"\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
                fprintf(fpop,"nghiem x = %.15f\n",c);
                fprintf(fpop,"sai so hai lan lap lien tiep = %.15f\n",check);
                fprintf(fpop,"sai so = %.15f\n", fabs(giaTriHamSoTai(c)));
                fprintf(fpop,"\t\t\t\t\t\t\t\t *-*-* \n");

            }
            if( check > ssDC){
                printf("\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          false         |\n",count,c,temp,check);
                fprintf(fpop,"\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          false         |\n",count,c,temp,check);
            }
            count ++;

        }
    }

}

#endif //FFINALLPROJECT_DAYCUNG_H
