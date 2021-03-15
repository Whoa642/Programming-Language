void escape(char s[],char t[])
{
    int i,j;
    for(i = 0; t[i]; ++i)
    {
        switch(t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = '\t';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}
