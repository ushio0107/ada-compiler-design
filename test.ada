{* test Program
 *
 *
 *}
program test
declare
  a : integer;
  a2: integer := 1 + 2;
  b: integer;
  const1: constant := 0;
  const2: constant: integer := 5;
  const3: constant := true;
  const4: constant := "test program start";
  sum:  integer;
  repReturn: integer;
  c: integer;
  sum2: integer;
  index1: integer;
  index2: integer;
  const5: constant := -10;
  const6: constant := 2 + 2;
  n: integer;

procedure rep (arg1: integer; arg2: integer) return integer
declare
  sum3 : integer := 0;
begin  
      if(arg1 > arg2) then
        sum3 := arg1 - arg2;
      else 
        sum3 := arg2 - arg1;
      end if;
    return sum3;
end;
end rep;

procedure no_returntype (kk: integer)
    begin
        println kk;
    end;
end no_returntype;

procedure testLocalDeclar return integer
declare
  d : integer;
  e : integer;
  f : integer := 17;
  sum : integer;
begin
  d := f + 3;
  e := 0;
  sum := 0;
  while(e <= 5) loop
    begin
      sum := sum + e;
      e := e + 1;
    end;
  end loop;
  return sum;
end;
end testLocalDeclar;

begin
  a := const1;
  sum := 0;
  c := 15;

  if(const3) then
    println const4;
  end if;

  for(b in 1..10) loop
    begin
      sum := sum + b;
    end;
  end loop;
  
  print "for(1 to 10) sum is ";
  println sum;

  repReturn := rep(sum, const2);
  print "check Function :";
  println repReturn;

  print ("check Procedure");
  no_returntype(b);

  sum2 := 0;
  while (c >= 0) loop
   declare 
    s :integer := 5;
   begin
    c := c - 1;
    sum2 := sum2 + c + s;
   end;
  end loop;

  print "sum2 result: ";
  println sum2;

  sum := 0;
  for(index1 in 1..10) loop
    begin
      for(index2 in 1..10) loop
        begin
          sum := sum + index1 + index2;
        end;
      end loop;
    end;
  end loop;

  print "for loop result:";
  println sum;

  sum2 := 0; 
  sum2 := const5 + 2;
  print "sum2 value: ";
  println sum2;
  print "const3 value(boolean): ";
  println const3;

  n := (10 + 2) * 5;
  print "check expression: ";
  print n;
  print ", ";
  println const6;

  
  print "check multiple boolean expression: ";
  if(n >= 0 AND sum2 <= 10) then
    println n + sum2;
  else
    println n - sum2;
  end if;

  print "check local declaration and print function: ";
  println testLocalDeclar();

  


  {if(n=10) then
   println n;
  else
    println a;
  end if;}
 end;
end test