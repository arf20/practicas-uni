sudo ldapadd -Q -Y EXTERNAL -H ldapi:/// -D cn=admin,dc=arf,dc=net

ldapmodify -D "cn=admin,dc=org-lego,dc=es" -W -H ldap://localhost

