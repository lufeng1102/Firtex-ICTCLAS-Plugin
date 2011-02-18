#include "ICTCLASAnalyzerPlugin.h"

#include "com/Com.h"
#include "com/ComPtr.h"
#include "com/DllServer.h"

FX_NS_USE(plugin);
FX_NS_USE(com);

/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Determines whether the DLL that implements this function is in use.
FX_STDAPI DllCanUnloadNow()
{
	return DllServer::DllCanUnloadNowImpl();
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

FX_STDAPI DllGetClassObject(FX_REFCLSID rclsid, FX_REFIID riid, void** ppv)
{
  // create ICTCLASAnalyzerFactory
	static ICTCLASAnalyzerFactory factory;

	// find the right UUID
//	if ( FX_IsEqualCLSID( rclsid, firtex::plugin::IParserPlugin::clsid ) )
	{
		return factory.QueryInterface( riid, ppv );
	}

	return FX_CLASS_E_CLASSNOTAVAILABLE;
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

FX_STDAPI DllRegisterServer(void)
{
	// registers object, typelib and all interfaces in typelib
	return DllServer::DllRegisterServerImpl( ictclasanalyzerplugin::clsid, 
		L"HTML Parser For FirteX",
		ictclasanalyzerplugin::VersionIndependentProgId, 
		ictclasanalyserplugin::ProgId
		);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

FX_STDAPI DllUnregisterServer(void)
{
	// _Module.UnregisterServer();
	return DllServer::DllUnregisterServerImpl( ictclasanalyzerplugin::clsid );
}
