#include<stdio.h>
#include<string.h>
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
        scanf(" %199[^\n]", subject[i]);

        for(int k=0; k <= sizeof(subject[i]); k++){
            printf("%s", toupper(subject[k]));
        }

        printf("%s\n", subject[i]);

        printf("Enter marks: ");
        scanf("%d", &mark[i]);
        while(mark[i] >100 || mark[i] < 0){
            printf("Enter marks(0~100)!: ");
            scanf("%d", &mark[i]);
        }

       

        printf("Enter credit: ");
        scanf("%d", &credit[i]);
        while(credit[i]>4 || credit[i]<1){
            printf("Enter credit(1~4)!: ");
            scanf("%d", &credit[i]);
        }
        
        printf("marks is :%d\n", mark[i]);
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

        printf("Your grade point is : %d\n", gradePoint[i]);

        //sum of all point and credit
        totalPoint += gradePoint[i] * credit[i];
        printf("total point is: %d\n", totalPoint);

        totalCredit += credit[i];
    }


    //use loop to result
    printf("    Subjects        Marks    Points    Credits\n");
    for(int j = 0; j < SUBJECT; j++){ 
        printf(" %d. %-11s",j+1,subject[j]);
        printf("    %4d", mark[j]);
        printf("     %4d", gradePoint[j]);
        printf("       %4d", credit[j]);
        printf("\n");
    }
    printf("-----------------------------------------------\n");

    printf("TotalPoint: %21d\n", totalPoint);
    printf("TotalCredit: %31d\n", totalCredit);

    //GPA calculation
    if (totalCredit > 0) {
        GPA = (double) totalPoint / totalCredit;
    } else {
        GPA = 0.0;
    }
    printf("\n===== GPA Results =====\n");
    printf("Your GPA: %.2f\n", GPA);

   return 0;
}
