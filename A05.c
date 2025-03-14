#include <stdio.h>

int bmiLevel(int height, int weight);

int main(){
    int height, weight;
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};
    scanf("%d %d", &height, &weight);

    int result = bmiLevel(height, weight);
    printf("%s (%d)", bmi_string[result], result);

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