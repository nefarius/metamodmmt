// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the METAMODMMT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// METAMODMMT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef METAMODMMT_EXPORTS
#define METAMODMMT_API __declspec(dllexport)
#else
#define METAMODMMT_API __declspec(dllimport)
#endif

// This class is exported from the metamodmmt.dll
class METAMODMMT_API Cmetamodmmt {
public:
	Cmetamodmmt(void);
	// TODO: add your methods here.
};

extern METAMODMMT_API int nmetamodmmt;

METAMODMMT_API int fnmetamodmmt(void);
