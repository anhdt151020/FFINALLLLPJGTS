//
// Created by TuanAnh on 9/11/2021.
//

#ifndef FFINALLPROJECT_BANKINH_H
#define FFINALLPROJECT_BANKINH_H

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


#endif //FFINALLPROJECT_BANKINH_H
