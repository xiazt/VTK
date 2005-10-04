/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkCoincidentTopologyResolutionPainter.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkCoincidentTopologyResolutionPainter.h"

#include "vtkInformation.h"
#include "vtkInformationIntegerKey.h"
#include "vtkInformationDoubleKey.h"
#include "vtkInformationDoubleVectorKey.h"
#include "vtkGraphicsFactory.h"
#include "vtkMapper.h" // for VTK_RESOLVE_*
#include "vtkObjectFactory.h"

// Needed when we don't use the vtkStandardNewMacro.
vtkInstantiatorNewMacro(vtkCoincidentTopologyResolutionPainter);
vtkCxxRevisionMacro(vtkCoincidentTopologyResolutionPainter, "1.2");
vtkInformationKeyMacro(vtkCoincidentTopologyResolutionPainter, 
  RESOLVE_COINCIDENT_TOPOLOGY, Integer);
vtkInformationKeyMacro(vtkCoincidentTopologyResolutionPainter, Z_SHIFT, Double);
vtkInformationKeyMacro(vtkCoincidentTopologyResolutionPainter,
  POLYGON_OFFSET_PARAMETERS, DoubleVector);
//-----------------------------------------------------------------------------
vtkCoincidentTopologyResolutionPainter::vtkCoincidentTopologyResolutionPainter()
{
  this->ResolveCoincidentTopology = VTK_RESOLVE_OFF;
  this->PolygonOffsetFactor = 1.0;
  this->PolygonOffsetUnits = 1.0;
  this->ZShift = 0.01;
}
//-----------------------------------------------------------------------------
vtkCoincidentTopologyResolutionPainter::~vtkCoincidentTopologyResolutionPainter()
{
  
}

//-----------------------------------------------------------------------------
vtkCoincidentTopologyResolutionPainter* 
vtkCoincidentTopologyResolutionPainter::New()
{
  vtkObject* o = vtkGraphicsFactory::CreateInstance(
    "vtkCoincidentTopologyResolutionPainter");
  return (vtkCoincidentTopologyResolutionPainter*)o;
}


//-----------------------------------------------------------------------------
void vtkCoincidentTopologyResolutionPainter::ProcessInformation(
  vtkInformation* info)
{
  if (info->Has(RESOLVE_COINCIDENT_TOPOLOGY()))
    {
    this->SetResolveCoincidentTopology(info->Get(RESOLVE_COINCIDENT_TOPOLOGY()));
    }

  if (info->Has(Z_SHIFT()))
    {
    this->SetZShift(info->Get(Z_SHIFT()));
    }

  if (info->Has(POLYGON_OFFSET_PARAMETERS()))
    {
    double* p = info->Get(POLYGON_OFFSET_PARAMETERS());
    this->SetPolygonOffsetParameters(p[0], p[1]);
    }

  this->Superclass::ProcessInformation(info);
}

//-----------------------------------------------------------------------------
void vtkCoincidentTopologyResolutionPainter::PrintSelf(ostream& os, 
  vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
