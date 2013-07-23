/*
* 
* Copyright (c) 2012, Ban the Rewind
* All rights reserved.
*
* Mac version by Caleb Johnston
*
* Redistribution and use in source and binary forms, with or 
* without modification, are permitted provided that the following 
* conditions are met:
* 
* Redistributions of source code must retain the above copyright 
* notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright 
* notice, this list of conditions and the following disclaimer in 
* the documentation and/or other materials provided with the 
* distribution.
* 
* Neither the name of the Ban the Rewind nor the names of its 
* contributors may be used to endorse or promote products 
* derived from this software without specific prior written 
* permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
* COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
*/

#pragma once

#include "CinderGTest.h"

/* 
* This application demonstrates how to implement Google C++ Testing
* in Cinder. The application itself does essentially nothing, while
* the "AppTest" class performs some tests and experiments on it. 
* Pay attenetion to the macro used to initialize the application 
* in the CPP file.
* 
* Errors will be reported to your debug console complete with
* file, line number, error description, and your custom message, if any.
* 
* Check out the wiki to get the most out of Google Test:
* http://code.google.com/p/googletest/w/list
*/
class CinderGTestApp : public ci::app::AppNative
{
public:
	void						draw();
	void						setup();
	void						update();

	int32_t						getCounter();
	std::vector<uint32_t>&		getNumbers();
private:
	int32_t						mCounter;
	std::vector<uint32_t>		mNumbers;
};
