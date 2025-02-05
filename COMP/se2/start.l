%s PR
%option yylineno
%%
\n                      BEGIN PR;
<PR>compiladores        {printf("Reconocida %s en linea %d\n", yytext, yylineno); BEGIN INITIAL;}
.                       BEGIN 0;
^compiladores           {printf("Reconocida %s en linea %d\n", yytext, yylineno); BEGIN 0;}

