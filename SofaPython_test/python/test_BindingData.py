# -*- coding: utf-8 -*-

import Sofa
import SofaTest

def createScene(rootNode):
    rootNode.addNewData("aField", "TestField", "help message", "float", 1.0)
    field = rootNode.getData("aField")
    ASSERT_NEQ(field, None)

    ### Check isPersistant/setPersistant
    ASSERT_FALSE( field.isPersistant() )
    field.setPersistant(True)
    ASSERT_TRUE( field.isPersistant() )

    ### Check isSet/unset
    ASSERT_TRUE( field.isSet() )
    field.unset()
    ASSERT_FALSE( field.isSet() )

    ### Check the hasParent/parentPath
    # Disabled, an API change in SOFA(sofa-framework/sofa#2354) make this test to fail
    # see https://github.com/sofa-framework/SofaPython/issues/1
    # ASSERT_EQ( field.hasParent(), field.getParentPath() == True )

    ### SetValueString
    t = field.getCounter()
    field.setValueString("2.0")
    ASSERT_NEQ(field.getCounter(), t)

    ### Different ways to get values.
    ASSERT_GT(field.getValue(0), 1.5)
    ASSERT_GT(field.value, 1.5)

    t = field.getCounter()
    field.value = 3.0
    ASSERT_NEQ(field.getCounter(), t)
    ASSERT_GT(field.getValue(0), 2.5)
    ASSERT_GT(field.value, 2.5)

    ### What happens if we do something wrong ?
    t = field.getCounter()
    field.setValueString("7.0 8.0 9.0")
    ASSERT_NEQ(field.getCounter(), t)

    #TODO(dmarchal 2017-11-17) well returning zero size and allowing a zero index looks not really
    #good API design.
    ASSERT_EQ(field.getSize(), 0)
    ASSERT_GT(field.getValue(0), 6.0)

    ASSERT_EQ(type(field.isRequired()), bool)
    ASSERT_EQ(type(field.isReadOnly()), bool)
    ASSERT_EQ(type(field.getHelp()), str)
