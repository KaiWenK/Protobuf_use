#ifndef PROTOBUF_READ_H
#define PROTOBUF_READ_H

#include <string>
#include "addressbook.pb.h"
using namespace std;

#define  STR_MAX_LEN  128
#define  PHONE_NUM_LEN  3

// 电话类型结构体
typedef enum EM_PHONE
{
	emNull   = 0,
	emMobile ,
	emHome   ,
	emWork
}emPhone;

typedef struct TAG_NUMBER
{
	char        strPhone[STR_MAX_LEN];
	emPhone     ePhoneType;

	TAG_NUMBER(){ memset(this, 0, sizeof(TAG_NUMBER)); }
} tPeopleNumber;

// 人员信息结构体
typedef struct TAG_PEOPLE
{
	int           nID;
	char          strName[STR_MAX_LEN];
	char          strEmail[STR_MAX_LEN];
	tPeopleNumber tPhoneNum[PHONE_NUM_LEN];

	TAG_PEOPLE(){ memset(this, 0, sizeof(TAG_PEOPLE)); }
} tPeople;

// protobuf读取类
class CProtobufRead
{
public:
	CProtobufRead();
	~CProtobufRead();

public:
	void ProtoRead(const tutorial::AddressBook& address_book, tPeople& tphone);
};

#endif // PROTOBUF_READ_H