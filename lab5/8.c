/*Лабораторная работа №5. Вариант 49. Задание 8.
Создать вручную англоязычный текстовый файл небольшого объёма. 
Для каждых двух слов из файла определить и вывести на экран, 
какие буквы у них совпадают по наличию, а какие по расположению.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 256

void clear_buffer(char [N]);
int separating_symbol(char);
void clear_from_sames(char [N], char[N]);


int main() {
  FILE *file_8 = fopen("C:/labs/5/file_8.txt", "r");
  if (file_8 == NULL) {
    printf("Error");
    exit(1);
  }

  char current_word[N], previous_word[N], symbol;
  int current_len = 0, previous_len = 0;
  clear_buffer(current_word);
  clear_buffer(previous_word);

  while ((symbol = fgetc(file_8)) != EOF) {
    if (separating_symbol(symbol)) {
      if (previous_len != 0) {
        printf("\nfirst_word: %s and second_word: %s \n", previous_word, current_word);
        printf("same by position letters: \n");
        char p_c, c_c;
        for (int i = 0; i < ((previous_len < current_len) ? previous_len : current_len); i++) {
          p_c = previous_word[i];
          c_c = current_word[i];
          if (p_c == c_c) 
            printf("\t--same '%c' on index %d.\n", c_c, i+1);
        }
        printf("\n");
        char previous_word_c[N], current_word_c[N];
        clear_from_sames(previous_word, previous_word_c);
        clear_from_sames(current_word, current_word_c);
        printf("\nsame by including: \n");
        for (int i = 0; (c_c = current_word_c[i]) != '\0'; i++) {
          for (int j = 0; (p_c = previous_word_c[j]) != '\0'; j++) {
            if (c_c == p_c) printf("%c ", c_c);
          }
        }
        printf("\n");
      }
      if (current_len != 0) {
        previous_len = current_len;
        strcpy(previous_word, current_word);
        clear_buffer(current_word);
      }
      current_len = 0;
      continue;
    }
    current_word[current_len++] = symbol;
  }
  fclose(file_8);
}
void clear_from_sames(char buff[N], char cleared_buffer[N]) {
  int cleared_buffer_len = 0;
  clear_buffer(cleared_buffer);
  for (int i = 0; i < N; i++) {
    int has_same = 0;
    for (int j = 0; j < i; j++)
      if (buff[i] == buff[j]) has_same = 1;
    if (!has_same) 
      cleared_buffer[cleared_buffer_len++] = buff[i];
  }
}

int separating_symbol(char symbol) {
  if (symbol == ' ' || symbol == '.' || symbol == '\n' || symbol == '!' || symbol == '?' || symbol == ';' || symbol == ',')
    return 1;
  return 0;
}

void clear_buffer(char buf[N]) {
  for (int i = 0; i < N; i++) buf[i] = '\0';
}
