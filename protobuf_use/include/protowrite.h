#ifndef PROTOBUF_WRITE_H
#define PROTOBUF_WRITE_H

#include <string>
#include "addressbook.pb.h"
using namespace std;

// protobuf–¥»Î¿‡
class CProtobufWrite
{
public:
	CProtobufWrite();
	~CProtobufWrite();

public:
	void ProtoWrite(tutorial::Person& person);

};

#endif // PROTOBUF_READ_H