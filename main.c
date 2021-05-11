#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n; //Bậc của đa thức
double arayF[10]; //Mảng chứa hệ số của đa thức
double arayCT[18]; //Mảng chứa x CTri
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
            x0 = x0 + 0.005 * fabs(daoHamTai(x0));
            if (fabs(daoHamTai(x0)) < 0.001){
                arayCT[j] = x0;
                j++;
                x0 = x0 + 0.001;
                continue;
            }
        }
    }
}

int main() {
    float x;
    nhapHamSo();
    printf("Ham so da cho co nghiem nam trong mat tron tam O ban kinh R=[%f] o trong mat phang phuc", banKinhNghiem());
    canTren();
    canDuoi();
    printf("\nCan tren va can duoi cua mien chua nghiem thuc: \nCan tren =[%f], Can duoi =[%f]", cT, cD);
    cucTriFx(cD);
    for (int i = 0; i < (n - 1) * 2; ++i) {
        if (arayCT[i] != 0){
            printf("\ntai x= [%f] phuong trinh co cuc tri",arayCT[i]);
        }
    }
}
