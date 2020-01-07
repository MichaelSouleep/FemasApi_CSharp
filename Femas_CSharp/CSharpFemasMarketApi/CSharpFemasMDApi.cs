using FemasCommon;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CSharpFemasMarketApi
{
    public class CSharpFemasMDSpi
    {
        protected CSharpFemasMDApi m_api;

        public CSharpFemasMDSpi() { }

        #region  Virtual Spi Method
        ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
        public virtual void OnFrontConnected() { }

        ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
        ///@param nReason 错误原因
        ///        0x1001 网络读失败
        ///        0x1002 网络写失败
        ///        0x2001 接收心跳超时
        ///        0x2002 发送心跳失败
        ///        0x2003 收到错误报文
        public virtual void OnFrontDisconnected(int nReason) { }

        ///心跳超时警告。当长时间未收到报文时，该方法被调用。
        ///@param nTimeLapse 距离上次接收报文的时间
        public virtual void OnHeartBeatWarning(int nTimeLapse) { }

        ///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
        ///@param nTopicID 主题代码（如私有流、公共流、行情流等）
        ///@param nSequenceNo 报文序号
        public virtual void OnPackageStart(int nTopicID, int nSequenceNo) { }

        ///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
        ///@param nTopicID 主题代码（如私有流、公共流、行情流等）
        ///@param nSequenceNo 报文序号
        public virtual void OnPackageEnd(int nTopicID, int nSequenceNo) { }


        ///错误应答
        public virtual void OnRspError(ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///风控前置系统用户登录应答
        public virtual void OnRspUserLogin(ref CUstpFtdcRspUserLoginField pRspUserLogin, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///用户退出应答
        public virtual void OnRspUserLogout(ref CUstpFtdcRspUserLogoutField pRspUserLogout, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///订阅主题应答
        public virtual void OnRspSubscribeTopic(ref CUstpFtdcDisseminationField pDissemination, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///主题查询应答
        public virtual void OnRspQryTopic(ref CUstpFtdcDisseminationField pDissemination, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///深度行情通知
        public virtual void OnRtnDepthMarketData(ref CUstpFtdcDepthMarketDataField pDepthMarketData) { }

        ///订阅合约的相关信息
        public virtual void OnRspSubMarketData(ref CUstpFtdcSpecificInstrumentField pSpecificInstrument, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///退订合约的相关信息
        public virtual void OnRspUnSubMarketData(ref CUstpFtdcSpecificInstrumentField pSpecificInstrument, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        #endregion
    }

    public class CSharpFemasMDApi
    {
        const string strDllFile = "femascsharpmdapi.dll";

        private string FlowPath;


        public void RegisterSpi(CSharpFemasMDSpi spi)
        {
            OnFrontConnected += spi.OnFrontConnected;
            OnFrontDisconnected += spi.OnFrontDisconnected;
            OnHeartBeatWarning += spi.OnHeartBeatWarning;
            OnPackageStart += spi.OnPackageStart;
            OnPackageEnd += spi.OnPackageEnd;
            OnRspError += spi.OnRspError;
            OnRspUserLogin += spi.OnRspUserLogin;
            OnRspUserLogout += spi.OnRspUserLogout;
            OnRspSubscribeTopic += spi.OnRspSubscribeTopic;
            OnRspQryTopic += spi.OnRspQryTopic;
            OnRtnDepthMarketData += spi.OnRtnDepthMarketData;
            OnRspSubMarketData += spi.OnRspSubMarketData;
            OnRspUnSubMarketData += spi.OnRspUnSubMarketData;
        }

        /////创建MdApi
        /////@return 创建出的MdApi
        public void CreateApi(string pszFlowPath)
        {
            cppCreateApi(pszFlowPath);
        }
        [DllImport(strDllFile, EntryPoint = "CreateApi", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppCreateApi(string pszFlowPath);


        ///删除接口对象本身
        ///@remark 不再使用本接口对象时,调用该函数删除接口对象
        public void Release()
        {
            cppRelease();
        }
        [DllImport(strDllFile, EntryPoint = "Release", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppRelease();


        ///初始化
        ///@remark 初始化运行环境,只有调用后,接口才开始工作
        public void Init()
        {
            cppInit();
        }
        [DllImport(strDllFile, EntryPoint = "Init", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppInit();


        ///等待接口线程结束运行
        ///@return 线程退出代码
        public void Join()
        {
            cppJoin();
        }
        [DllImport(strDllFile, EntryPoint = "Join", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppJoin();


        ///获取当前交易日
        ///@retrun 获取到的交易日
        ///@remark 只有登录成功后,才能得到正确的交易日
        public string GetTradingDay()
        {
            return cppGetTradingDay();
        }
        [DllImport(strDllFile, EntryPoint = "GetTradingDay", CallingConvention = CallingConvention.Cdecl)]
        static extern string cppGetTradingDay();


        ///注册前置机网络地址
        ///@param pszFrontAddress：前置机网络地址。
        ///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
        ///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
        public void RegisterFront(string pszFrontAddress)
        {
            cppRegisterFront(pszFrontAddress);
        }
        [DllImport(strDllFile, EntryPoint = "RegisterFront", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppRegisterFront(string pszFrontAddress);


        ///注册名字服务器网络地址
        ///@param pszNsAddress：名字服务器网络地址。
        ///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
        ///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
        ///@remark RegisterFront优先于RegisterNameServer
        public void RegisterNameServer(string pszNsAddress)
        {
            cppRegisterNameServer(pszNsAddress);
        }
        [DllImport(strDllFile, EntryPoint = "RegisterNameServer", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppRegisterNameServer(string pszNsAddress);



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
        public int RegisterCertificateFile(string pszCertFileName, string pszKeyFileName, string pszCaFileName, string pszKeyFilePassword)
        {
            return cppRegisterCertificateFile(pszCertFileName, pszKeyFileName, pszCaFileName, pszKeyFilePassword);
        }
        [DllImport(strDllFile, EntryPoint = "RegisterCertificateFile", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppRegisterCertificateFile(string pszCertFileName, string pszKeyFileName, string pszCaFileName, string pszKeyFilePassword);


        ///订阅市场行情。
        ///@param nTopicID 市场行情主题  
        ///@param nResumeType 市场行情重传方式  
        ///        USTP_TERT_RESTART:从本交易日开始重传
        ///        USTP_TERT_RESUME:从上次收到的续传(非订阅全部合约时，不支持续传模式)
        ///        USTP_TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
        ///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
        public void SubscribeMarketDataTopic(int nTopicID, EFemasTSSType nResumeType)
        {
            cppSubscribeMarketDataTopic(nTopicID, nResumeType);
        }
        [DllImport(strDllFile, EntryPoint = "SubscribeMarketDataTopic", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppSubscribeMarketDataTopic(int nTopicID, EFemasTSSType nResumeType);


        ///订阅合约行情。
        ///@param ppInstrumentID 合约ID  
        ///@param nCount 要订阅/退订行情的合约个数
        ///@remark 
        public int SubMarketData(string[] ppInstrumentID, int nCount)
        {
            return cppSubMarketData(ppInstrumentID, nCount);
        }
        [DllImport(strDllFile, EntryPoint = "SubMarketData", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppSubMarketData(string[] ppInstrumentID, int nCount);


        ///退订合约行情。
        ///@param ppInstrumentID 合约ID  
        ///@param nCount 要订阅/退订行情的合约个数
        ///@remark 
        public int UnSubMarketData(string[] ppInstrumentID, int nCount)
        {
            return cppUnSubMarketData(ppInstrumentID, nCount);
        }
        [DllImport(strDllFile, EntryPoint = "UnSubMarketData", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppUnSubMarketData(string[] ppInstrumentID, int nCount);


        ///设置心跳超时时间。
        ///@param timeout 心跳超时时间(秒)  
        public void SetHeartbeatTimeout(int timeout)
        {
            cppSetHeartbeatTimeout(timeout);
        }
        [DllImport(strDllFile, EntryPoint = "SetHeartbeatTimeout", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppSetHeartbeatTimeout(int timeout);


        ///风控前置系统用户登录请求
        public int ReqUserLogin(ref CUstpFtdcReqUserLoginField pReqUserLogin, int nRequestID)
        {
            return cppReqUserLogin(ref pReqUserLogin, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqUserLogin", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqUserLogin(ref CUstpFtdcReqUserLoginField pReqUserLogin, int nRequestID);


        ///用户退出请求
        public int ReqUserLogout(ref CUstpFtdcReqUserLogoutField pReqUserLogout, int nRequestID)
        {
            return cppReqUserLogout(ref pReqUserLogout, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqUserLogout", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqUserLogout(ref CUstpFtdcReqUserLogoutField pReqUserLogout, int nRequestID);


        ///订阅主题请求
        public int ReqSubscribeTopic(ref CUstpFtdcDisseminationField pDissemination, int nRequestID)
        {
            return cppReqSubscribeTopic(ref pDissemination, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqSubscribeTopic", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqSubscribeTopic(ref CUstpFtdcDisseminationField pDissemination, int nRequestID);


        ///主题查询请求
        public int ReqQryTopic(ref CUstpFtdcDisseminationField pDissemination, int nRequestID)
        {
            return cppReqQryTopic(ref pDissemination, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryTopic", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryTopic(ref CUstpFtdcDisseminationField pDissemination, int nRequestID);


        ///订阅合约的相关信息
        public int ReqSubMarketData(ref CUstpFtdcSpecificInstrumentField pSpecificInstrument, int nRequestID)
        {
            return cppReqSubMarketData(ref pSpecificInstrument, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqSubMarketData", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqSubMarketData(ref CUstpFtdcSpecificInstrumentField pSpecificInstrument, int nRequestID);


        ///退订合约的相关信息
        public int ReqUnSubMarketData(ref CUstpFtdcSpecificInstrumentField pSpecificInstrument, int nRequestID)
        {
            return cppReqUnSubMarketData(ref pSpecificInstrument, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqUnSubMarketData", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqUnSubMarketData(ref CUstpFtdcSpecificInstrumentField pSpecificInstrument, int nRequestID);


        //============================================ 回调 函数注册 ===========================================
        [DllImport(strDllFile, EntryPoint = "RegOnFrontConnected", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnFrontConnected(deleFrontConnected cb);
        deleFrontConnected FrontConnected;
        public delegate void deleFrontConnected();
        public event deleFrontConnected OnFrontConnected
        {
            add { FrontConnected += value; cppRegOnFrontConnected(FrontConnected); }
            remove { FrontConnected -= value; cppRegOnFrontConnected(FrontConnected); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnFrontDisconnected", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnFrontDisconnected(deleFrontDisconnected cb);
        deleFrontDisconnected FrontDisconnected;
        public delegate void deleFrontDisconnected(int nReason);
        public event deleFrontDisconnected OnFrontDisconnected
        {
            add { FrontDisconnected += value; cppRegOnFrontDisconnected(FrontDisconnected); }
            remove { FrontDisconnected -= value; cppRegOnFrontDisconnected(FrontDisconnected); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnHeartBeatWarning", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnHeartBeatWarning(deleHeartBeatWarning cb);
        deleHeartBeatWarning HeartBeatWarning;
        public delegate void deleHeartBeatWarning(int nTimeLapse);
        public event deleHeartBeatWarning OnHeartBeatWarning
        {
            add { HeartBeatWarning += value; cppRegOnHeartBeatWarning(HeartBeatWarning); }
            remove { HeartBeatWarning -= value; cppRegOnHeartBeatWarning(HeartBeatWarning); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnPackageStart", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnPackageStart(delePackageStart cb);
        delePackageStart PackageStart;
        public delegate void delePackageStart(int nTopicID, int nSequenceNo);
        public event delePackageStart OnPackageStart
        {
            add { PackageStart += value; cppRegOnPackageStart(PackageStart); }
            remove { PackageStart -= value; cppRegOnPackageStart(PackageStart); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnPackageEnd", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnPackageEnd(delePackageEnd cb);
        delePackageEnd PackageEnd;
        public delegate void delePackageEnd(int nTopicID, int nSequenceNo);
        public event delePackageEnd OnPackageEnd
        {
            add { PackageEnd += value; cppRegOnPackageEnd(PackageEnd); }
            remove { PackageEnd -= value; cppRegOnPackageEnd(PackageEnd); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspError", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspError(deleRspError cb);
        deleRspError RspError;
        public delegate void deleRspError(ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspError OnRspError
        {
            add { RspError += value; cppRegOnRspError(RspError); }
            remove { RspError -= value; cppRegOnRspError(RspError); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspUserLogin", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspUserLogin(deleRspUserLogin cb);
        deleRspUserLogin RspUserLogin;
        public delegate void deleRspUserLogin(ref CUstpFtdcRspUserLoginField pRspUserLogin, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspUserLogin OnRspUserLogin
        {
            add { RspUserLogin += value; cppRegOnRspUserLogin(RspUserLogin); }
            remove { RspUserLogin -= value; cppRegOnRspUserLogin(RspUserLogin); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspUserLogout", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspUserLogout(deleRspUserLogout cb);
        deleRspUserLogout RspUserLogout;
        public delegate void deleRspUserLogout(ref CUstpFtdcRspUserLogoutField pRspUserLogout, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspUserLogout OnRspUserLogout
        {
            add { RspUserLogout += value; cppRegOnRspUserLogout(RspUserLogout); }
            remove { RspUserLogout -= value; cppRegOnRspUserLogout(RspUserLogout); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspSubscribeTopic", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspSubscribeTopic(deleRspSubscribeTopic cb);
        deleRspSubscribeTopic RspSubscribeTopic;
        public delegate void deleRspSubscribeTopic(ref CUstpFtdcDisseminationField pDissemination, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspSubscribeTopic OnRspSubscribeTopic
        {
            add { RspSubscribeTopic += value; cppRegOnRspSubscribeTopic(RspSubscribeTopic); }
            remove { RspSubscribeTopic -= value; cppRegOnRspSubscribeTopic(RspSubscribeTopic); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryTopic", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryTopic(deleRspQryTopic cb);
        deleRspQryTopic RspQryTopic;
        public delegate void deleRspQryTopic(ref CUstpFtdcDisseminationField pDissemination, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryTopic OnRspQryTopic
        {
            add { RspQryTopic += value; cppRegOnRspQryTopic(RspQryTopic); }
            remove { RspQryTopic -= value; cppRegOnRspQryTopic(RspQryTopic); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnDepthMarketData", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnDepthMarketData(deleRtnDepthMarketData cb);
        deleRtnDepthMarketData RtnDepthMarketData;
        public delegate void deleRtnDepthMarketData(ref CUstpFtdcDepthMarketDataField pDepthMarketData);
        public event deleRtnDepthMarketData OnRtnDepthMarketData
        {
            add { RtnDepthMarketData += value; cppRegOnRtnDepthMarketData(RtnDepthMarketData); }
            remove { RtnDepthMarketData -= value; cppRegOnRtnDepthMarketData(RtnDepthMarketData); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspSubMarketData", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspSubMarketData(deleRspSubMarketData cb);
        deleRspSubMarketData RspSubMarketData;
        public delegate void deleRspSubMarketData(ref CUstpFtdcSpecificInstrumentField pSpecificInstrument, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspSubMarketData OnRspSubMarketData
        {
            add { RspSubMarketData += value; cppRegOnRspSubMarketData(RspSubMarketData); }
            remove { RspSubMarketData -= value; cppRegOnRspSubMarketData(RspSubMarketData); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspUnSubMarketData", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspUnSubMarketData(deleRspUnSubMarketData cb);
        deleRspUnSubMarketData RspUnSubMarketData;
        public delegate void deleRspUnSubMarketData(ref CUstpFtdcSpecificInstrumentField pSpecificInstrument, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspUnSubMarketData OnRspUnSubMarketData
        {
            add { RspUnSubMarketData += value; cppRegOnRspUnSubMarketData(RspUnSubMarketData); }
            remove { RspUnSubMarketData -= value; cppRegOnRspUnSubMarketData(RspUnSubMarketData); }
        }




    }
}
