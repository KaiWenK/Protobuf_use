#include "stdafx.h"
#include "protoread.h"

CProtobufRead::CProtobufRead()
{

}

CProtobufRead::~CProtobufRead()
{

}

void CProtobufRead::ProtoRead(const tutorial::AddressBook& address_book, tPeople& tphone)
{
	// 只测试读取一条数据，也就是一个tPeople的数据
	for (int i = 0; i < address_book.people_size() && i < 1; i++)
	{
		const tutorial::Person& person = address_book.people(i);
		tphone.nID = person.id();
		strcpy_s(tphone.strName, person.name().c_str());
		if (person.has_email())
		{
			strcpy_s(tphone.strEmail, person.email().c_str());
		}

		int phoneNumCount = sizeof(tphone.tPhoneNum) / sizeof(tphone.tPhoneNum[1]);
		for (int j = 0; j < person.phones_size() && j < phoneNumCount; j++)
		{
			const tutorial::Person::PhoneNumber& phone_number = person.phones(i);

			switch (phone_number.type())
			{
			case tutorial::Person::MOBILE:
				tphone.tPhoneNum[j].ePhoneType = emMobile;
				break;
			case tutorial::Person::HOME:
				tphone.tPhoneNum[j].ePhoneType = emHome;
				break;
			case tutorial::Person::WORK:
				tphone.tPhoneNum[j].ePhoneType = emWork;
				break;
			default:
				tphone.tPhoneNum[j].ePhoneType = emNull;
				break;
			}
			strcpy_s(tphone.tPhoneNum[j].strPhone, phone_number.number().c_str());
		}
	}
}
