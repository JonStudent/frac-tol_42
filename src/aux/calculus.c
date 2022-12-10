#include "../fractol.h"

t_cx    cmplx(double a, double b)
{
    t_cx    c;

    c.real = a;
    c.imag = b;
    return (c);
}

t_px    pxl(int a, int b)
{
    t_px    p;

    p.x = a;
    p.y = b;
    return (p);
}
