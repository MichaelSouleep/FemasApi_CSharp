using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FemasCommon
{
    public enum EFemasTSSType : int
    {
        USTP_TSS_DIALOG = 1,        //对话流
        USTP_TSS_PRIVATE = 2,       //客户私有流
        USTP_TSS_PUBLIC = 3,        //公共流
        USTP_TSS_QUERY = 4,     //查询
        USTP_TSS_USER = 5,      //用户私有流
        USTP_TSS_QUOTE = 6,		//询价流
    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpDSAppIDTypeType是一个AppID和RelayID类型类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcDSAppIDTypeType : byte
    {
        ///PC终端
        USTP_FTDC_DSID_PC = (byte)'1',
        ///IOS或安卓app
        USTP_FTDC_DSID_App = (byte)'2',
        ///中继转发模式，即多对多模式
        USTP_FTDC_DSID_ProxyNoOperator = (byte)'3',
        ///中继操作员模式，即多对一模式
        USTP_FTDC_DSID_ProxyOperator = (byte)'4',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpVolumeConditionType是一个成交量类型类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcVolumeConditionType : byte
    {
        ///任何数量
        USTP_FTDC_VC_AV = (byte)'1',
        ///最小数量
        USTP_FTDC_VC_MV = (byte)'2',
        ///全部数量
        USTP_FTDC_VC_CV = (byte)'3',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpForceCloseReasonType是一个强平原因类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcForceCloseReasonType : byte
    {
        ///非强平
        USTP_FTDC_FCR_NotForceClose = (byte)'0',
        ///资金不足
        USTP_FTDC_FCR_LackDeposit = (byte)'1',
        ///客户超仓
        USTP_FTDC_FCR_ClientOverPositionLimit = (byte)'2',
        ///会员超仓
        USTP_FTDC_FCR_MemberOverPositionLimit = (byte)'3',
        ///持仓非整数倍
        USTP_FTDC_FCR_NotMultiple = (byte)'4',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpInstrumentStatusType是一个合约交易状态类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcInstrumentStatusType : byte
    {
        ///开盘前
        USTP_FTDC_IS_BeforeTrading = (byte)'0',
        ///非交易
        USTP_FTDC_IS_NoTrading = (byte)'1',
        ///连续交易
        USTP_FTDC_IS_Continous = (byte)'2',
        ///集合竞价报单
        USTP_FTDC_IS_AuctionOrdering = (byte)'3',
        ///集合竞价价格平衡
        USTP_FTDC_IS_AuctionBalance = (byte)'4',
        ///集合竞价撮合
        USTP_FTDC_IS_AuctionMatch = (byte)'5',
        ///收盘
        USTP_FTDC_IS_Closed = (byte)'6',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpOffsetFlagType是一个开平标志类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcOffsetFlagType : byte
    {
        ///开仓
        USTP_FTDC_OF_Open = (byte)'0',
        ///平仓
        USTP_FTDC_OF_Close = (byte)'1',
        ///强平
        USTP_FTDC_OF_ForceClose = (byte)'2',
        ///平今
        USTP_FTDC_OF_CloseToday = (byte)'3',
        ///平昨
        USTP_FTDC_OF_CloseYesterday = (byte)'4',

    }


    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpOrderPriceTypeType是一个报单价格条件类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcOrderPriceTypeType : byte
    {
        ///任意价
        USTP_FTDC_OPT_AnyPrice = (byte)'1',
        ///限价
        USTP_FTDC_OPT_LimitPrice = (byte)'2',
        ///最优价
        USTP_FTDC_OPT_BestPrice = (byte)'3',
        ///五档价
        USTP_FTDC_OPT_FiveLevelPrice = (byte)'4',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpOrderStatusType是一个报单状态类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcOrderStatusType : byte
    {
        ///全部成交
        USTP_FTDC_OS_AllTraded = (byte)'0',
        ///部分成交还在队列中
        USTP_FTDC_OS_PartTradedQueueing = (byte)'1',
        ///部分成交不在队列中
        USTP_FTDC_OS_PartTradedNotQueueing = (byte)'2',
        ///未成交还在队列中
        USTP_FTDC_OS_NoTradeQueueing = (byte)'3',
        ///未成交不在队列中
        USTP_FTDC_OS_NoTradeNotQueueing = (byte)'4',
        ///撤单
        USTP_FTDC_OS_Canceled = (byte)'5',
        ///订单已报入交易所未应答
        USTP_FTDC_OS_AcceptedNoReply = (byte)'6',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpUserTypeType是一个用户类型类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcUserTypeType : byte
    {
        ///自然人
        USTP_FTDC_UT_Person = (byte)'1',
        ///理财产品
        USTP_FTDC_UT_Product = (byte)'2',
        ///期货公司管理员
        USTP_FTDC_UT_Manager = (byte)'3',
        ///席位
        USTP_FTDC_UT_Seat = (byte)'4',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpTradingRightType是一个交易权限类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcTradingRightType : byte
    {
        ///可以交易
        USTP_FTDC_TR_Allow = (byte)'0',
        ///只能平仓
        USTP_FTDC_TR_CloseOnly = (byte)'1',
        ///不能交易
        USTP_FTDC_TR_Forbidden = (byte)'2',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpTimeConditionType是一个有效期类型类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcTimeConditionType : byte
    {
        ///立即完成，否则撤销
        USTP_FTDC_TC_IOC = (byte)'1',
        ///本节有效
        USTP_FTDC_TC_GFS = (byte)'2',
        ///当日有效
        USTP_FTDC_TC_GFD = (byte)'3',
        ///指定日期前有效
        USTP_FTDC_TC_GTD = (byte)'4',
        ///撤销前有效
        USTP_FTDC_TC_GTC = (byte)'5',
        ///集合竞价有效
        USTP_FTDC_TC_GFA = (byte)'6',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpOrderSourceType是一个报单来源类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcOrderSourceType : byte
    {
        ///来自参与者
        USTP_FTDC_OS_Participant = (byte)'0',
        ///来自管理员
        USTP_FTDC_OS_Administrator = (byte)'1',
        ///报价单拆分出来的买单或卖单
        USTP_FTDC_OS_QuoteSplit = (byte)'2',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpDirectionType是一个买卖方向类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcDirectionType : byte
    {
        ///买
        USTP_FTDC_D_Buy = (byte)'0',
        ///卖
        USTP_FTDC_D_Sell = (byte)'1',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpCurrencyType是一个币种类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcCurrencyType : byte
    {
        ///人民币
        USTP_FTDC_C_RMB = (byte)'1',
        ///美元
        USTP_FTDC_C_UDOLLAR = (byte)'2',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpAccountDirectionType是一个出入金方向类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcAccountDirectionType : byte
    {
        ///入金
        USTP_FTDC_AD_In = (byte)'1',
        ///出金
        USTP_FTDC_AD_Out = (byte)'2',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpHedgeFlagType是一个投机套保标志类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcHedgeFlagType : byte
    {
        ///投机
        USTP_FTDC_CHF_Speculation = (byte)'1',
        ///套利
        USTP_FTDC_CHF_Arbitrage = (byte)'2',
        ///套保
        USTP_FTDC_CHF_Hedge = (byte)'3',
        ///做市商
        USTP_FTDC_CHF_MarketMaker = (byte)'4',
        ///匹配所有的值
        USTP_FTDC_CHF_AllValue = (byte)'9',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpActionFlagType是一个操作标志类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcActionFlagType : byte
    {
        ///删除
        USTP_FTDC_AF_Delete = (byte)'0',
        ///挂起
        USTP_FTDC_AF_Suspend = (byte)'1',
        ///激活
        USTP_FTDC_AF_Active = (byte)'2',
        ///修改
        USTP_FTDC_AF_Modify = (byte)'3',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpPositionTypeType是一个持仓类型类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcPositionTypeType : byte
    {
        ///净持仓
        USTP_FTDC_PT_Net = (byte)'1',
        ///综合持仓
        USTP_FTDC_PT_Gross = (byte)'2',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpOptionsTypeType是一个期权类型类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcOptionsTypeType : byte
    {
        ///非期权
        USTP_FTDC_OT_NotOptions = (byte)'0',
        ///看涨
        USTP_FTDC_OT_CallOptions = (byte)'1',
        ///看跌
        USTP_FTDC_OT_PutOptions = (byte)'2',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpIsActiveType是一个是否活跃类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcIsActiveType : byte
    {
        ///不活跃
        USTP_FTDC_UIA_NoActive = (byte)'0',
        ///活跃
        USTP_FTDC_UIA_Active = (byte)'1',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpGrantFuncSetType是一个授权功能号类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcGrantFuncSetType : byte
    {
        ///正常交易
        USTP_FTDC_FUNC_Trading = (byte)'0',
        ///只能平仓
        USTP_FTDC_FUNC_CloseOnly = (byte)'1',
        ///禁止交易
        USTP_FTDC_FUNC_CanotTrade = (byte)'2',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpQuoteStatusType是一个报价单状态类型类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcQuoteStatusType : byte
    {
        ///在飞马中还未进入交易系统
        USTP_FTDC_QS_Inited_InFEMAS = (byte)'0',
        ///已经报入交易系统中
        USTP_FTDC_QS_Accepted_InTradingSystem = (byte)'1',
        ///已经撤掉单腿
        USTP_FTDC_QS_Canceled_SingleLeg = (byte)'2',
        ///已经全部撤掉
        USTP_FTDC_QS_Canceled_All = (byte)'3',
        ///已经有单腿成交
        USTP_FTDC_QS_Traded_SingleLeg = (byte)'4',
        ///已经全部成交
        USTP_FTDC_QS_Traded_All = (byte)'5',
        ///错误的撤消报价请求
        USTP_FTDC_QS_Error_QuoteAction = (byte)'6',

    }

    /////////////////////////////////////////////////////////////////////////
    ///TFtdcUstpCombDirectionType是一个申请保证金组合指令方向类型
    /////////////////////////////////////////////////////////////////////////
    public enum TUstpFtdcCombDirectionType : byte
    {
        ///申请组合
        USTP_FTDC_CA_Combine = (byte)'0',
        ///申请拆分组合
        USTP_FTDC_CA_UnCombine = (byte)'1',

    }

}
