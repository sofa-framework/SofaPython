#include "PythonMacros.h"

#include <sofa/core/objectmodel/Base.h>
#include <sofa/core/objectmodel/BaseContext.h>
#include <sofa/core/objectmodel/Context.h>
#include <sofa/simulation/tree/GNode.h>
#include <sofa/simulation/common/Node.h>
#include <sofa/core/BaseState.h>
#include <sofa/core/loader/BaseLoader.h>
#include <sofa/core/loader/MeshLoader.h>
#include <sofa/core/topology/Topology.h>
#include <sofa/component/typedef/Sofa_typedef.h>

using namespace sofa::simulation;
using namespace sofa::simulation::tree;
using namespace sofa::core::objectmodel;
using namespace sofa::core;
using namespace sofa::core::loader;
using namespace sofa::core::topology;

#include "Binding_Base.h"
#include "Binding_BaseObject.h"
#include "Binding_BaseState.h"
#include "Binding_MechanicalObject.h"
#include "Binding_BaseContext.h"
#include "Binding_Context.h"
#include "Binding_Node.h"
#include "Binding_BaseLoader.h"
#include "Binding_MeshLoader.h"
#include "Binding_Topology.h"

using namespace sofa::core;

// crée un objet Python à partir d'un objet Cpp héritant de Base,
// retournant automatiquement le type Python de plus haut niveau possible
// en fonction du type de l'objet Cpp
// Ceci afin de permettre l'utilisation de fonctions des sous-classes de Base
PyObject* SP_BUILD_PYSPTR(Base* obj)
{
    if (dynamic_cast<Node*>(obj))
        return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(Node));
    if (dynamic_cast<Context*>(obj))
        return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(Context));
    if (dynamic_cast<BaseContext*>(obj))
        return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(BaseContext));

    if (dynamic_cast<MeshLoader*>(obj))
        return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(MeshLoader));
    if (dynamic_cast<BaseLoader*>(obj))
        return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(BaseLoader));

    if (dynamic_cast<Topology*>(obj))
        return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(Topology));

    if (dynamic_cast<MechanicalObject3*>(obj))
        return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(MechanicalObject));
    if (dynamic_cast<BaseState*>(obj))
        return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(BaseState));

    if (dynamic_cast<BaseObject*>(obj))
        return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(BaseObject));

    // par défaut...
    return BuildPySPtr<Base>(obj,&SP_SOFAPYTYPEOBJECT(Base));
}
