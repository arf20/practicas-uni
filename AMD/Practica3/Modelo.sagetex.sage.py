## -*- encoding: utf-8 -*-


# This file was *autogenerated* from the file Modelo.sagetex.sage
from sage.all_cmdline import *   # import sage library

_sage_const_19 = Integer(19); _sage_const_23836 = Integer(23836); _sage_const_2 = Integer(2); _sage_const_30 = Integer(30); _sage_const_1 = Integer(1); _sage_const_15 = Integer(15); _sage_const_10 = Integer(10); _sage_const_20 = Integer(20); _sage_const_36 = Integer(36); _sage_const_41 = Integer(41); _sage_const_0 = Integer(0); _sage_const_48 = Integer(48); _sage_const_56 = Integer(56); _sage_const_59 = Integer(59); _sage_const_63 = Integer(63); _sage_const_3 = Integer(3); _sage_const_66 = Integer(66); _sage_const_4 = Integer(4); _sage_const_5 = Integer(5); _sage_const_69 = Integer(69); _sage_const_6 = Integer(6); _sage_const_7 = Integer(7); _sage_const_8 = Integer(8); _sage_const_71 = Integer(71); _sage_const_9 = Integer(9); _sage_const_73 = Integer(73); _sage_const_11 = Integer(11); _sage_const_12 = Integer(12); _sage_const_13 = Integer(13); _sage_const_14 = Integer(14); _sage_const_77 = Integer(77); _sage_const_16 = Integer(16); _sage_const_17 = Integer(17); _sage_const_18 = Integer(18); _sage_const_81 = Integer(81); _sage_const_21 = Integer(21); _sage_const_88 = Integer(88); _sage_const_22 = Integer(22); _sage_const_23 = Integer(23); _sage_const_24 = Integer(24); _sage_const_96 = Integer(96); _sage_const_101 = Integer(101); _sage_const_104 = Integer(104); _sage_const_25 = Integer(25); _sage_const_108 = Integer(108); _sage_const_26 = Integer(26); _sage_const_111 = Integer(111); _sage_const_27 = Integer(27); _sage_const_28 = Integer(28); _sage_const_114 = Integer(114); _sage_const_29 = Integer(29); _sage_const_31 = Integer(31); _sage_const_122 = Integer(122); _sage_const_32 = Integer(32); _sage_const_33 = Integer(33); _sage_const_34 = Integer(34); _sage_const_35 = Integer(35); _sage_const_37 = Integer(37); _sage_const_38 = Integer(38); _sage_const_39 = Integer(39); _sage_const_40 = Integer(40); _sage_const_129 = Integer(129); _sage_const_42 = Integer(42); _sage_const_43 = Integer(43); _sage_const_44 = Integer(44); _sage_const_45 = Integer(45); _sage_const_46 = Integer(46); _sage_const_47 = Integer(47); _sage_const_49 = Integer(49); _sage_const_50 = Integer(50); _sage_const_51 = Integer(51); _sage_const_52 = Integer(52); _sage_const_53 = Integer(53); _sage_const_134 = Integer(134); _sage_const_54 = Integer(54); _sage_const_55 = Integer(55); _sage_const_57 = Integer(57); _sage_const_58 = Integer(58); _sage_const_60 = Integer(60); _sage_const_142 = Integer(142); _sage_const_61 = Integer(61); _sage_const_62 = Integer(62); _sage_const_64 = Integer(64); _sage_const_152 = Integer(152); _sage_const_65 = Integer(65); _sage_const_67 = Integer(67); _sage_const_68 = Integer(68); _sage_const_158 = Integer(158); _sage_const_1792944400 = Integer(1792944400); _sage_const_16054429802 = Integer(16054429802); _sage_const_177 = Integer(177); _sage_const_179 = Integer(179); _sage_const_70 = Integer(70); _sage_const_183 = Integer(183); _sage_const_187 = Integer(187); _sage_const_72 = Integer(72); _sage_const_190 = Integer(190); _sage_const_74 = Integer(74); _sage_const_75 = Integer(75); _sage_const_195 = Integer(195); _sage_const_76 = Integer(76); _sage_const_78 = Integer(78); _sage_const_79 = Integer(79); _sage_const_198 = Integer(198); _sage_const_80 = Integer(80); _sage_const_82 = Integer(82); _sage_const_83 = Integer(83); _sage_const_202 = Integer(202); _sage_const_84 = Integer(84); _sage_const_85 = Integer(85); _sage_const_86 = Integer(86); _sage_const_206 = Integer(206); _sage_const_87 = Integer(87); _sage_const_89 = Integer(89); _sage_const_211 = Integer(211); _sage_const_90 = Integer(90); _sage_const_91 = Integer(91); _sage_const_92 = Integer(92); _sage_const_217 = Integer(217); _sage_const_93 = Integer(93); _sage_const_94 = Integer(94); _sage_const_95 = Integer(95); _sage_const_97 = Integer(97); _sage_const_98 = Integer(98); _sage_const_99 = Integer(99); _sage_const_100 = Integer(100); _sage_const_102 = Integer(102); _sage_const_224 = Integer(224); _sage_const_103 = Integer(103); _sage_const_105 = Integer(105); _sage_const_106 = Integer(106); _sage_const_107 = Integer(107); _sage_const_109 = Integer(109); _sage_const_110 = Integer(110); _sage_const_112 = Integer(112); _sage_const_113 = Integer(113); _sage_const_229 = Integer(229); _sage_const_115 = Integer(115); _sage_const_116 = Integer(116); _sage_const_117 = Integer(117); _sage_const_118 = Integer(118); _sage_const_119 = Integer(119); _sage_const_120 = Integer(120); _sage_const_121 = Integer(121); _sage_const_235 = Integer(235); _sage_const_123 = Integer(123); _sage_const_124 = Integer(124); _sage_const_125 = Integer(125); _sage_const_241 = Integer(241); _sage_const_126 = Integer(126); _sage_const_127 = Integer(127); _sage_const_128 = Integer(128); _sage_const_130 = Integer(130); _sage_const_131 = Integer(131); _sage_const_132 = Integer(132); _sage_const_133 = Integer(133); _sage_const_135 = Integer(135); _sage_const_136 = Integer(136)## This file (Modelo.sagetex.sage) was *autogenerated* from Modelo.tex with sagetex.sty version 2021/10/16 v3.6.
import sagetex
_st_ = sagetex.SageTeXProcessor('Modelo', version='2021/10/16 v3.6', version_check=True)
_st_.current_tex_line = _sage_const_19 
_st_.blockbegin()
try:
 set_random_seed(_sage_const_23836 ) # Cambia este número por las 5 primeras cifras de tu DNI o NIE
 
 n1 = ZZ.random_element(_sage_const_2 **_sage_const_30 )
 x1 = ZZ.random_element(n1)
 while(gcd(x1,n1)!=_sage_const_1 ):
   x1 = ZZ.random_element(n1)
 a2 = ZZ.random_element(_sage_const_2 **_sage_const_15 )
 b2 = ZZ.random_element(_sage_const_2 **_sage_const_15 )
 m2 = gcd(a2,b2)*ZZ.random_element(_sage_const_2 **_sage_const_10 )
 p3 = ZZ.random_element(_sage_const_2 **_sage_const_20 ).next_prime()
 m31 = p3*ZZ.random_element(_sage_const_2 **_sage_const_15 )
 m32 = p3*ZZ.random_element(_sage_const_2 **_sage_const_15 )
 g3 = gcd(m31,m32)
 n3 = ZZ.random_element(m31*m32)
 a3 = Zmod(m31)(n3)
 b3 = Zmod(m32)(n3)
except:
 _st_.goboom(_sage_const_36 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_41 
 _st_.inline(_sage_const_0 , latex(x1))
except:
 _st_.goboom(_sage_const_41 )
try:
 _st_.current_tex_line = _sage_const_41 
 _st_.inline(_sage_const_1 , latex(n1))
except:
 _st_.goboom(_sage_const_41 )
_st_.current_tex_line = _sage_const_48 
_st_.blockbegin()
try:
 A = matrix(ZZ, [[x1], [n1]])
 Ap = block_matrix([[A, _sage_const_1 ]])
 Ar = Ap.echelon_form()
 Ar = copy(Ar)
 Ar.subdivide([], _sage_const_1 )
 S = Ar.subdivision(_sage_const_0 , _sage_const_1 )
 R = S * A
except:
 _st_.goboom(_sage_const_56 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_59 
 _st_.inline(_sage_const_2 , latex(Ap))
except:
 _st_.goboom(_sage_const_59 )
try:
 _st_.current_tex_line = _sage_const_63 
 _st_.inline(_sage_const_3 , latex(Ar))
except:
 _st_.goboom(_sage_const_63 )
try:
 _st_.current_tex_line = _sage_const_66 
 _st_.inline(_sage_const_4 , latex(x1))
except:
 _st_.goboom(_sage_const_66 )
try:
 _st_.current_tex_line = _sage_const_66 
 _st_.inline(_sage_const_5 , latex(n1))
except:
 _st_.goboom(_sage_const_66 )
try:
 _st_.current_tex_line = _sage_const_69 
 _st_.inline(_sage_const_6 , latex(S))
except:
 _st_.goboom(_sage_const_69 )
try:
 _st_.current_tex_line = _sage_const_69 
 _st_.inline(_sage_const_7 , latex(A))
except:
 _st_.goboom(_sage_const_69 )
try:
 _st_.current_tex_line = _sage_const_69 
 _st_.inline(_sage_const_8 , latex(R))
except:
 _st_.goboom(_sage_const_69 )
try:
 _st_.current_tex_line = _sage_const_71 
 _st_.inline(_sage_const_9 , latex(x1))
except:
 _st_.goboom(_sage_const_71 )
try:
 _st_.current_tex_line = _sage_const_71 
 _st_.inline(_sage_const_10 , latex(n1))
except:
 _st_.goboom(_sage_const_71 )
try:
 _st_.current_tex_line = _sage_const_73 
 _st_.inline(_sage_const_11 , latex(S[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_73 )
try:
 _st_.current_tex_line = _sage_const_73 
 _st_.inline(_sage_const_12 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_73 )
try:
 _st_.current_tex_line = _sage_const_73 
 _st_.inline(_sage_const_13 , latex(S[_sage_const_0 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_73 )
try:
 _st_.current_tex_line = _sage_const_73 
 _st_.inline(_sage_const_14 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_73 )
try:
 _st_.current_tex_line = _sage_const_73 
 _st_.inline(_sage_const_15 , latex(R[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_73 )
try:
 _st_.current_tex_line = _sage_const_77 
 _st_.inline(_sage_const_16 , latex(S[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_77 )
try:
 _st_.current_tex_line = _sage_const_77 
 _st_.inline(_sage_const_17 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_77 )
try:
 _st_.current_tex_line = _sage_const_77 
 _st_.inline(_sage_const_18 , latex(R[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_77 )
try:
 _st_.current_tex_line = _sage_const_81 
 _st_.inline(_sage_const_19 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_81 )
try:
 _st_.current_tex_line = _sage_const_81 
 _st_.inline(_sage_const_20 , latex(S[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_81 )
try:
 _st_.current_tex_line = _sage_const_81 
 _st_.inline(_sage_const_21 , latex(n1))
except:
 _st_.goboom(_sage_const_81 )
try:
 _st_.current_tex_line = _sage_const_88 
 _st_.inline(_sage_const_22 , latex(a2))
except:
 _st_.goboom(_sage_const_88 )
try:
 _st_.current_tex_line = _sage_const_88 
 _st_.inline(_sage_const_23 , latex(b2))
except:
 _st_.goboom(_sage_const_88 )
try:
 _st_.current_tex_line = _sage_const_88 
 _st_.inline(_sage_const_24 , latex(m2))
except:
 _st_.goboom(_sage_const_88 )
_st_.current_tex_line = _sage_const_96 
_st_.blockbegin()
try:
 A = matrix(ZZ, [[a2], [b2]])
 Ap = block_matrix([[A, _sage_const_1 ]])
 Ar = Ap.echelon_form()
 R = Ar[:, _sage_const_1 :] * A
except:
 _st_.goboom(_sage_const_101 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_104 
 _st_.inline(_sage_const_25 , latex(Ap))
except:
 _st_.goboom(_sage_const_104 )
try:
 _st_.current_tex_line = _sage_const_108 
 _st_.inline(_sage_const_26 , latex(Ar))
except:
 _st_.goboom(_sage_const_108 )
try:
 _st_.current_tex_line = _sage_const_111 
 _st_.inline(_sage_const_27 , latex(a2))
except:
 _st_.goboom(_sage_const_111 )
try:
 _st_.current_tex_line = _sage_const_111 
 _st_.inline(_sage_const_28 , latex(b2))
except:
 _st_.goboom(_sage_const_111 )
try:
 _st_.current_tex_line = _sage_const_114 
 _st_.inline(_sage_const_29 , latex(Ar[:, _sage_const_1 :]))
except:
 _st_.goboom(_sage_const_114 )
try:
 _st_.current_tex_line = _sage_const_114 
 _st_.inline(_sage_const_30 , latex(A))
except:
 _st_.goboom(_sage_const_114 )
try:
 _st_.current_tex_line = _sage_const_114 
 _st_.inline(_sage_const_31 , latex(R))
except:
 _st_.goboom(_sage_const_114 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_32 , latex(Ar[_sage_const_0 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_33 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_34 , latex(Ar[_sage_const_0 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_35 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_36 , latex(R[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_37 , latex(Ar[_sage_const_1 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_38 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_39 , latex(Ar[_sage_const_1 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_40 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_41 , latex(R[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_32 , latex(Ar[_sage_const_0 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_33 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_34 , latex(Ar[_sage_const_0 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_35 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_36 , latex(R[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_37 , latex(Ar[_sage_const_1 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_38 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_39 , latex(Ar[_sage_const_1 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_40 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_122 
 _st_.inline(_sage_const_41 , latex(R[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_122 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_42 , latex(Ar[_sage_const_0 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_43 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_44 , latex(m2))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_45 , latex(Ar[_sage_const_0 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_46 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_47 , latex(m2))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_48 , latex(m2))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_49 , latex(Ar[_sage_const_1 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_50 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_51 , latex(Ar[_sage_const_1 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_52 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_53 , latex(R[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_42 , latex(Ar[_sage_const_0 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_43 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_44 , latex(m2))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_45 , latex(Ar[_sage_const_0 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_46 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_47 , latex(m2))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_48 , latex(m2))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_49 , latex(Ar[_sage_const_1 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_50 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_51 , latex(Ar[_sage_const_1 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_52 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_129 
 _st_.inline(_sage_const_53 , latex(R[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_129 )
try:
 _st_.current_tex_line = _sage_const_134 
 _st_.inline(_sage_const_54 , latex(A[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_134 )
try:
 _st_.current_tex_line = _sage_const_134 
 _st_.inline(_sage_const_55 , latex(Ar[_sage_const_0 ][_sage_const_1 ] * m2))
except:
 _st_.goboom(_sage_const_134 )
try:
 _st_.current_tex_line = _sage_const_134 
 _st_.inline(_sage_const_56 , latex(Ar[_sage_const_1 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_134 )
try:
 _st_.current_tex_line = _sage_const_134 
 _st_.inline(_sage_const_57 , latex(A[_sage_const_1 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_134 )
try:
 _st_.current_tex_line = _sage_const_134 
 _st_.inline(_sage_const_58 , latex(Ar[_sage_const_0 ][_sage_const_2 ] * m2))
except:
 _st_.goboom(_sage_const_134 )
try:
 _st_.current_tex_line = _sage_const_134 
 _st_.inline(_sage_const_59 , latex(Ar[_sage_const_1 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_134 )
try:
 _st_.current_tex_line = _sage_const_134 
 _st_.inline(_sage_const_60 , latex(m2))
except:
 _st_.goboom(_sage_const_134 )
try:
 _st_.current_tex_line = _sage_const_142 
 _st_.inline(_sage_const_61 , latex(Ar[_sage_const_0 ][_sage_const_1 ] * m2))
except:
 _st_.goboom(_sage_const_142 )
try:
 _st_.current_tex_line = _sage_const_142 
 _st_.inline(_sage_const_62 , latex(Ar[_sage_const_1 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_142 )
try:
 _st_.current_tex_line = _sage_const_142 
 _st_.inline(_sage_const_63 , latex(Ar[_sage_const_0 ][_sage_const_2 ] * m2))
except:
 _st_.goboom(_sage_const_142 )
try:
 _st_.current_tex_line = _sage_const_142 
 _st_.inline(_sage_const_64 , latex(Ar[_sage_const_1 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_142 )
try:
 _st_.current_tex_line = _sage_const_142 
 _st_.inline(_sage_const_61 , latex(Ar[_sage_const_0 ][_sage_const_1 ] * m2))
except:
 _st_.goboom(_sage_const_142 )
try:
 _st_.current_tex_line = _sage_const_142 
 _st_.inline(_sage_const_62 , latex(Ar[_sage_const_1 ][_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_142 )
try:
 _st_.current_tex_line = _sage_const_142 
 _st_.inline(_sage_const_63 , latex(Ar[_sage_const_0 ][_sage_const_2 ] * m2))
except:
 _st_.goboom(_sage_const_142 )
try:
 _st_.current_tex_line = _sage_const_142 
 _st_.inline(_sage_const_64 , latex(Ar[_sage_const_1 ][_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_142 )
try:
 _st_.current_tex_line = _sage_const_152 
 _st_.inline(_sage_const_65 , latex(a3))
except:
 _st_.goboom(_sage_const_152 )
try:
 _st_.current_tex_line = _sage_const_152 
 _st_.inline(_sage_const_66 , latex(m31))
except:
 _st_.goboom(_sage_const_152 )
try:
 _st_.current_tex_line = _sage_const_152 
 _st_.inline(_sage_const_67 , latex(b3))
except:
 _st_.goboom(_sage_const_152 )
try:
 _st_.current_tex_line = _sage_const_152 
 _st_.inline(_sage_const_68 , latex(m32))
except:
 _st_.goboom(_sage_const_152 )
try:
 _st_.current_tex_line = _sage_const_152 
 _st_.inline(_sage_const_65 , latex(a3))
except:
 _st_.goboom(_sage_const_152 )
try:
 _st_.current_tex_line = _sage_const_152 
 _st_.inline(_sage_const_66 , latex(m31))
except:
 _st_.goboom(_sage_const_152 )
try:
 _st_.current_tex_line = _sage_const_152 
 _st_.inline(_sage_const_67 , latex(b3))
except:
 _st_.goboom(_sage_const_152 )
try:
 _st_.current_tex_line = _sage_const_152 
 _st_.inline(_sage_const_68 , latex(m32))
except:
 _st_.goboom(_sage_const_152 )
_st_.current_tex_line = _sage_const_158 
_st_.blockbegin()
try:
 A = matrix(ZZ, [[m31], [-m32]])
 Ap = block_matrix([[A, _sage_const_1 ]])
 Ar = Ap.echelon_form()
 Ar = copy(Ar)
 Ar.subdivide([], _sage_const_1 )
 As = Ar[:, _sage_const_1 :]
 R = Ar[:, :_sage_const_1 ]
 
 mcd = R[_sage_const_0 , _sage_const_0 ]
 
 a3n = _sage_const_1792944400 
 b3n = _sage_const_16054429802 
 d = b3n - a3n
 
 F = d / mcd
 
 c3 = a3n + (m31 * As[_sage_const_0 , _sage_const_0 ] * F)
 cm3 = m31 * As[_sage_const_1 , _sage_const_0 ]
except:
 _st_.goboom(_sage_const_177 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_179 
 _st_.inline(_sage_const_69 , latex(m31))
except:
 _st_.goboom(_sage_const_179 )
try:
 _st_.current_tex_line = _sage_const_179 
 _st_.inline(_sage_const_70 , latex(m32))
except:
 _st_.goboom(_sage_const_179 )
try:
 _st_.current_tex_line = _sage_const_183 
 _st_.inline(_sage_const_71 , latex(Ap))
except:
 _st_.goboom(_sage_const_183 )
try:
 _st_.current_tex_line = _sage_const_187 
 _st_.inline(_sage_const_72 , latex(Ar))
except:
 _st_.goboom(_sage_const_187 )
try:
 _st_.current_tex_line = _sage_const_190 
 _st_.inline(_sage_const_73 , latex(m31))
except:
 _st_.goboom(_sage_const_190 )
try:
 _st_.current_tex_line = _sage_const_190 
 _st_.inline(_sage_const_74 , latex(m32))
except:
 _st_.goboom(_sage_const_190 )
try:
 _st_.current_tex_line = _sage_const_190 
 _st_.inline(_sage_const_75 , latex(Ar[_sage_const_0 ][_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_190 )
try:
 _st_.current_tex_line = _sage_const_195 
 _st_.inline(_sage_const_76 , latex(a3))
except:
 _st_.goboom(_sage_const_195 )
try:
 _st_.current_tex_line = _sage_const_195 
 _st_.inline(_sage_const_77 , latex(m31))
except:
 _st_.goboom(_sage_const_195 )
try:
 _st_.current_tex_line = _sage_const_195 
 _st_.inline(_sage_const_78 , latex(b3))
except:
 _st_.goboom(_sage_const_195 )
try:
 _st_.current_tex_line = _sage_const_195 
 _st_.inline(_sage_const_79 , latex(m32))
except:
 _st_.goboom(_sage_const_195 )
try:
 _st_.current_tex_line = _sage_const_195 
 _st_.inline(_sage_const_76 , latex(a3))
except:
 _st_.goboom(_sage_const_195 )
try:
 _st_.current_tex_line = _sage_const_195 
 _st_.inline(_sage_const_77 , latex(m31))
except:
 _st_.goboom(_sage_const_195 )
try:
 _st_.current_tex_line = _sage_const_195 
 _st_.inline(_sage_const_78 , latex(b3))
except:
 _st_.goboom(_sage_const_195 )
try:
 _st_.current_tex_line = _sage_const_195 
 _st_.inline(_sage_const_79 , latex(m32))
except:
 _st_.goboom(_sage_const_195 )
try:
 _st_.current_tex_line = _sage_const_198 
 _st_.inline(_sage_const_80 , latex(a3))
except:
 _st_.goboom(_sage_const_198 )
try:
 _st_.current_tex_line = _sage_const_198 
 _st_.inline(_sage_const_81 , latex(m31))
except:
 _st_.goboom(_sage_const_198 )
try:
 _st_.current_tex_line = _sage_const_198 
 _st_.inline(_sage_const_82 , latex(b3))
except:
 _st_.goboom(_sage_const_198 )
try:
 _st_.current_tex_line = _sage_const_198 
 _st_.inline(_sage_const_83 , latex(m32))
except:
 _st_.goboom(_sage_const_198 )
try:
 _st_.current_tex_line = _sage_const_202 
 _st_.inline(_sage_const_84 , latex(m31))
except:
 _st_.goboom(_sage_const_202 )
try:
 _st_.current_tex_line = _sage_const_202 
 _st_.inline(_sage_const_85 , latex(m32))
except:
 _st_.goboom(_sage_const_202 )
try:
 _st_.current_tex_line = _sage_const_202 
 _st_.inline(_sage_const_86 , latex(d))
except:
 _st_.goboom(_sage_const_202 )
try:
 _st_.current_tex_line = _sage_const_206 
 _st_.inline(_sage_const_87 , latex(d))
except:
 _st_.goboom(_sage_const_206 )
try:
 _st_.current_tex_line = _sage_const_206 
 _st_.inline(_sage_const_88 , latex(mcd))
except:
 _st_.goboom(_sage_const_206 )
try:
 _st_.current_tex_line = _sage_const_206 
 _st_.inline(_sage_const_89 , latex(F))
except:
 _st_.goboom(_sage_const_206 )
try:
 _st_.current_tex_line = _sage_const_211 
 _st_.inline(_sage_const_90 , latex(As))
except:
 _st_.goboom(_sage_const_211 )
try:
 _st_.current_tex_line = _sage_const_211 
 _st_.inline(_sage_const_91 , latex(A))
except:
 _st_.goboom(_sage_const_211 )
try:
 _st_.current_tex_line = _sage_const_211 
 _st_.inline(_sage_const_92 , latex(R))
except:
 _st_.goboom(_sage_const_211 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_93 , latex(As[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_94 , latex(A[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_95 , latex(As[_sage_const_0 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_96 , latex(A[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_97 , latex(R[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_98 , latex(As[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_99 , latex(A[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_100 , latex(As[_sage_const_1 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_101 , latex(A[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_102 , latex(R[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_93 , latex(As[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_94 , latex(A[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_95 , latex(As[_sage_const_0 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_96 , latex(A[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_97 , latex(R[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_98 , latex(As[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_99 , latex(A[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_100 , latex(As[_sage_const_1 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_101 , latex(A[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_217 
 _st_.inline(_sage_const_102 , latex(R[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_217 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_103 , latex(As[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_104 , latex(A[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_105 , latex(F))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_106 , latex(As[_sage_const_0 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_107 , latex(A[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_108 , latex(F))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_109 , latex(R[_sage_const_0 , _sage_const_0 ] * F))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_110 , latex(As[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_111 , latex(A[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_112 , latex(As[_sage_const_1 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_113 , latex(A[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_114 , latex(R[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_103 , latex(As[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_104 , latex(A[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_105 , latex(F))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_106 , latex(As[_sage_const_0 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_107 , latex(A[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_108 , latex(F))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_109 , latex(R[_sage_const_0 , _sage_const_0 ] * F))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_110 , latex(As[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_111 , latex(A[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_112 , latex(As[_sage_const_1 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_113 , latex(A[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_224 
 _st_.inline(_sage_const_114 , latex(R[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_224 )
try:
 _st_.current_tex_line = _sage_const_229 
 _st_.inline(_sage_const_115 , latex(A[_sage_const_0 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_229 )
try:
 _st_.current_tex_line = _sage_const_229 
 _st_.inline(_sage_const_116 , latex(As[_sage_const_0 , _sage_const_0 ] * F))
except:
 _st_.goboom(_sage_const_229 )
try:
 _st_.current_tex_line = _sage_const_229 
 _st_.inline(_sage_const_117 , latex(As[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_229 )
try:
 _st_.current_tex_line = _sage_const_229 
 _st_.inline(_sage_const_118 , latex(A[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_229 )
try:
 _st_.current_tex_line = _sage_const_229 
 _st_.inline(_sage_const_119 , latex(As[_sage_const_0 , _sage_const_1 ] * F))
except:
 _st_.goboom(_sage_const_229 )
try:
 _st_.current_tex_line = _sage_const_229 
 _st_.inline(_sage_const_120 , latex(As[_sage_const_1 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_229 )
try:
 _st_.current_tex_line = _sage_const_229 
 _st_.inline(_sage_const_121 , latex(d))
except:
 _st_.goboom(_sage_const_229 )
try:
 _st_.current_tex_line = _sage_const_235 
 _st_.inline(_sage_const_122 , latex(As[_sage_const_0 , _sage_const_0 ] * F))
except:
 _st_.goboom(_sage_const_235 )
try:
 _st_.current_tex_line = _sage_const_235 
 _st_.inline(_sage_const_123 , latex(As[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_235 )
try:
 _st_.current_tex_line = _sage_const_235 
 _st_.inline(_sage_const_124 , latex(As[_sage_const_0 , _sage_const_1 ] * F))
except:
 _st_.goboom(_sage_const_235 )
try:
 _st_.current_tex_line = _sage_const_235 
 _st_.inline(_sage_const_125 , latex(As[_sage_const_1 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_235 )
try:
 _st_.current_tex_line = _sage_const_235 
 _st_.inline(_sage_const_122 , latex(As[_sage_const_0 , _sage_const_0 ] * F))
except:
 _st_.goboom(_sage_const_235 )
try:
 _st_.current_tex_line = _sage_const_235 
 _st_.inline(_sage_const_123 , latex(As[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_235 )
try:
 _st_.current_tex_line = _sage_const_235 
 _st_.inline(_sage_const_124 , latex(As[_sage_const_0 , _sage_const_1 ] * F))
except:
 _st_.goboom(_sage_const_235 )
try:
 _st_.current_tex_line = _sage_const_235 
 _st_.inline(_sage_const_125 , latex(As[_sage_const_1 , _sage_const_1 ]))
except:
 _st_.goboom(_sage_const_235 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_126 , latex(a3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_127 , latex(m31))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_128 , latex(a3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_129 , latex(m31))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_130 , latex(As[_sage_const_0 , _sage_const_0 ] * F))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_131 , latex(As[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_132 , latex(c3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_133 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_134 , latex(c3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_135 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_136 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_136 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_136 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_126 , latex(a3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_127 , latex(m31))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_128 , latex(a3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_129 , latex(m31))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_130 , latex(As[_sage_const_0 , _sage_const_0 ] * F))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_131 , latex(As[_sage_const_1 , _sage_const_0 ]))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_132 , latex(c3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_133 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_134 , latex(c3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_135 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_136 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_136 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
try:
 _st_.current_tex_line = _sage_const_241 
 _st_.inline(_sage_const_136 , latex(cm3))
except:
 _st_.goboom(_sage_const_241 )
_st_.endofdoc()

