UPDATE CLIENTE2
SET calle = 'LEPANTO', ciudad = 'YECLA'
WHERE nombre = 'MALDONADO,D';

UPDATE SUCURSAL2
SET activo = (
    SELECT activo
    FROM SUCURSAL2
    WHERE nombre = 'SUR'
) - 1650
WHERE nombre = 'SUR';

UPDATE PRESTAMO2
SET cantidad = cantidad*1.2
WHERE cliente_cod = (
    SELECT codigo
    FROM CLIENTE2
    WHERE nombre = 'ESPALLARDO,E'
);

ALTER TABLE CLIENTE2
ADD cuantas_cuentas NUMERIC;

UPDATE CLIENTE2 C
SET cuantas_cuentas = (
    SELECT COUNT(*)
    FROM CUENTA2
    WHERE cliente_cod = C.codigo
);

ALTER TABLE SUCURSAL2   
ADD media_prestamo NUMBER(9,2);

UPDATE CLIENTE2 C
SET cuantas_cuentas = (
    SELECT COUNT(*)
    FROM PRESTAMO2
    WHERE cliente_cod = C.codigo
);


SELECT AVG(cantidad)
FROM PRESTAMO2
WHERE sucursal_cod IN (
    SELECT sucursal_cod
    FROM PRESTAMO2
    GROUP BY sucursal_cod
    HAVING COUNT(*) >= 2
)
GROUP BY sucursal_cod;



select * from prestamo2;

create table cuenta2 as select * from cuenta;