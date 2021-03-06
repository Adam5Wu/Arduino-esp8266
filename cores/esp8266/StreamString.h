/**
 StreamString.h

 Copyright (c) 2015 Markus Sattler. All rights reserved.
 This file is part of the esp8266 core for Arduino environment.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#ifndef STREAMSTRING_H_
#define STREAMSTRING_H_

#include <WString.h>
#include <Stream.h>
#include <Print.h>

#include <utility>

class PrintString: public String, public Print {
  public:
    PrintString(void) {}
    PrintString(const __FlashStringHelper *str) : String(str) {}
#ifdef __GXX_EXPERIMENTAL_CXX0X__
    PrintString(String &&rval) : String(std::move(rval)) {}
#endif

    size_t write(const uint8_t *buffer, size_t size) override;
    size_t write(uint8_t data) override;
};

class StreamString: public Stream, public String {
  protected:
    size_t _offset = 0;
  public:
    StreamString(void) {}
    StreamString(const __FlashStringHelper *str) : String(str) {}
#ifdef __GXX_EXPERIMENTAL_CXX0X__
    StreamString(String &&rval) : String(std::move(rval)) {}
#endif

    size_t write(const uint8_t *buffer, size_t size) override;
    size_t write(uint8_t data) override;

    size_t readBytes(char *buffer, size_t length) override;

    int available() override;
    int read() override;
    int peek() override;
    void flush() override;

    void reset() { _offset = 0; }
};


#endif /* STREAMSTRING_H_ */
