f=function(x) {
  if (x < 2.7) return 0;
  if (x > 3.3) return 0;
  return k*(x-3)^2;
}

media = integrate(function(x)x*f(x), 2.7, 3.3);
varianza = integrate(function(x)x*f(x-media)^2, 2.7, 3.3);
