## -*- encoding: utf-8 -*-
## This file ("Ejercicios 2 2023_2024".sagetex.sage) was *autogenerated* from "Ejercicios 2 2023_2024".tex with sagetex.sty version 2021/10/16 v3.6.
import sagetex
_st_ = sagetex.SageTeXProcessor('"Ejercicios 2 2023_2024"', version='2021/10/16 v3.6', version_check=True)
_st_.current_tex_line = 38
_st_.blockbegin()
try:
 AC = matrix(QQ, [[1, 1, 0], [-1, 0, 1], [1, 1, 1]])
 AB = matrix(QQ, [[2, 1, -1], [3, -2, 1], [-1, 2, 0]])
 B = AC * AB.inverse()
except:
 _st_.goboom(42)
_st_.blockend()
try:
 _st_.current_tex_line = 45
 _st_.inline(0, latex(AB))
except:
 _st_.goboom(45)
try:
 _st_.current_tex_line = 45
 _st_.inline(1, latex(AC))
except:
 _st_.goboom(45)
try:
 _st_.current_tex_line = 49
 _st_.inline(2, latex(AC))
except:
 _st_.goboom(49)
try:
 _st_.current_tex_line = 49
 _st_.inline(3, latex(AB))
except:
 _st_.goboom(49)
try:
 _st_.current_tex_line = 53
 _st_.inline(4, latex(B))
except:
 _st_.goboom(53)
_st_.current_tex_line = 79
_st_.blockbegin()
try:
 Mf1 = matrix(QQ, [[1, -1], [2, 1], [1, 2], [3, 0]])
 Mf2 = matrix(QQ, [[1, -2, 1, 2], [2, 0, 1, -1]])
 Mf4 = matrix(QQ, [[1, 2, 3, 0]])
except:
 _st_.goboom(83)
_st_.blockend()
try:
 _st_.current_tex_line = 87
 _st_.inline(5, latex(Mf1))
except:
 _st_.goboom(87)
try:
 _st_.current_tex_line = 91
 _st_.inline(6, latex(Mf2))
except:
 _st_.goboom(91)
try:
 _st_.current_tex_line = 96
 _st_.inline(7, latex(Mf4))
except:
 _st_.goboom(96)
_st_.current_tex_line = 117
_st_.blockbegin()
try:
 B = matrix(Zmod(5), [[1, 1, 0], [1, 1, 1], [-1, 1, 1]])
 Br = B.echelon_form()
 Bi = B.inverse()
except:
 _st_.goboom(121)
_st_.blockend()
try:
 _st_.current_tex_line = 124
 _st_.inline(8, latex(B))
except:
 _st_.goboom(124)
try:
 _st_.current_tex_line = 124
 _st_.inline(9, latex(Br))
except:
 _st_.goboom(124)
try:
 _st_.current_tex_line = 129
 _st_.inline(10, latex(B))
except:
 _st_.goboom(129)
try:
 _st_.current_tex_line = 133
 _st_.inline(11, latex(Bi))
except:
 _st_.goboom(133)
_st_.current_tex_line = 164
_st_.blockbegin()
try:
 B1 = matrix(Zmod(5), [[1, 1, 0], [0, 1, 1], [1, 0, 1]])
 B2 = matrix(Zmod(5), [[0, -1, 1], [0, 1, 1], [1, 0, 1]])
 B1r = B1.echelon_form()
 B2r = B2.echelon_form()
 B1i = B1.inverse()
 B2i = B2.inverse()
 PB1B2 = B2i * B1
except:
 _st_.goboom(172)
_st_.blockend()
try:
 _st_.current_tex_line = 175
 _st_.inline(12, latex(B1))
except:
 _st_.goboom(175)
try:
 _st_.current_tex_line = 175
 _st_.inline(13, latex(B1r))
except:
 _st_.goboom(175)
try:
 _st_.current_tex_line = 179
 _st_.inline(14, latex(B2))
except:
 _st_.goboom(179)
try:
 _st_.current_tex_line = 179
 _st_.inline(15, latex(B2r))
except:
 _st_.goboom(179)
try:
 _st_.current_tex_line = 185
 _st_.inline(16, latex(PB1B2))
except:
 _st_.goboom(185)
_st_.endofdoc()