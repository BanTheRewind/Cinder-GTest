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

#include "AppTest.h"

void AppTest::SetUp()
{
	mApp = new CinderGTestApp();
}

void AppTest::TearDown()
{
	delete mApp;
}

TEST_F( AppTest, SetupTest ) 
{
	// The following tests should all fail
	EXPECT_EQ( mApp->getCounter(), 0 ) << "Not initialized (should cause access violation error)\n";
	EXPECT_ANY_THROW( mApp->setup() ) << "This should be reported because there is no exception thrown\n";
	EXPECT_GT( mApp->getCounter(), 0 ) << "This should be 0\n";
}

TEST_F( AppTest, UpdateTest ) 
{
	EXPECT_NO_THROW( mApp->update() );
}

TEST_F( AppTest, NumbersTest ) 
{
	mApp->getNumbers().push_back( 1 );
	EXPECT_GT( mApp->getNumbers().size(), 1 ) << "Not enough numbers!\n";
}

TEST( GlobalTestSuite, GlobalTest ) 
{
	CinderGTestApp* app = new CinderGTestApp();
	app->setup();
	for ( size_t i = 0; i < 4; ++i ) {
		app->update();
	}
	EXPECT_EQ( app->getNumbers().size(), 5 ) << "Did not add five numbers\n";
	EXPECT_EQ( app->getNumbers().size(), 4 );
}
