bool isValid(char* s) {
    int count = 0;
    int number = strlen(s);
    char stack[number];
    for(int i=0 ; i<number ; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack[count] = s[i];
            count++;
        }
        else if(count > 0 && s[i] == ')' && stack[count-1] == '('){  
            count--;
        }
        else if(count > 0 && s[i] == ']' && stack[count-1] == '['){         
            count--;
        }
        else if(count > 0 && s[i] == '}' && stack[count-1] == '{'){          
            count--;
        }
        else
            return false;
    }
    if(count==0)
        return true;
    else
        return false;
}