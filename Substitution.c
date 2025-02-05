#include <cs50.h>
#include <stdio.h>
#include <string.h>
int check_key(string);
string upper(string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("請提供一個命令列參數！\n");
        return 1; // 結束程式，並返回錯誤碼
    }
    string key_check = argv[1];
    string key = argv[1];

    string upper_key = upper(key_check);
    if (check_key(upper_key) != 0)
    {
        return 1;
    }
    string text = get_string("plaintext:  ");
    printf("index = %s\n", key);
    int index;
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int isupper = 1;
    for (int i = 0, m = strlen(text); i < m; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                if ((text[i] - 32) == abc[j])
                {
                    index = j;
                    isupper = 0;
                }
            }
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                if ((text[i]) == abc[j])
                {
                    index = j;
                    isupper = 1;
                }
            }
            else
            {
                index = -1;
            }
        }
        if (index != -1)
        {
            if (isupper == 1)
            {
                text[i] = key[index];
            }
            else if (isupper == 0)
            {
                text[i] = key[index] + 32;
            }
        }
    }
    printf("ciphertext:  %s\n", text);
}

int check_key(string key_check)
{
    if (strlen(key_check) != 26)
    {
        printf("請提供一個完整的命令列參數！\n");
        return 1; // 結束程式，並返回錯誤碼
    }
    for (int i = 0, m = strlen(key_check); i < m; i++)
    {
        if (key_check[i] > 'z' || key_check[i] < 'A' || (key_check[i] < 'a' && key_check[i] > 'Z'))
        {
            printf("請提供一個完整的命令列參數！\n");
            return 1; // 結束程式，並返回錯誤碼
        }
    }
    int c;
    // for(int i =0, m=strlen(key_check);i<m;i++){
    //     for(int j = i+1; j < m;j++){
    //         if(key_check[i]>key_check[j]){
    //             c = key_check[i];
    //             key_check[i] = key_check[j];
    //             key_check[j] = c;
    //         }
    //     }
    // }
    // for(int i =0, m=strlen(key_check);i<m-1;i++){
    //     if(key_check[i] == key_check[i+1]){
    //         printf("有重複字母！\n");
    //         return 1;
    //     }
    // }
    for (int i = 0, m = strlen(key_check); i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (key_check[i] == key_check[j])
            {
                printf("有重複字母！\n");
                return 1;
            }
        }
    }
    return 0;
}

string upper(string key_check)
{
    for (int i = 0, m = strlen(key_check); i < m; i++)
    {
        if (key_check[i] >= 'a' && key_check[i] <= 'z')
        {
            key_check[i] -= 32;
        }
    }
    return key_check;
}
