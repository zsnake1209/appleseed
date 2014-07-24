
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2014 Srinath Ravichandran, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_RENDERER_KERNEL_INTERSECTION_CURVEKEY_H
#define APPLESEED_RENDERER_KERNEL_INTERSECTION_CURVEKEY_H

// appleseed.foundation.headers.
#include "foundation/platform/types.h"

// Standard headers.
#include <cstddef>

namespace renderer
{

//
// The CurveKey class uniquely identifies a Bezier curve within an assembly.
//

class CurveKey
{
  public:
    // Constructors.
    CurveKey();
    CurveKey(
        const size_t    object_instance_index,
        const size_t    curve_index,
        const size_t    curve_pa);

    // Return the index of the object instance within the assembly.
    size_t get_object_instance_index() const;

    // Return the index of the curve within the object.
    size_t get_curve_index() const;

    // Return the primitive attribute index of the curve.
    size_t get_curve_pa() const;

  private:
    foundation::uint32  m_object_instance_index;
    foundation::uint32  m_curve_index;
    foundation::uint16  m_curve_pa;
};


//
// CurveKey class implementation.
//

inline CurveKey::CurveKey()
{
}

inline CurveKey::CurveKey(
    const size_t        object_instance_index,
    const size_t        curve_index,
    const size_t        curve_pa)
  : m_object_instance_index(static_cast<foundation::uint32>(object_instance_index))
  , m_curve_index(static_cast<foundation::uint32>(curve_index))
  , m_curve_pa(static_cast<foundation::uint16>(curve_pa))
{
}

inline size_t CurveKey::get_object_instance_index() const
{
    return static_cast<size_t>(m_object_instance_index);
}

inline size_t CurveKey::get_curve_index() const
{
    return static_cast<size_t>(m_curve_index);
}

inline size_t CurveKey::get_curve_pa() const
{
    return static_cast<size_t>(m_curve_pa);
}

};  // namespace renderer.

#endif // !APPLESEED_RENDERER_KERNEL_INTERSECTION_CURVEKEY_H