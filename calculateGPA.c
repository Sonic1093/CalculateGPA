#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SUBJECT 2

////save results to file
int saveToFile(const char *filename, char subject[][200], int mark[], int gradePoint[], int credit[], int totalPoint, int totalCredit, double GPA){
    FILE *fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Error: cannot open file %s\n", filename);
        return 0;
    }
 
    fprintf(fp, "---------------------------------------------------------------------\n");
    fprintf(fp, "   %-27s %12s %12s %12s\n", "Subject", "Marks", "Grade", "Credits");
    for(int k = 0; k < SUBJECT; k++){
        fprintf(fp, "%d. %-26s%12d%12d%12d\n", k+1, subject[k], mark[k], gradePoint[k], credit[k]);
    }
    fprintf(fp, "---------------------------------------------------------------------\n\n");
    fprintf(fp, "*TotalPoint: %d\n", totalPoint);
    fprintf(fp, "*TotalCredit: %d\n", totalCredit);
    fprintf(fp, "*Your GPA: %.2f\n", GPA);
 
    if(fclose(fp) != 0){
        printf("Error: failed to close file %s\n", filename);
        return 0;
    }
    return 1;
}


/* mainŠÖ”------------------------------------------------------------------ */
int main(void){

    int totalPoint =0;
    int totalCredit = 0;
    int gradePoint[SUBJECT];
    char subject[SUBJECT][200];
    char upperSubject[SUBJECT][200];
    int mark[SUBJECT];
    int credit[SUBJECT];
    double GPA;

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


        //sum of all point and credit
        totalPoint += gradePoint[i] * credit[i];
        totalCredit += credit[i];
    }

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
    printf("---------------------------------------------------------------------\n\n");

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


      //store data to file
    if(saveToFile("gpa_result.txt", subject, mark, gradePoint, credit, totalPoint, totalCredit, GPA)){
        printf("\nData saved to gpa_result.txt\n");
    }
    
    
    return 0;
}
