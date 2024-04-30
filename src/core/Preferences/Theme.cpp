/*
 * Hydrogen
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
#include <fstream>

#include "Theme.h"

#include <core/Helpers/Filesystem.h>
#include "../Version.h"

namespace H2Core
{

ColorTheme::ColorTheme()
	: m_songEditor_backgroundColor( QColor( 128, 134, 152 ) )
	, m_songEditor_alternateRowColor( QColor( 106, 111, 126 ) )
	, m_songEditor_virtualRowColor( QColor( 120, 112, 97 ) )
	, m_songEditor_selectedRowColor( QColor( 149, 157, 178 ) )
	, m_songEditor_selectedRowTextColor( QColor( 0, 0, 0 ) )
	, m_songEditor_lineColor( QColor( 54, 57, 67 ) )
	, m_songEditor_textColor( QColor( 206, 211, 224 ) )
	, m_songEditor_automationBackgroundColor( QColor( 83, 89, 103 ) )
	, m_songEditor_automationLineColor( QColor( 45, 66, 89 ) )
	, m_songEditor_automationNodeColor( QColor( 255, 255, 255 ) )
	, m_songEditor_stackedModeOnColor( QColor( 127, 159, 127 ) )
	, m_songEditor_stackedModeOnNextColor( QColor( 240, 223, 175 ) )
	, m_songEditor_stackedModeOffNextColor( QColor( 247, 100, 100 ) )
	, m_patternEditor_backgroundColor( QColor( 165, 166, 160 ) )
	, m_patternEditor_alternateRowColor( QColor( 133, 134, 129 ) )
	, m_patternEditor_selectedRowColor( QColor( 194, 195, 187 ) )
	, m_patternEditor_selectedRowTextColor( QColor( 0, 0, 0 ) )
	, m_patternEditor_octaveRowColor( QColor( 193, 194, 186 ) )
	, m_patternEditor_textColor( QColor( 240, 240, 240 ) )
	, m_patternEditor_noteVelocityFullColor( QColor( 247, 100, 100 ) )
	, m_patternEditor_noteVelocityDefaultColor( QColor( 40, 40, 40 ) )
	, m_patternEditor_noteVelocityHalfColor( QColor( 89, 131, 175 ) )
	, m_patternEditor_noteVelocityZeroColor( QColor( 255, 255, 255 ) )
	, m_patternEditor_noteOffColor( QColor( 71, 79, 191 ) )
	, m_patternEditor_lineColor( QColor(45, 45, 45) )
	, m_patternEditor_line1Color( QColor(55, 55, 55) )
	, m_patternEditor_line2Color( QColor(75, 75, 75) )
	, m_patternEditor_line3Color( QColor(95, 95, 95) )
	, m_patternEditor_line4Color( QColor(105, 105, 105) )
	, m_patternEditor_line5Color( QColor(115, 115, 115) )
	, m_selectionHighlightColor( QColor( 255, 255, 255 ) )
	, m_selectionInactiveColor( QColor( 199, 199, 199 ) )
	, m_windowColor( QColor( 58, 62, 72 ) )
	, m_windowTextColor( QColor( 255, 255, 255 ) )
	, m_baseColor( QColor( 88, 94, 112 ) )
	, m_alternateBaseColor( QColor( 138, 144, 162 ) )
	, m_textColor( QColor( 255, 255, 255 ) )
	, m_buttonColor( QColor( 88, 94, 112 ) )
	, m_buttonTextColor( QColor( 255, 255, 255 ) )
	, m_lightColor( QColor( 138, 144, 162 ) )
	, m_midLightColor( QColor( 128, 134, 152 ) )
	, m_midColor( QColor( 58, 62, 72 ) )
	, m_darkColor( QColor( 81, 86, 99 ) )
	, m_shadowTextColor( QColor( 255, 255, 255 ) )
	, m_highlightColor( QColor( 206, 150, 30 ) )
	, m_highlightedTextColor( QColor( 255, 255, 255 ) )
	, m_toolTipBaseColor( QColor( 227, 243, 252 ) )
	, m_toolTipTextColor( QColor( 64, 64, 66 ) )
	, m_widgetColor( QColor( 164, 170, 190 ) )
	, m_widgetTextColor( QColor( 10, 10, 10 ) )
	, m_buttonRedColor( QColor( 247, 100, 100 ) )
	, m_buttonRedTextColor( QColor( 10, 10, 10 ) )
	, m_spinBoxColor( QColor( 51, 74 , 100 ) )
	, m_spinBoxTextColor( QColor( 240, 240, 240 ) )
	, m_accentColor( QColor( 67, 96, 131 ) )
	, m_accentTextColor( QColor( 255, 255, 255 ) )
	, m_playheadColor( QColor( 0, 0, 0 ) )
	, m_cursorColor( QColor( 38, 39, 44 ) )
{
}

void ColorTheme::saveTo( XMLNode& parent ) const {

	XMLNode colorThemeNode = parent.createNode( "colorTheme" );

	// SONG EDITOR
	XMLNode songEditorNode = colorThemeNode.createNode( "songEditor" );
	songEditorNode.write_color( "backgroundColor", m_songEditor_backgroundColor );
	songEditorNode.write_color( "alternateRowColor", m_songEditor_alternateRowColor );
	songEditorNode.write_color( "virtualRowColor", m_songEditor_virtualRowColor );
	songEditorNode.write_color( "selectedRowColor",
								 m_songEditor_selectedRowColor );
	songEditorNode.write_color( "selectedRowTextColor",
								 m_songEditor_selectedRowTextColor );
	songEditorNode.write_color( "lineColor", m_songEditor_lineColor );
	songEditorNode.write_color( "textColor", m_songEditor_textColor );
	songEditorNode.write_color( "automationBackgroundColor",
								 m_songEditor_automationBackgroundColor );
	songEditorNode.write_color( "automationLineColor",
								 m_songEditor_automationLineColor );
	songEditorNode.write_color( "automationNodeColor",
								 m_songEditor_automationNodeColor );
	songEditorNode.write_color( "stackedModeOnColor",
								 m_songEditor_stackedModeOnColor );
	songEditorNode.write_color( "stackedModeOnNextColor",
								 m_songEditor_stackedModeOnNextColor );
	songEditorNode.write_color( "stackedModeOffNextColor",
								 m_songEditor_stackedModeOffNextColor );

	// PATTERN EDITOR
	XMLNode patternEditorNode = colorThemeNode.createNode( "patternEditor" );
	patternEditorNode.write_color( "backgroundColor", m_patternEditor_backgroundColor );
	patternEditorNode.write_color( "alternateRowColor", m_patternEditor_alternateRowColor );
	patternEditorNode.write_color( "selectedRowColor",
								 m_patternEditor_selectedRowColor );
	patternEditorNode.write_color( "selectedRowTextColor",
								 m_patternEditor_selectedRowTextColor );
	patternEditorNode.write_color( "octaveRowColor",
								 m_patternEditor_octaveRowColor );
	patternEditorNode.write_color( "textColor", m_patternEditor_textColor );
	patternEditorNode.write_color( "noteVelocityFullColor",
								 m_patternEditor_noteVelocityFullColor );
	patternEditorNode.write_color( "noteVelocityDefaultColor",
								 m_patternEditor_noteVelocityDefaultColor );
	patternEditorNode.write_color( "noteVelocityHalfColor",
								 m_patternEditor_noteVelocityHalfColor );
	patternEditorNode.write_color( "noteVelocityZeroColor",
								 m_patternEditor_noteVelocityZeroColor );
	patternEditorNode.write_color( "noteOffColor", m_patternEditor_noteOffColor );

	patternEditorNode.write_color( "lineColor", m_patternEditor_lineColor );
	patternEditorNode.write_color( "line1Color", m_patternEditor_line1Color );
	patternEditorNode.write_color( "line2Color", m_patternEditor_line2Color );
	patternEditorNode.write_color( "line3Color", m_patternEditor_line3Color );
	patternEditorNode.write_color( "line4Color", m_patternEditor_line4Color );
	patternEditorNode.write_color( "line5Color", m_patternEditor_line5Color );

	XMLNode selectionNode = colorThemeNode.createNode( "selection" );
	selectionNode.write_color( "highlightColor", m_selectionHighlightColor );
	selectionNode.write_color( "inactiveColor", m_selectionInactiveColor );

	XMLNode paletteNode = colorThemeNode.createNode( "palette" );
	paletteNode.write_color( "windowColor", m_windowColor );
	paletteNode.write_color( "windowTextColor", m_windowTextColor );
	paletteNode.write_color( "baseColor", m_baseColor );
	paletteNode.write_color( "alternateBaseColor", m_alternateBaseColor );
	paletteNode.write_color( "textColor", m_textColor );
	paletteNode.write_color( "buttonColor", m_buttonColor );
	paletteNode.write_color( "buttonTextColor", m_buttonTextColor );
	paletteNode.write_color( "lightColor", m_lightColor );
	paletteNode.write_color( "midLightColor", m_midLightColor );
	paletteNode.write_color( "midColor", m_midColor );
	paletteNode.write_color( "darkColor", m_darkColor );
	paletteNode.write_color( "shadowTextColor", m_shadowTextColor );
	paletteNode.write_color( "highlightColor", m_highlightColor );
	paletteNode.write_color( "highlightedTextColor", m_highlightedTextColor );
	paletteNode.write_color( "toolTipBaseColor", m_toolTipBaseColor );
	paletteNode.write_color( "toolTipTextColor", m_toolTipTextColor );

	XMLNode widgetNode = colorThemeNode.createNode( "widget" );
	widgetNode.write_color( "accentColor", m_accentColor );
	widgetNode.write_color( "accentTextColor", m_accentTextColor );
	widgetNode.write_color( "widgetColor", m_widgetColor );
	widgetNode.write_color( "widgetTextColor", m_widgetTextColor );
	widgetNode.write_color( "buttonRedColor", m_buttonRedColor );
	widgetNode.write_color( "buttonRedTextColor", m_buttonRedTextColor );
	widgetNode.write_color( "spinBoxColor", m_spinBoxColor );
	widgetNode.write_color( "spinBoxTextColor", m_spinBoxTextColor );
	widgetNode.write_color( "playheadColor", m_playheadColor );
	widgetNode.write_color( "cursorColor", m_cursorColor );
}

ColorTheme ColorTheme::loadFrom( const XMLNode& parent ) {
	auto colorTheme = ColorTheme();

	// SONG EDITOR
	XMLNode songEditorNode = parent.firstChildElement( "songEditor" );
	if ( ! songEditorNode.isNull() ) {
		colorTheme.m_songEditor_backgroundColor =
			songEditorNode.read_color( "backgroundColor",
									   colorTheme.m_songEditor_backgroundColor, false, false );
		colorTheme.m_songEditor_alternateRowColor =
			songEditorNode.read_color( "alternateRowColor",
									   colorTheme.m_songEditor_alternateRowColor, false, false );
		colorTheme.m_songEditor_virtualRowColor =
			songEditorNode.read_color( "virtualRowColor",
									   colorTheme.m_songEditor_virtualRowColor, false, false );
		colorTheme.m_songEditor_selectedRowColor =
			songEditorNode.read_color( "selectedRowColor",
									   colorTheme.m_songEditor_selectedRowColor, false, false );
		colorTheme.m_songEditor_selectedRowTextColor =
			songEditorNode.read_color( "selectedRowTextColor",
									   colorTheme.m_songEditor_selectedRowTextColor, false, false );
		colorTheme.m_songEditor_lineColor =
			songEditorNode.read_color( "lineColor",
									   colorTheme.m_songEditor_lineColor, false, false );
		colorTheme.m_songEditor_textColor =
			songEditorNode.read_color( "textColor",
									   colorTheme.m_songEditor_textColor, false, false );
		colorTheme.m_songEditor_automationBackgroundColor =
			songEditorNode.read_color( "automationBackgroundColor",
									   colorTheme.m_songEditor_automationBackgroundColor, false, false );
		colorTheme.m_songEditor_automationLineColor =
			songEditorNode.read_color( "automationLineColor",
									   colorTheme.m_songEditor_automationLineColor, false, false );
		colorTheme.m_songEditor_automationNodeColor =
			songEditorNode.read_color( "automationNodeColor",
									   colorTheme.m_songEditor_automationNodeColor, false, false );
		colorTheme.m_songEditor_stackedModeOnColor =
			songEditorNode.read_color( "stackedModeOnColor",
									   colorTheme.m_songEditor_stackedModeOnColor, false, false );
		colorTheme.m_songEditor_stackedModeOnNextColor =
			songEditorNode.read_color( "stackedModeOnNextColor",
									   colorTheme.m_songEditor_stackedModeOnNextColor, false, false );
		colorTheme.m_songEditor_stackedModeOffNextColor =
			songEditorNode.read_color( "stackedModeOffNextColor",
									   colorTheme.m_songEditor_stackedModeOffNextColor, false, false );
	} else {
		WARNINGLOG( "'songEditor' node not found" );
	}

	// PATTERN EDITOR
	XMLNode patternEditorNode = parent.firstChildElement( "patternEditor" );
	if ( ! patternEditorNode.isNull() ) {
		colorTheme.m_patternEditor_backgroundColor =
			patternEditorNode.read_color( "backgroundColor",
										  colorTheme.m_patternEditor_backgroundColor, false, false );
		colorTheme.m_patternEditor_alternateRowColor =
			patternEditorNode.read_color( "alternateRowColor",
										  colorTheme.m_patternEditor_alternateRowColor, false, false );
		colorTheme.m_patternEditor_selectedRowColor =
			patternEditorNode.read_color( "selectedRowColor",
										  colorTheme.m_patternEditor_selectedRowColor, false, false );
		colorTheme.m_patternEditor_selectedRowTextColor =
			patternEditorNode.read_color( "selectedRowTextColor",
										  colorTheme.m_patternEditor_selectedRowTextColor, false, false );
		colorTheme.m_patternEditor_octaveRowColor =
			patternEditorNode.read_color( "octaveRowColor",
										  colorTheme.m_patternEditor_octaveRowColor, false, false );
		colorTheme.m_patternEditor_textColor =
			patternEditorNode.read_color( "textColor",
										  colorTheme.m_patternEditor_textColor, false, false );
		colorTheme.m_patternEditor_noteVelocityFullColor =
			patternEditorNode.read_color( "noteVelocityFullColor",
										  colorTheme.m_patternEditor_noteVelocityFullColor, false, false );
		colorTheme.m_patternEditor_noteVelocityDefaultColor =
			patternEditorNode.read_color( "noteVelocityDefaultColor",
										  colorTheme.m_patternEditor_noteVelocityDefaultColor, false, false );
		colorTheme.m_patternEditor_noteVelocityHalfColor =
			patternEditorNode.read_color( "noteVelocityHalfColor",
										  colorTheme.m_patternEditor_noteVelocityHalfColor, false, false );
		colorTheme.m_patternEditor_noteVelocityZeroColor =
			patternEditorNode.read_color( "noteVelocityZeroColor",
										  colorTheme.m_patternEditor_noteVelocityZeroColor, false, false );
		colorTheme.m_patternEditor_noteOffColor =
			patternEditorNode.read_color( "noteOffColor",
										  colorTheme.m_patternEditor_noteOffColor, false, false );
		colorTheme.m_patternEditor_lineColor =
			patternEditorNode.read_color( "lineColor",
										  colorTheme.m_patternEditor_lineColor, false, false );
		colorTheme.m_patternEditor_line1Color =
			patternEditorNode.read_color( "line1Color",
										  colorTheme.m_patternEditor_line1Color, false, false );
		colorTheme.m_patternEditor_line2Color =
			patternEditorNode.read_color( "line2Color",
										  colorTheme.m_patternEditor_line2Color, false, false );
		colorTheme.m_patternEditor_line3Color =
			patternEditorNode.read_color( "line3Color",
										  colorTheme.m_patternEditor_line3Color, false, false );
		colorTheme.m_patternEditor_line4Color =
			patternEditorNode.read_color( "line4Color",
										  colorTheme.m_patternEditor_line4Color, false, false );
		colorTheme.m_patternEditor_line5Color =
			patternEditorNode.read_color( "line5Color",
										  colorTheme.m_patternEditor_line5Color, false, false );
	} else {
		WARNINGLOG( "'patternEditor' node not found" );
	}

	XMLNode selectionNode = parent.firstChildElement( "selection" );
	if ( ! selectionNode.isNull() ) {
		colorTheme.m_selectionHighlightColor =
			selectionNode.read_color( "highlightColor",
									  colorTheme.m_selectionHighlightColor, false, false );
		colorTheme.m_selectionInactiveColor =
			selectionNode.read_color( "inactiveColor",
									  colorTheme.m_selectionInactiveColor, false, false );
	} else {
		WARNINGLOG( "'selection' node not found" );
	}

	XMLNode paletteNode = parent.firstChildElement( "palette" );
	if ( ! paletteNode.isNull() ) {
		colorTheme.m_windowColor =
			paletteNode.read_color( "windowColor",
									colorTheme.m_windowColor, false, false );
		colorTheme.m_windowTextColor =
			paletteNode.read_color( "windowTextColor",
									colorTheme.m_windowTextColor, false, false );
		colorTheme.m_baseColor =
			paletteNode.read_color( "baseColor",
									colorTheme.m_baseColor, false, false );
		colorTheme.m_alternateBaseColor =
			paletteNode.read_color( "alternateBaseColor",
									colorTheme.m_alternateBaseColor, false, false );
		colorTheme.m_textColor =
			paletteNode.read_color( "textColor",
									colorTheme.m_textColor, false, false );
		colorTheme.m_buttonColor =
			paletteNode.read_color( "buttonColor",
									colorTheme.m_buttonColor, false, false );
		colorTheme.m_buttonTextColor =
			paletteNode.read_color( "buttonTextColor",
									colorTheme.m_buttonTextColor, false, false );
		colorTheme.m_lightColor =
			paletteNode.read_color( "lightColor",
									colorTheme.m_lightColor, false, false );
		colorTheme.m_midLightColor =
			paletteNode.read_color( "midLightColor",
									colorTheme.m_midLightColor, false, false );
		colorTheme.m_midColor =
			paletteNode.read_color( "midColor",
									colorTheme.m_midColor, false, false );
		colorTheme.m_darkColor =
			paletteNode.read_color( "darkColor",
									colorTheme.m_darkColor, false, false );
		colorTheme.m_shadowTextColor =
			paletteNode.read_color( "shadowTextColor",
									colorTheme.m_shadowTextColor, false, false );
		colorTheme.m_highlightColor =
			paletteNode.read_color( "highlightColor",
									colorTheme.m_highlightColor, false, false );
		colorTheme.m_highlightedTextColor =
			paletteNode.read_color( "highlightedTextColor",
									colorTheme.m_highlightedTextColor, false, false );
		colorTheme.m_toolTipBaseColor =
			paletteNode.read_color( "toolTipBaseColor",
									colorTheme.m_toolTipBaseColor, false, false );
		colorTheme.m_toolTipTextColor =
			paletteNode.read_color( "toolTipTextColor",
									colorTheme.m_toolTipTextColor, false, false );
	} else {
		WARNINGLOG( "'palette' node not found" );
	}

	XMLNode widgetNode = parent.firstChildElement( "widget" );
	if ( ! widgetNode.isNull() ) {
		colorTheme.m_accentColor =
			widgetNode.read_color( "accentColor",
								   colorTheme.m_accentColor, false, false );
		colorTheme.m_accentTextColor =
			widgetNode.read_color( "accentTextColor",
								   colorTheme.m_accentTextColor, false, false );
		colorTheme.m_widgetColor =
			widgetNode.read_color( "widgetColor",
								   colorTheme.m_widgetColor, false, false );
		colorTheme.m_widgetTextColor =
			widgetNode.read_color( "widgetTextColor",
								   colorTheme.m_widgetTextColor, false, false );
		colorTheme.m_buttonRedColor =
			widgetNode.read_color( "buttonRedColor",
								   colorTheme.m_buttonRedColor, false, false );
		colorTheme.m_buttonRedTextColor =
			widgetNode.read_color( "buttonRedTextColor",
								   colorTheme.m_buttonRedTextColor, false, false );
		colorTheme.m_spinBoxColor =
			widgetNode.read_color( "spinBoxColor",
								   colorTheme.m_spinBoxColor, false, false );
		colorTheme.m_spinBoxTextColor =
			widgetNode.read_color( "spinBoxTextColor",
								   colorTheme.m_spinBoxTextColor, false, false );
		colorTheme.m_playheadColor =
			widgetNode.read_color( "playheadColor",
								   colorTheme.m_playheadColor, false, false );
		colorTheme.m_cursorColor =
			widgetNode.read_color( "cursorColor",
								   colorTheme.m_cursorColor, false, false );
	} else {
		WARNINGLOG( "'widget' node not found" );
	}

	return colorTheme;
}

float InterfaceTheme::FALLOFF_SLOW = 1.08f;
float InterfaceTheme::FALLOFF_NORMAL = 1.1f;
float InterfaceTheme::FALLOFF_FAST = 1.5f;

InterfaceTheme::InterfaceTheme()
	: m_sQTStyle( "Fusion" )
	, m_fMixerFalloffSpeed( InterfaceTheme::FALLOFF_NORMAL )
	, m_layout( InterfaceTheme::Layout::SinglePane )
	, m_uiScalingPolicy( InterfaceTheme::ScalingPolicy::Smaller )
	, m_iconColor( InterfaceTheme::IconColor::Black )
	, m_coloringMethod( InterfaceTheme::ColoringMethod::Custom )
	, m_nVisiblePatternColors( 18 ) {
	m_patternColors.resize( nMaxPatternColors );
	for ( int ii = 0; ii < InterfaceTheme::nMaxPatternColors; ii++ ) {
		m_patternColors[ ii ] = QColor( 67, 96, 131 );
	}
}

FontTheme::FontTheme()
	: m_sApplicationFontFamily( "Lucida Grande" )
	, m_sLevel2FontFamily( "Lucida Grande" )
	, m_sLevel3FontFamily( "Lucida Grande" )
	, m_fontSize( FontTheme::FontSize::Medium ) {
}

Theme::Theme( const ColorTheme& colorTheme,
			  const InterfaceTheme& interfaceTheme,
			  const FontTheme& fontTheme )
	: m_color{ colorTheme }
	, m_interface{ interfaceTheme }
	, m_font{ fontTheme } {
}

Theme::Theme( const Theme& other )
	: m_color{ other.m_color }
	, m_interface{ other.m_interface}
	, m_font{ other.m_font } {
}

Theme::Theme( Theme&& other )
	: m_color{ other.m_color }
	, m_interface{ other.m_interface }
	, m_font{ other.m_font }
{
}

Theme& Theme::operator=( const Theme& other ) {
	m_color = other.m_color;
	m_interface = other.m_interface;
	m_font = other.m_font;

	return *this;
}

Theme& Theme::operator=( Theme&& other ) {
	m_color = std::move( other.m_color );
	m_interface = std::move( other.m_interface );
	m_font = std::move( other.m_font );

	return *this;
}

std::unique_ptr<Theme> Theme::importFrom( const QString& sPath ) {
	if ( ! Filesystem::file_exists( sPath ) || ! Filesystem::file_readable( sPath ) ){
		return nullptr;
	}

	INFOLOG( QString( "Importing theme to %1" ).arg( sPath ) );

	XMLDoc doc;
	if ( ! doc.read( sPath, nullptr, true ) ) {
		ERRORLOG( "Unable to load theme." );
		return nullptr;
	}
	
	XMLNode rootNode = doc.firstChildElement( "hydrogen_theme" );
	if ( rootNode.isNull() ) {
		ERRORLOG( "'hydrogen_theme' node not found" );
		return nullptr;
	}

	XMLNode colorThemeNode = rootNode.firstChildElement( "colorTheme" );
	if ( colorThemeNode.isNull() ) {
		ERRORLOG( "'colorTheme' node not found" );
		return nullptr;
	}
	auto colorTheme = ColorTheme::loadFrom( colorThemeNode );
	
	XMLNode interfaceNode = rootNode.firstChildElement( "interfaceTheme" );
	if ( interfaceNode.isNull() ) {
		ERRORLOG( "'interfaceTheme' node not found" );
		return nullptr;
	}
	auto interfaceTheme = InterfaceTheme();
	interfaceTheme.m_layout =
		static_cast<InterfaceTheme::Layout>(
			interfaceNode.read_int( "defaultUILayout",
									static_cast<int>(InterfaceTheme::Layout::SinglePane),
									false, false ));
	interfaceTheme.m_uiScalingPolicy =
		static_cast<InterfaceTheme::ScalingPolicy>(
			interfaceNode.read_int( "uiScalingPolicy",
									static_cast<int>(InterfaceTheme::ScalingPolicy::Smaller),
									false, false ));
				
	// QT Style
	interfaceTheme.m_sQTStyle =
		interfaceNode.read_string( "QTStyle", "Fusion", false, false );

	if ( interfaceTheme.m_sQTStyle == "Plastique" ){
		interfaceTheme.m_sQTStyle = "Fusion";
	}
	interfaceTheme.m_iconColor =
		static_cast<InterfaceTheme::IconColor>(
			interfaceNode.read_int( "iconColor",
									static_cast<int>(InterfaceTheme::IconColor::Black),
									false, false));

	// Mixer falloff speed
	interfaceTheme.m_fMixerFalloffSpeed =
		interfaceNode.read_float( "mixer_falloff_speed",
								  InterfaceTheme::FALLOFF_NORMAL, false, false );

	//SongEditor coloring
	interfaceTheme.m_coloringMethod =
		static_cast<InterfaceTheme::ColoringMethod>(
			interfaceNode.read_int("SongEditor_ColoringMethod",
								   static_cast<int>(InterfaceTheme::ColoringMethod::Custom),
								   false, false ));
	std::vector<QColor> colors( interfaceTheme.nMaxPatternColors );
	for ( int ii = 0; ii < interfaceTheme.nMaxPatternColors; ii++ ) {
		colors[ ii ] = interfaceNode.read_color( QString( "SongEditor_pattern_color_%1" ).arg( ii ),
												 colorTheme.m_accentColor,
												 false, false );
	}
	interfaceTheme.m_patternColors = colors;
	interfaceTheme.m_nVisiblePatternColors =
		interfaceNode.read_int( "SongEditor_visible_pattern_colors", 1, false, false );
	if ( interfaceTheme.m_nVisiblePatternColors > 50 ) {
		interfaceTheme.m_nVisiblePatternColors = 50;
	} else if ( interfaceTheme.m_nVisiblePatternColors < 0 ) {
		interfaceTheme.m_nVisiblePatternColors = 0;
	}									  
			
	XMLNode fontNode = rootNode.firstChildElement( "fontTheme" );
	if ( fontNode.isNull() ) {
		ERRORLOG( "'fontTheme' node not found" );
		return nullptr;
	}

	auto fontTheme = FontTheme();
	// Font fun
	fontTheme.m_sApplicationFontFamily =
		fontNode.read_string( "application_font_family",
							  fontTheme.m_sApplicationFontFamily, false, false );
	// The value defaults to m_sApplicationFontFamily on
	// purpose to provide backward compatibility.
	fontTheme.m_sLevel2FontFamily =
		fontNode.read_string( "level2_font_family",
							  fontTheme.m_sLevel2FontFamily, false, false );
	fontTheme.m_sLevel3FontFamily =
		fontNode.read_string( "level3_font_family",
							  fontTheme.m_sLevel3FontFamily, false, false );
	fontTheme.m_fontSize =
		static_cast<FontTheme::FontSize>(
			fontNode.read_int( "font_size",
							   static_cast<int>(FontTheme::FontSize::Medium), false, false ) );

	return std::make_unique<Theme>(colorTheme, interfaceTheme, fontTheme );
}

bool Theme::exportTo( const QString& sPath ) const {

	INFOLOG( QString( "Exporting theme to %1" ).arg( sPath ) );

	XMLDoc doc;
	XMLNode rootNode = doc.set_root( "hydrogen_theme", "theme" );
	// hydrogen version
	rootNode.write_string( "version", QString( get_version().c_str() ) );
	
	m_color.saveTo( rootNode );

	XMLNode interfaceNode = rootNode.createNode( "interfaceTheme" );
	interfaceNode.write_int( "defaultUILayout",
							 static_cast<int>(m_interface.m_layout) );
	interfaceNode.write_int( "uiScalingPolicy",
							 static_cast<int>(m_interface.m_uiScalingPolicy) );
	interfaceNode.write_string( "QTStyle", m_interface.m_sQTStyle );
	interfaceNode.write_int( "iconColor",
							 static_cast<int>(m_interface.m_iconColor) );
	interfaceNode.write_float( "mixer_falloff_speed",
							   m_interface.m_fMixerFalloffSpeed );
	interfaceNode.write_int( "SongEditor_ColoringMethod",
							 static_cast<int>(m_interface.m_coloringMethod) );
	for ( int ii = 0; ii < m_interface.nMaxPatternColors; ii++ ) {
		interfaceNode.write_color( QString( "SongEditor_pattern_color_%1" ).arg( ii ),
								   m_interface.m_patternColors[ ii ] );
	}
	interfaceNode.write_int( "SongEditor_visible_pattern_colors",
							 m_interface.m_nVisiblePatternColors );

	XMLNode fontNode = rootNode.createNode( "fontTheme" );
	fontNode.write_string( "application_font_family",
						   m_font.m_sApplicationFontFamily );
	fontNode.write_string( "level2_font_family",
						   m_font.m_sLevel2FontFamily );
	fontNode.write_string( "level3_font_family",
						   m_font.m_sLevel3FontFamily );
	fontNode.write_int( "font_size",
						static_cast<int>(m_font.m_fontSize) );

	return doc.write( sPath );
}	

}
