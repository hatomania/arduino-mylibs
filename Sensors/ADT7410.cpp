/*=============================================================================
* ADT7410 Temperature Sensor class implementation
*
===============================================================================
/ Copyright (C) 2023 hatomania All rights reserved.
/
/ Redistribution and use in source and binary forms, with or without 
/ modification, are permitted provided that the following conditions 
/ are met:
/
/  1. Redistributions of source code must retain the above copyright 
/     notice, this list of conditions and the following disclaimer.
/  2. Redistributions in binary form must reproduce the above copyright 
/     notice, this list of conditions and the following disclaimer in the 
/     documentation and/or other materials provided with the distribution.
/
/ THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR 
/ IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
/ OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
/ IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, 
/ INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
/ BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF 
/ USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
/ ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
/ (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF 
/ THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
/============================================================================*/

#include "ADT7410.h"
#include "Wire.h"

ADT7410::ADT7410(int _addr): Sensor(_addr) {
}

float ADT7410::get() const {
  // from https://kesoku-blog.com/?p=560
  uint16_t uiVal;  //2バイト(16ビット)の領域
  float fVal;
  int iVal;

  Wire.requestFrom(getAddr(), 2);  //2バイト要求

  uiVal = (uint8_t)Wire.read() << 8;  // 1バイト読み出しで上位にシフト
  uiVal |= Wire.read();               // 1バイト読み出して下位にセット

  uiVal >>= 3;  // シフトで13bit化

  if (uiVal & 0x1000) {     // 13ビットで符号判定
    iVal = uiVal - 0x2000;  // マイナスの時 (10進数で8192)
  } else {
    iVal = uiVal;  //プラスの時
  }

  fVal = (float)iVal / 16.0;  // 温度換算(摂氏)
  return fVal;
}
