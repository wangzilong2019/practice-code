#include "Conversion.h"
#include <string.h>
#include <ctype.h>

typedef enum MenuSelect {
    EXIT = 0,
    NULLDECIMAL = 1,    // 无小数
    DECIMAL = 2,        // 有小数
} MenuSelect;

void Menu(void );
void HelpInfo(void );
void ShowAnswer(const Answer *ans); // 打印答案
void NullDecimal (char *input, Answer *ans); // 处理无小数的输入
void Decimal (char *input, Answer *ans);    // 处理正数 + 小数

void HelpInfo(void ) {
    printf("\t#############  help info  #########\n");
    printf("\tnumber input format are as follows:\n");
    printf("\tbin number '111b' or '1111.111b'\n");
    printf("\toct number '777O' or '0777.777o'\n");
    printf("\tdec number '999D' or '0999.999d'\n");
    printf("\thex number 'fffh' or 'ffff.fffh'\n");
    printf("\t#############  help info  #########\n");
}

void Menu(void ) {
    printf("\t#################  Menu  #################\n");
    printf("\tinput 'end' or 'END' to exit the program!\n");
    printf("\t-----------------------------------------\n");
    printf("\tinput 'help' or 'HELP' to get user guide!\n");
    printf("\t#################  Menu  #################\n");
}

// 主函数：获取输入的字符串，将字母统一为大写，根据输入判断是否有小数部分，做相应的处理
int main()
{
    Answer ans;
    ans.a_bin = (char *)malloc(MAXLENGTH);
    ans.a_oct = (char *)malloc(MAXLENGTH);
    ans.a_dec = (char *)malloc(MAXLENGTH);
    ans.a_hex = (char *)malloc(MAXLENGTH);

    Menu();

    while (1) {
        char input[MAXLENGTH] = {0};
        printf("input>");
        scanf("%s", input);
        for (int j = 0; j < strlen(input); ++j) {
            // 转换成大写
            if (islower(input[j])) {
                input[j] = (char)toupper(input[j]);
            }
        }
        // 如果输入 EXIT 则退出程序
        if (strcmp(input, "END") == 0)
            goto HERETOEXIT;
        if (strcmp(input, "HELP") == 0)
        {
            HelpInfo();
            continue;
        }
        // 判断是否为默认 十进制
        char c = input[strlen(input)-1];
        if (
                c != BIN
                && c != OCT
                && c != DEC
                && c != HEX
                )
            strcat(input, "D");
        MenuSelect flag = EXIT;   // NULLDECIMAL->无小数部分   DECIMAL->有小数部分
        // 判断是否为小数
        for (int i = 0; i < strlen(input); ++i) {
            if (input[i] == POINT) {
                flag = DECIMAL;
            }
        }
        if (flag != DECIMAL)
        {
            flag = NULLDECIMAL;
        }

        switch (flag){
            case NULLDECIMAL:   // 无小数
                NullDecimal(input, &ans);
                break;
            case DECIMAL:
                Decimal(input, &ans);
                break;
            default:
                printf("input error!\n");
                break;
        }

        ShowAnswer(&ans);
    }

    HERETOEXIT:
        printf("Bye!\n");
    return 0;
}

void NullDecimal (char *input, Answer *ans) {

    assert(input != NULL);
    assert(ans != NULL);

    char *b = NULL;
    char *o = NULL;
    char *d = NULL;
    char *h = NULL;

    // 判断输入的是几进制的数,做相应的转换
    switch(input[strlen(input)-1]) {
        case BIN:   // 输入为2进制 -> 转10进制 -> 转8、16进制
            ans->a_input_num_type = BIN;
            int bin_dec = AllToDec(input, 2);
//            printf("%d\n", bin_dec);
            b = DecToAll(bin_dec, 2);
            o = DecToAll(bin_dec, 8);
            d = DecToAll(bin_dec, 10);
            h = DecToAll(bin_dec, 16);
            break;

        case OCT:   // 输入为8进制  -> 转10进制 -> 转2、16进制
            ans->a_input_num_type = OCT;
            int oct_dec = AllToDec(input, 8);
//            printf("%d\n", oct_dec);
            b = DecToAll(oct_dec, 2);
            o = DecToAll(oct_dec, 8);
            d = DecToAll(oct_dec, 10);
            h = DecToAll(oct_dec, 16);
            break;

        case DEC:   // 输入为10进制  -> 转2、8、16进制
            ans->a_input_num_type = DEC;
            int dec_dec = AllToDec(input, 10);
//            printf("%d\n", dec_dec);
            b = DecToAll(dec_dec, 2);
            o = DecToAll(dec_dec, 8);
            d = DecToAll(dec_dec, 10);
            h = DecToAll(dec_dec, 16);
            break;

        case HEX:   // 输入为16进制 -> 转10进制 -> 转2、8进制
            ans->a_input_num_type = HEX;
            int hex_dec = AllToDec(input, 16);
//            printf("---%d\n", hex_dec);
            b = DecToAll(hex_dec, 2);
            o = DecToAll(hex_dec, 8);
            d = DecToAll(hex_dec, 10);
            h = DecToAll(hex_dec, 16);
            break;

        default:
            exit(1001); // 输入格式错误，退出程序
            break;
    }

    strcpy(ans->a_bin, b);
    strcpy(ans->a_oct, o);
    strcpy(ans->a_dec, d);
    strcpy(ans->a_hex, h);
}

void Decimal (char *input, Answer *ans) {
    assert(input != NULL);
    assert(ans != NULL);

    // 用小数点分割，并加上相应的表示符号
    char sign = input[strlen(input)-1];
    char zhengshu[MAXLENGTH], xiaoshu[MAXLENGTH];
    strcpy(zhengshu, input);
    char *p = zhengshu;
    while (*p != POINT) {
        p++;
    }
    *p = sign;
    strcpy(xiaoshu, p+1);
    *(p+1) = '\0';

    NullDecimal(zhengshu, ans); // 处理正数部分

    char *b = NULL;
    char *o = NULL;
    char *d = NULL;
    char *h = NULL;

    // 判断输入的是几进制的数,做相应的转换
    switch(xiaoshu[strlen(xiaoshu)-1]) {
        case BIN:   // 输入为2进制 -> 转10进制 -> 转8、16进制
            ans->a_input_num_type = BIN;
            float bin_dec = DECIMAL_AllToDec(xiaoshu, 2);
//            printf("------------------%lf----------------\n", bin_dec);
            b = DECIMAL_DecToAll(bin_dec, 2);
            o = DECIMAL_DecToAll(bin_dec, 8);
            d = DECIMAL_DecToAll(bin_dec, 10);
            h = DECIMAL_DecToAll(bin_dec, 16);
            break;

        case OCT:   // 输入为8进制  -> 转10进制 -> 转2、16进制
            ans->a_input_num_type = OCT;
            float oct_dec = DECIMAL_AllToDec(xiaoshu, 8);
//            printf("------------------%lf----------------\n", oct_dec);

            b = DECIMAL_DecToAll(oct_dec, 2);
            o = DECIMAL_DecToAll(oct_dec, 8);
            d = DECIMAL_DecToAll(oct_dec, 10);
            h = DECIMAL_DecToAll(oct_dec, 16);
            break;

        case DEC:   // 输入为10进制  -> 转2、8、16进制
            ans->a_input_num_type = DEC;
            float dec_dec = DECIMAL_AllToDec(xiaoshu, 10);
//            printf("------------------%lf----------------\n", dec_dec);

            b = DECIMAL_DecToAll(dec_dec, 2);
            o = DECIMAL_DecToAll(dec_dec, 8);
            d = DECIMAL_DecToAll(dec_dec, 10);
            h = DECIMAL_DecToAll(dec_dec, 16);
            break;

        case HEX:   // 输入为16进制 -> 转10进制 -> 转2、8进制
            ans->a_input_num_type = HEX;
            float hex_dec = DECIMAL_AllToDec(xiaoshu, 16);
//            printf("------------------%lf----------------\n", hex_dec);

            b = DECIMAL_DecToAll(hex_dec, 2);
            o = DECIMAL_DecToAll(hex_dec, 8);
            d = DECIMAL_DecToAll(hex_dec, 10);
            h = DECIMAL_DecToAll(hex_dec, 16);
            break;

        default:
            exit(1001); // 输入格式错误，退出程序
            break;
    }

    strcat(ans->a_bin, ".");
    strcat(ans->a_oct, ".");
    strcat(ans->a_dec, ".");
    strcat(ans->a_hex, ".");
    strcat(ans->a_bin, b);
    strcat(ans->a_oct, o);
    strcat(ans->a_dec, d);
    strcat(ans->a_hex, h);
}

void ShowAnswer(const Answer *ans) {
    assert(ans != NULL);
//    system("clear");
    printf("\t\t-----answer-----\n");
    printf("\t\tbin : %s\n", ans->a_bin);
    printf("\t\toct : %s\n", ans->a_oct);
    printf("\t\tdec : %s\n", ans->a_dec);
    printf("\t\thex : %s\n", ans->a_hex);
    printf("\t\t-----answer-----\n");
}
