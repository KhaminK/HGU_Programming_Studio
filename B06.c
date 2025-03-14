#include <stdio.h>

int studentSum(int s[5][3], int number);
//파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
//리턴값 : 해당 학생의 총점
char getGrade(float score);
//파라미터 : 평균 점수(score) 
//리턴값 : 해당 평균 점수의 등급 ('A','B','C','D','F')
int classSum(int s[5][3], int number);
//파라미터 : 점수배열(s)과 과목번호(0,1,2) 
//리턴값 : 해당 과목의 총점

int main(){
    int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
    int sum_student[5]; // 학생별 총점
    float average_student[5];  // 학생별 평균
    char grade[5]; // 학생별 등급 

    int sum_class[3] = {0}; // 과목별 총점
    float average_class[3]; // 과목별 평균
    char class_name[3][20] = {"Korean", "English", "Math"};

    for(int i = 0; i < 5; i++){
        sum_student[i] = studentSum(jumsu, i);
        average_student[i] = sum_student[i]/3.0;
        grade[i] = getGrade(average_student[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("%d) %d %.1f %c\n", i+1, sum_student[i], average_student[i], grade[i]);
    }

    for (int j = 0; j < 3; j++){
        sum_class[j] = classSum(jumsu, j);
        average_class[j] = sum_class[j]/5.0;
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }

    return 0;
}

int studentSum(int s[5][3], int number){
    int total = 0;
    for (int i = 0; i < 3; i++){
        scanf("%d", &s[number][i]);
        total += s[number][i];
    }

    return total;
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

int classSum(int s[5][3], int number){
    int sum = 0;
    for (int i = 0; i < 5; i++){
        sum += s[i][number];
    }
    return sum;
}