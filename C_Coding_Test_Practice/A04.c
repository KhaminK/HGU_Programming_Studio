#include <stdio.h>

int main(){
    int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
    float bmi[10]; // 10명의 비만도 수치
    int count = 0; // 비만인 사람의 숫자
    int overweight[10];

    for (int i = 0; i < 10; i++){
        scanf("%d %d", &height[i], &weight[i]);
        bmi[i] = weight[i] / (height[i]*height[i]*0.01*0.01);
        if (bmi[i] >= 25){
            overweight[count] = i;
            count++;
        }
    }
    for (int i = 0; i < count; i++){
        printf("%d ", overweight[i]+1);
    }
    printf("\n%d\n", count);

    return 0;
}