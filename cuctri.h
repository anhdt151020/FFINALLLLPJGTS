//
// Created by TuanAnh on 9/11/2021.
//

#ifndef FFINALLPROJECT_CUCTRI_H
#define FFINALLPROJECT_CUCTRI_H

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

#endif //FFINALLPROJECT_CUCTRI_H
