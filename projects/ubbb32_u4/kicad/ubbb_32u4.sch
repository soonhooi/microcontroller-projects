EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:custom
EELAYER 27 0
EELAYER END
$Descr User 9000 7000
encoding utf-8
Sheet 1 1
Title "UBBB 32u4"
Date "2 apr 2015"
Rev "1.2"
Comp "Digital Cave"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA32U4-A U1
U 1 1 5457F510
P 4000 3550
F 0 "U1" H 3050 5250 40  0000 C CNN
F 1 "ATMEGA32U4-A" H 4700 2050 40  0000 C CNN
F 2 "TQFP44" H 4000 3550 35  0000 C CIN
F 3 "" H 5100 4650 60  0000 C CNN
	1    4000 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 1500 3550 1750
Wire Wire Line
	3800 1500 3800 1750
Wire Wire Line
	3900 1500 3900 1750
Connection ~ 3800 1650
Wire Wire Line
	4150 1500 4150 1750
Connection ~ 3900 1650
Wire Wire Line
	4250 1500 4250 1750
Wire Wire Line
	3600 5150 3600 5350
Wire Wire Line
	3600 5250 4150 5250
Wire Wire Line
	3850 5250 3850 5150
Wire Wire Line
	3950 5250 3950 5150
Connection ~ 3850 5250
Wire Wire Line
	4050 5250 4050 5150
Connection ~ 3950 5250
Wire Wire Line
	4150 5250 4150 5150
Connection ~ 4050 5250
Wire Wire Line
	5100 2100 6000 2100
Wire Wire Line
	5100 2200 6000 2200
Wire Wire Line
	5100 2300 6000 2300
Wire Wire Line
	2750 2000 2850 2000
Wire Wire Line
	2750 1450 2750 2000
$Comp
L USB-MINI-B CON1
U 1 1 54580264
P 1400 2900
F 0 "CON1" H 1150 3350 60  0000 C CNN
F 1 "USB-MINI-B" H 1350 2400 60  0000 C CNN
F 2 "" H 1400 2900 60  0000 C CNN
F 3 "" H 1400 2900 60  0000 C CNN
	1    1400 2900
	-1   0    0    1   
$EndComp
NoConn ~ 1950 2750
Wire Wire Line
	850  2600 750  2600
Wire Wire Line
	750  2600 750  3300
Wire Wire Line
	850  3200 750  3200
Connection ~ 750  3200
Wire Wire Line
	850  3050 750  3050
Connection ~ 750  3050
Wire Wire Line
	850  2750 750  2750
Connection ~ 750  2750
$Comp
L GND #PWR01
U 1 1 54580437
P 2050 2600
F 0 "#PWR01" H 2050 2600 30  0001 C CNN
F 1 "GND" H 2050 2530 30  0001 C CNN
F 2 "" H 2050 2600 60  0000 C CNN
F 3 "" H 2050 2600 60  0000 C CNN
	1    2050 2600
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR02
U 1 1 54580444
P 750 3300
F 0 "#PWR02" H 750 3300 30  0001 C CNN
F 1 "GND" H 750 3230 30  0001 C CNN
F 2 "" H 750 3300 60  0000 C CNN
F 3 "" H 750 3300 60  0000 C CNN
	1    750  3300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 54580485
P 2750 4800
F 0 "#PWR03" H 2750 4800 30  0001 C CNN
F 1 "GND" H 2750 4730 30  0001 C CNN
F 2 "" H 2750 4800 60  0000 C CNN
F 3 "" H 2750 4800 60  0000 C CNN
	1    2750 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4400 2850 4400
$Comp
L GND #PWR04
U 1 1 54580501
P 2750 4000
F 0 "#PWR04" H 2750 4000 30  0001 C CNN
F 1 "GND" H 2750 3930 30  0001 C CNN
F 2 "" H 2750 4000 60  0000 C CNN
F 3 "" H 2750 4000 60  0000 C CNN
	1    2750 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3900 2750 4000
Wire Wire Line
	2850 3600 2750 3600
Wire Wire Line
	2750 3600 2750 3700
Wire Wire Line
	1950 2600 2050 2600
$Comp
L R R2
U 1 1 545805E8
P 2250 3050
F 0 "R2" V 2330 3050 40  0000 C CNN
F 1 "22" V 2257 3051 40  0000 C CNN
F 2 "~" V 2180 3050 30  0000 C CNN
F 3 "~" H 2250 3050 30  0000 C CNN
	1    2250 3050
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 545805FA
P 2250 2900
F 0 "R1" V 2330 2900 40  0000 C CNN
F 1 "22" V 2257 2901 40  0000 C CNN
F 2 "~" V 2180 2900 30  0000 C CNN
F 3 "~" H 2250 2900 30  0000 C CNN
	1    2250 2900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2700 3350 2850 3350
Wire Wire Line
	1950 2900 2000 2900
Wire Wire Line
	1950 3200 2850 3200
Wire Wire Line
	1950 3050 2000 3050
Wire Wire Line
	2500 3050 2600 3050
Wire Wire Line
	2600 3050 2600 3450
Wire Wire Line
	2600 3450 2850 3450
Wire Wire Line
	2500 2900 2700 2900
Wire Wire Line
	2700 2900 2700 3350
Connection ~ 4250 1650
$Comp
L +5V #PWR05
U 1 1 54580A04
P 4550 1650
F 0 "#PWR05" H 4550 1740 20  0001 C CNN
F 1 "+5V" H 4550 1740 30  0000 C CNN
F 2 "" H 4550 1650 60  0000 C CNN
F 3 "" H 4550 1650 60  0000 C CNN
	1    4550 1650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR06
U 1 1 54580A5B
P 3600 5350
F 0 "#PWR06" H 3600 5350 30  0001 C CNN
F 1 "GND" H 3600 5280 30  0001 C CNN
F 2 "" H 3600 5350 60  0000 C CNN
F 3 "" H 3600 5350 60  0000 C CNN
	1    3600 5350
	1    0    0    -1  
$EndComp
Connection ~ 3600 5250
$Comp
L SW_PUSH_SMALL SW1
U 1 1 54580AA8
P 2650 1350
F 0 "SW1" H 2800 1460 30  0000 C CNN
F 1 "SW_PUSH_SMALL" H 2650 1271 30  0000 C CNN
F 2 "~" H 2650 1350 60  0000 C CNN
F 3 "~" H 2650 1350 60  0000 C CNN
	1    2650 1350
	1    0    0    -1  
$EndComp
Connection ~ 2750 1550
$Comp
L R R3
U 1 1 54580AFB
P 2400 1550
F 0 "R3" V 2480 1550 40  0000 C CNN
F 1 "1k" V 2407 1551 40  0000 C CNN
F 2 "~" V 2330 1550 30  0000 C CNN
F 3 "~" H 2400 1550 30  0000 C CNN
	1    2400 1550
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR07
U 1 1 54580C3A
P 2050 1550
F 0 "#PWR07" H 2050 1640 20  0001 C CNN
F 1 "+5V" H 2050 1640 30  0000 C CNN
F 2 "" H 2050 1550 60  0000 C CNN
F 3 "" H 2050 1550 60  0000 C CNN
	1    2050 1550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2050 1550 2150 1550
Wire Wire Line
	2550 1250 2050 1250
$Comp
L GND #PWR08
U 1 1 54580CD0
P 2050 1250
F 0 "#PWR08" H 2050 1250 30  0001 C CNN
F 1 "GND" H 2050 1180 30  0001 C CNN
F 2 "" H 2050 1250 60  0000 C CNN
F 3 "" H 2050 1250 60  0000 C CNN
	1    2050 1250
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 54580CE7
P 5500 5350
F 0 "R4" V 5580 5350 40  0000 C CNN
F 1 "1k" V 5507 5351 40  0000 C CNN
F 2 "~" V 5430 5350 30  0000 C CNN
F 3 "~" H 5500 5350 30  0000 C CNN
	1    5500 5350
	0    -1   -1   0   
$EndComp
Text Label 5800 5350 0    60   ~ 0
B4
Text Label 5200 2400 0    60   ~ 0
B4
Entry Wire Line
	6000 2000 6100 2100
Entry Wire Line
	6000 2100 6100 2200
Entry Wire Line
	6000 2200 6100 2300
Entry Wire Line
	6000 2300 6100 2400
Entry Wire Line
	6000 2400 6100 2500
Entry Wire Line
	6000 2500 6100 2600
Entry Wire Line
	6000 2600 6100 2700
Entry Wire Line
	6000 2700 6100 2800
Entry Wire Line
	6000 2900 6100 3000
Entry Wire Line
	6000 3000 6100 3100
Entry Wire Line
	6000 3200 6100 3300
Entry Wire Line
	6000 3300 6100 3400
Entry Wire Line
	6000 3400 6100 3500
Entry Wire Line
	6000 3500 6100 3600
Entry Wire Line
	6000 3600 6100 3700
Entry Wire Line
	6000 3700 6100 3800
Entry Wire Line
	6000 3800 6100 3900
Entry Wire Line
	6000 3900 6100 4000
Entry Wire Line
	6000 4100 6100 4200
Entry Wire Line
	6000 4200 6100 4300
Entry Wire Line
	6000 4400 6100 4500
Entry Wire Line
	6000 4500 6100 4600
Entry Wire Line
	6000 4600 6100 4700
Entry Wire Line
	6000 4700 6100 4800
Entry Wire Line
	6000 4800 6100 4900
Entry Wire Line
	6000 4900 6100 5000
Wire Wire Line
	5100 2000 6000 2000
Wire Wire Line
	6000 2400 5100 2400
Wire Wire Line
	5100 2500 6000 2500
Wire Wire Line
	6000 2600 5100 2600
Wire Wire Line
	5100 2700 6000 2700
Wire Wire Line
	6000 2900 5100 2900
Wire Wire Line
	5100 3000 6000 3000
Wire Wire Line
	6000 3200 5100 3200
Wire Wire Line
	5100 3300 6000 3300
Wire Wire Line
	6000 3400 5100 3400
Wire Wire Line
	5100 3500 6000 3500
Wire Wire Line
	6000 3600 5100 3600
Wire Wire Line
	5100 3700 6000 3700
Wire Wire Line
	6000 3800 5100 3800
Wire Wire Line
	5100 3900 6000 3900
Wire Wire Line
	6000 4100 5100 4100
Wire Wire Line
	5100 4200 6000 4200
Wire Wire Line
	6000 4400 5100 4400
Wire Wire Line
	5100 4500 6000 4500
Wire Wire Line
	6000 4600 5100 4600
Wire Wire Line
	5100 4700 6000 4700
Wire Wire Line
	6000 4800 5100 4800
Wire Wire Line
	5100 4900 6000 4900
Text Label 5200 2300 0    60   ~ 0
B3
Text Label 5200 2200 0    60   ~ 0
B2
Text Label 5200 2100 0    60   ~ 0
B1
Text Label 5200 2500 0    60   ~ 0
B5
Text Label 5200 2600 0    60   ~ 0
B6
Text Label 5200 2700 0    60   ~ 0
B7
Text Label 5200 2000 0    60   ~ 0
B0
Text Label 5200 2900 0    60   ~ 0
C6
Text Label 5200 3000 0    60   ~ 0
C7
Text Label 5200 3200 0    60   ~ 0
D0
Text Label 5200 3300 0    60   ~ 0
D1
Text Label 5200 3400 0    60   ~ 0
D2
Text Label 5200 3500 0    60   ~ 0
D3
Text Label 5200 3600 0    60   ~ 0
D4
Text Label 5200 3700 0    60   ~ 0
D5
Text Label 5200 3800 0    60   ~ 0
D6
Text Label 5200 3900 0    60   ~ 0
D7
Text Label 5200 4100 0    60   ~ 0
E2
Text Label 5200 4200 0    60   ~ 0
E6
Text Label 5200 4400 0    60   ~ 0
F0
Text Label 5200 4500 0    60   ~ 0
F1
Text Label 5200 4600 0    60   ~ 0
F4
Text Label 5200 4700 0    60   ~ 0
F5
Text Label 5200 4800 0    60   ~ 0
F6
Text Label 5200 4900 0    60   ~ 0
F7
Wire Bus Line
	6100 2100 6100 5750
Entry Wire Line
	6100 5200 6200 5300
$Comp
L SW_PUSH_SMALL SW2
U 1 1 5458175B
P 6600 5400
F 0 "SW2" H 6750 5510 30  0000 C CNN
F 1 "SW_PUSH_SMALL" H 6600 5321 30  0000 C CNN
F 2 "~" H 6600 5400 60  0000 C CNN
F 3 "~" H 6600 5400 60  0000 C CNN
	1    6600 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 5300 6700 5300
Text Label 6200 5300 0    60   ~ 0
E2
$Comp
L R R7
U 1 1 5458183C
P 6950 5300
F 0 "R7" V 7030 5300 40  0000 C CNN
F 1 "1k" V 6957 5301 40  0000 C CNN
F 2 "~" V 6880 5300 30  0000 C CNN
F 3 "~" H 6950 5300 30  0000 C CNN
	1    6950 5300
	0    -1   -1   0   
$EndComp
Connection ~ 6500 5300
Wire Wire Line
	6700 5500 6700 5600
$Comp
L GND #PWR09
U 1 1 54581914
P 6700 5600
F 0 "#PWR09" H 6700 5600 30  0001 C CNN
F 1 "GND" H 6700 5530 30  0001 C CNN
F 2 "" H 6700 5600 60  0000 C CNN
F 3 "" H 6700 5600 60  0000 C CNN
	1    6700 5600
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 5458191A
P 7300 5300
F 0 "#PWR010" H 7300 5390 20  0001 C CNN
F 1 "+5V" H 7300 5390 30  0000 C CNN
F 2 "" H 7300 5300 60  0000 C CNN
F 3 "" H 7300 5300 60  0000 C CNN
	1    7300 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	7300 5300 7200 5300
Entry Wire Line
	6100 2100 6200 2200
Entry Wire Line
	6100 2200 6200 2300
Entry Wire Line
	6100 2300 6200 2400
Entry Wire Line
	6100 2400 6200 2500
Entry Wire Line
	6100 2500 6200 2600
Entry Wire Line
	6100 2600 6200 2700
Entry Wire Line
	6100 2700 6200 2800
Entry Wire Line
	6100 2800 6200 2900
Entry Wire Line
	6100 2900 6200 3000
Entry Wire Line
	6100 3000 6200 3100
Entry Wire Line
	6100 3100 6200 3200
Entry Wire Line
	6100 3200 6200 3300
Entry Wire Line
	6100 3300 6200 3400
Entry Wire Line
	6100 3400 6200 3500
Entry Wire Line
	6100 3500 6200 3600
Entry Wire Line
	6100 3600 6200 3700
Entry Wire Line
	6100 3700 6200 3800
Entry Wire Line
	6100 3800 6200 3900
Entry Wire Line
	6100 3900 6200 4000
Entry Wire Line
	6100 4000 6200 4100
Entry Wire Line
	6100 4200 6200 4300
Entry Wire Line
	6100 4300 6200 4400
Entry Wire Line
	6100 4500 6200 4600
Entry Wire Line
	6100 4600 6200 4700
Entry Wire Line
	6100 4700 6200 4800
Entry Wire Line
	6100 4800 6200 4900
Entry Wire Line
	6100 4900 6200 5000
Entry Wire Line
	6100 5000 6200 5100
Wire Wire Line
	6200 2200 7300 2200
Wire Wire Line
	7300 2300 6200 2300
Wire Wire Line
	6200 2400 7300 2400
Wire Wire Line
	7300 2600 6200 2600
Wire Wire Line
	6200 2700 7300 2700
Wire Wire Line
	6200 2800 7300 2800
Wire Wire Line
	7300 2900 6200 2900
Wire Wire Line
	6200 3000 7300 3000
Wire Wire Line
	7300 3100 6200 3100
Wire Wire Line
	6200 3200 7300 3200
Wire Wire Line
	6200 3300 7300 3300
Wire Wire Line
	7300 3400 6200 3400
Wire Wire Line
	6200 3500 7300 3500
Wire Wire Line
	7300 3600 6200 3600
Wire Wire Line
	6200 3700 7300 3700
Wire Wire Line
	6200 3800 7300 3800
Wire Wire Line
	7300 3900 6200 3900
Wire Wire Line
	6200 4000 7300 4000
Wire Wire Line
	7300 4100 6200 4100
Wire Wire Line
	6200 4200 7300 4200
Wire Wire Line
	6200 4300 7300 4300
Wire Wire Line
	7300 4400 6200 4400
Wire Wire Line
	6200 4500 7300 4500
Wire Wire Line
	7300 4600 6200 4600
Wire Wire Line
	6200 4700 7300 4700
Wire Wire Line
	6200 4800 7300 4800
Wire Wire Line
	7300 4900 6200 4900
Wire Wire Line
	6200 5000 7300 5000
Wire Wire Line
	7300 5100 6200 5100
Wire Wire Line
	6200 2500 7300 2500
Entry Wire Line
	6100 4100 6200 4200
Entry Wire Line
	6100 4400 6200 4500
Text Label 6300 2400 0    60   ~ 0
AREF
Text Label 6300 2200 0    60   ~ 0
GND
Text Label 6300 2300 0    60   ~ 0
VCC
Text Label 6300 2600 0    60   ~ 0
F0
Text Label 6300 2700 0    60   ~ 0
F1
Text Label 6300 2800 0    60   ~ 0
F4
Text Label 6300 2900 0    60   ~ 0
F5
Text Label 6300 3000 0    60   ~ 0
F6
Text Label 6300 3100 0    60   ~ 0
F7
$Comp
L CONN_5 P4
U 1 1 54591799
P 7700 3400
F 0 "P4" V 7650 3400 50  0000 C CNN
F 1 "CONN_5" V 7750 3400 50  0000 C CNN
F 2 "" H 7700 3400 60  0000 C CNN
F 3 "" H 7700 3400 60  0000 C CNN
	1    7700 3400
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 P3
U 1 1 545917A6
P 7700 2900
F 0 "P3" V 7650 2900 50  0000 C CNN
F 1 "CONN_5" V 7750 2900 50  0000 C CNN
F 2 "" H 7700 2900 60  0000 C CNN
F 3 "" H 7700 2900 60  0000 C CNN
	1    7700 2900
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 P2
U 1 1 545917AC
P 7700 2400
F 0 "P2" V 7650 2400 50  0000 C CNN
F 1 "CONN_5" V 7750 2400 50  0000 C CNN
F 2 "" H 7700 2400 60  0000 C CNN
F 3 "" H 7700 2400 60  0000 C CNN
	1    7700 2400
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 P7
U 1 1 545917B2
P 7700 4900
F 0 "P7" V 7650 4900 50  0000 C CNN
F 1 "CONN_5" V 7750 4900 50  0000 C CNN
F 2 "" H 7700 4900 60  0000 C CNN
F 3 "" H 7700 4900 60  0000 C CNN
	1    7700 4900
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 P6
U 1 1 545917B8
P 7700 4400
F 0 "P6" V 7650 4400 50  0000 C CNN
F 1 "CONN_5" V 7750 4400 50  0000 C CNN
F 2 "" H 7700 4400 60  0000 C CNN
F 3 "" H 7700 4400 60  0000 C CNN
	1    7700 4400
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 P5
U 1 1 545917BE
P 7700 3900
F 0 "P5" V 7650 3900 50  0000 C CNN
F 1 "CONN_5" V 7750 3900 50  0000 C CNN
F 2 "" H 7700 3900 60  0000 C CNN
F 3 "" H 7700 3900 60  0000 C CNN
	1    7700 3900
	1    0    0    -1  
$EndComp
Text Label 6300 3200 0    60   ~ 0
E2
Text Label 6300 3300 0    60   ~ 0
C7
Text Label 6300 3400 0    60   ~ 0
C6
Text Label 6300 3500 0    60   ~ 0
B6
Text Label 6300 3600 0    60   ~ 0
B5
Text Label 6300 3700 0    60   ~ 0
B4
Text Label 6300 3800 0    60   ~ 0
D7
Text Label 6300 3900 0    60   ~ 0
D6
Text Label 6300 4100 0    60   ~ 0
D4
Text Label 6300 4000 0    60   ~ 0
D5
Text Label 6300 4200 0    60   ~ 0
D3
Text Label 6300 4300 0    60   ~ 0
D2
Text Label 6300 4400 0    60   ~ 0
D1
Text Label 6300 4500 0    60   ~ 0
D0
Text Label 6300 4600 0    60   ~ 0
RESET
Text Label 6300 4700 0    60   ~ 0
B7
Text Label 6300 4800 0    60   ~ 0
B3
Text Label 6300 4900 0    60   ~ 0
B2
Text Label 6300 5000 0    60   ~ 0
B1
Text Label 6300 5100 0    60   ~ 0
B0
Text Label 6300 2500 0    60   ~ 0
E6
Text Label 2300 1250 2    60   ~ 0
GND
Connection ~ 4150 1650
Text Label 3550 1650 0    60   ~ 0
VCC
Text Label 2750 4500 1    60   ~ 0
AREF
Text Label 2750 1700 2    60   ~ 0
RESET
$Comp
L GND #PWR011
U 1 1 545953BD
P 4550 1300
F 0 "#PWR011" H 4550 1300 30  0001 C CNN
F 1 "GND" H 4550 1230 30  0001 C CNN
F 2 "" H 4550 1300 60  0000 C CNN
F 3 "" H 4550 1300 60  0000 C CNN
	1    4550 1300
	0    -1   -1   0   
$EndComp
$Comp
L ISP P1
U 1 1 545A64CA
P 5650 1100
F 0 "P1" H 5650 850 60  0000 C CNN
F 1 "ISP" H 5650 1350 60  0000 C CNN
F 2 "~" H 5650 1100 60  0000 C CNN
F 3 "~" H 5650 1100 60  0000 C CNN
	1    5650 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	5500 1550 5500 1450
Wire Wire Line
	5600 1450 5600 2100
Connection ~ 5600 2100
Wire Wire Line
	5700 1450 5700 2300
Connection ~ 5700 2300
Wire Wire Line
	5800 1450 5800 2200
Connection ~ 5800 2200
$Comp
L GND #PWR012
U 1 1 545A6733
P 5500 650
F 0 "#PWR012" H 5500 650 30  0001 C CNN
F 1 "GND" H 5500 580 30  0001 C CNN
F 2 "" H 5500 650 60  0000 C CNN
F 3 "" H 5500 650 60  0000 C CNN
	1    5500 650 
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR013
U 1 1 545A6740
P 5800 650
F 0 "#PWR013" H 5800 740 20  0001 C CNN
F 1 "+5V" H 5800 740 30  0000 C CNN
F 2 "" H 5800 650 60  0000 C CNN
F 3 "" H 5800 650 60  0000 C CNN
	1    5800 650 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 650  5800 750 
Wire Wire Line
	5500 650  5500 750 
Entry Wire Line
	6000 5350 6100 5450
Entry Wire Line
	6000 5500 6100 5600
Entry Wire Line
	6000 5650 6100 5750
$Comp
L R R5
U 1 1 545BBA0D
P 5500 5500
F 0 "R5" V 5580 5500 40  0000 C CNN
F 1 "1k" V 5507 5501 40  0000 C CNN
F 2 "~" V 5430 5500 30  0000 C CNN
F 3 "~" H 5500 5500 30  0000 C CNN
	1    5500 5500
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 545BBA13
P 5500 5650
F 0 "R6" V 5580 5650 40  0000 C CNN
F 1 "1k" V 5507 5651 40  0000 C CNN
F 2 "~" V 5430 5650 30  0000 C CNN
F 3 "~" H 5500 5650 30  0000 C CNN
	1    5500 5650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5100 5350 5250 5350
Wire Wire Line
	5100 5500 5250 5500
Wire Wire Line
	5100 5650 5250 5650
Wire Wire Line
	5750 5350 6000 5350
Wire Wire Line
	6000 5500 5750 5500
Wire Wire Line
	5750 5650 6000 5650
Text Label 5800 5500 0    60   ~ 0
B5
Text Label 5800 5650 0    60   ~ 0
B6
$Comp
L +5V #PWR014
U 1 1 545BBE18
P 4450 5500
F 0 "#PWR014" H 4450 5590 20  0001 C CNN
F 1 "+5V" H 4450 5590 30  0000 C CNN
F 2 "" H 4450 5500 60  0000 C CNN
F 3 "" H 4450 5500 60  0000 C CNN
	1    4450 5500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4450 5500 4550 5500
Text Label 1950 2900 0    60   ~ 0
D+
Text Label 1950 3050 0    60   ~ 0
D-
Wire Wire Line
	2500 2300 2500 2200
Wire Wire Line
	2500 2200 2800 2200
Wire Wire Line
	2800 2200 2800 2400
Wire Wire Line
	2800 2400 2850 2400
Wire Wire Line
	2850 2600 2800 2600
Wire Wire Line
	2800 2600 2800 2800
Wire Wire Line
	2800 2800 2500 2800
Wire Wire Line
	2500 2800 2500 2700
$Comp
L GND #PWR015
U 1 1 5463E179
P 2650 2700
F 0 "#PWR015" H 2650 2700 30  0001 C CNN
F 1 "GND" H 2650 2630 30  0001 C CNN
F 2 "" H 2650 2700 60  0000 C CNN
F 3 "" H 2650 2700 60  0000 C CNN
	1    2650 2700
	1    0    0    -1  
$EndComp
$Comp
L RGB_LED_COMMON_ANODE_ALT1 D1
U 1 1 5463FD4C
P 4850 5500
F 0 "D1" H 4600 5400 50  0000 C CNN
F 1 "RGB_LED_COMMON_ANODE_ALT1" H 4900 5800 50  0000 C CNN
F 2 "~" H 4900 5500 60  0000 C CNN
F 3 "~" H 4900 5500 60  0000 C CNN
	1    4850 5500
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL_SMD_4PIN X1
U 1 1 5480875F
P 2500 2500
F 0 "X1" H 2650 2400 30  0000 C CNN
F 1 "CRYSTAL_SMD_4PIN" H 2350 2300 30  0000 L CNN
F 2 "~" H 2500 2500 60  0000 C CNN
F 3 "~" H 2500 2500 60  0000 C CNN
	1    2500 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2600 2550 2650 2550
Wire Wire Line
	2650 2450 2650 2700
Wire Wire Line
	2600 2450 2650 2450
Connection ~ 2650 2550
$Comp
L CSMALL C1
U 1 1 54808894
P 2300 2250
F 0 "C1" H 2325 2300 30  0000 L CNN
F 1 "8pF" H 2325 2200 30  0000 L CNN
F 2 "~" H 2300 2250 60  0000 C CNN
F 3 "~" H 2300 2250 60  0000 C CNN
	1    2300 2250
	0    -1   -1   0   
$EndComp
$Comp
L CSMALL C2
U 1 1 548088A6
P 2300 2750
F 0 "C2" H 2325 2800 30  0000 L CNN
F 1 "8pF" H 2325 2700 30  0000 L CNN
F 2 "~" H 2300 2750 60  0000 C CNN
F 3 "~" H 2300 2750 60  0000 C CNN
	1    2300 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2200 2750 2150 2750
Wire Wire Line
	2150 2750 2150 2250
Wire Wire Line
	2150 2250 2200 2250
Wire Wire Line
	2400 2250 2500 2250
Connection ~ 2500 2250
Wire Wire Line
	2400 2750 2500 2750
Connection ~ 2500 2750
$Comp
L GND #PWR016
U 1 1 54808B09
P 2250 2500
F 0 "#PWR016" H 2250 2500 30  0001 C CNN
F 1 "GND" H 2250 2430 30  0001 C CNN
F 2 "" H 2250 2500 60  0000 C CNN
F 3 "" H 2250 2500 60  0000 C CNN
	1    2250 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2150 2500 2250 2500
Connection ~ 2150 2500
Text Label 5150 5350 0    60   ~ 0
LR
Text Label 5150 5500 0    60   ~ 0
LB
Text Label 5150 5650 0    60   ~ 0
LG
Wire Wire Line
	5500 1550 5050 1550
Wire Wire Line
	5050 1550 5050 900 
Wire Wire Line
	5050 900  2900 900 
Wire Wire Line
	2900 900  2900 1550
Wire Wire Line
	2900 1550 2650 1550
$Comp
L CSMALL C6
U 1 1 54AC0BAA
P 3800 1400
F 0 "C6" H 3825 1450 30  0000 L CNN
F 1 "0.1uF" H 3825 1350 30  0000 L CNN
F 2 "~" H 3800 1400 60  0000 C CNN
F 3 "~" H 3800 1400 60  0000 C CNN
	1    3800 1400
	1    0    0    -1  
$EndComp
$Comp
L CSMALL C5
U 1 1 54AC0BBC
P 3550 1400
F 0 "C5" H 3575 1450 30  0000 L CNN
F 1 "0.1uF" H 3575 1350 30  0000 L CNN
F 2 "~" H 3550 1400 60  0000 C CNN
F 3 "~" H 3550 1400 60  0000 C CNN
	1    3550 1400
	1    0    0    -1  
$EndComp
$Comp
L CSMALL C7
U 1 1 54AC0BC2
P 3900 1400
F 0 "C7" H 3925 1450 30  0000 L CNN
F 1 "0.1uF" H 3925 1350 30  0000 L CNN
F 2 "~" H 3900 1400 60  0000 C CNN
F 3 "~" H 3900 1400 60  0000 C CNN
	1    3900 1400
	1    0    0    -1  
$EndComp
$Comp
L CSMALL C8
U 1 1 54AC0BC8
P 4150 1400
F 0 "C8" H 4175 1450 30  0000 L CNN
F 1 "0.1uF" H 4175 1350 30  0000 L CNN
F 2 "~" H 4150 1400 60  0000 C CNN
F 3 "~" H 4150 1400 60  0000 C CNN
	1    4150 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 1650 4550 1650
Wire Wire Line
	3550 1300 4550 1300
Connection ~ 4150 1300
Connection ~ 3900 1300
Connection ~ 3800 1300
$Comp
L CSMALL C9
U 1 1 54AC31D5
P 4250 1400
F 0 "C9" H 4275 1450 30  0000 L CNN
F 1 "0.1uF" H 4275 1350 30  0000 L CNN
F 2 "~" H 4250 1400 60  0000 C CNN
F 3 "~" H 4250 1400 60  0000 C CNN
	1    4250 1400
	1    0    0    -1  
$EndComp
Connection ~ 4250 1300
Connection ~ 3550 1650
$Comp
L TVS_BIDIRECTIONAL_2CH D2
U 1 1 54B02A64
P 6450 1450
F 0 "D2" H 6450 1175 60  0000 C CNN
F 1 "TVS" H 6450 1725 60  0000 C CNN
F 2 "SOT23" H 6100 1650 60  0000 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/PESD5V0X1BQ_PESD5V0X1BT.pdf" H 6475 1450 60  0001 C CNN
F 4 "568-4676-1-ND" H 6450 1450 60  0001 C CNN "Digikey Part#"
F 5 "Look for ~5.5v breakdown voltage.  Low capacitance is a good idea.  Bi-directional nice but not required." H 6450 1450 60  0001 C CNN "Notes"
	1    6450 1450
	0    1    -1   0   
$EndComp
$Comp
L GND #PWR017
U 1 1 54B02A71
P 6450 1300
F 0 "#PWR017" H 6450 1300 30  0001 C CNN
F 1 "GND" H 6450 1230 30  0001 C CNN
F 2 "" H 6450 1300 60  0000 C CNN
F 3 "" H 6450 1300 60  0000 C CNN
	1    6450 1300
	-1   0    0    1   
$EndComp
Text Label 5450 3300 0    60   ~ 0
SDA
Text Label 5450 3200 0    60   ~ 0
SCL
Text Label 6500 1650 3    60   ~ 0
SCL
Text Label 6400 1650 3    60   ~ 0
SDA
$Comp
L RSMALL R8
U 1 1 5512D421
P 2200 3450
F 0 "R8" V 2290 3445 40  0000 C CNN
F 1 "0" V 2115 3450 40  0000 C CNN
F 2 "~" V 2130 3450 30  0000 C CNN
F 3 "~" H 2200 3500 30  0000 C CNN
	1    2200 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3350 2200 3200
Connection ~ 2200 3200
$Comp
L +5V #PWR018
U 1 1 5512D4D1
P 2200 3550
F 0 "#PWR018" H 2200 3640 20  0001 C CNN
F 1 "+5V" H 2200 3640 30  0000 C CNN
F 2 "" H 2200 3550 60  0000 C CNN
F 3 "" H 2200 3550 60  0000 C CNN
	1    2200 3550
	-1   0    0    1   
$EndComp
$Comp
L PINS_4 K1
U 1 1 5512D5AC
P 1200 3850
F 0 "K1" H 1200 3600 60  0000 C CNN
F 1 "PINS_4" H 1200 4100 60  0000 C CNN
F 2 "~" H 1200 4000 60  0000 C CNN
F 3 "~" H 1200 4000 60  0000 C CNN
	1    1200 3850
	1    0    0    -1  
$EndComp
Text Label 1500 3800 0    60   ~ 0
D+
Text Label 1500 3900 0    60   ~ 0
D-
$Comp
L GND #PWR019
U 1 1 5512D5BD
P 1500 3700
F 0 "#PWR019" H 1500 3700 30  0001 C CNN
F 1 "GND" H 1500 3630 30  0001 C CNN
F 2 "" H 1500 3700 60  0000 C CNN
F 3 "" H 1500 3700 60  0000 C CNN
	1    1500 3700
	0    -1   -1   0   
$EndComp
Text Label 1500 4000 0    60   ~ 0
VBUS
Text Label 2200 3200 0    60   ~ 0
VBUS
$Comp
L MOUNTING_HOLE MP1
U 1 1 5512D645
P 6750 850
F 0 "MP1" H 6750 750 20  0000 C CNN
F 1 "MOUNTING_HOLE" H 6750 950 20  0000 C CNN
F 2 "~" H 6750 850 60  0000 C CNN
F 3 "~" H 6750 850 60  0000 C CNN
	1    6750 850 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 5512D654
P 6650 850
F 0 "#PWR020" H 6650 850 30  0001 C CNN
F 1 "GND" H 6650 780 30  0001 C CNN
F 2 "" H 6650 850 60  0000 C CNN
F 3 "" H 6650 850 60  0000 C CNN
	1    6650 850 
	0    1    1    0   
$EndComp
$Comp
L CSMALL C4
U 1 1 551D8DF9
P 2750 3800
F 0 "C4" H 2775 3850 30  0000 L CNN
F 1 "1uF" H 2775 3750 30  0000 L CNN
F 2 "~" H 2750 3800 60  0000 C CNN
F 3 "~" H 2750 3800 60  0000 C CNN
	1    2750 3800
	1    0    0    -1  
$EndComp
$Comp
L CSMALL C3
U 1 1 551D8E13
P 2750 4600
F 0 "C3" H 2775 4650 30  0000 L CNN
F 1 "0.1uF" H 2775 4550 30  0000 L CNN
F 2 "~" H 2750 4600 60  0000 C CNN
F 3 "~" H 2750 4600 60  0000 C CNN
	1    2750 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4700 2750 4800
Wire Wire Line
	2750 4400 2750 4500
Text Label 2750 3700 1    60   ~ 0
UCAP
$EndSCHEMATC
