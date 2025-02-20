function y = MATLAB_ditfft(x)
    m=nextpow2(length(x));
    N=2^m;
    if length(x)<N
        x=[x,zeros(1,N-length(x))];
    end
    %nxd=bin2dec(fliplr(dec2bin([1:N]-1,m)))+1;
    nxd0=dec2bin([1:N]-1,m);
    nxd1=fliplr(nxd0);
    nxd=bin2dec(nxd1)+1;
    y=x(nxd);
    for mm=1:m
        Nmr=2^mm;
        u=1;
        WN=exp(-1i*2*pi/Nmr);
        for j=1:Nmr/2
            for k=j:Nmr:N
                kp=k+Nmr/2;
                t=y(kp)*u;
                y(kp)=y(k)-t;
                y(k)=y(k)+t;
            end
            u=u*WN;
        end
    end
end

