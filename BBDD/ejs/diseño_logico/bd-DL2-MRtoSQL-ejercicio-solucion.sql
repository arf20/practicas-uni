/* Esquema 'EMPRESA' 
- Sentencias de CREACION de las tablas */

/* Eliminacion de tablas. Permite varias ejecuciones
DROP TABLE empleado_en_proyecto;
DROP TABLE proyecto;
DROP TABLE familiar;
DROP TABLE departamento CASCADE CONSTRAINTS;
DROP TABLE empleado;
*/


CREATE TABLE departamento (
coddep		CHAR(3)			NOT NULL,
nombre		VARCHAR2(20)	NOT NULL, 
nssdire		NUMBER(12)		NOT NULL, 
CONSTRAINT dep_pk	PRIMARY KEY (coddep),
CONSTRAINT dep_ak	UNIQUE(nssdire)
);

CREATE TABLE empleado (
nss        NUMBER(12)		NOT NULL,
dni        CHAR(9)			NOT NULL,
nombre     VARCHAR2(25)	NOT NULL, 
apellido   VARCHAR2(15)	NOT NULL, 
fechanacim DATE			NULL,
ciudad     VARCHAR2(30),
est_civil  CHAR(1),
salario    NUMBER(6,2)  DEFAULT 1000 NOT NULL,
cuantos_familiares NUMBER(2) DEFAULT 0 NOT NULL,
nssjefe    NUMBER(12),
dep			CHAR(3)			NULL,
CONSTRAINT emp_pk      PRIMARY KEY (nss),
CONSTRAINT emp_ak      UNIQUE (dni),
CONSTRAINT emp_jefe_ok CHECK (nssjefe <> nss),
CONSTRAINT emp_ec_ok   CHECK (est_civil IN ('S','C','V','D','P')),
CONSTRAINT emp_sal_ok  CHECK (salario>0), 
CONSTRAINT emp_fk_dep  FOREIGN KEY (dep) REFERENCES departamento(coddep),
                          --ON DELETE NO ACTION ON UPDATE CASCADE
CONSTRAINT emp_fk_emp  FOREIGN KEY (nssjefe) REFERENCES empleado(nss)
                          --ON DELETE NO ACTION ON UPDATE CASCADE
);
-- Ciclo referencial: anadir la clave ajena departamento-->empleado
ALTER TABLE departamento ADD 
  CONSTRAINT dep_fk_emp FOREIGN KEY (nssdire) REFERENCES empleado(nss);
                          -- ON DELETE NO ACTION ON UPDATE CASCADE

CREATE TABLE familiar (
nssemp		NUMBER(12)	 NOT NULL,
numero		NUMBER(2)	 NOT NULL,
nombre		VARCHAR2(25) NOT NULL,
fechanacim	DATE		 NOT NULL,
parentesco	VARCHAR2(10) NOT NULL,
CONSTRAINT fam_pk PRIMARY KEY (nssemp, numero),
CONSTRAINT fam_fk_emp FOREIGN KEY (nssemp) REFERENCES empleado(nss),
						-- ON DELETE CASCADE ON UPDATE CASCADE
CONSTRAINT fam_numero_ok CHECK (numero > 0)
);

CREATE TABLE proyecto (
idPro  CHAR(3)      NOT NULL, 
nombre VARCHAR2(20) NOT NULL, 
CONSTRAINT proy_pk  PRIMARY KEY (idPro)
);

CREATE TABLE empleado_en_proyecto (
empleado     NUMBER(12) NOT NULL,
proyecto     CHAR(3)    NOT NULL,
horas_semana NUMBER(12) NOT NULL,
CONSTRAINT ep_pk      PRIMARY KEY (empleado, proyecto),
CONSTRAINT ep_horas_ok  CHECK (horas_semana>0), 
CONSTRAINT ep_fk_proy  FOREIGN KEY (proyecto) REFERENCES proyecto(idPro),
                          --ON DELETE CASCADE ON UPDATE CASCADE
CONSTRAINT ep_fk_emp  FOREIGN KEY (empleado) REFERENCES empleado(nss)
                          --ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE objetivo_proyecto (
proyecto CHAR(3)     NOT NULL,
objetivo VARCHAR(30) NOT NULL,
CONSTRAINT op_pk      PRIMARY KEY (proyecto, objetivo),
CONSTRAINT op_fk_proy  FOREIGN KEY (proyecto) REFERENCES proyecto(idPro)
                          --ON DELETE CASCADE ON UPDATE CASCADE
);


-- The end!