function y=MATLAB_dft(x)
    N=length(x);
    x=x';
    A=zeros(N,N);
    W=exp(-1i*2*pi/N);
    for i=0:N-1
        for j=0:N-1
            A(i+1,j+1)=W^(i*j);
        end
    end
    y=A*x;
end
