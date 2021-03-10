unsigned invert(unsigned x,int p,int n)
{
    return x ^ (~(~0 << n) << (1+p-n));
}
