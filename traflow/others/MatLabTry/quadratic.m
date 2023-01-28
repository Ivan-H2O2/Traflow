
function ret = quadratic(a,b,c)
% To solve quadratic equation like ax^2+bx+c=0
ret = [(-b+discrim(a,b,c))/(2*a),(-b-discrim(a,b,c))/(2*a)];
%disp(ret);
end %end quadratic

% % Way: Out the main func.
% function d=discrim(a,b,c)
% To calculate discriminant(Delta) of the quadratic equa. Used within func.
% quadratic
% d=sqrt(b^2-4*a*c);
% end %end discrim




