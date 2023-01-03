/*=============================================================================
* Sensor class header
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

#ifndef SENSOR_6CB155C6_A999_4276_80F3_791ACB9B8A6F_H_
#define SENSOR_6CB155C6_A999_4276_80F3_791ACB9B8A6F_H_

class Sensor {
public:
  Sensor() = delete;
  explicit Sensor(uint8_t _addr_or_pin);
  virtual float get() const = 0;
  virtual float get2() const { return 0.f; }
  virtual float get3() const { return 0.f; }
  virtual float get4() const { return 0.f; }
  virtual float get5() const { return 0.f; }
  uint16_t getRaw() { return 0xFFFF; }
protected:
  uint8_t getAddr() const { return addr_or_pin_; }
  uint8_t getPin() const { return addr_or_pin_; }
private:
  uint8_t addr_or_pin_;
};

#endif /* SENSOR_6CB155C6_A999_4276_80F3_791ACB9B8A6F_H_ */
