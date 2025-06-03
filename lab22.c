#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main() {
    system("chcp 65001");
    FILE *input_file, *output_file;
    float matrix[ROWS][COLS];
    float result_vector[ROWS] = {0};

    input_file = fopen("vhid.txt", "r");
    if (input_file == NULL) {
        printf("Помилка відкриття файлу vhid.txt\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (fscanf(input_file, "%f", &matrix[i][j]) != 1) {
                printf("Помилка читання даних з файлу\n");
                fclose(input_file);
                return 1;
            }
        }
    }
    fclose(input_file);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] < 0) {
                result_vector[i] += matrix[i][j];
            }
        }
    }

    output_file = fopen("exit.txt", "w");
    if (output_file == NULL) {
        printf("Помилка створення файлу exit.txt\n");
        return 1;
    }
 
    for (int i = 0; i < ROWS; i++) {
        fprintf(output_file, "%.2f\n", result_vector[i]);
    }
    fclose(output_file);
    
    printf("Обробка завершена успішно. Результат записано у файл exit.txt\n");
    
    return 0;
}