/*
 * Hydrogen
 * Copyright(c) 2002-2008 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 * Copyright(c) 2008-2024 The hydrogen development team [hydrogen-devel@lists.sourceforge.net]
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


#ifndef PATCH_BAY_H
#define PATCH_BAY_H


#include <map>
#include <memory>

#include <QtGui>
#include <QtWidgets>

#include <core/Object.h>
#include <core/Basics/Drumkit.h>
#include <core/Basics/PatternList.h>

#include "LCDCombo.h"
#include "LCDDisplay.h"
#include "../Types/Patch.h"

/** Custom widget to map instruments and components onto eachother when
 * switching drumkits.
 *
 * \ingroup docGUI docWidgets*/
class PatchBay : public QDialog, public H2Core::Object<PatchBay>
{
	H2_OBJECT(PatchBay)
	Q_OBJECT

public:

	PatchBay( QWidget* pParent,
			  H2Core::PatternList* pPatternList,
			  std::shared_ptr<H2Core::Drumkit> pDrumkit );
	~PatchBay();

		Patch getPatch() const;

private:
		std::vector<LCDDisplay*> m_patternTypesBoxes;
		std::vector<LCDCombo*> m_drumkitInstrumentBoxes;

		H2Core::PatternList* m_pPatternList;
		std::shared_ptr<H2Core::Drumkit> m_pDrumkit;
};

#endif
