// MdApi.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "MdApi.h"

using namespace std;

extern CUstpFtdcMduserApi* pUserApi;
extern CBOnFrontConnected cbOnFrontConnected ;
extern CBOnFrontDisconnected cbOnFrontDisconnected ;
extern CBOnHeartBeatWarning cbOnHeartBeatWarning ;
///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
extern CBOnPackageStart cbOnPackageStart ;
///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
extern CBOnPackageEnd cbOnPackageEnd ;
extern CBOnRspError cbOnRspError ;
extern CBOnRspUserLogin cbOnRspUserLogin ;
extern CBOnRspUserLogout cbOnRspUserLogout ;
extern CBOnRspSubscribeTopic cbOnRspSubscribeTopic ;
///主题查询应答
extern CBOnRspQryTopic cbOnRspQryTopic ;
///深度行情通知
extern CBOnRtnDepthMarketData cbOnRtnDepthMarketData ;
extern CBOnRspSubMarketData cbOnRspSubMarketData ;
extern CBOnRspUnSubMarketData cbOnRspUnSubMarketData ;

CMdSpi::CMdSpi()
{
	return;
}

void CMdSpi::OnFrontConnected()
{
	if (cbOnFrontConnected != NULL)
		cbOnFrontConnected();
}


///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
void CMdSpi::OnFrontDisconnected(int nReason) {
	if (cbOnFrontDisconnected != NULL)
	{
		cbOnFrontDisconnected(nReason);
	}
}
///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void CMdSpi::OnHeartBeatWarning(int nTimeLapse) {
	if (cbOnHeartBeatWarning != NULL)
	{
		cbOnHeartBeatWarning(nTimeLapse);
	}
}
///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
///@param nTopicID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
void CMdSpi::OnPackageStart(int nTopicID, int nSequenceNo) {
	if (cbOnPackageStart != NULL)
	{
		cbOnPackageStart(nTopicID, nSequenceNo);
	}
}
///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
///@param nTopicID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
void CMdSpi::OnPackageEnd(int nTopicID, int nSequenceNo) {
	if (cbOnPackageEnd != NULL)
	{
		cbOnPackageEnd(nTopicID, nSequenceNo);
	}
}
///错误应答
void CMdSpi::OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspError != NULL)
	{
		cbOnRspError(repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///风控前置系统用户登录应答
void CMdSpi::OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspUserLogin != NULL)
	{
		cbOnRspUserLogin(pRspUserLogin, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///用户退出应答
void CMdSpi::OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspUserLogout != NULL)
	{
		cbOnRspUserLogout(pRspUserLogout, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///订阅主题应答
void CMdSpi::OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspSubscribeTopic != NULL)
	{
		cbOnRspSubscribeTopic(pDissemination, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///主题查询应答
void CMdSpi::OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspQryTopic != NULL)
	{
		cbOnRspQryTopic(pDissemination, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///深度行情通知
void CMdSpi::OnRtnDepthMarketData(CUstpFtdcDepthMarketDataField *pDepthMarketData) {
	if (cbOnRtnDepthMarketData != NULL)
	{
		cbOnRtnDepthMarketData(pDepthMarketData);
	}
}
///订阅合约的相关信息
void CMdSpi::OnRspSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspSubMarketData != NULL)
	{
		cbOnRspSubMarketData(pSpecificInstrument, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///退订合约的相关信息
void CMdSpi::OnRspUnSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspUnSubMarketData != NULL)
	{
		cbOnRspUnSubMarketData(pSpecificInstrument, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}



//针对收到空反馈的处理
CUstpFtdcRspInfoField rif;
CUstpFtdcRspInfoField* CMdSpi::repareInfo(CUstpFtdcRspInfoField *pRspInfo)
{
	if (pRspInfo == NULL)
	{
		memset(&rif, 0, sizeof(rif));
		return &rif;
	}
	else
		return pRspInfo;
}


