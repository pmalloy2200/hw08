#include <stdio.h>
#include <math.h>

#include </usr/include/gsl/gsl_errno.h>
#include </usr/include/gsl/gsl_odeiv2.h>

int gliderdemo (double v, double a, double x, double y);

int main(void)
{
    double v = 2., a = 0., x = 0., y;
    
    
for (y = .1; y <=5; y += .1/50)
    {
    gliderdemo(v, a, x, y);
    }
    
 return 0;
    
}
