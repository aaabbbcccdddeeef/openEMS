/*
*	Copyright (C) 2010 Thorsten Liebig (Thorsten.Liebig@gmx.de)
*
*	This program is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*
*	This program is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*
*	You should have received a copy of the GNU General Public License
*	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "operator_base.h"

Operator_Base::Operator_Base()
{
	Init();
	m_MeshType = Processing::CARTESIAN_MESH;
}

Operator_Base::~Operator_Base()
{

}

std::string Operator_Base::GetDirName(int ny) const
{
	if (ny==0) return "x";
	if (ny==1) return "y";
	if (ny==2) return "z";
	return "";
}

void Operator_Base::Init()
{
	dT = 0;
	for (int n=0; n<3; ++n)
		discLines[n]=NULL;
	for (int n=0; n<6; ++n)
		m_BC[n]=0;
}

void Operator_Base::Reset()
{
	for (int n=0; n<3; ++n)
		delete[] discLines[n];
	Init();
}