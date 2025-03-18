#include <stdio.h>

int bmiLevel(int height, int weight);
//파라미터: height: 신장(cm), weight: 체중(kg)
//수행내용: 비만도 계산 후 비만등급을 판정한다.
//리턴값: 비만등급 (0~4): 0 (Underweight), 1 (Normal weight), 2 (Overweight), 3 (Mild obesity), 4 (Severe obesity)


int main(){
	int height[20], weight[20]; // 최대 20명의 신장(cm), 체중(kg)
	int bmi_level[20]; // 최대 20명의 비만등급(0~4)
	int count = 0, all; // 비만인 사람의 숫자, 총 인원수

	// Your code here.
    scanf("%d", &all);
    for(int i = 0; i < all; i++){
        scanf("%d %d", &height[i], &weight[i]);
        int reuslt = bmiLevel(height[i], weight[i]);
        if (reuslt >= 3){
            bmi_level[count] = i;
            count++;
        }
    }
    printf("%d/%d", count, all);

	return 0;
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
