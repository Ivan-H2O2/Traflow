% 第四章-例1
 
%% ---- 初始化----
e=2.71828;
h0=20;
% init v
u1=20;
u0=15;
Alpha=8;    %%%% !
% Beta=0;
% Gamma=0;
dt=0.01;   %时间步长 step
T=60;  %模拟时长  whatever , log 40,60,80,140,200
tn=T/dt;  %时间步数
cn=2;
tautime = 0.19;
Tau = (tautime/dt); %0.19/dt;  %layback int8(0.19/dt)  %%%% !

% if tautime*Alpha*e > 1 
%     disp('TREMOR');
% end

if Alpha*2*tautime > pi
    disp('TREMOR');
else
    disp('NORMAL');
end
    

x=nan(tn+1,cn);   x(1,2:cn)=0;  x(1,1)=h0;
v=zeros(tn+1,cn);  
for n=1:cn
    v(1,n)=25-5*n;
    if v(1,n) < 0
        v(1,n)=0;
    end
end
% v(1,:)=[u1 u0];
a=zeros(tn+1,cn);
    
hw=waitbar(0,'calculating..');
tic;

%% 推进
for i=2:tn+1
    for n=1:cn
        x(i,n)=x(i-1,n)+dt*v(i-1,n);
        v(i,n)=v(i-1,n)+dt*a(i-1,n);
       % if v(i,n)<0
       %     v(i,n)=0;
       % end
        if v(i,n) > 60
            v(i,n) = 60;
        end
        if v(i,n) < 0
            v(i,n)=0;
        end
    end

    if i<=Tau+1
        for n=2:cn
            a(i,n)=Alpha*(v(1,n-1)-v(1,n));
        end
    else
        for n=2:cn
            a(i,n)=Alpha*(v(i-Tau,n-1)-v(i-Tau,n));
            if a(i,n) > 40
                a(i,n) = 40;
            end
        end
        
    end
    
  %  a(i,2)=Alpha*(Vn_1-Vn);
  %  if a(i,2)>4
  %      a(i,2)=4;
  %  end
  %  if a(i,2)<-4
  %      a(i,2)=-4;
  %  end
        
    waitbar(i/(tn+1),hw);
end

close(hw);
toc;
% plot
plot((0:tn)*dt,v); hold on;  
% legend('car 1','car 2','car 3','fontsize',12);

xlabel('time (s)','fontname','times new roman','fontsize',12);   
ylabel('{\itv} (m/s)','fontname','times new roman','fontsize',12);
title('Ch4-Ex1 Car Following');
grid on
text(10,26,['1/{\alpha}e = ' num2str(1/Alpha/e,'%6.4f')  '      {\pi}/2{\alpha} = ' num2str(pi/Alpha/2,'%6.4f')] ,'fontname','times new roman','fontsize',14);  
axis([0 T 12 28]);
