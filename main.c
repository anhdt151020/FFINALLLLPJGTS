#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n,sCT; //Bậc của đa thức
double arayF[10]; //Mảng chứa hệ số của đa thức
double arayF1[10]; //Mảng chứa hệ số của đa thức đạo hàm
double arayCT[18]; //Mảng chứa x CTri
double araySol[10]; //Mảng chứa nghiệm
float cT, cD;

typedef struct khoangPhanLy {
    double a;
    double b;
} kpl;

kpl arrKPL[20]; //Mảng chứa khoảng phân ly của đa thức
kpl arrKPL1[20]; //Mảng chứa khoảng phân ly dự phòng

// Hàm nhập hệ số của phương trình y = f(x)
void nhapHeSo() {
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            printf("Nhap he so cua x^[%d]: ", n - i);
            scanf("%lf", &arayF[i]);
            printf("\n");
            while (arayF[i] == 0) {
                printf("He so cua x^[%d] phai khac 0 \n", n - i);
                printf("Nhap lai he so cua x^[%d]:", n - i);
                scanf("%lf", &arayF[i]);
                printf("\n");
            }
            continue;
        }
        printf("Nhap he so cua x^[%d]: ", n - i);
        scanf("%lf", &arayF[i]);
        printf("\n");
    }
}

// Hàm nhập Hàm số y = f(x)
void nhapHamSo() {
    printf("Nhap bac cua da thuc n = ");
    scanf("%d", &n);
    nhapHeSo();
    printf("\t ham so: y= f(x)= ");
    for (int i = 0; i <= n; ++i) {
        if (i == n) {
            printf("%.2f\n", arayF[i]);
        } else {
            printf("%.2fx^[%d]+", arayF[i], n - i);
        }
    }
}

//Hàm tính giá trị hàm số tại một điểm sử dụng Hoocne
double giaTriHamSoTai(double x0) {
    double temp = 0;
    temp = arayF[0] * x0;
    for (int i = 1; i < n; ++i) {
        temp = (temp + arayF[i]) * x0;
    }
    temp = temp + arayF[n];
    return temp;
}

// Hàm tính đạo hàm cấp 1 của hàm số tại một điểm
double daoHamTai(double temp) {
    double sum = 0;
    for (int i = 0; i <= n - 1; i++) {
        sum = sum + arayF[i] * (n - i) * pow(temp, n - i - 1);
        arayF1[i] = arayF[i] * (n - 1);
    }
    return sum;
}

//Hàm tính đạo hàm cấp 2 của hàm số tại một điểm
double daoHamCap2Tai(double temp) {
    double sum = 0;
    for (int i = 0; i <= n - 1; i++) {
        sum = sum + arayF1[i] * (n - i - 1) * pow(temp, n - i - 2);
    }
    return sum;
}

//Hàm tìm bán kính khoảng nghiệm
float banKinhNghiem() {
    float maX = arayF[0];
    float R;
    for (int i = 0; i < n + 1; ++i) {
        if (fabs(arayF[i]) >= maX) {
            maX = fabs(arayF[i]);
        }
    }
    R = 1 + (maX / fabs(arayF[0]));
    return R;
}

//Hàm tìm cận trên miền chứa nghiệm thực
float canTren() {
    float temp = 0;
    double arrT[100];
    int j = 0, index = 0;
    if (arayF[0] < 0) {
        cT = banKinhNghiem();
    } else if (arayF[0] > 0) {
        for (int i = 1; i < n + 1; ++i) {
            if (arayF[i] < 0) {
                arrT[j] = arayF[i];
                j++;
            }
        }
        for (int i = 0; i < j + 1; ++i) {
            if (fabs(arrT[i]) >= temp) {
                temp = fabs(arrT[i]);
            }
        }
        int i = 0;
        do {
            if (arayF[i] < 0) {
                index = i;
                break;
            }
            i++;
        } while (i <= n);
        if (index == n) {
            if (arayF[n] < 0){
                cT = 1 + pow((temp / arayF[0]), (1.0 / index));
            } else {
                cT = 0;
            }
        } else if (index == 0){
            cT = 0;
        } else  cT = 1 + pow((temp / arayF[0]), (1.0 / index));
    }
    return cT;
}

//Hàm tìm cận dưới miền chứa nghiệm thực
float canDuoi() {
    cD = -1 * banKinhNghiem();
    return cD;
}

//Gradient descent
void cucTriFx(float x0) {
    int j = 0;
    for (int i = 0; i < (n - 1) * 2; ++i) {
        if (x0 > cT){
            break;
        }
        while (1){
            if (x0 > cT){
                break;
            }
            x0 = x0 + 0.0005 * fabs(daoHamTai(x0));
            if (fabs(daoHamTai(x0)) < 0.001){
                arayCT[j] = x0;
                j++;
                x0 = x0 + 0.001;
                continue;
            }
        }
    }
    sCT = j;
}

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
    printf("\n");
    printf("\t\t\t+------------------+--------------------+----------------------+\n");
    printf("\t\t\t|  Khoang phan ly  |         a          |           b          |\n");
    printf("\t\t\t+------------------+--------------------+----------------------+\n");
    for (int i = 0; i < n * 2; ++i) {
        if ((arrKPL[i].a != 0) || (arrKPL[i].b != 0)) {
            printf("\t\t\t|         %d        |         %1.2f      |          %1.2f       |\n", index, arrKPL[i].a,
                   arrKPL[i].b);
            printf("\t\t\t+------------------+--------------------+----------------------+\n");
            index++;
        }
    }
}

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
        printf("\t\t\t+----+---------------+---------------+---------------+---------+----------------+\n");
        printf("\t\t\t|  i |       a       |        b      |    x=(a+b)/2  |f(a).f(x)|  |b - a| < esl |\n");
        printf("\t\t\t+----+---------------+---------------+---------------+---------+----------------+\n");
        while (temp > ssCD) {
            j++;
            c = (arrKPL[i].b + arrKPL[i].a) / 2;
            if (giaTriHamSoTai(c) == 0) {
                printf("Nghiem cua phuong trinh la: %f", c);
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
                    break;
                }
                printf("\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    -    |      false     |\n",count,arrKPL[i].a,arrKPL[i].b,c);
            } else if (giaTriHamSoTai(c) * giaTriHamSoTai(arrKPL[i].a) > 0) {
                if (temp < ssCD){
                    printf("\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    +    |      true      |\n",count,arrKPL[i].a,arrKPL[i].b,c);
                    break;
                }
                printf("\t\t\t| %2d | %4.10f | %4.10f | %4.10f |    +    |      false     |\n",count,arrKPL[i].a,arrKPL[i].b,c);
            }
            count ++;
        }
        printf("\t\t\t+----+---------------+---------------+---------------+---------+----------------+\n");
        count = 0;
        printf("\n x= %.15f", c);
        printf("\n sai so= %.15f\n", temp);
    }
}

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

            }
            if( check > ssDC){
                printf("\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          false         |\n",count,c,temp,check);
            }
            count ++;

        }
    }

}

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
        } else if (arrKPL[i].b * daoHamCap2Tai(arrKPL[i].b > 0)) {
            temp = arrKPL[i].b - (giaTriHamSoTai(arrKPL[i].b) / daoHamTai(arrKPL[i].b));
            printf("Chon xap xi dau la can tren cua khoang phan li, giao diem giua tiep tuyen tai xap xi dau voi truc hoanh x0= %f \n", temp);
        }
        check = fabs(giaTriHamSoTai(temp));
        printf("\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
        printf("\t\t\t|  i |         xn         |        xn-1        |       sai so       |       sai so < ssDC    |\n");
        printf("\t\t\t+----+--------------------+--------------------+--------------------+------------------------+\n");
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
            }
            if (check > ssTT) {
                printf("\t\t\t| %2d | %3.15f | %4.15f | %4.16f |          false         |\n",count,temp,tempss,check);
            }
            count ++;
        }
    }
}

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
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].a = arrKPL1[i].a;
                    arrKPL[i].b = arrKPL1[i].b;
                }
                printf("Su dung phuong phap chia doi thu gon cac khoang phan li nghiem da cho ta duoc: \n");
                chiaDoi(1e-10);
                break;
            case 2:
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].a = arrKPL1[i].a;
                    arrKPL[i].b = arrKPL1[i].b;
                }
                printf("Su dung phuong phap day cung thu gon cac khoang phan li nghiem da cho ta duoc: \n");
                dayCung(1e-10);
                break;
            case 3:
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].a = arrKPL1[i].a;
                    arrKPL[i].b = arrKPL1[i].b;
                }
                printf("Su dung phuong phap tiep tuyen thu gon cac khoang phan li nghiem da cho ta duoc: \n");
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

//Ruts gọn
void main() {
    int choose;
    float buocNhay;
    float ssCD;
    nhapHamSo();
    printf("Ham so da cho co nghiem nam trong mat tron tam O ban kinh R=[%f] o trong mat phang phuc", banKinhNghiem());
    printf("\nCan tren va can duoi cua mien chua nghiem thuc: \nCan tren =[%f], Can duoi =[%f]", canTren(), canDuoi());
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
                for (int i = 0; i < n; ++i) {
                    arrKPL[i].b = 0;
                    arrKPL[i].a = 0;
                }
                buocNhay = 0;
                ssCD = 0;

                // Tìm khoảng phân ly nghiệm từ bán kính nghiệm và cận trên cận dưới miền chứa nghiệm.
                buocNhay = (cT-cD)/100;
                printf("Voi khoang cach k = 1/100 khoang chua nghiem ta su dung thuat toan vet can de tim khoang phan ly nghiem duoc:");
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
                printf("Su dung thuat toan Gradient Descent tim cuc tri cua ham so da cho ta duoc:");
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
                    }
                    if ((arayCT[i] == 0) && (daoHamTai(arayCT[i]) == 0)){
                        printf("\n Tai x = [%f] ham so da cho co 1 cuc tri",arayCT[i]);
                    }
                }
                for (int i = 0; i < sCT; ++i) {
                    if (arayCT[i] != 0){
                        if (fabs(giaTriHamSoTai(arayCT[i])) < 0.001){
                            printf("\nCuc tri x = [%f] la mot nghiem cua ham so da cho",arayCT[i]);
                        }
                    }
                    if ((arayCT[i] == 0) && (daoHamTai(arayCT[i]) == 0)){
                        if (fabs(giaTriHamSoTai(arayCT[i])) < 0.001){
                            printf("\nCuc tri x = [%f] la mot nghiem cua ham so da cho",arayCT[i]);
                        }
                    }
                }
                printf("\n Voi cac cuc tri da tim duoc ta co the xet cac khoang phan ly nghiem sau day:\n");
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
                for (int i = 0; i < n * 2; ++i) {
                    if (giaTriHamSoTai(arrKPL[i].a) * giaTriHamSoTai(arrKPL[i].b) > 0){
                        continue;
                    }
                    if ((arrKPL[i].a != 0) || (arrKPL[i].b != 0)) {
                        printf("\t\t\t|         %d        |         %1.2f      |          %1.2f       |\n", index, arrKPL[i].a,arrKPL[i].b);
                        printf("\t\t\t+------------------+--------------------+----------------------+\n");
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
}
