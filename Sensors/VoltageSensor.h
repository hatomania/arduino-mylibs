/*=============================================================================
* Analog Voltage Sensor class header
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

#ifndef VOLTAGESENSOR_7DFA7028_B9C5_49D5_BC60_4AEE047616A9_H_
#define VOLTAGESENSOR_7DFA7028_B9C5_49D5_BC60_4AEE047616A9_H_

#include "Sensor.h"

class VoltageSensor : public Sensor {
public:
  VoltageSensor() = delete;
  // https://www.amazon.co.jp/gp/product/B0171FA59C
  explicit VoltageSensor(uint8_t _pin, float _cal = (5.f / 1024.f) * 5.f);
  float get() const;
private:
  float cal_;
};

#endif /* VOLTAGESENSOR_7DFA7028_B9C5_49D5_BC60_4AEE047616A9_H_ */
