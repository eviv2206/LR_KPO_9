#include <stdio.h>

typedef struct student{
    char surname[8];
    char group[7];
    char marks[6];
}student;

int main() {
    FILE *f1 = fopen("D:/1.txt", "r");

    int amount = 0;
    char surname[7], group[6], marks[5];
    while (!feof(f1)) {
        fscanf(f1, "%s" , surname);
        fscanf(f1, "%s" ,group);
        fscanf(f1,"%s", marks);
        ++amount;
    }

    student students[amount];

    fclose(f1);

    f1 = fopen("D:/1.txt", "r");
    int l = 0;

    while (!feof(f1)) {
        fscanf(f1, "%s" ,students[l].surname);
        fscanf(f1, "%s" ,students[l].group);
        fscanf(f1, "%s", students[l].marks);
        ++l;
    }

    fclose(f1);




    int counterDebtsStudents = 0;
    for (int i = 0; i < amount; ++i) {
        int counterDebts = 0;
        for (int j = 0; j < 5; ++j){
            if(students[i].marks[j] - '0' < 4){
                counterDebts++;
            }
        }
        if(counterDebts){
            counterDebtsStudents++;
        }
    }

    student failedStudents[counterDebtsStudents];
    int numOfDebts[counterDebtsStudents];

    int k = 0;
    for (int i = 0; i < amount; ++i){
        int counterDebts = 0;
        for (int j = 0; j < 5; ++j){
            if(students[i].marks[j] - '0' < 4){
                counterDebts++;
            }
        }
        if(counterDebts) {
            failedStudents[k] = students[i];
            numOfDebts[k] = counterDebts;
            k++;
        }
    }

    FILE *f2 = fopen("D:/2.txt", "w");

    for (int j = 0; j < counterDebtsStudents; ++j) {
        fprintf(f2, "%s ", failedStudents[j].surname);
        fprintf(f2, "%6.6s ", failedStudents[j].group);
        fprintf(f2, "%d", numOfDebts[j]);
        fprintf(f2, "%s", "\n");
    }

    fclose(f2);
    printf("All done");
    return 0;
}
