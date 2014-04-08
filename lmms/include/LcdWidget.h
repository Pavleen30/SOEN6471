/*
 * LcdWidget.h - a widget for displaying numbers in LCD style
 *
 * Copyright (c) 2014 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#ifndef _LCD_WIDGET_H
#define _LCD_WIDGET_H

#include <QtCore/QMap>
#include <QtGui/QWidget>

#include "export.h"

class EXPORT LcdWidget : public QWidget
{
	Q_OBJECT
public:
	LcdWidget( int numDigits, QWidget* parent, const QString& name = QString::null );

	LcdWidget( int numDigits, const QString& style, QWidget* parent, const QString& name = QString::null );

	virtual ~LcdWidget();

	void setValue( int value );
	void setLabel( const QString& label );

	void addTextForValue( int value, const QString& text )
	{
		m_textForValue[value] = text;
		update();
	}


public slots:
	virtual void setMarginWidth( int _width );


protected:
	virtual void paintEvent( QPaintEvent * _me );
	
	virtual void updateSize();

	int cellHeight() const
	{
		return m_cellHeight;
	}


private:

	static const int charsPerPixmap = 12;

	QMap<int, QString> m_textForValue;

	QString m_display;

	QString m_label;
	QPixmap* m_lcdPixmap;

	int m_cellWidth;
	int m_cellHeight;
	int m_numDigits;
	int m_marginWidth;

} ;

#endif
