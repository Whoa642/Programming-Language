int bitcount(unsigned x)
{
    int n;
    for(n = 0; x; x &= (x-1)) n++;
    return n;
}
