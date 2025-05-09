#ifndef KEYBOARD_KEY_MAPPING_H
#define KEYBOARD_KEY_MAPPING_H

#include <touchgfx/widgets/Keyboard.hpp>
using namespace touchgfx;

/**
 * This file contains all the keymappings for the CustomKeyboard.
 */
static const Keyboard::KeyMapping keyMappingsAlphaLower[39] = { { 1, 49 },  // 1
		{ 2, 50 },  	// 2
		{ 3, 51 },  	// 3
		{ 4, 52 },  	// 4
		{ 5, 53 },  	// 5
		{ 6, 54 },  	// 6
		{ 7, 55 },  	// 7
		{ 8, 56 },  	// 8
		{ 9, 57 },  	// 9
		{ 10, 48 },  	// 0
		{ 11, 113 },   	// q
		{ 12, 119 },  	// w
		{ 13, 101 },  	// e
		{ 14, 114 },  	// r
		{ 15, 116 },  	// t
		{ 16, 121 },  	// y
		{ 17, 117 },  	// u
		{ 18, 105 },  	// i
		{ 19, 111 },  	// o
		{ 20, 112 },  	// p
		{ 21, 97 },   	// a
		{ 22, 115 },   	// s
		{ 23, 100 },  	// d
		{ 24, 102 },  	// f
		{ 25, 103 },  	// g
		{ 26, 104 },  	// h
		{ 27, 106 },  	// j
		{ 28, 107 },  	// k
		{ 29, 108 },  	// l
		{ 30, 122 },  	// z
		{ 31, 120 },	// x
		{ 32, 99 },		// c
		{ 33, 118 },	// v
		{ 34, 98 },		// b
		{ 35, 110 },	// n
		{ 36, 109 },	// m
		{ 37, 44 },		// ,
		{ 38, 46 },		// .
		{ 39, 32 },		// space
		};

static const Keyboard::KeyMappingList keyMappingListAlphaLower = {
		keyMappingsAlphaLower, 39 };

static const Keyboard::KeyMapping keyMappingsAlphaUpper[39] =
		{
		{ 1, 49 },  		// 1
		{ 2, 50 },  		// 2
		{ 3, 51 },  		// 3
		{ 4, 52 },  		// 4
		{ 5, 53 },  		// 5
		{ 6, 54 },  		// 6
		{ 7, 55 },  		// 7
		{ 8, 56 },  		// 8
		{ 9, 57 },  		// 9
		{ 10, 48 },  		// 0
		{ 11, 113 - 32 },   // Q
		{ 12, 119 - 32 },  	// W
		{ 13, 101 - 32 },  	// E
		{ 14, 114 - 32 },  	// R
		{ 15, 116 - 32 },  	// T
		{ 16, 121 - 32 },  	// Y
		{ 17, 117 - 32 },  	// U
		{ 18, 105 - 32 },  	// I
		{ 19, 111 - 32 },  	// O
		{ 20, 112 - 32 },  	// P
		{ 21, 97 - 32 },   	// Q
		{ 22, 115 - 32 },   // R
		{ 23, 100 - 32 },  	// d
		{ 24, 102 - 32 },  	// f
		{ 25, 103 - 32 },  	// g
		{ 26, 104 - 32 },  	// h
		{ 27, 106 - 32 },  	// j
		{ 28, 107 - 32 },  	// k
		{ 29, 108 - 32 },  	// l
		{ 30, 122 - 32 },  	// z
		{ 31, 120 - 32 },	// x
		{ 32, 99 - 32 },	// c
		{ 33, 118 - 32 },	// v
		{ 34, 98 - 32 },	// b
		{ 35, 110 - 32 },	// n
		{ 36, 109 - 32 },	// m
		{ 37, 44 },			// ,
		{ 38, 46 },			// .
		{ 39, 32 }			// space			// space
		};

static const Keyboard::KeyMappingList keyMappingListAlphaUpper = {
		keyMappingsAlphaUpper, 39 };

static const Keyboard::KeyMapping keyMappingsNumLower[30] =
{
    { 1,  49},  // 1
    { 2,  50},  // 2
    { 3,  51},  // 3
    { 4,  52},  // 4
    { 5,  53},  // 5
    { 6,  54},  // 6
    { 7,  55},  // 7
    { 8,  56},  // 8
    { 9,  57},  // 9
    {10,  48},  // 0
    {11,  64},  // @

    {12,  35},  // #
    {13,  36},  // $
    {14,  37},  // %
    {15,  38},  // &
    {16,  42},  // *
    {17,  45},  // -
    {18,  43},  // +
    {19,  40},  // (
    {20,  41},  // )
    {21,  33},  // !
    {22,  34},  // "

    {23,  39},  // '
    {24,  58},  // :
    {25,  59},  // ;
    {26,  47},  // /
    {27,  63},  // ?
    {28,  44},  // ,
    {29,  46},  // .

    {30,  32}   // space
};

static const Keyboard::KeyMappingList keyMappingListNumLower =
{
    keyMappingsNumLower,
    30
};

static const Keyboard::KeyMapping keyMappingsNumUpper[30] =
{
    { 1,  126},  // ~
    { 2,  177},  // +/-
    { 3,  215},  // x
    { 4,  247},  // -
    { 5,  8226}, // *
    { 6,  186},  // o
    { 7,  96},   // '
    { 8,  180},  // '
    { 9,  123},  // {
    {10,  125},  // }
    {11,  169},  // (c)

    {12, 163},   // pound
    {13,  8364}, // euro
    {14,  94},   // ^
    {15,  174},  // (R)
    {16,  165},  // yen
    {17,  95},   // _
    {18,  61},   // =
    {19,  91},   // [
    {20,  93},   // ]
    {21,  60},   // <
    {22, 62},    // >

    {23,  161},  // !
    {24,  162},  // cent
    {25,  124},  // |
    {26,  92},   // \ .
    {27,  191},  // ?
    {28,  44},   // ,
    {29,  46},   // .

    {30,  32}   // space
};

static const Keyboard::KeyMappingList keyMappingListNumUpper =
{
    keyMappingsNumUpper,
    30
};

#endif
