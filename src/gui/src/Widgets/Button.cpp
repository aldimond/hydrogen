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

#include "Button.h"

#include "../Skin.h"
#include "../HydrogenApp.h"
#include "../CommonStrings.h"
#include "MidiSenseWidget.h"

#include <qglobal.h>	// for QT_VERSION

#include <core/Globals.h>
#include <core/Preferences.h>
#include <core/Hydrogen.h>

const char* Button::__class_name = "Button";

Button::Button( QWidget *pParent, QSize size, Type type, const QString& sIcon, const QString& sText, bool bUseRedBackground, QSize iconSize, QString sBaseTooltip, bool bColorful )
	: QPushButton( pParent )
	, Object( __class_name )
	, m_size( size )
	, m_iconSize( iconSize )
	, m_sBaseTooltip( sBaseTooltip )
	, m_sRegisteredMidiEvent( "" )
	, m_nRegisteredMidiParameter( 0 )
	, m_bColorful( bColorful )
	, m_bLastCheckedState( false )
	, m_sIcon( sIcon )
	, m_bUseRedBackground( bUseRedBackground )
{
	auto pPref = H2Core::Preferences::get_instance();
	
	m_lastUsedFontSize = pPref->getFontSize();
	m_sLastUsedFontFamily = pPref->getLevel3FontFamily();
	m_lastWidgetTextColor = pPref->getDefaultUIStyle()->m_widgetTextColor;
	m_lastWidgetColor = pPref->getDefaultUIStyle()->m_widgetColor;
	m_lastAccentColor = pPref->getDefaultUIStyle()->m_accentColor;
	m_lastAccentTextColor = pPref->getDefaultUIStyle()->m_accentTextColor;
	m_lastButtonRedColor = pPref->getDefaultUIStyle()->m_buttonRedColor;
	m_lastButtonRedTextColor = pPref->getDefaultUIStyle()->m_buttonRedTextColor;
		
	setAttribute( Qt::WA_OpaquePaintEvent );
	setFocusPolicy( Qt::NoFocus );
	
	adjustSize();
	setFixedSize( size );
	resize( size );

	if ( ! sIcon.isEmpty() ) {
		if ( bColorful ) {
			setIcon( QIcon( Skin::getSvgImagePath() + "/icons/" + sIcon ) );
		} else {
			// Unchecked version
			setIcon( QIcon( Skin::getSvgImagePath() + "/icons/black/" + sIcon ) );
		}
		setIconSize( iconSize );
	} else {
		setText( sText );
	}

	if ( size.width() <= 12 || size.height() <= 12 ) {
		m_sBorderRadius = "0";
	} else if ( size.width() <= 20 || size.height() <= 20 ) {
		m_sBorderRadius = "3";
	} else {
		m_sBorderRadius = "5";
	}
	
	if ( type == Type::Toggle ) {
		setCheckable( true );
	} else {
		setCheckable( false );
	}

	updateFont();
	updateStyleSheet();
	updateTooltip();
	
	connect( HydrogenApp::get_instance(), &HydrogenApp::preferencesChanged, this, &Button::onPreferencesChanged );
}

Button::~Button() {
}

void Button::updateStyleSheet() {

	int nFactorGradient = 120;
	int nHover = 10;
	
	QColor backgroundLight = m_lastWidgetColor.lighter( nFactorGradient );
	QColor backgroundDark = m_lastWidgetColor.darker( nFactorGradient );
	QColor backgroundLightHover = m_lastWidgetColor.lighter( nFactorGradient + nHover );
	QColor backgroundDarkHover = m_lastWidgetColor.darker( nFactorGradient + nHover );

	QColor backgroundCheckedLight, backgroundCheckedDark, backgroundCheckedLightHover,
		backgroundCheckedDarkHover, textChecked;
	if ( ! m_bUseRedBackground ) {
		backgroundCheckedLight = m_lastAccentColor.lighter( nFactorGradient );
		backgroundCheckedDark = m_lastAccentColor.darker( nFactorGradient );
		backgroundCheckedLightHover = m_lastAccentColor.lighter( nFactorGradient + nHover );
		backgroundCheckedDarkHover = m_lastAccentColor.darker( nFactorGradient + nHover );
		textChecked = m_lastAccentTextColor;
	} else {
		backgroundCheckedLight = m_lastButtonRedColor.lighter( nFactorGradient );
		backgroundCheckedDark = m_lastButtonRedColor.darker( nFactorGradient );
		backgroundCheckedLightHover = m_lastButtonRedColor.lighter( nFactorGradient + nHover );
		backgroundCheckedDarkHover = m_lastButtonRedColor.darker( nFactorGradient + nHover );
		textChecked = m_lastButtonRedTextColor;
	}
	
	setStyleSheet( QString( "QPushButton { \
    color: %1; \
    border: 1px solid %1; \
    border-radius: %2px; \
    padding: 0px; \
    background-color: qlineargradient(x1: 0.1, y1: 0.1, x2: 1, y2: 1, \
                                      stop: 0 %3, stop: 1 %4); \
} \
QPushButton:hover { \
    background-color: qlineargradient(x1: 0.1, y1: 0.1, x2: 1, y2: 1, \
                                      stop: 0 %5, stop: 1 %6); \
} \
QPushButton:checked { \
    color: %7; \
    border: 1px solid %1; \
    border-radius: %2px; \
    padding: 0px; \
    background-color: qlineargradient(x1: 0.1, y1: 0.1, x2: 1, y2: 1, \
                                      stop: 0 %8, stop: 1 %9); \
} \
QPushButton:checked:hover { \
    background-color: qlineargradient(x1: 0.1, y1: 0.1, x2: 1, y2: 1, \
                                      stop: 0 %10, stop: 1 %11); \
}"
							)
				   .arg( m_lastWidgetTextColor.name() )
				   .arg( m_sBorderRadius )
				   .arg( backgroundLight.name() ).arg( backgroundDark.name() )
				   .arg( backgroundLightHover.name() ).arg( backgroundDarkHover.name() )
				   .arg( textChecked.name() )
				   .arg( backgroundCheckedLight.name() ).arg( backgroundCheckedDark.name() )
				   .arg( backgroundCheckedLightHover.name() ).arg( backgroundCheckedDarkHover.name() ) );
}

void Button::setBaseToolTip( const QString& sNewTip ) {
	m_sBaseTooltip = sNewTip;
	updateTooltip();
}

void Button::setAction( Action *pAction ) {
	m_action = pAction;
	updateTooltip();
}

void Button::mousePressEvent(QMouseEvent*ev) {
	
	/*
	*  Shift + Left-Click activate the midi learn widget
	*/
	
	if ( ev->button() == Qt::LeftButton && ( ev->modifiers() & Qt::ShiftModifier ) ){
		MidiSenseWidget midiSense( this, true, this->getAction() );
		midiSense.exec();

		// Store the registered MIDI event and parameter in order to
		// show them in the tooltip. Looking them up in the MidiMap
		// using the Action associated to the Widget might not yield a
		// unique result since the Action can be registered from the
		// PreferencesDialog as well.
		m_sRegisteredMidiEvent = H2Core::Hydrogen::get_instance()->lastMidiEvent;
		m_nRegisteredMidiParameter = H2Core::Hydrogen::get_instance()->lastMidiEventParameter;
		
		updateTooltip();
		return;
	}

	QPushButton::mousePressEvent( ev );
}

void Button::updateTooltip() {

	auto pCommonStrings = HydrogenApp::get_instance()->getCommonStrings();

	QString sTip = QString("%1" ).arg( m_sBaseTooltip );

	// Add the associated MIDI action.
	if ( m_action != nullptr ) {
		sTip.append( QString( "\n%1: %2 " ).arg( pCommonStrings->getMidiTooltipHeading() )
					 .arg( m_action->getType() ) );
		if ( ! m_sRegisteredMidiEvent.isEmpty() ) {
			sTip.append( QString( "%1 [%2 : %3]" ).arg( pCommonStrings->getMidiTooltipBound() )
						 .arg( m_sRegisteredMidiEvent ).arg( m_nRegisteredMidiParameter ) );
		} else {
			sTip.append( QString( "%1" ).arg( pCommonStrings->getMidiTooltipUnbound() ) );
		}
	}
			
	setToolTip( sTip );
}

void Button::updateFont() {
	
	float fScalingFactor = 1.0;
    switch ( m_lastUsedFontSize ) {
    case H2Core::Preferences::FontSize::Small:
		fScalingFactor = 1.2;
		break;
    case H2Core::Preferences::FontSize::Normal:
		fScalingFactor = 1.0;
		break;
    case H2Core::Preferences::FontSize::Large:
		fScalingFactor = 0.75;
		break;
	}

	int nMargin, nPixelSize;
	if ( m_size.width() <= 12 || m_size.height() <= 12 ) {
		nMargin = 1;
	} else if ( m_size.width() <= 19 || m_size.height() <= 19 ) {
		nMargin = 5;
	} else if ( m_size.width() <= 22 || m_size.height() <= 22 ) {
		nMargin = 7;
	} else {
		nMargin = 9;
	}
	
	if ( m_size.width() >= m_size.height() ) {
		nPixelSize = m_size.height() - std::round( fScalingFactor * nMargin );
	} else {
		nPixelSize = m_size.width() - std::round( fScalingFactor * nMargin );
	}

	QFont font( m_sLastUsedFontFamily );
	font.setPixelSize( nPixelSize );
	setFont( font );

	if ( m_size.width() > m_size.height() ) {
		// Check whether the width of the text fits the available frame
		// width of the button.
		while ( fontMetrics().size( Qt::TextSingleLine, text() ).width() > width()
				&& nPixelSize > 1 ) {
			nPixelSize--;
			font.setPixelSize( nPixelSize );
			setFont( font );
		}
	}
}
	
void Button::paintEvent( QPaintEvent* ev )
{
	QPushButton::paintEvent( ev );

	updateFont();

	if ( ! m_sIcon.isEmpty() && !m_bColorful && isChecked() != m_bLastCheckedState ) {
		if ( isChecked() ) {
			setIcon( QIcon( Skin::getSvgImagePath() + "/icons/white/" + m_sIcon ) );
		} else {
			setIcon( QIcon( Skin::getSvgImagePath() + "/icons/black/" + m_sIcon ) );
		}

		m_bLastCheckedState = isChecked();
	}
}

void Button::onPreferencesChanged( bool bAppearanceOnly ) {
	auto pPref = H2Core::Preferences::get_instance();
	
	if ( m_sLastUsedFontFamily != pPref->getLevel3FontFamily() ||
		 m_lastWidgetTextColor != pPref->getDefaultUIStyle()->m_widgetTextColor ||
		 m_lastWidgetColor != pPref->getDefaultUIStyle()->m_widgetColor ||
		 m_lastAccentColor != pPref->getDefaultUIStyle()->m_accentColor ||
		 m_lastAccentTextColor != pPref->getDefaultUIStyle()->m_accentTextColor ||
		 m_lastButtonRedColor != pPref->getDefaultUIStyle()->m_buttonRedColor ||
		 m_lastButtonRedTextColor != pPref->getDefaultUIStyle()->m_buttonRedTextColor ||
		 m_lastUsedFontSize != pPref->getFontSize() ) {

		m_lastWidgetTextColor = pPref->getDefaultUIStyle()->m_widgetTextColor;
		m_lastWidgetColor = pPref->getDefaultUIStyle()->m_widgetColor;
		m_lastAccentColor = pPref->getDefaultUIStyle()->m_accentColor;
		m_lastAccentTextColor = pPref->getDefaultUIStyle()->m_accentTextColor;
		m_lastButtonRedColor = pPref->getDefaultUIStyle()->m_buttonRedColor;
		m_lastButtonRedTextColor = pPref->getDefaultUIStyle()->m_buttonRedTextColor;
		
		m_lastUsedFontSize = pPref->getFontSize();
		m_sLastUsedFontFamily = pPref->getLevel3FontFamily();
		updateFont();
		updateStyleSheet();
	}
}
