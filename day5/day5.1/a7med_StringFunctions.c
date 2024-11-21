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

void stringConcat(char s1[], char s2[]){
    int i = stringLength(s1), j = 0;
    while(s2[j] != '\0'){
        s1[i] = s2[j];
        i++; j++;
    }
    s1[i] = '\0';
}

void stringCopy(char destination[], char source[]){
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void stringToUpper(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 97 && str[i] <= 122){
            str[i] -= 32;
        }
        i++;
    }
}

void stringToLower(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 65 && str[i] <= 90){
            str[i] += 32;
        }
        i++;
    }
}
