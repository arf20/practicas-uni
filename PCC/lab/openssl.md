Using configuration from /usr/lib/ssl/openssl.cnf
Enter pass phrase for demoCA/cakey.pem:
Check that the request matches the signature
Signature ok
The stateOrProvinceName field is different between
CA certificate (murcia) and the request (murcia)

openssl ca -policy policy_anything -keyfile demoCA/cakey.pem -in demoCA/servidor.csr

keytool -import -alias servidor -file newcerts/01.pem -keystore servidor.ks

