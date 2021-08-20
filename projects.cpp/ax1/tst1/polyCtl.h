// polyCtl.h : Declaration of the CpolyCtl

#ifndef __POLYCTL_H_
#define __POLYCTL_H_

#include "resource.h"       // main symbols
#include <math.h>
#include <atlctl.h>


/////////////////////////////////////////////////////////////////////////////
// CpolyCtl
class ATL_NO_VTABLE CpolyCtl : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CpolyCtl, IpolyCtl, &IID_IpolyCtl, &LIBID_TST1Lib>,
	public CComControl<CpolyCtl>,
	public IPersistStreamInitImpl<CpolyCtl>,
	public IOleControlImpl<CpolyCtl>,
	public IOleObjectImpl<CpolyCtl>,
	public IOleInPlaceActiveObjectImpl<CpolyCtl>,
	public IViewObjectExImpl<CpolyCtl>,
	public IOleInPlaceObjectWindowlessImpl<CpolyCtl>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CpolyCtl>,
	public IPersistStorageImpl<CpolyCtl>,
	public ISpecifyPropertyPagesImpl<CpolyCtl>,
	public IQuickActivateImpl<CpolyCtl>,
	public IDataObjectImpl<CpolyCtl>,
	public IProvideClassInfo2Impl<&CLSID_polyCtl, &DIID__IpolyCtlEvents, &LIBID_TST1Lib>,
	public IPropertyNotifySinkCP<CpolyCtl>,
	public CComCoClass<CpolyCtl, &CLSID_polyCtl>
{
public:
	CpolyCtl();

DECLARE_REGISTRY_RESOURCEID(IDR_POLYCTL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CpolyCtl)
	COM_INTERFACE_ENTRY(IpolyCtl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()

BEGIN_PROP_MAP(CpolyCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("FillColor", DISPID_FILLCOLOR, CLSID_StockColorPage)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CpolyCtl)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CpolyCtl)
	CHAIN_MSG_MAP(CComControl<CpolyCtl>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] = 
		{
			&IID_IpolyCtl,
		};
		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IpolyCtl
public:
	STDMETHOD(get_sides)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_sides)(/*[in]*/ short newVal);

    void    CalcPoints(const RECT& rc);

	HRESULT OnDraw(ATL_DRAWINFO& di);

	OLE_COLOR m_clrFillColor;
    short     m_nSides;
    POINT     m_points[101];
};

#endif //__POLYCTL_H_
