#include "../mac-802_11e_management_framebody.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

	unsigned int		SupportedRates_Len;

	unsigned int		framebody_len;
	char			*framebody;
	
	bool			ESS;
	bool			IBSS;
	bool			CFPollable;
	bool			CFPollRequest;
	bool			Privacy;
	bool			ShortPreamble;
	bool			PBCC;
	bool			ChannelAgility;
	bool			SpectrumManagement;
	bool			QoS;
	bool			ShortSlotTime;
	bool			APSD;
	bool			DSSS_OFDM;
	bool			DelayedBloackAck;
	bool			ImmediateBlockAck;

	unsigned short		StatusCode;

	unsigned short		AID;

	char			*SupportedRates;

	u_char 			QoSInfo_EDCAParameterSetUpdateCount;
	bool 			QoSInfo_QAck;
	bool 			QoSInfo_QueueRequest;
	bool 			QoSInfo_TXOPRequest;
	u_char 			AC_BE_AIFSN;
	bool 			AC_BE_ACM;
	u_char 			AC_BE_ECW;
	unsigned short 		AC_BE_TXOP_Limit;
	u_char 			AC_BK_AIFSN;
	bool 			AC_BK_ACM;
	u_char 			AC_BK_ECW;
	unsigned short 		AC_BK_TXOP_Limit;
	u_char 			AC_VI_AIFSN;
	bool 			AC_VI_ACM;
	u_char 			AC_VI_ECW;
	unsigned short 		AC_VI_TXOP_Limit;
	u_char 			AC_VO_AIFSN;
	bool 			AC_VO_ACM;
	u_char 			AC_VO_ECW;
	unsigned short 		AC_VO_TXOP_Limit;

	char			*CapabilityInfo;
	char			*QoSInfo;
	char			*AC_XX_Parameter_Record;

	void			*tmp_void_ptr;
	char			*tmp_char_ptr;

	/* Build frame body */
	SupportedRates_Len = 8;
	framebody_len = Calculate80211eAssociationResponseFrameBodyLength(SupportedRates_Len);

	framebody = (char *)malloc(framebody_len);
	Initialize80211eFrameBodyWithZero(framebody, framebody_len);

	ESS = true;
	IBSS = false;
	CFPollable = true;
	CFPollRequest = false;
	Privacy = true;
	ShortPreamble = true;
	PBCC = false;
	ChannelAgility = true;
	SpectrumManagement = false;
	QoS = true;
	ShortSlotTime = false;
	APSD = true;
	DSSS_OFDM = false;
	DelayedBloackAck = true;
	ImmediateBlockAck = false;
	SetCapabilityInfoInto80211eAssociationResponseFrameBody(framebody, ESS, IBSS, CFPollable, CFPollRequest, Privacy, ShortPreamble, PBCC, ChannelAgility, SpectrumManagement, QoS, ShortSlotTime, APSD, DSSS_OFDM, DelayedBloackAck, ImmediateBlockAck);
	if(ESS)
	   printf("\e[0;31;40mSet\e[m ESS = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m ESS = 0\n");
	if(IBSS)
	   printf("\e[0;31;40mSet\e[m IBSS = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m IBSS = 0\n");
	if(CFPollable)
	   printf("\e[0;31;40mSet\e[m CFPollable = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m CFPollable = 0\n");
	if(CFPollRequest)
	   printf("\e[0;31;40mSet\e[m CFPollRequest = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m CFPollRequest = 0\n");
	if(Privacy)
	   printf("\e[0;31;40mSet\e[m Privacy = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m Privacy = 0\n");

	StatusCode = 2;
	SetStatusCodeInto80211eAssociationResponseFrameBody(framebody, &StatusCode);
	printf("\e[0;31;40mSet\e[m StatusCode = %d\n", StatusCode);

	AID = 12;
	SetAIDInto80211eAssociationResponseFrameBody(framebody, &AID);
	printf("\e[0;31;40mSet\e[m AID = %d\n", AID);

	SupportedRates = (char *)malloc(SupportedRates_Len);
	strncpy(SupportedRates, "12345678", SupportedRates_Len);
	SetSupportedRatesInto80211eAssociationResponseFrameBody(framebody, SupportedRates_Len, (void *)SupportedRates);
	printf("\e[0;31;40mSet\e[m SupportedRates_Len = %d\n", SupportedRates_Len);
	if(SupportedRates != NULL && SupportedRates_Len != 0) 
		printf("\e[0;31;40mSet\e[m SupportedRates -> %s\n", SupportedRates);
	free((void *)SupportedRates);

	QoSInfo_EDCAParameterSetUpdateCount = 0x0e;
	QoSInfo_QAck = true;
	QoSInfo_QueueRequest = false;
	QoSInfo_TXOPRequest = true;
	AC_BE_AIFSN = 0x0a;
	AC_BE_ACM = true;
	AC_BE_ECW = 0xaa;
	AC_BE_TXOP_Limit = 11;
	AC_BK_AIFSN = 0x0b;
	AC_BK_ACM = false;
	AC_BK_ECW = 0xbb;
	AC_BK_TXOP_Limit = 22;
	AC_VI_AIFSN = 0x0c;
	AC_VI_ACM = true;
	AC_VI_ECW = 0xcc;
	AC_VI_TXOP_Limit = 33;
	AC_VO_AIFSN = 0x0d;
	AC_VO_ACM = false;
	AC_VO_ECW = 0xdd;
	AC_VO_TXOP_Limit = 44;            	
	SetEDCAParameterSetInto80211eAssociationResponseFrameBody(framebody, SupportedRates_Len, QoSInfo_EDCAParameterSetUpdateCount, QoSInfo_QAck, QoSInfo_QueueRequest, QoSInfo_TXOPRequest, AC_BE_AIFSN, AC_BE_ACM, AC_BE_ECW, &AC_BE_TXOP_Limit, AC_BK_AIFSN, AC_BK_ACM, AC_BK_ECW, &AC_BK_TXOP_Limit, AC_VI_AIFSN, AC_VI_ACM, AC_VI_ECW, &AC_VI_TXOP_Limit, AC_VO_AIFSN, AC_VO_ACM, AC_VO_ECW, &AC_VO_TXOP_Limit);
	printf("\e[0;31;40mSet\e[m EDCA QoSInfo_EDCAParameterSetUpdateCount = %x\n", QoSInfo_EDCAParameterSetUpdateCount);
	if(QoSInfo_QAck)
	   printf("\e[0;31;40mSet\e[m EDCA QoSInfo_QAck = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m EDCA QoSInfo_QAck = 0\n");
	if(QoSInfo_QueueRequest)
	   printf("\e[0;31;40mSet\e[m EDCA QoSInfo_QueueRequest = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m EDCA QoSInfo_QueueRequest = 0\n");
	if(QoSInfo_TXOPRequest)
	   printf("\e[0;31;40mSet\e[m EDCA QoSInfo_TXOPRequest = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m EDCA QoSInfo_TXOPRequest = 0\n");

	printf("\e[0;31;40mSet\e[m AC_BE_AIFSN = %x\n", AC_BE_AIFSN);
	if(AC_BE_ACM)
	   printf("\e[0;31;40mSet\e[m AC_BE_ACM = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m AC_BE_ACM = 0\n");
	printf("\e[0;31;40mSet\e[m AC_BE_ECW = %x\n", AC_BE_ECW);
	printf("\e[0;31;40mSet\e[m AC_BE_TXOP_Limit = %d\n", AC_BE_TXOP_Limit);

	printf("\e[0;31;40mSet\e[m AC_BK_AIFSN = %x\n", AC_BK_AIFSN);
	if(AC_BK_ACM)
	   printf("\e[0;31;40mSet\e[m AC_BK_ACM = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m AC_BK_ACM = 0\n");
	printf("\e[0;31;40mSet\e[m AC_BK_ECW = %x\n", AC_BK_ECW);
	printf("\e[0;31;40mSet\e[m AC_BK_TXOP_Limit = %d\n", AC_BK_TXOP_Limit);

	printf("\e[0;31;40mSet\e[m AC_VI_AIFSN = %x\n", AC_VI_AIFSN);
	if(AC_VI_ACM)
	   printf("\e[0;31;40mSet\e[m AC_VI_ACM = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m AC_VI_ACM = 0\n");
	printf("\e[0;31;40mSet\e[m AC_VI_ECW = %x\n", AC_VI_ECW);
	printf("\e[0;31;40mSet\e[m AC_VI_TXOP_Limit = %d\n", AC_VI_TXOP_Limit);

	printf("\e[0;31;40mSet\e[m AC_VO_AIFSN = %x\n", AC_VO_AIFSN);
	if(AC_VO_ACM)
	   printf("\e[0;31;40mSet\e[m AC_VO_ACM = 1\n");
	else
	   printf("\e[0;31;40mSet\e[m AC_VO_ACM = 0\n");
	printf("\e[0;31;40mSet\e[m AC_VO_ECW = %x\n", AC_VO_ECW);
	printf("\e[0;31;40mSet\e[m AC_VO_TXOP_Limit = %d\n", AC_VO_TXOP_Limit);

	/*==Get=========================*/
	CapabilityInfo = GetCapabilityInfoFrom80211eAssociationResponseFrameBody(framebody);
	if(GetESSFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m ESS = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m ESS = 0\n");
	if(GetIBSSFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m IBSS = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m IBSS = 0\n");
	if(GetCFPollableFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m CFPollable = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m CFPollable = 0\n");
	if(GetCFPollRequestFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m CFPollRequest = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m CFPollRequest = 0\n");
	if(GetPrivacyFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m Privacy = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m Privacy = 0\n");
	if(GetShortPreambleFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m ShortPreamble = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m ShortPreamble = 0\n");
	if(GetPBCCFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m PBCC = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m PBCC = 0\n");
	if(GetChannelAgilityFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m ChannelAgility = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m ChannelAgility = 0\n");
	if(GetSpectrumManagementFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m SpectrumManagement = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m SpectrumManagement = 0\n");
	if(GetQoSFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m QoS = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m QoS = 0\n");
	if(GetShortSlotTimeFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m ShortSlotTime = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m ShortSlotTime = 0\n");
	if(GetAPSDFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m APSD = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m APSD = 0\n");
	if(GetDSSSOFDMFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m DSSS_OFDM = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m DSSS_OFDM = 0\n");
	if(GetDelayedBlockAckFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m DelayedBloackAck = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m DelayedBloackAck = 0\n");
	if(GetImmediateBlockAckFrom80211eCapabilityInfo(CapabilityInfo) == true)
	   printf("\e[0;32;40mGet\e[m ImmediateBlockAck = 1\n");
	else
	   printf("\e[0;32;40mGet\e[m ImmediateBlockAck = 0\n");

	GetStatusCodeFrom80211eAssociationResponseFrameBody(framebody, &StatusCode);
	printf("\e[0;32;40mGet\e[m StatusCode = %d\n", StatusCode);

	GetAIDFrom80211eAssociationResponseFrameBody(framebody, &AID);
	printf("\e[0;32;40mGet\e[m AID = %d\n", AID);

	tmp_void_ptr = GetSupportedRatesFrom80211eAssociationResponseFrameBody(framebody, &SupportedRates_Len);
	if(tmp_void_ptr != NULL && SupportedRates_Len != 0) {
		SupportedRates = (char *)malloc(SupportedRates_Len);
		strncpy(SupportedRates, (char *)tmp_void_ptr, SupportedRates_Len);
		SupportedRates[SupportedRates_Len] = '\0';
		printf("\e[0;32;40mGet\e[m SupportedRates_Len = %d\n", SupportedRates_Len);
		printf("\e[0;32;40mGet\e[m SupportedRates -> %s\n", SupportedRates);
		free((void *)SupportedRates);
	}

	tmp_char_ptr = GetEDCAParameterSetFrom80211eAssociationResponseFrameBody(framebody, SupportedRates_Len);
	if(tmp_char_ptr != NULL) {
		QoSInfo = GetQoSInfoFromEDCAParameterSet(tmp_char_ptr);
		if(QoSInfo != NULL) {
			if(GetEDCAParameterSetUpdateCountFromQoSInfo(QoSInfo, &QoSInfo_EDCAParameterSetUpdateCount) == true)
				printf("\e[0;32;40mGet\e[m EDCA QoSInfo_EDCAParameterSetUpdateCount = %x\n", QoSInfo_EDCAParameterSetUpdateCount);
			if(GetQAckFromQoSInfo(QoSInfo) == true) 
			   printf("\e[0;32;40mGet\e[m EDCA QoSInfo_QAck = 1\n");
			else
			   printf("\e[0;32;40mGet\e[m EDCA QoSInfo_QAck = 0\n");
			if(GetQueueRequestFromQoSInfo(QoSInfo) == true) 
			   printf("\e[0;32;40mGet\e[m EDCA QoSInfo_QueueRequest = 1\n");
			else
			   printf("\e[0;32;40mGet\e[m EDCA QoSInfo_QueueRequest = 0\n");
			if(GetTXOPRequestFromQoSInfo(QoSInfo) == true) 
			   printf("\e[0;32;40mGet\e[m EDCA QoSInfo_TXOPRequest = 1\n");
			else
			   printf("\e[0;32;40mGet\e[m EDCA QoSInfo_TXOPRequest = 0\n");
		}

		AC_XX_Parameter_Record = GetACBEParameterRecordFromEDCAParameterSet(tmp_char_ptr);
		if(AC_XX_Parameter_Record != NULL) {
			if(GetAIFSNFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_BE_AIFSN) == true) 
				printf("\e[0;32;40mGet\e[m AC_BE_AIFSN = %x\n", AC_BE_AIFSN);	
			if(GetACMFromACXXParameterRecord(AC_XX_Parameter_Record) == true)
			   printf("\e[0;32;40mGet\e[m AC_BE_ACM = 1\n");
			else
			   printf("\e[0;32;40mGet\e[m AC_BE_ACM = 0\n");
			if(GetECWFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_BE_ECW) == true) 
				printf("\e[0;32;40mGet\e[m AC_BE_ECW = %x\n", AC_BE_ECW);	
			if(GetTXOPLimitFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_BE_TXOP_Limit) == true) 
				printf("\e[0;32;40mGet\e[m AC_BE_TXOP_Limit = %d\n", AC_BE_TXOP_Limit);	
		}
		
		AC_XX_Parameter_Record = GetACBKParameterRecordFromEDCAParameterSet(tmp_char_ptr);
		if(AC_XX_Parameter_Record != NULL) {
			if(GetAIFSNFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_BK_AIFSN) == true) 
				printf("\e[0;32;40mGet\e[m AC_BK_AIFSN = %x\n", AC_BK_AIFSN);	
			if(GetACMFromACXXParameterRecord(AC_XX_Parameter_Record) == true)
			   printf("\e[0;32;40mGet\e[m AC_BK_ACM = 1\n");
			else
			   printf("\e[0;32;40mGet\e[m AC_BK_ACM = 0\n");
			if(GetECWFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_BK_ECW) == true) 
				printf("\e[0;32;40mGet\e[m AC_BK_ECW = %x\n", AC_BK_ECW);	
			if(GetTXOPLimitFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_BK_TXOP_Limit) == true) 
				printf("\e[0;32;40mGet\e[m AC_BK_TXOP_Limit = %d\n", AC_BK_TXOP_Limit);	
		}

		AC_XX_Parameter_Record = GetACVIParameterRecordFromEDCAParameterSet(tmp_char_ptr);
		if(AC_XX_Parameter_Record != NULL) {
			if(GetAIFSNFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_VI_AIFSN) == true) 
				printf("\e[0;32;40mGet\e[m AC_VI_AIFSN = %x\n", AC_VI_AIFSN);	
			if(GetACMFromACXXParameterRecord(AC_XX_Parameter_Record) == true)
			   printf("\e[0;32;40mGet\e[m AC_VI_ACM = 1\n");
			else
			   printf("\e[0;32;40mGet\e[m AC_VI_ACM = 0\n");
			if(GetECWFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_VI_ECW) == true) 
				printf("\e[0;32;40mGet\e[m AC_VI_ECW = %x\n", AC_VI_ECW);	
			if(GetTXOPLimitFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_VI_TXOP_Limit) == true) 
				printf("\e[0;32;40mGet\e[m AC_VI_TXOP_Limit = %d\n", AC_VI_TXOP_Limit);	
		}

		AC_XX_Parameter_Record = GetACVOParameterRecordFromEDCAParameterSet(tmp_char_ptr);
		if(AC_XX_Parameter_Record != NULL) {
			if(GetAIFSNFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_VO_AIFSN) == true) 
				printf("\e[0;32;40mGet\e[m AC_VO_AIFSN = %x\n", AC_VO_AIFSN);	
			if(GetACMFromACXXParameterRecord(AC_XX_Parameter_Record) == true)
			   printf("\e[0;32;40mGet\e[m AC_VO_ACM = 1\n");
			else
			   printf("\e[0;32;40mGet\e[m AC_VO_ACM = 0\n");
			if(GetECWFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_VO_ECW) == true) 
				printf("\e[0;32;40mGet\e[m AC_VO_ECW = %x\n", AC_VO_ECW);	
			if(GetTXOPLimitFromACXXParameterRecord(AC_XX_Parameter_Record, &AC_VO_TXOP_Limit) == true) 
				printf("\e[0;32;40mGet\e[m AC_VO_TXOP_Limit = %d\n", AC_VO_TXOP_Limit);	
		}
	}

	free(framebody);	
	return 0;
}

