#include <stdio.h>
#include <string.h>

int main() {
    int index1, index2, total;
    char temp[100];
    char words[100][50];    // Fixed array used to store input
    printf("Total amount of words (max 100): "); // Limits strings when getting input
    scanf("%d", &total);
    
    for(index1 = 0; index1 < total; index1++) {
        scanf("%s", words[index1]);
    }

    for(index1 = 0; index1 < total - 1; index1++) {
        for(index2 = index1 + 1; index2 < total; index2++) {
            if(strcmp(words[index1], words[index2]) > 0) { //First Run: strcmp(words[0], words[1])
                strcpy(temp, words[index1]);    // Copy words[index1] to a temporary location 
                strcpy(words[index1], words[index2]);   // Overwrite words[index1] with words[index2]
                strcpy(words[index2], temp);    // Copy words[index1] to a temporary location 
            }
        }
    }

    FILE * fptr = fopen("sort.txt", "w");

    fprintf(fptr, "Sorted List\n===============\n\n");
    for(index1 = 0; index1 < total; index1++) {
        fprintf(fptr, "%s\n", words[index1]);
    }
    fclose(fptr);
    printf("\nList sorted in file sort.txt\n");
}