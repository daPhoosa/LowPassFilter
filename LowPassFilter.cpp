/*
  LowPassFilter.cpp - Median Filter for the Arduino platform.
  Copyright (c) 2012 Phillip Schmidt.  All right reserved.
 
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

/* 
 
	!!! All data must be type INT.  !!!
 
*/

#include "LowPassFilter.h"

LowPassFilter::LowPassFilter(byte shift, int startPoint)
{
	_data = startPoint;	// used to seed the filter 
	_shift = shift;		// bit shift value
}

int LowPassFilter::in(int value)
{  
	_data += (value - _data) >> _shift;
	return _data; // low pass filter result
}

int LowPassFilter::out()
{  
	return _data; // low pass filter result
}
