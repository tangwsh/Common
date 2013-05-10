/*
 * KSSTservPck.h
 *
 *  Created on: 2010-4-21
 *      Author: evantang
 */

#ifndef KSSTSERVPCK_H_
#define KSSTSERVPCK_H_

/* 错误码定义 */
#define	CORRECT 			   (0)			//结果正确
#define	ParseKSSWordErr 	   (-1)			//解析关键词失败
#define	WordLengthTooLong 	   (-2)			//关键词过长
#define	ResNumTooLarge 		   (-3)			//请求查询的数目过多（超过300）
#define	NotEnoughBuff 		   (-4)			//为查询结果的分配空间不足
#define	NoResult			   (-5)			//查询无结果
#define	NoQuery 			   (-6)			//无此关键词
#define	ParamError 			   (-7)			//检索时参数错误
#define	IndexError 			   (-8)			//分享服务器索引错误
#define MultiWordOverLoad      (-9)			//多词数目超过限制
#define SectionOverLoad		   (-10) 		//多词取回结果时要求的条目数超过限制

/*以下为proxy和search_server内部通信错误*/
#define	ReceiveSearchHeadError (-100) 		//收SearchServer包头错误
#define	ReceiveSearchBodyError (-101) 		//收SearchServer包体错误
#define SendError              (-102)       //发送失败
#define ServerError			   (-103)       //发送都失败的命令字
#define	Other 				   (-1000)		//其它情况
//}KSSWordErrorCode;

/***************************************** 命令字定义 *****************************************/
						/*********检索***********/
#define	ADDKSSWORD 							1	/*新增词*/
#define	SEARCHKSSWORDBYTIME 				2	/*单个词按时间取结果*/
#define	SEARCHKSSWORDBYRELATIVE 			7	/*单个词按相关性取结果*/
#define	SEARCHKSSWORDBYTIMEANDRELATIVE		4	/*单个词根据时间取一定时间内相关性最好的n条结果*/
#define	SEARCHKSSDOC						3	/*根据词和Doc取结果*/
#define	SEARCHMULTIKSSWORDBYTIMEWITHOUTMERGE    	6	/*多个词根据时间共取m*n条结果*/
#define	SEARCHMULTIKSSWORDBYRELATIVEWITHOUTMERGE    22	/*多个词根据相关性共取m*n条结果*/
#define	SEARCHMULTIKSSWORDBYTIME			12	/*多个词按时间取结果*/
#define SEARCHDOMAININFO                    20  /*查询主域信息*/
#define SEARCHDOCSIZE						21  /*查询指定doc出现的位置信息，并返回对应页面的文档内容*/
#define SEARCHNEWSPOOLDOC                   23  /*在推荐的新闻池里查找指定的信息*/

#define SEARCHKSSTOPN						31  /*从新闻池里查找信息*/
#define SEARCHKSSTOPNFORGOOD                32  /*从新闻池里查找较好的信息*/
#define SEARCHKSSTOPNOLD					30  /*从新闻池里查找信息，老协议*/

#define SEARCHPROFILE 						33  /*根据profile提供用户感兴趣内容*/

#define SEARCHWORDINRBU						15  /*从RBU拉取新词结果，返回前台*/
#define SAVEWORDINRBU                       14  /*从RBU摘取新词结果，并存储*/

						/*********分享 收藏***********/
#define	GETSINGLEDOCID						3	/*按单个DocId取分享结果*/
#define GETMULTIDOCID                       5   /*按多个DocId取分享结果*/

#define	SAVESINGLEDOCID 					9	/*按单个DocId存分享结果*/
#define SAVEMULTIDOCID                      8   /*按多个DocId存分享结果*/

						/*********测试使用***********/
#define TESTFORSEARCHKSSWORDBYTIMEWITHOUTRBU 100
/***************************************** 命令字定义 *****************************************/

/* 协议包 */
#pragma pack(1)
struct recTservPckHead
{
	int length;			//总长度（含包头本身）
	int cmd; 			//查询指令
	int magic;			//验证码

	recTservPckHead()
	{
		length = 0;
		cmd = 0;
		magic = 0;
	}
};


struct recRequestPck
{
	recTservPckHead head;
	char data[0];
};

struct recResponsePck
{
	recTservPckHead head;
	int ret;			//返回码
	char data[0];

	recResponsePck()
	{
		ret = 0;
	}
};

#pragma pack()

#endif /* KSSTSERVPCK_H_ */
