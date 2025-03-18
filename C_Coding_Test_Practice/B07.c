#include <stdio.h>

int studentSum(int s[20][3], int size, int index);
char getGrade(float score);
int classSum(int s[20][3], int size, int index);
int firstRanking(int s[20], int size);

int main(){
	int jumsu[20][3]; // 최대 20명의 3과목 점수를 저장하고 있는 2차원 배열 
	int sum_student[20]; // 최대 20명의 학생별 총점
	float average_student[20];  // 최대 20명의 학생별 평균
	char grade[20]; // 최대 20명의 학생별 등급 

	int first;	// 1등 학생 번호
	int all;	// 인원수

	int sum_class[3]; // 과목별 총점
	float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};

    scanf("%d", &all);

    for(int i = 0; i < all; i++){
        sum_student[i] = studentSum(jumsu, all, i);

        average_student[i] = sum_student[i]/3.0;
        grade[i] = getGrade(average_student[i]);
    }

    for(int i = 0; i < all; i++){
        printf("%d) %d %.1f %c\n", i+1, sum_student[i], average_student[i], grade[i]);
    }

    for (int j = 0; j < 3; j++){
        sum_class[j] = classSum(jumsu, all, j);
        average_class[j] = sum_class[j]/(all*1.0);
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }

    int firstPlace = firstRanking(sum_student, all);
    printf("1st Ranking: %d", firstPlace);

    return 0;
}

//why do we need size?
int studentSum(int s[20][3], int size, int index){
    int total = 0;
    for (int i = 0; i < 3; i++){
        scanf("%d", &s[index][i]);
        total += s[index][i];
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

int classSum(int s[20][3], int size, int index){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += s[i][index];
    }
    return sum;
}

int firstRanking(int s[20], int size){
    int max = -1;
    int maxindex;
    for (int i = 0; i < size; i++){
        if (s[i] > max){
            max = s[i];
            maxindex = i;
        }
    }
    return maxindex+1;
}