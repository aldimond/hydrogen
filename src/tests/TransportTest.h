/*
 * Hydrogen
 * Copyright(c) 2002-2008 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 * Copyright(c) 2008-2021 The hydrogen development team [hydrogen-devel@lists.sourceforge.net]
 *
 * http://www.hydrogen-music.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see https://www.gnu.org/licenses
 *
 */

#include <random>

#include <core/config.h>

#include <cppunit/extensions/HelperMacros.h>
#include <core/Hydrogen.h>

class TransportTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE( TransportTest );
	CPPUNIT_TEST( testFrameToTickConversion );
	CPPUNIT_TEST_SUITE_END();
	
private:
	QString m_sValidPath;
	std::default_random_engine m_randomEngine;
    std::uniform_int_distribution<int> m_randomDist;
	
public:
	void setUp();
	void tearDown();
	
	void testFrameToTickConversion();
};
