#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[20];
    int roll_no;
    float marks;
};

struct student s[10];

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    while(getchar() != '\n');
    
    for(int i = 0; i < n; i++) {
        printf("Enter name %d: ", i+1);
        fgets(s[i].name, 20, stdin);  
        if (s[i].name[strlen(s[i].name)-1] == '\n') {
            s[i].name[strlen(s[i].name)-1] = '\0';
        }
        
        printf("roll number %d: ", i+1);
        scanf("%d", &s[i].roll_no);
        
        printf("marks of %d: ", i+1);
        scanf("%f", &s[i].marks);
        
        while(getchar() != '\n');
    }
    
    printf("Student details:\n");
    for(int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Marks: %.2f\n", s[i].name, s[i].roll_no, s[i].marks);
    }
    
    return 0;
}