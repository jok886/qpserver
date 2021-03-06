#ifndef SINGLE_PRO_ITEM_CONTROL_HEAD
#define SINGLE_PRO_ITEM_CONTROL_HEAD

#pragma once

#include "GamePropertyHead.h"


//////////////////////////////////////////////////////////////////////////
//喇叭道具
class  GAME_PROPERTY_CLASS  CDlgTrumpetItem : public CSkinDialog,public IExpressionSink
{
  //变量定义
protected:
  int               m_nMaxChar;           //最大个数
  WORD                            m_wRadioSelected;               //单选按钮
  COLORREF            m_crChatTX;           //字体颜色
  CString             m_strInuptChat;         //输入信息
  CString             m_strPropertyInfo;        //道具信息

  //控件变量
protected:
  CEdit             m_InputChat;          //聊天框
  CExpressionControl *      m_pExpressionControl;     //表情窗口

  //接口变量
protected:
  IClientUserItem  *              m_pIClientUserItem;             //用户接口
  IGamePropertyUseSink *          m_pGameTrumpetSink;             //回调接口

  //函数定义
public:
  //构造函数
  CDlgTrumpetItem();
  //析构函数
  virtual ~CDlgTrumpetItem();

  //绑定函数
protected:
  //确定函数
  virtual VOID OnOK();
  //取消消息
  virtual VOID OnCancel();
  //初始框架
  virtual BOOL OnInitDialog();
  //控件绑定
  virtual void DoDataExchange(CDataExchange* pDX);

  //重载函数
public:
  //初始控件
  virtual VOID InitControlUI();
  //消息提醒
  virtual VOID Notify(TNotifyUI &  msg);
  //皮肤名称
  virtual LPCTSTR GetSkinFile()
  {
    return TEXT("DlgTrumpetItem.xml");
  }

  //绘画函数
protected:
  //绘画消息
  virtual VOID OnDrawClientAreaEnd(CDC * pDC, INT nWidth, INT nHeight);

  //表情接口
public:
  //选择事件
  virtual VOID OnExpressionSelect(CExpression * pExpression, tagExpressionInfo * pExpressionInfo);

  //辅助函数
public:
  //更新界面
  void UpdateControlSurface();
  //获取颜色
  COLORREF GetTrumpetColor()
  {
    return m_crChatTX;
  };
  //获取内容
  void GetTrumpetContent(LPTSTR pszTrumpetContent);
  //设置接口
  bool SetGameTrumpetSink(IUnknownEx * pIUnknownEx);
  //显示窗口
  void ShowTrumpetWindow(CWnd * pParentWnd,IClientUserItem  * pIClientUserItem);

  //消息处理
protected:
  //喇叭按钮
  void OnBnClickedTrumpet();
  //喇叭按钮
  void OnBnClickedTyphon();
  //颜色按钮
  void OnBnClickedColorSet();
  //表情按钮
  void OnBnClickedExpression();

  DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////

#endif
