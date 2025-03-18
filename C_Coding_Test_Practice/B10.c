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

struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index);

int countGrade(struct st_jumsu* data[], int size, char grade);


int main(){
    struct st_jumsu* jdata[20]; // 최대 20명의 점수 데이터
	int sum_class[3]; // 과목별 총점
	float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};
	struct st_jumsu* first[3];
	char grades[5] = "ABCDF";
	int count_grade[5];
	int count;

    scanf("%d", &count);
    for (int i = 0; i < count; i++){
        jdata[i] = (struct st_jumsu*) malloc(sizeof(struct st_jumsu));
        makeJumsu(jdata[i]);
    }

    for (int i = 0; i < count; i++){
        printf("%d) ", i+1);
        printJumsu(jdata[i]);
    }

    for (int j = 0; j < 3; j++){
        struct st_jumsu* best = firstRanking(jdata, count, j);
        printf("[%s] %s %d\n", class_name[j], best->name, best->jumsu[j]);
    }

    for (int i = 0; i < 5; i++){
        int returned = countGrade(jdata, count, grades[i]);
        printf("[%c] %d\n", grades[i], returned);
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
    printf("%s - %d %.1f %c\n", p->name, p->sum, p->avg, p->grade);
}

struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index){
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < size; i++){
        if (data[i]->jumsu[index] > max){
            max = data[i]->jumsu[index];
            max_index = i;
        }
    }
    return data[max_index];
}

int countGrade(struct st_jumsu* data[], int size, char grade){
    int total = 0;
    for (int i = 0; i < size; i++){
        if (data[i]->grade == grade){
            total++;
        }
    }
    return total;
}