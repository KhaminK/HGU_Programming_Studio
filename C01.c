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


int main(){
    struct st_person* one; // 학생 1명의 데이터
    char country[5]; // 국적입력을 위한 문자열

    one = (struct st_person*)malloc(sizeof(struct st_person));
    scanf("%s %d %s %d", one->name, &one->gender, country, &one->birthyear);
    one->country = getCountry(country);
    printInfo(one);

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
    printf("%s (%s, age:%d, from %s)", p->name, gender_name[p->gender], 2025-p->birthyear, country_name[p->country]);
}