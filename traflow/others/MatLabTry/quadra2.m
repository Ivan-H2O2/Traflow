function [x1,x2] = quadra2(a,b,c)
% To solve quadratic equation like ax^2+bx+c=0
function d=disc %nested in quadra2 
d=sqrt(b^2-4*a*c);
end %disc
disc;
x1=(-b+d)/(2*a);
x2=(-b-d)/(2*a);
%disp(ret);
end %end quadratic

% Note:Unavailable?