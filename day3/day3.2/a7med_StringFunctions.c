int stringLength(char string_name[]){
    int i = 0;
    while(string_name[i] != '\0'){
        i++;
    }
    return i;
}

int stringCompare(char str1[], char str2[]){
    if(stringLength(str1) > stringLength(str2)){
        return 1;
    } else if(stringLength(str1) < stringLength(str2)){
        return -1;
    } else {
        for(int i=0;i<stringLength(str1);i++){
            if(str1[i] > str2[i]){
                return 1;
            } else if(str1[i] < str2[i]){
                return -1;
            }
        }
    }
    return 0;
}
