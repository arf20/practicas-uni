CREATE TABLE empleado (
    nss NUMBER(12)  NOT NULL,
    dni CHAR(9)     NOT NULL,
    nombre VARCHAR(30) NOT NULL,
    apellido VARCHAR(30) NOT NULL,
    fechanacim DATE,
    ciudad VARCHAR(30),
    est_civil CHAR(1),
    salario NUMBER(2,6) NOT NULL,
    cuantos_familiares NUMBER(2) DEFAULT 0 NOT NULL,
    nssjefe NUMBER(12),
    dep CHAR(3),
    CONSTRAINT empleado_pk PRIMARY KEY (nss),
    CONSTRAINT empleado_ak UNIQUE (dni),
    CONSTRAINT empleado_fk_nssjefe FOREIGN KEY (nssjefe) REFERENCES empleado(nss),
    CONSTRAINT empleado_fk_dep FOREIGN KEY (dep) REFERENCES departamento(coddep),
    CONSTRAINT empleado_jefe_ok CHECK (nssjefe != nss),
    CONSTRAINT empleado_salario_ok CHECK(salario >0),
    CONSTRAINT empleado_estado_civil_ok CHECK(estado_civil IN ('S', 'C'...))
);




