#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int n; //Bậc của đa thức
double arayF[10]; //Mảng chứa hệ số của đa thức
double arayCT[20]; //Mảng chứa x CT
float cT, cD;

typedef struct khoangPhanLy {
    double a;
    double b;
} kpl;

kpl arrKPL[20]; //Mảng chứa khoảng phân ly của đa thức

// Hàm nhập hệ số của phương trình y = f(x)
void nhapHeSo(int n) {
    int i = 0;
    for (i = 0; i <= n; i++) {
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
    nhapHeSo(n);
    printf("\t ham so: y= f(x)= ");
    for (int i = 0; i <= n; ++i) {
        if (i == n) {
            printf("%.2f\n", arayF[i]);
        } else {
            printf("%.2fx^[%d]+", arayF[i], n - i);
        }
    }
}

//Hàm in ra hàm số đa thức
void xuatHS() {
    printf("\t ham so:");
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

// Ham tinh dao ham cua ham so tai mot diem
double daoHamTai(double temp) {
    double sum = 0;
    for (int i = 0; i <= n - 1; i++) {
        sum = sum + arayF[i] * (n - i) * pow(temp, n - i - 1);
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
    float temp = 0, index = 0;
    double arrT[100];
    int j = 0;
    if (arayF[0] < 0) {
        cT = banKinhNghiem();
    } else if (arayF[0] > 0) {
        for (int i = 0; i < n + 1; ++i) {
            if (arayF[i] < 0) {
                arrT[j] = arayF[i];
                j++;
            }
        }
        for (int i = 0; i < j; ++i) {
            if (fabs(arrT[i]) >= temp) {
                temp = fabs(arrT[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (arayF[i] < 0) {
                index = i;
                break;
            }
        }
        if (index == n) {
            if (arayF[n] > 0) {
                cT = 0;
            }
        } else if (index == 0){
            cT = 0;
        } else cT = 1 + pow((temp / arayF[0]), (1.0 / index));
    }
    return cT;
}

//Hàm tìm cận dưới miền chứa nghiệm thực
float canDuoi() {
    cD = -1 * banKinhNghiem();
    return cD;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
