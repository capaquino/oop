   IL = 60: CL = 151: NL = 59: RL = 33: MX = 5: AR = 11: TT = 13: LN = 3: LT = 125: ML = 71: TR = 3
   DIM NV(1), C0%(151), C1%(151), C2%(151), C3%(151), C4%(151), C5%(151), C6%(151), C7%(151)
   DIM NV$(59, 1), IA$(60), IA(60), RS$(33), RM(33, 5), MS$(71), NT$(1), I2(60)
   SCREEN 0, 0, 0, 0: COLOR 7, 0, 0: WIDTH 80: RESET
   KEY OFF: KEY 1, "LIST ": KEY 2, "RUN" + CHR$(13): KEY 3, "LOAD" + CHR$(34) + "B:": KEY 4, "SAVE" + CHR$(34) + "B:": KEY 5, "GOSUB ": KEY 6, "RETURN": KEY 7, "FILES " + CHR$(34) + "B:*.*": KEY 8, "EDIT ": KEY 9, "CLS": KEY 10, "SYSTEM"
   DEF SEG = &H40: RANDOMIZE PEEK(&H6D) * 256! + PEEK(&H6C) - 32768!
   LOCATE , , 0: CLS : GOTO 100
80 GOSUB 99: REM single character input, lower case converted to uppercase
81 IN$ = INKEY$: IF IN$ = "" THEN 81 ELSE SOUND 1000, 1
   IF ASC(IN$) = 27 THEN RUN
   IF ASC(IN$) > 96 THEN IN$ = CHR$(ASC(IN$) - 32): REM Lower case to upper case.
   RETURN
96 GOSUB 99: LOCATE 24, 1, 0: PRINT "************************** "; : COLOR 18, 0: PRINT "Press any key to continue"; : COLOR 7, 0: PRINT " **************************"; : BEEP
97 IN$ = INKEY$: IF IN$ = "" THEN 97 ELSE CLS : SOUND 1000, 1: RETURN
99 IN$ = INKEY$: IF IN$ <> "" THEN 99 ELSE LOCATE , , 1: RETURN
100 REM
    X = Y = Z: K = R = V: N = LL = F: TP$ = K$: W = IP = P: GOSUB 190: GOSUB 2210' *****
    GOSUB 96
    CLS : GOTO 350
190 CLS : LOCATE , 28: COLOR 0, 7: PRINT " W E L C O M E   T O "; : COLOR 7, 0: PRINT : LOCATE 3, 27: COLOR 0, 7: PRINT " A D V E N T U R E - 1 "; : COLOR 7, 0: PRINT
    LOCATE 7, 1: PRINT "The object of your adventure is to find treasures and return them"
    PRINT "to the proper place for you to accumulate points.  I'm your clone.  Give me"
    PRINT "commands that consist of a verb & noun, i.e. GO EAST, TAKE KEY, CLIMB TREE,"
    PRINT "SAVE GAME, TAKE INVENTORY, FIND AXE, etc.": PRINT
    PRINT "You'll need some special items to do some things, but I'm sure that you'll be"
    PRINT "a good adventurer and figure these things out (which is most of the fun of"
    PRINT "this game).": PRINT
    PRINT "Note that going in the opposite direction won't always get you back to where"
    PRINT "you were.": PRINT : PRINT : A$ = "HAPPY ADVENTURING!!!": LOCATE , 40 - ((LEN(A$)) / 2): PRINT A$
    LOCATE 24, 31: COLOR 18: PRINT " < INITIALIZING > "; : COLOR 7:
    RETURN
350 R = AR: LX = LT: DF = 0: SF = 0: PRINT : PRINT "Use saved game (Y or N)? "; : GOSUB 80: K$ = IN$: PRINT K$
    PRINT : IF LEFT$(K$, 1) <> "Y" THEN CLS : GOTO 420
    PRINT "Is previously saved game now on the disk in drive C:? "; : GOSUB 80: K$ = IN$: PRINT K$: IF LEFT$(K$, 1) <> "Y" THEN 350
    OPEN "C:ADVEN-1.DAT" FOR INPUT AS 1
    INPUT #1, SF, LX, DF, R
    FOR X = 0 TO IL: INPUT #1, IA(X): NEXT X
    CLOSE 1: CLS
420 LOCATE , , 0: GOSUB 600: GOTO 490
430 PRINT : BEEP: INPUT "Tell me what to do"; TP$: PRINT : GOSUB 500
    IF F THEN PRINT "You use word(s) I don't know.!": GOTO 430
    GOSUB 760: IF IA(9) = -1 THEN LX = LX - 1: GOTO 470
    GOTO 490
470 IF LX < 0 THEN PRINT "light has run out!": IA(9) = 0: GOTO 490
    IF LX < 25 THEN PRINT "light runs out in"; LX; "turns!"
490 NV(0) = 0: GOSUB 760: GOTO 430
500 K = 0: NT$(0) = "": NT$(1) = ""
    FOR X = 1 TO LEN(TP$): K$ = MID$(TP$, X, 1): IF K$ = " " THEN K = 1: GOTO 530
    NT$(K) = LEFT$(NT$(K) + K$, LN)
530 NEXT X: FOR X = 0 TO 1: NV(X) = 0: IF NT$(X) = "" THEN 590
    FOR Y = 0 TO NL: K$ = NV$(Y, X): IF LEFT$(K$, 1) = "*" THEN K$ = MID$(K$, 2)
    IF X = 1 AND Y < 7 THEN K$ = LEFT$(K$, LN)
    IF NT$(X) = K$ THEN NV(X) = Y: GOTO 580
    NEXT Y: GOTO 590
580 IF LEFT$(NV$(NV(X), X), 1) = "*" THEN NV(X) = NV(X) - 1: GOTO 580
590 NEXT X: F = NV(0) < 1 OR LEN(NT$(1)) > 0 AND NV(1) < 1: RETURN
600 IF DF THEN IF IA(9) <> -1 AND IA(9) <> R THEN PRINT "I can't see.  It's too dark!": RETURN
    K = -1: IF LEFT$(RS$(R), 1) = "*" THEN PRINT MID$(RS$(R), 2); : GOTO 630
    PRINT "I'm in a "; RS$(R);
630 FOR Z = 0 TO IL: IF K THEN IF IA(Z) = R THEN PRINT : PRINT : PRINT "VISIBLE ITEMS HERE:": K = 0
    GOTO 690
650 TP$ = IA$(Z): IF RIGHT$(TP$, 1) <> "/" THEN RETURN
    FOR W = LEN(TP$) - 1 TO 1 STEP -1: IF MID$(TP$, W, 1) = "/" THEN TP$ = LEFT$(TP$, W - 1): RETURN
    NEXT W
    RETURN
690 IF IA(Z) <> R THEN 720
    GOSUB 650: IF POS(0) + LEN(TP$) + 3 > 39 THEN PRINT
    PRINT TP$; ".  ";
720 NEXT: PRINT
    K = -1: FOR Z = 0 TO 5: IF K THEN IF RM(R, Z) <> 0 THEN PRINT : PRINT "Obvious exits: ": K = 0
    IF RM(R, Z) <> 0 THEN PRINT NV$(Z + 1, 1); " ";
    NEXT: PRINT : PRINT : RETURN
760 F2 = -1: F = -1: F3 = 0: IF NV(0) = 1 AND NV(1) < 7 THEN 1240
    FOR X = 0 TO CL: V = INT(C0%(X) / 150): IF NV(0) = 0 THEN IF V <> 0 THEN RETURN
    IF NV(0) <> V THEN 830
    N = C0%(X) - V * 150
    IF NV(0) = 0 THEN F = 0: GOTO 820
    GOTO 840
820 IF INT(RND(1) * 100 + 1) <= N THEN 850
830 NEXT X: GOTO 1760
840 IF N <> NV(1) AND N <> 0 THEN 830
850 F2 = -1: F = 0: F3 = -1: FOR Y = 1 TO 5: ON Y GOTO 860, 870, 880, 890, 900
860 W = C1%(X): GOTO 910
870 W = C2%(X): GOTO 910
880 W = C3%(X): GOTO 910
890 W = C4%(X): GOTO 910
900 W = C5%(X): GOTO 910
910 LL = INT(W / 20): K = W - LL * 20: F1 = -1
    ON K + 1 GOTO 1110, 990, 1010, 1030, 1050, 1060, 1070, 1080, 1090, 1100, 950, 970
    IF K < 12 THEN 950
    ON K - 11 GOTO 1000, 1020, 1040
950 F1 = -1: FOR Z = 0 TO IL: IF IA(Z) = -1 THEN 1110
    NEXT: F1 = 0: GOTO 1110
970 F1 = 0: FOR Z = 0 TO IL: IF IA(Z) = -1 THEN 1110
    NEXT: F1 = -1: GOTO 1110
990 F1 = IA(LL) = -1: GOTO 1110'  *****
1000 F1 = IA(LL) <> -1 AND IA(LL) <> R: GOTO 1110
1010 F1 = IA(LL) = R: GOTO 1110'  *****
1020 F1 = IA(LL) <> 0: GOTO 1110
1030 F1 = IA(LL) = R OR IA(LL) = -1: GOTO 1110'  *****
1040 F1 = IA(LL) = 0: GOTO 1110'  *****
1050 F1 = R = LL: GOTO 1110'  *****
1060 F1 = IA(LL) <> R: GOTO 1110
1070 F1 = IA(LL) <> -1: GOTO 1110
1080 F1 = R <> LL: GOTO 1110
1090 F1 = SF AND INT(2 ^ LL + .5): F1 = F1 <> 0: GOTO 1110
1100 F1 = SF AND INT(2 ^ LL + .5): F1 = F1 = 0'  *****
1110 F2 = F2 AND F1
     IF NOT F2 THEN 830
     NEXT Y
     IP = 0: FOR Y = 1 TO 4: K = INT((Y - 1) / 2 + 6): ON Y GOTO 1140, 1150, 1160, 1170
1140 AC = INT(C6%(X) / 150): GOTO 1180
1150 AC = C6%(X) - INT(C6%(X) / 150) * 150: GOTO 1180
1160 AC = INT(C7%(X) / 150): GOTO 1180
1170 AC = C7%(X) - INT(C7%(X) / 150) * 150
1180 IF AC > 101 THEN 1230
     IF AC = 0 THEN 1720
     IF AC < 52 THEN PRINT MS$(AC): GOTO 1720
     ON AC - 51 GOTO 1340, 1380, 1450, 1470, 1480, 1490, 1500, 1470, 1520, 1540, 1550
     ON AC - 62 GOTO 1560, 1580, 1590, 1640, 1680, 1690, 1700, 1710, 1390, 1460
1230 PRINT MS$(AC - 50): GOTO 1720
1240 L = DF: IF L THEN L = DF AND IA(9) <> R AND IA(9) <> -1: GOTO 1260
     GOTO 1270
1260 IF L THEN PRINT "Dangerous to move in the dark!"
1270 IF NV(1) < 1 THEN PRINT "Give me a direction too.": GOTO 1800
     K = RM(R, NV(1) - 1)
     IF K >= 1 THEN 1320
     IF L THEN PRINT "I fell down and broke my neck.": K = RL: DF = 0: GOTO 1320
     PRINT "I can't go in that direction.": GOTO 1800
1320 IF NOT L THEN CLS
     R = K: GOSUB 600: GOTO 1800
1340 L = 0: FOR Z = 1 TO IL: IF IA(Z) = -1 THEN L = L + 1
     NEXT Z
     IF L >= MX THEN PRINT "I've too much to carry!": GOTO 1730
     GOSUB 1810: IA(P) = -1: GOTO 1720
1380 GOSUB 1810: IA(P) = R: GOTO 1720
1390 PRINT "Is disk drive C: ready to receive the saved game? "; : GOSUB 80: K$ = IN$: PRINT K$: IF LEFT$(K$, 1) <> "Y" THEN 1440
     OPEN "C:ADVEN-1.DAT" FOR OUTPUT AS 1
     PRINT #1, SF: PRINT #1, LX: PRINT #1, DF: PRINT #1, R
     FOR W = 0 TO IL: PRINT #1, IA(W): NEXT W: CLOSE 1
1440 PRINT : GOTO 1720
1450 GOSUB 1810: R = P: GOTO 1720
1460 GOSUB 1810: L = P: GOSUB 1810: Z = IA(P): IA(P) = IA(L): IA(L) = Z: GOTO 1720
1470 GOSUB 1810: IA(P) = 0: GOTO 1720
1480 DF = -1: GOTO 1720
1490 DF = 0: GOTO 1720
1500 GOSUB 1810
1510 SF = INT(.5 + 2 ^ P) OR SF: GOTO 1720
1520 GOSUB 1810
1530 SF = SF AND NOT INT(.5 + 2 ^ P): GOTO 1720
1540 PRINT "I'm dead...": R = RL: DF = 0: GOTO 1580
1550 GOSUB 1810: L = P: GOSUB 1810: IA(L) = P: GOTO 1720
1560 PRINT "The game is now over.": PRINT "Another game? "; : GOSUB 80: K$ = IN$: PRINT K$: IF LEFT$(K$, 1) = "N" THEN 9999
     FOR X = 0 TO IL: IA(X) = I2(X): NEXT: GOTO 350
1580 GOSUB 600: GOTO 1720
1590 L = 0: FOR Z = 1 TO IL: IF IA(Z) = TR THEN IF LEFT$(IA$(Z), 1) = "*" THEN L = L + 1
     NEXT Z: PRINT "I've stored"; L; "treasures.  On a scale"
     PRINT "of 0 to 100, that rates a"; INT(L / TT * 100); "."
     IF L = TT THEN PRINT "Well done. ": GOTO 1560
     GOTO 1720
1640 PRINT "I'm carrying:": K$ = "Nothing!": FOR Z = 0 TO IL: IF IA(Z) <> -1 THEN 1670
     GOSUB 650: IF LEN(TP$) + POS(0) > 39 THEN PRINT
     PRINT TP$; ".", ; : K$ = ""
1670 NEXT: PRINT K$: GOTO 1720
1680 P = 0: GOTO 1510
1690 P = 0: GOTO 1530
1700 LX = LT: IA(9) = -1: GOTO 1720
1710 CLS : GOTO 1720
1720 NEXT Y
1730 IF NV(0) <> 0 THEN 1760
     GOTO 830
1760 IF NV(0) = 0 THEN 1800
     GOSUB 1900
     IF F THEN PRINT "I don't understand your command.": GOTO 1800
     IF NOT F2 THEN PRINT "I can't do that yet.": GOTO 1800
1800 RETURN
1810 IP = IP + 1
     ON IP GOTO 1830, 1840, 1850, 1860, 1870
1830 W = C1%(X): GOTO 1880
1840 W = C2%(X): GOTO 1880
1850 W = C3%(X): GOTO 1880
1860 W = C4%(X): GOTO 1880
1870 W = C5%(X): GOTO 1880
1880 P = INT(W / 20): M = W - P * 20: IF M <> 0 THEN 1810
     RETURN

1900 IF NV(0) <> 10 AND NV(0) <> 18 OR F3 THEN 2120
     IF NV(1) = 0 THEN PRINT "What?": GOTO 2060
     IF NV(0) <> 10 THEN 1950
     L = 0: FOR Z = 0 TO IL: IF IA(Z) = -1 THEN L = L + 1
     NEXT Z: IF L >= MX THEN PRINT "I've too much to carry!": GOTO 2060
1950 K = 0
     FOR X = 0 TO IL
     IF RIGHT$(IA$(X), 1) <> "/" THEN 2070
     LL = LEN(IA$(X)) - 1
     TP$ = MID$(IA$(X), 1, LL)
     FOR Y = LL TO 2 STEP -1
     IF MID$(TP$, Y, 1) = "/" THEN
       TP$ = LEFT$(MID$(TP$, Y + 1), LN)
       IF TP$ <> NV$(NV(1), 1) THEN 2070
       IF NV(0) = 10 THEN 2030
       IF IA(X) <> -1 THEN K = 1: GOTO 2070
       IA(X) = R: K = 3: GOTO 2050
2030   IF IA(X) <> R THEN K = 2: GOTO 2070
       IA(X) = -1: K = 3
2050   PRINT "OK, "
2060   F = 0: RETURN
     END IF
     NEXT Y
2070 NEXT X
     IF K = 1 THEN PRINT "I'm not carrying it!"
     IF K = 2 THEN PRINT "I don't see it here."
     IF K = 0 THEN IF NOT F3 THEN PRINT "It's beyond my power to do that.": F = 0
     IF K <> 0 THEN F = 0
2120 RETURN
2210 FOR X = 0 TO CL STEP 2: Y = X + 1
     READ C0%(X), C1%(X), C2%(X), C3%(X), C4%(X), C5%(X), C6%(X), C7%(X)
     READ C0%(Y), C1%(Y), C2%(Y), C3%(Y), C4%(Y), C5%(Y), C6%(Y), C7%(Y): NEXT X
     FOR X = 0 TO NL STEP 10: FOR Y = 0 TO 1
     READ NV$(X, Y), NV$(X + 1, Y), NV$(X + 2, Y), NV$(X + 3, Y), NV$(X + 4, Y), NV$(X + 5, Y)
     READ NV$(X + 6, Y), NV$(X + 7, Y), NV$(X + 8, Y), NV$(X + 9, Y): NEXT Y, X
     FOR X = 0 TO RL: READ RM(X, 0), RM(X, 1), RM(X, 2), RM(X, 3), RM(X, 4), RM(X, 5), RS$(X): NEXT
     FOR X = 0 TO ML: READ MS$(X): NEXT X
     FOR X = 0 TO IL: READ IA$(X), IA(X): I2(X) = IA(X): NEXT X: RETURN
     DATA 75,161,386,160,200,0,17612,0
     DATA 10,401,420,400,146,0,1852,8850
     DATA 8,421,0,0,0,0,2011,0
     DATA 8,521,520,260,0,0,2609,7800
     DATA 100,108,760,820,420,100,8312,9064
     DATA 100,484,0,0,0,0,5613,0
     DATA 5,141,140,20,246,0,6062,0
     DATA 5,406,426,400,442,146,7845,0
     DATA 8,482,152,0,0,0,2311,0
     DATA 100,104,0,0,0,0,8550,0
     DATA 50,161,246,160,1100,0,7259,7800
     DATA 100,148,140,940,500,0,9062,9900
     DATA 30,841,426,406,400,0,7845,0
     DATA 50,542,141,0,0,0,10504,9150
     DATA 100,248,642,720,640,700,8005,7950
     DATA 100,248,542,1040,540,0,8005,0
     DATA 100,28,49,20,40,0,6360,8700
     DATA 100,288,260,280,0,0,7860,9150
     DATA 100,248,240,0,0,0,9660,0
     DATA 100,269,260,0,0,0,16558,17357
     DATA 100,28,48,20,40,0,4110,9000
     DATA 4366,22,0,0,0,0,6900,0
     DATA 4374,0,0,0,0,0,9750,0
     DATA 4404,682,0,0,0,0,6900,0
     DATA 4407,82,0,0,0,0,6900,0
     DATA 1521,142,421,420,140,0,8902,450
     DATA 1542,462,146,482,0,0,2311,0
     DATA 1521,142,401,400,140,0,8902,450
     DATA 2742,461,460,502,780,500,8864,8005
     DATA 2742,461,460,0,0,0,7950,0
     DATA 1523,482,146,0,0,0,2311,0
     DATA 1523,482,141,266,0,0,2400,0
     DATA 1523,482,141,261,260,520,8902,0
     DATA 1533,0,0,0,0,0,9900,0
     DATA 4350,0,0,0,0,0,10564,0
     DATA 5100,0,0,0,0,0,9900,0
     DATA 3450,581,344,460,0,0,8118,8614
     DATA 2125,623,566,0,0,0,2850,0
     DATA 2125,621,561,620,0,0,3021,9209
     DATA 6794,0,0,0,0,0,17100,0
     DATA 2125,622,561,620,240,0,10555,8720
     DATA 184,404,702,380,0,0,8170,9600
     DATA 1525,24,806,0,0,0,2400,0
     DATA 1525,24,801,800,620,0,8902,0
     DATA 2725,621,620,800,0,0,8902,3450
     DATA 2125,362,561,0,0,0,3300,0
     DATA 6803,0,0,0,0,0,17100,0
     DATA 185,384,0,0,0,0,3750,0
     DATA 1510,762,760,505,0,0,7800,0
     DATA 2710,761,760,582,20,0,7986,8700
     DATA 6343,921,920,0,0,0,509,0
     DATA 1513,122,261,260,240,0,8902,0
     DATA 900,384,420,726,0,0,8164,0
     DATA 900,424,380,0,0,0,8164,0
     DATA 185,424,502,0,0,0,3900,0
     DATA 185,424,505,440,0,0,8170,9600
     DATA 5265,0,0,0,0,0,10650,0
     DATA 204,682,0,0,0,0,7650,0
     DATA 2723,521,502,520,480,280,4259,8008
     DATA 1513,122,266,0,0,0,2400,0
     DATA 5751,62,0,0,0,0,300,0
     DATA 207,40,102,0,0,0,8170,9600
     DATA 2713,241,240,260,0,0,8902,4350
     DATA 1528,442,440,200,0,0,8319,8294
     DATA 1257,100,102,292,80,221,8303,1050
     DATA 5870,104,322,286,0,0,900,0
     DATA 5570,104,322,286,0,0,900,0
     DATA 3611,221,60,220,0,0,4558,7950
     DATA 5870,322,281,320,340,0,8303,9600
     DATA 2737,721,685,720,0,0,7950,0
     DATA 900,384,721,0,0,0,5011,0
     DATA 2737,721,1120,900,680,720,8003,8309
     DATA 1537,722,720,0,0,0,4852,0
     DATA 3300,0,0,0,0,0,5100,0
     DATA 3900,0,0,0,0,0,9813,0
     DATA 1510,762,502,0,0,0,3900,0
     DATA 2710,761,585,820,760,0,5303,8850
     DATA 1050,68,765,60,0,0,16710,0
     DATA 4800,68,60,542,0,0,5910,0
     DATA 4950,0,0,0,0,0,9750,0
     DATA 7050,401,0,0,0,0,16613,15750
     DATA 7050,421,0,0,0,0,16613,15750
     DATA 184,364,0,0,0,0,15300,0
     DATA 1554,682,0,0,0,0,7650,0
     DATA 7650,502,860,360,500,0,6212,8250
     DATA 2723,521,542,480,880,540,8003,8293
     DATA 7350,68,60,0,0,0,9001,16607
     DATA 5870,342,0,0,0,0,9600,0
     DATA 166,702,380,0,0,0,10554,9600
     DATA 1050,68,760,100,80,502,8308,4710
     DATA 6761,0,0,0,0,0,16614,0
     DATA 5400,0,0,0,0,0,197,0
     DATA 207,82,60,0,0,0,8170,9600
     DATA 1257,102,221,100,80,281,8303,1200
     DATA 6038,502,0,0,0,0,3947,0
     DATA 6039,542,0,0,0,0,5897,0
     DATA 6313,241,240,260,0,0,509,7800
     DATA 6313,122,0,0,0,0,450,0
     DATA 6342,461,460,0,0,0,509,0
     DATA 7500,322,68,320,340,60,8303,810
     DATA 4050,524,10,0,0,0,4950,0
     DATA 4050,524,11,200,0,0,8170,9600
     DATA 1200,226,0,0,0,0,5700,0
     DATA 6600,943,221,220,500,140,2762,8700
     DATA 6600,221,527,220,500,0,2762,9900
     DATA 4217,183,0,0,0,0,7650,0
     DATA 1521,142,140,0,0,0,7800,0
     DATA 4217,203,169,960,160,0,7403,8700
     DATA 4217,203,228,0,0,0,150,0
     DATA 4217,203,208,220,660,960,7558,8159
     DATA 4217,203,188,200,660,980,7558,8159
     DATA 4217,203,168,980,180,0,7403,8700
     DATA 7650,401,400,420,0,0,462,8902
     DATA 7650,421,0,0,0,0,463,9150
     DATA 4050,527,0,0,0,0,15300,0
     DATA 3450,586,0,0,0,0,150,0
     DATA 6600,0,0,0,0,0,150,0
     DATA 2117,183,0,0,0,0,1500,0
     DATA 6807,0,0,0,0,0,15450,0
     DATA 2723,521,480,520,260,0,8009,7800
     DATA 6780,0,0,0,0,0,15450,0
     DATA 6771,0,0,0,0,0,15450,0
     DATA 7200,0,0,0,0,0,15600,0
     DATA 207,224,560,0,0,0,8170,9600
     DATA 7050,524,0,0,0,0,16605,16350
     DATA 7050,224,0,0,0,0,16605,0
     DATA 7050,384,0,0,0,0,16605,0
     DATA 7050,464,0,0,0,0,16606,0
     DATA 7050,264,0,0,0,0,16609,0
     DATA 7050,344,0,0,0,0,16609,0
     DATA 7050,304,0,0,0,0,16609,0
     DATA 7050,424,0,0,0,0,16605,0
     DATA 7050,164,0,0,0,0,16608,0
     DATA 5570,281,322,340,320,0,8005,0
     DATA 206,342,120,0,0,0,8156,10564
     DATA 2117,201,200,180,0,0,8902,1500
     DATA 2119,181,180,200,0,0,8902,1350
     DATA 1551,62,0,0,0,0,1711,0
     DATA 166,1042,480,0,0,0,8170,9600
     DATA 1549,0,0,0,0,0,16611,0
     DATA 2100,561,365,0,0,0,3600,0
     DATA 7650,0,0,0,0,0,150,0
     DATA 3450,581,347,340,0,0,8118,8464
     DATA 7050,24,0,0,0,0,16605,0
     DATA 3611,226,0,0,0,0,5700,0
     DATA 7050,404,0,0,0,0,16616,15450
     DATA 6774,0,0,0,0,0,9750,0
     DATA 166,84,100,0,0,0,8170,9600
     DATA 1542,462,460,0,0,0,7800,0
     DATA 7050,0,0,0,0,0,150,0
     DATA 1200,0,0,0,0,0,197,0
     DATA 3600,0,0,0,0,0,16800,0
     REM VOCABULARY
     DATA AUT,GO,*ENT,*RUN,*WAL,*CLI,JUM,BEA,CHO,*CUT
     DATA ANY,NORTH,SOUTH,EAST,WEST,UP,DOWN,NET,FIS,AWA
     DATA TAK,*GET,*PIC,*CAT,LIG,*TUR,*LAM,*BUR,DRO,*REL
     DATA MIR,AXE,AXE,WAT,BOT,GAM,HOL,LAM,*ON,OFF
     DATA *SPI,*LEA,STO,AWA,THR,TOS,QUI,SWI,RUB,LOO
     DATA DOO,MUD,*MED,BEE,SCO,GAS,FLI,EGG,OIL,*SLI
     DATA *SHO,*SEE,DRA,SCO,INV,SAV,WAK,UNL,REA,OPE
     DATA KEY,HEL,BUN,INV,LED,THR,CRO,BRI,BEA,DRA
     DATA ATT,*KIL,DRI,*GAT,BUN,FIN,*LOC,HEL,SAY,WIN
     DATA RUG,RUB,HON,FRU,OX,RIN,CHI,*BIT,BRA,SIG
     DATA DOO,SCR,*YEL,*HOL," "," "," "," "," "," "
     DATA BLA,WEB,*WRI,SWA,LAV,ARO,HAL,TRE,*STU,FIR
     REM ROOMS
     DATA 0,7,10,1,0,24," "
     DATA 23,1,1,25,0,0,"dismal swamp."
     DATA 0,0,0,0,0,1,"*I'm in the top of a tall cypress tree."
     DATA 1,1,1,1,1,4,"large hollow damp stump in the swamp."
     DATA 0,0,0,0,3,5,"root chamber under the stump."
     DATA 0,0,0,0,4,0,"semi-dark hole by the root chamber."
     DATA 0,0,0,0,5,7,"long down-sloping hall."
     DATA 8,9,0,27,6,12,"large cavern."
     DATA 0,7,0,0,0,0,"large 8-sided room."
     DATA 7,0,0,0,20,0,"royal anteroom."
     DATA 11,10,0,1,0,26,"*I'm on the shore of a lake."
     DATA 11,11,23,11,0,0,"forest."
     DATA 13,15,15,0,0,13,"maze of pits."
     DATA 0,0,0,14,12,0,"maze of pits."
     DATA 17,12,13,16,16,17,"maze of pits."
     DATA 12,0,13,12,13,0,"maze of pits."
     DATA 0,17,0,0,14,17,"maze of pits."
     DATA 17,12,12,15,14,18,"maze of pits."
     DATA 0,0,0,0,17,0
     DATA "bottom of a chasm.  Above 2 ledges.  One has a bricked up window."
     DATA 0,0,0,20,0,0
     DATA "*I'm on a narrow ledge by a chasm.  Across the chasm is a throne room."
     DATA 0,0,0,0,0,9,"royal chamber."
     DATA 0,0,0,0,0,0,"*I'm on a narrow ledge by the throne room-across chasm-ledge."
     DATA 0,0,0,21,0,0,"throne room."
     DATA 10,1,10,11,0,0,"sunny meadow."
     DATA 0,0,0,0,0,0
     DATA "*I think I'm in real trouble.  Here's a guy with a pitchfork!"
     DATA 11,0,1,11,0,0,"hidden grove."
     DATA 0,0,0,0,0,0,"quick-sand bog."
     DATA 0,0,7,0,0,0,"memory RAM of an IBM-PC.  I took a wrong turn!"
     DATA 0,0,0,0,0,11
     DATA "branch on the top of an old oak tree.                                           To the east I see a meadow beyond a lake."
     DATA 0,0,0,0,0,0," "
     DATA 0,0,0,0,0,0," "
     DATA 0,0,0,0,0,0," "
     DATA 0,0,0,0,0,0," "
     DATA 0,24,11,24,28,24
     DATA "large misty room with strange letters over the exits."
     REM MESSAGES
     DATA " ",Nothing happens,CHOP IT DOWN!,Boy that really hit the spot!
     DATA Dragon smells something - awakens - attacks me!,Lock shatters.
     DATA I can't.  It's locked.
     DATA TIMBER...  Something fell from the treetop and vanished!
     DATA TIMBER...,Lamp is off,Flameless lamp is on.
     DATA I'm bit by a spider.,My chigger bites are now infected.
     DATA The bites have rotted my whole body.,The bear eats the honey and falls asleep.
     DATA Bees sting me,I've no container.,The bees all suffocated.
     DATA Something I'm holding vibrated and...,Nothing to light it with.
     DATA Gas bladder blew up.,in my hands!
     DATA Gas needs to be contained before it will burn.,Gas dissipates.
     DATA That won't ignite.,How?  Jump?
     DATA The bear won't let me.,Don't waste *HONEY*.  Get mad instead.  Dam lava!
     DATA Bees madden the bear.  Bear then attacks me!,It soaks into the ground.
     DATA In one word tell me what.,Oh no...Bear dodges...CRASH!,It's heavy!
     DATA Something's too heavy.  I fall.,To stop game say -QUIT-
     DATA The mirror hits the floor and shatters into a million pieces.
     DATA "Mirror lands softly on the rug - lights up and says:"
     DATA You lost *ALL* treasures.,Not carrying the axe.  TAKE INVENTORY!
     DATA It doesn't bother him at all.,The mud dried up and fell off.
     DATA The bear got startled and fell off the ledge!
     DATA *DRAGON STINGS* and fades.  I don't get it - hope you do.
     DATA The bees attack the dragon which gets up and flies away...
     DATA Magic oil attracts magic lamp.  Lamp is now full.
     DATA I'm bit by chiggers.
     DATA There's something there all right!  Maybe I should go there?
     DATA Maybe if I threw something?...,Too dry.  Fish die.
     DATA A glowing genie appears - drops something - then vanishes.
     DATA A genie appears - says 'boy you're selfish' - takes something - then vanishes!
     DATA NO!  It's too hot.,Not here.,Try the swamp,Use one word.
     DATA "Try:  LOOK,JUMP,SWIM,CLIMB,THROW,FIND,GO,TAKE,INVENTORY,SCORE."
     DATA Only 3 things will wake the dragon.  One of them is dangerous!
     DATA "If you need a hint on something, try 'HELP'."
     DATA Read the sign in the meadow!,You may need magic words here.
     DATA A voice booms out ...,PLEASE LEAVE IT ALONE!,Can only throw axe.
     DATA Medicine is good for bites.,I don't know where it is.
     DATA Treasures have an * in their name.  Say 'SCORE',Blow it up.
     DATA Fish escape back to the lake.
     DATA " "," "," "," "
     REM ITEMS
     DATA " ",0,"dark hole",4,*POT OF RUBIES*/RUB/,4
     DATA "spider web with writing on it.",2
     DATA "Hollow stump and remains of a felled tree.",0,"cypress tree",1
     DATA "water",10,"evil smelling mud/MUD/",1,*GOLDEN FISH*/FIS/,10
     DATA "lit brass lamp/LAM/",0,"old fashoned brass lamp/LAM/",3
     DATA "rusty axe (magic word- BUNYON -on it)/AXE/",10
     DATA "bottle of water/BOT/",3,"empty bottle/BOT/",0
     DATA "ring of skeleton keys/KEY/",2
     DATA "sign- LEAVE TREASURE HERE - (say 'SCORE')",3
     DATA "locked door",5,"open door with a hallway beyond",0,"swamp gas",1
     DATA *GOLDEN NET*/NET/,18,"chigger bites",0,"infected chigger bites",0
     DATA "floating patch of oily slime",1,*ROYAL HONEY*/HON/,8
     DATA "large african bees",8,"thin black bear",21,"bees in a bottle/BOT/",0
     DATA "large sleeping dragon",23,"flint and steel/FLI/",13
     DATA *THICK PERSIAN RUG*/RUG/,17
     DATA "sign- MAGIC WORD IS AWAY. LOOK LA -(rest of sign is missing)",18
     DATA "distended gas bladder/BLA/",0,"bricked up window",20
     DATA "sign here says- IN SOME CASES MUD IS GOOD, IN OTHERS...",23
     DATA "stream of lava",18
     DATA "bricked up window with a hole in it.  Beyond is a ledge.",0
     DATA "loose fire bricks",0,*GOLD CROWN*/CRO/,22,*MAGIC MIRROR*,21
     DATA "sleeping bear",0,"empty wine bladder/BLA/",9,"broken glass",0
     DATA "chiggers/CHI/",1,"dead bear",0,*DRAGON EGGS* (very rare)/EGG/,0
     DATA "lava stream with a brick dam",0,*JEWELED FRUIT*/FRU/,25
     DATA *SMALL STATUE OF A BLUE OX*/OX/,26,*DIAMOND RING*/RIN/,0
     DATA *DIAMOND BRACELET*/BRA/,0
     DATA "strange scratchings on rock reveals- ALADDIN WAS HERE -",14
     DATA "sign says- LIMBO.  FIND RIGHT EXIT AND LIVE AGAIN!",33
     DATA "smoking hole.  Pieces of dragon and gore.",0
     DATA "sign says- NO SWIMMING ALLOWED -",10,"arrow pointing down",17
     DATA "dead fish/FIS/",0,*FIRESTONE* (cold now)/FIR/,0
     DATA "sign says- PAUL'S PLACE -",25,"trees",11," ",0," ",0
9999 WIDTH 80: COLOR 7, 0: KEY ON: LOCATE , , 1, 8, 11: END

