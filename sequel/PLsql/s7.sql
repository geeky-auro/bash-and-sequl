-- dISPLAY 1 DIGIT NO. IN WORDS
DECLARE 
VDIGIT NUMBER(1);
BEGIN
VDIGIT:= &VDIGIT;
CASE VDIGIT
WHEN 0 THEN DBMS_OUTPUT.PUT_LINE('ZERO');
WHEN 0 THEN DBMS_OUTPUT.PUT_LINE('ONE');
WHEN 2 THEN DBMS_OUTPUT.PUT_LINE('TWO');
WHEN 3 THEN DBMS_OUTPUT.PUT_LINE('THREE');
WHEN 4 THEN DBMS_OUTPUT.PUT_LINE('FOUR');
WHEN 5 THEN DBMS_OUTPUT.PUT_LINE('FIVE');
WHEN 6 THEN DBMS_OUTPUT.PUT_LINE('SIX');
WHEN 7 THEN DBMS_OUTPUT.PUT_LINE('SEVEN');
WHEN 8 THEN DBMS_OUTPUT.PUT_LINE('EIGHT');
WHEN 9 THEN DBMS_OUTPUT.PUT_LINE('NINE');
ELSE DBMS_OUTPUT.PUT_LINE('WRONG INPUT');END CASE;
END;
/