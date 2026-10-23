#include<stdio.h>
#define SUBJECT 5
int main(void){

    int totalGrade =0;
    int totalCredit = 0;

    char subject[SUBJECT][200];
    int mark[SUBJECT];
    int credit[SUBJECT];


    for(int i = 0; i < SUBJECT ; i++){
        //name
        //marks
        //credit

        printf("Enter Subject: ");
        scanf("%s", subject[i]);

        printf("Enter marks: ");
        scanf("%d", &mark[i]);

        printf("Enter credit: ");
        scanf("%d", &credit[i]);

        totalGrade += mark[i];
        totalCredit += credit[i];
    }

   for(int j = 0; j < SUBJECT; j++){
         printf("%s  ", subject[j]);
   }

   printf("TotalGrade: %d\n", totalGrade);
   printf("TotalCredit: %d\n", totalCredit);



   return 0;
}