#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int str_len(const char *str){
//        int len=0;
//        while(*strIn != '\0'){
//            len++;
//            strIn++;
//        }
//        return len;
//}
int str_copy(const char **strOut,const char *strIn){
    int d = (strlen(strIn)+1);
//    *strOut = malloc(d);
//    memccpy(*strOut,strIn,'\0',d);
//    return 0;
    char *s = (char*)malloc(d);
    int i = 0;
    for(;strIn[i]!='\0';i++){
        s[i]=strIn[i];
    }
    s[i]='\0';
    *strOut = s;
    return 0;
}

void str_print(const char **str){
    printf(*str);
}

int main(){
    char* str = NULL;
    str_copy(&str, "Hello");
    str_print(&str);
    return 0;
}
