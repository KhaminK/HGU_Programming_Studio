#include <stdio.h>

int main(){
    int kor, eng, math; // 국어점수, 영어점수, 수학점수
    int total; // 총점
    float average;  // 평균점수
    char grade; // 등급

    scanf("%d %d %d", &kor, &eng, &math);
    total = kor + eng + math;
    average = total / 3.0;
    printf("%.1f ", average);
    if (average >= 90){
        printf("A");
    }else if(average >= 80){
        printf("B");
    }else if(average >= 70){
        printf("C");
    }else if(average >= 60){
        printf("D");
    }else{
        printf("F");
    }
    return 0;
}