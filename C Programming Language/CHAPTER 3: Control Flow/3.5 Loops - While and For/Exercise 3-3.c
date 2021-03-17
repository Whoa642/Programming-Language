void expand(char s1[],char s2[])
{
    int i,j,c;
    i = j = 0;
    while((c = s1[i++]))
    {
        if(s1[i] == '-' && c <= s1[i+1])
        {
            i++;
            for(;c < s1[i]; c++)
                s2[j++] = c;
        }
        else s2[j++] = c;
    }
    s2[j] = '\0';
}
