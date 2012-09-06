/*
* 
* Copyright (c) 2012, Ban the Rewind
* All rights reserved.
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

#include "gtest/gtest.h"
#include "cinder/app/AppBasic.h"

#if defined( CINDER_MAC )
	#define CINDER_APP_BASIC_GTEST( APP, RENDERER )								\
	GTEST_API_ int main( int argc, char * const argv[] ) {					\
		cinder::app::AppBasic::prepareLaunch();								\
		cinder::app::AppBasic *app = new APP;								\
		cinder::app::Renderer *ren = new RENDERER;							\
		cinder::app::AppBasic::executeLaunch( app, ren, #APP, argc, argv );	\
		cinder::app::AppBasic::cleanupLaunch();								\
		testing::InitGoogleTest(&argc, (char **)argv);						\
		return RUN_ALL_TESTS();												\
	}
	#define CINDER_APP_GTEST( APP, RENDERER )							\
	GTEST_API_ int main( int argc, char * const argv[] ) {					\
		testing::InitGoogleTest(&argc, (char **)argv);						\
		return RUN_ALL_TESTS();												\
	}
#elif defined( CINDER_MSW )
	#include "Shellapi.h"
	#define CINDER_APP_BASIC_GTEST( APP, RENDERER )																	\
	GTEST_API_ int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {	\
		cinder::app::AppBasic::prepareLaunch();																	\
		cinder::app::AppBasic *app = new APP;																	\
		cinder::app::Renderer *ren = new RENDERER;																\
		cinder::app::AppBasic::executeLaunch( app, ren, #APP );													\
		cinder::app::AppBasic::cleanupLaunch();																	\
		int argc;																								\
		wchar_t** argv = CommandLineToArgvW( GetCommandLineW(), &argc );										\
		testing::InitGoogleTest( &argc, argv );																	\
		return RUN_ALL_TESTS();																					\
	}
	#define CINDER_APP_GTEST( APP, RENDERER )																\
	GTEST_API_ int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {	\
		int argc;																								\
		wchar_t** argv = CommandLineToArgvW( GetCommandLineW(), &argc );										\
		testing::InitGoogleTest( &argc, argv );																	\
		return RUN_ALL_TESTS();																					\
	}
#endif