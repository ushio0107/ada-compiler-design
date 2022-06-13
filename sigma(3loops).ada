{* Sigma.sp
 *
 * Compute sum = 1 + 2 + ... + n
 *}
program computeSigma
-- constant and variable declarations
declare
  n: constant := 5;
  n1: integer;
  sum: integer;
  sum1: integer;
  index: integer;
  index2: integer;
  index3: integer;

-- main statements
begin
  sum := 0;
  sum1 := 0;
  index := 0;
  index2 := 0;
  index3 := 0;

  if(sum >= n AND index <= n) then
   println "Yes";
   end if;
  
  n1 := 10;

  while (index < 5) loop
    begin
      while (index2 < n) loop
        begin
          while (index3 < n) loop
            begin
            sum := sum + index +index2 + index3;
            index3 := index3 + 1;
            end;
          end loop;
        index2 := index2 + 1;   
        index3 := 0;
        end;
      end loop;
    index := index + 1;
    index2 := 0;
    index3 := 0;
    end;
  end loop;
  
  index := 0;
  index2 := 0;
  index3 := 0;

  print "The while loop result is ";
  println sum;

  for(index in 0..4) loop
    begin
      for(index2 in 0..4) loop
        begin
          for(index3 in 0..4) loop
            begin
              sum1 := sum1 + index + index2 + index3;
            end;
          end loop;
        end;
      end loop;
    end;
  end loop;

  print "The for loop result is ";
  println sum1;

  if(sum = sum1) then
    println ("sum = sum1");
  else
    println ("sum != sum1");
  end if;
    
end;
end computeSigma