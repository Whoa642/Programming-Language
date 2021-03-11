int lower(int x)
{
    return (x >= 'a' && x <= 'z') ? x : (x+('a'-'A'));
}
