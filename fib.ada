program fib
declare
    n : integer;
    sum: integer;
    sk: integer;

procedure fibn(n: integer) return integer
    begin
        if(n <= 1) then
            return n;
        end if;
        return fibn(n - 1) + fibn(n - 2);
    end;
end fibn;

begin
    n := 8;
    sum := fibn(n);
    println sum;
    sk := n + 10 + 5;
end;
end fib