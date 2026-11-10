#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SUBJECT 2



/* mainä÷êî------------------------------------------------------------------ */
int main(void){

    /*file handling*/
    FILE *fp = fopen("GPA.txt", "a");

    if(fp == NULL){
        printf("Error opening file!\n");
        return 1;
    };


   
 

    int totalPoint =0;
    int totalCredit = 0;
    int gradePoint[SUBJECT];
    char subject[SUBJECT][200];
    char upperSubject[SUBJECT][200];
    int mark[SUBJECT];
    int credit[SUBJECT];
    double GPA;
    int id = 0;


    for(int i = 0; i < SUBJECT ; i++){
        //name
        //marks
        //credit

        printf("Enter Subject: ");
        scanf(" %199[^\n]", subject[i]);

        int j=0;
        while(subject[i][j] != '\0'){
            upperSubject[i][j] = toupper((unsigned char)subject[i][j]);
            j++;
        }
        upperSubject[i][j] = '\0'; // NUll-terminate the string


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

        fprintf(fp, "Subject%d:%s\n",i+1, upperSubject[i]);
        fprintf(fp, "Mark%d: %d\n",  i+1, mark[i]);
        fprintf(fp, "GradePoint%d: %d\n", i+1, gradePoint[i]);
        fprintf(fp, "Credit%d: %d\n", i+1, credit[i]);


        
        //sum of all point and credit
        totalPoint += gradePoint[i] * credit[i];
        totalCredit += credit[i];
    }


    //counter how many user input 
    id ++;


    printf("---------------------------------------------------------------------\n");
    //use loop to result
    printf("   %-27s %12s %12s %12s\n","Subject", "Marks", "Grade", "Credits");
    for(int j = 0; j < SUBJECT; j++){ 
        printf("%d. %-26s",j+1,upperSubject[j]);
        printf("%12d", mark[j]);
        printf("%12d", gradePoint[j]);
        printf("%12d", credit[j]);
        printf("\n");
    }
    printf("---------------------------------------------------------------------\n");

    printf("*TotalPoint: %d\n", totalPoint);
    printf("*TotalCredit: %d\n", totalCredit);

    //GPA calculation
    if (totalCredit > 0) {
        GPA = (double) totalPoint / totalCredit;
    } else {
        GPA = 0.00;
    }
    printf("\n===== GPA Results =====\n");
    printf("*Your GPA: %.2f\n", GPA);


    //file shoow in txt
    fprintf(fp,"TotalPoint: %d\n", totalPoint);
    fprintf(fp, "TotalCredit: %d\n", totalCredit);
    fprintf(fp, "GPA: %.2f\n", GPA);
      //store data to file
    fclose(fp);

    //Read saved information from file
    fp = fopen("GPA.txt", "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        return 1;
    }
    int filenumber;
    for(int j = 0; j < id-1 ; j++){
        for(int i = 0; i < SUBJECT; i++){
        fscanf(fp, "Subject%d: %199[^\n]", &filenumber, upperSubject[i]);
        fscanf(fp, "Mkar%d: %d\n", &filenumber, &mark[i]);
        fscanf(fp, "GradePoint%d: %d\n", &filenumber, &gradePoint[i]);
        fscanf(fp, "Credit%: %d\n", &filenumber, &credit[i]);
    }
    }

    for(int j = 0; j < id-1 ; j++){
        fscanf(fp, "TotalPoint: %d\n", &totalPoint);
        fscanf(fp, "TotalCredit: %d\n", &totalCredit);
        fscanf(fp, "GPA: %lf\n", &GPA);
    }

    fclose(fp);

    printf("\n--------GPA Reulst from TXT file-------");
    for(int j = 0; j < id ; j++){
        for(int i = 0; i < SUBJECT; i++){
        printf("\nSubject%d: %s", i+1, upperSubject[i]);
        printf("\nMark%d: %d\n", i+1, mark[i]);
    }
    }
    printf("GPA: %.2f", GPA);



    return 0;

}