int htoi(char s[])
{
    int i,n,valid;
    i = n = 0;
    valid = 0;

    if(s[i] == '0' && ((s[i+1] == 'x') || s[i+1] == 'X'))
        valid = 1;
    i += 2;

    for(; s[i] && valid; ++i)
    {
        if(s[i] >= '0' && s[i] <= '9') n = n*16+(s[i]-'0');
        else if(s[i] >= 'a' && s[i] <= 'f') n = n*16+(s[i]-'a'+10);
        else if(s[i] >= 'A' && s[i] <= 'F') n = n*16+(s[i]-'A'+10);
        else valid = 0;
    }
    return valid ? n : -1;
}
