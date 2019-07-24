#include "stdafx.h"
#include "protowrite.h"

CProtobufWrite::CProtobufWrite()
{

}

CProtobufWrite::~CProtobufWrite()
{

}

void CProtobufWrite::ProtoWrite(tutorial::Person& person)
{
	person.set_id(1);
	person.set_name("god");
	person.set_email("1298074546@qq.com");

	tutorial::Person::PhoneNumber* phone_number = person.add_phones();
	phone_number->set_number("840198354");
	phone_number->set_type(tutorial::Person_PhoneType::Person_PhoneType_HOME);
}
