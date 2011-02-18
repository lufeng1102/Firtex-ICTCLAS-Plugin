//
// Copyright(C) 2005--2011 FirteX Development Team. 
// All rights reserved.
// This file is part of FirteX (www.firtex.org)
//
// Use of the FirteX is subject to the terms of the software license set forth in 
// the LICENSE file included with this software, and also available at
// http://www.firtex.org/license.html
//
// Author	: Lemo(lufeng)
// Email	: amuseme.lu@gmail.com
// Created	: 2010/02/18
//

#ifndef _PLUGINS_ICTCLASANALYZERPLUGIN_H
#define _PLUGINS_ICTCLASANALYZERPLUGIN_H

#include "com/Com.h"
#include "plugin/FirteXCOM.h"
#include "com/ComPtr.h"

FX_NS_DEF(plugin)

class ICTCLASAnalyzerPlugin: public IAnalyzerPlugin
{
public:
  ICTCLASAnalyzerPlugin();
  virtual ~ICTCLASAnalyzerPlugin();
  
  public:
  FX_STDMETHOD_(uint32_t,AddRef)();
  FX_STDMETHOD_(uint32_t,Release)();
  FX_STDMETHOD(QueryInterface)( FX_NS(com)::FX_IID const& riid, void** ptr);
	
	virtual FX_NS(com)::FX_HRESULT FX_STDMETHODCALLTYPE getIdentifier(/* [out] [retval] */FX_NS(com)::FX_BSTR* retVal);
	virtual FX_NS(com)::FX_HRESULT FX_STDMETHODCALLTYPE getTokenType(/* [out] [retval] */TOKENTYPE* retVal) = 0;
	virtual FX_NS(com)::FX_HRESULT FX_STDMETHODCALLTYPE getRecommendIndexer(/* [out] [retval] */ FX_NS(com)::FX_BSTR* retVal) = 0;
	virtual FX_NS(com)::FX_HRESULT FX_STDMETHODCALLTYPE nextTokensInternal(/* [in] */ITokenView* pUnAnalyzedTokenVector,
                                                                           ITokenView** ppAnalyzedTokenVector) = 0;

}

#enfif // end _PLUGINS_ICTCLASANALYZERPLUGIN_H
