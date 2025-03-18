#include <stdio.h>

int bmiLevel(int height, int weight);

int main(){
    int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
    int bmi_level[10]; // 10명의 비만등급(0~4)
    int count = 0; // 비만인 사람의 숫자
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};
    
    for (int i = 0; i < 10; i++){
        scanf("%d %d", &height[i], &weight[i]);
        int result = bmiLevel(height[i], weight[i]);
        if (result >= 3){
            bmi_level[count] = i;
            count++;
        }
    }
    
    for (int i = 0; i < count; i++){
        printf("%d ", bmi_level[i]+1);
    }
    printf("\n%d\n", count);
    

    


}

int bmiLevel(int height, int weight){
    float bmi = weight / (height*height*0.01*0.01);
    if (bmi < 18.5){
        return 0;
    } else if (bmi < 23.1){
        return 1;
    } else if (bmi < 25.2){
        return 2;
    } else if (bmi < 30.3){
        return 3;
    } else{
        return 4;
    }
}