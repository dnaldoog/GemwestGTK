#ifndef PIXMAPS_S_H
#define PIXMAPS_S_H
/* XPM */
GtkWidget *gem_image; 
GdkPixbuf* gem_pixbuf;
gint countPixmapGem=1;/*restrict reprint of same cut twice or more*/
GtkWidget *adjxpm_image;
GdkPixbuf* adjxpm_pixbuf;
//static const gchar *tXPM[GEMCUTXPMARRAYLENGTH];/*tmp array for colouring in stone color*/
/* XPM */
static gchar *gemstoneXPM[] = {
		/* columns rows colors chars-per-pixel */
		"60 41 2 1",
		"  c #341717",
		". c None",
		/* pixels */
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XX........................................................XX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
};
/* XPM */
static gchar *diamr_xpm[] = {
		/* columns rows colors chars-per-pixel */
		"90 60 256 2",
		"   c #CDD2D9",
		".  c #777879",
		"X  c #ADB1BC",
		"o  c #DADCE3",
		"O  c #D2D4D5",
		"+  c #ECF0F9",
		"@  c #ABADB3",
		"#  c #676A73",
		"$  c #7470AB",
		"%  c #646668",
		"&  c #CDD1D3",
		"*  c #BCC3D8",
		"=  c #E3E5EB",
		"-  c #F4F3E7",
		";  c #CBD5E7",
		":  c #D4D9DC",
		">  c #B1B4BA",
		",  c #C5C9D2",
		"<  c #BCC3CB",
		"1  c #7D8187",
		"2  c #C9CBCC",
		"3  c #DCE0E4",
		"4  c #B5BAC1",
		"5  c #5A5C64",
		"6  c #C5C9CC",
		"7  c #F1F0F0",
		"8  c #ECEEF3",
		"9  c #1E2028",
		"0  c #8C97C6",
		"q  c #C2C3C5",
		"w  c #B6B7D6",
		"e  c #B8BBBC",
		"r  c #484A55",
		"t  c #ABB4C1",
		"y  c #D5DAE3",
		"u  c #8A866F",
		"i  c #B0ABF2",
		"p  c #A2A4AA",
		"a  c #BBC1C5",
		"s  c #9EA1A6",
		"d  c #5D606E",
		"f  c #94A1B9",
		"g  c #A8ABC3",
		"h  c #9A9C9A",
		"j  c #8B8D92",
		"k  c #9DA09B",
		"l  c #82848B",
		"z  c #9B9DA3",
		"x  c #8C93A8",
		"c  c #92959B",
		"v  c #D6D9F4",
		"b  c #999BB7",
		"n  c #CED2CA",
		"m  c #8489A5",
		"M  c #B5B8BB",
		"N  c #8E9097",
		"B  c #54565A",
		"V  c #C1C7D4",
		"C  c #959381",
		"Z  c #D1D5E4",
		"A  c #A1A3A3",
		"S  c #43464D",
		"D  c #B2B4B4",
		"F  c #B5BBC9",
		"G  c #D4DDE8",
		"H  c #D2D4CC",
		"J  c #A1A4B2",
		"K  c #898B8E",
		"L  c #7C7D82",
		"P  c #7A7DA7",
		"I  c #F2F5FC",
		"U  c #AAABAE",
		"Y  c #EAE9E8",
		"T  c #656880",
		"R  c #EEECEC",
		"E  c #DEE2EA",
		"W  c #FFFFFF",
		"Q  c #C9CDDB",
		"!  c #C6CAE2",
		"~  c #E5E6E6",
		"^  c #7D86AE",
		"/  c #ACB0AF",
		"(  c #34363F",
		")  c #A7AAB4",
		"_  c #C2C6CD",
		"`  c #ECEBFA",
		"'  c #A4AAAD",
		"]  c #929AAB",
		"[  c #C3CBD8",
		"{  c #BDBEC0",
		"}  c #9B9FAC",
		"|  c #F6F8FD",
		" . c #F4F4F5",
		".. c #F0EFEF",
		"X. c #E5EAE5",
		"o. c #C1C3BD",
		"O. c #BDBFC5",
		"+. c #B3B6AE",
		"@. c #96999D",
		"#. c #9396A4",
		"$. c #3D4047",
		"%. c #ABADBA",
		"&. c #8A8E9D",
		"*. c #838393",
		"=. c #757F9B",
		"-. c #DDDCDE",
		";. c #929493",
		":. c #818282",
		">. c #EAEDE4",
		",. c #C2C6DC",
		"<. c #B9BFCE",
		"1. c #D6D6D8",
		"2. c #FAF9FD",
		"3. c #D9DCEB",
		"4. c #D2D6DA",
		"5. c #D9D9D9",
		"6. c #C8CDD4",
		"7. c #FEFDFA",
		"8. c #E0E1E5",
		"9. c #DFE1E1",
		"0. c #A7A89B",
		"q. c #9BA5C0",
		"w. c #969BA2",
		"e. c #C9CAD1",
		"r. c #E5EBF5",
		"t. c #C8CAD6",
		"y. c #6D7087",
		"u. c #EDEEE8",
		"i. c #D9D9DF",
		"p. c #D2D5EC",
		"a. c #DEE0DC",
		"s. c #F9FAFA",
		"d. c #FDFEF5",
		"f. c #595A93",
		"g. c #6E7078",
		"h. c #B9BAC1",
		"j. c #D1D5DE",
		"k. c #7B7E91",
		"l. c #CCCED0",
		"z. c #E6E8EC",
		"x. c #E0E4E6",
		"c. c #D9DCDC",
		"v. c #E3E7D6",
		"b. c #BABCB8",
		"n. c #B1B8C2",
		"m. c #878D95",
		"M. c #C5C5C8",
		"N. c #A3A5B8",
		"B. c #E5E7F3",
		"V. c #D9DCD5",
		"C. c #83888D",
		"Z. c #B8BDC0",
		"A. c #A4ABBA",
		"S. c #C6C6CD",
		"D. c #C7CBC1",
		"F. c #E3EAFC",
		"G. c #CBCDC8",
		"H. c #C0C2C8",
		"J. c #EBF0F0",
		"K. c #4E5056",
		"L. c #DEDEE5",
		"P. c #EEEFF0",
		"I. c #B8BEC6",
		"U. c #ADBADA",
		"Y. c #8787C2",
		"T. c #858999",
		"R. c #F0F2F4",
		"E. c #717482",
		"W. c #D6DAD1",
		"Q. c #F3F3F2",
		"!. c #FFFFFC",
		"~. c #777B8D",
		"^. c #CFD2DE",
		"/. c #DDDDD9",
		"(. c #C2C7CA",
		"). c #C8CECF",
		"_. c #CCCED5",
		"`. c #A4A8A5",
		"'. c #9C9E89",
		"]. c #F1F4F7",
		"[. c #E3E5E2",
		"{. c #505368",
		"}. c #ECEBEB",
		"|. c #D5D7DD",
		" X c #AFB6CB",
		".X c #747A86",
		"XX c #8F9DBD",
		"oX c #EFEEEE",
		"OX c #ECEBEF",
		"+X c #636D91",
		"@X c #C1C2CE",
		"#X c #F7F6F1",
		"$X c #7B7E6C",
		"%X c #ECEDEF",
		"&X c #424463",
		"*X c #FDFEFC",
		"=X c #FCFDFE",
		"-X c #FCFCFC",
		";X c #EBEBF1",
		":X c #9194AB",
		">X c #B5C4D2",
		",X c #EEEDED",
		"<X c #E7E7E8",
		"1X c #71748D",
		"2X c #FBFBFE",
		"3X c #EBEBED",
		"4X c #EDECEC",
		"5X c #4C4E4D",
		"6X c #C5C3CD",
		"7X c #B9B7BF",
		"8X c #858782",
		"9X c #CFD0D6",
		"0X c #8F909D",
		"qX c #BCBBC7",
		"wX c #FDFEFF",
		"eX c #DFDFDE",
		"rX c #ECECEC",
		"tX c #D8D8E3",
		"yX c #BBBFB7",
		"uX c #717893",
		"iX c #8F908E",
		"pX c #BECAC8",
		"aX c #F8FDFB",
		"sX c #C9D1DF",
		"dX c #595576",
		"fX c #A7A7AD",
		"gX c #A8A5DE",
		"hX c #AEAFCD",
		"jX c #969894",
		"kX c #E9EEE8",
		"lX c #97969B",
		"zX c #E2E3F8",
		"xX c #F5F6F5",
		"cX c #958FA5",
		"vX c #7F8497",
		"bX c #918FB0",
		"nX c #8A8997",
		"mX c #AFB0B5",
		"MX c #898A88",
		"NX c #D7D8DC",
		"BX c #DCE2F0",
		"VX c #EEEDEC",
		"CX c #6E726D",
		"ZX c #E3E3E7",
		"AX c #E5E7E0",
		"SX c #BBBCC3",
		"DX c #606260",
		"FX c #CFD6D9",
		"GX c #BBBBC0",
		"HX c #C7C9C8",
		"JX c #C7C7D0",
		"KX c #78787F",
		"LX c #BFBFEA",
		"PX c #625C98",
		"IX c #E9EDEF",
		"UX c #655DB1",
		/* pixels */
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoX7 oXoX,XVX,X4X4XVX7 Q...oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,XoX7 ~ O -.G.HX& l.9.= & j fX5.<X7 Q.7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,X7 Y 8.N d jXH n n   mX& = 3 L ~.7X@ 1 U i.#X..4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X7 4XS.&.V q.5 A v.W.G.6.w.FXr.r.0X0Xt.1 . C *.$ 3.xX..4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,XoX5.O.4 X G BXT.:XG a.D.> g.FXI | mXp E & b.'.+.UXY.J eXQ.R 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoXrX{ z ' x.o c.IXx P ^ ) yXl % FX+   z @.3 FX+.+.E w ( 9 T S.Q.,X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X..<X  < ' z ).& 9.~ &.^ ^ m L eXl.mXN C.l c   sX6 H x.= S 9 d fX-.}.oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X7 8.  V sXG <.z > 8.o J =.^ =.:XW lXe @.l :.X ; sXj.4.  ` cX9 % 7XmXHX}.oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X7 2 nX, ^.Z 3.y w.U 9.i.tXx =.=.[ <X( / xX@.m.sX[ sXo G sXt.#..Xt M n.F Q oXoX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,X}.SXl C.o o 6.4 @.h 4.1.i.Z T.k.n.1.5X:.W i.F Q [ 6.y : : @ w.)   I.F ; sX> 4X,X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,XR : 3 [.z `.3 O s z c h.O 2   _ S c i.K.K.ZX_._ I., ,   & M.iX% # 9Xx.B.F.p.*.U Q.R 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XVX: O O c.].l.M H.nX*.*.X ).6 & j $.N _.KX5 SXe.9XM h.4 _ A . DX. L 7X-X| r.sX#.L 1.7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoXNXt   4.|.o P.  * b =.T < < _ (.. e.X z > N l 7X3 9XM c % $.( 5Xc z > Y u.J.: , JXq Y ,X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,X_ t <.Z [ X X 6. X=.^ {.' [ 4 ).lXmX` O.> fXz t.~ & e > c 9 $.~.] ] I.- - kX).= tXM.5.oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X}.Q.2XNXn.t XXf b @.j &Xf.( L l N t.O.d eX[.{ <X8 JX6Xq { / : / L A.U.q./ - - G./ H.z.i.E ,X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X..eXfXg.# b q.XXf ] 5 $.r r KXS q <X# 9 j 7 @ e 5 $.r s U ' ,. XU.* >XA./ #X- a.Q.W M.{.# H.7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X..1.mXK # K.d x XXXX,.1 ( DXh + o J.: DXg.K 4.CXN z $.$.h ' F * 0 0 U.t @   d.d.W -XA S r S ) 7 VX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoX5.HX1.SX@ ) t  X X<.: W.DXlXZ.+ ].+ E y o GXl O.1.{ . ' > G :X0 0 f F M q *X*X .M j z s } Q ZXoX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoXW P.q O._ a < pXI.> c.l 9 fX`.n.<.} G Z ^.9XSXq q & 2 s & [ ] ] f A.hXn.pXW W O K p q yXh.,.^.oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X}.Q.W W 7 S.a a a I.O.GX2 lXnXS.HXF Z } <.3.Z : _.O.JX9X, m.&.d vXx ] g %.6.& @ 8.7Xl +.AX;.t >XV VX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XY u./.q q a < a JXqXZX8.2 2 O =X].I ;Xt.3.y G   < _.e.n.< N.S {.k.] p : W /.M e.s lX>.V.M >X>X>X[.oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X7 / h iX;.O.< <.H._ NXW A p 2 2 s.wXW W *X<XtXBXy , O q n.V < r B c t 8 W W -X1.M ) l.V.W.9XV [ F -.oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X7 p MXMXK 7XB.L., N C.~ . ( s 9.W W *X-X*Xs.R.r.E 6.6 Z.<.<.I.@.6 ,   6.: 9.O % % 1 K jX/ c ] &.E.M.Q.4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XVX,Xz :.MXK } -.h N } } ) # B z mXO. .W W W W W 2X8 ^.< , * <.^.4 N & o 6 > D D iX;.N K DXL #.g.g.d @ Q.4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,X}.g.% . l 0X:.8XH.) ] } N N z l 5 L GXP.}.ZX-.eXM } ] x m m ~.#.9XO.m.# L A A `.:.% B / b.2.|.JX@ SX7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,XY z w.SX4.).s M a w.l E.N H.3 9.& E.#.Z.M SXJX> 5 $.d +X+X+Xy.@XOXl.g.S B h 0.$.( 5X5 J./ iXh h k b.7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,XS.O.M > @ # ] Z [ Q V C.S NXW J.t <.< 6X@X@XB KX$.&XT uXT A.6.Y oX;X{ . CXh 1 S $.E.+ FX. :.:.8XM 7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X7 p L C.KXg.5 {.vX; ,.V d 9 l x.(.t F ^.^.o g.$.E.% B 5Xd T._ & [.[.L.z.3XHX/ V t y.<.F.+ A jXU A l.7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X..O.s s c g.5 ( ( T N.Z S ( p q 6 3 6.F fXl 5X5X5X% DXB r j O.R.s.|  .R.7  .P.^.y G F.+ | 1.{ M.k 1.7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X..a mXZ.e g.DX( ( K.NX;X1 _ l.e ' J.' # p iXDX5XB B 5X% l { 9X= i.ZXW s.s.=XW L.  & :  .W -XZXq p 5...4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X..5.> @ 2 |.2 { D M.b.a.yXl d r 5 y i.> ).!.+.K % L e 2 hXm LXtXK 1 2.wX2XW ~ h.j.  & & 9.s.8.8.i.<X,X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X..-.&.l 5.].I ZXo S.e <XL.{.&X&X#.z.i.l 4.4.) t.c U ZXqXP P w J X # h !.W  .nXw.y       e.1.@ @.-.oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,X4XnXp u.5.& M.X nXE.O.W z.J K W.x.# L %.y.T z eXH wXbX$ $ hXK.vXm 5Xb.xX# ( J ^.Q y = R.P.8.{ l.7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XQ.%.mXo.h L # g.~.#.X jXa ^.! w c $.9 d uX1X) b.W.|.dX$ $ b K y.gX$ y.U 5 9 ) j.6., 3 z.%X~ %X<X,X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoX8.s . DX.X] g  XF g.E.Z p.LXPX{.% ( T y.0XD S.l.h.:.k.$ $ n.b i i hX) 3 $.J j.6.6.6.3 ~ P.[.}.4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoXO { H.F  Xt %.s 1 O.n G.ZXN.B d 5 g..Xp o.o 6XA d.z.$ UXg  XgXv 6.e FX* 4 _ t.FX  4. .!.rX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,X<XO 4.> w.} w.jXk 6._.9.7.W MXB T g.C.A X.7 ~ U >.- @XPXY.* ' a.!.V.e @Xe 6 _ J g.{ Q. .,X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XVXtXF vXk.d E.h g.g ;XW W Q.k N 5 y.l q W 8 %XHXAX9.+ N.bXF p j <Xn : @X~.) DXS r d k eX..4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoXY T T b y.*.= } y.> b.D.0.8XR.} } } ;Xc.q 1.q [.8.e.c.X vXF j (.NX= 8.g N.A CX5 $.N Q.R 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XQ.%.&X{.N.` 9X0Xd S % 8X8Xc B.B.2X| e.5Xd L mX*XW D ;.& V F p , H.(.NXqXE !.3 r {.eX7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,XQ.&.N.= 4.@.@.% CX8XjX7X,.zX` z (.5 5XKX# o !.!.1.%.t.Q , ) n.JX) G.n X.W I J H. .R 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XVXQ.8.e.SX/ j L $X$Xs p.^.` @XL 4 5 $.:XT.c.W c.mX%.< 6.).> t } D H G.n 5.O.-.Q.4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XVX}.JX6XN K.:.'.'.! v Z 8 L ) qXH.C.vXm.& + H.GX> Z.).& F m N H n H n HX5...4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoX,Xp B $XC 0.t.v ; H.U g.6XmX6 W M T.w Q H.SXM 4 6 FX! m 0X+.`.b.n 9.oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X..<X/ u u +.3.v G ) K.@.q mX-.W X.X LX[ X U ' e < : 3.b %.k k A eX7 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X.. .G.C W.+ p.I N DXO h.O | 7.d.v Y.f ' U s Z.(.pXx.Q q / o.<X..4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X7 <XkXr.BXW fXp E 4.W W 7.d.v Y.w.A : 4.a _ ).n O.M /.7 oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XoXVXrX%X3X  sX; G aXd.!.-Xv q.w.p 4.x.3 N j H.1.}.oX4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4XY ZXy ; sX| !.W wXv w #.z : 3 ~ l.M.}...,X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,X,XoXR <X,X7 7 ..3.^.e.1.<X}.4X7 Q.4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X,X4X}.}.}.VX..7 ..,XR 4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X",
		"4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X4X"
};

/* XPM */
static char * gemr_xpm[] = {
		"90 60 256 2",
		"  	c #BA4544",
		". 	c #C9C9C9",
		"+ 	c #D2A29B",
		"@ 	c #760D12",
		"# 	c #AB3F44",
		"$ 	c #E6E5E5",
		"% 	c #BAB4B3",
		"& 	c #9B0A0B",
		"* 	c #C52627",
		"= 	c #8C1316",
		"- 	c #992428",
		"; 	c #D6BBB8",
		"> 	c #870D12",
		", 	c #B45656",
		"' 	c #D77975",
		") 	c #B81C1F",
		"! 	c #950A0C",
		"~ 	c #970D13",
		"{ 	c #EEF1F1",
		"] 	c #E5DCDA",
		"^ 	c #844345",
		"/ 	c #957A79",
		"( 	c #B40C0D",
		"_ 	c #A94749",
		": 	c #D06864",
		"< 	c #BC1B1F",
		"[ 	c #B2A8A7",
		"} 	c #CA8B79",
		"| 	c #D9D8D8",
		"1 	c #C9B8B4",
		"2 	c #8C0A0E",
		"3 	c #C86866",
		"4 	c #978282",
		"5 	c #D8AAA7",
		"6 	c #D7D6D6",
		"7 	c #D56160",
		"8 	c #DEDCDC",
		"9 	c #D35A5A",
		"0 	c #840A0E",
		"a 	c #C79895",
		"b 	c #CCC6C4",
		"c 	c #CDCDCD",
		"d 	c #BC2123",
		"e 	c #B26B58",
		"f 	c #A7453E",
		"g 	c #913533",
		"h 	c #A20A0B",
		"i 	c #7C0B0F",
		"j 	c #EAEDED",
		"k 	c #A3141C",
		"l 	c #A75D56",
		"m 	c #981B23",
		"n 	c #BC292B",
		"o 	c #E2E1E1",
		"p 	c #75090D",
		"q 	c #762929",
		"r 	c #AC0A0C",
		"s 	c #A30D11",
		"t 	c #AD1B22",
		"u 	c #C4726C",
		"v 	c #D29B97",
		"w 	c #823D3D",
		"x 	c #91141C",
		"y 	c #680C12",
		"z 	c #E7E6E6",
		"A 	c #CD7D75",
		"B 	c #D48A87",
		"C 	c #B86464",
		"D 	c #872826",
		"E 	c #86201D",
		"F 	c #8B5555",
		"G 	c #7C1215",
		"H 	c #98413E",
		"I 	c #A87777",
		"J 	c #BA3E3E",
		"K 	c #C01C1D",
		"L 	c #D24A4B",
		"M 	c #C44142",
		"N 	c #B58466",
		"O 	c #CF8783",
		"P 	c #DDD3D2",
		"Q 	c #7D3637",
		"R 	c #CA4D4A",
		"S 	c #9C5954",
		"T 	c #D1D1D1",
		"U 	c #B68881",
		"V 	c #CC4444",
		"W 	c #9B4942",
		"X 	c #BC3133",
		"Y 	c #DBCACA",
		"Z 	c #CD5C5A",
		"` 	c #B4191E",
		" .	c #9B1418",
		"..	c #E0CDCB",
		"+.	c #921115",
		"@.	c #C93433",
		"#.	c #B3292C",
		"$.	c #CA5456",
		"%.	c #C5C4C4",
		"&.	c #C23A3C",
		"*.	c #C34C4B",
		"=.	c #EBEAEA",
		"-.	c #C33233",
		";.	c #C9413D",
		">.	c #C4C3C3",
		",.	c #804849",
		"'.	c #AB191E",
		").	c #A18A89",
		"!.	c #BB2D2F",
		"~.	c #B2211F",
		"{.	c #D4B1AD",
		"].	c #AC292C",
		"^.	c #B12426",
		"/.	c #BB2528",
		"(.	c #BE9793",
		"_.	c #AA2D31",
		":.	c #A9161A",
		"<.	c #A43135",
		"[.	c #E9E8E8",
		"}.	c #C6C6C6",
		"|.	c #D07370",
		"1.	c #CA908B",
		"2.	c #AB3432",
		"3.	c #B33334",
		"4.	c #AA2023",
		"5.	c #A79B9A",
		"6.	c #BB0A0E",
		"7.	c #B9A39D",
		"8.	c #B8958B",
		"9.	c #A13538",
		"0.	c #9E292C",
		"a.	c #9D6D6A",
		"b.	c #B53E3E",
		"c.	c #C1C1C1",
		"d.	c #8B322B",
		"e.	c #907372",
		"f.	c #ECEEEE",
		"g.	c #AB343A",
		"h.	c #A20F18",
		"i.	c #CD5856",
		"j.	c #C93D3D",
		"k.	c #BC1312",
		"l.	c #B51114",
		"m.	c #AC2429",
		"n.	c #C11E20",
		"o.	c #9D5244",
		"p.	c #BF5754",
		"q.	c #9C312C",
		"r.	c #C4C6C6",
		"s.	c #A74F44",
		"t.	c #BE2C25",
		"u.	c #6C1116",
		"v.	c #DCC5C1",
		"w.	c #C13E40",
		"x.	c #B52427",
		"y.	c #B54D4E",
		"z.	c #9A1017",
		"A.	c #941E1F",
		"B.	c #D04547",
		"C.	c #6F0A0F",
		"D.	c #761F21",
		"E.	c #C52D2E",
		"F.	c #EEEEEE",
		"G.	c #8E6869",
		"H.	c #E5E9E9",
		"I.	c #E4E9E4",
		"J.	c #CED0D0",
		"K.	c #CBCCCC",
		"L.	c #A31E23",
		"M.	c #A7181C",
		"N.	c #B07F76",
		"O.	c #7E080A",
		"P.	c #E0D1D2",
		"Q.	c #C01614",
		"R.	c #B2171F",
		"S.	c #C43837",
		"T.	c #AE393B",
		"U.	c #B83737",
		"V.	c #EDECEC",
		"W.	c #D7C6C2",
		"X.	c #C4C5C5",
		"Y.	c #89080C",
		"Z.	c #A22329",
		"`.	c #C52121",
		" +	c #6F171D",
		".+	c #C93837",
		"++	c #D9DBDB",
		"@+	c #83080B",
		"#+	c #D0CECE",
		"$+	c #C8C7C7",
		"%+	c #CF5350",
		"&+	c #BE524F",
		"*+	c #9C1B1B",
		"=+	c #A81013",
		"-+	c #90090A",
		";+	c #ECEBEB",
		">+	c #E4E3E3",
		",+	c #EAE9E9",
		"'+	c #D4D3D3",
		")+	c #C6C5C5",
		"!+	c #DBDADA",
		"~+	c #CBCACA",
		"{+	c #EEEDED",
		"]+	c #C6C7C7",
		"^+	c #7A080A",
		"/+	c #BD6E6B",
		"(+	c #DA9286",
		"_+	c #EDEDED",
		":+	c #CFD0CF",
		"<+	c #D2A480",
		"[+	c #E2E5E5",
		"}+	c #C4B0AB",
		"|+	c #E4E6E1",
		"1+	c #DFDFDF",
		"2+	c #C9C2C0",
		"3+	c #EDEEEE",
		"4+	c #AE8F90",
		"5+	c #EDEDEE",
		"6+	c #A0908F",
		"7+	c #E9EBEB",
		"8+	c #BEBCBB",
		"9+	c #DFD3CE",
		"0+	c #BB181A",
		"a+	c #D5D4D4",
		"b+	c #EDEFEF",
		"c+	c #A36B6A",
		"d+	c #D7D8D8",
		"e+	c #E6DFDD",
		"f+	c #C64848",
		"g+	c #CD4F4F",
		"h+	c #C94746",
		"i+	c #BA5B62",
		"j+	c #C2C4C4",
		"k+	c #C4C3C4",
		"l+	c #EBECEC",
		"m+	c #EDECED",
		"n+	c #9F7670",
		"o+	c #AC4D4E",
		"p+	c #E9E9E8",
		"q+	c #EAE9EA",
		"r+	c #895F5B",
		"s+	c #D06E6B",
		"t+	c #981619",
		"u+	c #BF3636",
		"v+	c #B90E0E",
		"w+	c #EEEDEE",
		"x+	c #B12E2F",
		"y+	c #C3A5A2",
		"z+	c #9E2B25",
		"A+	c #C75853",
		"B+	c #C5615C",
		"C+	c #8B2D31",
		"D+	c #772F30",
		"E+	c #9F3C35",
		"F+	c #A1383E",
		"G+	c #9D2E30",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.m+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.w+b+{ { b+f.f.j j j j j j f.f.f.5+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.F.{ b+p+] ..; {.+ + v v + + 5 5 ; v.9+e+p+j j V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.{+{ b+$ ..{.1.A u B+Z Z i.i.i.9 9 7 7 s+s+A O v ; P.$ j l+;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.{+{ 7+..5 O 3 B+$.g+f+V V V V B.B.B.L L g+%+%+9 9 Z Z s+O {.P H.l+=.;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.{ ;+Y v |.9 %+R f+M w.&.&.S.S.-.@..+.+.+.+j.;.;.V V V V h+f+*.B+1.Y H.7+=.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.F.{ P.v |.7 %+f+M ;.S.-.-.n /./.d /.d `.`.* * * * * E.E.E.-.@..+j.;.V p.a | p+[.;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.{ =.{.B ' 9 f+M S.-.n x.` ) ) ) ) < < ) < K n.K n.n.n.K K K 0+< d d n u+w.  /+1 [+z =.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.{ e+v ' ' i.&.-.n d n.0+) d n.d d d d d d d d n.< K K K K K n.< K K < < /.!.&.w.&+y+1+$ ,+;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.{ ] 1.' 7 M * n.) n.`.n.n.d /.n !.!.X X !.!.n /.d d n.< n.K < < < 0+0+) ) ) ) x.X w.y.(.++>+[.;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.{ ] B s+%+@.* d `.< k.0+n -.E.u+w.M *.R f+M &.u+!.n /.d /.d < < < < ` ` ` ` ` ` R.~.x+  y.(.++o [.;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.F.z v 7 L @.`.`.n.l.( 6.l.-.f+Z i.: s+s+: Z A+*.w.&.X X !.n /./.x.d ) ~.) ` ` R.` R.` '.].J , y+++o ,+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.3+5 : L @.* `.< ( 6.( t i+B |.O A A (+O |.: B+A+*.f+J J u+!.#.n x./.x.x.~.` t R.R.R.` '.t #.J C 2+!+>+=.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.{ ..' $.j.* `.k.6.6.6.3.; I.H.; 1.A A u B+p.&+A+A+A+*.    &.U.X x+!.n #.^.^.~.t t t '.'.M.'.M.#.o+U T !+z ;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V._+7+v 9 V E.`.Q.v+6.6.( } { $ |+{.u B+&+  3.x+x+_.  p.&+*.  J U.U.3.x+x+#.^.m.~.t t t t M.:.:.M.M.T.l 1 '+1+[.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.{ Y ' L @.`.Q.v+k.0+0+l., ; W.a , 2.x+^.'.:.:.=+s k 2.y.y.  b.b.U.3.x+].].m.4.4.t t t '.:.M.:.M.:.Z.f U :+6 >+=.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.3+5 7 M E.K v+6.k.0+d l.=+2.2.M.M.4.:.=+=+s s s r r =+L._.T.b.b.T.g.x+_.].m.4.L.'.k k k k k k k h.k _.e 2+T 1+[.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.3+e+B i..+* k.6.v+( l.l.( r r r =+=+=+=+h h h h h s s s =+ .<.p., y.# T.g._._.].L.M.k h.h.h.h.h.h.h.h.L.s.}+c | $ ;+V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.b+..A g+-.`.v+6.( ( ( r r r r r s s h h h h & h & h s s h t+, u C , y.# # g.<._.L.L.k h.h.h.z.s z.s h.k E+8.c T o ,+V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.f.v.s+h+t.Q.6.6.( ( r r r r h h h h h h & h & & & h & s & 0./+/+C , o+o+_ # # g.Z.L.k z.h.z.~ ~ ~ ~ s z.q.U c #+8 [.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.j ; 3 M t.k.( ( ( r r r r h h h h & & & & & & & & & & s ! <., , o+o+_ _ # F+F+<.- Z.k z.z.~ ~ ~ ~ s h. .z+N.~+K.!+z V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.l+{.3 w.t.v+r r r r r h h h h h & & & & & & & & & ~ & & ~ 0.9.9.9.9.9.9.G+G+G+0.L.m t+t+z.~ z.~ z.z. . .z+N.~+~+| $ ;+V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.7+{.3 w.~.( r r r h h h h h & & & & & & & & ! ! & & & ! ~ - - 0.0.0.- - - - - - m t+t+z.~ ~ ~ ~ z. . .t+q.U . $+6 $ ;+V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.7+; 3 J ~.r r r h h h & h & & & & ! & ! ! ! ! ! ! ! ! ! ~ m m - m - - m m m m m m +.t+z.2 ~ ~ z.z. .t+*+E+8.$+. 6 $ ;+V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.7+W./+J ~.r h h h h & & & ! ! ! ! ! ! ! ! ! ! -+! -+! -+-++.m m m m x x m x x m x 2 +.2 ~ +.+.+.t+t+t+A.s.7.}.. | $ ;+V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.=.a+A   4.h h h & & & & ! ! ! ! -+-+-+-+-+-+-+-+-+-+-+-+2 +.x x x x x x x x x x > 2 Y.2 2 2 +.x *+*+t+0.l % X.K.| z ;+V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.=.o a o+].s & & ! ! ! ! ! -+-+-+-+-+-+-+-+-+-+2 2 2 2 2 > +.= x = x x x x x = 0 2 2 2 2 2 ~ t+- z+A.A.H N.j+X.c 8 z V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.=.[+; C 2. .! ! 2 ! ! -+-+-+Y.-+Y.Y.-+Y.-+2 -+2 Y.Y.2 2 +.= x x x = = = > > 0 0 Y.Y.Y.2 +.= z+f q.A.g S 7.X.)+T 1+,+V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+z ++U # *+& ! ~ ! -+-+2 +.2 2 Y.Y.Y.Y.Y.Y.Y.Y.0 0 0 2 > > +.> > > > 0 0 0 @+@+0 @+> = z+e } s.d.- W n+8+%.. 6 >+=.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.[.o 1 l q.+.-+-+-+2 2 2 +.> > 0 0 0 0 Y.@+@+@+@+@+@+@+@+@+0 0 0 @+0 0 @+O.@+@+@+@+= E s.<+N H d.f S 7.X.%.c !+z ;+V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.=.>+++(.H - 2 Y.Y.> > > > > > i > i 0 0 0 O.O.O.@+O.@+O.O.O.O.O.O.O.O.O.O.O.O.O.> E W e o.d.D s.l ).j+>.$+'+o ,+V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+[.1+T I g A.0 0 0 > > > G i > i G i i i ^+O.O.O.O.O.O.O.O.^+^+^+^+^+^+i ^+O.i E E+s.g D E W e n+8+k+)+#+!+z ;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.=.$ ++b c+g x p i G G i G > @ @ i i i i i i ^+^+^+^+^+^+^+p ^+p p p ^+i i i = E D E E D W l a.% X.>.~+6 >+=.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.,+o d+2+a.C+E p p @ G @ @ @ @ @ G @ @ @ i p p i p p p p p p p p p p p G G G G G  +D W S a.% r.>.. '+1+[.;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+z 1+6 >.I g D @ C.C.@ @ @ @ C.@ @ @ p @ p p @ p p p p C.p p p p @ p @ G G G D.d.W F / 8+%.>.. T 8 z ;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+z 1+a+K.4+^ D D.C.C.C.C.C.C.@ C.C.@ C.C.@ C.C.C.C.C.C.C.@ @ p C.C.C.D.q Q H W F 6+c.>.>.. T 8 z =.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+z 1+a+J.% n+^ q D. +u.y C.y C.y C.y C.y C.C.C.C.C.C.C.C.y u.u.D.q Q ^ H F / [ . >.%.. '+8 z =.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+z 1+6 J.. [ n+,.Q D+q D. +u.y y y y y y y y y y u.u.D.q D+w w ^ ^ F / [ X.r.>.}.c 6 1+z =.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+[.o !+T J.$+% ).r+^ w w w Q Q D+D+D+D+q D+D+Q Q w w w w ,.F G.).% r.X.>.)+. T | o z ;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+,+$ 8 6 #+c K.c.[ 4 G.F ,.^ ^ ^ ^ ^ ^ ^ ^ ,.,.,.,.r+e.6+[ c.]+X.>.)+. #+6 8 $ ,+;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.=.[.>+8 6 T c K.. %.% [ 5.).4 / e.e.e./ 4 6+5.% 8+j+}.}.k+%.$+K.#+6 8 >+z =.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+=.z >+1+| '+c K.K.. . ]+r.r.r.]+]+r.r.]+r.r.X.%.)+$+~+c '+| 1+>+z =.;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+=.[.$ o 8 | a+T c K.~+. . $+$+$+$+. . ~+K.c T a+| 8 o $ [.=.;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+,+z $ >+1+8 !+| 6 6 a+'+'+a+6 6 | !+8 1+o $ z ,+;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+=.,+[.z $ $ >+>+o o >+>+$ $ z [.,+=.;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.;+;+;+;+=.=.;+;+;+;+V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.",
		"V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V.V."};
/* XPM */
static char * adjustIcon_xpm[] = {
		"18 21 152 2",
		"  	c #707475",
		". 	c #2E3436",
		"+ 	c #636462",
		"@ 	c #6B6C6B",
		"# 	c #696A68",
		"$ 	c #686967",
		"% 	c #5F605E",
		"& 	c #64625D",
		"* 	c #65635C",
		"= 	c #64635B",
		"- 	c #64635C",
		"; 	c #616360",
		"> 	c #545654",
		", 	c #6B6C6A",
		"' 	c #848583",
		") 	c #808280",
		"! 	c #868785",
		"~ 	c #878886",
		"{ 	c #4C4E4C",
		"] 	c #695E49",
		"^ 	c #726348",
		"/ 	c #6E6149",
		"( 	c #535553",
		"_ 	c #5C6F4D",
		": 	c #84C644",
		"< 	c #84C744",
		"[ 	c #85C845",
		"} 	c #85C846",
		"| 	c #86C847",
		"1 	c #86C948",
		"2 	c #87C948",
		"3 	c #87C949",
		"4 	c #88C94A",
		"5 	c #88CA4B",
		"6 	c #88C84B",
		"7 	c #5C6F4E",
		"8 	c #6E8C54",
		"9 	c #A5E963",
		"0 	c #A7E768",
		"a 	c #C6E3AA",
		"b 	c #CCEAAF",
		"c 	c #CBEAAE",
		"d 	c #CAE9AD",
		"e 	c #CDEAB1",
		"f 	c #CDEBB2",
		"g 	c #CEEBB2",
		"h 	c #ADEA71",
		"i 	c #ABEA6D",
		"j 	c #708D55",
		"k 	c #73905B",
		"l 	c #AEEB73",
		"m 	c #A2E55F",
		"n 	c #CBE9AE",
		"o 	c #D1F3B0",
		"p 	c #D0F3AE",
		"q 	c #D4F4B4",
		"r 	c #D8F5BB",
		"s 	c #DCF6C3",
		"t 	c #B9EE86",
		"u 	c #B9EE85",
		"v 	c #728F5B",
		"w 	c #597840",
		"x 	c #8AE234",
		"y 	c #8BE037",
		"z 	c #A3E463",
		"A 	c #A6E965",
		"B 	c #8EE33B",
		"C 	c #9BE651",
		"D 	c #65824E",
		"E 	c #4B544B",
		"F 	c #5B7B42",
		"G 	c #5B7C42",
		"H 	c #5C7C42",
		"I 	c #5D7C42",
		"J 	c #5D7D43",
		"K 	c #5D7D44",
		"L 	c #4D554C",
		"M 	c #555753",
		"N 	c #6C6E6B",
		"O 	c #5A5C58",
		"P 	c #6E706B",
		"Q 	c #71746F",
		"R 	c #737570",
		"S 	c #767873",
		"T 	c #737571",
		"U 	c #777974",
		"V 	c #8A8D89",
		"W 	c #A3A6A0",
		"X 	c #555854",
		"Y 	c #B3B4B1",
		"Z 	c #B4B5B1",
		"` 	c #B6B8B5",
		" .	c #5C5E5A",
		"..	c #92938F",
		"+.	c #797B78",
		"@.	c #7F817E",
		"#.	c #484C4B",
		"$.	c #676864",
		"%.	c #6B6C68",
		"&.	c #6A6C67",
		"*.	c #686A66",
		"=.	c #6D6F6B",
		"-.	c #686B66",
		";.	c #6F716C",
		">.	c #5B5D58",
		",.	c #6C6E69",
		"'.	c #71736E",
		").	c #6E716D",
		"!.	c #70726D",
		"~.	c #757772",
		"{.	c #6E706C",
		"].	c #777975",
		"^.	c #5D5F5A",
		"/.	c #878986",
		"(.	c #C1C3BE",
		"_.	c #C5C6C2",
		":.	c #959692",
		"<.	c #515554",
		"[.	c #6A6C68",
		"}.	c #70716D",
		"|.	c #747571",
		"1.	c #757773",
		"2.	c #5C5E59",
		"3.	c #939591",
		"4.	c #70726E",
		"5.	c #71726E",
		"6.	c #6F726C",
		"7.	c #747671",
		"8.	c #70736E",
		"9.	c #676A65",
		"0.	c #868984",
		"a.	c #BFC2BC",
		"b.	c #C3C5C0",
		"c.	c #C0C3BD",
		"d.	c #5C5F5A",
		"e.	c #747672",
		"f.	c #797C78",
		"g.	c #767974",
		"h.	c #747772",
		"i.	c #7C7E78",
		"j.	c #5E605B",
		"k.	c #71736F",
		"l.	c #797B77",
		"m.	c #A4A7A4",
		"n.	c #7E7F7B",
		"o.	c #5B5E59",
		"p.	c #5B5D59",
		"q.	c #787B77",
		"r.	c #A6AAA5",
		"s.	c #656763",
		"t.	c #838382",
		"u.	c #6F6F6E",
		"  . . . . . . . . . . . . . . . .   ",
		". + + @ # $ # % % % % % & * = - ; . ",
		". > , ' ) ! ~ { { { { { ] ^ ^ / ( . ",
		". _ : < [ [ } } | 1 2 3 3 4 5 6 7 . ",
		". 8 9 0 a b c d c b e e f g h i j . ",
		". k l m n o p p p p o q r s t u v . ",
		". w x y z A A A A A A A A A B C D . ",
		". E F G G G G H H H I I J J J K L . ",
		"M N O O P M Q Q M R S M T U O O V M ",
		"M N W X M Y M M Z M M ` M  .....+.M ",
		"M @.#.O $.M %.&.M *.=.M -.;.>.>.V M ",
		"M @.X O ,.M '.).M !.~.M {.].^.^./.M ",
		"M N W O M (.M M (.M M _.M  .:.:.+.M ",
		"M @.<.O [.M }.{.M {.|.M ,.1.2.2.3.M ",
		"M @.M O !.M 4.5.M 6.7.M 8.9.O O 0.M ",
		"M N W O M a.M M b.M M c.M d.e.e.f.M ",
		"M @.M O {.M g.h.M 7.i.M 8.j.k.k.l.M ",
		"M m.n.n.n.n.n.n.n.n.n.n.n.o.'.'.+.M ",
		"M m.n.n.n.n.n.n.n.n.n.n.n. .p.p.q.M ",
		"M r.m.m.m.m.m.m.m.m.m.m.m.m.m.m.m.s.",
		"t.M M M M M M M M M M M M M M M M u."};


#endif 
/* __PIXMAPS_S_H__ */