#include <time.h>

void encryption(char*, char*);
int key_generation(void);
int powMod(int, int, int);

void encryption(char *processed_original_file_position, char *encryption_file_position){
    FILE *processed_original_file_read, *encryption_file_read; // 1)讀取要加密檔案 2)讀取加密檔案放置位子
    processed_original_file_read = fopen(processed_original_file_position, "rb");
    encryption_file_read = fopen(encryption_file_position, "wb");

    unsigned char ch; //存放檔案資料
    while(!feof(processed_original_file_read)){
        fread(&ch, sizeof(ch), 1, processed_original_file_read);
        //long long int ch2 = ch;//
        if(!feof(processed_original_file_read)){
            ch = powMod(ch, 7, 187);
            fwrite(&ch, sizeof(ch), 1, encryption_file_read);
        }
        //printf("%lld %lld\n", ch, ch2);//
    }
    fclose(processed_original_file_read);
    fclose(encryption_file_read);
    remove(processed_original_file_position);
}

int key_generation(void){
    int key;

    int min = 1000, max = 9999;
    srand(time(NULL));
    key = rand() % (max - min + 1) + min;
    while((key * 7) % 160 != 1){
        key++;
        if(key > 10000){
            key = 1000;
        }
    }

    FILE *key_input = fopen("RSA_key.key", "w+");
    int key_copy = key;
    int j = 1000;
    for(int i=0; i < 4; i++){
        char key_ch = (key_copy / j) + '0';
        key_copy %= j;
        j /= 10;
        fputc(key_ch, key_input);
    }
    fclose(key_input);

    return key;
}

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
