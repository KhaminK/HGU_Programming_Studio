#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st_person{
	char name[20]; 	// Name (single word, no duplicates)
	int gender;  	// 0 - Female, 1 - Male
	int country;	// Country code (index of COUNTRY_NAME 0~5)
	int birthyear; 	// Birthyear
};

int getCountry(char* str);
void printInfo(struct st_person* p);
int countGender(struct st_person* data[], int size, int gender);



int main(){
    struct st_person* pdata[20]; // 최대 20명의 데이터
    char country[5]; // 국적입력을 위한 문자열
    char count_gender[2]; // 성별 인원수
    int count;  // 인원수

    scanf("%d", &count);
    for (int i = 0; i < count; i++){
        pdata[i] = (struct st_person*)malloc(sizeof(struct st_person));
        scanf("%s %d %s %d", pdata[i]->name, &pdata[i]->gender, country, &pdata[i]->birthyear);
        pdata[i]->country = getCountry(country);
    }

    for (int i = 0; i < count; i++){
        printf("%d) ", i+1);
        printInfo(pdata[i]);
    }

    for (int j = 0; j < 2; j++){
        countGender(pdata, count, j);
    }
    
    return 0;
}

int getCountry(char* str){
    char country_name[6][5] = {"KR", "US", "JP", "CN", "FR", "--"};
    int num;
    for (num = 0; num< 5; num++){
        if(strcmp(str, country_name[num]) == 0){
            return num;
        }
    }
    return num;
}

void printInfo(struct st_person* p){
    char gender_name[2][10] = {"Female", "Male"};
    char country_name[6][5] = {"KR", "US", "JP", "CN", "FR", "--"};
    printf("%s (%s, age:%d, from %s)\n", p->name, gender_name[p->gender], 2025-p->birthyear, country_name[p->country]);
}

int countGender(struct st_person* data[], int size, int gender){
    char gender_name[2][10] = {"Female", "Male"};
    int count = 0;
    for (int i = 0; i < size; i++){
        if (data[i]->gender == gender){
            count++;
        }
    }
    printf("%s:%d ", gender_name[gender], count);
}