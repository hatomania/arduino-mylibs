/*=============================================================================
* Button class header
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

#ifndef BUTTON_D7DEAB1A_5894_CEFB_DC34_92920B5352A3_H_
#define BUTTON_D7DEAB1A_5894_CEFB_DC34_92920B5352A3_H_

class ButtonAction {
  friend class Button;
public:
  ButtonAction() = delete;
  explicit ButtonAction(uint8_t _pin);
  virtual void pressing(bool _is_triggered) const;
  virtual void released() const;

protected:
  static const uint8_t kINVALID_PIN = 0xFF;

private:
  uint8_t pin_;
  uint8_t last_pin_stat_;
  uint16_t pressing_cnt_;
};

class ButtonActionFooter : public ButtonAction {
public:
  explicit ButtonActionFooter()
    : ButtonAction(ButtonAction::kINVALID_PIN) {}
};

class Button {
public:
  Button() = delete;
  explicit Button(ButtonAction** const _ba, uint16_t _interval = 20);
  void action() const;
private:
  ButtonAction** const ba_;
  const uint16_t interval_;
};

#endif /* BUTTON_D7DEAB1A_5894_CEFB_DC34_92920B5352A3_H_ */
