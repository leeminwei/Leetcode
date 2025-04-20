bool isIsomorphic(char* s, char* t) {
    int size = strlen(s);
    int s_map[256] = {0};
    int t_map[256] = {0};
    for(int i=0 ; i<size ; i++){
        if(s_map[s[i]] == 0 && t_map[t[i]] == 0){
            s_map[s[i]] = t[i];
            t_map[t[i]] = s[i];
        }
        if(s_map[s[i]] != t[i] || t_map[t[i]] != s[i])
            return false;
        else{
            s_map[s[i]] = t[i];
            t_map[t[i]] = s[i];
        }

    }
    return true;
}