#version 330 core

in vec3  fmatamb;
in vec3  fmatdiff;
in vec3  fmatspec;
in float fmatshin;
in vec3  fvertex;
in vec3  fnormal;

const vec3 llumAmbient = vec3(0.1, 0.1, 0.1);

uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;

out vec4 FragColor;


const vec3 magenta = vec3(0.7, 0, 0.7);
const vec3 groc = vec3(0.9, 0.9, 0);

vec3 focosMagentaPos[4];


vec3 Ambient() {
  return llumAmbient*fmatamb;
}

vec3 Difus (vec3 NormSCO, vec3 L, vec3 colFocus)
{
  // Fixeu-vos que SOLS es retorna el terme de Lambert!
  // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats
  vec3 colRes = vec3(0);
  if (dot (L, NormSCO) > 0)
    colRes = colFocus * fmatdiff * dot (L, NormSCO);
  return (colRes);
}

vec3 Especular (vec3 NormSCO, vec3 L, vec3 vertSCO, vec3 colFocus)
{
  // Fixeu-vos que SOLS es retorna el terme especular!
  // Assumim que els vectors estan normalitzats
  vec3 colRes = vec3 (0);
  // Si la llum ve de darrera o el material és mate no fem res
  if ((dot(NormSCO,L) < 0) || (fmatshin == 0))
    return colRes;  // no hi ha component especular

  vec3 R = reflect(-L, NormSCO); // equival a: 2.0*dot(NormSCO,L)*NormSCO - L;
  vec3 V = normalize(-vertSCO); // perquè la càmera està a (0,0,0) en SCO

  if (dot(R, V) < 0)
    return colRes;  // no hi ha component especular

  float shine = pow(max(0.0, dot(R, V)), fmatshin);
  return (colRes + fmatspec * colFocus * shine);
}

void main()
{
    focosMagentaPos[0] = vec3(2, 5, 1);
    focosMagentaPos[1] = vec3(8, 5, 1);
    focosMagentaPos[2] = vec3(2, 5, 9);
    focosMagentaPos[3] = vec3(8, 5, 9);
    
    vec3 focoGrocPos = vec3(5, 2, 5);

    vec3 normalnormalSCO = normalize(fnormal);

    vec3 color = Ambient();

    for (int i = 0; i < 4; i++) {
        vec3 L = normalize(focosMagentaPos[i] - vec3(fvertex));
        color += Difus(normalnormalSCO, L, magenta) + Especular(normalnormalSCO, L, fvertex, magenta);
    }
    vec3 L = normalize(focoGrocPos - vec3(fvertex));
    color += Difus(normalnormalSCO, L, magenta) + Especular(normalnormalSCO, L, fvertex, groc);

    FragColor = vec4(color, 1.0);
}

