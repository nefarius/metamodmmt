// metamodmmt.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "metamodmmt.h"


// This is an example of an exported variable
METAMODMMT_API int nmetamodmmt=0;

// This is an example of an exported function.
METAMODMMT_API int fnmetamodmmt(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see metamodmmt.h for the class definition
Cmetamodmmt::Cmetamodmmt()
{
    return;
}
