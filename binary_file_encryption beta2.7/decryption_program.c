#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "decryption.h"
#include "folder_decryption.h"
#include "ui.h"

int main(void){
    int key = key_generation();

    int ch, a;
    home();
    while(1){
        if(_kbhit()){
            ch = _getch();
            if(ch == 49){
                home_1();
                a = ch;
            }
            else if(ch == 50){
                home_2();
                a = ch;
            }
            else if(ch == 51){
                home_3();
                a = ch;
            }
            else if(ch == 13 && a == 49){
                ui_1();
            }
            else if(ch == 13 && a == 50){
                ui_2();
            }
            else if(ch == 13 && a == 51){
                ui_3();
                int key_input;
                scanf("%d", &key_input);
                //p=11, q=17, n=p*q = 187, (p-1)(q-1) = 160, e=7, d=23, key = 183
                if(key_input == key){
                    key_true();
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
                    remove("RSA_key.key");
                    complete();
                    return 0;
                }
                else{
                    key_false();
                }
            }
        }
    }

    return 0;
}
