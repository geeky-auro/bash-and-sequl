-- gCD OF TWO nO'S
DECLARE 
i number(4);
j number(4);
BEGIN
i:=&i;
j:=&j;
while(i!=j) LOOP
i:=i-j;
END LOOP;
DBMS_OUTPUT.PUT_LINE(i);
END;
/

