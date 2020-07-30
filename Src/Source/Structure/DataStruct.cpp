#include "PCH.h"

//#include  <Header/Structure/DataStruct.h>
// TODO: Use cmake and create a project that interfaces with it. Use the project to setup filters and source grouping correctly.

namespace JsonStruct
{
	void DataStruct::Initialize(void* pJson)
	{

	}

	void DataStruct::Test_Init()
	{

	}

	template<typename Type>
	DataMember<Type> DataStruct::GetMemberNonNull(string memberName)
	{
		auto member = GetMemberNonNull(memberName);

		return static_cast<DataMember<Type>>(member);
	}

	DataMember<any> DataStruct::GetMemberNonNull(string memberName)
	{
		auto it = m_Members.find(memberName);

		if (it == m_Members.end())
		{
			return DataMember<any>();
		}

		return it->second;
	}
}