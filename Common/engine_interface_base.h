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

#ifndef ENGINE_INTERFACE_BASE_H
#define ENGINE_INTERFACE_BASE_H

#include "tools/global.h"

//! This is the abstact base for all Engine Interface classes.
/*!
	 This is the abstact base for all Engine Interface classes. It will provide unified access to the field information of the corresponding engine.
	 All processing methods should only access this base class.
*/
class Engine_Interface_Base
{
public:
	enum InterpolationType { NO_INTERPOLATION, NODE_INTERPOLATE, CELL_INTERPOLATE };

	//! Set the current interpolation type \sa GetInterpolationType
	void SetInterpolationType(InterpolationType type) {m_InterpolType=type;}
	//! Set the current interpolation type \sa GetInterpolationType
	void SetInterpolationType(int type) {m_InterpolType=(InterpolationType)type;}
	//! Get the current interpolation type as string \sa SetInterpolationType GetInterpolationType GetInterpolationNameByType
	std::string GetInterpolationTypeString() {return GetInterpolationNameByType(m_InterpolType);}
	//! Get the current interpolation type \sa SetInterpolationType
	InterpolationType GetInterpolationType() {return m_InterpolType;}

	//! Get the (interpolated) electric field at \p pos. \sa SetInterpolationType
	virtual double* GetEField(const unsigned int* pos, double* out) const {UNUSED(pos);return out;}
	//! Get the (interpolated) magnetic field at \p pos. \sa SetInterpolationType
	virtual double* GetHField(const unsigned int* pos, double* out) const {UNUSED(pos);return out;}

	//! Convert the interpolation type into a string.
	static std::string GetInterpolationNameByType(InterpolationType mode);

protected:
    Engine_Interface_Base();

	InterpolationType m_InterpolType;
};

#endif // ENGINE_INTERFACE_BASE_H
