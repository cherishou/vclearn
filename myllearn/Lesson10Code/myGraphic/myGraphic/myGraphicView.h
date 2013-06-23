
// myGraphicView.h : CmyGraphicView ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class CmyGraphicView : public CView
{
protected: // �������л�����
	CmyGraphicView();
	DECLARE_DYNCREATE(CmyGraphicView)

// ����
public:
	CmyGraphicDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CmyGraphicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDot();
	afx_msg void OnEllipse();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
private:
	unsigned int m_nDrawType;
public:
	afx_msg void OnSetting();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CPoint m_ptOrigin;
	unsigned int m_nLineWidth;
	int m_nLineStyle;
};

#ifndef _DEBUG  // myGraphicView.cpp �еĵ��԰汾
inline CmyGraphicDoc* CmyGraphicView::GetDocument() const
   { return reinterpret_cast<CmyGraphicDoc*>(m_pDocument); }
#endif

