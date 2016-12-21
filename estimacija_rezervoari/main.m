s = 1;
sout = 10e-4;
hmax = 10;
h10 = 4;
h20 = 4;
h30 = 4;
h0 = 3;
A = sout * sqrt(2*9.81)/s;
B = 1/s;
q0 = A * sqrt(h0) / B;
k1 = 1;
k2 = 1;
k3 = 1;
d1 = 0.0012;
d2 = 0.0012;
d3 = 0.0012;

a = (sout * sqrt(2*9.81))/(s * 2 * sqrt(h0));
b = 1/s;

Al = [-a  0  0;
       a -a  0;
       0  a -a];
Bl = [b 0 0]';
alpha = 2;
P0 = [-a -a -a];
P = alpha * P0;
K = acker(Al, Bl, P);

r = 3;
Cl = [0 0 1];
kr = -1/(Cl * ((Al-Bl*K)\Bl));
kd = 0.00001;
sv = eig([Al-Bl*K -Bl; kd*Cl 0]);
Ts = 0.01;

AA = [Al Bl;0, 0, 0, 0];
BB = [Bl;0];
CC = [Cl 0];
Po = [-0.9;-0.9;-0.9;-0.9];
K2 = acker(AA', CC', Po)';
L = K2(1:3);
Ld = K2(4);
%disp(eig([Al - L*Cl, Bl;Ld * Cl, 0]));