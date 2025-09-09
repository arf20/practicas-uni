SELECT activo, ciudad
FROM SUCURSAL;

SELECT nombre
FROM CLIENTE
WHERE ciudad = 'YECLA';

SELECT p.prestamo_id, s.nombre, p.cliente_cod, p.cantidad
FROM PRESTAMO p
JOIN SUCURSAL s ON s.codigo = p.sucursal_cod;

SELECT c.nombre, saldo
FROM CUENTA
JOIN CLIENTE c ON c.codigo = cliente_cod
ORDER BY cliente_cod ASC, saldo;

SELECT saldo
FROM CUENTA a
JOIN CLIENTE c ON c.codigo = a.cliente_cod
WHERE c.nombre = 'ARRUBAL,A';


10.

SELECT c.nombre
FROM CLIENTE c
JOIN CUENTA a ON c.codigo = a.cliente_cod
JOIN PRESTAMO p ON c.codigo = p.cliente_cod
GROUP BY c.nombre;

select * from cuenta;

15.

SELECT nombre
FROM CLIENTE
WHERE calle = (
    SELECT calle
    FROM CLIENTE
    WHERE nombre = 'MALDONADO,D';
) AND ciudad = (
    SELECT ciudad
    FROM CLIENTE
    WHERE nombre = 'MALDONADO,D';
);

20.

SELECT MAX(cantidad) prestamo_maximo
FROM PRESTAMO;

25.

SELECT cliente_cod, COUNT(cliente_cod) cuantas_cuentas
FROM CUENTA
GROUP BY cliente_cod;

30.

SELECT c.codigo, COALESCE(p.prestamo_id, '---'), COALESCE(cantidad, 0)
FROM CLIENTE c
LEFT JOIN PRESTAMO p ON c.codigo = p.cliente_cod
ORDER BY c.codigo;

31.

SELECT codigo
FROM CLIENTE C
JOIN CUENTA Q ON C.codigo = Q.cliente_cod
WHERE Q.sucursal_cod IN (
    SELECT codigo
    FROM SUCURSAL
    WHERE ciudad != 'MURCIA'
)
GROUP BY codigo
HAVING COUNT(DISTINCT(Q.sucursal_cod)) = (
    SELECT COUNT(*)
    FROM SUCURSAL
    WHERE CIUDAD != 'MURCIA'
);

