// protobuf_use.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "protoread.h"
#include "protowrite.h"

#define MAX_SIZE  1024

int _tmain(int argc, _TCHAR* argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	// 写入并序列化
	tutorial::AddressBook address_book1;
	CProtobufWrite protobufw;
	protobufw.ProtoWrite(*address_book1.add_people());
	char tmpArr[MAX_SIZE];
	memset(tmpArr, 0, sizeof(tmpArr));
	ZeroCopyOutputStream *raw_output = new ArrayOutputStream(tmpArr, address_book1.ByteSize());
	CodedOutputStream* coded_output = new CodedOutputStream(raw_output);
	address_book1.SerializeToCodedStream(coded_output);

	// 读取并解析输入流
	tPeople tp;
	tutorial::AddressBook address_book2;
	ZeroCopyInputStream *raw_input = new ArrayInputStream(tmpArr, strlen(tmpArr));
	CodedInputStream* coded_input = new CodedInputStream(raw_input);
	address_book2.ParseFromCodedStream(coded_input);
	CProtobufRead protobufr;
	protobufr.ProtoRead(address_book2, tp);

	cout << "id:" << tp.nID << endl;
	cout << "name:" << tp.strName << endl;
	cout << "eMail:" << tp.strEmail << endl;
	cout << "phoneType:" << tp.tPhoneNum[0].ePhoneType << endl;
	cout << "phoneNumber:" << tp.tPhoneNum[0].strPhone << endl;

	google::protobuf::ShutdownProtobufLibrary();

	system("pause");
	return 0;
}