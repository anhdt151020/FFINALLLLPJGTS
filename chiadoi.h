//
// Created by TuanAnh on 9/11/2021.
//

#ifndef FFINALLPROJECT_CHIADOI_H
#define FFINALLPROJECT_CHIADOI_H

// Rút gọn khoảng phân ly nghiệm bằng phương pháp chia đôi |a - b| <= ssCĐ
void chiaDoi(double ssCD) {
    double c, temp;
    int j = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (giaTriHamSoTai(arrKPL[i].a) * giaTriHamSoTai(arrKPL[i].b) > 0) {
            continue;
        }
        temp = (arrKPL[i].b - arrKPL[i].a);
        if (arrKPL[i].a == arrKPL[i].b) {
            break;
        }
        fprintf(fpop,"\t\t\t+----+---------------+---------------+---------------+---------+----------------+\n");
        fprintf(fpop,"\t\t\t|  i |       a       |        b      |    x=(a+b)/2  |f(a).f(x)|  |b - a| < esl |\n");
        fprintf(fpop,"\t\t\t+----+---------------+---------------+---------------+---------+----------------+\n");
        printf("\t\t\t+----+---------------+---------------+---------------+---------+----------------+\n");
        printf("\t\t\t|  i |       a       |        b      |    x=(a+b)/2  |f(a).f(x)|  |b - a| < esl |\n");
        printf("\t\t\t+----+---------------+---------------+---------------+---------+----------------+\n");
        while (temp > ssCD) {
            j++;
            c = (arrKPL[i].b + arrKPL[i].a) / 2;
            if (giaTriHamSoTai(c) == 0) {
                printf("Nghiem cua phuong trinh la: %f", c);
                fprintf(fpop,"Nghiem cua phuong trinh la: %f", c);
                break;
            } else if (giaTriHamSoTai(c) * giaTriHamSoTai(arrKPL[i].a) < 0) {
                arrKPL[i].b = c;
            } else if (giaTriHamSoTai(c) * giaTriHamSoTai(arrKPL[i].a) > 0) {
                arrKPL[i].a = c;
            }
            temp = (arrKPL[i].b - arrKPL[i].a);
            if (giaTriHamSoTai(c) * giaTriHamSoTai(arrKPL[i].a) < 0) {
                if (temp < ssCD){
                    printf("\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    -    |      true      |\n",count,arrKPL[i].a,arrKPL[i].b,c);
                    fprintf(fpop,"\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    -    |      true      |\n",count,arrKPL[i].a,arrKPL[i].b,c);
                    break;
                }
                printf("\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    -    |      false     |\n",count,arrKPL[i].a,arrKPL[i].b,c);
                fprintf(fpop,"\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    -    |      false     |\n",count,arrKPL[i].a,arrKPL[i].b,c);
            } else if (giaTriHamSoTai(c) * giaTriHamSoTai(arrKPL[i].a) > 0) {
                if (temp < ssCD){
                    printf("\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    +    |      true      |\n",count,arrKPL[i].a,arrKPL[i].b,c);
                    fprintf(fpop,"\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    +    |      true      |\n",count,arrKPL[i].a,arrKPL[i].b,c);
                    break;
                }
                printf("\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    +    |      false     |\n",count,arrKPL[i].a,arrKPL[i].b,c);
                fprintf(fpop,"\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    +    |      false     |\n",count,arrKPL[i].a,arrKPL[i].b,c);
            }
            count ++;
        }
        printf("\t\t\t+----+---------------+---------------+---------------+---------+----------------+\n");
        fprintf(fpop,"\t\t\t+----+---------------+---------------+---------------+---------+----------------+\n");
        count = 0;
        printf("\n x= %.15f", c);
        printf("\n sai so= %.15f\n", temp);
        fprintf(fpop,"\n x= %.15f", c);
        fprintf(fpop,"\n sai so= %.15f\n", temp);
    }
}

#endif //FFINALLPROJECT_CHIADOI_H
