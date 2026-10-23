#include<stdio.h>
#define SUBJECT 5


int main(void){

    int totalPoint =0;
    int totalCredit = 0;
    int gradePoint[SUBJECT];
    char subject[SUBJECT][200];
    int mark[SUBJECT];
    int credit[SUBJECT];
    double GPA;

    printf("Enter");

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
        
        //grade level 
        if(mark[i]>= 90){
            gradePoint[i]= 4;
        }else if(mark[i]>= 80){
            gradePoint[i] = 3;
        }else if(mark[i] >= 70){
            gradePoint[i] = 2;
        }else if(mark [i]>= 60){
            gradePoint[i] = 1;
        }else{
            gradePoint[i] = 0;
        }

        //sum of all point and credit
        totalPoint += gradePoint[i] * credit[i];
        totalCredit += credit[i];
    }

    printf("\n===== GPA Results =====\n");

    //GPA calculation
    GPA = (double) totalPoint / totalCredit;

    //use loop to result

    for(int j = 0; j < SUBJECT; j++){ 
        printf("Subject%d: %s\n", j+1, subject[j]);
        printf("Makr: %d\n", mark[j]);
        printf("Credit: %d\n\n", credit[j]);
    }

    printf("TotalPoint: %d\n", totalPoint);
    printf("TotalCredit: %d\n", totalCredit);
    printf("Your GPA: %.2f\n", GPA);

   return 0;
}
