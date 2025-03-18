#include <stdio.h>
#include <stdlib.h>

struct st_jumsu{
    char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
    int jumsu[3]; // 3과목 점수 (국, 영, 수)
    int sum;	// 총점
    float avg;	// 평균
    char grade;	// 평균에 대한 등급
};

char getGrade(float score);

void makeJumsu(struct st_jumsu* p);

void printJumsu(struct st_jumsu* p);

int getClassSum(struct st_jumsu* data[], int size, int index);


int main(){
    struct st_jumsu* jdata[20]; // 최대 20명의 점수 데이터
    int sum_class[3]; // 과목별 총점
    float average_class[3]; // 과목별 평균
    char class_name[3][20] = {"Korean", "English", "Math"};
    int num;

    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        jdata[i] = (struct st_jumsu*) malloc(sizeof(struct st_jumsu));
        makeJumsu(jdata[i]);
    }

    for (int i = 0; i < num; i++)printJumsu(jdata[i]);

    for (int j = 0; j < 3; j++){
        sum_class[j] = getClassSum(jdata, num, j);
        average_class[j] = sum_class[j]/(num*1.0);

        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);    
    }


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

void makeJumsu(struct st_jumsu* p){
    scanf("%s %d %d %d",p->name, &p->jumsu[0], &p->jumsu[1], &p->jumsu[2]);
    p->sum = p->jumsu[0]+p->jumsu[1]+p->jumsu[2];
    p->avg = p->sum / 3.0;
    p->grade = getGrade(p->avg);
}

void printJumsu(struct st_jumsu* p){
    printf("%s %d %.1f %c\n", p->name, p->sum, p->avg, p->grade);
}

int getClassSum(struct st_jumsu* data[], int size, int index){
    int total = 0;
    for (int i = 0; i < size; i++){
        total += data[i]->jumsu[index];
    }
    return total;
}