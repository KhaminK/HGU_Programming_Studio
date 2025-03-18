#include <stdio.h>

struct st_jumsu{
    char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
    int jumsu[3]; // 3과목 점수 (국, 영, 수)
    int sum;	// 총점
    float avg;	// 평균
    char grade;	// 평균에 대한 등급
};

char getGrade(float score);

int main(){
    struct st_jumsu one;
    int sum_score;
    float average_score;
    scanf("%s %d %d %d", one.name, &one.jumsu[0], &one.jumsu[1], &one.jumsu[2]);

    sum_score = one.jumsu[0]+one.jumsu[1]+one.jumsu[2];
    average_score = sum_score / 3.0;
    printf("%s %d %.1f %c", one.name, sum_score, average_score, getGrade(average_score));
}

char getGrade(float score){
    if (score >= 90){
        return 'A';
    }else if(score >= 80){
        return 'B';
    }else if(score >= 70){
        return 'C';
    }else if(score >= 60){
        return 'D';
    }else{
        return 'F';
    }
}