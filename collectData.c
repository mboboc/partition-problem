#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *);

char *ft_itoa(int a) {
    char number[4];
    char *return_number;
    int digit;
    char char_digit;
    int i;
    
    if(a <= 9) {
        char_digit = a + '0';
        number[0] = char_digit;
        number[1] = '\0';
    } else {
        i= 0;
        while (a != 0) {
            digit = a % 10;
            char_digit = digit + '0';
            printf("%d\n",digit);
            number[i] = char_digit;
            i++;
            a = a / 10;
        }
    }
    return_number = (char*)malloc(4 * sizeof(char));
    return_number = strrev(number);
    return (return_number);
}

char *strrev(char *str) {
    char *p1, *p2;
    
    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

int main () {
    FILE *fid;
    char name[] = "out/test";
    char end_of_name[] = ".out";
    char *full_name;
    char *string_number;
    int *array;
    int i;

    array = (int *)malloc(sizeof(int) * 201);
    full_name = (char *)calloc(20, sizeof(int));
    if(full_name == NULL) {
        printf("Nu s-a alocat memorie.");
        return 1;
    }
    if(array == NULL) {
        printf("Nu s-a alocat memorie.");
        return 1;
    }
    string_number = (char *)malloc(sizeof(char) * 4);
    if(string_number == NULL) {
        printf("Nu s-a alocat memorie.");
        return 1;
    }
    for (i = 0; i <= 200; i++) {
        strcat(full_name, name);
        string_number = ft_itoa(i);
        //printf("%s", string_number);
        strcat(full_name, string_number);
        strcat(full_name, end_of_name);
        printf("%s\n", full_name);
        fid = fopen(full_name, "r");
        if(fid == NULL) {
            printf("Nu s-a deschis fisierul.\n");
            return 1;
        }
        fscanf(fid, "%d", &(array[i]));
        fclose;
        full_name[0] = '\0';
    }
    
    i = 0;
    int count = 0;
    while(i <= 200) {
        printf("%d, ", array[i]);
        count = count + array[i];
        /*if(array[i] <= 100) { // && array[i] > 1) {
            count ++;
        }*/
        i++;
    }
    printf("\n******\n");
    printf("%d\n", count/201);

    return 0;
}
