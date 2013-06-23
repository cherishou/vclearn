
// mystyleView.cpp : CmystyleView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "mystyle.h"
#endif

#include "mystyleDoc.h"
#include "mystyleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmystyleView

IMPLEMENT_DYNCREATE(CmystyleView, CView)

BEGIN_MESSAGE_MAP(CmystyleView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmystyleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CmystyleView ����/����

CmystyleView::CmystyleView()
{
	// TODO: �ڴ˴���ӹ������

}

CmystyleView::~CmystyleView()
{
}

BOOL CmystyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CmystyleView ����

void CmystyleView::OnDraw(CDC* /*pDC*/)
{
	CmystyleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CmystyleView ��ӡ


void CmystyleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmystyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CmystyleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CmystyleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CmystyleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmystyleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmystyleView ���

#ifdef _DEBUG
void CmystyleView::AssertValid() const
{
	CView::AssertValid();
}

void CmystyleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmystyleDoc* CmystyleView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmystyleDoc)));
	return (CmystyleDoc*)m_pDocument;
}
#endif //_DEBUG


// CmystyleView ��Ϣ�������
