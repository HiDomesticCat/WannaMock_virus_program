void decryption(char *encryption_file_position, char *original_file_position);
int powMod(int, int, int);
int key_generation(void);

int key;

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

void decryption(char *encryption_file_position, char *original_file_position){
    FILE *encryption_file_read, *original_file_read;
    encryption_file_read = fopen(encryption_file_position, "rb");
    original_file_read = fopen(original_file_position, "wb");

    unsigned char ch;
    while(!feof(encryption_file_read)){
    fread(&ch, sizeof(ch), 1, encryption_file_read);
    //unsigned char ch2 = ch;//
        if(!feof(encryption_file_read)){
            //解密的地方
            ch = powMod(ch, key, 187);
            fwrite(&ch, sizeof(ch), 1, original_file_read);
        }
        //printf("%lld %lld\n", ch, ch2);//
    }
    //system("pause");//
    fclose(encryption_file_read);
    fclose(original_file_read);
    remove(encryption_file_position);
}

int key_generation(void){
    int ch;
    FILE *key_get = fopen("RSA_key.key", "r");
    while((ch = fgetc(key_get)) != EOF){
        key = key * 10 + (ch-'0');
    }
    fclose(key_get);

    return key;
}
