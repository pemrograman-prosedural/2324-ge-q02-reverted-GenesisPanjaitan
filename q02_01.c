// 12S23003 - Chrismansyah T Siahaan
// 12S23012 - Genesis Tombak Dapot Tua Panjaitan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/gender.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    char input [100];
    int n = 0;
    int size = 0;
    struct dorm_t *dorm = malloc(size * sizeof(struct dorm_t));
    int p = 0;
    int size2 = 0;
    struct student_t *mahasiswa = malloc(size2 * sizeof(struct student_t));
    char *token;

    while(1)
    {
        fgets(input, sizeof input, stdin);
        while(1)
        {
            if(input[strlen(input) - 1] == '\n' || input[strlen(input) - 1] == '\r')
            {
                input[strlen(input) - 1] = '\0';
            }
            else
            {
                break;
            }
        }

        token = strtok(input, "#");
        if(strcmp(token, "---") == 0)
        {
            break;
        } else if(strcmp(token, "dorm-add") == 0)
        {
            size++;
            dorm = realloc(dorm, size * sizeof(struct dorm_t));
            dorm[n] = create_dorm(input);
            n++;
        } else if(strcmp(token, "dorm-print-all") == 0)
        {
            for(int i = 0; i < n; i++)
            {
                print_dorm(dorm[i]);
            }
        } else if(strcmp(token, "student-add") == 0)
        {
            size2++;
            mahasiswa = realloc(mahasiswa, size2 * sizeof(struct student_t));
            mahasiswa[p] = create_student(input);
            p++;
        } else if(strcmp(token, "student-print-all") == 0)
        {
            for(int i = 0; i < p; i++)
            {
                print_student(mahasiswa[i]);
            }
        }
    }
    free(dorm);
    free(mahasiswa);
    return 0;
}
