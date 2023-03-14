/* Copyright 2021 Carlos Martins
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sofle.h"

#ifdef RGB_MATRIX_ENABLE
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  //                                            0
  //
  //                                            1
  //
  //                                            2
  //
  //                                            3
  //
  //                                            4

led_config_t g_led_config = {
    {
        {28, 21, 20, 11, 10,  0},
        {27, 22, 19, 12,  9,  1},
        {26, 23, 18, 13,  8,  2},
        {25, 24, 17, 14,  7,  3},
        {16, 15,  6,  5,  4,  NO_LED },
        {57, 50, 49, 40, 39, 29},
        {56, 51, 48, 41, 38, 30},
        {55, 52, 47, 42, 37, 31},
        {54, 53, 46, 43, 36, 32},
        {45, 44, 35, 34, 33, NO_LED}
    },
    {
        // Left side Matrix
        { 90,  4}, { 90, 19}, { 90, 34}, { 90, 49}, {108, 64},
        { 90, 64}, { 72, 64}, { 72, 47}, { 72, 32}, { 72, 17},
        { 72,  2}, { 54,  0}, { 54, 15}, { 54, 30}, { 54, 45},
        { 54, 64}, { 36, 64}, { 36, 47}, { 36, 32}, { 36, 32},
        { 36,  2}, { 18,  4}, { 18, 19}, { 18, 34}, { 18, 49},
        {  0, 49}, {  0, 34}, {  0, 19}, {  0, 4},

        // Right side Matrix
        {148,  4}, {148, 19}, {148, 34}, {148, 49}, {132, 64},
        {148, 64}, {164, 64}, {164, 47}, {164, 32}, {164, 17},
        {164,  2}, {180,  0}, {180, 15}, {180, 30}, {180, 45},
        {180, 64}, {196, 64}, {196, 47}, {196, 32}, {196, 32},
        {196,  2}, {212,  4}, {212, 19}, {212, 34}, {212, 49},
        {224, 49}, {224, 34}, {224, 19}, {224, 4},
    },
    {
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};
#endif
