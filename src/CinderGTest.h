#pragma once

#include "gtest/gtest.h"
#include "cinder/app/AppBasic.h"

#if defined( CINDER_MAC )
	#define CINDER_APP_GTEST( APP, RENDERER )								\
	GTEST_API_ int main( int argc, char * const argv[] ) {					\
		testing::InitGoogleTest(&argc, (char **)argv);						\
		RUN_ALL_TESTS();													\
		cinder::app::AppBasic::prepareLaunch();								\
		cinder::app::AppBasic *app = new APP;								\
		cinder::app::Renderer *ren = new RENDERER;							\
		cinder::app::AppBasic::executeLaunch( app, ren, #APP, argc, argv );	\
		cinder::app::AppBasic::cleanupLaunch();								\
		return 0;															\
	}
#elif defined( CINDER_MSW )
	#include "Shellapi.h"
	#define CINDER_APP_GTEST( APP, RENDERER )																	\
	GTEST_API_ int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {	\
		int argc;																								\
		wchar_t** argv = CommandLineToArgvW( GetCommandLineW(), &argc );										\
		testing::InitGoogleTest( &argc, argv );																	\
		RUN_ALL_TESTS();																						\
		cinder::app::AppBasic::prepareLaunch();																	\
		cinder::app::AppBasic *app = new APP;																	\
		cinder::app::Renderer *ren = new RENDERER;																\
		cinder::app::AppBasic::executeLaunch( app, ren, #APP );													\
		cinder::app::AppBasic::cleanupLaunch();																	\
		return 0;																								\
	}
#endif
