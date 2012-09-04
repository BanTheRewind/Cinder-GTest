#pragma once

#include "gtest/gtest.h"
#include "cinder/app/AppBasic.h"

namespace cinder { namespace app {
	typedef AppBasic AppGTest;
} }

#if defined( CINDER_MAC )
	#define CINDER_APP_GTEST( APP, RENDERER )								\
	GTEST_API_ int main( int argc, char * const argv[] ) {					\
		cinder::app::AppBasic::prepareLaunch();								\
		cinder::app::AppBasic *app = new APP;								\
		cinder::app::Renderer *ren = new RENDERER;							\
		cinder::app::AppBasic::executeLaunch( app, ren, #APP, argc, argv );	\
		cinder::app::AppBasic::cleanupLaunch();								\
		testing::InitGoogleTest(&argc, (char **)argv);						\
		return RUN_ALL_TESTS();												\
	}
#elif defined( CINDER_MSW )
	#define CINDER_APP_GTEST( APP, RENDERER )																	\
	GTEST_API_ int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {	\
		cinder::app::AppBasic::prepareLaunch();																	\
		cinder::app::AppBasic *app = new APP;																	\
		cinder::app::Renderer *ren = new RENDERER;																\
		cinder::app::AppBasic::executeLaunch( app, ren, #APP );													\
		cinder::app::AppBasic::cleanupLaunch();																	\
		testing::InitGoogleTest(&nCmdShow, (char **)lpCmdLine);													\
		return RUN_ALL_TESTS();																					\
	}
#endif
