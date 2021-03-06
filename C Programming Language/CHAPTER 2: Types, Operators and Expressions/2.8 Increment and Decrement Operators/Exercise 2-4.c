void squeeze(char s1[],char s2[])
{
    int i,j,k;

    for(i = 0; s1[i]; i++)
    {
        for(j = 0; s2[j]; j++)
            if(s1[i] == s2[j])
                break;
        if(s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';

    printf("%s",s1);
}
