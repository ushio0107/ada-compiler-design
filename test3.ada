program testProgram
declare 
  var1 : integer := 0;
  var2 : constant : integer := 10;
  a := 0;
  a1 := 0;
  sum : integer;

begin
    sum := 0;
    print "while-if function";
    while(var1 <= var2) loop
        begin
            if(var1 = var2) then
                println sum;
            else
                sum := sum + var1;
            end if;
            var1 := var1 + 1;
        end;
    end loop;

    var1 := 0;
    sum := 0;
    while(var1 <= var2) loop
        begin 
            for(a in 1..5) loop
                println a;
            end loop;
            var1 := var1 + 1;
            print "var1:";
            println var1;
        end;
    end loop;

    if(var1 < sum) then
    begin
        for(a1 in 1..5) loop
            var1 := var1 + a1 * 2;
        end loop;
        println var1;
    end;
    else
    begin
        for(a1 in 1..3) loop
            var1 := var1 + a1 * 2;
        end loop;
        println var1;
    end;
    end if;

end;
end testProgram
        
    