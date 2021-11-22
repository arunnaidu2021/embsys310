int funct1(int a, int b, int c, int d, int e);
int funct2( int x );

int funct1(int a, int b, int c, int d, int e)
{
  return (a + b + c + d + e);
}

int funct2( int x )
{
  int sum = funct1( x, x, x, x, x );
  return sum;
}

int main()
{
  int y = funct2( 1 );
  return 0;
}
