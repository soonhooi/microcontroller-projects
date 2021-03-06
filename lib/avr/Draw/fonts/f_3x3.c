#include "f_3x3.h"

//Use codepage_ascii for this font.

/*
 * A 3x3 pixel font.  The bits are read across from top left to top right, then down
 * to the next line.  Each character is represented by 2 8-bit unsigned integers, with 
 * the seven bits of the first byte ignored.
 */
uint8_t font_3X3[] PROGMEM = {
	0x00,0x00,	//Space
	0x01,0x92,	//!
	0x01,0x68, 	//"
	0x01,0x45,	//#
	0x00,0x00,	//$ ( )
	0x01,0x01,	//%
	0x00,0xba,	//& (+)
	0x00,0x90,	//'
	0x00,0xa6,	//( ([)
	0x00,0xcb,	//) (])
	0x00,0x00,	//* ( )
	0x00,0xba,	//+
	0x00,0x24,	//,
	0x00,0x38,	//-
	0x00,0x04,	//.
	0x00,0x54,	///, 0x0F
	0x01,0xef,	//0, 0x10
	0x01,0x97,	//1
	0x01,0x93,	//2
	0x01,0xdf,	//3
	0x01,0x79,	//4
	0x00,0xd6,	//5
	0x01,0x3f,  //6
	0x01,0xca,	//7
	0x01,0xff,	//8
	0x01,0xf9,	//9,0x19
	0x00,0x82,	//:
	0x00,0x82,	//;
	0x00,0xa2,	//<
	0x01,0xc7,	//=
	0x00,0x8a,	//>
	0x01,0xda,	//?
	0x00,0x00,	//@ ( )
	0x00,0xbd,	//A, 0x21
	0x01,0xbf,	//B, 0x22
	0x01,0xe7,	//C
	0x01,0xae,	//D
	0x01,0xf7,	//E
	0x01,0xf4,	//F
	0x01,0xaf,	//G
	0x01,0x7d,	//H
	0x01,0xd7,	//I
	0x00,0x6f,	//J
	0x01,0x75,	//K
	0x01,0x27,	//L
	0x01,0xfd,	//M
	0x01,0xed,	//N
	0x01,0xef,	//O
	0x01,0xfc,	//P
	0x01,0xf9,	//Q
	0x01,0xf5,	//R
	0x00,0xd6,	//S
	0x01,0xd2,	//T
	0x01,0x6f,	//U
	0x01,0x6a,	//V
	0x01,0x7f,	//W
	0x01,0x55,	//X
	0x01,0x7a,	//Y
	0x01,0x93,	//Z, 0x3a
	0x01,0xa6,	//[
	0x01,0x11,	//backslash
	0x01,0xcb,	//]
	0x00,0xa8,	//^
	0x00,0x07,	//_
	//If you implement lower case letters, do so here...
	0x00,0x90,	//`, 0x40
	0x00,0xf8,	//{
	0x00,0x92,	//|
	0x01,0x9e,	//}
	0x00,0xf0,	//~
};
