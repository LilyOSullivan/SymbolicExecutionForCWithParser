int check_local_scope()
{
    int x = 5;
    {
      int x = 10;
    }
    return x;
}
