Ts = 0.01;
b = 2;
a = 1;

ksi = 1;
w0 = 1;

alpha0 = w0*w0;
alpha1 = 2*ksi*w0;
alpha2 = 3; %STA OVDE

A = [1 a 0];
B = [b]; %#ok<*NBRAK>

Am = [1 alpha1 alpha0];
Bm = [alpha0];

r0 = (alpha1 + alpha2) - a;
R = [1 r0];

p0 = alpha0*alpha2 / b;
p1 = (alpha0 + alpha1*alpha2-a*r0)/b;
S = [p1 p0];

t1 = alpha0/b;
t0 = alpha2*alpha0/b;
T = [t1 t0];

