#include <stdio.h>

int main(){
    int num = 0;
    int height, weight; // 신장(cm), 체중(kg) 
    float bmi; // 비만도 수치 
    int count = 0;

    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        scanf("%d %d", &height, &weight);
        bmi = weight / (height*height*0.01*0.01);
        if (bmi >= 25){
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}