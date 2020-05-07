/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/


#include "Binding_Topology.h"
#include "Binding_BaseObject.h"
#include "PythonToSofa.inl"

using namespace sofa::core::topology;
using namespace sofa::core;
using namespace sofa::core::objectmodel;

static inline Topology* get_topology(PyObject* obj) {
    return sofa::py::unwrap<Topology>(obj);
}


static PyObject * Topology_hasPos(PyObject *self, PyObject * /*args*/)
{
    Topology* obj = get_topology( self );
    return PyBool_FromLong(obj->hasPos());
}

static PyObject * Topology_getNbPoints(PyObject *self, PyObject * /*args*/)
{
    Topology* obj = get_topology( self );
    return PyInt_FromLong(obj->getNbPoints());
}

static PyObject * Topology_setNbPoints(PyObject *self, PyObject * args)
{
    Topology* obj = get_topology( self );
    int nb;
    if (!PyArg_ParseTuple(args, "i",&nb))
    {
        return nullptr;
    }
    obj->setNbPoints(nb);
    Py_RETURN_NONE;
}

static PyObject * Topology_getPX(PyObject *self, PyObject * args)
{
    Topology* obj = get_topology( self );
    int i;
    if (!PyArg_ParseTuple(args, "i",&i))
    {
        return nullptr;
    }
    return PyFloat_FromDouble(obj->getPX(i));
}

static PyObject * Topology_getPY(PyObject *self, PyObject * args)
{
    Topology* obj = get_topology( self );
    int i;
    if (!PyArg_ParseTuple(args, "i",&i))
    {
        return nullptr;
    }
    return PyFloat_FromDouble(obj->getPY(i));
}

static PyObject * Topology_getPZ(PyObject *self, PyObject * args)
{
    Topology* obj = get_topology( self );
    int i;
    if (!PyArg_ParseTuple(args, "i",&i))
    {
        return nullptr;
    }
    return PyFloat_FromDouble(obj->getPZ(i));
}



SP_CLASS_METHODS_BEGIN(Topology)
SP_CLASS_METHOD(Topology,hasPos)
SP_CLASS_METHOD(Topology,getNbPoints)
SP_CLASS_METHOD(Topology,setNbPoints)
SP_CLASS_METHOD(Topology,getPX)
SP_CLASS_METHOD(Topology,getPY)
SP_CLASS_METHOD(Topology,getPZ)
SP_CLASS_METHODS_END


SP_CLASS_TYPE_SPTR(Topology,Topology,BaseObject)



