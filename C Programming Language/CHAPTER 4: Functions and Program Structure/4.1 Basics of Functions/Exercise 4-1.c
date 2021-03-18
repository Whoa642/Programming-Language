int strrindex(char s[],char t[])
{
    int i,j,k,index;
    index = -1;
    for(i = 0; s[i]; i++)
    {
        for(j = i,k = 0; t[k] && s[j] == t[k]; j++,k++);
        if(k > 0 && !t[k]) index = i;
    }
    return index;
}
