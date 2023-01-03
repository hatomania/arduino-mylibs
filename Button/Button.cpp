/*=============================================================================
* Button class implementation
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

#include <Arduino.h>
#include "Button.h"

ButtonAction::ButtonAction(uint8_t _pin)
  : pin_(_pin), last_pin_stat_(1), pressing_cnt_(0) {
  if (_pin != ButtonAction::kINVALID_PIN) {
    pinMode(_pin, INPUT_PULLUP);
  }
}
void ButtonAction::pressing(bool _is_triggered) const {}
void ButtonAction::released() const {}

Button::Button(ButtonAction** const _ba, uint16_t _interval)
  : ba_(_ba), interval_(_interval) {}
void Button::action() const {
  for (uint8_t i = 0; ba_[i]->pin_ != ButtonAction::kINVALID_PIN; ++i) {
    ButtonAction* const ba = ba_[i];
    uint8_t now_pin_stat = digitalRead(ba->pin_);
    if (ba->last_pin_stat_ > now_pin_stat) {
      ba->pressing(true);
    } else if (now_pin_stat == LOW && ba->last_pin_stat_ == now_pin_stat) {
      ++ba->pressing_cnt_;
      if (ba->pressing_cnt_ > interval_) { ba->pressing(false); }
    }
    if (ba->last_pin_stat_ < now_pin_stat) {
      ba->pressing_cnt_ = 0;
      ba->released();
    }
    ba->last_pin_stat_ = now_pin_stat;
  }
}
