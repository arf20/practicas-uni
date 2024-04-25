## EJERCICIO 1 ##
datos<-read.table("C:/Users/Alumno/Downloads/datos32.dat")
str(datos)
attach(datos)
#a)
  plot(Longitud,Peso)
#b)
  reg<-lm(Peso~Longitud)
  abline(lm(Peso~Longitud),col='magenta')
#c)
  r<-cor(Peso,Longitud)
  #r = 0.997
  r2<-r*r
  #para que sea un buen ajuste el coeficiente de determinación 
  #debe ser > 0.8, en este caso es 0.995, así que se trata de un
  #muy buen ajuste
#d)
  #y = ax + b
  y=(reg$coefficient[2]*5.2)+reg$coefficient[1]
  #36.7 gramos
#e)
  pesosprev<-Longitud*reg$coefficient[2]+reg$coefficient[1]
  res<-Peso-pesosprev
  mean(res) #valor aproximadamente 0
  var(res)
  rel<-var(pesosprev)/var(Peso)
  #rel = r2
#f)
  Peso2<-Peso*Peso
  plot(Peso2,Longitud)
  reg2<-lm(Longitud~Peso2)
  abline(reg2,col='red')
  r_2<-cor(Longitud,Peso2)
  r2_2<-r_2*r_2
  #r_2 es 0.978, con lo cual es peor que el calculado anteriormente
  #r2_2, que es el de determinación en este caso, también es peor
  
## EJERCICIO 2 ##
#a)
  D1<-1:6
  D2<-1:12
  P_D1<-70/100
  P_D2<-30/100
  P_1<-(P_D1*1/6)+(P_D2*1/12)
  #la probabilidad de que se obtenga 1 es 0.1417
#b)
  dados<-1:2
  prob<-c(0.7,0.3)
  dado=sample(dados,1,prob=prob)
  if(dado == 1)
  {
    numero=sample(D1,1)
  }
  if(dado == 2)
  {
     numero=sample(D2,1)
  }
  c(dado,numero)
#c)
  numeros=c()
  for(i in 1:1000){
    dado=sample(dados,1,prob=prob)
    if(dado == 1)
    {
      numero=sample(D1,1)
    }
    if(dado == 2)
    {
      numero=sample(D2,1)
    }
    numeros[i]=numero
  }
  table(numeros)
  frec1<-table(numeros)[1]/length(numeros)
  #da 0.14, aproximadamente lo que da en el apartado a) (0.1417)
#d)
  numeros=c()
  numero1=c()
  dadoselegidos=c()
  for(i in 1:1000){
    dado=sample(dados,1,prob=prob)
    dadoselegidos[i]=dado
    if(dado == 1)
    {
      numero=sample(D1,1)
      numero1[i]=numero
    }
    if(dado == 2)
    {
      numero=sample(D2,1)
    }
    numeros[i]=numero
  }
  datos_2<-data.frame(dadoselegidos,numeros)
  datos_2
#e)
  #P(D1|1)=(P(1|D1)*P(D1))/P(1)
  PD1<-length(dadoselegidos[dadoselegidos==1])/1000
  P1<-length(numeros[numeros==1])/1000
  table(numero1)[1]
  P1D1<-125/715
  resultado<-(P1D1*PD1)/P1
  #resultado=0.82236
#f)
  simulacion<-table(datos_2)
  simulacion
  sim2<-addmargins(simulacion)
  sim2
  sale1<-sim2[,1]
  sale1
  frec2<-125/152
  frec2
  #frec2=0.82236 igual al anterior