## -*- encoding: utf-8 -*-


# This file was *autogenerated* from the file PracticasBasesyCoordenadasTarea.sagetex.sage
from sage.all_cmdline import *   # import sage library

_sage_const_20 = Integer(20); _sage_const_22 = Integer(22); _sage_const_47 = Integer(47); _sage_const_7 = Integer(7); _sage_const_0 = Integer(0); _sage_const_2 = Integer(2); _sage_const_3 = Integer(3); _sage_const_1 = Integer(1); _sage_const_4 = Integer(4); _sage_const_6 = Integer(6); _sage_const_5 = Integer(5); _sage_const_54 = Integer(54); _sage_const_61 = Integer(61); _sage_const_65 = Integer(65); _sage_const_70 = Integer(70); _sage_const_94 = Integer(94); _sage_const_8 = Integer(8); _sage_const_100 = Integer(100); _sage_const_103 = Integer(103); _sage_const_136 = Integer(136); _sage_const_15 = Integer(15); _sage_const_38 = Integer(38); _sage_const_10 = Integer(10); _sage_const_31 = Integer(31); _sage_const_14 = Integer(14); _sage_const_23 = Integer(23); _sage_const_148 = Integer(148); _sage_const_153 = Integer(153); _sage_const_157 = Integer(157); _sage_const_161 = Integer(161); _sage_const_165 = Integer(165); _sage_const_9 = Integer(9); _sage_const_11 = Integer(11); _sage_const_176 = Integer(176); _sage_const_12 = Integer(12); _sage_const_194 = Integer(194); _sage_const_197 = Integer(197); _sage_const_211 = Integer(211); _sage_const_13 = Integer(13); _sage_const_229 = Integer(229); _sage_const_233 = Integer(233); _sage_const_264 = Integer(264); _sage_const_16 = Integer(16); _sage_const_265 = Integer(265); _sage_const_17 = Integer(17); _sage_const_279 = Integer(279); _sage_const_283 = Integer(283); _sage_const_314 = Integer(314); _sage_const_18 = Integer(18); _sage_const_19 = Integer(19); _sage_const_315 = Integer(315); _sage_const_21 = Integer(21); _sage_const_351 = Integer(351); _sage_const_356 = Integer(356); _sage_const_369 = Integer(369); _sage_const_24 = Integer(24); _sage_const_25 = Integer(25); _sage_const_387 = Integer(387); _sage_const_391 = Integer(391); _sage_const_419 = Integer(419); _sage_const_26 = Integer(26); _sage_const_27 = Integer(27); _sage_const_28 = Integer(28); _sage_const_420 = Integer(420); _sage_const_29 = Integer(29); _sage_const_433 = Integer(433); _sage_const_437 = Integer(437); _sage_const_470 = Integer(470); _sage_const_30 = Integer(30); _sage_const_32 = Integer(32); _sage_const_33 = Integer(33); _sage_const_487 = Integer(487); _sage_const_491 = Integer(491); _sage_const_522 = Integer(522); _sage_const_34 = Integer(34); _sage_const_35 = Integer(35); _sage_const_36 = Integer(36); _sage_const_37 = Integer(37); _sage_const_537 = Integer(537); _sage_const_546 = Integer(546); _sage_const_549 = Integer(549); _sage_const_39 = Integer(39); _sage_const_556 = Integer(556); _sage_const_40 = Integer(40); _sage_const_41 = Integer(41); _sage_const_42 = Integer(42); _sage_const_559 = Integer(559); _sage_const_43 = Integer(43); _sage_const_565 = Integer(565); _sage_const_44 = Integer(44); _sage_const_45 = Integer(45); _sage_const_46 = Integer(46); _sage_const_568 = Integer(568); _sage_const_48 = Integer(48); _sage_const_49 = Integer(49); _sage_const_570 = Integer(570); _sage_const_50 = Integer(50); _sage_const_51 = Integer(51); _sage_const_584 = Integer(584); _sage_const_587 = Integer(587); _sage_const_590 = Integer(590); _sage_const_52 = Integer(52); _sage_const_593 = Integer(593); _sage_const_53 = Integer(53); _sage_const_55 = Integer(55); _sage_const_609 = Integer(609); _sage_const_612 = Integer(612); _sage_const_615 = Integer(615); _sage_const_56 = Integer(56); _sage_const_616 = Integer(616); _sage_const_57 = Integer(57); _sage_const_58 = Integer(58); _sage_const_59 = Integer(59); _sage_const_632 = Integer(632); _sage_const_639 = Integer(639); _sage_const_642 = Integer(642); _sage_const_60 = Integer(60); _sage_const_645 = Integer(645); _sage_const_62 = Integer(62); _sage_const_63 = Integer(63); _sage_const_659 = Integer(659); _sage_const_662 = Integer(662); _sage_const_665 = Integer(665); _sage_const_64 = Integer(64); _sage_const_666 = Integer(666); _sage_const_66 = Integer(66); _sage_const_67 = Integer(67); _sage_const_689 = Integer(689); _sage_const_694 = Integer(694); _sage_const_698 = Integer(698); _sage_const_68 = Integer(68); _sage_const_700 = Integer(700); _sage_const_69 = Integer(69); _sage_const_728 = Integer(728); _sage_const_735 = Integer(735); _sage_const_739 = Integer(739); _sage_const_71 = Integer(71); _sage_const_743 = Integer(743); _sage_const_72 = Integer(72); _sage_const_774 = Integer(774); _sage_const_779 = Integer(779); _sage_const_782 = Integer(782); _sage_const_73 = Integer(73); _sage_const_74 = Integer(74); _sage_const_804 = Integer(804); _sage_const_813 = Integer(813); _sage_const_820 = Integer(820); _sage_const_75 = Integer(75); _sage_const_824 = Integer(824); _sage_const_76 = Integer(76); _sage_const_828 = Integer(828); _sage_const_77 = Integer(77); _sage_const_831 = Integer(831); _sage_const_78 = Integer(78); _sage_const_79 = Integer(79); _sage_const_80 = Integer(80); _sage_const_853 = Integer(853); _sage_const_863 = Integer(863); _sage_const_870 = Integer(870); _sage_const_81 = Integer(81); _sage_const_874 = Integer(874); _sage_const_82 = Integer(82); _sage_const_878 = Integer(878); _sage_const_83 = Integer(83); _sage_const_881 = Integer(881); _sage_const_84 = Integer(84); _sage_const_85 = Integer(85); _sage_const_86 = Integer(86); _sage_const_904 = Integer(904); _sage_const_913 = Integer(913); _sage_const_920 = Integer(920); _sage_const_87 = Integer(87); _sage_const_924 = Integer(924); _sage_const_88 = Integer(88); _sage_const_928 = Integer(928); _sage_const_89 = Integer(89); _sage_const_932 = Integer(932); _sage_const_90 = Integer(90); _sage_const_954 = Integer(954); _sage_const_966 = Integer(966); _sage_const_969 = Integer(969); _sage_const_91 = Integer(91); _sage_const_92 = Integer(92); _sage_const_974 = Integer(974); _sage_const_93 = Integer(93); _sage_const_980 = Integer(980); _sage_const_95 = Integer(95)## This file (PracticasBasesyCoordenadasTarea.sagetex.sage) was *autogenerated* from PracticasBasesyCoordenadasTarea.tex with sagetex.sty version 2021/10/16 v3.6.
import sagetex
_st_ = sagetex.SageTeXProcessor('PracticasBasesyCoordenadasTarea', version='2021/10/16 v3.6', version_check=True)
_st_.current_tex_line = _sage_const_20 
_st_.blockbegin()
try:
 latex.matrix_delimiters("[", "]")
except:
 _st_.goboom(_sage_const_22 )
_st_.blockend()
_st_.current_tex_line = _sage_const_47 
_st_.blockbegin()
try:
 B=matrix(Zmod(_sage_const_7 ),[[_sage_const_0 ,_sage_const_2 ,_sage_const_2 ,_sage_const_2 ,_sage_const_3 ,_sage_const_1 ],[_sage_const_4 ,_sage_const_0 ,_sage_const_4 ,_sage_const_6 ,_sage_const_6 ,_sage_const_6 ],
 [_sage_const_6 ,_sage_const_1 ,_sage_const_5 ,_sage_const_1 ,_sage_const_2 ,_sage_const_3 ],[_sage_const_4 ,_sage_const_3 ,_sage_const_0 ,_sage_const_2 ,_sage_const_6 ,_sage_const_1 ],
 [_sage_const_2 ,_sage_const_6 ,_sage_const_6 ,_sage_const_4 ,_sage_const_4 ,_sage_const_0 ],[_sage_const_4 ,_sage_const_3 ,_sage_const_5 ,_sage_const_3 ,_sage_const_5 ,_sage_const_5 ]])
 y=column_matrix(Zmod(_sage_const_7 ),[_sage_const_2 ,_sage_const_2 ,_sage_const_1 ,_sage_const_5 ,_sage_const_0 ,_sage_const_4 ])
 By = block_matrix(_sage_const_1 ,_sage_const_2 ,[B,y])
 R=By.echelon_form()
except:
 _st_.goboom(_sage_const_54 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_61 
 _st_.inline(_sage_const_0 , latex(By))
except:
 _st_.goboom(_sage_const_61 )
try:
 _st_.current_tex_line = _sage_const_65 
 _st_.inline(_sage_const_1 , latex(R))
except:
 _st_.goboom(_sage_const_65 )
try:
 _st_.current_tex_line = _sage_const_70 
 _st_.inline(_sage_const_2 , latex(y))
except:
 _st_.goboom(_sage_const_70 )
try:
 _st_.current_tex_line = _sage_const_70 
 _st_.inline(_sage_const_3 , latex(R.subdivision(_sage_const_0 ,_sage_const_1 )))
except:
 _st_.goboom(_sage_const_70 )
_st_.current_tex_line = _sage_const_94 
_st_.blockbegin()
try:
 B = matrix(QQ, [[_sage_const_1 , -_sage_const_2 , -_sage_const_5 ], [_sage_const_0 , _sage_const_1 , _sage_const_3 ], [_sage_const_3 , -_sage_const_4 , -_sage_const_8 ], [-_sage_const_1 , _sage_const_0 , _sage_const_4 ], [_sage_const_1 , -_sage_const_4 , -_sage_const_6 ]])
 y = column_matrix(QQ, [-_sage_const_5 , _sage_const_3 , -_sage_const_8 , _sage_const_4 , -_sage_const_5 ])
 
 By = block_matrix([[B, y]])
 Byr = By.echelon_form()
except:
 _st_.goboom(_sage_const_100 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_103 
 _st_.inline(_sage_const_4 , latex(By))
except:
 _st_.goboom(_sage_const_103 )
try:
 _st_.current_tex_line = _sage_const_103 
 _st_.inline(_sage_const_5 , latex(Byr))
except:
 _st_.goboom(_sage_const_103 )
_st_.current_tex_line = _sage_const_136 
_st_.blockbegin()
try:
 B=matrix(QQ,[[_sage_const_1 ,_sage_const_7 ,-_sage_const_1 ],[_sage_const_0 ,_sage_const_1 ,-_sage_const_1 ],
 [_sage_const_0 ,-_sage_const_5 ,_sage_const_6 ],[_sage_const_0 ,_sage_const_2 ,-_sage_const_4 ],
 [_sage_const_0 ,_sage_const_4 ,-_sage_const_3 ],[_sage_const_0 ,_sage_const_0 ,-_sage_const_3 ]])
 B1=matrix(QQ,[[_sage_const_15 ,-_sage_const_8 ,-_sage_const_38 ],[_sage_const_2 ,-_sage_const_1 ,-_sage_const_6 ],
 [-_sage_const_10 ,_sage_const_5 ,_sage_const_31 ],[_sage_const_4 ,-_sage_const_2 ,-_sage_const_14 ],
 [_sage_const_8 ,-_sage_const_4 ,-_sage_const_23 ],[_sage_const_0 ,_sage_const_0 ,-_sage_const_3 ]])
 BI = block_matrix(_sage_const_1 ,_sage_const_2 ,[B,_sage_const_1 ])
 R=BI.echelon_form()
 R=copy(R)
 R.subdivide(_sage_const_3 ,_sage_const_3 )
 A=R.subdivision(_sage_const_0 ,_sage_const_1 )
except:
 _st_.goboom(_sage_const_148 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_153 
 _st_.inline(_sage_const_6 , latex(BI))
except:
 _st_.goboom(_sage_const_153 )
try:
 _st_.current_tex_line = _sage_const_157 
 _st_.inline(_sage_const_7 , latex(R))
except:
 _st_.goboom(_sage_const_157 )
try:
 _st_.current_tex_line = _sage_const_161 
 _st_.inline(_sage_const_8 , latex(A))
except:
 _st_.goboom(_sage_const_161 )
try:
 _st_.current_tex_line = _sage_const_165 
 _st_.inline(_sage_const_9 , latex(A))
except:
 _st_.goboom(_sage_const_165 )
try:
 _st_.current_tex_line = _sage_const_165 
 _st_.inline(_sage_const_10 , latex(B1))
except:
 _st_.goboom(_sage_const_165 )
try:
 _st_.current_tex_line = _sage_const_165 
 _st_.inline(_sage_const_11 , latex(A*B1))
except:
 _st_.goboom(_sage_const_165 )
try:
 _st_.current_tex_line = _sage_const_176 
 _st_.inline(_sage_const_12 , latex(A*B1))
except:
 _st_.goboom(_sage_const_176 )
_st_.current_tex_line = _sage_const_194 
_st_.blockbegin()
try:
 B=matrix(Zmod(_sage_const_7 ),[[_sage_const_1 ,_sage_const_7 ,-_sage_const_1 ,_sage_const_2 ],[_sage_const_0 ,_sage_const_1 ,-_sage_const_1 ,-_sage_const_1 ],
 [_sage_const_0 ,-_sage_const_5 ,_sage_const_6 ,-_sage_const_4 ],[_sage_const_0 ,_sage_const_2 ,-_sage_const_4 ,-_sage_const_1 ]])
except:
 _st_.goboom(_sage_const_197 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_211 
 _st_.inline(_sage_const_13 , latex(B**-_sage_const_1 ))
except:
 _st_.goboom(_sage_const_211 )
_st_.current_tex_line = _sage_const_229 
_st_.blockbegin()
try:
 Mf = matrix(QQ,[[_sage_const_1 ,_sage_const_2 ,_sage_const_3 ],[-_sage_const_3 ,-_sage_const_5 ,-_sage_const_8 ],[-_sage_const_1 ,-_sage_const_5 ,-_sage_const_6 ]])
 B1=matrix(QQ,[[_sage_const_1 ,_sage_const_1 ,_sage_const_6 ],[-_sage_const_1 ,_sage_const_0 ,-_sage_const_2 ],[_sage_const_0 ,_sage_const_0 ,_sage_const_1 ]])
 B=matrix(QQ,[[-_sage_const_2 ,_sage_const_7 ,_sage_const_3 ],[_sage_const_1 ,-_sage_const_4 ,-_sage_const_1 ],[_sage_const_0 ,_sage_const_0 ,_sage_const_1 ]])
except:
 _st_.goboom(_sage_const_233 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_264 
 _st_.inline(_sage_const_14 , latex(B**-_sage_const_1 ))
except:
 _st_.goboom(_sage_const_264 )
try:
 _st_.current_tex_line = _sage_const_264 
 _st_.inline(_sage_const_15 , latex(Mf))
except:
 _st_.goboom(_sage_const_264 )
try:
 _st_.current_tex_line = _sage_const_264 
 _st_.inline(_sage_const_16 , latex(B1))
except:
 _st_.goboom(_sage_const_264 )
try:
 _st_.current_tex_line = _sage_const_265 
 _st_.inline(_sage_const_17 , latex(B**-_sage_const_1 *Mf*B1))
except:
 _st_.goboom(_sage_const_265 )
_st_.current_tex_line = _sage_const_279 
_st_.blockbegin()
try:
 MB1Bf = matrix(QQ,[[-_sage_const_2 ,-_sage_const_6 ,_sage_const_2 ,_sage_const_0 ],[-_sage_const_3 ,-_sage_const_9 ,_sage_const_3 ,_sage_const_0 ]])
 B1=matrix(QQ,[[_sage_const_6 ,-_sage_const_4 ,_sage_const_0 ,_sage_const_3 ],[-_sage_const_1 ,_sage_const_2 ,-_sage_const_4 ,-_sage_const_7 ],[_sage_const_0 ,_sage_const_2 ,-_sage_const_5 ,-_sage_const_7 ],[_sage_const_5 ,-_sage_const_3 ,-_sage_const_1 ,_sage_const_1 ]])
 B=matrix(QQ,[[-_sage_const_1 ,_sage_const_5 ],[-_sage_const_2 ,_sage_const_9 ]])
except:
 _st_.goboom(_sage_const_283 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_314 
 _st_.inline(_sage_const_18 , latex(B))
except:
 _st_.goboom(_sage_const_314 )
try:
 _st_.current_tex_line = _sage_const_314 
 _st_.inline(_sage_const_19 , latex(MB1Bf))
except:
 _st_.goboom(_sage_const_314 )
try:
 _st_.current_tex_line = _sage_const_314 
 _st_.inline(_sage_const_20 , latex(B1.inverse()))
except:
 _st_.goboom(_sage_const_314 )
try:
 _st_.current_tex_line = _sage_const_315 
 _st_.inline(_sage_const_21 , latex(B*MB1Bf*B1.inverse()))
except:
 _st_.goboom(_sage_const_315 )
_st_.current_tex_line = _sage_const_351 
_st_.blockbegin()
try:
 MC2B1 = matrix(QQ, [[-_sage_const_2 , -_sage_const_8 ], [_sage_const_2 , _sage_const_9 ], [-_sage_const_1 , -_sage_const_4 ], [-_sage_const_1 , -_sage_const_1 ]])
 B1 = matrix(QQ, [[_sage_const_1 , _sage_const_1 , -_sage_const_2 , -_sage_const_2 ], [_sage_const_1 , _sage_const_2 , -_sage_const_3 , -_sage_const_4 ], [_sage_const_1 , -_sage_const_1 , _sage_const_1 , _sage_const_5 ], [-_sage_const_4 , -_sage_const_1 , _sage_const_7 , _sage_const_9 ]])
 B2 = matrix(QQ, [[_sage_const_1 , _sage_const_2 , -_sage_const_1 , _sage_const_8 ], [_sage_const_0 , _sage_const_1 , -_sage_const_1 , _sage_const_0 ], [_sage_const_0 , _sage_const_5 , -_sage_const_4 , _sage_const_5 ], [_sage_const_0 , _sage_const_5 , -_sage_const_6 , -_sage_const_4 ]])
 MCB2 =  B2.inverse() * B1 * MC2B1
except:
 _st_.goboom(_sage_const_356 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_369 
 _st_.inline(_sage_const_22 , latex(B2.inverse()))
except:
 _st_.goboom(_sage_const_369 )
try:
 _st_.current_tex_line = _sage_const_369 
 _st_.inline(_sage_const_23 , latex(B1))
except:
 _st_.goboom(_sage_const_369 )
try:
 _st_.current_tex_line = _sage_const_369 
 _st_.inline(_sage_const_24 , latex(MC2B1))
except:
 _st_.goboom(_sage_const_369 )
try:
 _st_.current_tex_line = _sage_const_369 
 _st_.inline(_sage_const_25 , latex(MCB2))
except:
 _st_.goboom(_sage_const_369 )
_st_.current_tex_line = _sage_const_387 
_st_.blockbegin()
try:
 MB11C2f = matrix(QQ,[[_sage_const_4 ,_sage_const_0 ,_sage_const_8 ],[_sage_const_3 ,_sage_const_0 ,_sage_const_6 ]])
 B11=matrix(QQ,[[-_sage_const_2 ,_sage_const_3 ,-_sage_const_5 ],[_sage_const_3 ,-_sage_const_5 ,_sage_const_8 ],[_sage_const_0 ,-_sage_const_4 ,_sage_const_5 ]])
 B12=matrix(QQ,[[_sage_const_1 ,_sage_const_1 ,-_sage_const_2 ],[_sage_const_3 ,_sage_const_4 ,-_sage_const_8 ],[-_sage_const_5 ,-_sage_const_3 ,_sage_const_7 ]])
except:
 _st_.goboom(_sage_const_391 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_419 
 _st_.inline(_sage_const_26 , latex(MB11C2f))
except:
 _st_.goboom(_sage_const_419 )
try:
 _st_.current_tex_line = _sage_const_419 
 _st_.inline(_sage_const_27 , latex(B11))
except:
 _st_.goboom(_sage_const_419 )
try:
 _st_.current_tex_line = _sage_const_419 
 _st_.inline(_sage_const_28 , latex(B12))
except:
 _st_.goboom(_sage_const_419 )
try:
 _st_.current_tex_line = _sage_const_420 
 _st_.inline(_sage_const_29 , latex(MB11C2f*B11.inverse()*B12))
except:
 _st_.goboom(_sage_const_420 )
_st_.current_tex_line = _sage_const_433 
_st_.blockbegin()
try:
 MB1Bf = matrix(QQ,[[-_sage_const_2 ,_sage_const_2 ],[-_sage_const_1 ,_sage_const_1 ]])
 B1=matrix(QQ,[[_sage_const_6 ,-_sage_const_5 ],[_sage_const_5 ,-_sage_const_4 ]])
 B=matrix(QQ,[[-_sage_const_1 ,-_sage_const_5 ],[_sage_const_2 ,_sage_const_9 ]])
except:
 _st_.goboom(_sage_const_437 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_470 
 _st_.inline(_sage_const_30 , latex(B))
except:
 _st_.goboom(_sage_const_470 )
try:
 _st_.current_tex_line = _sage_const_470 
 _st_.inline(_sage_const_31 , latex(MB1Bf))
except:
 _st_.goboom(_sage_const_470 )
try:
 _st_.current_tex_line = _sage_const_470 
 _st_.inline(_sage_const_32 , latex(B1))
except:
 _st_.goboom(_sage_const_470 )
try:
 _st_.current_tex_line = _sage_const_470 
 _st_.inline(_sage_const_33 , latex(B*MB1Bf*B1.inverse()))
except:
 _st_.goboom(_sage_const_470 )
_st_.current_tex_line = _sage_const_487 
_st_.blockbegin()
try:
 MB1C3f = matrix(Zmod(_sage_const_5 ),[[_sage_const_2 ,_sage_const_3 ],[_sage_const_4 ,_sage_const_4 ],[_sage_const_1 ,_sage_const_3 ]])
 B1=matrix(Zmod(_sage_const_5 ),[[_sage_const_6 ,-_sage_const_5 ],[_sage_const_5 ,-_sage_const_4 ]])
 B=matrix(Zmod(_sage_const_5 ),[[_sage_const_2 ,_sage_const_3 ,_sage_const_4 ],[_sage_const_0 ,-_sage_const_3 ,_sage_const_4 ],[_sage_const_0 ,_sage_const_0 ,_sage_const_3 ]])
except:
 _st_.goboom(_sage_const_491 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_522 
 _st_.inline(_sage_const_34 , latex(B))
except:
 _st_.goboom(_sage_const_522 )
try:
 _st_.current_tex_line = _sage_const_522 
 _st_.inline(_sage_const_35 , latex(MB1C3f))
except:
 _st_.goboom(_sage_const_522 )
try:
 _st_.current_tex_line = _sage_const_522 
 _st_.inline(_sage_const_36 , latex(B1))
except:
 _st_.goboom(_sage_const_522 )
try:
 _st_.current_tex_line = _sage_const_522 
 _st_.inline(_sage_const_37 , latex(B.inverse()*MB1C3f*B1.inverse()))
except:
 _st_.goboom(_sage_const_522 )
_st_.current_tex_line = _sage_const_537 
_st_.blockbegin()
try:
 A=matrix(Zmod(_sage_const_3 ),[[_sage_const_1 ,_sage_const_1 ,_sage_const_1 ,_sage_const_2 ],[_sage_const_1 ,_sage_const_0 ,_sage_const_2 ,_sage_const_0 ],[_sage_const_0 ,_sage_const_1 ,_sage_const_2 ,_sage_const_2 ]])
 R = A.echelon_form()
 P = PolynomialRing(Zmod(_sage_const_3 ),_sage_const_4 ,'x')
 X = matrix(P,_sage_const_4 ,_sage_const_1 ,P.gens())
 Ecuaciones = A*X
 EcuacionesR = R*X
 v1 = column_matrix(Zmod(_sage_const_3 ),[_sage_const_1 ,_sage_const_1 ,_sage_const_1 ,_sage_const_0 ])
 v2 = column_matrix(Zmod(_sage_const_3 ),[_sage_const_0 ,_sage_const_1 ,_sage_const_0 ,_sage_const_1 ])
except:
 _st_.goboom(_sage_const_546 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_549 
 _st_.inline(_sage_const_38 , latex(A))
except:
 _st_.goboom(_sage_const_549 )
try:
 _st_.current_tex_line = _sage_const_549 
 _st_.inline(_sage_const_39 , latex(X))
except:
 _st_.goboom(_sage_const_549 )
try:
 _st_.current_tex_line = _sage_const_556 
 _st_.inline(_sage_const_40 , latex(Ecuaciones[_sage_const_0 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_556 )
try:
 _st_.current_tex_line = _sage_const_556 
 _st_.inline(_sage_const_41 , latex(Ecuaciones[_sage_const_1 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_556 )
try:
 _st_.current_tex_line = _sage_const_556 
 _st_.inline(_sage_const_42 , latex(Ecuaciones[_sage_const_2 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_556 )
try:
 _st_.current_tex_line = _sage_const_556 
 _st_.inline(_sage_const_40 , latex(Ecuaciones[_sage_const_0 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_556 )
try:
 _st_.current_tex_line = _sage_const_556 
 _st_.inline(_sage_const_41 , latex(Ecuaciones[_sage_const_1 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_556 )
try:
 _st_.current_tex_line = _sage_const_556 
 _st_.inline(_sage_const_42 , latex(Ecuaciones[_sage_const_2 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_556 )
try:
 _st_.current_tex_line = _sage_const_559 
 _st_.inline(_sage_const_43 , latex(R))
except:
 _st_.goboom(_sage_const_559 )
try:
 _st_.current_tex_line = _sage_const_565 
 _st_.inline(_sage_const_44 , latex(EcuacionesR[_sage_const_0 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_565 )
try:
 _st_.current_tex_line = _sage_const_565 
 _st_.inline(_sage_const_45 , latex(EcuacionesR[_sage_const_1 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_565 )
try:
 _st_.current_tex_line = _sage_const_565 
 _st_.inline(_sage_const_46 , latex(EcuacionesR[_sage_const_2 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_565 )
try:
 _st_.current_tex_line = _sage_const_565 
 _st_.inline(_sage_const_44 , latex(EcuacionesR[_sage_const_0 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_565 )
try:
 _st_.current_tex_line = _sage_const_565 
 _st_.inline(_sage_const_45 , latex(EcuacionesR[_sage_const_1 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_565 )
try:
 _st_.current_tex_line = _sage_const_565 
 _st_.inline(_sage_const_46 , latex(EcuacionesR[_sage_const_2 ,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_565 )
try:
 _st_.current_tex_line = _sage_const_568 
 _st_.inline(_sage_const_47 , latex(X))
except:
 _st_.goboom(_sage_const_568 )
try:
 _st_.current_tex_line = _sage_const_568 
 _st_.inline(_sage_const_48 , latex(v1))
except:
 _st_.goboom(_sage_const_568 )
try:
 _st_.current_tex_line = _sage_const_568 
 _st_.inline(_sage_const_49 , latex(v2))
except:
 _st_.goboom(_sage_const_568 )
try:
 _st_.current_tex_line = _sage_const_570 
 _st_.inline(_sage_const_50 , latex(v1))
except:
 _st_.goboom(_sage_const_570 )
try:
 _st_.current_tex_line = _sage_const_570 
 _st_.inline(_sage_const_51 , latex(v2))
except:
 _st_.goboom(_sage_const_570 )
_st_.current_tex_line = _sage_const_584 
_st_.blockbegin()
try:
 A = matrix(Zmod(_sage_const_5 ),[[_sage_const_4 ,_sage_const_4 ,_sage_const_2 ],[_sage_const_2 ,_sage_const_1 ,_sage_const_0 ],[_sage_const_2 ,_sage_const_2 ,_sage_const_2 ]])
 R = A.echelon_form()
except:
 _st_.goboom(_sage_const_587 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_590 
 _st_.inline(_sage_const_52 , latex(R))
except:
 _st_.goboom(_sage_const_590 )
try:
 _st_.current_tex_line = _sage_const_593 
 _st_.inline(_sage_const_53 , latex(A[:,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_593 )
try:
 _st_.current_tex_line = _sage_const_593 
 _st_.inline(_sage_const_54 , latex(A[:,_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_593 )
try:
 _st_.current_tex_line = _sage_const_593 
 _st_.inline(_sage_const_55 , latex(A[:,_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_593 )
_st_.current_tex_line = _sage_const_609 
_st_.blockbegin()
try:
 A=matrix(Zmod(_sage_const_5 ),[[_sage_const_0 ,_sage_const_4 ,_sage_const_3 ,_sage_const_1 ],[_sage_const_1 ,_sage_const_0 ,_sage_const_2 ,_sage_const_0 ],[_sage_const_3 ,_sage_const_3 ,_sage_const_3 ,_sage_const_0 ]])
 B=A.echelon_form()
except:
 _st_.goboom(_sage_const_612 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_615 
 _st_.inline(_sage_const_56 , latex(B))
except:
 _st_.goboom(_sage_const_615 )
try:
 _st_.current_tex_line = _sage_const_616 
 _st_.inline(_sage_const_57 , latex(B[_sage_const_0 ,:].T))
except:
 _st_.goboom(_sage_const_616 )
try:
 _st_.current_tex_line = _sage_const_616 
 _st_.inline(_sage_const_58 , latex(B[_sage_const_1 ,:].T))
except:
 _st_.goboom(_sage_const_616 )
try:
 _st_.current_tex_line = _sage_const_616 
 _st_.inline(_sage_const_59 , latex(B[_sage_const_2 ,:].T))
except:
 _st_.goboom(_sage_const_616 )
_st_.current_tex_line = _sage_const_632 
_st_.blockbegin()
try:
 A=matrix(Zmod(_sage_const_3 ),[[_sage_const_0 ,_sage_const_2 ],[_sage_const_0 ,_sage_const_1 ],[_sage_const_2 ,_sage_const_0 ],[_sage_const_2 ,_sage_const_1 ]])
 B=block_matrix(_sage_const_1 ,_sage_const_2 ,[A,_sage_const_1 ])
 R=B.echelon_form()
 R=copy(R)
 R.subdivide(_sage_const_2 ,_sage_const_2 )
 H = R.subdivision(_sage_const_1 ,_sage_const_1 )
except:
 _st_.goboom(_sage_const_639 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_642 
 _st_.inline(_sage_const_60 , latex(B))
except:
 _st_.goboom(_sage_const_642 )
try:
 _st_.current_tex_line = _sage_const_642 
 _st_.inline(_sage_const_61 , latex(R))
except:
 _st_.goboom(_sage_const_642 )
try:
 _st_.current_tex_line = _sage_const_645 
 _st_.inline(_sage_const_62 , latex(H[_sage_const_0 ,:].T))
except:
 _st_.goboom(_sage_const_645 )
try:
 _st_.current_tex_line = _sage_const_645 
 _st_.inline(_sage_const_63 , latex(H[_sage_const_1 ,:].T))
except:
 _st_.goboom(_sage_const_645 )
_st_.current_tex_line = _sage_const_659 
_st_.blockbegin()
try:
 B=matrix(Zmod(_sage_const_5 ),[[_sage_const_3 ,_sage_const_4 ,_sage_const_4 ,_sage_const_0 ],[_sage_const_1 ,_sage_const_0 ,_sage_const_0 ,_sage_const_0 ],[_sage_const_4 ,_sage_const_2 ,_sage_const_3 ,_sage_const_3 ]])
 C=B.echelon_form()
except:
 _st_.goboom(_sage_const_662 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_665 
 _st_.inline(_sage_const_64 , latex(C))
except:
 _st_.goboom(_sage_const_665 )
try:
 _st_.current_tex_line = _sage_const_666 
 _st_.inline(_sage_const_65 , latex(B[:,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_666 )
try:
 _st_.current_tex_line = _sage_const_666 
 _st_.inline(_sage_const_66 , latex(B[:,_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_666 )
try:
 _st_.current_tex_line = _sage_const_666 
 _st_.inline(_sage_const_67 , latex(B[:,_sage_const_2 ]))
except:
 _st_.goboom(_sage_const_666 )
_st_.current_tex_line = _sage_const_689 
_st_.blockbegin()
try:
 B=matrix(QQ,[[_sage_const_1 ,-_sage_const_4 ],[-_sage_const_1 ,_sage_const_5 ],[-_sage_const_3 ,_sage_const_7 ],[_sage_const_1 ,-_sage_const_2 ]])
 B1=column_matrix(QQ,[_sage_const_5 ,-_sage_const_6 ,-_sage_const_10 ,_sage_const_3 ])
 B1B=block_matrix(_sage_const_1 ,_sage_const_2 ,[B1,B])
 C=B1B.echelon_form()
except:
 _st_.goboom(_sage_const_694 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_698 
 _st_.inline(_sage_const_68 , latex(C))
except:
 _st_.goboom(_sage_const_698 )
try:
 _st_.current_tex_line = _sage_const_700 
 _st_.inline(_sage_const_69 , latex(B1B[:,_sage_const_0 ]))
except:
 _st_.goboom(_sage_const_700 )
try:
 _st_.current_tex_line = _sage_const_700 
 _st_.inline(_sage_const_70 , latex(B1B[:,_sage_const_1 ]))
except:
 _st_.goboom(_sage_const_700 )
_st_.current_tex_line = _sage_const_728 
_st_.blockbegin()
try:
 B=matrix(Zmod(_sage_const_5 ),[[_sage_const_0 ,_sage_const_3 ,_sage_const_2 ,_sage_const_4 ],[_sage_const_3 ,_sage_const_1 ,_sage_const_0 ,_sage_const_1 ],
 [_sage_const_3 ,_sage_const_0 ,_sage_const_2 ,_sage_const_4 ],[_sage_const_0 ,_sage_const_0 ,_sage_const_3 ,_sage_const_3 ],[_sage_const_2 ,_sage_const_4 ,_sage_const_2 ,_sage_const_1 ]])
 B1=matrix(Zmod(_sage_const_5 ),[[_sage_const_2 ,_sage_const_4 ],[_sage_const_2 ,_sage_const_4 ],
 [_sage_const_0 ,_sage_const_2 ],[_sage_const_1 ,_sage_const_3 ],[_sage_const_2 ,_sage_const_3 ]])
 BB1 = block_matrix(_sage_const_1 ,_sage_const_2 ,[B,B1])
 R=BB1.echelon_form()
except:
 _st_.goboom(_sage_const_735 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_739 
 _st_.inline(_sage_const_71 , latex(BB1))
except:
 _st_.goboom(_sage_const_739 )
try:
 _st_.current_tex_line = _sage_const_743 
 _st_.inline(_sage_const_72 , latex(R))
except:
 _st_.goboom(_sage_const_743 )
_st_.current_tex_line = _sage_const_774 
_st_.blockbegin()
try:
 B = matrix(Zmod(_sage_const_7 ), [[_sage_const_3 , _sage_const_0 , _sage_const_4 , _sage_const_1 , _sage_const_3 ], [_sage_const_6 , _sage_const_6 , _sage_const_4 , _sage_const_4 , _sage_const_2 ], [_sage_const_4 , _sage_const_0 , _sage_const_5 , _sage_const_0 , _sage_const_0 ], [_sage_const_6 , _sage_const_3 , _sage_const_1 , _sage_const_0 , _sage_const_1 ], [_sage_const_4 , _sage_const_5 , _sage_const_4 , _sage_const_0 , _sage_const_0 ], [_sage_const_1 , _sage_const_6 , _sage_const_3 , _sage_const_0 , _sage_const_3 ]])
 Bp = matrix(Zmod(_sage_const_7 ), [[_sage_const_2 , _sage_const_3 , _sage_const_2 , _sage_const_3 , _sage_const_6 ], [_sage_const_6 , _sage_const_6 , _sage_const_1 , _sage_const_3 , _sage_const_1 ], [_sage_const_0 , _sage_const_2 , _sage_const_6 , _sage_const_0 , _sage_const_5 ], [_sage_const_4 , _sage_const_5 , _sage_const_4 , _sage_const_3 , _sage_const_5 ], [_sage_const_2 , _sage_const_2 , _sage_const_1 , _sage_const_5 , _sage_const_6 ], [_sage_const_3 , _sage_const_0 , _sage_const_3 , _sage_const_0 , _sage_const_5 ]])
 BBp = block_matrix([[B, Bp]])
 BBpr = BBp.echelon_form()
except:
 _st_.goboom(_sage_const_779 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_782 
 _st_.inline(_sage_const_73 , latex(BBp))
except:
 _st_.goboom(_sage_const_782 )
try:
 _st_.current_tex_line = _sage_const_782 
 _st_.inline(_sage_const_74 , latex(BBpr))
except:
 _st_.goboom(_sage_const_782 )
_st_.current_tex_line = _sage_const_804 
_st_.blockbegin()
try:
 H=matrix(Zmod(_sage_const_5 ),[[_sage_const_1 ,_sage_const_4 ,_sage_const_4 ,_sage_const_2 ,_sage_const_0 ],[_sage_const_0 ,_sage_const_2 ,_sage_const_4 ,_sage_const_2 ,_sage_const_4 ],
 [_sage_const_2 ,_sage_const_1 ,_sage_const_4 ,_sage_const_2 ,_sage_const_1 ],[_sage_const_2 ,_sage_const_2 ,_sage_const_1 ,_sage_const_3 ,_sage_const_3 ]])
 H1=matrix(Zmod(_sage_const_5 ),[[_sage_const_4 ,_sage_const_2 ,_sage_const_3 ,_sage_const_4 ,_sage_const_2 ],[_sage_const_1 ,_sage_const_1 ,_sage_const_3 ,_sage_const_4 ,_sage_const_4 ]])
 HTI = block_matrix(_sage_const_1 ,_sage_const_2 ,[H.T,_sage_const_1 ])
 R=HTI.echelon_form()
 R=copy(R)
 R.subdivide(_sage_const_2 ,_sage_const_4 )
 A=R.subdivision(_sage_const_1 ,_sage_const_1 )
except:
 _st_.goboom(_sage_const_813 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_820 
 _st_.inline(_sage_const_75 , latex(HTI))
except:
 _st_.goboom(_sage_const_820 )
try:
 _st_.current_tex_line = _sage_const_824 
 _st_.inline(_sage_const_76 , latex(R))
except:
 _st_.goboom(_sage_const_824 )
try:
 _st_.current_tex_line = _sage_const_828 
 _st_.inline(_sage_const_77 , latex(A.T))
except:
 _st_.goboom(_sage_const_828 )
try:
 _st_.current_tex_line = _sage_const_831 
 _st_.inline(_sage_const_78 , latex(H1))
except:
 _st_.goboom(_sage_const_831 )
try:
 _st_.current_tex_line = _sage_const_831 
 _st_.inline(_sage_const_79 , latex(A))
except:
 _st_.goboom(_sage_const_831 )
try:
 _st_.current_tex_line = _sage_const_831 
 _st_.inline(_sage_const_80 , latex(H1*A.T))
except:
 _st_.goboom(_sage_const_831 )
_st_.current_tex_line = _sage_const_853 
_st_.blockbegin()
try:
 H=matrix(Zmod(_sage_const_31 ),[[_sage_const_12 ,_sage_const_19 ,_sage_const_9 ,_sage_const_30 ,_sage_const_0 ],[_sage_const_30 ,_sage_const_14 ,_sage_const_29 ,_sage_const_4 ,_sage_const_19 ],
 [_sage_const_28 ,_sage_const_14 ,_sage_const_11 ,_sage_const_29 ,_sage_const_28 ],[_sage_const_3 ,_sage_const_1 ,_sage_const_12 ,_sage_const_25 ,_sage_const_13 ]])
 H1=matrix(Zmod(_sage_const_31 ),[[_sage_const_26 ,_sage_const_24 ,_sage_const_4 ,_sage_const_20 ,_sage_const_0 ],[_sage_const_10 ,_sage_const_6 ,_sage_const_15 ,_sage_const_7 ,_sage_const_4 ],
 [_sage_const_22 ,_sage_const_0 ,_sage_const_2 ,_sage_const_25 ,_sage_const_26 ]])
 HTI = block_matrix(_sage_const_1 ,_sage_const_2 ,[H.T,_sage_const_1 ])
 R=HTI.echelon_form()
 R=copy(R)
 R.subdivide(_sage_const_2 ,_sage_const_4 )
 A=R.subdivision(_sage_const_1 ,_sage_const_1 )
except:
 _st_.goboom(_sage_const_863 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_870 
 _st_.inline(_sage_const_81 , latex(HTI))
except:
 _st_.goboom(_sage_const_870 )
try:
 _st_.current_tex_line = _sage_const_874 
 _st_.inline(_sage_const_82 , latex(R))
except:
 _st_.goboom(_sage_const_874 )
try:
 _st_.current_tex_line = _sage_const_878 
 _st_.inline(_sage_const_83 , latex(A.T))
except:
 _st_.goboom(_sage_const_878 )
try:
 _st_.current_tex_line = _sage_const_881 
 _st_.inline(_sage_const_84 , latex(H1))
except:
 _st_.goboom(_sage_const_881 )
try:
 _st_.current_tex_line = _sage_const_881 
 _st_.inline(_sage_const_85 , latex(A))
except:
 _st_.goboom(_sage_const_881 )
try:
 _st_.current_tex_line = _sage_const_881 
 _st_.inline(_sage_const_86 , latex(H1*A.T))
except:
 _st_.goboom(_sage_const_881 )
_st_.current_tex_line = _sage_const_904 
_st_.blockbegin()
try:
 B=column_matrix(Zmod(_sage_const_19 ),[_sage_const_1 ,_sage_const_8 ,_sage_const_14 ,_sage_const_0 ,_sage_const_18 ])
 H1=matrix(Zmod(_sage_const_19 ),[[_sage_const_17 ,_sage_const_6 ,_sage_const_15 ,_sage_const_5 ,_sage_const_3 ],[_sage_const_13 ,_sage_const_6 ,_sage_const_12 ,_sage_const_4 ,_sage_const_0 ]])
 H1TI = block_matrix(_sage_const_1 ,_sage_const_2 ,[H1.T,_sage_const_1 ])
 R=H1TI.echelon_form()
 R=copy(R)
 R.subdivide(_sage_const_2 ,_sage_const_2 )
 A=R.subdivision(_sage_const_1 ,_sage_const_1 )
 D=block_matrix(_sage_const_1 ,_sage_const_2 ,[A.T,B])
except:
 _st_.goboom(_sage_const_913 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_920 
 _st_.inline(_sage_const_87 , latex(H1TI))
except:
 _st_.goboom(_sage_const_920 )
try:
 _st_.current_tex_line = _sage_const_924 
 _st_.inline(_sage_const_88 , latex(R))
except:
 _st_.goboom(_sage_const_924 )
try:
 _st_.current_tex_line = _sage_const_928 
 _st_.inline(_sage_const_89 , latex(A.T))
except:
 _st_.goboom(_sage_const_928 )
try:
 _st_.current_tex_line = _sage_const_932 
 _st_.inline(_sage_const_90 , latex(D))
except:
 _st_.goboom(_sage_const_932 )
_st_.current_tex_line = _sage_const_954 
_st_.blockbegin()
try:
 B = column_matrix(Zmod(_sage_const_19 ), [_sage_const_1 , _sage_const_8 , _sage_const_15 , _sage_const_2 , _sage_const_16 ])
 Hp = matrix(Zmod(_sage_const_19 ), [[_sage_const_1 , _sage_const_11 , _sage_const_0 , _sage_const_10 , _sage_const_0 ], [_sage_const_5 , _sage_const_15 , _sage_const_66 , _sage_const_2 , _sage_const_4 ]])
 HpTI = block_matrix([[Hp.T, _sage_const_1 ]])
 HpTIr = HpTI.echelon_form()
 HpTIr = copy(HpTIr)
 HpTIr.subdivide(_sage_const_2 ,_sage_const_2 )
 A = HpTIr.subdivision(_sage_const_1 ,_sage_const_1 )
 BAT = block_matrix(_sage_const_2 ,_sage_const_1 ,[B.T,A])
 BATr = BAT.echelon_form()
 BATr = copy(BATr)
 BATr.subdivide(None,_sage_const_4 )
except:
 _st_.goboom(_sage_const_966 )
_st_.blockend()
try:
 _st_.current_tex_line = _sage_const_969 
 _st_.inline(_sage_const_91 , latex(HpTI))
except:
 _st_.goboom(_sage_const_969 )
try:
 _st_.current_tex_line = _sage_const_969 
 _st_.inline(_sage_const_92 , latex(HpTIr))
except:
 _st_.goboom(_sage_const_969 )
try:
 _st_.current_tex_line = _sage_const_974 
 _st_.inline(_sage_const_93 , latex(A))
except:
 _st_.goboom(_sage_const_974 )
try:
 _st_.current_tex_line = _sage_const_980 
 _st_.inline(_sage_const_94 , latex(BAT))
except:
 _st_.goboom(_sage_const_980 )
try:
 _st_.current_tex_line = _sage_const_980 
 _st_.inline(_sage_const_95 , latex(BATr))
except:
 _st_.goboom(_sage_const_980 )
_st_.endofdoc()

