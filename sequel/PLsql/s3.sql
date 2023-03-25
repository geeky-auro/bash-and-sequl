-- plsql program to perform all arithmetic operation and take variables as user input;
declare
x Number(2);
y Number(2);
z1 Number(2);
z2 Number(2);
z3 Number(2);
z4 Number(2);
begin
x:=&x;
y:=&y;
z1:=x+y;
z2:=x-y;
z3:=x*y;
z4:=x/y;
dbms_output.put_line('Addition');
dbms_output.put_line(z1);
dbms_output.put_line('Substraction');
dbms_output.put_line(z2);
dbms_output.put_line('Multiplication');
dbms_output.put_line(z3);
dbms_output.put_line('Division');
dbms_output.put_line(z4);
end;
/