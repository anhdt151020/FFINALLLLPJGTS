//
// Created by TuanAnh on 9/11/2021.
//

#ifndef FFINALLPROJECT_FX_H
#define FFINALLPROJECT_FX_H

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

FILE *fpop;

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
    fprintf(fpop,"\t ham so: y= f(x)= ");
    for (int i = 0; i <= n; ++i) {
        if (i == n) {
            printf("%.2f\n", arayF[i]);
            fprintf(fpop,"%.2f\n", arayF[i]);
        } else {
            printf("%.2fx^[%d]+", arayF[i], n - i);
            fprintf(fpop,"%.2fx^[%d]+", arayF[i], n - i);
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


#endif //FFINALLPROJECT_FX_H
