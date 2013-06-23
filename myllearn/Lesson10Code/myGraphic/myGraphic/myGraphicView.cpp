
// myGraphicView.cpp : CmyGraphicView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "myGraphic.h"
#endif

#include "myGraphicDoc.h"
#include "myGraphicView.h"

#include"SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyGraphicView

IMPLEMENT_DYNCREATE(CmyGraphicView, CView)

BEGIN_MESSAGE_MAP(CmyGraphicView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmyGraphicView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_DOT, &CmyGraphicView::OnDot)
	ON_COMMAND(ID_ELLIPSE, &CmyGraphicView::OnEllipse)
	ON_COMMAND(IDM_LINE, &CmyGraphicView::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CmyGraphicView::OnRectangle)
	ON_COMMAND(IDM_SETTING, &CmyGraphicView::OnSetting)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CmyGraphicView ����/����

CmyGraphicView::CmyGraphicView()
	: m_nDrawType(0)
	, m_ptOrigin(0)
	, m_nLineWidth(0)
	, m_nLineStyle(0)
{
	// TODO: �ڴ˴���ӹ������
	m_nDrawType=0;
	m_ptOrigin=0;
	m_nLineWidth=0;
	m_nLineStyle=0;

}

CmyGraphicView::~CmyGraphicView()
{
}

BOOL CmyGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CmyGraphicView ����

void CmyGraphicView::OnDraw(CDC* /*pDC*/)
{
	CmyGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CmyGraphicView ��ӡ


void CmyGraphicView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmyGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CmyGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CmyGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CmyGraphicView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmyGraphicView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmyGraphicView ���

#ifdef _DEBUG
void CmyGraphicView::AssertValid() const
{
	CView::AssertValid();
}

void CmyGraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmyGraphicDoc* CmyGraphicView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmyGraphicDoc)));
	return (CmyGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CmyGraphicView ��Ϣ�������


void CmyGraphicView::OnDot()
{
	// TODO: �ڴ���������������
	m_nDrawType=1;
}

void CmyGraphicView::OnLine()
{
	// TODO: �ڴ���������������
	m_nDrawType=2;
}

void CmyGraphicView::OnRectangle()
{
	// TODO: �ڴ���������������
	m_nDrawType=3;
}

void CmyGraphicView::OnEllipse()
{
	// TODO: �ڴ���������������
	m_nDrawType=4;
}

void CmyGraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_ptOrigin=point;
	CView::OnLButtonDown(nFlags, point);
}


void CmyGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CPen pen(m_nLineStyle,m_nLineWidth,RGB(255,0,0));
	dc.SelectObject(&pen);
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(pBrush);
	switch(m_nDrawType)
	{
	case 1:
		dc.SetPixel(point,RGB(255,0,0));
		break;
	case 2:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;
	case 3:
		dc.Rectangle(CRect(m_ptOrigin,point));
		break;
	case 4:
		dc.Ellipse(CRect(m_ptOrigin,point));
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}





void CmyGraphicView::OnSetting()
{
	// TODO: �ڴ���������������
	static CSettingDlg dlg;
//	dlg.m_nLineWidth=m_nLineWidth;
	if(IDOK==dlg.DoModal())
	{
		m_nLineWidth=dlg.m_nLineWidth;
		m_nLineStyle=dlg.m_nLineStyle;
	}
}



