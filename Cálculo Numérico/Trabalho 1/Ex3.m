syms x;
fprintf(1,'Este é o método de Newton-Raphson para x^2 - 2 com epsilon = 1*10^-4\n');
s=x^2 - 2;
sp =  diff(s,x); % <--- derivada da função
spp = diff(sp,x); % <--- segunda derivada

F = inline(s,'x'); % <--- paso de função simbólica a inline para que
FP = inline(sp,'x');%      o código possa trabalhar sem problemas
FPP = inline(spp,'x');

OK = FALSE;
while OK == FALSE
    fprintf(1,'Insira as extremidades A < B em linhas separadas\n');
    A = input(' ');
    B = input(' ');
    if A > B
        X = A;
        A = B;
        B = X;
    end
    if A == B
        fprintf(1,'a não pode ser igual a b\n');
    else
        FA = F(A);
        FB = F(B);
        if FA*FB > 0
            fprintf(1,'f(a) e f(b) têm o mesmo sinal.\n');
        else
            OK = TRUE;
        end
        FPP0 = FPP(0);
        FPPA = FPP(A);
        if FPPA*FA>0
            P0 = A;
        else
            P0 = B;
        end
    end
end

TOL = 1*10^-4;
F0 = F(P0);
% STEP 1
I = 1;
OK = TRUE;
% STEP 2
while I <= NO & OK == TRUE
    % STEP 3
    % compute P(I)
    FP0 = FP(P0);
    D = F0/FP0;
    % STEP 6
    P0prev = P0;
    P0 = P0 - D;
    F0 = F(P0);
    if FLAG == 2
        fprintf(OUP, '%3d \t %3.10f  \t %3.10f\n', I, P0, abs(P0-P0prev));
    end
    % STEP 4
    if abs(P0prev-P0) < TOL
        % procedure completed successfully
        fprintf(OUP,'\nA solução aproximada é %.10f\n',P0);
        %fprintf(OUP,'with F(P) = %.10e\n',F0);
        fprintf(OUP,'Número de iterações = %d\n',I);
        %fprintf(OUP,'Tolerance = %.10f\n',TOL);
        OK = FALSE;
        % STEP 5
    else
        I = I+1;
    end
end
if OK == TRUE
    % STEP 7
    % procedure completed unsuccessfully
    fprintf(OUP,'\nIteration number %d',NO);
    fprintf(OUP,' gave approximation %.10e\n',P0);
    fprintf(OUP,'with F(P) = %.10e not within tolerance  %.10e\n',F0,TOL);
end
if OUP ~= 1
    fclose(OUP);
    fprintf(1,'Output file %s created successfully \n',NAME);
end