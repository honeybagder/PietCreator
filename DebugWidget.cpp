/*
    Copyright (C) 2010 Casey Link <unnamedrambler@gmail.com>

    This library is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 3 of the License, or (at your
    option) any later version.

    This library is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301, USA.
*/

#include "DebugWidget.h"

extern "C"
{
    #include "npiet/npiet_utils.h"
}

#include "ImageModel.h"

#include <QDebug>

DebugWidget::DebugWidget( ImageModel* model, QWidget* parent, Qt::WindowFlags f ): QWidget( parent, f ), mImageModel( model )
{
    setupUi( this );
}

DebugWidget::~DebugWidget()
{

}

void DebugWidget::slotActionChanged( trace_action* action )
{

}

void DebugWidget::slotStepped( trace_step* step )
{
    mCoordinate->setText( QString("%1,%2").arg(step->p_xpos).arg( step->p_ypos) );
    mImageModel->setDebuggedPixel( step->p_xpos, step->p_ypos );
}


#include "DebugWidget.moc"
