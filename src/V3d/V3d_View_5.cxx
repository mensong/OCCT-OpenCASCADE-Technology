// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

/***********************************************************************
     FONCTION :
     ----------
        Classe V3d_View :
     HISTORIQUE DES MODIFICATIONS   :
     --------------------------------
      22-10-01 : SAV ; Created
************************************************************************/
/*----------------------------------------------------------------------*/
/*
 * Includes
 */

#include <Aspect_GradientBackground.hxx>
#include <Aspect_Grid.hxx>
#include <Aspect_Window.hxx>
#include <Bnd_Box.hxx>
#include <gp_Ax3.hxx>
#include <gp_Dir.hxx>
#include <Graphic3d_Group.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_TextureEnv.hxx>
#include <Graphic3d_Vector.hxx>
#include <Quantity_Color.hxx>
#include <Standard_MultiplyDefined.hxx>
#include <Standard_TypeMismatch.hxx>
#include <V3d_BadValue.hxx>
#include <V3d_LayerMgr.hxx>
#include <V3d_Light.hxx>
#include <V3d_UnMapped.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>
#include <Visual3d_View.hxx>

//BUC61044 25/10/01 SAV ; added functionality to control gl depth testing from higher API
//BUC61045 25/10/01 SAV ; added functionality to control gl lighting from higher API
void V3d_View::EnableGLLight( const Standard_Boolean enable ) const
{
  MyView->EnableGLLight( enable );
}

Standard_Boolean V3d_View::IsGLLightEnabled() const
{
  return MyView->IsGLLightEnabled();
}

const Graphic3d_RenderingParams& V3d_View::RenderingParams() const
{
  return static_cast<Graphic3d_CView*> (MyView->CView())->RenderParams;
}

Graphic3d_RenderingParams& V3d_View::ChangeRenderingParams()
{
  return static_cast<Graphic3d_CView*> (MyView->CView())->RenderParams;
}

void V3d_View::SetLayerMgr(const Handle(V3d_LayerMgr)& aMgr)
{
  MyLayerMgr = aMgr;
}
