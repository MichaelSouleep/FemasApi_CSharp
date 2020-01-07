// MdApi.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "MdApi.h"
#include "USTPFtdcMduserApi.h"

CUstpFtdcMduserApi* pUserApi;
CMdSpi* pUserSpi;

CBOnFrontConnected cbOnFrontConnected = 0;
CBOnFrontDisconnected cbOnFrontDisconnected = 0;
CBOnHeartBeatWarning cbOnHeartBeatWarning = 0;
///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
CBOnPackageStart cbOnPackageStart = 0;
///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
CBOnPackageEnd cbOnPackageEnd = 0;
CBOnRspError cbOnRspError = 0;
CBOnRspUserLogin cbOnRspUserLogin = 0;
CBOnRspUserLogout cbOnRspUserLogout = 0;
CBOnRspSubscribeTopic cbOnRspSubscribeTopic = 0;
///主题查询应答
CBOnRspQryTopic cbOnRspQryTopic = 0;
///深度行情通知
CBOnRtnDepthMarketData cbOnRtnDepthMarketData = 0;
CBOnRspSubMarketData cbOnRspSubMarketData = 0;
CBOnRspUnSubMarketData cbOnRspUnSubMarketData = 0;


/////创建MdApi
/////@return 创建出的MdApi
extern "C" MDAPI_API void CreateApi(char * pszFlowPath)
{
	pUserApi = CUstpFtdcMduserApi::CreateFtdcMduserApi();			// 创建UserApi
}

///删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
extern "C" MDAPI_API void Release()
{
	delete pUserSpi;
	pUserSpi = nullptr;
	pUserApi->Release();
}

///初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
extern "C" MDAPI_API void Init()
{
	pUserApi->Init();
}

///等待接口线程结束运行
///@return 线程退出代码
extern "C" MDAPI_API void Join()
{
	pUserApi->Join();
}

///获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
extern "C" MDAPI_API const char* GetTradingDay()
{
	return pUserApi->GetTradingDay();
}

///注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
extern "C" MDAPI_API void RegisterFront(char *pszFrontAddress)
{
	pUserSpi = new CMdSpi();
	pUserApi->RegisterSpi((CUstpFtdcMduserSpi*)pUserSpi);			// 注册事件类
	//pUserApi->SubscribePublicTopic(THOST_TERT_QUICK/*THOST_TERT_RESTART*/);					// 注册公有流
	//pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK/*THOST_TERT_RESTART*/);					// 注册私有流
	pUserApi->RegisterFront(pszFrontAddress);
}

///注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterFront优先于RegisterNameServer
extern "C" MDAPI_API void RegisterNameServer(char *pszNsAddress)
{
	pUserApi->RegisterNameServer(pszNsAddress);
}

///注册回调接口
///@param pSpi 派生自回调接口类的实例
extern "C" MDAPI_API void RegisterSpi(CUstpFtdcMduserSpi *pSpi)
{
	pUserApi->RegisterSpi(pSpi);
}

///加载证书
///@param pszCertFileName 用户证书文件名
///@param pszKeyFileName 用户私钥文件名
///@param pszCaFileName 可信任CA证书文件名
///@param pszKeyFilePassword 用户私钥文件密码
///@return 0 操作成功
///@return -1 可信任CA证书载入失败
///@return -2 用户证书载入失败
///@return -3 用户私钥载入失败	
///@return -4 用户证书校验失败
extern "C" MDAPI_API int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName,
	const char *pszCaFileName, const char *pszKeyFilePassword)
{
	return pUserApi->RegisterCertificateFile(pszCertFileName, pszKeyFileName, pszCaFileName, pszKeyFilePassword);
}

///订阅市场行情。
///@param nTopicID 市场行情主题  
///@param nResumeType 市场行情重传方式  
///        USTP_TERT_RESTART:从本交易日开始重传
///        USTP_TERT_RESUME:从上次收到的续传(非订阅全部合约时，不支持续传模式)
///        USTP_TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
extern "C" MDAPI_API void SubscribeMarketDataTopic(int nTopicID, USTP_TE_RESUME_TYPE nResumeType)
{
	pUserApi->SubscribeMarketDataTopic(nTopicID, nResumeType);
}

///订阅合约行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
extern "C" MDAPI_API int SubMarketData(char *ppInstrumentID[], int nCount)
{
	return pUserApi->SubMarketData(ppInstrumentID, nCount);
}

///退订合约行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
extern "C" MDAPI_API int UnSubMarketData(char *ppInstrumentID[], int nCount)
{
	return pUserApi->UnSubMarketData(ppInstrumentID, nCount);
}

///设置心跳超时时间。
///@param timeout 心跳超时时间(秒)  
extern "C" MDAPI_API void SetHeartbeatTimeout(unsigned int timeout)
{
	pUserApi->SetHeartbeatTimeout(timeout);
}


///风控前置系统用户登录请求
extern "C" MDAPI_API int ReqUserLogin(CUstpFtdcReqUserLoginField *pReqUserLogin, int nRequestID)
{
	return pUserApi->ReqUserLogin(pReqUserLogin, nRequestID);
}

///用户退出请求
extern "C" MDAPI_API int ReqUserLogout(CUstpFtdcReqUserLogoutField *pReqUserLogout, int nRequestID)
{
	return pUserApi->ReqUserLogout(pReqUserLogout, nRequestID);
}

///订阅主题请求
extern "C" MDAPI_API int ReqSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, int nRequestID)
{
	return pUserApi->ReqSubscribeTopic(pDissemination, nRequestID);
}

///主题查询请求
extern "C" MDAPI_API int ReqQryTopic(CUstpFtdcDisseminationField *pDissemination, int nRequestID)
{
	return pUserApi->ReqQryTopic(pDissemination, nRequestID);
}

///订阅合约的相关信息
extern "C" MDAPI_API int ReqSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID)
{
	return pUserApi->ReqSubMarketData(pSpecificInstrument, nRequestID);
}

///退订合约的相关信息
extern "C" MDAPI_API int ReqUnSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID)
{
	return pUserApi->ReqUnSubMarketData(pSpecificInstrument, nRequestID);
}



//============================================ 回调 函数注册 ===========================================

///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
extern "C" MDAPI_API void WINAPI RegOnFrontConnected(CBOnFrontConnected cb)
{
	cbOnFrontConnected = cb;
}
///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
extern "C" MDAPI_API void WINAPI RegOnFrontDisconnected(CBOnFrontDisconnected cb)
{
	cbOnFrontDisconnected = cb;
}
///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
extern "C" MDAPI_API void WINAPI RegOnHeartBeatWarning(CBOnHeartBeatWarning cb)
{
	cbOnHeartBeatWarning = cb;
}
///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
///@param nTopicID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
extern "C" MDAPI_API void WINAPI RegOnPackageStart(CBOnPackageStart cb)
{
	cbOnPackageStart = cb;
}
///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
///@param nTopicID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
extern "C" MDAPI_API void WINAPI RegOnPackageEnd(CBOnPackageEnd cb)
{
	cbOnPackageEnd = cb;
}
///错误应答
extern "C" MDAPI_API void WINAPI RegOnRspError(CBOnRspError cb)
{
	cbOnRspError = cb;
}
///风控前置系统用户登录应答
extern "C" MDAPI_API void WINAPI RegOnRspUserLogin(CBOnRspUserLogin cb)
{
	cbOnRspUserLogin = cb;
}
///用户退出应答
extern "C" MDAPI_API void WINAPI RegOnRspUserLogout(CBOnRspUserLogout cb)
{
	cbOnRspUserLogout = cb;
}
///订阅主题应答
extern "C" MDAPI_API void WINAPI RegOnRspSubscribeTopic(CBOnRspSubscribeTopic cb)
{
	cbOnRspSubscribeTopic = cb;
}
///主题查询应答
extern "C" MDAPI_API void WINAPI RegOnRspQryTopic(CBOnRspQryTopic cb)
{
	cbOnRspQryTopic = cb;
}
///深度行情通知
extern "C" MDAPI_API void WINAPI RegOnRtnDepthMarketData(CBOnRtnDepthMarketData cb)
{
	cbOnRtnDepthMarketData = cb;
}
///订阅合约的相关信息
extern "C" MDAPI_API void WINAPI RegOnRspSubMarketData(CBOnRspSubMarketData cb)
{
	cbOnRspSubMarketData = cb;
}
///退订合约的相关信息
extern "C" MDAPI_API void WINAPI RegOnRspUnSubMarketData(CBOnRspUnSubMarketData cb)
{
	cbOnRspUnSubMarketData = cb;
}
