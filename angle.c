#include <stdio.h>
#include <math.h>

#include </home/jharvard/Downloads/gsl-1.16/gsl/gsl_errno.h>
#include </home/jharvard/Downloads/gsl-1.16/gsl/gsl_odeiv2.h>

int gliderdemo (double v, double a, double x, double y);

int main(void)
{
    double v = 2., a, x = 0., y = 2.;
    
    
for (a = -3.14159/3. ; a <= 3.14159/3.; a += 3.14159/3./20.)
    {
    gliderdemo(v, a, x, y);
    }
    
 return 0;
    
}
