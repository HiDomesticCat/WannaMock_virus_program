/*
���:2020/12/6
�@��:HiCat
���e:����e���s�@�A�ѱK�{�����λs�@�C

���:2020/12/12
�@��:HiCat
���e:�ѱK�{�ǧ����A�ѱK�{���e���s�@�����C
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
  printf("    *           **********           *      �A�b����Ƨ��Ҧ�txt���ɦW���ɮ׳��Q�ڥ[�K�F�A\n");
  printf("   *    ****                   ****   *     �p�G�Q�n�^�A���ɮ�                        \n");
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
  printf("�п�J�A������X: ");


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
    printf("    *           **********           *      �K�X���T�A�ɮ׫�_���A�еy���C              \n");
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
    printf("    *           **********           *      ��ƭ״_�����A                            \n");
    printf("   *    ****                   ****   *     �A��txt�ɧ��w��_�C                       \n");
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
