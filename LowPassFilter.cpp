/*
  LowPassFilter.cpp - Exponential Decay Filter for the Arduino platform.
  Copyright (c) 2013 Phillip Schmidt.  All right reserved.
 
 
	!!! All data must be type INT.  !!!
	
	Note: This library is intended to run under the Arduino dev platform
	
	Usage:
	#include <LowPassFilter.h>  // library must be in ..\Arduino\libraries\LowPassFilter
	
	LowPassFilter filter1(2, 100);  // create filter object with a filter strength of 2
					// and seeded to start at 100 (seed only needs to be a rough guess)
	
	filteredData = filter1.in(rawData);// new data is passed to the object and
					// the oject return the current filtered value
					
	filteredData = filter1.out();	// use the 'out()' function to get the latest result
					// without submitting new data.
					
	TIPS:
	-create a filter oject for each uniquie data stream
	-The filter strength must be an integer
	-The filter is more effective, but introduces more delay with higher filter strength values
		(the "smootheness" and delay double for each increase of filter strength)
	-A filter strength of '0' will have no effect (filteredData = rawData)
	-Avoid using a larger filter strength than needed as incoming data precision may suffer
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
